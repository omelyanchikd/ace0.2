#pragma once

#include "world.cpp"

#include "firms.cpp"
#include "households.cpp"

#include "firm.cpp"
#include "household.cpp"

#include "labormarket.cpp"
#include "goodmarket.cpp"

#include "offer.cpp"

#include "matrix.cpp"

#include "scenario.cpp"

#include "unconscious.cpp"
#include "qlearning.cpp"
#include "rls.cpp"

#include "data.cpp"
#include "macro.cpp"


world earth(2,50,0,0,scenario(nonconscious, value, salary_price_desired, forecast), "model");

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
	private: System::Windows::Forms::CheckBox^  checkSalaryY;
	private: System::Windows::Forms::CheckBox^  checkPriceY;
	private: System::Windows::Forms::CheckBox^  checkMoneyY;
	private: System::Windows::Forms::CheckBox^  checkWorkersY;
	private: System::Windows::Forms::CheckBox^  checkProfitY;
	private: System::Windows::Forms::CheckBox^  checkStockY;
	private: System::Windows::Forms::CheckBox^  checkSoldY;
	private: System::Windows::Forms::CheckBox^  checkDesiredY;
	private: System::Windows::Forms::CheckBox^  checkProfitX;
	private: System::Windows::Forms::CheckBox^  checkStockX;
	private: System::Windows::Forms::CheckBox^  checkSoldX;
	private: System::Windows::Forms::CheckBox^  checkDesiredX;
	private: System::Windows::Forms::CheckBox^  checkWorkersX;
	private: System::Windows::Forms::CheckBox^  checkMoneyX;
	private: System::Windows::Forms::CheckBox^  checkPriceX;
	private: System::Windows::Forms::CheckBox^  checkSalaryX;
	private: System::Windows::Forms::Button^  button1;




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
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox = (gcnew System::Windows::Forms::CheckBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->checkSalaryY = (gcnew System::Windows::Forms::CheckBox());
			this->checkPriceY = (gcnew System::Windows::Forms::CheckBox());
			this->checkMoneyY = (gcnew System::Windows::Forms::CheckBox());
			this->checkWorkersY = (gcnew System::Windows::Forms::CheckBox());
			this->checkProfitY = (gcnew System::Windows::Forms::CheckBox());
			this->checkStockY = (gcnew System::Windows::Forms::CheckBox());
			this->checkSoldY = (gcnew System::Windows::Forms::CheckBox());
			this->checkDesiredY = (gcnew System::Windows::Forms::CheckBox());
			this->checkProfitX = (gcnew System::Windows::Forms::CheckBox());
			this->checkStockX = (gcnew System::Windows::Forms::CheckBox());
			this->checkSoldX = (gcnew System::Windows::Forms::CheckBox());
			this->checkDesiredX = (gcnew System::Windows::Forms::CheckBox());
			this->checkWorkersX = (gcnew System::Windows::Forms::CheckBox());
			this->checkMoneyX = (gcnew System::Windows::Forms::CheckBox());
			this->checkPriceX = (gcnew System::Windows::Forms::CheckBox());
			this->checkSalaryX = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			this->comboBox1->Location = System::Drawing::Point(883, 5);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &mainForm::comboBox1_SelectedIndexChanged);
			// 
			// chart
			// 
			chartArea3->Name = L"chartArea";
			this->chart->ChartAreas->Add(chartArea3);
			this->chart->Location = System::Drawing::Point(137, 101);
			this->chart->Name = L"chart";
			this->chart->Size = System::Drawing::Size(878, 437);
			this->chart->TabIndex = 0;
			this->chart->Text = L"Chart";
			// 
			// checkSalaryY
			// 
			this->checkSalaryY->AutoSize = true;
			this->checkSalaryY->Location = System::Drawing::Point(12, 101);
			this->checkSalaryY->Name = L"checkSalaryY";
			this->checkSalaryY->Size = System::Drawing::Size(53, 17);
			this->checkSalaryY->TabIndex = 5;
			this->checkSalaryY->Text = L"salary";
			this->checkSalaryY->UseVisualStyleBackColor = true;
			// 
			// checkPriceY
			// 
			this->checkPriceY->AutoSize = true;
			this->checkPriceY->Location = System::Drawing::Point(12, 125);
			this->checkPriceY->Name = L"checkPriceY";
			this->checkPriceY->Size = System::Drawing::Size(49, 17);
			this->checkPriceY->TabIndex = 6;
			this->checkPriceY->Text = L"price";
			this->checkPriceY->UseVisualStyleBackColor = true;
			// 
			// checkMoneyY
			// 
			this->checkMoneyY->AutoSize = true;
			this->checkMoneyY->Location = System::Drawing::Point(12, 149);
			this->checkMoneyY->Name = L"checkMoneyY";
			this->checkMoneyY->Size = System::Drawing::Size(57, 17);
			this->checkMoneyY->TabIndex = 7;
			this->checkMoneyY->Text = L"money";
			this->checkMoneyY->UseVisualStyleBackColor = true;
			// 
			// checkWorkersY
			// 
			this->checkWorkersY->AutoSize = true;
			this->checkWorkersY->Location = System::Drawing::Point(12, 173);
			this->checkWorkersY->Name = L"checkWorkersY";
			this->checkWorkersY->Size = System::Drawing::Size(63, 17);
			this->checkWorkersY->TabIndex = 8;
			this->checkWorkersY->Text = L"workers";
			this->checkWorkersY->UseVisualStyleBackColor = true;
			// 
			// checkProfitY
			// 
			this->checkProfitY->AutoSize = true;
			this->checkProfitY->Location = System::Drawing::Point(12, 268);
			this->checkProfitY->Name = L"checkProfitY";
			this->checkProfitY->Size = System::Drawing::Size(49, 17);
			this->checkProfitY->TabIndex = 12;
			this->checkProfitY->Text = L"profit";
			this->checkProfitY->UseVisualStyleBackColor = true;
			// 
			// checkStockY
			// 
			this->checkStockY->AutoSize = true;
			this->checkStockY->Location = System::Drawing::Point(12, 244);
			this->checkStockY->Name = L"checkStockY";
			this->checkStockY->Size = System::Drawing::Size(52, 17);
			this->checkStockY->TabIndex = 11;
			this->checkStockY->Text = L"stock";
			this->checkStockY->UseVisualStyleBackColor = true;
			// 
			// checkSoldY
			// 
			this->checkSoldY->AutoSize = true;
			this->checkSoldY->Location = System::Drawing::Point(12, 220);
			this->checkSoldY->Name = L"checkSoldY";
			this->checkSoldY->Size = System::Drawing::Size(45, 17);
			this->checkSoldY->TabIndex = 10;
			this->checkSoldY->Text = L"sold";
			this->checkSoldY->UseVisualStyleBackColor = true;
			// 
			// checkDesiredY
			// 
			this->checkDesiredY->AutoSize = true;
			this->checkDesiredY->Location = System::Drawing::Point(12, 196);
			this->checkDesiredY->Name = L"checkDesiredY";
			this->checkDesiredY->Size = System::Drawing::Size(60, 17);
			this->checkDesiredY->TabIndex = 9;
			this->checkDesiredY->Text = L"desired";
			this->checkDesiredY->UseVisualStyleBackColor = true;
			// 
			// checkProfitX
			// 
			this->checkProfitX->AutoSize = true;
			this->checkProfitX->Location = System::Drawing::Point(558, 69);
			this->checkProfitX->Name = L"checkProfitX";
			this->checkProfitX->Size = System::Drawing::Size(49, 17);
			this->checkProfitX->TabIndex = 20;
			this->checkProfitX->Text = L"profit";
			this->checkProfitX->UseVisualStyleBackColor = true;
			// 
			// checkStockX
			// 
			this->checkStockX->AutoSize = true;
			this->checkStockX->Location = System::Drawing::Point(500, 69);
			this->checkStockX->Name = L"checkStockX";
			this->checkStockX->Size = System::Drawing::Size(52, 17);
			this->checkStockX->TabIndex = 19;
			this->checkStockX->Text = L"stock";
			this->checkStockX->UseVisualStyleBackColor = true;
			// 
			// checkSoldX
			// 
			this->checkSoldX->AutoSize = true;
			this->checkSoldX->Location = System::Drawing::Point(449, 69);
			this->checkSoldX->Name = L"checkSoldX";
			this->checkSoldX->Size = System::Drawing::Size(45, 17);
			this->checkSoldX->TabIndex = 18;
			this->checkSoldX->Text = L"sold";
			this->checkSoldX->UseVisualStyleBackColor = true;
			// 
			// checkDesiredX
			// 
			this->checkDesiredX->AutoSize = true;
			this->checkDesiredX->Location = System::Drawing::Point(383, 69);
			this->checkDesiredX->Name = L"checkDesiredX";
			this->checkDesiredX->Size = System::Drawing::Size(60, 17);
			this->checkDesiredX->TabIndex = 17;
			this->checkDesiredX->Text = L"desired";
			this->checkDesiredX->UseVisualStyleBackColor = true;
			// 
			// checkWorkersX
			// 
			this->checkWorkersX->AutoSize = true;
			this->checkWorkersX->Location = System::Drawing::Point(314, 69);
			this->checkWorkersX->Name = L"checkWorkersX";
			this->checkWorkersX->Size = System::Drawing::Size(63, 17);
			this->checkWorkersX->TabIndex = 16;
			this->checkWorkersX->Text = L"workers";
			this->checkWorkersX->UseVisualStyleBackColor = true;
			// 
			// checkMoneyX
			// 
			this->checkMoneyX->AutoSize = true;
			this->checkMoneyX->Location = System::Drawing::Point(251, 69);
			this->checkMoneyX->Name = L"checkMoneyX";
			this->checkMoneyX->Size = System::Drawing::Size(57, 17);
			this->checkMoneyX->TabIndex = 15;
			this->checkMoneyX->Text = L"money";
			this->checkMoneyX->UseVisualStyleBackColor = true;
			// 
			// checkPriceX
			// 
			this->checkPriceX->AutoSize = true;
			this->checkPriceX->Location = System::Drawing::Point(196, 69);
			this->checkPriceX->Name = L"checkPriceX";
			this->checkPriceX->Size = System::Drawing::Size(49, 17);
			this->checkPriceX->TabIndex = 14;
			this->checkPriceX->Text = L"price";
			this->checkPriceX->UseVisualStyleBackColor = true;
			// 
			// checkSalaryX
			// 
			this->checkSalaryX->AutoSize = true;
			this->checkSalaryX->Location = System::Drawing::Point(137, 69);
			this->checkSalaryX->Name = L"checkSalaryX";
			this->checkSalaryX->Size = System::Drawing::Size(53, 17);
			this->checkSalaryX->TabIndex = 13;
			this->checkSalaryX->Text = L"salary";
			this->checkSalaryX->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 69);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 26);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &mainForm::button1_Click);
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1016, 537);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkProfitX);
			this->Controls->Add(this->checkStockX);
			this->Controls->Add(this->checkSoldX);
			this->Controls->Add(this->checkDesiredX);
			this->Controls->Add(this->checkWorkersX);
			this->Controls->Add(this->checkMoneyX);
			this->Controls->Add(this->checkPriceX);
			this->Controls->Add(this->checkSalaryX);
			this->Controls->Add(this->checkProfitY);
			this->Controls->Add(this->checkStockY);
			this->Controls->Add(this->checkSoldY);
			this->Controls->Add(this->checkDesiredY);
			this->Controls->Add(this->checkWorkersY);
			this->Controls->Add(this->checkMoneyY);
			this->Controls->Add(this->checkPriceY);
			this->Controls->Add(this->checkSalaryY);
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
			for (int i = 0; i < 10; i++)
			{
				earth.step();
			}
			
		}
	private: System::Void comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			this->chart->Series->Clear();
			vector<int> firm_ids;
			for (int i = 1; i < 3; i++)
			{
				firm_ids.push_back(i);
			}
			ostringstream request;
			ifstream fin;
			switch (comboBox->SelectedIndex)
			{
				case 0: request<<"model_salary_firm_"; break;
				case 1: request<<"model_price_firm_"; break;
				case 2: request<<"model_money_firm_"; break;
				case 3: request<<"model_workers_firm_"; break; 
				case 4: request<<"model_desired_firm_"; break;
				case 5: request<<"model_sold_firm_"; break;
				case 6: request<<"model_stock_firm_"; break;
				case 7: request<<"model_profit_firm_"; break;
				//case 8: request = earth._log.getfirmaction(); break;
			}
			if (!checkBox->Checked)
			{
				request<<int::Parse(textBox->Text)<<".txt";
				fin.open(request.str());
				this->chart->Series->Add("series");
				this->chart->Series["series"]->ChartType =  System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
//				this->chart->Series["series"]->ChartArea = chartArea1;
				while (!fin.eof())
				{
					double value;
					fin>>value;
					this->chart->Series["series"]->Points->AddY(value);
				}
				fin.close();
			}
			else
			{
				for (int i = 0; i < firm_ids.size(); i++)
				{
					this->chart->Series->Add("series"+(i).ToString());
					if (comboBox->SelectedIndex != 8)
						this->chart->Series["series"+(i).ToString()]->ChartType =  System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
					else
						this->chart->Series["series"+(i).ToString()]->ChartType =  System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
//					this->chart->Series["series"]->ChartArea = chartArea1;
					ostringstream filename;
					filename<<request.str()<<firm_ids[i]<<".txt";
					fin.open(filename.str());
					while(!fin.eof())
					{
						double value;
						fin>>value;
						this->chart->Series["series"+(i).ToString()]->Points->AddY(value);
					}
					fin.close();
					filename.clear();
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
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			this->chart->Series->Clear();
			vector<int> firm_ids;
			for (int i = 1; i < 3; i++)
			{
				firm_ids.push_back(i);
			}
			vector<ostringstream> requestX;
			vector<ostringstream> requestY;
			ifstream finX, finY;
			if (checkSalaryX->Checked)
			{
				requestX.push_back(ostringstream());
				requestX[requestX.size() - 1]<<"model_salary_firm_";
			}
			if (checkPriceX->Checked)
			{
				requestX.push_back(ostringstream());
				requestX[requestX.size() - 1]<<"model_price_firm_";
			}
			if (checkMoneyX->Checked)
			{
				requestX.push_back(ostringstream());
				requestX[requestX.size() - 1]<<"model_money_firm_";
			}
			if (checkWorkersX->Checked)
			{
				requestX.push_back(ostringstream());
				requestX[requestX.size() - 1]<<"model_workers_firm_";
			}
			if (checkDesiredX->Checked)
			{
				requestX.push_back(ostringstream());
				requestX[requestX.size() - 1]<<"model_desired_firm_";
			}
			if (checkSoldX->Checked)
			{
				requestX.push_back(ostringstream());
				requestX[requestX.size() - 1]<<"model_sold_firm_";
			}
			if (checkStockX->Checked)
			{
				requestX.push_back(ostringstream());
				requestX[requestX.size() - 1]<<"model_stock_firm_";
			}
			if (checkProfitX->Checked)
			{
				requestX.push_back(ostringstream());
				requestX[requestX.size() - 1]<<"model_profit_firm_";
			}
			if (checkSalaryY->Checked)
			{
				requestY.push_back(ostringstream());
				requestY[requestY.size() - 1]<<"model_salary_firm_";
			}
			if (checkPriceY->Checked)
			{
				requestY.push_back(ostringstream());
				requestY[requestY.size() - 1]<<"model_price_firm_";
			}
			if (checkMoneyY->Checked)
			{
				requestY.push_back(ostringstream());
				requestY[requestY.size() - 1]<<"model_money_firm_";
			}
			if (checkWorkersY->Checked)
			{
				requestY.push_back(ostringstream());
				requestY[requestY.size() - 1]<<"model_workers_firm_";
			}
			if (checkDesiredY->Checked)
			{
				requestY.push_back(ostringstream());
				requestY[requestY.size() - 1]<<"model_desired_firm_";
			}
			if (checkSoldY->Checked)
			{
				requestY.push_back(ostringstream());
				requestY[requestY.size() - 1]<<"model_sold_firm_";
			}
			if (checkStockY->Checked)
			{
				requestY.push_back(ostringstream());
				requestY[requestY.size() - 1]<<"model_stock_firm_";
			}
			if (checkProfitY->Checked)
			{
				requestY.push_back(ostringstream());
				requestY[requestY.size() - 1]<<"model_profit_firm_";
			}
			if (!checkBox->Checked)
			{
				
				if (requestX.size())
				{
					for (int i = 0; i < requestX.size(); i++)
					{
						ostringstream title, sourceX, sourceY;
						for (int j = 0; j < requestY.size(); j++)
						{
							title<<requestX[i].str()<<requestY[j].str();
							sourceX<<requestX[i].str()<<int::Parse(textBox->Text)<<".txt";
							sourceY<<requestY[j].str()<<int::Parse(textBox->Text)<<".txt";
							this->chart->Series->Add(gcnew String(title.str().c_str()));
							this->chart->Series[gcnew String(title.str().c_str())]->ChartType =  System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
							//this->chart->Series[gcnew String(title.str().c_str())]->Color = System::Drawing::Color::FromArgb(i,j,i,j);
							finX.open(sourceX.str());							
							finY.open(sourceY.str());
							while ((!finX.eof()) && (!finY.eof()))
							{
								double valueX, valueY;
								finX>>valueX;
								finY>>valueY;
								this->chart->Series[gcnew String(title.str().c_str())]->Points->AddXY(valueX, valueY);
							}
							finY.close();
							finX.close();
							title.str("");
							sourceX.str("");
							sourceY.str("");
						}						
					}
				}
				else
				{
					for (int j = 0; j < requestY.size(); j++)
					{
						ostringstream title, sourceY;
						title<<requestY[j].str();
						sourceY<<requestY[j].str()<<int::Parse(textBox->Text)<<".txt";
						this->chart->Series->Add(gcnew String(title.str().c_str()));
						this->chart->Series[gcnew String(title.str().c_str())]->ChartType =  System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
						//this->chart->Series[gcnew String(title.str().c_str())]->Color = System::Drawing::Color::FromArgb(i,j,i,j);
						finY.open(sourceY.str());
						while (!finY.eof())
						{
							double valueY;
							finY>>valueY;
							this->chart->Series[gcnew String(title.str().c_str())]->Points->AddY(valueY);
						}
						finY.close();
						finX.close();
						title.str("");
						sourceY.str("");
					}	
				}
			}
			else
			{
				if (requestX.size())
				{
					for (int f = 0; f < firm_ids.size(); f++)
					{						
						for (int i = 0; i < requestX.size(); i++)
						{
							ostringstream title, sourceX, sourceY;						
							for (int j = 0; j < requestY.size(); j++)
							{
								title<<requestX[i].str()<<requestY[j].str()<<firm_ids[f];
								sourceX<<requestX[i].str()<<firm_ids[f]<<".txt";
								sourceY<<requestY[j].str()<<firm_ids[f]<<".txt";								
								this->chart->Series->Add(gcnew String(title.str().c_str()));
								this->chart->Series[gcnew String(title.str().c_str())]->ChartType =  System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
								//this->chart->Series[gcnew String(title.str().c_str())]->Color = System::Drawing::Color::FromArgb(i,j,i,j);
								finX.open(sourceX.str());
								finY.open(sourceY.str());								
								while ((!finX.eof()) && (!finY.eof()))
								{
									double valueX, valueY;
									finX>>valueX;
									finY>>valueY;
									this->chart->Series[gcnew String(title.str().c_str())]->Points->AddXY(valueX, valueY);
								}
								finY.close();
								finX.close();
								title.str("");
								sourceX.str("");
								sourceY.str("");
							}							
						}
					}
				}
				else
				{
					for (int f = 0; f < firm_ids.size(); f++)
					{						
						ostringstream title, sourceY;
						for (int j = 0; j < requestY.size(); j++)
						{
							title<<requestY[j].str()<<firm_ids[f];							
							sourceY<<requestY[j].str()<<firm_ids[f]<<".txt";								
							this->chart->Series->Add(gcnew String(title.str().c_str()));
							this->chart->Series[gcnew String(title.str().c_str())]->ChartType =  System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
							//this->chart->Series[gcnew String(title.str().c_str())]->Color = System::Drawing::Color::FromArgb(i,j,i,j);
							finY.open(sourceY.str());								
							while (!finY.eof())
							{
								double valueY;								
								finY>>valueY;
								this->chart->Series[gcnew String(title.str().c_str())]->Points->AddY(valueY);
							}
							finY.close();						;
							title.str("");							
							sourceY.str("");
						}							
					}
				}
			}			
}
};
}

