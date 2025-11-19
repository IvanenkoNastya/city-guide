#pragma once
#include "../../managers/InstitutionManager.h"

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormFindTransportByPlaces
	/// </summary>
	public ref class FormFindTransportByPlaces : public System::Windows::Forms::Form
	{
	public:
		FormFindTransportByPlaces(void)
		{
			InitializeComponent();

			comboBoxInstitutionFrom->Items->AddRange(InstitutionManager::Instance->GetInstitutionList()->ToArray());
			comboBoxInstitutionTo->Items->AddRange(InstitutionManager::Instance->GetInstitutionList()->ToArray());
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormFindTransportByPlaces()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBoxInstitutionFrom;
	protected:

	private: System::Windows::Forms::Label^ labelInfo;
	private: System::Windows::Forms::Label^ labelFrom;
	private: System::Windows::Forms::Label^ labelTo;
	private: System::Windows::Forms::ComboBox^ comboBoxInstitutionTo;

	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::ListBox^ listBoxTransports;

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
			this->comboBoxInstitutionFrom = (gcnew System::Windows::Forms::ComboBox());
			this->labelInfo = (gcnew System::Windows::Forms::Label());
			this->labelFrom = (gcnew System::Windows::Forms::Label());
			this->labelTo = (gcnew System::Windows::Forms::Label());
			this->comboBoxInstitutionTo = (gcnew System::Windows::Forms::ComboBox());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->listBoxTransports = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// comboBoxInstitutionFrom
			// 
			this->comboBoxInstitutionFrom->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxInstitutionFrom->FormattingEnabled = true;
			this->comboBoxInstitutionFrom->Location = System::Drawing::Point(48, 46);
			this->comboBoxInstitutionFrom->Name = L"comboBoxInstitutionFrom";
			this->comboBoxInstitutionFrom->Size = System::Drawing::Size(191, 21);
			this->comboBoxInstitutionFrom->TabIndex = 0;
			this->comboBoxInstitutionFrom->SelectedIndexChanged += gcnew System::EventHandler(this, &FormFindTransportByPlaces::comboBoxInstitution_SelectedIndexChanged);
			// 
			// labelInfo
			// 
			this->labelInfo->AutoSize = true;
			this->labelInfo->Location = System::Drawing::Point(12, 13);
			this->labelInfo->Name = L"labelInfo";
			this->labelInfo->Size = System::Drawing::Size(416, 13);
			this->labelInfo->TabIndex = 1;
			this->labelInfo->Text = L"Enter your starting point and destination to find transport(s) that connect that "
				L"institutions";
			// 
			// labelFrom
			// 
			this->labelFrom->AutoSize = true;
			this->labelFrom->Location = System::Drawing::Point(12, 49);
			this->labelFrom->Name = L"labelFrom";
			this->labelFrom->Size = System::Drawing::Size(30, 13);
			this->labelFrom->TabIndex = 2;
			this->labelFrom->Text = L"From";
			// 
			// labelTo
			// 
			this->labelTo->AutoSize = true;
			this->labelTo->Location = System::Drawing::Point(264, 49);
			this->labelTo->Name = L"labelTo";
			this->labelTo->Size = System::Drawing::Size(20, 13);
			this->labelTo->TabIndex = 3;
			this->labelTo->Text = L"To";
			// 
			// comboBoxInstitutionTo
			// 
			this->comboBoxInstitutionTo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxInstitutionTo->FormattingEnabled = true;
			this->comboBoxInstitutionTo->Location = System::Drawing::Point(290, 46);
			this->comboBoxInstitutionTo->Name = L"comboBoxInstitutionTo";
			this->comboBoxInstitutionTo->Size = System::Drawing::Size(191, 21);
			this->comboBoxInstitutionTo->TabIndex = 4;
			this->comboBoxInstitutionTo->SelectedIndexChanged += gcnew System::EventHandler(this, &FormFindTransportByPlaces::comboBoxInstitution_SelectedIndexChanged);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(409, 310);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &FormFindTransportByPlaces::buttonCancel_Click);
			// 
			// listBoxTransports
			// 
			this->listBoxTransports->Enabled = false;
			this->listBoxTransports->FormattingEnabled = true;
			this->listBoxTransports->Location = System::Drawing::Point(12, 92);
			this->listBoxTransports->Name = L"listBoxTransports";
			this->listBoxTransports->Size = System::Drawing::Size(469, 212);
			this->listBoxTransports->TabIndex = 6;
			// 
			// FormFindTransportByPlaces
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 345);
			this->Controls->Add(this->listBoxTransports);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->comboBoxInstitutionTo);
			this->Controls->Add(this->labelTo);
			this->Controls->Add(this->labelFrom);
			this->Controls->Add(this->labelInfo);
			this->Controls->Add(this->comboBoxInstitutionFrom);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FormFindTransportByPlaces";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Find Transport by Places";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		void RefreshListOfTransports(Institution^ institutionFrom, Institution^ institutionTo) {
			listBoxTransports->Items->Clear();
			if (institutionFrom == nullptr || institutionTo == nullptr) {
				return;
			}
			if (institutionFrom == institutionTo) {
				listBoxTransports->Items->Add("Starting point and Destination are the same.");
				listBoxTransports->Items->Add("To get a circular ride and come back you can use these transport options:");
				listBoxTransports->Items->Add("");
			}

			listBoxTransports->Items->AddRange(
				InstitutionManager::Instance->GetTransportList(institutionFrom, institutionTo)->ToArray()
			);
		}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void comboBoxInstitution_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Institution^ selectedInstitutionFrom = dynamic_cast<Institution^>(comboBoxInstitutionFrom->SelectedItem);
		Institution^ selectedInstitutionTo = dynamic_cast<Institution^>(comboBoxInstitutionTo->SelectedItem);

		RefreshListOfTransports(selectedInstitutionFrom, selectedInstitutionTo);
	}
};
}
