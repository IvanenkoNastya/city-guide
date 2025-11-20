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
	private: System::Windows::Forms::TabControl^ tabControl;

	private: System::Windows::Forms::TabPage^ tabPageLighthouse;

	private: System::Windows::Forms::TabPage^ tabPageWharf;
	private: System::Windows::Forms::TabPage^ tabPageMuseum;
	private: System::Windows::Forms::TabPage^ tabPageTheatre;
	private: System::Windows::Forms::TabPage^ tabPageLibrary;
	private: System::Windows::Forms::TabPage^ tabPageHospital;
	private: System::Windows::Forms::TabPage^ tabPageAirport;
	private: System::Windows::Forms::TabPage^ tabPageSchool;
	private: System::Windows::Forms::TabPage^ tabPageMall;

	private: System::Windows::Forms::CheckBox^ checkBoxAirportIsInternational;
	private: System::Windows::Forms::TabPage^ tabPageRestaurant;
	private: System::Windows::Forms::TextBox^ textBoxLighthouseColour;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ comboBoxHospitalType;
	private: System::Windows::Forms::CheckBox^ checkBoxLibraryIsUniversity;
	private: System::Windows::Forms::CheckBox^ checkBoxMallHasParking;
	private: System::Windows::Forms::CheckBox^ checkBoxMallHasEntertainment;

	private: System::Windows::Forms::CheckBox^ checkBoxMallHasGrocery;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ comboBoxMuseumType;
	private: System::Windows::Forms::Label^ labelCuisine;
	private: System::Windows::Forms::TextBox^ textBoxRestaurantCuisine;
	private: System::Windows::Forms::Label^ labelSchoolFaculties;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownSchoolFaculties;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownWharfNumberOfFloatingVehicles;
