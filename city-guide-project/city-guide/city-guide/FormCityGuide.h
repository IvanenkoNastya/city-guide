#pragma once
#include "managers/UserManager.h"
#include "FormUserManager.h"
#include "FormLogin.h"
#include "FormHelp.h"

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CityGuide
	/// </summary>
	public ref class FormCityGuide : public System::Windows::Forms::Form
	{
	public:
		FormCityGuide(void)
		{
			InitializeComponent();
			if (UserManager::Instance->CurrentUser->IsAdmin) {
				panelAdmin->Visible = true;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormCityGuide()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panelMenuAll;
	private: System::Windows::Forms::Panel^ panelAdmin;


	private: System::Windows::Forms::Label^ labelMenu;
	private: System::Windows::Forms::Button^ buttonManageUsers;
	private: System::Windows::Forms::Panel^ panelGeneral;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;

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
			this->panelMenuAll = (gcnew System::Windows::Forms::Panel());
			this->panelGeneral = (gcnew System::Windows::Forms::Panel());
			this->panelAdmin = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->buttonManageUsers = (gcnew System::Windows::Forms::Button());
			this->labelMenu = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panelMenuAll->SuspendLayout();
			this->panelAdmin->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelMenuAll
			// 
			this->panelMenuAll->Controls->Add(this->panelGeneral);
			this->panelMenuAll->Controls->Add(this->panelAdmin);
			this->panelMenuAll->Controls->Add(this->labelMenu);
			this->panelMenuAll->Location = System::Drawing::Point(13, 50);
			this->panelMenuAll->Name = L"panelMenuAll";
			this->panelMenuAll->Size = System::Drawing::Size(471, 237);
			this->panelMenuAll->TabIndex = 1;
			// 
			// panelGeneral
			// 
			this->panelGeneral->Location = System::Drawing::Point(4, 43);
			this->panelGeneral->Name = L"panelGeneral";
			this->panelGeneral->Size = System::Drawing::Size(229, 190);
			this->panelGeneral->TabIndex = 4;
			// 
			// panelAdmin
			// 
			this->panelAdmin->Controls->Add(this->button2);
			this->panelAdmin->Controls->Add(this->button1);
			this->panelAdmin->Controls->Add(this->buttonManageUsers);
			this->panelAdmin->Location = System::Drawing::Point(239, 43);
			this->panelAdmin->Name = L"panelAdmin";
			this->panelAdmin->Size = System::Drawing::Size(229, 190);
			this->panelAdmin->TabIndex = 3;
			this->panelAdmin->Visible = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(15, 109);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(179, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Manage transport";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 80);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(179, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Manage institutions";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// buttonManageUsers
			// 
			this->buttonManageUsers->Location = System::Drawing::Point(15, 50);
			this->buttonManageUsers->Name = L"buttonManageUsers";
			this->buttonManageUsers->Size = System::Drawing::Size(179, 23);
			this->buttonManageUsers->TabIndex = 0;
			this->buttonManageUsers->Text = L"Manage users";
			this->buttonManageUsers->UseVisualStyleBackColor = true;
			this->buttonManageUsers->Click += gcnew System::EventHandler(this, &FormCityGuide::buttonManageUsers_Click);
			// 
			// labelMenu
			// 
			this->labelMenu->AutoSize = true;
			this->labelMenu->Location = System::Drawing::Point(218, 13);
			this->labelMenu->Name = L"labelMenu";
			this->labelMenu->Size = System::Drawing::Size(34, 13);
			this->labelMenu->TabIndex = 1;
			this->labelMenu->Text = L"Menu";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->helpToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(496, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormCityGuide::helpToolStripMenuItem_Click);
			// 
			// FormCityGuide
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 345);
			this->Controls->Add(this->panelMenuAll);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"FormCityGuide";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CityGuide";
			this->panelMenuAll->ResumeLayout(false);
			this->panelMenuAll->PerformLayout();
			this->panelAdmin->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonShowCurrentUser_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void buttonManageUsers_Click(System::Object^ sender, System::EventArgs^ e) {
		FormUserManager^ form = gcnew FormUserManager();
		form->ShowDialog();
	}
	private: System::Void FormCityGuide_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	}
	private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		FormHelp^ form = gcnew FormHelp();
		form->ShowDialog();
	}

};
}
