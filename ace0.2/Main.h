#pragma once

#include "world.cpp"

#include "firms.cpp"
#include "households.cpp"

#include "firm.cpp"
#include "household.cpp"

#include "labormarket.cpp"
#include "goodmarket.cpp"

#include "offer.cpp"
#include "unconscious.cpp"

#include "data.cpp"
#include "macro.cpp"

world earth(2,200,10,10);

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

	private: System::Windows::Forms::ComboBox^  comboBox;
	private: System::Windows::Forms::CheckBox^  checkBox;
	private: System::Windows::Forms::Label^  label;
	private: System::Windows::Forms::TextBox^  textBox;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart;




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
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox = (gcnew System::Windows::Forms::CheckBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBox
			// 
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(9) {L"Salary", L"Price", L"Money", L"Workers", L"Desired", 
				L"Sold", L"Stock", L"Profit", L"Action"});
			this->comboBox->Location = System::Drawing::Point(12, 7);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(121, 21);
			this->comboBox->TabIndex = 0;
			this->comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &mainForm::comboBox_SelectedIndexChanged);
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
			// textBox
			// 
			this->textBox->Location = System::Drawing::Point(338, 5);
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(44, 20);
			this->textBox->TabIndex = 3;
			this->textBox->Text = L"1";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(9) {L"Average price", L"Average salary", L"Inflation", 
				L"Unemployment rate", L"Production", L"Consumption", L"GDP", L"Firm number", L"Household number"});
			this->comboBox1->Location = System::Drawing::Point(630, 3);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &mainForm::comboBox1_SelectedIndexChanged);
			// 
			// chart
			// 
			chartArea1->Name = L"chartArea";
			this->chart->ChartAreas->Add(chartArea1);
			this->chart->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->chart->Location = System::Drawing::Point(0, 34);
			this->chart->Name = L"chart";
			this->chart->Size = System::Drawing::Size(763, 297);
			this->chart->TabIndex = 0;
			this->chart->Text = L"Chart";
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(763, 331);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox);
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
			for (int i = 0; i < 100; i++)
			{
				earth.step();
			}
			
		}
	private: System::Void comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			this->chart->Series->Clear();
			map<int,vector<double>> request;
			switch (comboBox->SelectedIndex)
			{
				case 0: request = earth._log.getfirmsalary(); break;
				case 1: request = earth._log.getfirmprice(); break;
				case 2: request = earth._log.getfirmmoney(); break;
				case 3: request = earth._log.getfirmworkers(); break; 
				case 4: request = earth._log.getfirmdesired(); break;
				case 5: request = earth._log.getfirmsold(); break;
				case 6: request = earth._log.getfirmstock(); break;
				case 7: request = earth._log.getfirmprofit(); break;
				case 8: request = earth._log.getfirmaction(); break;
			}
			if (!checkBox->Checked)
			{
				this->chart->Series->Add("series");
				this->chart->Series["series"]->ChartType =  System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
//				this->chart->Series["series"]->ChartArea = chartArea1;
				for(int i = 0; i < request[int::Parse(textBox->Text)].size(); i++)
				{
					this->chart->Series["series"]->Points->AddY(request[int::Parse(textBox->Text)][i]);
				}
			}
			else
			{
				for (map<int, vector<double>>::iterator id = request.begin(); id != request.end(); ++id)
				{
					this->chart->Series->Add("series"+(id->first).ToString());
					if (comboBox->SelectedIndex != 8)
						this->chart->Series["series"+(id->first).ToString()]->ChartType =  System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
					else
						this->chart->Series["series"+(id->first).ToString()]->ChartType =  System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
//					this->chart->Series["series"]->ChartArea = chartArea1;
					for(int i = 0; i < (id->second).size(); i++)
					{
						this->chart->Series["series"+(id->first).ToString()]->Points->AddY((id->second)[i]);
					}
				}
			}
		}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			this->chart->Series->Clear();
			vector<double> stats;
			switch (comboBox1->SelectedIndex)
			{
				case 0: stats = earth._statistics.get_average_price(); break;
				case 1: stats = earth._statistics.get_average_salary(); break;
				case 2: stats = earth._statistics.get_inflation(); break;
				case 3: stats = earth._statistics.get_unemployment(); break; 
				case 4: stats = earth._statistics.get_production(); break;
				case 5: stats = earth._statistics.get_consumption(); break;
				case 6: stats = earth._statistics.get_gdp(); break;
				case 7: stats = earth._statistics.get_firm(); break;
				case 8: stats = earth._statistics.get_household(); break;
			}
			this->chart->Series->Add("series");
			this->chart->Series["series"]->ChartType =  System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
//				this->chart->Series["series"]->ChartArea = chartArea1;
			for(int i = 1; i < stats.size(); i++)
			{
				this->chart->Series["series"]->Points->AddY(stats[i]);
			}
		 }
};
}

