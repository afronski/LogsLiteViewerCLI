#pragma once

#include "stdafx.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace LogViewer::Logic;

namespace LogsLiteViewerCLI 
{
	public ref class ManageChannelsDialog : public System::Windows::Forms::Form
	{
	public:
		ManageChannelsDialog(void)
		{
			InitializeComponent();
			_channels = nullptr;
		}

	protected:
		~ManageChannelsDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnOk;
	private: System::Windows::Forms::ListBox^  listChannels;
	private: System::Windows::Forms::TextBox^  tbName;

	private: System::Windows::Forms::Button^  btnRename;
	private: System::Windows::Forms::Button^  btnDelete;


	private: System::Windows::Forms::Label^  lbName;	
	private: System::Windows::Forms::ListBox^  listInputs;


	private:
		System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ManageChannelsDialog::typeid));
			this->btnOk = (gcnew System::Windows::Forms::Button());
			this->listChannels = (gcnew System::Windows::Forms::ListBox());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->btnRename = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->lbName = (gcnew System::Windows::Forms::Label());
			this->listInputs = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// btnOk
			// 
			this->btnOk->Location = System::Drawing::Point(374, 193);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(88, 23);
			this->btnOk->TabIndex = 0;
			this->btnOk->Text = L"OK";
			this->btnOk->UseVisualStyleBackColor = true;
			this->btnOk->Click += gcnew System::EventHandler(this, &ManageChannelsDialog::btnOk_Click);
			// 
			// listChannels
			// 
			this->listChannels->FormattingEnabled = true;
			this->listChannels->Location = System::Drawing::Point(12, 12);
			this->listChannels->Name = L"listChannels";
			this->listChannels->Size = System::Drawing::Size(165, 173);
			this->listChannels->TabIndex = 1;
			this->listChannels->SelectedIndexChanged += gcnew System::EventHandler(this, &ManageChannelsDialog::listChannels_SelectedIndexChanged);
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(227, 12);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(235, 20);
			this->tbName->TabIndex = 2;
			// 
			// btnRename
			// 
			this->btnRename->Location = System::Drawing::Point(227, 38);
			this->btnRename->Name = L"btnRename";
			this->btnRename->Size = System::Drawing::Size(84, 23);
			this->btnRename->TabIndex = 3;
			this->btnRename->Text = L"Rename";
			this->btnRename->UseVisualStyleBackColor = true;
			this->btnRename->Click += gcnew System::EventHandler(this, &ManageChannelsDialog::btnRename_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(374, 38);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(88, 23);
			this->btnDelete->TabIndex = 4;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &ManageChannelsDialog::btnDelete_Click);
			// 
			// lbName
			// 
			this->lbName->AutoSize = true;
			this->lbName->Location = System::Drawing::Point(183, 15);
			this->lbName->Name = L"lbName";
			this->lbName->Size = System::Drawing::Size(38, 13);
			this->lbName->TabIndex = 5;
			this->lbName->Text = L"Name:";
			// 
			// listInputs
			// 
			this->listInputs->FormattingEnabled = true;
			this->listInputs->Location = System::Drawing::Point(183, 64);
			this->listInputs->Name = L"listInputs";
			this->listInputs->Size = System::Drawing::Size(279, 121);
			this->listInputs->TabIndex = 6;
			// 
			// ManageChannelsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(474, 228);
			this->Controls->Add(this->listInputs);
			this->Controls->Add(this->lbName);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnRename);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->listChannels);
			this->Controls->Add(this->btnOk);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"ManageChannelsDialog";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Manage channels...";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &ManageChannelsDialog::ManageChannelsDialog_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	public:
		delegate System::Void EraseTabDelegateType(int idx, System::String^ name);
	
	public:
		event EraseTabDelegateType^ EraseTabEvent;
		
	private:
		void LoadChannels()
		{
			if (_channels)
			{
				listChannels->Items->Clear();
				for(unsigned int i = 0; i < _channels->channelCount(); ++i)			
				{
					listChannels->Items->Add(_channels[i]->Name());
				}
			}
		}
		
	private:
		ChannelManager^ _channels;
		
	public:			
		ChannelManager^% channelsManagerRef()	
		{ 
			return _channels; 
		}

	private: 
		System::Void btnOk_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			this->DialogResult = Windows::Forms::DialogResult::OK;
			Close();
		}
		
	private: 
		System::Void ManageChannelsDialog_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			LoadChannels();
		}
		
	private: 
		System::Void listChannels_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			if (listChannels->SelectedIndex != -1 && listChannels->SelectedIndex < static_cast<int>(_channels->channelCount()))
			{
				tbName->Text = _channels[listChannels->SelectedIndex]->Name();
				
				listInputs->Items->Clear();
				for(unsigned int i = 0; i < _channels[listChannels->SelectedIndex]->inputsCount(); ++i)
				{
					listInputs->Items->Add(_channels[listChannels->SelectedIndex][i]->Name());
				}
			}
		}
								
	private: 
		System::Void btnRename_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (listChannels->SelectedIndex != -1 && listChannels->SelectedIndex < static_cast<int>(_channels->channelCount()))
			{
				if (tbName->Text == "")
				{
					MessageBox::Show("Please write a name!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;					
				}
				
				_channels[listChannels->SelectedIndex]->Name() = tbName->Text;
			}
			
			LoadChannels();
		}
		
	private: 
		System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (listChannels->SelectedIndex != -1 && listChannels->SelectedIndex < static_cast<int>(_channels->channelCount()))
			{
				EraseTabEvent(listChannels->SelectedIndex, _channels[listChannels->SelectedIndex]->Name());
			}		
			
			LoadChannels();
		}		
	
	#pragma endregion
};	
}