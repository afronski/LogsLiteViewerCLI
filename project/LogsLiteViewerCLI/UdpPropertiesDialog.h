#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace LogsLiteViewerCLI 
{
	public ref class UdpPropertiesDialog : public System::Windows::Forms::Form
	{
	public:
		UdpPropertiesDialog(void)
		{
			InitializeComponent();
		}

	protected:
		~UdpPropertiesDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnOK;
	protected: 

	private: System::Windows::Forms::LinkLabel^  linkCancel;
	public: System::Windows::Forms::TextBox^  tbAddress;
	private: 

	private: 

	protected: 



	private: System::Windows::Forms::Label^  lbAddress;
	private: System::Windows::Forms::Label^  lbPort;
	public: System::Windows::Forms::NumericUpDown^  nmPort;
	private: 



	private:
		System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UdpPropertiesDialog::typeid));
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->linkCancel = (gcnew System::Windows::Forms::LinkLabel());
			this->tbAddress = (gcnew System::Windows::Forms::TextBox());
			this->lbAddress = (gcnew System::Windows::Forms::Label());
			this->lbPort = (gcnew System::Windows::Forms::Label());
			this->nmPort = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmPort))->BeginInit();
			this->SuspendLayout();
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(216, 64);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(75, 23);
			this->btnOK->TabIndex = 0;
			this->btnOK->Text = L"OK";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &UdpPropertiesDialog::btnOK_Click);
			// 
			// linkCancel
			// 
			this->linkCancel->AutoSize = true;
			this->linkCancel->Location = System::Drawing::Point(155, 69);
			this->linkCancel->Name = L"linkCancel";
			this->linkCancel->Size = System::Drawing::Size(40, 13);
			this->linkCancel->TabIndex = 1;
			this->linkCancel->TabStop = true;
			this->linkCancel->Text = L"Cancel";
			this->linkCancel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &UdpPropertiesDialog::linkCancel_LinkClicked);
			// 
			// tbAddress
			// 
			this->tbAddress->Location = System::Drawing::Point(72, 12);
			this->tbAddress->Name = L"tbAddress";
			this->tbAddress->Size = System::Drawing::Size(219, 20);
			this->tbAddress->TabIndex = 2;
			// 
			// lbAddress
			// 
			this->lbAddress->AutoSize = true;
			this->lbAddress->Location = System::Drawing::Point(12, 15);
			this->lbAddress->Name = L"lbAddress";
			this->lbAddress->Size = System::Drawing::Size(48, 13);
			this->lbAddress->TabIndex = 4;
			this->lbAddress->Text = L"Address:";
			// 
			// lbPort
			// 
			this->lbPort->AutoSize = true;
			this->lbPort->Location = System::Drawing::Point(12, 41);
			this->lbPort->Name = L"lbPort";
			this->lbPort->Size = System::Drawing::Size(29, 13);
			this->lbPort->TabIndex = 5;
			this->lbPort->Text = L"Port:";
			// 
			// nmPort
			// 
			this->nmPort->Location = System::Drawing::Point(158, 39);
			this->nmPort->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {65536, 0, 0, 0});
			this->nmPort->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->nmPort->Name = L"nmPort";
			this->nmPort->Size = System::Drawing::Size(133, 20);
			this->nmPort->TabIndex = 6;
			this->nmPort->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nmPort->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2424, 0, 0, 0});
			// 
			// UdpPropertiesDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(303, 94);
			this->Controls->Add(this->nmPort);
			this->Controls->Add(this->lbPort);
			this->Controls->Add(this->lbAddress);
			this->Controls->Add(this->tbAddress);
			this->Controls->Add(this->linkCancel);
			this->Controls->Add(this->btnOK);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"UdpPropertiesDialog";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UDP properties...";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmPort))->EndInit();
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
			if (tbAddress->Text == "")
			{
				MessageBox::Show("Please write an address!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}
		
			this->DialogResult = Windows::Forms::DialogResult::OK;
			Close();
		}
		
	#pragma endregion				
};

}