#pragma once

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormFilterInstitutions
	/// Form to filter institutions by transport, as well as serch them by name or address
	/// </summary>
	public ref class FormFilterInstitutions : public System::Windows::Forms::Form
	{
	public:
		FormFilterInstitutions(void)
		{
			InitializeComponent();

			RefreshInstitutionListBox();

			for each (Object^ transportType in Enum::GetValues(Transport::TransportTypeEnum::typeid)) {
				if ((Transport::TransportTypeEnum)transportType != Transport::TransportTypeEnum::Unknown) {
					comboBoxTransportType->Items->Add(transportType);
				}
			}

			SetTransportsDropdown();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormFilterInstitutions()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::ListBox^ listBoxInstitutions;
	private: System::Windows::Forms::ComboBox^ comboBoxTransport;
	private: System::Windows::Forms::Label^ labelTransport;
	private: System::Windows::Forms::Label^ labelTransportType;
	private: System::Windows::Forms::ComboBox^ comboBoxTransportType;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPageTransport;
	private: System::Windows::Forms::TabPage^ tabPageAddress;
	private: System::Windows::Forms::TextBox^ textBoxSearchInput;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonReset;

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
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->listBoxInstitutions = (gcnew System::Windows::Forms::ListBox());
			this->comboBoxTransport = (gcnew System::Windows::Forms::ComboBox());
			this->labelTransport = (gcnew System::Windows::Forms::Label());
			this->labelTransportType = (gcnew System::Windows::Forms::Label());
			this->comboBoxTransportType = (gcnew System::Windows::Forms::ComboBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPageTransport = (gcnew System::Windows::Forms::TabPage());
			this->tabPageAddress = (gcnew System::Windows::Forms::TabPage());
			this->textBoxSearchInput = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPageTransport->SuspendLayout();
			this->tabPageAddress->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(409, 310);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 0;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &FormFilterInstitutions::buttonCancel_Click);
			// 
			// listBoxInstitutions
			// 
			this->listBoxInstitutions->FormattingEnabled = true;
			this->listBoxInstitutions->Location = System::Drawing::Point(12, 104);
			this->listBoxInstitutions->Name = L"listBoxInstitutions";
			this->listBoxInstitutions->Size = System::Drawing::Size(472, 199);
			this->listBoxInstitutions->TabIndex = 1;
			// 
			// comboBoxTransport
			// 
			this->comboBoxTransport->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxTransport->FormattingEnabled = true;
			this->comboBoxTransport->Location = System::Drawing::Point(132, 27);
			this->comboBoxTransport->Name = L"comboBoxTransport";
			this->comboBoxTransport->Size = System::Drawing::Size(146, 21);
			this->comboBoxTransport->TabIndex = 2;
			this->comboBoxTransport->SelectedIndexChanged += gcnew System::EventHandler(this, &FormFilterInstitutions::comboBoxTransport_SelectedIndexChanged);
			// 
			// labelTransport
			// 
			this->labelTransport->AutoSize = true;
			this->labelTransport->Location = System::Drawing::Point(129, 8);
			this->labelTransport->Name = L"labelTransport";
			this->labelTransport->Size = System::Drawing::Size(52, 13);
			this->labelTransport->TabIndex = 3;
			this->labelTransport->Text = L"Transport";
			// 
			// labelTransportType
			// 
			this->labelTransportType->AutoSize = true;
			this->labelTransportType->Location = System::Drawing::Point(5, 8);
			this->labelTransportType->Name = L"labelTransportType";
			this->labelTransportType->Size = System::Drawing::Size(75, 13);
			this->labelTransportType->TabIndex = 4;
			this->labelTransportType->Text = L"Transport type";
			// 
			// comboBoxTransportType
			// 
			this->comboBoxTransportType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxTransportType->FormattingEnabled = true;
			this->comboBoxTransportType->Location = System::Drawing::Point(5, 27);
			this->comboBoxTransportType->Name = L"comboBoxTransportType";
			this->comboBoxTransportType->Size = System::Drawing::Size(121, 21);
			this->comboBoxTransportType->TabIndex = 5;
			this->comboBoxTransportType->SelectedIndexChanged += gcnew System::EventHandler(this, &FormFilterInstitutions::comboBoxTransportType_SelectedIndexChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPageTransport);
			this->tabControl1->Controls->Add(this->tabPageAddress);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(472, 83);
			this->tabControl1->TabIndex = 6;
			// 
			// tabPageTransport
			// 
			this->tabPageTransport->Controls->Add(this->comboBoxTransport);
			this->tabPageTransport->Controls->Add(this->comboBoxTransportType);
			this->tabPageTransport->Controls->Add(this->labelTransport);
			this->tabPageTransport->Controls->Add(this->labelTransportType);
			this->tabPageTransport->Location = System::Drawing::Point(4, 22);
			this->tabPageTransport->Name = L"tabPageTransport";
			this->tabPageTransport->Padding = System::Windows::Forms::Padding(3);
			this->tabPageTransport->Size = System::Drawing::Size(464, 57);
			this->tabPageTransport->TabIndex = 0;
			this->tabPageTransport->Text = L"Filter by transport available to the institution";
			this->tabPageTransport->UseVisualStyleBackColor = true;
			// 
			// tabPageAddress
			// 
			this->tabPageAddress->Controls->Add(this->textBoxSearchInput);
			this->tabPageAddress->Controls->Add(this->label1);
			this->tabPageAddress->Location = System::Drawing::Point(4, 22);
			this->tabPageAddress->Name = L"tabPageAddress";
			this->tabPageAddress->Padding = System::Windows::Forms::Padding(3);
			this->tabPageAddress->Size = System::Drawing::Size(464, 57);
			this->tabPageAddress->TabIndex = 1;
			this->tabPageAddress->Text = L"Search by name or address";
			this->tabPageAddress->UseVisualStyleBackColor = true;
			// 
			// textBoxSearchInput
			// 
			this->textBoxSearchInput->Location = System::Drawing::Point(8, 27);
			this->textBoxSearchInput->Name = L"textBoxSearchInput";
			this->textBoxSearchInput->Size = System::Drawing::Size(450, 20);
			this->textBoxSearchInput->TabIndex = 1;
			this->textBoxSearchInput->TextChanged += gcnew System::EventHandler(this, &FormFilterInstitutions::textBoxSearchInput_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Start typing...";
			// 
			// buttonReset
			// 
			this->buttonReset->Location = System::Drawing::Point(12, 310);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(75, 23);
			this->buttonReset->TabIndex = 7;
			this->buttonReset->Text = L"Reset";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &FormFilterInstitutions::buttonReset_Click);
			// 
			// FormFilterInstitutions
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 345);
			this->Controls->Add(this->buttonReset);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->listBoxInstitutions);
			this->Controls->Add(this->buttonCancel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FormFilterInstitutions";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Filter Institutions";
			this->tabControl1->ResumeLayout(false);
			this->tabPageTransport->ResumeLayout(false);
			this->tabPageTransport->PerformLayout();
			this->tabPageAddress->ResumeLayout(false);
			this->tabPageAddress->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void RefreshInstitutionListBox() {
		listBoxInstitutions->Items->Clear();
		listBoxInstitutions->Items->AddRange(InstitutionManager::Instance->GetInstitutionList()->ToArray());
		comboBoxTransportType->SelectedItem = nullptr;
		comboBoxTransport->SelectedItem = nullptr;
	}

	private: void UpdateInstitutionListBoxTransports() {
		listBoxInstitutions->Items->Clear();
		if (comboBoxTransportType->SelectedItem == nullptr && comboBoxTransport->SelectedItem == nullptr) {
			RefreshInstitutionListBox();
		} else if (comboBoxTransport->SelectedItem != nullptr) {
			// show institutions with selected transport
			Transport^ selectedTransport = (Transport^)comboBoxTransport->SelectedItem;
			for each (Institution ^ institution in InstitutionManager::Instance->GetInstitutionList()) {
				for each (Transport ^ transport in institution->TransportList) {
					if (transport->Equals(selectedTransport)) {
						listBoxInstitutions->Items->Add(institution);
					}
				}
			}
		} else if (comboBoxTransportType->SelectedItem != nullptr) {
			// show institutions with selected transport type
			Transport::TransportTypeEnum selectedTransportType = (Transport::TransportTypeEnum)comboBoxTransportType->SelectedItem;
			for each (Institution ^ institution in InstitutionManager::Instance->GetInstitutionList()) {
				for each (Transport ^ transport in institution->TransportList) {
					if (transport->TransportType == selectedTransportType) {
						listBoxInstitutions->Items->Add(institution);
						break;
					}
				}
			}
		}
	}

	private: void SetTransportsDropdown() {
		comboBoxTransport->Items->Clear();
		if (comboBoxTransportType->SelectedItem == nullptr) {
			// all transports
			comboBoxTransport->Items->AddRange(TransportManager::Instance->GetTransportList()->ToArray());
		} else {
			// transports of selected kind
			Transport::TransportTypeEnum selectedTransportType = (Transport::TransportTypeEnum)comboBoxTransportType->SelectedItem;
			for each (Transport ^ transport in TransportManager::Instance->GetTransportList()) {
				if (transport->TransportType == selectedTransportType) {
					comboBoxTransport->Items->Add(transport);
				}
			}
		}
	}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void buttonReset_Click(System::Object^ sender, System::EventArgs^ e) {
		RefreshInstitutionListBox();
	}

	private: System::Void comboBoxTransportType_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		SetTransportsDropdown();
		UpdateInstitutionListBoxTransports();
	}

	private: System::Void comboBoxTransport_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		UpdateInstitutionListBoxTransports();
	}

	// search by text from textbox
	private: System::Void textBoxSearchInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		List<Institution^>^ newListOfInstitutions = gcnew List<Institution^>();
		for each (Institution^ institution in InstitutionManager::Instance->GetInstitutionList()) {
			array<String^>^ stringsInput = textBoxSearchInput->Text->ToLower()->Split(
				gcnew array<Char> {' ', ',', ';'}, StringSplitOptions::RemoveEmptyEntries
			);
			for each (String^ strInput in stringsInput) {
				if (institution->Name->ToLower()->Contains(strInput) || institution->Address->ToLower()->Contains(strInput)) {
					newListOfInstitutions->Add(institution);
				}
			}
		}
		listBoxInstitutions->Items->Clear();
		listBoxInstitutions->Items->AddRange(newListOfInstitutions->ToArray());
	}
};
}
