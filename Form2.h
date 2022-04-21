#pragma once

#include "pch.h"
#include "Form1.h"
#include <msclr\marshal_cppstd.h>


namespace CppCLRWinFormsProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for Form1
	/// </summary>



	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
		{
			InitializeComponent();
			pictureBox10->Image = Image::FromFile("images/SearchButton.png");
			pictureBox11->Image = Image::FromFile("images/Enter a card.png");
			winratePicture->Image = Image::FromFile("images/Winrate.png");
			winratePicture->Hide();
			gamesPicture->Image = Image::FromFile("images/Games.png");
			gamesPicture->Hide();
			panel1->BackColor = Color::FromArgb(200, Color::White);
			this->BackgroundImage = Image::FromFile("images/Background Image.jpg");
			this->pictureBox1->BackColor = Color::FromArgb(200, Color::White);
			this->pictureBox2->BackColor = Color::FromArgb(200, Color::White);
			this->pictureBox3->BackColor = Color::FromArgb(200, Color::White);
			this->pictureBox4->BackColor = Color::FromArgb(200, Color::White);
			this->pictureBox5->BackColor = Color::FromArgb(200, Color::White);
			this->pictureBox6->BackColor = Color::FromArgb(200, Color::White);
			this->pictureBox7->BackColor = Color::FromArgb(200, Color::White);
			this->pictureBox8->BackColor = Color::FromArgb(200, Color::White);
			this->pictureBox9->BackColor = Color::FromArgb(200, Color::White);
			this->pictureBox10->BackColor = Color::FromArgb(200, Color::White);
			this->pictureBox11->BackColor = Color::FromArgb(200, Color::White);
			this->gamesPicture->BackColor = Color::FromArgb(200, Color::White);
			this->winratePicture->BackColor = Color::FromArgb(200, Color::White);
			this->deckLabel->BackColor = Color::FromArgb(200, Color::White);
			this->winrateLabel->BackColor = Color::FromArgb(200, Color::White);
			this->gameCountLabel->BackColor = Color::FromArgb(200, Color::White);









			Form1^ form1 = gcnew Form1();
			form1->ShowDialog();
			mapChoice = form1->getMapChoice();
			this->Show();
			this->Text = "Loading...";


			cards = new MapCreator(mapChoice);

			this->Text = "Clash Royale Deck Finder";
			timer->Text = "Load Time: " + gcnew String(cards->getTimeElapsed().data()) + " s";

			if (mapChoice) {
				this->Text += " ordered map";
			}
			else {
				this->Text += " unordered map";
			}
		}

	protected:
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
		MapCreator* cards;
		bool mapChoice;
		System::Windows::Forms::ComboBox^ cardSearch;
		System::Windows::Forms::PictureBox^ pictureBox1;
		System::Windows::Forms::Label^ timer;
		System::Windows::Forms::Label^ deckLabel;

		System::Windows::Forms::Label^ searchTimeLabel;
		System::Windows::Forms::PictureBox^ pictureBox2;
		System::Windows::Forms::PictureBox^ pictureBox3;
		System::Windows::Forms::PictureBox^ pictureBox4;
		System::Windows::Forms::PictureBox^ pictureBox5;
		System::Windows::Forms::PictureBox^ pictureBox6;
		System::Windows::Forms::PictureBox^ pictureBox7;
		System::Windows::Forms::PictureBox^ pictureBox8;
		System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::PictureBox^ pictureBox10;
	private: System::Windows::Forms::PictureBox^ pictureBox11;
	private: System::Windows::Forms::Label^ winrateLabel;
	private: System::Windows::Forms::Label^ gameCountLabel;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ gamesPicture;
	private: System::Windows::Forms::PictureBox^ winratePicture;

	public:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cardSearch = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Label());
			this->deckLabel = (gcnew System::Windows::Forms::Label());
			this->searchTimeLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->winrateLabel = (gcnew System::Windows::Forms::Label());
			this->gameCountLabel = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->gamesPicture = (gcnew System::Windows::Forms::PictureBox());
			this->winratePicture = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gamesPicture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->winratePicture))->BeginInit();
			this->SuspendLayout();
			// 
			// cardSearch
			// 
			this->cardSearch->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(107) {
				L"Arrows", L"Bats", L"Dark Prince",
					L"Giant", L"Giant Snowball", L"Graveyard", L"Skeleton Army", L"Witch", L"Cannon Cart", L"Fireball", L"Inferno Dragon", L"Skeleton King",
					L"Tombstone", L"Zappies", L"Dart Goblin", L"Golem", L"Night Witch", L"Rascals", L"Royal Recruits", L"Barbarian Barrel", L"Elite Barbarians",
					L"Elixir Collector", L"Golden Knight", L"Heal Spirit", L"Ice Golem", L"Royal Ghost", L"Three Musketeers", L"Goblin Barrel", L"Goblin Gang",
					L"Ice Spirit", L"Inferno Tower", L"Knight", L"Princess", L"Rocket", L"The Log", L"Electro Spirit", L"Guards", L"Valkyrie", L"Goblin Giant",
					L"Mega Minion", L"Mini P.E.K.K.A", L"Mother Witch", L"Rage", L"Sparky", L"Zap", L"Bandit", L"Electro Wizard", L"Lightning", L"Mega Knight",
					L"Ram Rider", L"Flying Machine", L"Furnace", L"Lava Hound", L"Miner", L"Battle Ram", L"Magic Archer", L"P.E.K.K.A", L"Baby Dragon",
					L"Lumberjack", L"Tornado", L"Goblin Drill", L"Mirror", L"Archer Queen", L"Fire Spirit", L"Skeletons", L"X-Bow", L"Skeleton Barrel",
					L"Spear Goblins", L"Tesla", L"Mighty Miner", L"Balloon", L"Electro Dragon", L"Freeze", L"Musketeer", L"Wall Breakers", L"Ice Wizard",
					L"Poison", L"Bowler", L"Minions", L"Cannon", L"Earthquake", L"Royal Delivery", L"Royal Hogs", L"Barbarians", L"Hog Rider", L"Goblin Cage",
					L"Executioner", L"Firecracker", L"Royal Giant", L"Fisherman", L"Giant Skeleton", L"Hunter", L"Bomber", L"Electro Giant", L"Battle Healer",
					L"Elixir Golem", L"Mortar", L"Clone", L"Archers", L"Skeleton Dragons", L"Minion Horde", L"Prince", L"Goblin Hut", L"Goblins",
					L"Wizard", L"Bomb Tower", L"Barbarian Hut"
			});
			this->cardSearch->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->cardSearch->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->cardSearch->FormattingEnabled = true;
			this->cardSearch->Location = System::Drawing::Point(322, 58);
			this->cardSearch->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->cardSearch->Name = L"cardSearch";
			this->cardSearch->Size = System::Drawing::Size(228, 25);
			this->cardSearch->TabIndex = 5;
			this->cardSearch->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form2::cardSearch_KeyUp);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(103, 159);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(122, 180);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// timer
			// 
			this->timer->AutoSize = true;
			this->timer->Location = System::Drawing::Point(100, 423);
			this->timer->Name = L"timer";
			this->timer->Size = System::Drawing::Size(95, 17);
			this->timer->TabIndex = 7;
			this->timer->Text = L"Time elapsed: ";
			// 
			// deckLabel
			// 
			this->deckLabel->AutoSize = true;
			this->deckLabel->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deckLabel->Location = System::Drawing::Point(319, 130);
			this->deckLabel->Name = L"deckLabel";
			this->deckLabel->Size = System::Drawing::Size(35, 17);
			this->deckLabel->TabIndex = 8;
			this->deckLabel->Text = L"         ";
			// 
			// searchTimeLabel
			// 
			this->searchTimeLabel->AutoSize = true;
			this->searchTimeLabel->Location = System::Drawing::Point(100, 376);
			this->searchTimeLabel->Name = L"searchTimeLabel";
			this->searchTimeLabel->Size = System::Drawing::Size(0, 17);
			this->searchTimeLabel->TabIndex = 10;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(322, 159);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(72, 102);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 11;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(400, 159);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(72, 102);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 12;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(478, 159);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(72, 102);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 13;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(556, 159);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(72, 102);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 14;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Location = System::Drawing::Point(556, 268);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(72, 102);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 18;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Location = System::Drawing::Point(478, 268);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(72, 102);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 17;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Location = System::Drawing::Point(400, 268);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(72, 102);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox8->TabIndex = 16;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Location = System::Drawing::Point(322, 268);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(72, 102);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox9->TabIndex = 15;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Location = System::Drawing::Point(580, 43);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(121, 49);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox10->TabIndex = 19;
			this->pictureBox10->TabStop = false;
			this->pictureBox10->Click += gcnew System::EventHandler(this, &Form2::pictureBox10_Click);
			// 
			// pictureBox11
			// 
			this->pictureBox11->Location = System::Drawing::Point(63, 52);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(228, 31);
			this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox11->TabIndex = 20;
			this->pictureBox11->TabStop = false;
			// 
			// winrateLabel
			// 
			this->winrateLabel->AutoSize = true;
			this->winrateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->winrateLabel->Location = System::Drawing::Point(622, 197);
			this->winrateLabel->Name = L"winrateLabel";
			this->winrateLabel->Size = System::Drawing::Size(57, 36);
			this->winrateLabel->TabIndex = 21;
			this->winrateLabel->Text = L"      ";
			// 
			// gameCountLabel
			// 
			this->gameCountLabel->AutoSize = true;
			this->gameCountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gameCountLabel->Location = System::Drawing::Point(622, 307);
			this->gameCountLabel->Name = L"gameCountLabel";
			this->gameCountLabel->Size = System::Drawing::Size(85, 36);
			this->gameCountLabel->TabIndex = 22;
			this->gameCountLabel->Text = L"          ";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->gameCountLabel);
			this->panel1->Controls->Add(this->gamesPicture);
			this->panel1->Controls->Add(this->winrateLabel);
			this->panel1->Controls->Add(this->winratePicture);
			this->panel1->Location = System::Drawing::Point(30, 26);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(839, 459);
			this->panel1->TabIndex = 23;
			// 
			// gamesPicture
			// 
			this->gamesPicture->Location = System::Drawing::Point(625, 242);
			this->gamesPicture->Name = L"gamesPicture";
			this->gamesPicture->Size = System::Drawing::Size(189, 41);
			this->gamesPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->gamesPicture->TabIndex = 1;
			this->gamesPicture->TabStop = false;
			// 
			// winratePicture
			// 
			this->winratePicture->Location = System::Drawing::Point(625, 133);
			this->winratePicture->Name = L"winratePicture";
			this->winratePicture->Size = System::Drawing::Size(189, 41);
			this->winratePicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->winratePicture->TabIndex = 0;
			this->winratePicture->TabStop = false;
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(907, 510);
			this->Controls->Add(this->pictureBox11);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->searchTimeLabel);
			this->Controls->Add(this->deckLabel);
			this->Controls->Add(this->timer);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->cardSearch);
			this->Controls->Add(this->pictureBox10);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form2";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gamesPicture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->winratePicture))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: vector<string> deckToVector(string deckName) {
		vector<string> cardNames;
		int end = 0;
		string cardName;
		while (deckName != "") {
			end = deckName.find(',');
			if (end != string::npos) {
				cardName = deckName.substr(0,end);
				cardNames.push_back(cardName);
				deckName = deckName.substr(end + 1);
			}
			else {
				cardNames.push_back(deckName);
				deckName = "";
			}
		}
		return cardNames;
	}
	private: System::Void searchButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ managedCardName = cardSearch->Text;
		
		string cardName = marshal_as<std::string>(managedCardName);


		if (cards->hasCard(cardName,mapChoice)) {
			auto start = high_resolution_clock::now();

			string bestDeck = cards->getBestDeck(cardName, mapChoice);

			deckLabel->Text = "Best deck: " + gcnew String(cards->getBestDeck(cardName, mapChoice).data());
			auto stop = high_resolution_clock::now();

			winratePicture->Show();
			gamesPicture->Show();
			winrateLabel->Text = 100*cards->getBestDeckWinrate(cardName, mapChoice) + "%";
			gameCountLabel->Text = ""+cards->getBestDeckGameCount(cardName, mapChoice);

			auto searchDuration = duration_cast<microseconds>(stop - start);
			float msElapsed = searchDuration.count() / 1000.0;
			searchTimeLabel->Text = "Search Time: " + gcnew String(to_string(msElapsed).data()) + " ms";

			string imageName = "images/" + cardName + ".png";
			delete pictureBox1->Image;
			pictureBox1->Image = Image::FromFile(gcnew String(imageName.data()));

			vector<string> cardNames = deckToVector(bestDeck);
			delete pictureBox2->Image;
			delete pictureBox3->Image;
			delete pictureBox4->Image;
			delete pictureBox5->Image;
			delete pictureBox6->Image;
			delete pictureBox7->Image;
			delete pictureBox8->Image;
			delete pictureBox9->Image;
			pictureBox2->Image = Image::FromFile(gcnew String(("images/" + cardNames[0] + ".png").data()));
			pictureBox3->Image = Image::FromFile(gcnew String(("images/" + cardNames[1] + ".png").data()));
			pictureBox4->Image = Image::FromFile(gcnew String(("images/" + cardNames[2] + ".png").data()));
			pictureBox5->Image = Image::FromFile(gcnew String(("images/" + cardNames[3] + ".png").data()));
			pictureBox6->Image = Image::FromFile(gcnew String(("images/" + cardNames[4] + ".png").data()));
			pictureBox7->Image = Image::FromFile(gcnew String(("images/" + cardNames[5] + ".png").data()));
			pictureBox8->Image = Image::FromFile(gcnew String(("images/" + cardNames[6] + ".png").data()));
			pictureBox9->Image = Image::FromFile(gcnew String(("images/" + cardNames[7] + ".png").data()));
		}
		else {
			deckLabel->Text = "Invalid search, please enter a valid card";
			searchTimeLabel->Text = "Searc Time: N/A";
		}
	}
private: System::Void cardSearch_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter) {
		searchButton_Click(sender,e);
	}
}
private: System::Void pictureBox10_Click(System::Object^ sender, System::EventArgs^ e) {
	searchButton_Click(sender, e);
}
};
}
