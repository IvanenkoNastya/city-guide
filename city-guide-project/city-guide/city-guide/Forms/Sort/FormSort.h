#pragma once

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormSort
	/// </summary>
	public ref class FormSort : public System::Windows::Forms::Form
	{
	public:
		FormSort(void)
		{
			InitializeComponent();

			RefreshInstitutionListBox();
			RefreshTransportListBox();
			RefreshDistrictListBox();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormSort()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::TabControl^ tabControl;

	private: System::Windows::Forms::TabPage^ tabPageInstitution;
	private: System::Windows::Forms::Button^ buttonSortInstitutionByName;
	private: System::Windows::Forms::ListBox^ listBoxInstitutions;


	private: System::Windows::Forms::TabPage^ tabPageTransport;
	private: System::Windows::Forms::TabPage^ tabPageDistrict;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonResetInstitutions;

	private: System::Windows::Forms::Button^ buttonSortByInstitutionType;
	private: System::Windows::Forms::Button^ buttonSortInstitutionsByAmountOfTransports;
	private: System::Windows::Forms::Button^ buttonSortInstitutionsByDistrict;
	private: System::Windows::Forms::Button^ buttonSortTransportsByName;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buttonSortTransportsByType;
	private: System::Windows::Forms::Button^ buttonResetTransports;

	private: System::Windows::Forms::ListBox^ listBoxTransports;
	private: System::Windows::Forms::Button^ buttonSortDistricts;
	private: System::Windows::Forms::Button^ buttonResetDistricts;
	private: System::Windows::Forms::ListBox^ listBoxDistricts;







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
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPageInstitution = (gcnew System::Windows::Forms::TabPage());
			this->buttonSortInstitutionsByDistrict = (gcnew System::Windows::Forms::Button());
			this->buttonSortByInstitutionType = (gcnew System::Windows::Forms::Button());
			this->buttonSortInstitutionsByAmountOfTransports = (gcnew System::Windows::Forms::Button());
			this->buttonResetInstitutions = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonSortInstitutionByName = (gcnew System::Windows::Forms::Button());
			this->listBoxInstitutions = (gcnew System::Windows::Forms::ListBox());
			this->tabPageTransport = (gcnew System::Windows::Forms::TabPage());
			this->buttonResetTransports = (gcnew System::Windows::Forms::Button());
			this->listBoxTransports = (gcnew System::Windows::Forms::ListBox());
			this->buttonSortTransportsByType = (gcnew System::Windows::Forms::Button());
			this->buttonSortTransportsByName = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabPageDistrict = (gcnew System::Windows::Forms::TabPage());
			this->listBoxDistricts = (gcnew System::Windows::Forms::ListBox());
			this->buttonResetDistricts = (gcnew System::Windows::Forms::Button());
			this->buttonSortDistricts = (gcnew System::Windows::Forms::Button());
			this->tabControl->SuspendLayout();
			this->tabPageInstitution->SuspendLayout();
			this->tabPageTransport->SuspendLayout();
			this->tabPageDistrict->SuspendLayout();
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
			this->buttonCancel->Click += gcnew System::EventHandler(this, &FormSort::buttonCancel_Click);
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabPageInstitution);
			this->tabControl->Controls->Add(this->tabPageTransport);
			this->tabControl->Controls->Add(this->tabPageDistrict);
			this->tabControl->Location = System::Drawing::Point(12, 12);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(472, 292);
			this->tabControl->TabIndex = 1;
			// 
			// tabPageInstitution
			// 
			this->tabPageInstitution->Controls->Add(this->buttonSortInstitutionsByDistrict);
			this->tabPageInstitution->Controls->Add(this->buttonSortByInstitutionType);
			this->tabPageInstitution->Controls->Add(this->buttonSortInstitutionsByAmountOfTransports);
			this->tabPageInstitution->Controls->Add(this->buttonResetInstitutions);
			this->tabPageInstitution->Controls->Add(this->label1);
			this->tabPageInstitution->Controls->Add(this->buttonSortInstitutionByName);
			this->tabPageInstitution->Controls->Add(this->listBoxInstitutions);
			this->tabPageInstitution->Location = System::Drawing::Point(4, 22);
			this->tabPageInstitution->Name = L"tabPageInstitution";
			this->tabPageInstitution->Padding = System::Windows::Forms::Padding(3);
			this->tabPageInstitution->Size = System::Drawing::Size(464, 266);
			this->tabPageInstitution->TabIndex = 0;
			this->tabPageInstitution->Text = L"Institutions";
			this->tabPageInstitution->UseVisualStyleBackColor = true;
			// 
			// buttonSortInstitutionsByDistrict
			// 
			this->buttonSortInstitutionsByDistrict->Location = System::Drawing::Point(340, 6);
			this->buttonSortInstitutionsByDistrict->Name = L"buttonSortInstitutionsByDistrict";
			this->buttonSortInstitutionsByDistrict->Size = System::Drawing::Size(54, 23);
			this->buttonSortInstitutionsByDistrict->TabIndex = 6;
			this->buttonSortInstitutionsByDistrict->Text = L"District";
			this->buttonSortInstitutionsByDistrict->UseVisualStyleBackColor = true;
			this->buttonSortInstitutionsByDistrict->Click += gcnew System::EventHandler(this, &FormSort::buttonSortByDistrict_Click);
			// 
			// buttonSortByInstitutionType
			// 
			this->buttonSortByInstitutionType->Location = System::Drawing::Point(246, 6);
			this->buttonSortByInstitutionType->Name = L"buttonSortByInstitutionType";
			this->buttonSortByInstitutionType->Size = System::Drawing::Size(88, 23);
			this->buttonSortByInstitutionType->TabIndex = 5;
			this->buttonSortByInstitutionType->Text = L"InstitutionType";
			this->buttonSortByInstitutionType->UseVisualStyleBackColor = true;
			this->buttonSortByInstitutionType->Click += gcnew System::EventHandler(this, &FormSort::buttonSortByInstitutionType_Click);
			// 
			// buttonSortInstitutionsByAmountOfTransports
			// 
			this->buttonSortInstitutionsByAmountOfTransports->Location = System::Drawing::Point(111, 6);
			this->buttonSortInstitutionsByAmountOfTransports->Name = L"buttonSortInstitutionsByAmountOfTransports";
			this->buttonSortInstitutionsByAmountOfTransports->Size = System::Drawing::Size(129, 23);
			this->buttonSortInstitutionsByAmountOfTransports->TabIndex = 4;
			this->buttonSortInstitutionsByAmountOfTransports->Text = L"Amount of transports";
			this->buttonSortInstitutionsByAmountOfTransports->UseVisualStyleBackColor = true;
			this->buttonSortInstitutionsByAmountOfTransports->Click += gcnew System::EventHandler(this, &FormSort::buttonSortByAmountOfTransports_Click);
			// 
			// buttonResetInstitutions
			// 
			this->buttonResetInstitutions->Location = System::Drawing::Point(6, 237);
			this->buttonResetInstitutions->Name = L"buttonResetInstitutions";
			this->buttonResetInstitutions->Size = System::Drawing::Size(75, 23);
			this->buttonResetInstitutions->TabIndex = 3;
			this->buttonResetInstitutions->Text = L"Reset";
			this->buttonResetInstitutions->UseVisualStyleBackColor = true;
			this->buttonResetInstitutions->Click += gcnew System::EventHandler(this, &FormSort::buttonResetInstitutions_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Sort by";
			// 
			// buttonSortInstitutionByName
			// 
			this->buttonSortInstitutionByName->Location = System::Drawing::Point(52, 6);
			this->buttonSortInstitutionByName->Name = L"buttonSortInstitutionByName";
			this->buttonSortInstitutionByName->Size = System::Drawing::Size(53, 23);
			this->buttonSortInstitutionByName->TabIndex = 1;
			this->buttonSortInstitutionByName->Text = L"Name";
			this->buttonSortInstitutionByName->UseVisualStyleBackColor = true;
			this->buttonSortInstitutionByName->Click += gcnew System::EventHandler(this, &FormSort::buttonSortByName_Click);
			// 
			// listBoxInstitutions
			// 
			this->listBoxInstitutions->FormattingEnabled = true;
			this->listBoxInstitutions->Location = System::Drawing::Point(6, 35);
			this->listBoxInstitutions->Name = L"listBoxInstitutions";
			this->listBoxInstitutions->Size = System::Drawing::Size(452, 199);
			this->listBoxInstitutions->TabIndex = 0;
			// 
			// tabPageTransport
			// 
			this->tabPageTransport->Controls->Add(this->buttonResetTransports);
			this->tabPageTransport->Controls->Add(this->listBoxTransports);
			this->tabPageTransport->Controls->Add(this->buttonSortTransportsByType);
			this->tabPageTransport->Controls->Add(this->buttonSortTransportsByName);
			this->tabPageTransport->Controls->Add(this->label2);
			this->tabPageTransport->Location = System::Drawing::Point(4, 22);
			this->tabPageTransport->Name = L"tabPageTransport";
			this->tabPageTransport->Padding = System::Windows::Forms::Padding(3);
			this->tabPageTransport->Size = System::Drawing::Size(464, 266);
			this->tabPageTransport->TabIndex = 1;
			this->tabPageTransport->Text = L"Transports";
			this->tabPageTransport->UseVisualStyleBackColor = true;
			// 
			// buttonResetTransports
			// 
			this->buttonResetTransports->Location = System::Drawing::Point(6, 237);
			this->buttonResetTransports->Name = L"buttonResetTransports";
			this->buttonResetTransports->Size = System::Drawing::Size(75, 23);
			this->buttonResetTransports->TabIndex = 6;
			this->buttonResetTransports->Text = L"Reset";
			this->buttonResetTransports->UseVisualStyleBackColor = true;
			this->buttonResetTransports->Click += gcnew System::EventHandler(this, &FormSort::buttonResetTransports_Click);
			// 
			// listBoxTransports
			// 
			this->listBoxTransports->FormattingEnabled = true;
			this->listBoxTransports->Location = System::Drawing::Point(6, 35);
			this->listBoxTransports->Name = L"listBoxTransports";
			this->listBoxTransports->Size = System::Drawing::Size(452, 199);
			this->listBoxTransports->TabIndex = 5;
			// 
			// buttonSortTransportsByType
			// 
			this->buttonSortTransportsByType->Location = System::Drawing::Point(133, 6);
			this->buttonSortTransportsByType->Name = L"buttonSortTransportsByType";
			this->buttonSortTransportsByType->Size = System::Drawing::Size(75, 23);
			this->buttonSortTransportsByType->TabIndex = 4;
			this->buttonSortTransportsByType->Text = L"Type";
			this->buttonSortTransportsByType->UseVisualStyleBackColor = true;
			this->buttonSortTransportsByType->Click += gcnew System::EventHandler(this, &FormSort::buttonSortTransportsByType_Click);
			// 
			// buttonSortTransportsByName
			// 
			this->buttonSortTransportsByName->Location = System::Drawing::Point(52, 6);
			this->buttonSortTransportsByName->Name = L"buttonSortTransportsByName";
			this->buttonSortTransportsByName->Size = System::Drawing::Size(75, 23);
			this->buttonSortTransportsByName->TabIndex = 3;
			this->buttonSortTransportsByName->Text = L"Name";
			this->buttonSortTransportsByName->UseVisualStyleBackColor = true;
			this->buttonSortTransportsByName->Click += gcnew System::EventHandler(this, &FormSort::buttonSortTransportsByName_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Sort by";
			// 
			// tabPageDistrict
			// 
			this->tabPageDistrict->Controls->Add(this->listBoxDistricts);
			this->tabPageDistrict->Controls->Add(this->buttonResetDistricts);
			this->tabPageDistrict->Controls->Add(this->buttonSortDistricts);
			this->tabPageDistrict->Location = System::Drawing::Point(4, 22);
			this->tabPageDistrict->Name = L"tabPageDistrict";
			this->tabPageDistrict->Padding = System::Windows::Forms::Padding(3);
			this->tabPageDistrict->Size = System::Drawing::Size(464, 266);
			this->tabPageDistrict->TabIndex = 2;
			this->tabPageDistrict->Text = L"Districts";
			this->tabPageDistrict->UseVisualStyleBackColor = true;
			// 
			// listBoxDistricts
			// 
			this->listBoxDistricts->FormattingEnabled = true;
			this->listBoxDistricts->Location = System::Drawing::Point(6, 35);
			this->listBoxDistricts->Name = L"listBoxDistricts";
			this->listBoxDistricts->Size = System::Drawing::Size(452, 199);
			this->listBoxDistricts->TabIndex = 2;
			// 
			// buttonResetDistricts
			// 
			this->buttonResetDistricts->Location = System::Drawing::Point(6, 237);
			this->buttonResetDistricts->Name = L"buttonResetDistricts";
			this->buttonResetDistricts->Size = System::Drawing::Size(75, 23);
			this->buttonResetDistricts->TabIndex = 1;
			this->buttonResetDistricts->Text = L"Reset";
			this->buttonResetDistricts->UseVisualStyleBackColor = true;
			this->buttonResetDistricts->Click += gcnew System::EventHandler(this, &FormSort::buttonResetDistricts_Click);
			// 
			// buttonSortDistricts
			// 
			this->buttonSortDistricts->Location = System::Drawing::Point(6, 6);
			this->buttonSortDistricts->Name = L"buttonSortDistricts";
			this->buttonSortDistricts->Size = System::Drawing::Size(75, 23);
			this->buttonSortDistricts->TabIndex = 0;
			this->buttonSortDistricts->Text = L"Sort";
			this->buttonSortDistricts->UseVisualStyleBackColor = true;
			this->buttonSortDistricts->Click += gcnew System::EventHandler(this, &FormSort::buttonSortDistricts_Click);
			// 
			// FormSort
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 345);
			this->Controls->Add(this->tabControl);
			this->Controls->Add(this->buttonCancel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FormSort";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sort";
			this->tabControl->ResumeLayout(false);
			this->tabPageInstitution->ResumeLayout(false);
			this->tabPageInstitution->PerformLayout();
			this->tabPageTransport->ResumeLayout(false);
			this->tabPageTransport->PerformLayout();
			this->tabPageDistrict->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	// institutions
	private: void RefreshInstitutionListBox() {
		listBoxInstitutions->Items->Clear();
		listBoxInstitutions->Items->AddRange(InstitutionManager::Instance->GetInstitutionList()->ToArray());
	}

	private: System::Void buttonResetInstitutions_Click(System::Object^ sender, System::EventArgs^ e) {
		RefreshInstitutionListBox();
	}

	private: System::Void buttonSortByName_Click(System::Object^ sender, System::EventArgs^ e) {
		List<Institution^>^ institutionsToSort = gcnew List<Institution^>();
		institutionsToSort->AddRange(InstitutionManager::Instance->GetInstitutionList());
		institutionsToSort->Sort(gcnew CompareInstitutionsByName());
		listBoxInstitutions->Items->Clear();
		listBoxInstitutions->Items->AddRange(institutionsToSort->ToArray());
	}

	private: System::Void buttonSortByAmountOfTransports_Click(System::Object^ sender, System::EventArgs^ e) {
		List<Institution^>^ institutionsToSort = gcnew List<Institution^>();
		institutionsToSort->AddRange(InstitutionManager::Instance->GetInstitutionList());
		institutionsToSort->Sort(gcnew CompareInstitutionsByAmountOfTransports());
		listBoxInstitutions->Items->Clear();
		for each (Institution^ institution in institutionsToSort) {
			listBoxInstitutions->Items->Add(institution->GetNameWithTransportsAmount());
		}
	}

	private: System::Void buttonSortByInstitutionType_Click(System::Object^ sender, System::EventArgs^ e) {
		List<Institution^>^ institutionsToSort = gcnew List<Institution^>();
		institutionsToSort->AddRange(InstitutionManager::Instance->GetInstitutionList());
		institutionsToSort->Sort(gcnew CompareInstitutionsByType());
		listBoxInstitutions->Items->Clear();
		listBoxInstitutions->Items->AddRange(institutionsToSort->ToArray());
	}

	private: System::Void buttonSortByDistrict_Click(System::Object^ sender, System::EventArgs^ e) {
		List<Institution^>^ institutionsToSort = gcnew List<Institution^>();
		institutionsToSort->AddRange(InstitutionManager::Instance->GetInstitutionList());
		institutionsToSort->Sort(gcnew CompareInstitutionsByDistrict());
		listBoxInstitutions->Items->Clear();
		for each (Institution ^ institution in institutionsToSort) {
			listBoxInstitutions->Items->Add(institution->GetNameWithDistrict());
		}
	}

	// transports
	private: void RefreshTransportListBox() {
		listBoxTransports->Items->Clear();
		listBoxTransports->Items->AddRange(TransportManager::Instance->GetTransportList()->ToArray());
	}

	private: System::Void buttonResetTransports_Click(System::Object^ sender, System::EventArgs^ e) {
		RefreshTransportListBox();
	}

	private: System::Void buttonSortTransportsByName_Click(System::Object^ sender, System::EventArgs^ e) {
		List<Transport^>^ transportsToSort = gcnew List<Transport^>();
		transportsToSort->AddRange(TransportManager::Instance->GetTransportList());
		transportsToSort->Sort(gcnew CompareTransportsByName());
		listBoxTransports->Items->Clear();
		listBoxTransports->Items->AddRange(transportsToSort->ToArray());
	}

	private: System::Void buttonSortTransportsByType_Click(System::Object^ sender, System::EventArgs^ e) {
		List<Transport^>^ transportsToSort = gcnew List<Transport^>();
		transportsToSort->AddRange(TransportManager::Instance->GetTransportList());
		transportsToSort->Sort(gcnew CompareTransportsByType());
		listBoxTransports->Items->Clear();
		listBoxTransports->Items->AddRange(transportsToSort->ToArray());
	}

	// districts
	private: void RefreshDistrictListBox() {
		listBoxDistricts->Items->Clear();
		listBoxDistricts->Items->AddRange(DistrictManager::Instance->GetDistrictList()->ToArray());
	}

	private: System::Void buttonResetDistricts_Click(System::Object^ sender, System::EventArgs^ e) {
		RefreshDistrictListBox();
	}

	private: System::Void buttonSortDistricts_Click(System::Object^ sender, System::EventArgs^ e) {
		List<String^>^ districtsToSort = gcnew List<String^>();
		districtsToSort->AddRange(DistrictManager::Instance->GetDistrictList());
		districtsToSort->Sort();
		listBoxDistricts->Items->Clear();
		listBoxDistricts->Items->AddRange(districtsToSort->ToArray());
	}
};
}
