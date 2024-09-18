#pragma once
#define BLACK false
#define RED true
#define TNULL nullptr
#include <vector>
#include <iostream>
#include <string>

using namespace std;


template <typename T, typename S>
class OrderedMap
{
	struct Node {
		T key;
		S value;
		bool color = BLACK; // false = black, true = red
		bool alive = false;
		Node* left = nullptr;
		Node* right = nullptr;
		Node* parent = nullptr;


		// Constructor(s)
		Node(T _key, S _value) : key(_key), value(_value) {};


		// Traversals
		void printInorder() {
			vector<Node*> nodes;
			inorder(nodes);
			bool first = true;
			for (Node* n : nodes) {
				if (first) {
					first = false;
					std::cout << n->key;
				}
				else
					std::cout << ", " << n->key;
			}
		}

		void inorder(vector<Node*>& nodes) {
			if (this->left)
				this->left->inorder(nodes);
			nodes.push_back(this);
			if (this->right)
				this->right->inorder(nodes);
			return;
		}


		// Red-Black Methods
		void verify() {
			// Case 1: Black Parent
			if (parent->color == BLACK)
				return;

			// Case 2: Red Parent
			if (parent->color == RED) {
				Node* grandparent = parent->parent;
				Node* uncle = nullptr;
				if (*parent < *grandparent)
					uncle = grandparent->right;
				else
					uncle = grandparent->left;

				// Case 2a: Red Parent & Uncle
				if (parent->color == RED && uncle != nullptr && uncle->color == RED) {
					parent->color = BLACK;
					uncle->color = BLACK;
					if (grandparent->parent != nullptr)
						grandparent->color = RED;
				}
				// Case 2b: Red Parent, Black Uncle
				if (parent->color == RED && (uncle->color == BLACK || uncle == nullptr)) {
					// Case 2b1: Red Parent, Black Uncle, node > parent > grandparent
					if (grandparent->right == parent && parent->right == this) {
						grandparent->rotateLeft();
						parent->color = BLACK;
						grandparent->color = RED;
					}
					else if (grandparent->right == parent && parent->right == this) {
						grandparent->rotateRightLeft();
						parent->color = BLACK;
						grandparent->color = RED;
					}
					else if (grandparent->right == parent && parent->right == this) {
						grandparent->rotateRight();
						parent->color = BLACK;
						grandparent->color = RED;
					}
					else if (grandparent->right == parent && parent->right == this) {
						grandparent->rotateLeftRight();
						parent->color = BLACK;
						grandparent->color = RED;
					}


				}
			}
		}

		Node* rotateLeft() {
			Node* newParent = right;
			right = newParent->left;
			newParent->left = this;
			return newParent;
		}

		Node* rotateRight()
		{
			Node* newParent = left;
			left = newParent->right;
			newParent->right = this;
			return newParent;
		}

		Node* rotateLeftRight() {
			left = left->rotateLeft();
			return rotateRight();
		}

		Node* rotateRightLeft() {
			right = right->rotateRight();
			return right->rotateLeft();
		}


		// BST Methods
		Node* search(T identifier) {
			if (!this) return nullptr;
			if (identifier == key) return this;
			if (identifier < key && left) return left->search(identifier);
			if (identifier > key && right) return right->search(identifier);
			return nullptr;
		}

		Node* insert(Node* newNode) {
			if (this == nullptr) {
				Node(newNode->key, newNode->value);
				color = 0;
				delete newNode;
				return this;
			}
			if (*newNode == *this) {
				this->value = newNode->value;
				delete newNode;
				return this;
			}
			if (*newNode < *this && left)
				left->insert(newNode);
			else if (*newNode < *this) {
				this->left = newNode;
				newNode->parent = this;
				return newNode;
			}
			if (*newNode > *this && right)
				right->insert(newNode);
			else if (*newNode > *this) {
				this->right = newNode;
				newNode->parent = this;
				return newNode;
			}
		}


		// Operators
		bool operator<(const Node& rhs) {
			return key < rhs.key;
		}

		bool operator>(const Node& rhs) {
			return key > rhs.key;
		}

		bool operator==(const Node& rhs) {
			return key == rhs.key;
		}


		// Destructor
		~Node() {
			if (left) delete left;
			if (right) delete right;
		}
	};

	Node* root = nullptr;

public:
	OrderedMap() {
		root = nullptr;
	}
	Node* search(T key) {
		return root->search(key);
	}
	void insert(T key, S value) {
		Node* newNode = new Node(key, value);
		newNode->alive = true;
		newNode->color = RED;
		if (!root) {
			root = newNode;
			root->color = BLACK;
		}
		else
			newNode = root->insert(newNode);
		//newNode->verify();
	}
	void print() {
		root->printInorder();
	}

	bool hasKey(T key) {
		return search(key) != nullptr;
	}
	S& getValue(T key) {
		return search(key)->value;
	}
	bool empty() {
		return root == nullptr;
	}
	std::pair<T, S> getMax() {
		vector<Node*> nodes;
		root->inorder(nodes);

		Node* maxNode = nodes[0];
		S maxVal = maxNode->value;
		for (int i = 1; i < nodes.size(); i++)
		{
			if (nodes[i]->value->compare(maxVal))
			{
				maxNode = nodes[i];
				maxVal = nodes[i]->value;
			}
		}

		return std::pair<T, S>({ maxNode->key, maxVal });
	}
};
