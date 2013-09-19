#pragma once

#include "world.h"

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// Chart
			// 
			chartArea->Name = L"chartArea";
			this->chart->ChartAreas->Add(chartArea);
			this->chart->Dock = System::Windows::Forms::DockStyle::Fill;
			legend->Name = L"legend";
			this->chart->Legends->Add(legend);
			this->chart->Location = System::Drawing::Point(0, 0);
			this->chart->Name = L"chart";
			series->ChartArea = L"chartArea";
			series->Legend = L"legend";
			series->Name = L"series";
			this->chart->Series->Add(series);
			this->chart->Size = System::Drawing::Size(1345, 566);
			this->chart->TabIndex = 0;
			this->chart->Text = L"Chart";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1345, 566);
			this->Controls->Add(this->chart);
			this->Name = L"mainForm";
			this->Text = L"Main Form";
			this->DoubleClick += gcnew System::EventHandler(this, &mainForm::mainForm_DoubleClick);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void mainForm_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
				 world _world;
			 }
	};
}

