#pragma once
#include "../../models/Institutions/Institution.h"
#include "../../managers/InstitutionManager.h"

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormInstitutionAddOrEdit
	/// </summary>
	public ref class FormInstitutionAddOrEdit : public System::Windows::Forms::Form
	{
	public:
		FormInstitutionAddOrEdit(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		FormInstitutionAddOrEdit(Institution^ selectedInstitution) {
			// edit user
			InitializeComponent();

			if (selectedInstitution == nullptr) {
				// if wrong to edit
				this->Close();
			} else {
				Text = "Edit institution: " + selectedInstitution->Name;
				buttonSave->Click += gcnew System::EventHandler(this, &FormInstitutionAddOrEdit::buttonSaveEdit_Click);
				buttonSave->Text = "Edit";

				textBoxName->Text = selectedInstitution->Name;
				textBoxAddress->Text = selectedInstitution->Address;

				_selectedInstitution = selectedInstitution;
				_institutionType = _selectedInstitution->InstitutionType;
				RefreshForm();
				comboBoxDistrict->Text = _selectedInstitution->District;
			}
		}

		FormInstitutionAddOrEdit(InstitutionTypeEnum institutionType) {
			// add user
			InitializeComponent();

			Text = "Add institution: " + institutionType.ToString();
			buttonSave->Click += gcnew System::EventHandler(this, &FormInstitutionAddOrEdit::buttonSaveAdd_Click);
			buttonSave->Text = "Add";

			_institutionType = institutionType;
			RefreshForm();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormInstitutionAddOrEdit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonSave;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::TextBox^ textBoxName;
	protected:

	private:
		Institution^ _selectedInstitution = nullptr;
	private:
		InstitutionTypeEnum _institutionType = InstitutionTypeEnum::Unknown;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBoxDistrict;
	private: System::Windows::Forms::CheckedListBox^ checkedListBoxTransport;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxAddress;

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
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBoxDistrict = (gcnew System::Windows::Forms::ComboBox());
			this->checkedListBoxTransport = (gcnew System::Windows::Forms::CheckedListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxAddress = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(12, 310);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(75, 23);
			this->buttonSave->TabIndex = 1;
			this->buttonSave->Text = L"Save";
			this->buttonSave->UseVisualStyleBackColor = true;
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(737, 310);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 7;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &FormInstitutionAddOrEdit::buttonCancel_Click);
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Location = System::Drawing::Point(13, 15);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(35, 13);
			this->labelName->TabIndex = 11;
			this->labelName->Text = L"Name";
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(92, 12);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(180, 20);
			this->textBoxName->TabIndex = 10;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"District";
			// 
			// comboBoxDistrict
			// 
			this->comboBoxDistrict->FormattingEnabled = true;
			this->comboBoxDistrict->Location = System::Drawing::Point(92, 38);
			this->comboBoxDistrict->Name = L"comboBoxDistrict";
			this->comboBoxDistrict->Size = System::Drawing::Size(180, 21);
			this->comboBoxDistrict->TabIndex = 13;
			// 
			// checkedListBoxTransport
			// 
			this->checkedListBoxTransport->FormattingEnabled = true;
			this->checkedListBoxTransport->Location = System::Drawing::Point(16, 116);
			this->checkedListBoxTransport->Name = L"checkedListBoxTransport";
			this->checkedListBoxTransport->Size = System::Drawing::Size(256, 184);
			this->checkedListBoxTransport->TabIndex = 14;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Transport";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 13);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Address";
			// 
			// textBoxAddress
			// 
			this->textBoxAddress->Location = System::Drawing::Point(92, 66);
			this->textBoxAddress->Name = L"textBoxAddress";
			this->textBoxAddress->Size = System::Drawing::Size(180, 20);
			this->textBoxAddress->TabIndex = 17;
			// 
			// FormInstitutionAddOrEdit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(824, 345);
			this->Controls->Add(this->textBoxAddress);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->checkedListBoxTransport);
			this->Controls->Add(this->comboBoxDistrict);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonSave);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FormInstitutionAddOrEdit";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormInstitutionAddOrEdit";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		void RefreshForm() {
			comboBoxDistrict->Items->AddRange(DistrictManager::Instance->GetDistrictList()->ToArray());
			if (_selectedInstitution == nullptr || _selectedInstitution->TransportList == nullptr) {
				checkedListBoxTransport->Items->AddRange(TransportManager::Instance->GetTransportList()->ToArray());
			} else {
				for each (Transport^ transport in TransportManager::Instance->GetTransportList()) {
					bool tmp = false;
					for each (Transport^ old in _selectedInstitution->TransportList) {
						if (transport->Equals(old)) {
							tmp = true;
							break;
						}
					}
					checkedListBoxTransport->Items->Add(transport, tmp);
				}
			}
		}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void buttonSaveAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		Institution^ baseInstitution;
		switch (_institutionType) {
		case InstitutionTypeEnum::Airport: {
			Airport^ airport = gcnew Airport();
			baseInstitution = airport;
			break;
		}
		case InstitutionTypeEnum::Hospital: {
			Hospital^ hospital = gcnew Hospital();
			baseInstitution = hospital;
			break;
		}
		case InstitutionTypeEnum::Library: {
			Library^ library = gcnew Library();
			baseInstitution = library;
			break;
		}
		case InstitutionTypeEnum::Lighthouse: {
			Lighthouse^ lighthouse = gcnew Lighthouse();
			baseInstitution = lighthouse;
			break;
		}
		case InstitutionTypeEnum::Mall: {
			Mall^ mall = gcnew Mall();
			baseInstitution = mall;
			break;
		}
		case InstitutionTypeEnum::Museum: {
			Museum^ museum = gcnew Museum();
			baseInstitution = museum;
			break;
		}
		case InstitutionTypeEnum::Restaurant: {
			Restaurant^ restaurant = gcnew Restaurant();
			baseInstitution = restaurant;
			break;
		}
		case InstitutionTypeEnum::School: {
			School^ school = gcnew School();
			baseInstitution = school;
			break;
		}
		case InstitutionTypeEnum::Theatre: {
			Theatre^ theatre = gcnew Theatre();
			baseInstitution = theatre;
			break;
		}
		case InstitutionTypeEnum::Wharf: {
			Wharf^ wharf = gcnew Wharf();
			baseInstitution = wharf;
			break;
		}
		default: {
			MessageBox::Show("Couldn't add institution", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Close();
			return;
		}
		}

		baseInstitution->Name = textBoxName->Text;
		baseInstitution->Address = textBoxAddress->Text;
		baseInstitution->InstitutionType = _institutionType;
		baseInstitution->District = comboBoxDistrict->Text;
		for each (Object^ transport in checkedListBoxTransport->CheckedItems) {
			baseInstitution->TransportList->Add(dynamic_cast<Transport^>(transport));
		}

		if (InstitutionManager::Instance->TryAddInstitution(
			baseInstitution,
			_institutionType
		)) {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		} else {
			MessageBox::Show("Couldn't add institution", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->Close();
	}

	private: System::Void buttonSaveEdit_Click(System::Object^ sender, System::EventArgs^ e) {
		switch (_institutionType) {
		case InstitutionTypeEnum::Airport: {
			Airport^ airport = dynamic_cast<Airport^>(_selectedInstitution);

			break;
		}
		case InstitutionTypeEnum::Hospital: {
			Hospital^ hospital = dynamic_cast<Hospital^>(_selectedInstitution);
			break;
		}
		case InstitutionTypeEnum::Library: {
			Library^ library = dynamic_cast<Library^>(_selectedInstitution);
			break;
		}
		case InstitutionTypeEnum::Lighthouse: {
			Lighthouse^ lighthouse = dynamic_cast<Lighthouse^>(_selectedInstitution);
			break;
		}
		case InstitutionTypeEnum::Mall: {
			Mall^ mall = dynamic_cast<Mall^>(_selectedInstitution);
			break;
		}
		case InstitutionTypeEnum::Museum: {
			Museum^ museum = dynamic_cast<Museum^>(_selectedInstitution);
			break;
		}
		case InstitutionTypeEnum::Restaurant: {
			Restaurant^ restaurant = dynamic_cast<Restaurant^>(_selectedInstitution);
			break;
		}
		case InstitutionTypeEnum::School: {
			School^ school = dynamic_cast<School^>(_selectedInstitution);
			break;
		}
		case InstitutionTypeEnum::Theatre: {
			Theatre^ theatre = dynamic_cast<Theatre^>(_selectedInstitution);
			break;
		}
		case InstitutionTypeEnum::Wharf: {
			Wharf^ wharf = dynamic_cast<Wharf^>(_selectedInstitution);
			break;
		}
		default: {
			MessageBox::Show("Couldn't add institution", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Close();
			return;
		}
		}

		_selectedInstitution->Name = textBoxName->Text;
		_selectedInstitution->Address = textBoxAddress->Text;
		_selectedInstitution->InstitutionType = _institutionType;
		_selectedInstitution->District = comboBoxDistrict->Text;
		for each (Object ^ transport in checkedListBoxTransport->CheckedItems) {
			_selectedInstitution->TransportList->Add(dynamic_cast<Transport^>(transport));
		}

		if (InstitutionManager::Instance->TryEditInstitution(
			_selectedInstitution
		)) {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		} else {
			MessageBox::Show("Couldn't edit institution", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->Close();
	}
};
}
