#pragma once
#include <set>
#include <string>
#include <list>
#include <utility>
#include <initializer_list>

template<class T>
class unorderedMap
{
	unsigned int bucketCount;
	unsigned int size;

	const double load_factor = 0.75;

	std::list<std::pair<std::string, T>>* hashTable;

	std::set<std::string> keyList;

	//iterator redefining
public:

	//Class Methods
	unorderedMap();
	unorderedMap(int bucketCount_);

	std::set<std::string> getKeyList();

	void insert(std::pair<std::string, T> pair);
	void deleteItem(std::string key);
	bool hasKey(std::string key);
	T& value(std::string key);
	bool empty();
private:
	int hashFunction(std::string s);
	void rehash();
public:
	std::pair<std::string, T> getMax();

};

template<class T>
unorderedMap<T>::unorderedMap()
{
	bucketCount = 16;
	size = 0;
	hashTable = new std::list<std::pair<std::string, T>>[bucketCount];
}


template<class T>
unorderedMap<T>::unorderedMap(int bucketCount_)
{
	bucketCount = bucketCount_;
	size = 0;
	hashTable = new list<std::pair<std::string, T>>[bucketCount];
}

template<class T>
inline std::set<std::string> unorderedMap<T>::getKeyList()
{
	return keyList;
}


template<class T>
inline void unorderedMap<T>::insert(std::pair<std::string, T> pair)
{
	if (!hasKey(pair.first))
	{
		int index = hashFunction(pair.first);

		hashTable[index].push_back(pair);
		size++;

		double curLF = (double)size / bucketCount;

		if (curLF > load_factor)
			rehash();
	}
}

template<class T>
inline void unorderedMap<T>::deleteItem(std::string key)
{
	int index = hashFunction(key);

	for (auto iter = hashTable[index].begin(); iter != hashTable[index].end(); ++iter)
	{
		if (iter->first == key)
		{
			size--;
			break;
		}
	}

	if (iter != hashTable[index].end())
		hashTable[index].erase(iter);
}

template<class T>
inline bool unorderedMap<T>::hasKey(std::string key)
{
	int index = hashFunction(key);

	for (auto iter = hashTable[index].begin(); iter != hashTable[index].end(); ++iter)
	{
		if (iter->first == key)
		{
			return true;
		}
	}

	return false;
}

template<class T>
inline T& unorderedMap<T>::value(std::string key) //to remove errors check if exists first
{
	int index = hashFunction(key);
	for (auto iter = hashTable[index].begin(); iter != hashTable[index].end(); ++iter)
	{
		if (iter->first == key)
		{
			return iter->second;
		}
	}
}


template<class T>
inline bool unorderedMap<T>::empty()
{
	if (size == 0)
		return true;
	return false;
}

//Hashing function is djb2 by Dan Bernstein
template<class T>
inline int unorderedMap<T>::hashFunction(std::string const s)
{
	unsigned long hash = 5381;
	for (auto c : s) {
		hash = (hash << 5) + hash + c; /* hash * 33 + c */
	}

	hash %= bucketCount; //reduction
	return hash;
}

template<class T>
inline void unorderedMap<T>::rehash()
{
	unsigned int newBucketCount = bucketCount * 2;

	std::list <std::pair<std::string, T>>* newTable = new std::list<std::pair<std::string, T>>[newBucketCount];

	for (unsigned int i = 0; i < bucketCount; i++)
	{
		if (!hashTable[i].empty())
		{
			for (auto iter = hashTable[i].begin(); iter != hashTable[i].end(); ++iter)
			{
				int index = hashFunction(iter->first);
				newTable[index].push_back(*iter);
				keyList.insert(iter->first);
			}
		}
	}

	bucketCount = newBucketCount;

	delete[] hashTable;
	hashTable = newTable;
}

template<class T>
inline std::pair<std::string, T> unorderedMap<T>::getMax()
{
	if (size == 0)
		return std::pair<std::string, T>();

	T max;
	bool isFirst = true;
	std::pair<std::string, T> maxPair;

	for (unsigned int i = 0; i < bucketCount; i++)
	{
		if (hashTable[i].empty() == 0)
		{
			for (auto iter = hashTable[i].begin(); iter != hashTable[i].end(); ++iter)
			{
				if (isFirst)
				{
					max = iter->second;
					maxPair = *iter;
					isFirst = false;
					continue;
				}
				if (iter->second->compare(max))
				{
					maxPair = *iter;
					max = maxPair.second;
				}
			}
		}
	}

	return maxPair;
}
