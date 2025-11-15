#pragma once
#include "../../managers/TransportManager.h"
#include "FormTransportAddOrEdit.h"

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormTransport
	/// </summary>
	public ref class FormTransport : public System::Windows::Forms::Form
	{
	public:
		FormTransport(void)
		{
			InitializeComponent();

			RefreshTransportListBox();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormTransport()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBoxTransports;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ addTransportToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editTransportToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteTransportToolStripMenuItem;

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
			this->listBoxTransports = (gcnew System::Windows::Forms::ListBox());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->addTransportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editTransportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteTransportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// listBoxTransports
			// 
			this->listBoxTransports->FormattingEnabled = true;
			this->listBoxTransports->Location = System::Drawing::Point(12, 52);
			this->listBoxTransports->MultiColumn = true;
			this->listBoxTransports->Name = L"listBoxTransports";
			this->listBoxTransports->Size = System::Drawing::Size(472, 251);
			this->listBoxTransports->TabIndex = 0;
			this->listBoxTransports->SelectedIndexChanged += gcnew System::EventHandler(this, &FormTransport::listBoxTransports_SelectedIndexChanged);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(409, 310);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 1;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &FormTransport::buttonCancel_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addTransportToolStripMenuItem,
					this->editTransportToolStripMenuItem, this->deleteTransportToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(496, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// addTransportToolStripMenuItem
			// 
			this->addTransportToolStripMenuItem->Name = L"addTransportToolStripMenuItem";
			this->addTransportToolStripMenuItem->Size = System::Drawing::Size(117, 20);
			this->addTransportToolStripMenuItem->Text = L"Add new transport";
			this->addTransportToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormTransport::addTransportToolStripMenuItem_Click);
			// 
			// editTransportToolStripMenuItem
			// 
			this->editTransportToolStripMenuItem->Enabled = false;
			this->editTransportToolStripMenuItem->Name = L"editTransportToolStripMenuItem";
			this->editTransportToolStripMenuItem->Size = System::Drawing::Size(90, 20);
			this->editTransportToolStripMenuItem->Text = L"Edit transport";
			this->editTransportToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormTransport::editTransportToolStripMenuItem_Click);
			// 
			// deleteTransportToolStripMenuItem
			// 
			this->deleteTransportToolStripMenuItem->Enabled = false;
			this->deleteTransportToolStripMenuItem->Name = L"deleteTransportToolStripMenuItem";
			this->deleteTransportToolStripMenuItem->Size = System::Drawing::Size(103, 20);
			this->deleteTransportToolStripMenuItem->Text = L"Delete transport";
			this->deleteTransportToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormTransport::deleteTransportToolStripMenuItem_Click);
			// 
			// FormTransport
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 345);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->listBoxTransports);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"FormTransport";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormTransport";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void RefreshTransportListBox() {
		listBoxTransports->Items->Clear();
		listBoxTransports->Items->AddRange(TransportManager::Instance->GetTransportList()->ToArray());
		editTransportToolStripMenuItem->Enabled = false;
		deleteTransportToolStripMenuItem->Enabled = false;
	}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void listBoxTransports_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		editTransportToolStripMenuItem->Enabled = true;
		deleteTransportToolStripMenuItem->Enabled = true;
	}

	private: System::Void addTransportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		FormTransportAddOrEdit^ form = gcnew FormTransportAddOrEdit(nullptr);
		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			RefreshTransportListBox();
		}
	}

	private: System::Void editTransportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		FormTransportAddOrEdit^ form = gcnew FormTransportAddOrEdit(dynamic_cast<Transport^>(listBoxTransports->SelectedItem));
		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			RefreshTransportListBox();
		}
	}
	private: System::Void deleteTransportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		// to do: check if this transport is used in any institution (and do smth with it)
		System::Windows::Forms::DialogResult answer = MessageBox::Show("Are you sure?", "Delete transport", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (answer == System::Windows::Forms::DialogResult::Yes) {
			Transport^ transportToDelete = dynamic_cast<Transport^>(listBoxTransports->SelectedItem);
			if (!TransportManager::Instance->TryDeleteTransport(transportToDelete)) {
				MessageBox::Show("Couldn't delete transport", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			RefreshTransportListBox();
		}
	}
};
}
