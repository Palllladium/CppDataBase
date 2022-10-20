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
	/// Сводка для GuitarsSupplies_Report
	/// </summary>
	public ref class GuitarsSupplies_Report : public System::Windows::Forms::Form
	{
	public:
		GuitarsSupplies_Report(Unit<Guitar>* data)
		{
			InitializeComponent();
			this->SearchedGuitar = data;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GuitarsSupplies_Report()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private:

		Unit<Guitar>* SearchedGuitar;
		List<Employee>* EmployeeBase;
		List<Guitar>* GuitarBase;
		List<Buyer>* BuyerBase;
		Sales_list* SaleBase;
		Supplies_list* SupplyBase;
		StructsOfSales_list* StructOfSaleBase;
		StructsOfSupplies_list* StructOfSupplyBase;

	private: System::Windows::Forms::DataGridView^ ReportDgv;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ TitleBox;
	private: System::Windows::Forms::Label^ TitleLabel;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GuitarsSupplies_Report::typeid));
			this->ReportDgv = (gcnew System::Windows::Forms::DataGridView());
			this->TitleBox = (gcnew System::Windows::Forms::TextBox());
			this->TitleLabel = (gcnew System::Windows::Forms::Label());
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
			this->ReportDgv->Location = System::Drawing::Point(13, 102);
			this->ReportDgv->MultiSelect = false;
			this->ReportDgv->Name = L"ReportDgv";
			this->ReportDgv->ReadOnly = true;
			this->ReportDgv->RowHeadersVisible = false;
			this->ReportDgv->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ReportDgv->ShowEditingIcon = false;
			this->ReportDgv->Size = System::Drawing::Size(667, 294);
			this->ReportDgv->TabIndex = 2;
			this->ReportDgv->TabStop = false;
			// 
			// TitleBox
			// 
			this->TitleBox->BackColor = System::Drawing::SystemColors::Window;
			this->TitleBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->TitleBox->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TitleBox->HideSelection = false;
			this->TitleBox->Location = System::Drawing::Point(175, 66);
			this->TitleBox->Name = L"TitleBox";
			this->TitleBox->ReadOnly = true;
			this->TitleBox->Size = System::Drawing::Size(325, 30);
			this->TitleBox->TabIndex = 1;
			this->TitleBox->TabStop = false;
			this->TitleBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TitleLabel
			// 
			this->TitleLabel->BackColor = System::Drawing::SystemColors::ControlLight;
			this->TitleLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TitleLabel->ForeColor = System::Drawing::SystemColors::MenuText;
			this->TitleLabel->Location = System::Drawing::Point(215, 18);
			this->TitleLabel->Name = L"TitleLabel";
			this->TitleLabel->Size = System::Drawing::Size(245, 33);
			this->TitleLabel->TabIndex = 0;
			this->TitleLabel->Text = L"Поставки по товару";
			// 
			// pictureBox1
			// 
			this->pictureBox1->ImageLocation = L"D:\\Филиповский\\Muztorg\\Muztorg\\line2.jpg";
			this->pictureBox1->Location = System::Drawing::Point(-4, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(700, 48);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// GuitarsSupplies_Report
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(692, 407);
			this->Controls->Add(this->TitleLabel);
			this->Controls->Add(this->TitleBox);
			this->Controls->Add(this->ReportDgv);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"GuitarsSupplies_Report";
			this->Text = L"Отчёт по поставкам";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &GuitarsSupplies_Report::GuitarsSupplies_Report_FormClosed);
			this->Load += gcnew System::EventHandler(this, &GuitarsSupplies_Report::GuitarsSupplies_Report_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ReportDgv))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ExitButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void GuitarsSupplies_Report_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void GuitarsSupplies_Report_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	};
}
