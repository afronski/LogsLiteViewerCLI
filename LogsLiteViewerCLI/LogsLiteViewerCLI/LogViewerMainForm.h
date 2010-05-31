#pragma once

namespace LogsLiteViewerCLI 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Security::Permissions;
	
	using namespace LogViewer::Logic;

	public ref class LogViewerMainForm : public System::Windows::Forms::Form
	{
	public:
		LogViewerMainForm(void)
		{
			InitializeComponent();						
		}

	protected:		
		~LogViewerMainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TabControl^  MainTabs;
	private: System::Windows::Forms::TabPage^  SampleView;
	
	private: System::Windows::Forms::ToolStrip^  MainToolbar;

	private: System::Windows::Forms::MenuStrip^  MainMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripButton^  joinStripButton;
	private: System::Windows::Forms::ToolStripButton^  createChannelStripButton;

	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  joinToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  createChannelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  splitChannelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^  manageChannelsToolStripMenuItem;
	private: System::Windows::Forms::NotifyIcon^  NotifyIcon;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::FolderBrowserDialog^  FolderBrowserDialog;
	private: System::Windows::Forms::ListBox^  MainChangeSink;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


	#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LogViewerMainForm::typeid));
			this->MainTabs = (gcnew System::Windows::Forms::TabControl());
			this->SampleView = (gcnew System::Windows::Forms::TabPage());
			this->MainChangeSink = (gcnew System::Windows::Forms::ListBox());
			this->MainMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createChannelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->joinToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->splitChannelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->manageChannelsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->aboutToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MainToolbar = (gcnew System::Windows::Forms::ToolStrip());
			this->joinStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->createChannelStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->NotifyIcon = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->FolderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->MainTabs->SuspendLayout();
			this->SampleView->SuspendLayout();
			this->MainMenu->SuspendLayout();
			this->MainToolbar->SuspendLayout();
			this->SuspendLayout();
			// 
			// MainTabs
			// 
			this->MainTabs->Controls->Add(this->SampleView);
			this->MainTabs->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->MainTabs->Location = System::Drawing::Point(0, 52);
			this->MainTabs->Name = L"MainTabs";
			this->MainTabs->SelectedIndex = 0;
			this->MainTabs->Size = System::Drawing::Size(494, 520);
			this->MainTabs->TabIndex = 0;
			// 
			// SampleView
			// 
			this->SampleView->Controls->Add(this->MainChangeSink);
			this->SampleView->Location = System::Drawing::Point(4, 22);
			this->SampleView->Name = L"SampleView";
			this->SampleView->Padding = System::Windows::Forms::Padding(3);
			this->SampleView->Size = System::Drawing::Size(486, 494);
			this->SampleView->TabIndex = 0;
			this->SampleView->Text = L"Sample view";
			this->SampleView->UseVisualStyleBackColor = true;
			// 
			// MainChangeSink
			// 
			this->MainChangeSink->Dock = System::Windows::Forms::DockStyle::Fill;
			this->MainChangeSink->FormattingEnabled = true;
			this->MainChangeSink->Location = System::Drawing::Point(3, 3);
			this->MainChangeSink->Name = L"MainChangeSink";
			this->MainChangeSink->Size = System::Drawing::Size(480, 485);
			this->MainChangeSink->TabIndex = 0;
			// 
			// MainMenu
			// 
			this->MainMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->editToolStripMenuItem, this->helpToolStripMenuItem});
			this->MainMenu->Location = System::Drawing::Point(0, 0);
			this->MainMenu->Name = L"MainMenu";
			this->MainMenu->Size = System::Drawing::Size(494, 24);
			this->MainMenu->TabIndex = 1;
			this->MainMenu->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->createChannelToolStripMenuItem, 
				this->toolStripMenuItem3, this->joinToolStripMenuItem, this->toolStripMenuItem2, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// createChannelToolStripMenuItem
			// 
			this->createChannelToolStripMenuItem->Name = L"createChannelToolStripMenuItem";
			this->createChannelToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->createChannelToolStripMenuItem->Text = L"&Create channel";
			this->createChannelToolStripMenuItem->Click += gcnew System::EventHandler(this, &LogViewerMainForm::createChannelToolStripMenuItem_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(150, 6);
			// 
			// joinToolStripMenuItem
			// 
			this->joinToolStripMenuItem->Name = L"joinToolStripMenuItem";
			this->joinToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->joinToolStripMenuItem->Text = L"&Join input";
			this->joinToolStripMenuItem->Click += gcnew System::EventHandler(this, &LogViewerMainForm::joinToolStripMenuItem_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(150, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->exitToolStripMenuItem->Text = L"&Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &LogViewerMainForm::exitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->splitChannelToolStripMenuItem, 
				this->aToolStripMenuItem, this->toolStripMenuItem4, this->manageChannelsToolStripMenuItem});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"&Edit";
			// 
			// splitChannelToolStripMenuItem
			// 
			this->splitChannelToolStripMenuItem->Name = L"splitChannelToolStripMenuItem";
			this->splitChannelToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->splitChannelToolStripMenuItem->Text = L"&Split channel";
			// 
			// aToolStripMenuItem
			// 
			this->aToolStripMenuItem->Name = L"aToolStripMenuItem";
			this->aToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->aToolStripMenuItem->Text = L" &Tie channels";
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(173, 6);
			// 
			// manageChannelsToolStripMenuItem
			// 
			this->manageChannelsToolStripMenuItem->Name = L"manageChannelsToolStripMenuItem";
			this->manageChannelsToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->manageChannelsToolStripMenuItem->Text = L"&Manage channels...";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->aboutToolStripMenuItem, 
				this->toolStripMenuItem1, this->aboutToolStripMenuItem1});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"&Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"&Index";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(104, 6);
			// 
			// aboutToolStripMenuItem1
			// 
			this->aboutToolStripMenuItem1->Name = L"aboutToolStripMenuItem1";
			this->aboutToolStripMenuItem1->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem1->Text = L"&About";
			// 
			// MainToolbar
			// 
			this->MainToolbar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->joinStripButton, 
				this->toolStripSeparator1, this->createChannelStripButton});
			this->MainToolbar->Location = System::Drawing::Point(0, 24);
			this->MainToolbar->Name = L"MainToolbar";
			this->MainToolbar->Size = System::Drawing::Size(494, 25);
			this->MainToolbar->TabIndex = 2;
			this->MainToolbar->Text = L"toolStrip1";
			// 
			// joinStripButton
			// 
			this->joinStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->joinStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"joinStripButton.Image")));
			this->joinStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->joinStripButton->Name = L"joinStripButton";
			this->joinStripButton->Size = System::Drawing::Size(23, 22);
			this->joinStripButton->Text = L"Join inputs...";
			this->joinStripButton->ToolTipText = L"Join inputs into one channel...";
			this->joinStripButton->Click += gcnew System::EventHandler(this, &LogViewerMainForm::joinStripButton_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// createChannelStripButton
			// 
			this->createChannelStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->createChannelStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"createChannelStripButton.Image")));
			this->createChannelStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->createChannelStripButton->Name = L"createChannelStripButton";
			this->createChannelStripButton->Size = System::Drawing::Size(23, 22);
			this->createChannelStripButton->Text = L"Create channel";
			this->createChannelStripButton->ToolTipText = L"Click here to create channel...";
			this->createChannelStripButton->Click += gcnew System::EventHandler(this, &LogViewerMainForm::createChannelStripButton_Click);
			// 
			// NotifyIcon
			// 
			this->NotifyIcon->Visible = true;
			// 
			// LogViewerMainForm
			// 
			this->AccessibleName = L"";
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(494, 572);
			this->Controls->Add(this->MainToolbar);
			this->Controls->Add(this->MainTabs);
			this->Controls->Add(this->MainMenu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->MainMenu;
			this->MaximizeBox = false;
			this->MinimumSize = System::Drawing::Size(500, 600);
			this->Name = L"LogViewerMainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"LogLiteViewer.CLI";
			this->Load += gcnew System::EventHandler(this, &LogViewerMainForm::LogViewerMainForm_Load);
			this->MainTabs->ResumeLayout(false);
			this->SampleView->ResumeLayout(false);
			this->MainMenu->ResumeLayout(false);
			this->MainMenu->PerformLayout();
			this->MainToolbar->ResumeLayout(false);
			this->MainToolbar->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion

	#pragma region Application logic - Main Window 

	private:		
		ChannelManager^ channelsManager;

	private: 
		System::Void LogViewerMainForm_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			channelsManager = gcnew ChannelManager();								
			channelsManager->appendChannel(gcnew Channel(MainTabs->TabPages[0]->Name));			
		}
		
	private:   
		System::Void CreateChannelLogic()
		{
			// Create new name.
			String^ newName = "New Channel " + channelsManager->channelCount().ToString();
							
			// Create new page.									
			TabPage^ newPage = gcnew TabPage(newName);
			newPage->Name = "NewChannelTab" + channelsManager->channelCount().ToString();
			MainTabs->TabPages->Add(newPage);	
			
			// Create new ListBox to out page.
			ListBox^ temp = gcnew ListBox();
			temp->Dock = DockStyle::Fill;
			temp->Name = "NewChannelListBox" + channelsManager->channelCount().ToString();
			
			// Adding channel and page to the page control.
			MainTabs->TabPages[newPage->Name]->Controls->Add(temp);			
			channelsManager->appendChannel(gcnew Channel(newName));
		}
	
		System::Void createChannelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{			
			CreateChannelLogic();
		}
		
	private: 		
		System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			Close();	
		}			
	
	public:
		delegate void DelegateAddItemToListBox(ListBox^ lb, String^ item);
		
		void AddItemToListBox(ListBox^ lb, String^ item)
		{
			lb->Items->Add(item);
		}
	
	private:			 
		System::Void FileSystemWatcher_Changed(System::Object^  sender, System::IO::FileSystemEventArgs^  e) 
		{			
			System::String^ str = "";
			switch(e->ChangeType)
			{				
				case System::IO::WatcherChangeTypes::Changed:
					str = "Changed";
					break;
					
				default:
					str = "Unrecognized";
					break;					
			}
			
			MainChangeSink->Invoke(gcnew DelegateAddItemToListBox(this, &LogViewerMainForm::AddItemToListBox), MainChangeSink, e->Name + ": " + str);
		}		 			
		
	private:
		System::Void JoinLogic()
		{
			if (FolderBrowserDialog->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
			{
				channelsManager[MainTabs->TabIndex]->appendInput(gcnew Inputs::FileInput(FolderBrowserDialog->SelectedPath, 
																 InputWatcher::FileType::FileType_Txt, 
																 gcnew System::IO::FileSystemEventHandler(this, &LogViewerMainForm::FileSystemWatcher_Changed)));
			}
		}			
		
	private: 
		System::Void joinToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			JoinLogic();
		}
						
	private: 
		System::Void joinStripButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			JoinLogic();
		}
							
	private: 
		System::Void createChannelStripButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			CreateChannelLogic();
		}
			 
	#pragma endregion		 		 
};
}