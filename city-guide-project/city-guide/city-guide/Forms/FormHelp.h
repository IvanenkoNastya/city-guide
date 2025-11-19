#pragma once

namespace cityguide {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;

	/// <summary>
	/// Summary for FormHelp
	/// </summary>
	public ref class FormHelp : public System::Windows::Forms::Form
	{
	public:
		FormHelp(void)
		{
			InitializeComponent();

			LoadHelpDaraFromFile();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormHelp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBoxHelp;
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
			this->richTextBoxHelp = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBoxHelp
			// 
			this->richTextBoxHelp->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->richTextBoxHelp->Location = System::Drawing::Point(12, 12);
			this->richTextBoxHelp->Name = L"richTextBoxHelp";
			this->richTextBoxHelp->ReadOnly = true;
			this->richTextBoxHelp->Size = System::Drawing::Size(472, 321);
			this->richTextBoxHelp->TabIndex = 0;
			this->richTextBoxHelp->Text = L"Help\n\nThis is user guide.";
			// 
			// FormHelp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 345);
			this->Controls->Add(this->richTextBoxHelp);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FormHelp";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Help";
			this->ResumeLayout(false);

		}
#pragma endregion
		static String^ fileName = "helpData.txt";

		void LoadHelpDaraFromFile() {
			try {
				StreamReader^ sr = File::OpenText(fileName);
				richTextBoxHelp->Text = sr->ReadToEnd();
				sr->Close();
			} catch (Exception^ e) {
				if (dynamic_cast<FileNotFoundException^>(e)) {
					Console::WriteLine("file '{0}' not found", fileName);
				} else {
					Console::WriteLine("problem reading file '{0}'", fileName);
				}
			}
		}


	};
}
