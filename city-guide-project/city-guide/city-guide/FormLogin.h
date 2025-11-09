#pragma once
#include <fstream>
#include "CityGuide.h"
#include "models/User.h"
#include "managers/UserManager.h"

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormLogin
	/// </summary>
	public ref class FormLogin : public System::Windows::Forms::Form
	{
	public:
		FormLogin(void)
		{
			InitializeComponent();
			UserManager::Current->LoadUsers();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonLogIn;
	private: System::Windows::Forms::Panel^ panelUsername;
	private: System::Windows::Forms::Label^ labelUsername;
	private: System::Windows::Forms::Panel^ panelPassword;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::TextBox^ textBoxUsername;
	private: System::Windows::Forms::TextBox^ textBoxPassword;

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
			this->buttonLogIn = (gcnew System::Windows::Forms::Button());
			this->panelUsername = (gcnew System::Windows::Forms::Panel());
			this->textBoxUsername = (gcnew System::Windows::Forms::TextBox());
			this->labelUsername = (gcnew System::Windows::Forms::Label());
			this->panelPassword = (gcnew System::Windows::Forms::Panel());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->panelUsername->SuspendLayout();
			this->panelPassword->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonLogIn
			// 
			this->buttonLogIn->Location = System::Drawing::Point(97, 132);
			this->buttonLogIn->Name = L"buttonLogIn";
			this->buttonLogIn->Size = System::Drawing::Size(75, 23);
			this->buttonLogIn->TabIndex = 0;
			this->buttonLogIn->Text = L"Log in";
			this->buttonLogIn->UseVisualStyleBackColor = true;
			this->buttonLogIn->Click += gcnew System::EventHandler(this, &FormLogin::buttonLogIn_Click);
			// 
			// panelUsername
			// 
			this->panelUsername->Controls->Add(this->textBoxUsername);
			this->panelUsername->Controls->Add(this->labelUsername);
			this->panelUsername->Location = System::Drawing::Point(37, 28);
			this->panelUsername->Name = L"panelUsername";
			this->panelUsername->Size = System::Drawing::Size(200, 46);
			this->panelUsername->TabIndex = 1;
			// 
			// textBoxUsername
			// 
			this->textBoxUsername->Location = System::Drawing::Point(7, 20);
			this->textBoxUsername->Name = L"textBoxUsername";
			this->textBoxUsername->Size = System::Drawing::Size(190, 20);
			this->textBoxUsername->TabIndex = 1;
			this->textBoxUsername->Text = L"default-username";
			// 
			// labelUsername
			// 
			this->labelUsername->AutoSize = true;
			this->labelUsername->Location = System::Drawing::Point(4, 4);
			this->labelUsername->Name = L"labelUsername";
			this->labelUsername->Size = System::Drawing::Size(61, 13);
			this->labelUsername->TabIndex = 0;
			this->labelUsername->Text = L"Username: ";
			// 
			// panelPassword
			// 
			this->panelPassword->Controls->Add(this->textBoxPassword);
			this->panelPassword->Controls->Add(this->labelPassword);
			this->panelPassword->Location = System::Drawing::Point(37, 80);
			this->panelPassword->Name = L"panelPassword";
			this->panelPassword->Size = System::Drawing::Size(200, 46);
			this->panelPassword->TabIndex = 2;
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Location = System::Drawing::Point(7, 20);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->PasswordChar = '?';
			this->textBoxPassword->Size = System::Drawing::Size(190, 20);
			this->textBoxPassword->TabIndex = 1;
			this->textBoxPassword->Text = L"password";
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Location = System::Drawing::Point(4, 4);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(59, 13);
			this->labelPassword->TabIndex = 0;
			this->labelPassword->Text = L"Password: ";
			// 
			// FormLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 181);
			this->Controls->Add(this->panelPassword);
			this->Controls->Add(this->panelUsername);
			this->Controls->Add(this->buttonLogIn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FormLogin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormLogin";
			this->panelUsername->ResumeLayout(false);
			this->panelUsername->PerformLayout();
			this->panelPassword->ResumeLayout(false);
			this->panelPassword->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		System::Void buttonLogIn_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ username = textBoxUsername->Text;
			String^ password = textBoxPassword->Text;
			bool foundUser = UserManager::Current->TryLogin(username, password);
			if (!foundUser) {
				MessageBox::Show("Failed to login", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			} else {
				CityGuideForm^ newForm = gcnew CityGuideForm();
				newForm->Show();
				this->Hide();
			}
		}
};
}
