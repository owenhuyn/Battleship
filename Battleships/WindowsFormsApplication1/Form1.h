#pragma once
#include "GameLogic.h"
#include "stdafx.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include "Form2.h"
#include "Form3.h"

namespace WindowsFormsApplication1 {

	

	using namespace msclr::interop;
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	struct playerStats{
		int rank;
		string playerName;
		int shotsFired;
		double yourHitPercent;
		int score;
	};

	public ref class Form1 : public System::Windows::Forms::Form{

	public:
		Form1(void)
		{
			InitializeComponent();
		}

	public: 
	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

		Grid* playerGrid;//ht
		Grid* computerGrid;//ht
		int shipCounter;
		bool isVertical;
		int computerShips;
		int playerShips;
		double playerShotsMiss;
		double compShotsMiss;
		double totalShots;
		double playerHitPercent;
		double computerHitPercent;

		


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  a_AttackPos;
	private: System::Windows::Forms::TextBox^  b_AttackPos;
	private: System::Windows::Forms::Button^  ShootShipButton;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  a_PlacePos;
	private: System::Windows::Forms::TextBox^  b_PlacePos;
	private: System::Windows::Forms::Button^  PlaceShipButton;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  SaveButton;


	private: System::Windows::Forms::Button^  LoadButton;
	private: System::Windows::Forms::TextBox^  PlayerStatus;
	private: System::Windows::Forms::Button^  ResetButton;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TextBox^  ComputerStatus;
	private: System::Windows::Forms::TextBox^  PlayerScore;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  saveText;
	private: System::Windows::Forms::Label^  label9;

	private: System::Windows::Forms::Button^  HelpButton;
	private: System::Windows::Forms::Button^  Stats;



	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 void InitializeComponent(void){
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->a_AttackPos = (gcnew System::Windows::Forms::TextBox());
				 this->b_AttackPos = (gcnew System::Windows::Forms::TextBox());
				 this->ShootShipButton = (gcnew System::Windows::Forms::Button());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->a_PlacePos = (gcnew System::Windows::Forms::TextBox());
				 this->b_PlacePos = (gcnew System::Windows::Forms::TextBox());
				 this->PlaceShipButton = (gcnew System::Windows::Forms::Button());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->SaveButton = (gcnew System::Windows::Forms::Button());
				 this->LoadButton = (gcnew System::Windows::Forms::Button());
				 this->PlayerStatus = (gcnew System::Windows::Forms::TextBox());
				 this->ResetButton = (gcnew System::Windows::Forms::Button());
				 this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				 this->ComputerStatus = (gcnew System::Windows::Forms::TextBox());
				 this->PlayerScore = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->saveText = (gcnew System::Windows::Forms::TextBox());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->HelpButton = (gcnew System::Windows::Forms::Button());
				 this->Stats = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(204, 310);
				 this->label2->Name = L"label2";
				 this->label2->RightToLeft = System::Windows::Forms::RightToLeft::No;
				 this->label2->Size = System::Drawing::Size(57, 13);
				 this->label2->TabIndex = 2;
				 this->label2->Text = L"A Position:";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(204, 334);
				 this->label3->Name = L"label3";
				 this->label3->RightToLeft = System::Windows::Forms::RightToLeft::No;
				 this->label3->Size = System::Drawing::Size(57, 13);
				 this->label3->TabIndex = 3;
				 this->label3->Text = L"B Position:";
				 // 
				 // a_AttackPos
				 // 
				 this->a_AttackPos->Location = System::Drawing::Point(267, 307);
				 this->a_AttackPos->MaxLength = 2;
				 this->a_AttackPos->Name = L"a_AttackPos";
				 this->a_AttackPos->ReadOnly = true;
				 this->a_AttackPos->Size = System::Drawing::Size(59, 20);
				 this->a_AttackPos->TabIndex = 3;
				 this->a_AttackPos->Text = L"1";
				 this->a_AttackPos->TextChanged += gcnew System::EventHandler(this, &Form1::a_AttackPos_TextChanged);
				 // 
				 // b_AttackPos
				 // 
				 this->b_AttackPos->Location = System::Drawing::Point(267, 331);
				 this->b_AttackPos->MaxLength = 2;
				 this->b_AttackPos->Name = L"b_AttackPos";
				 this->b_AttackPos->ReadOnly = true;
				 this->b_AttackPos->Size = System::Drawing::Size(59, 20);
				 this->b_AttackPos->TabIndex = 4;
				 this->b_AttackPos->Text = L"1";
				 this->b_AttackPos->TextChanged += gcnew System::EventHandler(this, &Form1::b_AttackPos_TextChanged);
				 // 
				 // ShootShipButton
				 // 
				 this->ShootShipButton->Enabled = false;
				 this->ShootShipButton->Location = System::Drawing::Point(231, 360);
				 this->ShootShipButton->Name = L"ShootShipButton";
				 this->ShootShipButton->Size = System::Drawing::Size(68, 37);
				 this->ShootShipButton->TabIndex = 6;
				 this->ShootShipButton->Text = L"HIT!";
				 this->ShootShipButton->UseVisualStyleBackColor = true;
				 this->ShootShipButton->Click += gcnew System::EventHandler(this, &Form1::ShootShipButton_Click);
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(24, 291);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(95, 13);
				 this->label4->TabIndex = 8;
				 this->label4->Text = L"Set Ship Positions:";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(24, 310);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(57, 13);
				 this->label5->TabIndex = 9;
				 this->label5->Text = L"A Position:";
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Location = System::Drawing::Point(24, 334);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(57, 13);
				 this->label6->TabIndex = 10;
				 this->label6->Text = L"B Position:";
				 // 
				 // a_PlacePos
				 // 
				 this->a_PlacePos->ForeColor = System::Drawing::SystemColors::MenuText;
				 this->a_PlacePos->Location = System::Drawing::Point(87, 307);
				 this->a_PlacePos->MaxLength = 6;
				 this->a_PlacePos->Name = L"a_PlacePos";
				 this->a_PlacePos->Size = System::Drawing::Size(59, 20);
				 this->a_PlacePos->TabIndex = 1;
				 this->a_PlacePos->Text = L"1";
				 this->a_PlacePos->TextChanged += gcnew System::EventHandler(this, &Form1::a_PlacePos_TextChanged);
				 // 
				 // b_PlacePos
				 // 
				 this->b_PlacePos->Location = System::Drawing::Point(87, 331);
				 this->b_PlacePos->MaxLength = 6;
				 this->b_PlacePos->Name = L"b_PlacePos";
				 this->b_PlacePos->Size = System::Drawing::Size(59, 20);
				 this->b_PlacePos->TabIndex = 2;
				 this->b_PlacePos->Text = L"1";
				 this->b_PlacePos->TextChanged += gcnew System::EventHandler(this, &Form1::b_PlacePos_TextChanged);
				 // 
				 // PlaceShipButton
				 // 
				 this->PlaceShipButton->Location = System::Drawing::Point(112, 360);
				 this->PlaceShipButton->Name = L"PlaceShipButton";
				 this->PlaceShipButton->Size = System::Drawing::Size(74, 37);
				 this->PlaceShipButton->TabIndex = 13;
				 this->PlaceShipButton->Text = L"Place Ship";
				 this->PlaceShipButton->UseVisualStyleBackColor = true;
				 this->PlaceShipButton->Click += gcnew System::EventHandler(this, &Form1::PlaceShipButton_Click);
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(204, 291);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(71, 13);
				 this->label7->TabIndex = 14;
				 this->label7->Text = L"Attack Mode:";
				 // 
				 // SaveButton
				 // 
				 this->SaveButton->Enabled = false;
				 this->SaveButton->Location = System::Drawing::Point(545, 83);
				 this->SaveButton->Name = L"SaveButton";
				 this->SaveButton->Size = System::Drawing::Size(75, 23);
				 this->SaveButton->TabIndex = 15;
				 this->SaveButton->Text = L"Save";
				 this->SaveButton->UseVisualStyleBackColor = true;
				 this->SaveButton->Click += gcnew System::EventHandler(this, &Form1::SaveButton_Click);
				 // 
				 // LoadButton
				 // 
				 this->LoadButton->Location = System::Drawing::Point(545, 112);
				 this->LoadButton->Name = L"LoadButton";
				 this->LoadButton->Size = System::Drawing::Size(75, 23);
				 this->LoadButton->TabIndex = 16;
				 this->LoadButton->Text = L"Load";
				 this->LoadButton->UseVisualStyleBackColor = true;
				 this->LoadButton->Click += gcnew System::EventHandler(this, &Form1::LoadButton_Click);
				 // 
				 // PlayerStatus
				 // 
				 this->PlayerStatus->BackColor = System::Drawing::SystemColors::ActiveCaption;
				 this->PlayerStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->PlayerStatus->Location = System::Drawing::Point(339, 83);
				 this->PlayerStatus->Name = L"PlayerStatus";
				 this->PlayerStatus->ReadOnly = true;
				 this->PlayerStatus->Size = System::Drawing::Size(200, 21);
				 this->PlayerStatus->TabIndex = 17;
				 this->PlayerStatus->Text = L"Player Status";
				 this->PlayerStatus->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				 this->PlayerStatus->TextChanged += gcnew System::EventHandler(this, &Form1::PlayerStatus_TextChanged);
				 // 
				 // ResetButton
				 // 
				 this->ResetButton->Location = System::Drawing::Point(465, 53);
				 this->ResetButton->Name = L"ResetButton";
				 this->ResetButton->Size = System::Drawing::Size(74, 23);
				 this->ResetButton->TabIndex = 18;
				 this->ResetButton->Text = L"Reset Game";
				 this->ResetButton->UseVisualStyleBackColor = true;
				 this->ResetButton->Click += gcnew System::EventHandler(this, &Form1::ResetButton_Click);
				 // 
				 // checkBox1
				 // 
				 this->checkBox1->AutoSize = true;
				 this->checkBox1->Location = System::Drawing::Point(8, 371);
				 this->checkBox1->Name = L"checkBox1";
				 this->checkBox1->Size = System::Drawing::Size(98, 17);
				 this->checkBox1->TabIndex = 19;
				 this->checkBox1->Text = L"Place Vertically";
				 this->checkBox1->UseVisualStyleBackColor = true;
				 this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
				 // 
				 // ComputerStatus
				 // 
				 this->ComputerStatus->BackColor = System::Drawing::SystemColors::ActiveCaption;
				 this->ComputerStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->ComputerStatus->Location = System::Drawing::Point(339, 114);
				 this->ComputerStatus->Name = L"ComputerStatus";
				 this->ComputerStatus->ReadOnly = true;
				 this->ComputerStatus->Size = System::Drawing::Size(200, 21);
				 this->ComputerStatus->TabIndex = 20;
				 this->ComputerStatus->Text = L"Computer Status";
				 this->ComputerStatus->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				 // 
				 // PlayerScore
				 // 
				 this->PlayerScore->BackColor = System::Drawing::SystemColors::ActiveCaption;
				 this->PlayerScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->PlayerScore->Location = System::Drawing::Point(339, 54);
				 this->PlayerScore->Name = L"PlayerScore";
				 this->PlayerScore->Size = System::Drawing::Size(56, 21);
				 this->PlayerScore->TabIndex = 21;
				 this->PlayerScore->Text = L"Score";
				 this->PlayerScore->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				 this->PlayerScore->TextChanged += gcnew System::EventHandler(this, &Form1::PlayerScore_TextChanged);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
				 this->label1->Location = System::Drawing::Point(98, 310);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(33, 13);
				 this->label1->TabIndex = 22;
				 this->label1->Text = L"Ships";
				 this->label1->Visible = false;
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->BackColor = System::Drawing::SystemColors::ButtonHighlight;
				 this->label8->Location = System::Drawing::Point(98, 334);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(40, 13);
				 this->label8->TabIndex = 23;
				 this->label8->Text = L"Placed";
				 this->label8->Visible = false;
				 // 
				 // saveText
				 // 
				 this->saveText->Location = System::Drawing::Point(545, 54);
				 this->saveText->MaxLength = 10;
				 this->saveText->Name = L"saveText";
				 this->saveText->Size = System::Drawing::Size(75, 20);
				 this->saveText->TabIndex = 24;
				 this->saveText->Text = L"Save/Load As";
				 this->saveText->TextChanged += gcnew System::EventHandler(this, &Form1::saveText_TextChanged);
				 // 
				 // label9
				 // 
				 this->label9->Location = System::Drawing::Point(12, 400);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(100, 21);
				 this->label9->TabIndex = 25;
				 // 
				 // HelpButton
				 // 
				 this->HelpButton->Location = System::Drawing::Point(401, 53);
				 this->HelpButton->Name = L"HelpButton";
				 this->HelpButton->Size = System::Drawing::Size(58, 23);
				 this->HelpButton->TabIndex = 27;
				 this->HelpButton->Text = L"Help";
				 this->HelpButton->UseVisualStyleBackColor = true;
				 this->HelpButton->Click += gcnew System::EventHandler(this, &Form1::HelpButton_Click);
				 // 
				 // Stats
				 // 
				 this->Stats->Location = System::Drawing::Point(287, 53);
				 this->Stats->Name = L"Stats";
				 this->Stats->Size = System::Drawing::Size(46, 23);
				 this->Stats->TabIndex = 28;
				 this->Stats->Text = L"Stats";
				 this->Stats->UseVisualStyleBackColor = true;
				 this->Stats->Click += gcnew System::EventHandler(this, &Form1::Stats_Click);
				 // 
				 // Form1
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::SystemColors::ActiveCaption;
				 this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
				 this->ClientSize = System::Drawing::Size(643, 414);
				 this->Controls->Add(this->Stats);
				 this->Controls->Add(this->HelpButton);
				 this->Controls->Add(this->label9);
				 this->Controls->Add(this->saveText);
				 this->Controls->Add(this->label8);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->PlayerScore);
				 this->Controls->Add(this->ComputerStatus);
				 this->Controls->Add(this->checkBox1);
				 this->Controls->Add(this->ResetButton);
				 this->Controls->Add(this->PlayerStatus);
				 this->Controls->Add(this->LoadButton);
				 this->Controls->Add(this->SaveButton);
				 this->Controls->Add(this->ShootShipButton);
				 this->Controls->Add(this->label7);
				 this->Controls->Add(this->PlaceShipButton);
				 this->Controls->Add(this->b_PlacePos);
				 this->Controls->Add(this->a_PlacePos);
				 this->Controls->Add(this->label6);
				 this->Controls->Add(this->label5);
				 this->Controls->Add(this->label4);
				 this->Controls->Add(this->b_AttackPos);
				 this->Controls->Add(this->a_AttackPos);
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->label2);
				 this->DoubleBuffered = true;
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				 this->Name = L"Form1";
				 this->Text = L"Battleship!";
				 this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }

