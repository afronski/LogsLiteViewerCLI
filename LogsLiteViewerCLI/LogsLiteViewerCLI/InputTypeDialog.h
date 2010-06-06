#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace LogsLiteViewerCLI 
{
	public ref class InputTypeDialog : public System::Windows::Forms::Form
	{
	public:
		InputTypeDialog(void)
		{
			InitializeComponent();
		}

	protected:
		~InputTypeDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnOK;
	public: System::Windows::Forms::ComboBox^  cbxType;
	protected: 

	protected: 


	private: System::Windows::Forms::LinkLabel^  linkCancel;


	private: System::Windows::Forms::Label^  lbType;



	private:
		System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(InputTypeDialog::typeid));
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->cbxType = (gcnew System::Windows::Forms::ComboBox());
			this->linkCancel = (gcnew System::Windows::Forms::LinkLabel());
			this->lbType = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(178, 39);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(76, 23);
			this->btnOK->TabIndex = 0;
			this->btnOK->Text = L"OK";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &InputTypeDialog::btnOK_Click);
			// 
			// cbxType
			// 
			this->cbxType->FormattingEnabled = true;
			this->cbxType->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"XML file", L"TXT file", L"UDP socket"});
			this->cbxType->Location = System::Drawing::Point(50, 12);
			this->cbxType->Name = L"cbxType";
			this->cbxType->Size = System::Drawing::Size(204, 21);
			this->cbxType->TabIndex = 1;
			// 
			// linkCancel
			// 
			this->linkCancel->AutoSize = true;
			this->linkCancel->Location = System::Drawing::Point(132, 44);
			this->linkCancel->Name = L"linkCancel";
			this->linkCancel->Size = System::Drawing::Size(40, 13);
			this->linkCancel->TabIndex = 3;
			this->linkCancel->TabStop = true;
			this->linkCancel->Text = L"Cancel";
			this->linkCancel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &InputTypeDialog::linkCancel_LinkClicked);
			// 
			// lbType
			// 
			this->lbType->AutoSize = true;
			this->lbType->Location = System::Drawing::Point(6, 15);
			this->lbType->Name = L"lbType";
			this->lbType->Size = System::Drawing::Size(34, 13);
			this->lbType->TabIndex = 5;
			this->lbType->Text = L"Type:";
			// 
			// InputTypeDialog
			// 
			this->AcceptButton = this->btnOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->linkCancel;
			this->ClientSize = System::Drawing::Size(266, 70);
			this->Controls->Add(this->lbType);
			this->Controls->Add(this->linkCancel);
			this->Controls->Add(this->cbxType);
			this->Controls->Add(this->btnOK);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"InputTypeDialog";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Select input type...";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
	private: 
		System::Void linkCancel_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
		{
			this->DialogResult = Windows::Forms::DialogResult::Cancel;
			Close();
		}
					
	private: 
		System::Void btnOK_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			// Simple validation.
			if (cbxType->SelectedIndex == -1)
			{
				MessageBox::Show("Please select an option!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}
		
			this->DialogResult = Windows::Forms::DialogResult::OK;
			Close();					
		}
	
	#pragma endregion	
};

}