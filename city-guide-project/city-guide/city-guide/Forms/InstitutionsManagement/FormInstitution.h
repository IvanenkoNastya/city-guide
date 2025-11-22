#pragma once
#include "../../managers/InstitutionManager.h"
#include "FormInstitutionAddOrEdit.h"

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormInstitution
	/// </summary>
	public ref class FormInstitution : public System::Windows::Forms::Form
	{
	public:
		FormInstitution(void)
		{
			InitializeComponent();
			
			for each (InstitutionTypeEnum type in Enum::GetValues(InstitutionTypeEnum::typeid)) {
				if (type == InstitutionTypeEnum::Unknown) {
					continue;
				}
				System::Windows::Forms::ToolStripMenuItem^ someToolStripMenuItem;
				someToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());

				someToolStripMenuItem->Name = L"someToolStripMenuItem" + type.ToString();
				someToolStripMenuItem->Size = System::Drawing::Size(180, 22);
				someToolStripMenuItem->Text = L"" + type.ToString();
				someToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormInstitution::addInstitutionToolStripMenuItem_Click);
				someToolStripMenuItem->Tag = type;

				this->addInstitutionToolStripMenuItem->DropDownItems->Add(someToolStripMenuItem);
			}

			RefreshInstitutionListBox();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormInstitution()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ addInstitutionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editInstitutionToolStripMenuItem;
	protected:


	private: System::Windows::Forms::ToolStripMenuItem^ deleteInstitutionToolStripMenuItem;

	private: System::Windows::Forms::ListBox^ listBoxInstitutions;

	private: System::Windows::Forms::Button^ buttonCancel;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->addInstitutionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editInstitutionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteInstitutionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listBoxInstitutions = (gcnew System::Windows::Forms::ListBox());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addInstitutionToolStripMenuItem,
					this->editInstitutionToolStripMenuItem, this->deleteInstitutionToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(496, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// addInstitutionToolStripMenuItem
			// 
			this->addInstitutionToolStripMenuItem->Name = L"addInstitutionToolStripMenuItem";
			this->addInstitutionToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->addInstitutionToolStripMenuItem->Text = L"Add";
			// 
			// editInstitutionToolStripMenuItem
			// 
			this->editInstitutionToolStripMenuItem->Name = L"editInstitutionToolStripMenuItem";
			this->editInstitutionToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editInstitutionToolStripMenuItem->Text = L"Edit";
			this->editInstitutionToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormInstitution::editInstitutionToolStripMenuItem_Click);
			// 
			// deleteInstitutionToolStripMenuItem
			// 
			this->deleteInstitutionToolStripMenuItem->Name = L"deleteInstitutionToolStripMenuItem";
			this->deleteInstitutionToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->deleteInstitutionToolStripMenuItem->Text = L"Delete";
			this->deleteInstitutionToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormInstitution::deleteInstitutionToolStripMenuItem_Click);
			// 
			// listBoxInstitutions
			// 
			this->listBoxInstitutions->FormattingEnabled = true;
			this->listBoxInstitutions->Location = System::Drawing::Point(12, 55);
			this->listBoxInstitutions->Name = L"listBoxInstitutions";
			this->listBoxInstitutions->Size = System::Drawing::Size(472, 251);
			this->listBoxInstitutions->TabIndex = 1;
			this->listBoxInstitutions->SelectedIndexChanged += gcnew System::EventHandler(this, &FormInstitution::listBoxInstitution_SelectedIndexChanged);
			this->listBoxInstitutions->DoubleClick += gcnew System::EventHandler(this, &FormInstitution::editInstitutionToolStripMenuItem_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(409, 310);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 2;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &FormInstitution::buttonCancel_Click);
			// 
			// FormInstitution
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 345);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->listBoxInstitutions);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"FormInstitution";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Institution";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void RefreshInstitutionListBox() {
		listBoxInstitutions->Items->Clear();
		listBoxInstitutions->Items->AddRange(InstitutionManager::Instance->GetInstitutionList()->ToArray());
		editInstitutionToolStripMenuItem->Enabled = false;
		deleteInstitutionToolStripMenuItem->Enabled = false;
	}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}


	private: System::Void listBoxInstitution_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		editInstitutionToolStripMenuItem->Enabled = true;
		deleteInstitutionToolStripMenuItem->Enabled = true;
	}

	private: System::Void addInstitutionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		System::Windows::Forms::ToolStripMenuItem^ item = dynamic_cast<System::Windows::Forms::ToolStripMenuItem^>(sender);
		InstitutionTypeEnum type = (InstitutionTypeEnum)(item->Tag);

		FormInstitutionAddOrEdit^ form = gcnew FormInstitutionAddOrEdit(type);
		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			RefreshInstitutionListBox();
		}
	}

	private: System::Void editInstitutionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listBoxInstitutions->SelectedItem == nullptr) {
			return;
		}
		FormInstitutionAddOrEdit^ form = gcnew FormInstitutionAddOrEdit(dynamic_cast<Institution^>(listBoxInstitutions->SelectedItem));
		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			RefreshInstitutionListBox();
		}
	}

	private: System::Void deleteInstitutionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult answer = MessageBox::Show("Are you sure?", "Delete institution", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (answer == System::Windows::Forms::DialogResult::Yes) {
			Institution^ institutionToDelete = dynamic_cast<Institution^>(listBoxInstitutions->SelectedItem);
			if (!InstitutionManager::Instance->TryDeleteInstitution(institutionToDelete)) {
				MessageBox::Show("Couldn't delete institution", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			RefreshInstitutionListBox();
		}
	}
};
}
