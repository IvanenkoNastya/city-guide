#pragma once
#include "../../managers/DistrictManager.h"
#include "FormDistrictAddOrEdit.h"

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormDistrict
	/// </summary>
	public ref class FormDistrict : public System::Windows::Forms::Form
	{
	public:
		FormDistrict(void)
		{
			InitializeComponent();

			RefreshDistrictListBox();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormDistrict()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBoxDistricts;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ addDistrictToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editDistrictToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteDistrictToolStripMenuItem;

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
			this->listBoxDistricts = (gcnew System::Windows::Forms::ListBox());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->addDistrictToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editDistrictToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteDistrictToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// listBoxDistricts
			// 
			this->listBoxDistricts->FormattingEnabled = true;
			this->listBoxDistricts->Location = System::Drawing::Point(12, 53);
			this->listBoxDistricts->MultiColumn = true;
			this->listBoxDistricts->Name = L"listBoxDistricts";
			this->listBoxDistricts->Size = System::Drawing::Size(472, 251);
			this->listBoxDistricts->TabIndex = 0;
			this->listBoxDistricts->SelectedIndexChanged += gcnew System::EventHandler(this, &FormDistrict::listBoxDistricts_SelectedIndexChanged);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(409, 310);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 1;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &FormDistrict::buttonCancel_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addDistrictToolStripMenuItem,
					this->editDistrictToolStripMenuItem, this->deleteDistrictToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(496, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// addDistrictToolStripMenuItem
			// 
			this->addDistrictToolStripMenuItem->Name = L"addDistrictToolStripMenuItem";
			this->addDistrictToolStripMenuItem->Size = System::Drawing::Size(106, 20);
			this->addDistrictToolStripMenuItem->Text = L"Add new District";
			this->addDistrictToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormDistrict::addDistrictToolStripMenuItem_Click);
			// 
			// editDistrictToolStripMenuItem
			// 
			this->editDistrictToolStripMenuItem->Enabled = false;
			this->editDistrictToolStripMenuItem->Name = L"editDistrictToolStripMenuItem";
			this->editDistrictToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->editDistrictToolStripMenuItem->Text = L"Edit District";
			this->editDistrictToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormDistrict::editDistrictToolStripMenuItem_Click);
			// 
			// deleteDistrictToolStripMenuItem
			// 
			this->deleteDistrictToolStripMenuItem->Enabled = false;
			this->deleteDistrictToolStripMenuItem->Name = L"deleteDistrictToolStripMenuItem";
			this->deleteDistrictToolStripMenuItem->Size = System::Drawing::Size(92, 20);
			this->deleteDistrictToolStripMenuItem->Text = L"Delete District";
			this->deleteDistrictToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormDistrict::deleteDistrictToolStripMenuItem_Click);
			// 
			// FormDistrict
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 345);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->listBoxDistricts);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"FormDistrict";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormDistrict";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void RefreshDistrictListBox() {
		listBoxDistricts->Items->Clear();
		listBoxDistricts->Items->AddRange(DistrictManager::Instance->GetDistrictList()->ToArray());
		editDistrictToolStripMenuItem->Enabled = false;
		deleteDistrictToolStripMenuItem->Enabled = false;
	}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void listBoxDistricts_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		editDistrictToolStripMenuItem->Enabled = true;
		deleteDistrictToolStripMenuItem->Enabled = true;
	}

	private: System::Void addDistrictToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		FormDistrictAddOrEdit^ form = gcnew FormDistrictAddOrEdit(nullptr);
		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			RefreshDistrictListBox();
		}
	}

	private: System::Void editDistrictToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		FormDistrictAddOrEdit^ form = gcnew FormDistrictAddOrEdit(dynamic_cast<String^>(listBoxDistricts->SelectedItem));
		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			RefreshDistrictListBox();
		}
	}
	private: System::Void deleteDistrictToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		// to do: check if this District is used in any institution (and do smth with it)
		System::Windows::Forms::DialogResult answer = MessageBox::Show("Are you sure?", "Delete District", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (answer == System::Windows::Forms::DialogResult::Yes) {
			String^ districtToDelete = dynamic_cast<String^>(listBoxDistricts->SelectedItem);
			if (!DistrictManager::Instance->TryDeleteDistrict(districtToDelete)) {
				MessageBox::Show("Couldn't delete District", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			RefreshDistrictListBox();
		}
	}
};
}
