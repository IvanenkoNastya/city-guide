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
	/// Summary for CityGuide
	/// </summary>
	public ref class CityGuideForm : public System::Windows::Forms::Form
	{
	public:
		CityGuideForm(void)
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
		~CityGuideForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonShowCurrentUser;
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
			this->buttonShowCurrentUser = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonShowCurrentUser
			// 
			this->buttonShowCurrentUser->Location = System::Drawing::Point(22, 22);
			this->buttonShowCurrentUser->Name = L"buttonShowCurrentUser";
			this->buttonShowCurrentUser->Size = System::Drawing::Size(75, 23);
			this->buttonShowCurrentUser->TabIndex = 0;
			this->buttonShowCurrentUser->Text = L"ShowMyself";
			this->buttonShowCurrentUser->UseVisualStyleBackColor = true;
			this->buttonShowCurrentUser->Click += gcnew System::EventHandler(this, &CityGuideForm::buttonShowCurrentUser_Click);
			// 
			// CityGuideForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->buttonShowCurrentUser);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"CityGuideForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CityGuide";
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		System::Void buttonShowCurrentUser_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ infoText =
				"My name is "
				+ UserManager::Current->CurrentUser->Username
				+ "\nMy password is "
				+ UserManager::Current->CurrentUser->Password
				+ "\nI am ";
			if (UserManager::Current->CurrentUser->IsAdmin) {
				infoText += "Admin";
			} else {
				infoText += "User";
			}
			MessageBox::Show(infoText , "User Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	};
}
