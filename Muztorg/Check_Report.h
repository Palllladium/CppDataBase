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
	/// Сводка для Check_Report
	/// </summary>
	public ref class Check_Report : public System::Windows::Forms::Form
	{
	public:
		Check_Report(Unit<Sale>* data)
		{
			InitializeComponent();
			this->SearchedSale = data;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Check_Report()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private:

		Unit<Sale>* SearchedSale;
		List<Employee>* EmployeeBase;
		List<Guitar>* GuitarBase;
		List<Buyer>* BuyerBase;
		Sales_list* SaleBase;
		Supplies_list* SupplyBase;
		StructsOfSales_list* StructOfSaleBase;
		StructsOfSupplies_list* StructOfSupplyBase;

	private: System::Windows::Forms::DataGridView^ ReportDgv;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ DateBox;
	private: System::Windows::Forms::TextBox^ EmployeeBox;
	private: System::Windows::Forms::TextBox^ BuyerBox;
	private: System::Windows::Forms::TextBox^ EmptyBox;
	private: System::Windows::Forms::TextBox^ CheckIDBox;
	private: System::Windows::Forms::Label^ CheckLabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label6;

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
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Check_Report::typeid));
			this->ReportDgv = (gcnew System::Windows::Forms::DataGridView());
			this->DateBox = (gcnew System::Windows::Forms::TextBox());
			this->CheckLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->EmployeeBox = (gcnew System::Windows::Forms::TextBox());
			this->BuyerBox = (gcnew System::Windows::Forms::TextBox());
			this->EmptyBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->CheckIDBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
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
			this->ReportDgv->Location = System::Drawing::Point(13, 102);
			this->ReportDgv->MultiSelect = false;
			this->ReportDgv->Name = L"ReportDgv";
			this->ReportDgv->ReadOnly = true;
			this->ReportDgv->RowHeadersVisible = false;
			this->ReportDgv->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ReportDgv->ShowEditingIcon = false;
			this->ReportDgv->Size = System::Drawing::Size(724, 119);
			this->ReportDgv->TabIndex = 2;
			this->ReportDgv->TabStop = false;
			// 
			// DateBox
			// 
			this->DateBox->BackColor = System::Drawing::SystemColors::Window;
			this->DateBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->DateBox->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DateBox->HideSelection = false;
			this->DateBox->Location = System::Drawing::Point(613, 76);
			this->DateBox->Name = L"DateBox";
			this->DateBox->ReadOnly = true;
			this->DateBox->Size = System::Drawing::Size(124, 20);
			this->DateBox->TabIndex = 1;
			this->DateBox->TabStop = false;
			this->DateBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// CheckLabel
			// 
			this->CheckLabel->BackColor = System::Drawing::SystemColors::ControlLight;
			this->CheckLabel->Font = (gcnew System::Drawing::Font(L"Calibri Light", 18.25F));
			this->CheckLabel->ForeColor = System::Drawing::SystemColors::MenuText;
			this->CheckLabel->Location = System::Drawing::Point(282, 21);
			this->CheckLabel->Name = L"CheckLabel";
			this->CheckLabel->Size = System::Drawing::Size(188, 33);
			this->CheckLabel->TabIndex = 0;
			this->CheckLabel->Text = L"Товарный чек №";
			// 
			// pictureBox1
			// 
			this->pictureBox1->ImageLocation = L"D:\\Филиповский\\Muztorg\\Muztorg\\line4.png";
			this->pictureBox1->Location = System::Drawing::Point(-4, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(754, 48);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// EmployeeBox
			// 
			this->EmployeeBox->BackColor = System::Drawing::SystemColors::HighlightText;
			this->EmployeeBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->EmployeeBox->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EmployeeBox->Location = System::Drawing::Point(131, 236);
			this->EmployeeBox->Name = L"EmployeeBox";
			this->EmployeeBox->ReadOnly = true;
			this->EmployeeBox->Size = System::Drawing::Size(277, 20);
			this->EmployeeBox->TabIndex = 4;
			this->EmployeeBox->TabStop = false;
			// 
			// BuyerBox
			// 
			this->BuyerBox->BackColor = System::Drawing::SystemColors::HighlightText;
			this->BuyerBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->BuyerBox->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BuyerBox->Location = System::Drawing::Point(131, 292);
			this->BuyerBox->Name = L"BuyerBox";
			this->BuyerBox->ReadOnly = true;
			this->BuyerBox->Size = System::Drawing::Size(277, 20);
			this->BuyerBox->TabIndex = 5;
			this->BuyerBox->TabStop = false;
			// 
			// EmptyBox
			// 
			this->EmptyBox->BackColor = System::Drawing::SystemColors::HighlightText;
			this->EmptyBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->EmptyBox->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->EmptyBox->Location = System::Drawing::Point(578, 236);
			this->EmptyBox->Name = L"EmptyBox";
			this->EmptyBox->ReadOnly = true;
			this->EmptyBox->Size = System::Drawing::Size(140, 20);
			this->EmptyBox->TabIndex = 6;
			this->EmptyBox->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->label1->Location = System::Drawing::Point(23, 238);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 19);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Продавец:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->label2->Location = System::Drawing::Point(23, 294);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 19);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Покупатель:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label3->Location = System::Drawing::Point(128, 259);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 14);
			this->label3->TabIndex = 9;
			this->label3->Text = L"(фамилия, имя, отчество)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label4->Location = System::Drawing::Point(128, 315);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(141, 14);
			this->label4->TabIndex = 10;
			this->label4->Text = L"(фамилия, имя, отчество)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(504, 238);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(68, 19);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Подпись";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(36, 74);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(197, 19);
			this->label6->TabIndex = 12;
			this->label6->Text = L"ООО \"Музторг\" ИНН 58934";
			// 
			// CheckIDBox
			// 
			this->CheckIDBox->BackColor = System::Drawing::SystemColors::ControlLight;
			this->CheckIDBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->CheckIDBox->Font = (gcnew System::Drawing::Font(L"Calibri Light", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CheckIDBox->Location = System::Drawing::Point(463, 22);
			this->CheckIDBox->Name = L"CheckIDBox";
			this->CheckIDBox->ReadOnly = true;
			this->CheckIDBox->Size = System::Drawing::Size(30, 30);
			this->CheckIDBox->TabIndex = 13;
			this->CheckIDBox->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(578, 247);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(140, 10);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			// 
			// Check_Report
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(749, 407);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->CheckIDBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->EmptyBox);
			this->Controls->Add(this->BuyerBox);
			this->Controls->Add(this->EmployeeBox);
			this->Controls->Add(this->CheckLabel);
			this->Controls->Add(this->DateBox);
			this->Controls->Add(this->ReportDgv);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Check_Report";
			this->Text = L"Отчёт по продажам";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Check_Report::Check_Report_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Check_Report::Check_Report_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ReportDgv))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ExitButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Check_Report_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Check_Report_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	};
}
