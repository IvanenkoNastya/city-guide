#pragma once
#include "../../managers/DistrictManager.h"

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormDistrictAddOrEdit
	/// </summary>
	public ref class FormDistrictAddOrEdit : public System::Windows::Forms::Form
	{
	public:
		FormDistrictAddOrEdit(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		FormDistrictAddOrEdit(String^ selectedDistrict) {
			InitializeComponent();

			if (selectedDistrict == nullptr) {
				// add user
				Text = "Add District";
				buttonSave->Click += gcnew System::EventHandler(this, &FormDistrictAddOrEdit::buttonSaveAdd_Click);
				buttonSave->Text = "Add";
			} else {
				// edit user
				Text = "Edit District";
				buttonSave->Click += gcnew System::EventHandler(this, &FormDistrictAddOrEdit::buttonSaveEdit_Click);
				buttonSave->Text = "Edit";

				textBoxName->Text = selectedDistrict;

				_selectedDistrict = selectedDistrict;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormDistrictAddOrEdit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonSave;
	private: System::Windows::Forms::Button^ buttonCancel;

	private: System::Windows::Forms::TextBox^ textBoxName;


	private: System::Windows::Forms::Label^ labelName;

	protected:

	protected:

	private:
		String^ _selectedDistrict = nullptr;

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
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(12, 149);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(75, 23);
			this->buttonSave->TabIndex = 0;
			this->buttonSave->Text = L"Save";
			this->buttonSave->UseVisualStyleBackColor = true;
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(197, 149);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 6;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &FormDistrictAddOrEdit::buttonCancel_Click);
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(12, 59);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(260, 20);
			this->textBoxName->TabIndex = 8;
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Location = System::Drawing::Point(12, 43);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(68, 13);
			this->labelName->TabIndex = 9;
			this->labelName->Text = L"District name";
			// 
			// FormDistrictAddOrEdit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 184);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonSave);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FormDistrictAddOrEdit";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormDistrictAddOrEdit";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void buttonSaveAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		if (DistrictManager::Instance->TryAddDistrict(
			textBoxName->Text
		)) {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		} else {
			MessageBox::Show("Couldn't add District", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->Close();
	}

	private: System::Void buttonSaveEdit_Click(System::Object^ sender, System::EventArgs^ e) {
		if (DistrictManager::Instance->TryEditDistrict(
			_selectedDistrict,
			textBoxName->Text
		)) {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		} else {
			MessageBox::Show("Couldn't edit District", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->Close();
	}
	};
}
