#pragma once
#include "GameLogic.h"
#include <fstream>

namespace WindowsFormsApplication1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;


	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(2, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(173, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"1. Enter co-ordinates for your ships.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(2, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(308, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"2. Check \"Place Vertical\" if you wish to place the ship vertically.";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(2, 65);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(233, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"3. Click the place ship button to place your ship.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(2, 87);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(293, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"4. Once all ships are placed choose co-ordinates to shoot at.";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(2, 112);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(235, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"5. Press the \"HIT!\" button to shoot enemy ships.";
			this->label5->Click += gcnew System::EventHandler(this, &Form2::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(2, 134);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(321, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"6. Repeat the shooting process until all of a players ships are sunk.";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(95, 8);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(93, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Play The Game";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(95, 168);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(70, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Save/Load";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(2, 181);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(352, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"1. Enter the name you wish to save your file as into the save/load textbox";
			this->label9->Click += gcnew System::EventHandler(this, &Form2::label9_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(2, 203);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(204, 13);
			this->label10->TabIndex = 9;
			this->label10->Text = L"2. Press either the save or the load button";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(2, 225);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(227, 13);
			this->label11->TabIndex = 10;
			this->label11->Text = L"3. Press the restart button to start a new game.";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(95, 330);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(100, 13);
			this->label12->TabIndex = 11;
			this->label12->Text = L"**Additional Notes**";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(2, 356);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(215, 13);
			this->label13->TabIndex = 12;
			this->label13->Text = L"Your save/load file must only contain letters.";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(2, 343);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(308, 13);
			this->label14->TabIndex = 13;
			this->label14->Text = L"Your grid co-ordinates must be integer values between 1 and 10";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(95, 248);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(89, 13);
			this->label15->TabIndex = 14;
			this->label15->Text = L"User Statistics";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(2, 261);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(136, 13);
			this->label16->TabIndex = 15;
			this->label16->Text = L"1. Click on the stats button.";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(2, 283);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(116, 13);
			this->label17->TabIndex = 16;
			this->label17->Text = L"2. Enter a player name.";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(2, 308);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(152, 13);
			this->label18->TabIndex = 17;
			this->label18->Text = L"3. Press the show stats button.";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(3, 369);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(184, 13);
			this->label19->TabIndex = 18;
			this->label19->Text = L"Deletion of player stats is unavailable.";
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(352, 391);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form2";
			this->Text = L"How To Play";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e) {

			 }
	private: System::Void Winner_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void label9_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
