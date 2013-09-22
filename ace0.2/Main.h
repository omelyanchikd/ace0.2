#pragma once

#include "world.cpp"

#include "firm.cpp"
#include "household.cpp"

#include "labormarket.cpp"
#include "goodmarket.cpp"

#include "offer.cpp"
#include "data.cpp"


namespace ace02 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart ^chart;
	private: System::Windows::Forms::ComboBox^  comboBox;
	private: System::Windows::Forms::CheckBox^  checkBox;
	private: System::Windows::Forms::Label^  label;
	private: System::Windows::Forms::TextBox^  textBox1;



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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox = (gcnew System::Windows::Forms::CheckBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// chart
			// 
			chartArea1->Name = L"chartArea";
			this->chart->ChartAreas->Add(chartArea1);
			this->chart->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend1->Enabled = false;
			legend1->Name = L"legend";
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(0, 34);
			this->chart->Name = L"chart";
			series1->ChartArea = L"chartArea";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->IsVisibleInLegend = false;
			series1->Legend = L"legend";
			series1->Name = L"series";
			this->chart->Series->Add(series1);
			this->chart->Size = System::Drawing::Size(763, 297);
			this->chart->TabIndex = 0;
			this->chart->Text = L"Chart";
			// 
			// comboBox
			// 
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"Salary", L"Price", L"Money", L"Workers", L"Desired", 
				L"Sold", L"Stock", L"Profit"});
			this->comboBox->Location = System::Drawing::Point(12, 7);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(121, 21);
			this->comboBox->TabIndex = 0;
			// 
			// checkBox
			// 
			this->checkBox->AutoSize = true;
			this->checkBox->Location = System::Drawing::Point(177, 7);
			this->checkBox->Name = L"checkBox";
			this->checkBox->Size = System::Drawing::Size(67, 17);
			this->checkBox->TabIndex = 1;
			this->checkBox->Text = L"All firms\?";
			this->checkBox->UseVisualStyleBackColor = true;
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Location = System::Drawing::Point(285, 7);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(38, 13);
			this->label->TabIndex = 2;
			this->label->Text = L"Firm Id";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(338, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(44, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"1";
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(763, 331);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label);
			this->Controls->Add(this->checkBox);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->chart);
			this->Name = L"mainForm";
			this->Text = L"Main Form";
			this->Load += gcnew System::EventHandler(this, &mainForm::mainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void mainForm_Load(System::Object^  sender, System::EventArgs^  e) {
			world earth(2,10,10,10);
			for (int i = 0; i < 100; i++)
			{
				earth.step();
			}
			map<int,vector<double>> sold = earth._log.getfirmsold();
			for(int i = 0; i < sold[1].size(); i++)
			{
 				this->chart->Series["series"]->Points->AddY(sold[1][i]);
			}
			
		}
	};
}