private: System::Windows::Forms::CheckBox^ checkBoxTheatreHasOrchestra;





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
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPageLighthouse = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBoxLighthouseColour = (gcnew System::Windows::Forms::TextBox());
			this->tabPageWharf = (gcnew System::Windows::Forms::TabPage());
			this->numericUpDownWharfNumberOfFloatingVehicles = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tabPageMuseum = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBoxMuseumType = (gcnew System::Windows::Forms::ComboBox());
			this->tabPageTheatre = (gcnew System::Windows::Forms::TabPage());
			this->checkBoxTheatreHasOrchestra = (gcnew System::Windows::Forms::CheckBox());
			this->tabPageLibrary = (gcnew System::Windows::Forms::TabPage());
			this->checkBoxLibraryIsUniversity = (gcnew System::Windows::Forms::CheckBox());
			this->tabPageHospital = (gcnew System::Windows::Forms::TabPage());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBoxHospitalType = (gcnew System::Windows::Forms::ComboBox());
			this->tabPageAirport = (gcnew System::Windows::Forms::TabPage());
			this->checkBoxAirportIsInternational = (gcnew System::Windows::Forms::CheckBox());
			this->tabPageSchool = (gcnew System::Windows::Forms::TabPage());
			this->labelSchoolFaculties = (gcnew System::Windows::Forms::Label());
			this->numericUpDownSchoolFaculties = (gcnew System::Windows::Forms::NumericUpDown());
			this->tabPageMall = (gcnew System::Windows::Forms::TabPage());
			this->checkBoxMallHasEntertainment = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxMallHasGrocery = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxMallHasParking = (gcnew System::Windows::Forms::CheckBox());
			this->tabPageRestaurant = (gcnew System::Windows::Forms::TabPage());
			this->labelCuisine = (gcnew System::Windows::Forms::Label());
			this->textBoxRestaurantCuisine = (gcnew System::Windows::Forms::TextBox());
			this->tabControl->SuspendLayout();
			this->tabPageLighthouse->SuspendLayout();
			this->tabPageWharf->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownWharfNumberOfFloatingVehicles))->BeginInit();
			this->tabPageMuseum->SuspendLayout();
			this->tabPageTheatre->SuspendLayout();
			this->tabPageLibrary->SuspendLayout();
			this->tabPageHospital->SuspendLayout();
			this->tabPageAirport->SuspendLayout();
			this->tabPageSchool->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSchoolFaculties))->BeginInit();
			this->tabPageMall->SuspendLayout();
			this->tabPageRestaurant->SuspendLayout();
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
			this->buttonCancel->Location = System::Drawing::Point(409, 310);
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
			this->textBoxName->Size = System::Drawing::Size(176, 20);
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
			this->comboBoxDistrict->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxDistrict->FormattingEnabled = true;
			this->comboBoxDistrict->Location = System::Drawing::Point(92, 38);
			this->comboBoxDistrict->Name = L"comboBoxDistrict";
			this->comboBoxDistrict->Size = System::Drawing::Size(176, 21);
			this->comboBoxDistrict->TabIndex = 13;
			// 
			// checkedListBoxTransport
			// 
			this->checkedListBoxTransport->FormattingEnabled = true;
			this->checkedListBoxTransport->Location = System::Drawing::Point(16, 116);
			this->checkedListBoxTransport->Name = L"checkedListBoxTransport";
			this->checkedListBoxTransport->Size = System::Drawing::Size(252, 184);
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
			this->textBoxAddress->Size = System::Drawing::Size(176, 20);
			this->textBoxAddress->TabIndex = 17;
			// 
			// tabControl
			// 
			this->tabControl->Appearance = System::Windows::Forms::TabAppearance::Buttons;
			this->tabControl->Controls->Add(this->tabPageLighthouse);
			this->tabControl->Controls->Add(this->tabPageWharf);
			this->tabControl->Controls->Add(this->tabPageMuseum);
			this->tabControl->Controls->Add(this->tabPageTheatre);
			this->tabControl->Controls->Add(this->tabPageLibrary);
			this->tabControl->Controls->Add(this->tabPageHospital);
			this->tabControl->Controls->Add(this->tabPageAirport);
			this->tabControl->Controls->Add(this->tabPageSchool);
			this->tabControl->Controls->Add(this->tabPageMall);
			this->tabControl->Controls->Add(this->tabPageRestaurant);
			this->tabControl->Location = System::Drawing::Point(274, 12);
			this->tabControl->Multiline = true;
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(210, 288);
			this->tabControl->TabIndex = 18;
			// 
			// tabPageLighthouse
			// 
			this->tabPageLighthouse->Controls->Add(this->label4);
			this->tabPageLighthouse->Controls->Add(this->textBoxLighthouseColour);
			this->tabPageLighthouse->Location = System::Drawing::Point(4, 73);
			this->tabPageLighthouse->Name = L"tabPageLighthouse";
			this->tabPageLighthouse->Padding = System::Windows::Forms::Padding(3);
			this->tabPageLighthouse->Size = System::Drawing::Size(202, 211);
			this->tabPageLighthouse->TabIndex = 0;
			this->tabPageLighthouse->Text = L"Lighthouse";
			this->tabPageLighthouse->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 30);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 13);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Light colour";
			// 
			// textBoxLighthouseColour
			// 
			this->textBoxLighthouseColour->Location = System::Drawing::Point(6, 46);
			this->textBoxLighthouseColour->Name = L"textBoxLighthouseColour";
			this->textBoxLighthouseColour->Size = System::Drawing::Size(190, 20);
			this->textBoxLighthouseColour->TabIndex = 0;
			// 
			// tabPageWharf
			// 
			this->tabPageWharf->Controls->Add(this->numericUpDownWharfNumberOfFloatingVehicles);
			this->tabPageWharf->Controls->Add(this->label7);
			this->tabPageWharf->Location = System::Drawing::Point(4, 73);
			this->tabPageWharf->Name = L"tabPageWharf";
			this->tabPageWharf->Padding = System::Windows::Forms::Padding(3);
			this->tabPageWharf->Size = System::Drawing::Size(202, 211);
			this->tabPageWharf->TabIndex = 1;
			this->tabPageWharf->Text = L"Wharf";
			this->tabPageWharf->UseVisualStyleBackColor = true;
			// 
			// numericUpDownWharfNumberOfFloatingVehicles
			// 
			this->numericUpDownWharfNumberOfFloatingVehicles->Location = System::Drawing::Point(7, 46);
			this->numericUpDownWharfNumberOfFloatingVehicles->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {
				1000, 0,
					0, 0
			});
			this->numericUpDownWharfNumberOfFloatingVehicles->Name = L"numericUpDownWharfNumberOfFloatingVehicles";
			this->numericUpDownWharfNumberOfFloatingVehicles->Size = System::Drawing::Size(97, 20);
			this->numericUpDownWharfNumberOfFloatingVehicles->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 30);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(139, 13);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Number of Floating Vehicles";
			// 
			// tabPageMuseum
			// 
			this->tabPageMuseum->Controls->Add(this->label6);
			this->tabPageMuseum->Controls->Add(this->comboBoxMuseumType);
			this->tabPageMuseum->Location = System::Drawing::Point(4, 73);
			this->tabPageMuseum->Name = L"tabPageMuseum";
			this->tabPageMuseum->Padding = System::Windows::Forms::Padding(3);
			this->tabPageMuseum->Size = System::Drawing::Size(202, 211);
			this->tabPageMuseum->TabIndex = 2;
			this->tabPageMuseum->Text = L"Museum";
			this->tabPageMuseum->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 30);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 13);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Museum type";
			// 
			// comboBoxMuseumType
			// 
			this->comboBoxMuseumType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxMuseumType->FormattingEnabled = true;
			this->comboBoxMuseumType->Location = System::Drawing::Point(6, 46);
			this->comboBoxMuseumType->Name = L"comboBoxMuseumType";
			this->comboBoxMuseumType->Size = System::Drawing::Size(186, 21);
			this->comboBoxMuseumType->TabIndex = 2;
			// 
			// tabPageTheatre
			// 
			this->tabPageTheatre->Controls->Add(this->checkBoxTheatreHasOrchestra);
			this->tabPageTheatre->Location = System::Drawing::Point(4, 73);
			this->tabPageTheatre->Name = L"tabPageTheatre";
			this->tabPageTheatre->Padding = System::Windows::Forms::Padding(3);
			this->tabPageTheatre->Size = System::Drawing::Size(202, 211);
			this->tabPageTheatre->TabIndex = 3;
			this->tabPageTheatre->Text = L"Theatre";
			this->tabPageTheatre->UseVisualStyleBackColor = true;
			// 
			// checkBoxTheatreHasOrchestra
			// 
			this->checkBoxTheatreHasOrchestra->AutoSize = true;
			this->checkBoxTheatreHasOrchestra->Location = System::Drawing::Point(6, 46);
			this->checkBoxTheatreHasOrchestra->Name = L"checkBoxTheatreHasOrchestra";
			this->checkBoxTheatreHasOrchestra->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBoxTheatreHasOrchestra->Size = System::Drawing::Size(92, 17);
			this->checkBoxTheatreHasOrchestra->TabIndex = 0;
			this->checkBoxTheatreHasOrchestra->Text = L"Has orchestra";
			this->checkBoxTheatreHasOrchestra->UseVisualStyleBackColor = true;
			// 
			// tabPageLibrary
			// 
			this->tabPageLibrary->Controls->Add(this->checkBoxLibraryIsUniversity);
			this->tabPageLibrary->Location = System::Drawing::Point(4, 73);
			this->tabPageLibrary->Name = L"tabPageLibrary";
			this->tabPageLibrary->Padding = System::Windows::Forms::Padding(3);
			this->tabPageLibrary->Size = System::Drawing::Size(202, 211);
			this->tabPageLibrary->TabIndex = 4;
			this->tabPageLibrary->Text = L"Library";
			this->tabPageLibrary->UseVisualStyleBackColor = true;
			// 
			// checkBoxLibraryIsUniversity
			// 
			this->checkBoxLibraryIsUniversity->AutoSize = true;
			this->checkBoxLibraryIsUniversity->Location = System::Drawing::Point(7, 46);
			this->checkBoxLibraryIsUniversity->Name = L"checkBoxLibraryIsUniversity";
			this->checkBoxLibraryIsUniversity->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBoxLibraryIsUniversity->Size = System::Drawing::Size(117, 17);
			this->checkBoxLibraryIsUniversity->TabIndex = 0;
			this->checkBoxLibraryIsUniversity->Text = L"Is University Library";
			this->checkBoxLibraryIsUniversity->UseVisualStyleBackColor = true;
			// 
			// tabPageHospital
			// 
			this->tabPageHospital->Controls->Add(this->label5);
			this->tabPageHospital->Controls->Add(this->comboBoxHospitalType);
			this->tabPageHospital->Location = System::Drawing::Point(4, 73);
			this->tabPageHospital->Name = L"tabPageHospital";
			this->tabPageHospital->Padding = System::Windows::Forms::Padding(3);
			this->tabPageHospital->Size = System::Drawing::Size(202, 211);
			this->tabPageHospital->TabIndex = 5;
			this->tabPageHospital->Text = L"Hospital";
			this->tabPageHospital->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(7, 30);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(68, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Hospital type";
			// 
			// comboBoxHospitalType
			// 
			this->comboBoxHospitalType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxHospitalType->FormattingEnabled = true;
			this->comboBoxHospitalType->Location = System::Drawing::Point(10, 46);
			this->comboBoxHospitalType->Name = L"comboBoxHospitalType";
			this->comboBoxHospitalType->Size = System::Drawing::Size(186, 21);
			this->comboBoxHospitalType->TabIndex = 0;
			// 
			// tabPageAirport
			// 
			this->tabPageAirport->Controls->Add(this->checkBoxAirportIsInternational);
			this->tabPageAirport->Location = System::Drawing::Point(4, 73);
			this->tabPageAirport->Name = L"tabPageAirport";
			this->tabPageAirport->Padding = System::Windows::Forms::Padding(3);
			this->tabPageAirport->Size = System::Drawing::Size(202, 211);
			this->tabPageAirport->TabIndex = 6;
			this->tabPageAirport->Text = L"Airport";
			this->tabPageAirport->UseVisualStyleBackColor = true;
			// 
			// checkBoxAirportIsInternational
			// 
			this->checkBoxAirportIsInternational->AutoSize = true;
			this->checkBoxAirportIsInternational->Location = System::Drawing::Point(6, 46);
			this->checkBoxAirportIsInternational->Name = L"checkBoxAirportIsInternational";
			this->checkBoxAirportIsInternational->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBoxAirportIsInternational->Size = System::Drawing::Size(84, 17);
			this->checkBoxAirportIsInternational->TabIndex = 0;
			this->checkBoxAirportIsInternational->Text = L"International";
			this->checkBoxAirportIsInternational->UseVisualStyleBackColor = true;
			// 
			// tabPageSchool
			// 
			this->tabPageSchool->Controls->Add(this->labelSchoolFaculties);
			this->tabPageSchool->Controls->Add(this->numericUpDownSchoolFaculties);
			this->tabPageSchool->Location = System::Drawing::Point(4, 73);
			this->tabPageSchool->Name = L"tabPageSchool";
			this->tabPageSchool->Padding = System::Windows::Forms::Padding(3);
			this->tabPageSchool->Size = System::Drawing::Size(202, 211);
			this->tabPageSchool->TabIndex = 7;
			this->tabPageSchool->Text = L"School";
			this->tabPageSchool->UseVisualStyleBackColor = true;
			// 
			// labelSchoolFaculties
			// 
			this->labelSchoolFaculties->AutoSize = true;
			this->labelSchoolFaculties->Location = System::Drawing::Point(7, 27);
			this->labelSchoolFaculties->Name = L"labelSchoolFaculties";
			this->labelSchoolFaculties->Size = System::Drawing::Size(101, 13);
			this->labelSchoolFaculties->TabIndex = 1;
			this->labelSchoolFaculties->Text = L"Number of Faculties";
			// 
			// numericUpDownSchoolFaculties
			// 
			this->numericUpDownSchoolFaculties->Location = System::Drawing::Point(6, 46);
			this->numericUpDownSchoolFaculties->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			this->numericUpDownSchoolFaculties->Name = L"numericUpDownSchoolFaculties";
			this->numericUpDownSchoolFaculties->Size = System::Drawing::Size(102, 20);
			this->numericUpDownSchoolFaculties->TabIndex = 0;
			this->numericUpDownSchoolFaculties->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// tabPageMall
			// 
			this->tabPageMall->Controls->Add(this->checkBoxMallHasEntertainment);
			this->tabPageMall->Controls->Add(this->checkBoxMallHasGrocery);
			this->tabPageMall->Controls->Add(this->checkBoxMallHasParking);
			this->tabPageMall->Location = System::Drawing::Point(4, 73);
			this->tabPageMall->Name = L"tabPageMall";
			this->tabPageMall->Padding = System::Windows::Forms::Padding(3);
			this->tabPageMall->Size = System::Drawing::Size(202, 211);
			this->tabPageMall->TabIndex = 8;
			this->tabPageMall->Text = L"Mall";
			this->tabPageMall->UseVisualStyleBackColor = true;
			// 
			// checkBoxMallHasEntertainment
			// 
			this->checkBoxMallHasEntertainment->AutoSize = true;
			this->checkBoxMallHasEntertainment->Location = System::Drawing::Point(6, 92);
			this->checkBoxMallHasEntertainment->Name = L"checkBoxMallHasEntertainment";
			this->checkBoxMallHasEntertainment->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBoxMallHasEntertainment->Size = System::Drawing::Size(145, 17);
			this->checkBoxMallHasEntertainment->TabIndex = 3;
			this->checkBoxMallHasEntertainment->Text = L"Has entertainment center";
			this->checkBoxMallHasEntertainment->UseVisualStyleBackColor = true;
			// 
			// checkBoxMallHasGrocery
			// 
			this->checkBoxMallHasGrocery->AutoSize = true;
			this->checkBoxMallHasGrocery->Location = System::Drawing::Point(42, 69);
			this->checkBoxMallHasGrocery->Name = L"checkBoxMallHasGrocery";
			this->checkBoxMallHasGrocery->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBoxMallHasGrocery->Size = System::Drawing::Size(109, 17);
			this->checkBoxMallHasGrocery->TabIndex = 2;
			this->checkBoxMallHasGrocery->Text = L"Has grocery shop";
			this->checkBoxMallHasGrocery->UseVisualStyleBackColor = true;
			// 
			// checkBoxMallHasParking
			// 
			this->checkBoxMallHasParking->AutoSize = true;
			this->checkBoxMallHasParking->Location = System::Drawing::Point(68, 46);
			this->checkBoxMallHasParking->Name = L"checkBoxMallHasParking";
			this->checkBoxMallHasParking->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBoxMallHasParking->Size = System::Drawing::Size(83, 17);
			this->checkBoxMallHasParking->TabIndex = 1;
			this->checkBoxMallHasParking->Text = L"Has parking";
			this->checkBoxMallHasParking->UseVisualStyleBackColor = true;
			// 
			// tabPageRestaurant
			// 
			this->tabPageRestaurant->Controls->Add(this->labelCuisine);
			this->tabPageRestaurant->Controls->Add(this->textBoxRestaurantCuisine);
			this->tabPageRestaurant->Location = System::Drawing::Point(4, 73);
			this->tabPageRestaurant->Name = L"tabPageRestaurant";
			this->tabPageRestaurant->Padding = System::Windows::Forms::Padding(3);
			this->tabPageRestaurant->Size = System::Drawing::Size(202, 211);
			this->tabPageRestaurant->TabIndex = 9;
			this->tabPageRestaurant->Text = L"Restaurant";
			this->tabPageRestaurant->UseVisualStyleBackColor = true;
			// 
			// labelCuisine
			// 
			this->labelCuisine->AutoSize = true;
			this->labelCuisine->Location = System::Drawing::Point(7, 27);
			this->labelCuisine->Name = L"labelCuisine";
			this->labelCuisine->Size = System::Drawing::Size(41, 13);
			this->labelCuisine->TabIndex = 1;
			this->labelCuisine->Text = L"Cuisine";
			// 
			// textBoxRestaurantCuisine
			// 
			this->textBoxRestaurantCuisine->Location = System::Drawing::Point(7, 46);
			this->textBoxRestaurantCuisine->Name = L"textBoxRestaurantCuisine";
			this->textBoxRestaurantCuisine->Size = System::Drawing::Size(189, 20);
			this->textBoxRestaurantCuisine->TabIndex = 0;
			// 
			// FormInstitutionAddOrEdit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 345);
			this->Controls->Add(this->tabControl);
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
			this->tabControl->ResumeLayout(false);
			this->tabPageLighthouse->ResumeLayout(false);
			this->tabPageLighthouse->PerformLayout();
			this->tabPageWharf->ResumeLayout(false);
			this->tabPageWharf->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownWharfNumberOfFloatingVehicles))->EndInit();
			this->tabPageMuseum->ResumeLayout(false);
			this->tabPageMuseum->PerformLayout();
			this->tabPageTheatre->ResumeLayout(false);
			this->tabPageTheatre->PerformLayout();
			this->tabPageLibrary->ResumeLayout(false);
			this->tabPageLibrary->PerformLayout();
			this->tabPageHospital->ResumeLayout(false);
			this->tabPageHospital->PerformLayout();
			this->tabPageAirport->ResumeLayout(false);
			this->tabPageAirport->PerformLayout();
			this->tabPageSchool->ResumeLayout(false);
			this->tabPageSchool->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSchoolFaculties))->EndInit();
			this->tabPageMall->ResumeLayout(false);
			this->tabPageMall->PerformLayout();
			this->tabPageRestaurant->ResumeLayout(false);
			this->tabPageRestaurant->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		void RefreshForm() {
			comboBoxDistrict->Items->AddRange(DistrictManager::Instance->GetDistrictList()->ToArray());
			tabControl->Appearance = TabAppearance::FlatButtons;
			tabControl->ItemSize = System::Drawing::Size(0, 1);
			tabControl->SizeMode = TabSizeMode::Fixed;
			switch (_institutionType) {
			case InstitutionTypeEnum::Airport: {
				tabControl->SelectedTab = tabPageAirport;
				break;
			}
			case InstitutionTypeEnum::Hospital: {
				tabControl->SelectedTab = tabPageHospital;
				for each (Object ^ type in Enum::GetValues(Hospital::HospitalTypeEnum::typeid)) {
					comboBoxHospitalType->Items->Add(type);
				}
				break;
			}
			case InstitutionTypeEnum::Library: {
				tabControl->SelectedTab = tabPageLibrary;
				break;
			}
			case InstitutionTypeEnum::Lighthouse: {
				tabControl->SelectedTab = tabPageLighthouse;
				break;
			}
			case InstitutionTypeEnum::Mall: {
				tabControl->SelectedTab = tabPageMall;
				break;
			}
			case InstitutionTypeEnum::Museum: {
				tabControl->SelectedTab = tabPageMuseum;
				for each (Object ^ type in Enum::GetValues(Museum::MuseumTypeEnum::typeid)) {
					comboBoxMuseumType->Items->Add(type);
				}
				break;
			}
			case InstitutionTypeEnum::Restaurant: {
				tabControl->SelectedTab = tabPageRestaurant;
				break;
			}
			case InstitutionTypeEnum::School: {
				tabControl->SelectedTab = tabPageSchool;
				break;
			}
			case InstitutionTypeEnum::Theatre: {
				tabControl->SelectedTab = tabPageTheatre;
				break;
			}
			case InstitutionTypeEnum::Wharf: {
				tabControl->SelectedTab = tabPageWharf;
				break;
			}
			default: {
				MessageBox::Show("Couldn't find institution type", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->Close();
				return;
			}
			}

			if (_selectedInstitution == nullptr || _selectedInstitution->TransportList == nullptr) {
				// add
				checkedListBoxTransport->Items->AddRange(TransportManager::Instance->GetTransportList()->ToArray());
			} else {
				// edit
				// fill transports checklist
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

				// fill institution selected special values
				switch (_institutionType) {
				case InstitutionTypeEnum::Airport: {
					Airport^ airport = dynamic_cast<Airport^>(_selectedInstitution);
					checkBoxAirportIsInternational->Checked = airport->IsInternational;
					break;
				}
				case InstitutionTypeEnum::Hospital: {
					Hospital^ hospital = dynamic_cast<Hospital^>(_selectedInstitution);
					comboBoxHospitalType->Text = hospital->HospitalType.ToString();
					break;
				}
				case InstitutionTypeEnum::Library: {
					Library^ library = dynamic_cast<Library^>(_selectedInstitution);
					checkBoxLibraryIsUniversity->Checked = library->IsUniversityLibrary;
					break;
				}
				case InstitutionTypeEnum::Lighthouse: {
					Lighthouse^ lighthouse = dynamic_cast<Lighthouse^>(_selectedInstitution);
					textBoxLighthouseColour->Text = lighthouse->LightColour;
					break;
				}
				case InstitutionTypeEnum::Mall: {
					Mall^ mall = dynamic_cast<Mall^>(_selectedInstitution);
					checkBoxMallHasParking->Checked = mall->HasParking;
					checkBoxMallHasGrocery->Checked = mall->HasGrocery;
					checkBoxMallHasEntertainment->Checked = mall->HasEntertainmentCenter;
					break;
				}
				case InstitutionTypeEnum::Museum: {
					Museum^ museum = dynamic_cast<Museum^>(_selectedInstitution);
					comboBoxMuseumType->Text = museum->MuseumType.ToString();
					break;
				}
				case InstitutionTypeEnum::Restaurant: {
					Restaurant^ restaurant = dynamic_cast<Restaurant^>(_selectedInstitution);
					textBoxRestaurantCuisine->Text = restaurant->Cuisine;
					break;
				}
				case InstitutionTypeEnum::School: {
					School^ school = dynamic_cast<School^>(_selectedInstitution);
					numericUpDownSchoolFaculties->Value = school->NumberOfFaculties;
					break;
				}
				case InstitutionTypeEnum::Theatre: {
					Theatre^ theatre = dynamic_cast<Theatre^>(_selectedInstitution);
					checkBoxTheatreHasOrchestra->Checked = theatre->HasOrchestra;
					break;
				}
				case InstitutionTypeEnum::Wharf: {
					Wharf^ wharf = dynamic_cast<Wharf^>(_selectedInstitution);
					numericUpDownWharfNumberOfFloatingVehicles->Value = wharf->NumberOfFloatingVehicles;
					break;
				}
				default: {
					MessageBox::Show("Couldn't find institution type", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					this->Close();
					return;
				}
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
			airport->UpdateEntity(checkBoxAirportIsInternational->Checked);
			break;
		}
		case InstitutionTypeEnum::Hospital: {
			Hospital^ hospital = gcnew Hospital();
			baseInstitution = hospital;
			hospital->UpdateEntity(comboBoxHospitalType->Text);
			break;
		}
		case InstitutionTypeEnum::Library: {
			Library^ library = gcnew Library();
			baseInstitution = library;
			library->UpdateEntity(checkBoxLibraryIsUniversity->Checked);
			break;
		}
		case InstitutionTypeEnum::Lighthouse: {
			Lighthouse^ lighthouse = gcnew Lighthouse();
			baseInstitution = lighthouse;
			lighthouse->UpdateEntity(textBoxLighthouseColour->Text);
			break;
		}
		case InstitutionTypeEnum::Mall: {
			Mall^ mall = gcnew Mall();
			baseInstitution = mall;
			mall->UpdateEntity(
				checkBoxMallHasParking->Checked,
				checkBoxMallHasGrocery->Checked,
				checkBoxMallHasEntertainment->Checked
			);
			break;
		}
		case InstitutionTypeEnum::Museum: {
			Museum^ museum = gcnew Museum();
			baseInstitution = museum;
			museum->UpdateEntity(comboBoxMuseumType->Text);
			break;
		}
		case InstitutionTypeEnum::Restaurant: {
			Restaurant^ restaurant = gcnew Restaurant();
			baseInstitution = restaurant;
			restaurant->UpdateEntity(textBoxRestaurantCuisine->Text);
			break;
		}
		case InstitutionTypeEnum::School: {
			School^ school = gcnew School();
			baseInstitution = school;
			school->UpdateEntity((int)numericUpDownSchoolFaculties->Value);
			break;
		}
		case InstitutionTypeEnum::Theatre: {
			Theatre^ theatre = gcnew Theatre();
			baseInstitution = theatre;
			theatre->UpdateEntity(checkBoxTheatreHasOrchestra->Checked);
			break;
		}
		case InstitutionTypeEnum::Wharf: {
			Wharf^ wharf = gcnew Wharf();
			baseInstitution = wharf;
			wharf->UpdateEntity((int)numericUpDownWharfNumberOfFloatingVehicles->Value);
			break;
		}
		default: {
			MessageBox::Show("Couldn't add institution", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Close();
			return;
		}
		}

		List<Transport^>^ checkedTransports = gcnew List<Transport^>();
		for each (Object ^ transport in checkedListBoxTransport->CheckedItems) {
			checkedTransports->Add(dynamic_cast<Transport^>(transport));
		}
		baseInstitution->UpdateBase(
			textBoxName->Text,
			_institutionType,
			checkedTransports,
			comboBoxDistrict->Text,
			textBoxAddress->Text
		);

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
			airport->UpdateEntity(checkBoxAirportIsInternational->Checked);
			break;
		}
		case InstitutionTypeEnum::Hospital: {
			Hospital^ hospital = dynamic_cast<Hospital^>(_selectedInstitution);
			hospital->UpdateEntity(comboBoxHospitalType->Text);
			break;
		}
		case InstitutionTypeEnum::Library: {
			Library^ library = dynamic_cast<Library^>(_selectedInstitution);
			library->UpdateEntity(checkBoxLibraryIsUniversity->Checked);
			break;
		}
		case InstitutionTypeEnum::Lighthouse: {
			Lighthouse^ lighthouse = dynamic_cast<Lighthouse^>(_selectedInstitution);
			lighthouse->UpdateEntity(textBoxLighthouseColour->Text);
			break;
		}
		case InstitutionTypeEnum::Mall: {
			Mall^ mall = dynamic_cast<Mall^>(_selectedInstitution);
			mall->UpdateEntity(
				checkBoxMallHasParking->Checked,
				checkBoxMallHasGrocery->Checked,
				checkBoxMallHasEntertainment->Checked
			);
			break;
		}
		case InstitutionTypeEnum::Museum: {
			Museum^ museum = dynamic_cast<Museum^>(_selectedInstitution);
			museum->UpdateEntity(comboBoxMuseumType->Text);
			break;
		}
		case InstitutionTypeEnum::Restaurant: {
			Restaurant^ restaurant = dynamic_cast<Restaurant^>(_selectedInstitution);
			restaurant->UpdateEntity(textBoxRestaurantCuisine->Text);
			break;
		}
		case InstitutionTypeEnum::School: {
			School^ school = dynamic_cast<School^>(_selectedInstitution);
			school->UpdateEntity((int)numericUpDownSchoolFaculties->Value);
			break;
		}
		case InstitutionTypeEnum::Theatre: {
			Theatre^ theatre = dynamic_cast<Theatre^>(_selectedInstitution);
			theatre->UpdateEntity(checkBoxTheatreHasOrchestra->Checked);
			break;
		}
		case InstitutionTypeEnum::Wharf: {
			Wharf^ wharf = dynamic_cast<Wharf^>(_selectedInstitution);
			wharf->UpdateEntity((int)numericUpDownWharfNumberOfFloatingVehicles->Value);
			break;
		}
		default: {
			MessageBox::Show("Couldn't add institution", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Close();
			return;
		}
		}

		List<Transport^>^ checkedTransports = gcnew List<Transport^>();
		for each (Object ^ transport in checkedListBoxTransport->CheckedItems) {
			checkedTransports->Add(dynamic_cast<Transport^>(transport));
		}
		_selectedInstitution->UpdateBase(
			textBoxName->Text,
			_institutionType,
			checkedTransports,
			comboBoxDistrict->Text,
			textBoxAddress->Text
		);

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
