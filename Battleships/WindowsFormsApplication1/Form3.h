#pragma once
#include "GameLogic.h"
#include "stdafx.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <string>


namespace WindowsFormsApplication1 {

	using namespace System;
	using namespace msclr::interop;
	using namespace std;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form3
	/// </summary>
	public ref class Form3 : public System::Windows::Forms::Form
	{
	public:
		Form3(void)
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
		~Form3()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
		Grid* playerGrid;
		Grid* computerGrid;
		int computerShips;
		int playerShips;
		double playerShotsMiss;
		double compShotsMiss;
		double totalShots;
		double playerHitPercent;
		double computerHitPercent;

	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  statsButton;
	private: System::Windows::Forms::TextBox^  Stats;
	private: System::Windows::Forms::Label^  showStats;


	protected: 

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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->statsButton = (gcnew System::Windows::Forms::Button());
			this->Stats = (gcnew System::Windows::Forms::TextBox());
			this->showStats = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(5, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(390, 230);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// statsButton
			// 
			this->statsButton->Location = System::Drawing::Point(15, 243);
			this->statsButton->Name = L"statsButton";
			this->statsButton->Size = System::Drawing::Size(75, 23);
			this->statsButton->TabIndex = 2;
			this->statsButton->Text = L"Show Stats";
			this->statsButton->UseVisualStyleBackColor = true;
			this->statsButton->Click += gcnew System::EventHandler(this, &Form3::statsButton_Click);
			// 
			// Stats
			// 
			this->Stats->Location = System::Drawing::Point(100, 266);
			this->Stats->Name = L"Stats";
			this->Stats->Size = System::Drawing::Size(100, 20);
			this->Stats->TabIndex = 3;
			this->Stats->Text = L"PlayerName";
			// 
			// showStats
			// 
			this->showStats->AutoSize = true;
			this->showStats->Location = System::Drawing::Point(12, 269);
			this->showStats->Name = L"showStats";
			this->showStats->Size = System::Drawing::Size(82, 13);
			this->showStats->TabIndex = 4;
			this->showStats->Text = L"Show Stats For:";
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(407, 291);
			this->Controls->Add(this->showStats);
			this->Controls->Add(this->Stats);
			this->Controls->Add(this->statsButton);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"Form3";
			this->Text = L"Stats";
			this->Load += gcnew System::EventHandler(this, &Form3::Form3_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form3_Load(System::Object^  sender, System::EventArgs^  e) {
			}
			 
	private: System::Void statsButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 richTextBox1->Text = "";
					string statistics = (marshal_as<std::string>(Stats -> Text));	
					bool contains_non_alpha = statistics.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != std::string::npos;
				 if (contains_non_alpha || statistics == ""){
					 MessageBox::Show("Please enter a name, only letters are allowed",
						 "Error", MessageBoxButtons::OK,
						 MessageBoxIcon::Asterisk);
					 return;
				 }
					vector <string> line;
					line = reader(statistics + "scores.txt");
					for(int i = 0; i < line.size(); i++){
						richTextBox1->Text = richTextBox1 -> Text + gcnew String(line[i].c_str()) + "\r\n";
					}
			 }
};
}
