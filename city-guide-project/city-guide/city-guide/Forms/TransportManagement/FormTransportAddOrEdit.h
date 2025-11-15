#pragma once
#include "../../managers/TransportManager.h"

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormTransportAddOrEdit
	/// </summary>
	public ref class FormTransportAddOrEdit : public System::Windows::Forms::Form
	{
	public:
		FormTransportAddOrEdit(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		FormTransportAddOrEdit(Transport^ selectedTransport) {
			InitializeComponent();

			for each (Object^ transportType in Enum::GetValues(Transport::TransportTypeEnum::typeid)) {
				comboBoxType->Items->Add(transportType);
			}

			if (selectedTransport == nullptr) {
				// add user
				Text = "Add transport";
				buttonSave->Click += gcnew System::EventHandler(this, &FormTransportAddOrEdit::buttonSaveAdd_Click);
				buttonSave->Text = "Add";
			} else {
				// edit user
				Text = "Edit transport";
				buttonSave->Click += gcnew System::EventHandler(this, &FormTransportAddOrEdit::buttonSaveEdit_Click);
				buttonSave->Text = "Edit";

				textBoxName->Text = selectedTransport->Name;
				comboBoxType->Text = selectedTransport->TransportType.ToString();

				_selectedTransport = selectedTransport;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormTransportAddOrEdit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonSave;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::ComboBox^ comboBoxType;
	private: System::Windows::Forms::TextBox^ textBoxName;


	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::Label^ labelType;
	protected:

	protected:

	private:
		Transport^ _selectedTransport = nullptr;

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
			this->comboBoxType = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->labelType = (gcnew System::Windows::Forms::Label());
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
			this->buttonCancel->Click += gcnew System::EventHandler(this, &FormTransportAddOrEdit::buttonCancel_Click);
			// 
			// comboBoxType
			// 
			this->comboBoxType->FormattingEnabled = true;
			this->comboBoxType->Location = System::Drawing::Point(100, 36);
			this->comboBoxType->Name = L"comboBoxType";
			this->comboBoxType->Size = System::Drawing::Size(172, 21);
			this->comboBoxType->TabIndex = 7;
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(100, 10);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(172, 20);
			this->textBoxName->TabIndex = 8;
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Location = System::Drawing::Point(13, 13);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(81, 13);
			this->labelName->TabIndex = 9;
			this->labelName->Text = L"Transport name";
			// 
			// labelType
			// 
			this->labelType->AutoSize = true;
			this->labelType->Location = System::Drawing::Point(13, 39);
			this->labelType->Name = L"labelType";
			this->labelType->Size = System::Drawing::Size(75, 13);
			this->labelType->TabIndex = 10;
			this->labelType->Text = L"Transport type";
			// 
			// FormTransportAddOrEdit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 184);
			this->Controls->Add(this->labelType);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->comboBoxType);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonSave);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FormTransportAddOrEdit";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormTransportAddOrEdit";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void buttonSaveAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		if (TransportManager::Instance->TryAddTransport(
			textBoxName->Text,
			Transport::GetTranportTypeEnum(comboBoxType->Text)
		)) {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		} else {
			MessageBox::Show("Couldn't add transport", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->Close();
	}

	private: System::Void buttonSaveEdit_Click(System::Object^ sender, System::EventArgs^ e) {
		if (TransportManager::Instance->TryEditTransport(
			_selectedTransport,
			textBoxName->Text,
			Transport::GetTranportTypeEnum(comboBoxType->Text)
		)) {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		} else {
			MessageBox::Show("Couldn't edit transport", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->Close();
	}
	};
}
