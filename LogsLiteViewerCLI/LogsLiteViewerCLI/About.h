#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace LogsLiteViewerCLI 
{
	public ref class About : public System::Windows::Forms::Form
	{
	public:
		About(void)
		{
			InitializeComponent();
		}

	protected:
		~About()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnAboutOk;
	protected: 
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private:
		System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(About::typeid));
			this->btnAboutOk = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnAboutOk
			// 
			this->btnAboutOk->Location = System::Drawing::Point(197, 135);
			this->btnAboutOk->Name = L"btnAboutOk";
			this->btnAboutOk->Size = System::Drawing::Size(75, 23);
			this->btnAboutOk->TabIndex = 0;
			this->btnAboutOk->Text = L"OK";
			this->btnAboutOk->UseVisualStyleBackColor = true;
			this->btnAboutOk->Click += gcnew System::EventHandler(this, &About::btnAboutOk_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(260, 115);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// About
			// 
			this->AcceptButton = this->btnAboutOk;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 170);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnAboutOk);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"About";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"About...";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}		
		
		private: 
			System::Void btnAboutOk_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				this->Close();
			}
			
		#pragma endregion			
	};
}