#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 playerGrid = new Grid();
				 computerGrid = new Grid();
				 computerGrid->loaded = false;
				 computerShips = 0;
				 playerShips = 0;
				 shipCounter = 0;
				 playerShotsMiss = 0;
				 compShotsMiss = 0;
				 totalShots = 0;

				 computerGrid->AIsetup();
			 }

			 //Shoot button
	private: System::Void ShootShipButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 playerStats currentUser;
				 int x = int::Parse(a_AttackPos -> Text);
				 int y = int::Parse(b_AttackPos -> Text);
				 int score;
				 if (PlayerScore -> Text == "Score"){
					 score = 0;
				 }else{
					 score = int::Parse(PlayerScore -> Text);
				 }
				 if ((x >= 1) && (x <= 10) && (y >= 1) && (y <= 10)){
					 totalShots++;
					 if (computerGrid->shoot(x,y)==0){
						 return;
					 }

					 if (computerGrid->getBlock(x,y) == 3){
						 PlayerStatus -> Text = "Player Missed";
						 playerShotsMiss++;
					 }
					 else if (computerGrid->getBlock(x,y) == 2){
						 if (computerGrid -> isSunk(x,y) == -1){
							 PlayerStatus -> Text = "Player hit, Ship not sunk";
						 }
						 else{
							 if (computerGrid -> isSunk(x,y) == 0){
								 computerShips++;
								 PlayerStatus -> Text = "Player hit, Submarine sunk";
								 score = score + 50;
							 }
							 else if (computerGrid -> isSunk(x,y) == 1){
								 computerShips++;
								 PlayerStatus -> Text = "Player hit, Submarine sunk";
								 score = score + 50;
							 }
							 else if (computerGrid -> isSunk(x,y) == 2){
								 computerShips++;
								 PlayerStatus -> Text = "Player hit, Destroyer sunk";
								 score = score + 40;
							 }
							 else if (computerGrid -> isSunk(x,y) == 3){
								 computerShips++;
								 PlayerStatus -> Text = "Player hit, Destroyer sunk";
								 score = score + 40;
							 }
							 else if (computerGrid -> isSunk(x,y) == 4){
								 computerShips++;
								 PlayerStatus -> Text = "Player hit, Cruiser sunk";
								 score = score + 30;
							 }
							 else if (computerGrid -> isSunk(x,y) == 5){
								 computerShips++;
								 PlayerStatus -> Text = "Player hit, Battleship sunk";
								 score = score + 20;
							 }
							 else{
								 computerShips++;
								 PlayerStatus -> Text = "Player hit, Aircraft carrier sunk";
								 score = score + 10;
							 }
						 }

					 }

					 int* computerShot = playerGrid -> MediumAIshoot();

					 if (playerGrid->getBlock(computerShot[0],computerShot[1]) == 3){
						 compShotsMiss++;
						 ComputerStatus -> Text = "Computer Missed";
					 }
					 else if (playerGrid->getBlock(computerShot[0],computerShot[1]) == 2){
						 if (playerGrid -> isSunk(computerShot[0],computerShot[1]) == -1){
							 ComputerStatus -> Text = "Computer hit, Ship not sunk";
						 }
						 else{
							 if (playerGrid -> isSunk(computerShot[0],computerShot[1]) == 0){
								 playerShips++;
								 ComputerStatus -> Text = "Computer hit, Submarine sunk";
								 score = score - 50;
							 }
							 else if (playerGrid -> isSunk(computerShot[0],computerShot[1]) == 1){
								 playerShips++;
								 ComputerStatus -> Text = "Computer hit, Submarine sunk";
								 score = score - 50;
							 }
							 else if (playerGrid -> isSunk(computerShot[0],computerShot[1]) == 2){
								 playerShips++;
								 ComputerStatus -> Text = "Computer hit, Destroyer sunk";
								 score = score - 40;
							 }
							 else if (playerGrid -> isSunk(computerShot[0],computerShot[1]) == 3){
								 playerShips++;
								 ComputerStatus -> Text = "Computer hit, Destroyer sunk";
								 score = score - 40;
							 }
							 else if (playerGrid -> isSunk(computerShot[0],computerShot[1]) == 4){
								 playerShips++;
								 ComputerStatus -> Text = "Computer hit, Cruiser sunk";
								 score = score - 30;
							 }
							 else if (playerGrid -> isSunk(computerShot[0],computerShot[1]) == 5){
								 playerShips++;
								 ComputerStatus -> Text = "Computer hit, Battleship sunk";
								 score = score - 20;
							 }
							 else{
								 playerShips++;
								 ComputerStatus -> Text = "Computer hit, Aircraft carrier sunk";
								 score = score - 10;
							 }
						 }
					 }

					 //displays the endgame and saves statistics.
					 if(computerShips == 7){
						//checks the save textbox to see if it has a name input at the end of game.
						std::string saveAs = (marshal_as<std::string>(saveText -> Text));
						bool contains_non_alpha = saveAs.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != std::string::npos;
						if (contains_non_alpha || saveAs == ""){
							 MessageBox::Show("Please enter a name in ""Save/Load"" to store your score, only letters are allowed",
							"Error", MessageBoxButtons::OK,
							MessageBoxIcon::Asterisk);
						    return;
						 } else {
								 //if successfull it stores users stats into a playerstats object called currentUser.
								//The playerstats structure is located at top of this file.
								 currentUser.playerName = (marshal_as<std::string>(saveText -> Text));
								 currentUser.score = score;
								 currentUser.shotsFired = totalShots;
								 currentUser.yourHitPercent = playerHitPercent;
								 //runs my highscore function to append users stats to a textfile.
								 playerGrid->statistics(currentUser.playerName + "scores.txt", currentUser.playerName, currentUser.yourHitPercent, currentUser.shotsFired, currentUser.score);
								 //displays win message
								 MessageBox::Show("You Win!!",
								 "GameOver", MessageBoxButtons::OK,
								 MessageBoxIcon::Asterisk);
								 Application::Restart();
								 Form1::Show(); 
								 return;
						 }
					 
					 }
					 else if(playerShips == 7){
							//displays a "YOU LOSE" message.
						     MessageBox::Show("You Lose",
						     "GameOver", MessageBoxButtons::OK,
						     MessageBoxIcon::Asterisk);
						     Application::Restart();
						     Form1::Show(); 
						     return;
					 }

					 PlayerScore -> Text = score + "";

					 //stats for hit percent
					 if(totalShots >= 1){
					 playerHitPercent = ((totalShots - playerShotsMiss) / totalShots)*100;
					 computerHitPercent = ((totalShots - compShotsMiss) / totalShots)*100;
					 }


					 //Black Boxes
					 System::Drawing::SolidBrush^ myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
					 System::Drawing::Graphics^ formGraphics;

					 formGraphics = this->CreateGraphics();
					 formGraphics->FillRectangle(myBrush, System::Drawing::Rectangle(369 , 161, 243, 243));

					 formGraphics = this->CreateGraphics();
					 formGraphics->FillRectangle(myBrush, System::Drawing::Rectangle(32 , 33, 243, 243));

					 delete myBrush;
					 delete formGraphics;

					 for (int i = 1; i < 11; i++){
						 for (int j=1;j<11;j++){
							 int colorz = computerGrid->getBlock(i,j);
							 if (colorz == 0){
								 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightBlue);
							 }else if (colorz == 1){
								 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightBlue);
							 }else if (colorz == 2){
								 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red);
							 } else{
								 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightGray);
							 }
							 System::Drawing::Graphics^ formGraphics;
							 formGraphics = this->CreateGraphics();
							 formGraphics->FillRectangle(myBrush, System::Drawing::Rectangle(369 +(i-1)+ 23*(i - 1), 162+ (j-1) + 23*(j - 1), 23, 23));
							 delete myBrush;
							 delete formGraphics;
						 }
					 }

					 for (int i = 1; i < 11; i++){
						 for (int j=1;j<11;j++){
							 int colorz = playerGrid->getBlock(i,j);
							 if (colorz == 0){
								 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightBlue);
							 }else if (colorz == 1){
								 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
							 }else if (colorz == 2){
								 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red);
							 } else{
								 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightGreen);
							 }
							 System::Drawing::Graphics^ formGraphics;
							 formGraphics = this->CreateGraphics();
							 formGraphics->FillRectangle(myBrush, System::Drawing::Rectangle(32 +(i-1)+ 23*(i - 1), 33+ (j-1) + 23*(j - 1), 23, 23));
							 delete myBrush;
							 delete formGraphics;
						 }
					 }

				 }
			 }

			 //Place ship button
	private: System::Void PlaceShipButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 int x1 = int::Parse(a_PlacePos -> Text);
				 int y1 = int::Parse(b_PlacePos -> Text);
				 if ((x1 >= 1) && (x1 <= 10) && (y1 >= 1) && (y1 <= 10)){
					 int orientation;
					 if (isVertical){
						 orientation = 1;
					 }
					 else{
						 orientation = 0;
					 }
					 if (shipCounter <= 6){
						 if (playerGrid->addShip(shipCounter,orientation,x1,y1)){
							 shipCounter++;
						 }
					 }

					 if (shipCounter == 7){
						 ShootShipButton -> Enabled = true;
						 checkBox1 -> Enabled = false;
						 a_PlacePos ->Visible = false;
						 b_PlacePos ->Visible = false;
						 label1 -> Visible = true;
						 label8 -> Visible = true;
						 a_AttackPos ->Text = "1";
						 a_AttackPos ->ReadOnly = false;
						 b_AttackPos ->Text = "1";
						 b_AttackPos ->ReadOnly = false;
						 SaveButton->Enabled = true;
						 PlaceShipButton -> Enabled = false;
					 }

					 System::Drawing::SolidBrush^ myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
					 System::Drawing::Graphics^ formGraphics;
					 formGraphics = this->CreateGraphics();
					 formGraphics->FillRectangle(myBrush, System::Drawing::Rectangle(32 , 33, 243, 243));

					 delete myBrush;
					 delete formGraphics;

					 for (int i = 1; i < 11; i++){
						 for (int j=1;j<11;j++){
							 int colorz = playerGrid->getBlock(i,j);
							 if (colorz == 0){
								 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightBlue);
							 }else if (colorz == 1){
								 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
							 }else if (colorz == 2){
								 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red);
							 } else{
								 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightGreen);
							 }
							 System::Drawing::Graphics^ formGraphics;
							 formGraphics = this->CreateGraphics();
							 formGraphics->FillRectangle(myBrush, System::Drawing::Rectangle(32 +(i-1)+ 23*(i - 1), 33+ (j-1) + 23*(j - 1), 23, 23));
							 delete myBrush;
							 delete formGraphics;
						 }
					 }
				 }

				 a_PlacePos -> Text = "1";
				 b_PlacePos -> Text = "1";
			 }

			 //Save, load and restart buttons
	private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 std::string saveAs = (marshal_as<std::string>(saveText -> Text));
				 bool contains_non_alpha = saveAs.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != std::string::npos;
				 if (contains_non_alpha || saveAs == ""){
					 MessageBox::Show("Please enter a name, only letters are allowed",
						 "Error", MessageBoxButtons::OK,
						 MessageBoxIcon::Asterisk);
					 return;
				 } else {
					 MessageBox::Show("Saved as "+saveText -> Text,
						 "Success!", MessageBoxButtons::OK,
						 MessageBoxIcon::Asterisk);
				 }
				 int score;
				 if (PlayerScore -> Text == "Score"){
					 score = 0; 
				 } else {
					 score = int::Parse(PlayerScore -> Text);
				 }
				 playerGrid -> save("z"+ saveAs + "_player", score, playerShips, playerHitPercent, totalShots);
				 computerGrid -> save("z"+ saveAs + "_computer", score, computerShips,computerHitPercent, totalShots);


			 }
	private: System::Void LoadButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 computerGrid->loaded=true;
				 computerGrid->clear();

				 //displays a message box to user according to if the file name was valid or invalid.
				 std::string saveAs = (marshal_as<std::string>(saveText -> Text));
				 bool contains_non_alpha = saveAs.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != std::string::npos;
				 if (contains_non_alpha || saveAs == ""){
					 MessageBox::Show("Please enter a name, only letters are allowed",
						 "Error", MessageBoxButtons::OK,
						 MessageBoxIcon::Asterisk);
					 return;
				 }
				 playerGrid -> load("z"+ saveAs + "_player");
				 int score = computerGrid -> load("z"+ saveAs + "_computer");

				 //Gets the player/AI sunkenships value from save file.
				 computerShips = computerGrid -> sunkenShips("z"+ saveAs + "_computer");
				 playerShips = playerGrid -> sunkenShips("z"+ saveAs + "_player");

				 //gets the player/AI hit percents from the save file.
				 playerHitPercent = playerGrid -> HitPercent("z"+ saveAs + "_player");
				 computerHitPercent = computerGrid -> HitPercent("z"+ saveAs + "_computer");

				 //loads the total number of shots from the save file.
				 totalShots = playerGrid -> totalShots("z"+ saveAs + "_player");
   				 playerShotsMiss = totalShots - ((playerHitPercent/100)*totalShots);
				 compShotsMiss = totalShots - ((computerHitPercent/100)*totalShots);

				 if (score == -1){
					 MessageBox::Show("Save file not found",
						 "Error", MessageBoxButtons::OK,
						 MessageBoxIcon::Asterisk);
					 return;
				 }
				 PlayerScore -> Text = score + "";


				 shipCounter = 7;
				 ShootShipButton -> Enabled = true;
				 PlaceShipButton -> Enabled = false;
				 SaveButton -> Enabled = true;
				 checkBox1 -> Enabled = false;
				 a_PlacePos ->Visible = false;
				 b_PlacePos ->Visible = false;
				 label1 -> Visible = true;
				 label8 -> Visible = true;
				 a_AttackPos ->Text = "1";
				 a_AttackPos ->ReadOnly = false;
				 b_AttackPos ->Text = "1";
				 b_AttackPos ->ReadOnly = false;


				 System::Drawing::SolidBrush^ myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
				 System::Drawing::Graphics^ formGraphics;

				 formGraphics = this->CreateGraphics();
				 formGraphics->FillRectangle(myBrush, System::Drawing::Rectangle(369 , 161, 243, 243));

				 formGraphics = this->CreateGraphics();
				 formGraphics->FillRectangle(myBrush, System::Drawing::Rectangle(32 , 33, 243, 243));

				 delete myBrush;
				 delete formGraphics;

				 for (int i = 1; i < 11; i++){
					 for (int j=1;j<11;j++){
						 int colorz = playerGrid->getBlock(i,j);
						 if (colorz == 0){
							 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightBlue);
						 }else if (colorz == 1){
							 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
						 }else if (colorz == 2){
							 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red);
						 } else{
							 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightGreen);
						 }
						 System::Drawing::Graphics^ formGraphics;
						 formGraphics = this->CreateGraphics();
						 formGraphics->FillRectangle(myBrush, System::Drawing::Rectangle(32 +(i-1)+ 23*(i - 1), 33+ (j-1) + 23*(j - 1), 23, 23));
						 delete myBrush;
						 delete formGraphics;
					 }
				 }
				 for (int i = 1; i < 11; i++){
					 for (int j=1;j<11;j++){
						 int colorz = computerGrid->getBlock(i,j);
						 if (colorz == 0){
							 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightBlue);
						 }else if (colorz == 1){
							 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightBlue);
						 }else if (colorz == 2){
							 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red);
						 } else{
							 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightGray);
						 }
						 System::Drawing::Graphics^ formGraphics;
						 formGraphics = this->CreateGraphics();
						 formGraphics->FillRectangle(myBrush, System::Drawing::Rectangle(369 +(i-1)+ 23*(i - 1), 162+ (j-1) + 23*(j - 1), 23, 23));
						 delete myBrush;
						 delete formGraphics;
					 }
				 }
			 }
	private: System::Void ResetButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Restart();
				 Form1::Show();
			 }

			 //Orientation checkbox
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 isVertical = !isVertical;
			 }

			 //Getting rid of boxes after we use them
	private: System::Void a_PlacePos_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (((a_PlacePos -> Text == "1") || (a_PlacePos -> Text == "2") || (a_PlacePos -> Text == "3") || 
					 (a_PlacePos -> Text == "4") || (a_PlacePos -> Text == "5") || (a_PlacePos -> Text == "6") ||
					 (a_PlacePos -> Text == "7") || (a_PlacePos -> Text == "8") || (a_PlacePos -> Text == "9") ||
					 (a_PlacePos -> Text == "10")) && ((b_PlacePos -> Text == "1") || (b_PlacePos -> Text == "2") || (b_PlacePos -> Text == "3") || 
					 (b_PlacePos -> Text == "4") || (b_PlacePos -> Text == "5") || (b_PlacePos -> Text == "6") ||
					 (b_PlacePos -> Text == "7") || (b_PlacePos -> Text == "8") || (b_PlacePos -> Text == "9") ||
					 (b_PlacePos -> Text == "10"))){
						 a_PlacePos -> ForeColor = Color::Black;
						 b_PlacePos -> ForeColor = Color::Black;
						 PlaceShipButton -> Enabled = true;
				 }else{
					 a_PlacePos -> ForeColor = Color::Red;
					 b_PlacePos -> ForeColor = Color::Red;
					 PlaceShipButton -> Enabled = false;
				 }
			 }
	private: System::Void b_PlacePos_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (((b_PlacePos -> Text == "1") || (b_PlacePos -> Text == "2") || (b_PlacePos -> Text == "3") || 
					 (b_PlacePos -> Text == "4") || (b_PlacePos -> Text == "5") || (b_PlacePos -> Text == "6") ||
					 (b_PlacePos -> Text == "7") || (b_PlacePos -> Text == "8") || (b_PlacePos -> Text == "9") ||
					 (b_PlacePos -> Text == "10")) && ((a_PlacePos -> Text == "1") || (a_PlacePos -> Text == "2") || (a_PlacePos -> Text == "3") || 
					 (a_PlacePos -> Text == "4") || (a_PlacePos -> Text == "5") || (a_PlacePos -> Text == "6") ||
					 (a_PlacePos -> Text == "7") || (a_PlacePos -> Text == "8") || (a_PlacePos -> Text == "9") ||
					 (a_PlacePos -> Text == "10"))){
						 a_PlacePos -> ForeColor = Color::Black;
						 b_PlacePos -> ForeColor = Color::Black;
						 PlaceShipButton-> Enabled = true;
				 }else{
					 b_PlacePos -> ForeColor = Color::Red;
					 a_PlacePos -> ForeColor = Color::Red;
					 PlaceShipButton -> Enabled = false;
				 } 
			 }	
	private: System::Void a_AttackPos_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (((a_AttackPos -> Text == "1") || (a_AttackPos -> Text == "2") || (a_AttackPos -> Text == "3") || 
					 (a_AttackPos -> Text == "4") || (a_AttackPos -> Text == "5") || (a_AttackPos -> Text == "6") ||
					 (a_AttackPos -> Text == "7") || (a_AttackPos -> Text == "8") || (a_AttackPos -> Text == "9") ||
					 (a_AttackPos -> Text == "10")) && ((b_AttackPos -> Text == "1") || (b_AttackPos -> Text == "2") || (b_AttackPos -> Text == "3") || 
					 (b_AttackPos -> Text == "4") || (b_AttackPos -> Text == "5") || (b_AttackPos -> Text == "6") ||
					 (b_AttackPos -> Text == "7") || (b_AttackPos -> Text == "8") || (b_AttackPos -> Text == "9") ||
					 (b_AttackPos -> Text == "10"))){
						 a_AttackPos -> ForeColor = Color::Black;
						 b_AttackPos -> ForeColor = Color::Black;
						 ShootShipButton-> Enabled = true;
				 }else{
					 a_AttackPos -> ForeColor = Color::Red;
					 b_AttackPos -> ForeColor = Color::Red;
					 ShootShipButton -> Enabled = false;
				 } 
			 }
	private: System::Void b_AttackPos_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (((b_AttackPos -> Text == "1") || (b_AttackPos -> Text == "2") || (b_AttackPos -> Text == "3") || 
					 (b_AttackPos -> Text == "4") || (b_AttackPos -> Text == "5") || (b_AttackPos -> Text == "6") ||
					 (b_AttackPos -> Text == "7") || (b_AttackPos -> Text == "8") || (b_AttackPos -> Text == "9") ||
					 (b_AttackPos -> Text == "10")) && ((a_AttackPos -> Text == "1") || (a_AttackPos -> Text == "2") || (a_AttackPos -> Text == "3") || 
					 (a_AttackPos -> Text == "4") || (a_AttackPos -> Text == "5") || (a_AttackPos -> Text == "6") ||
					 (a_AttackPos -> Text == "7") || (a_AttackPos -> Text == "8") || (a_AttackPos -> Text == "9") ||
					 (a_AttackPos -> Text == "10"))){
						 a_AttackPos -> ForeColor = Color::Black;
						 b_AttackPos -> ForeColor = Color::Black;
						 ShootShipButton -> Enabled = true;
				 }else{
					 a_AttackPos -> ForeColor = Color::Red;
					 b_AttackPos -> ForeColor = Color::Red;
					 ShootShipButton -> Enabled = false;
				 } 
			 }

			 //Pause Button


	private: System::Void saveText_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 std::string saveAs = (marshal_as<std::string>(saveText -> Text));
				 bool contains_non_alpha = saveAs.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != std::string::npos;
				 if (!contains_non_alpha && !(saveAs == "")){
					 std::ifstream ifile("z"+saveAs+"_computer.txt");
					 if (ifile){
						 Grid* scoreGrid;
						 scoreGrid = new Grid();
						 label9->Text = saveText->Text + "'s best: " + (scoreGrid->load("z"+ saveAs + "_computer")+"");
					 }
					 ifile.close();
				 }
			 }
	private: System::Void PlayerStatus_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void PlayerScore_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void HelpButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 Form2^ help = gcnew Form2;
			 help -> ShowDialog();
		 }

private: System::Void Stats_Click(System::Object^  sender, System::EventArgs^  e) {
			 //Loads an instance of form3 called stats, the form i want to display stats on.
			 Form3^ stats = gcnew Form3;
			 stats -> ShowDialog();	 
		 }
};
}