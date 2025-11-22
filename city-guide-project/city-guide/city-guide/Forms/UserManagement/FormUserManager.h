#pragma once
#include "../../managers/UserManager.h"
#include "FormUserAddOrEdit.h"

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormUserManager
	/// Form allows admin to add, edit and remove users (except for itself)
	/// </summary>
	public ref class FormUserManager : public System::Windows::Forms::Form
	{
	public:
		FormUserManager(void)
		{
			InitializeComponent();

			RefreshUserListBox();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormUserManager()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBoxUsers;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ addUserToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editUserToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteUserToolStripMenuItem;
	private: System::Windows::Forms::Button^ buttonCancel;

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
			this->listBoxUsers = (gcnew System::Windows::Forms::ListBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->addUserToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editUserToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteUserToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// listBoxUsers
			// 
			this->listBoxUsers->FormattingEnabled = true;
			this->listBoxUsers->Location = System::Drawing::Point(12, 51);
			this->listBoxUsers->Name = L"listBoxUsers";
			this->listBoxUsers->Size = System::Drawing::Size(472, 251);
			this->listBoxUsers->TabIndex = 0;
			this->listBoxUsers->SelectedIndexChanged += gcnew System::EventHandler(this, &FormUserManager::listBoxUsers_SelectedIndexChanged);
			this->listBoxUsers->DoubleClick += gcnew System::EventHandler(this, &FormUserManager::editUserToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addUserToolStripMenuItem,
					this->editUserToolStripMenuItem, this->deleteUserToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(496, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// addUserToolStripMenuItem
			// 
			this->addUserToolStripMenuItem->Name = L"addUserToolStripMenuItem";
			this->addUserToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->addUserToolStripMenuItem->Text = L"Add user";
			this->addUserToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormUserManager::addUserToolStripMenuItem_Click);
			// 
			// editUserToolStripMenuItem
			// 
			this->editUserToolStripMenuItem->Enabled = false;
			this->editUserToolStripMenuItem->Name = L"editUserToolStripMenuItem";
			this->editUserToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->editUserToolStripMenuItem->Text = L"Edit user";
			this->editUserToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormUserManager::editUserToolStripMenuItem_Click);
			// 
			// deleteUserToolStripMenuItem
			// 
			this->deleteUserToolStripMenuItem->Enabled = false;
			this->deleteUserToolStripMenuItem->Name = L"deleteUserToolStripMenuItem";
			this->deleteUserToolStripMenuItem->Size = System::Drawing::Size(77, 20);
			this->deleteUserToolStripMenuItem->Text = L"Delete user";
			this->deleteUserToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormUserManager::deleteUserToolStripMenuItem_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(409, 310);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 2;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &FormUserManager::buttonCancel_Click);
			// 
			// FormUserManager
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 345);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->listBoxUsers);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"FormUserManager";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormUserManager";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void RefreshUserListBox() {
		listBoxUsers->Items->Clear();
		List<String^>^ userInfos = UserManager::Instance->GetUsers();
		for each (String ^ userInfo in userInfos) {
			listBoxUsers->Items->Add(userInfo);
		}
		editUserToolStripMenuItem->Enabled = false;
		deleteUserToolStripMenuItem->Enabled = false;
	}

	private: System::Void addUserToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		FormUserAddOrEdit^ form = gcnew FormUserAddOrEdit(nullptr);
		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			RefreshUserListBox();
		}
	}

	private: System::Void editUserToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ selectedUser = listBoxUsers->GetItemText(listBoxUsers->SelectedItem);
		FormUserAddOrEdit^ form = gcnew FormUserAddOrEdit(selectedUser);
		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			RefreshUserListBox();
		}
	}

	private: System::Void deleteUserToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult answer = MessageBox::Show("Are you sure?", "Delete user", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (answer == System::Windows::Forms::DialogResult::Yes) {
			String^ selectedUser = listBoxUsers->GetItemText(listBoxUsers->SelectedItem);
			if (!UserManager::Instance->TryDeleteUser(selectedUser)) {
				MessageBox::Show("Couldn't delete user", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			RefreshUserListBox();
		}
	}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void listBoxUsers_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		editUserToolStripMenuItem->Enabled = true;
		deleteUserToolStripMenuItem->Enabled = true;
	}
};
}
