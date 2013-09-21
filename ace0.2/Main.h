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
	private: System::Windows::Forms::ListBox^  listBox;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->listBox = (gcnew System::Windows::Forms::ListBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// chart
			// 
			chartArea3->Name = L"chartArea";
			this->chart->ChartAreas->Add(chartArea3);
			this->chart->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend3->Enabled = false;
			legend3->Name = L"legend";
			this->chart->Legends->Add(legend3);
			this->chart->Location = System::Drawing::Point(0, 34);
			this->chart->Name = L"chart";
			series3->ChartArea = L"chartArea";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->IsVisibleInLegend = false;
			series3->Legend = L"legend";
			series3->Name = L"series";
			this->chart->Series->Add(series3);
			this->chart->Size = System::Drawing::Size(763, 297);
			this->chart->TabIndex = 0;
			this->chart->Text = L"Chart";
			// 
			// listBox
			// 
			this->listBox->AllowDrop = true;
			this->listBox->FormattingEnabled = true;
			this->listBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"Salary", L"Price", L"Sold", L"Stock", L"Money", 
				L"Workers", L"Desired", L"Profit"});
			this->listBox->Location = System::Drawing::Point(36, 2);
			this->listBox->Name = L"listBox";
			this->listBox->Size = System::Drawing::Size(159, 17);
			this->listBox->TabIndex = 1;
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(763, 331);
			this->Controls->Add(this->listBox);
			this->Controls->Add(this->chart);
			this->Name = L"mainForm";
			this->Text = L"Main Form";
			this->Load += gcnew System::EventHandler(this, &mainForm::mainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart))->EndInit();
			this->ResumeLayout(false);

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

