#pragma once
#include "../../managers/DistrictManager.h"
#include "../../managers/InstitutionManager.h"

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;

	/// <summary>
	/// Summary for FormFindAddress
	/// </summary>
	public ref class FormFindAddress : public System::Windows::Forms::Form
	{
	public:
		FormFindAddress(void)
		{
			InitializeComponent();
			comboBoxDistrict->Items->Add(_allDistrictsString);
			comboBoxDistrict->Items->AddRange(DistrictManager::Instance->GetDistrictList()->ToArray());
		
			RefreshInstitutionListBox();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormFindAddress()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBoxInstitutions;
	protected:

	protected:
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::Button^ buttonSeeAddress;

	private: System::Windows::Forms::ComboBox^ comboBoxDistrict;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private:
		String^ _allDistrictsString = " - All - ";

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBoxInstitutions = (gcnew System::Windows::Forms::ListBox());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonSeeAddress = (gcnew System::Windows::Forms::Button());
			this->comboBoxDistrict = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// listBoxInstitutions
			// 
			this->listBoxInstitutions->FormattingEnabled = true;
			this->listBoxInstitutions->Location = System::Drawing::Point(12, 53);
			this->listBoxInstitutions->Name = L"listBoxInstitutions";
			this->listBoxInstitutions->Size = System::Drawing::Size(472, 251);
			this->listBoxInstitutions->TabIndex = 0;
			this->listBoxInstitutions->SelectedIndexChanged += gcnew System::EventHandler(this, &FormFindAddress::listBox1_SelectedIndexChanged);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(409, 310);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 1;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &FormFindAddress::buttonCancel_Click);
			// 
			// buttonSeeAddress
			// 
			this->buttonSeeAddress->Enabled = false;
			this->buttonSeeAddress->Location = System::Drawing::Point(409, 24);
			this->buttonSeeAddress->Name = L"buttonSeeAddress";
			this->buttonSeeAddress->Size = System::Drawing::Size(75, 23);
			this->buttonSeeAddress->TabIndex = 2;
			this->buttonSeeAddress->Text = L"See address";
			this->buttonSeeAddress->UseVisualStyleBackColor = true;
			this->buttonSeeAddress->Click += gcnew System::EventHandler(this, &FormFindAddress::buttonSeeAddress_Click);
			// 
			// comboBoxDistrict
			// 
			this->comboBoxDistrict->FormattingEnabled = true;
			this->comboBoxDistrict->Location = System::Drawing::Point(12, 24);
			this->comboBoxDistrict->Name = L"comboBoxDistrict";
			this->comboBoxDistrict->Size = System::Drawing::Size(180, 21);
			this->comboBoxDistrict->TabIndex = 14;
			this->comboBoxDistrict->SelectedIndexChanged += gcnew System::EventHandler(this, &FormFindAddress::comboBoxDistrict_SelectedIndexChanged);
			// 
			// FormFindAddress
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 345);
			this->Controls->Add(this->comboBoxDistrict);
			this->Controls->Add(this->buttonSeeAddress);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->listBoxInstitutions);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FormFindAddress";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Find Address of Institution";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void RefreshInstitutionListBox() {
		listBoxInstitutions->Items->Clear();
		buttonSeeAddress->Enabled = false;
		if (comboBoxDistrict->Text == _allDistrictsString) {
			listBoxInstitutions->Items->AddRange(
				InstitutionManager::Instance->GetInstitutionList()->ToArray()
			);
		} else if (comboBoxDistrict->Text != "") {
			listBoxInstitutions->Items->AddRange(
				InstitutionManager::Instance->GetInstitutionListByDistrict(comboBoxDistrict->Text)->ToArray()
			);
		}
	}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		buttonSeeAddress->Enabled = true;
	}

	private: System::Void comboBoxDistrict_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		RefreshInstitutionListBox();
	}

	private: System::Void buttonSeeAddress_Click(System::Object^ sender, System::EventArgs^ e) {
		Institution^ selectedInstitution = dynamic_cast<Institution^>(listBoxInstitutions->SelectedItem);

		if (selectedInstitution == nullptr) {
			System::Windows::Forms::DialogResult answer = MessageBox::Show(
				"No institution is chosen",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		String^ header = selectedInstitution->Name;
		StringBuilder^ sb = gcnew StringBuilder();
		sb->Append("Address of ");
		sb->Append(selectedInstitution->Name);
		sb->Append(" is:");
		sb->Append("\n");
		sb->Append(selectedInstitution->Address);

		String^ text = sb->ToString();

		System::Windows::Forms::DialogResult answer = MessageBox::Show(
			text,
			header,
			MessageBoxButtons::OK,
			MessageBoxIcon::Information
		);
		RefreshInstitutionListBox();
	}
};
}
