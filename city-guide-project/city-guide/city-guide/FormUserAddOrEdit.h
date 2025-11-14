#pragma once
#include "managers/UserManager.h"

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormUserAddOrEdit
	/// </summary>
	public ref class FormUserAddOrEdit : public System::Windows::Forms::Form
	{
	public:
		FormUserAddOrEdit(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		FormUserAddOrEdit(String^ userToEditStr) {
			InitializeComponent();
			if (userToEditStr == nullptr) {
				// add user
				Text = "Add user";
				buttonSave->Click += gcnew System::EventHandler(this, &FormUserAddOrEdit::buttonSaveAdd_Click);
				buttonSave->Text = "Add";

			} else {
				// edit user
				Text = "Edit user";
				buttonSave->Click += gcnew System::EventHandler(this, &FormUserAddOrEdit::buttonSaveEdit_Click);
				buttonSave->Text = "Edit";
				User^ userToEdit = UserManager::Instance->FindUserByInfo(userToEditStr);
				Text += " " + userToEdit->Username;

				checkBoxIsAdmin->Checked = userToEdit->IsAdmin;
				textBoxUsername->Text = userToEdit->Username;
				textBoxPassword->Text = userToEdit->Password;

				usernameToEdit = userToEditStr;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormUserAddOrEdit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ checkBoxIsAdmin;
	protected:
	private: System::Windows::Forms::TextBox^ textBoxUsername;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxPassword;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::Button^ buttonSave;


	private: String^ usernameToEdit = nullptr;

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
			this->checkBoxIsAdmin = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxUsername = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// checkBoxIsAdmin
			// 
			this->checkBoxIsAdmin->AutoSize = true;
			this->checkBoxIsAdmin->Location = System::Drawing::Point(12, 12);
			this->checkBoxIsAdmin->Name = L"checkBoxIsAdmin";
			this->checkBoxIsAdmin->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBoxIsAdmin->Size = System::Drawing::Size(55, 17);
			this->checkBoxIsAdmin->TabIndex = 0;
			this->checkBoxIsAdmin->Text = L"Admin";
			this->checkBoxIsAdmin->UseVisualStyleBackColor = true;
			// 
			// textBoxUsername
			// 
			this->textBoxUsername->Location = System::Drawing::Point(16, 57);
			this->textBoxUsername->Name = L"textBoxUsername";
			this->textBoxUsername->Size = System::Drawing::Size(256, 20);
			this->textBoxUsername->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Username";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password";
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Location = System::Drawing::Point(16, 112);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(256, 20);
			this->textBoxPassword->TabIndex = 4;
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(197, 147);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &FormUserAddOrEdit::buttonCancel_Click);
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(16, 147);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(75, 23);
			this->buttonSave->TabIndex = 6;
			this->buttonSave->Text = L"Save";
			this->buttonSave->UseVisualStyleBackColor = true;
			// 
			// FormUserAddOrEdit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 184);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxUsername);
			this->Controls->Add(this->checkBoxIsAdmin);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FormUserAddOrEdit";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormUserAddOrEdit";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void buttonSaveAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		if (UserManager::Instance->TryAddUser(
			checkBoxIsAdmin->Checked,
			textBoxUsername->Text,
			textBoxPassword->Text
		)) {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		} else {
			MessageBox::Show("Couldn't add user", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->Close();
	}

	private: System::Void buttonSaveEdit_Click(System::Object^ sender, System::EventArgs^ e) {
		if (UserManager::Instance->TryEditUser(
			usernameToEdit,
			checkBoxIsAdmin->Checked,
			textBoxUsername->Text,
			textBoxPassword->Text
		)) {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		} else {
			MessageBox::Show("Couldn't edit user", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->Close();
	}
};
}
