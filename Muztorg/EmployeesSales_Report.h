#pragma once
#include "buttonMenu.h"

namespace Muztorg {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ EmployeesSales_Report
	/// </summary>
	public ref class EmployeesSales_Report : public System::Windows::Forms::Form
	{
	public:
		EmployeesSales_Report(Unit<Employee>* data)
		{
			InitializeComponent();
			this->SearchedEmployee = data;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~EmployeesSales_Report()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private:

		Unit<Employee>* SearchedEmployee;
		List<Employee>* EmployeeBase;
		List<Guitar>* GuitarBase;
		List<Buyer>* BuyerBase;
		Sales_list* SaleBase;
		Supplies_list* SupplyBase;
		StructsOfSales_list* StructOfSaleBase;
		StructsOfSupplies_list* StructOfSupplyBase;

	private: System::Windows::Forms::DataGridView^ ReportDgv;
	private: System::Windows::Forms::TextBox^ NameBox;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;

	public:

		void set_EmployeeBase(List<Employee>* value) { this->EmployeeBase = value; }
		void set_GuitarBase(List<Guitar>* value) { this->GuitarBase = value; }
		void set_BuyerBase(List<Buyer>* value) { this->BuyerBase = value; }
		void set_SaleBase(Sales_list* value) { this->SaleBase = value; }
		void set_SupplyBase(Supplies_list* value) { this->SupplyBase = value; }
		void set_StructOfSaleBase(StructsOfSales_list* value) { this->StructOfSaleBase = value; }
		void set_StructsOfSupplyBase(StructsOfSupplies_list* value) { this->StructOfSupplyBase = value; }

	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EmployeesSales_Report::typeid));
			this->ReportDgv = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->NameBox = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ReportDgv))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// ReportDgv
			// 
			this->ReportDgv->AllowUserToAddRows = false;
			this->ReportDgv->AllowUserToDeleteRows = false;
			this->ReportDgv->AllowUserToResizeColumns = false;
			this->ReportDgv->AllowUserToResizeRows = false;
			this->ReportDgv->BackgroundColor = System::Drawing::SystemColors::Window;
			this->ReportDgv->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ReportDgv->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ReportDgv->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->ReportDgv->ColumnHeadersHeight = 25;
			this->ReportDgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ReportDgv->DefaultCellStyle = dataGridViewCellStyle2;
			this->ReportDgv->GridColor = System::Drawing::SystemColors::InfoText;
			this->ReportDgv->Location = System::Drawing::Point(12, 102);
			this->ReportDgv->MultiSelect = false;
			this->ReportDgv->Name = L"ReportDgv";
			this->ReportDgv->ReadOnly = true;
			this->ReportDgv->RowHeadersVisible = false;
			this->ReportDgv->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ReportDgv->ShowEditingIcon = false;
			this->ReportDgv->Size = System::Drawing::Size(724, 293);
			this->ReportDgv->TabIndex = 2;
			this->ReportDgv->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(182, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(387, 33);
			this->label1->TabIndex = 20;
			this->label1->Text = L"ќтчЄт по продажам сотрудника";
			// 
			// NameBox
			// 
			this->NameBox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->NameBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->NameBox->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NameBox->Location = System::Drawing::Point(128, 64);
			this->NameBox->Name = L"NameBox";
			this->NameBox->ReadOnly = true;
			this->NameBox->Size = System::Drawing::Size(500, 30);
			this->NameBox->TabIndex = 19;
			this->NameBox->TabStop = false;
			this->NameBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pictureBox1
			// 
			this->pictureBox1->ImageLocation = L"D:\\‘илиповский\\Muztorg\\Muztorg\\line5.png";
			this->pictureBox1->Location = System::Drawing::Point(-4, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(755, 48);
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// EmployeesSales_Report
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(749, 407);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->NameBox);
			this->Controls->Add(this->ReportDgv);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"EmployeesSales_Report";
			this->Text = L"ќтчЄт по продажам";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &EmployeesSales_Report::EmployeesSales_Report_FormClosed);
			this->Load += gcnew System::EventHandler(this, &EmployeesSales_Report::EmployeesSales_Report_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ReportDgv))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EmployeesSales_Report_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EmployeesSales_Report_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	};
}