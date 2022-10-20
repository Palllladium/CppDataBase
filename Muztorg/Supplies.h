#pragma once
#include "buttonMenu.h"
#include "StructOfSupplies.h"

namespace Muztorg {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <sumOfSale>
	/// Сводка для Supplies
	/// </sumOfSale>
	public ref class Supplies : public System::Windows::Forms::Form
	{
	public:
		Supplies(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <sumOfSale>
		/// Освободить все используемые ресурсы.
		/// </sumOfSale>
		~Supplies()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private:

		List<Buyer>* BuyerBase;
		List<Employee>* EmployeeBase;
		List<Guitar>* GuitarBase;
		Sales_list* SaleBase;
		StructsOfSales_list* StructOfSaleBase;
		Supplies_list* SupplyBase;
		StructsOfSupplies_list* StructOfSupplyBase;

		Unit<Supply>* CurrentPtr;

		bool DataChanged;
		bool BoxActive;
		bool AddMode;

	private: System::Windows::Forms::ComboBox^ EmployeeBox;
	private: System::Windows::Forms::MaskedTextBox^ DateMaskedBox;
	private: System::Windows::Forms::Button^ ToggleChange;
	private: System::Windows::Forms::Button^ ToggleChangesOff;
	private: System::Windows::Forms::DataGridView^ SupplyGridView;
	private: System::Windows::Forms::Button^ Save;

	private: System::Windows::Forms::Button^ Add;
	private: System::Windows::Forms::Button^ Prev;
	private: System::Windows::Forms::Button^ Next;
	private: System::Windows::Forms::Button^ Exit;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ strSupplyButton;
	private: System::Windows::Forms::Label^ label4;

	public:

		void set_BuyerBase(List<Buyer>* value) { this->BuyerBase = value; }
		void set_EmployeeBase(List<Employee>* value) { this->EmployeeBase = value; }
		void set_GuitarBase(List<Guitar>* value) { this->GuitarBase = value; }
		void set_SaleBase(Sales_list* value) { this->SaleBase = value; }
		void set_StructOfSaleBase(StructsOfSales_list* value) { this->StructOfSaleBase = value; }
		void set_SupplyBase(Supplies_list* value) { this->SupplyBase = value; }
		void set_StructsOfSuppliesBase(StructsOfSupplies_list* value) { this->StructOfSupplyBase = value; }

	private:
		/// <sumOfSale>
		/// Обязательная переменная конструктора.
		/// </sumOfSale>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <sumOfSale>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </sumOfSale>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Supplies::typeid));
			this->EmployeeBox = (gcnew System::Windows::Forms::ComboBox());
			this->DateMaskedBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->ToggleChangesOff = (gcnew System::Windows::Forms::Button());
			this->ToggleChange = (gcnew System::Windows::Forms::Button());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->Prev = (gcnew System::Windows::Forms::Button());
			this->Next = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->SupplyGridView = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->strSupplyButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SupplyGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// EmployeeBox
			// 
			this->EmployeeBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->EmployeeBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->EmployeeBox->FormattingEnabled = true;
			this->EmployeeBox->Location = System::Drawing::Point(174, 110);
			this->EmployeeBox->Name = L"EmployeeBox";
			this->EmployeeBox->Size = System::Drawing::Size(323, 25);
			this->EmployeeBox->TabIndex = 1;
			this->EmployeeBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Supplies::Box_SelectedIndexChanged);
			this->EmployeeBox->Enter += gcnew System::EventHandler(this, &Supplies::Box_Enter);
			this->EmployeeBox->Leave += gcnew System::EventHandler(this, &Supplies::Box_Leave);
			// 
			// DateMaskedBox
			// 
			this->DateMaskedBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->DateMaskedBox->Location = System::Drawing::Point(174, 148);
			this->DateMaskedBox->Mask = L"00/00/0000";
			this->DateMaskedBox->Name = L"DateMaskedBox";
			this->DateMaskedBox->Size = System::Drawing::Size(323, 23);
			this->DateMaskedBox->TabIndex = 30;
			this->DateMaskedBox->ValidatingType = System::DateTime::typeid;
			this->DateMaskedBox->TextChanged += gcnew System::EventHandler(this, &Supplies::Box_SelectedIndexChanged);
			this->DateMaskedBox->Enter += gcnew System::EventHandler(this, &Supplies::Box_Enter);
			this->DateMaskedBox->Leave += gcnew System::EventHandler(this, &Supplies::Box_Leave);
			// 
			// ToggleChangesOff
			// 
			this->ToggleChangesOff->BackColor = System::Drawing::Color::DarkCyan;
			this->ToggleChangesOff->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ToggleChangesOff->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->ToggleChangesOff->Location = System::Drawing::Point(25, 35);
			this->ToggleChangesOff->Name = L"ToggleChangesOff";
			this->ToggleChangesOff->Size = System::Drawing::Size(237, 61);
			this->ToggleChangesOff->TabIndex = 20;
			this->ToggleChangesOff->Text = L"Запретить изменения";
			this->ToggleChangesOff->UseVisualStyleBackColor = false;
			this->ToggleChangesOff->Click += gcnew System::EventHandler(this, &Supplies::ToggleChangesOff_Click);
			// 
			// ToggleChange
			// 
			this->ToggleChange->BackColor = System::Drawing::Color::DarkCyan;
			this->ToggleChange->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ToggleChange->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->ToggleChange->Location = System::Drawing::Point(25, 35);
			this->ToggleChange->Name = L"ToggleChange";
			this->ToggleChange->Size = System::Drawing::Size(237, 61);
			this->ToggleChange->TabIndex = 18;
			this->ToggleChange->Text = L"Разрешить изменения";
			this->ToggleChange->UseVisualStyleBackColor = false;
			this->ToggleChange->Click += gcnew System::EventHandler(this, &Supplies::ToggleChange_Click);
			// 
			// Save
			// 
			this->Save->BackColor = System::Drawing::Color::MediumSeaGreen;
			this->Save->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Save->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Save->Location = System::Drawing::Point(268, 35);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(230, 29);
			this->Save->TabIndex = 19;
			this->Save->Text = L"Сохранить";
			this->Save->UseVisualStyleBackColor = false;
			this->Save->Click += gcnew System::EventHandler(this, &Supplies::Save_Click);
			// 
			// Add
			// 
			this->Add->BackColor = System::Drawing::Color::Gold;
			this->Add->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Add->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Add->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->Add->Location = System::Drawing::Point(268, 67);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(230, 29);
			this->Add->TabIndex = 17;
			this->Add->Text = L"Добавить";
			this->Add->UseVisualStyleBackColor = false;
			this->Add->Click += gcnew System::EventHandler(this, &Supplies::Add_Click);
			// 
			// Prev
			// 
			this->Prev->BackColor = System::Drawing::Color::DarkCyan;
			this->Prev->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Prev->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Prev->Location = System::Drawing::Point(30, 461);
			this->Prev->Name = L"Prev";
			this->Prev->Size = System::Drawing::Size(101, 29);
			this->Prev->TabIndex = 16;
			this->Prev->Text = L"PREV";
			this->Prev->UseVisualStyleBackColor = false;
			this->Prev->DoubleClick += gcnew System::EventHandler(this, &Supplies::Prev_Click);
			this->Prev->Click += gcnew System::EventHandler(this, &Supplies::Prev_Click);
			// 
			// Next
			// 
			this->Next->BackColor = System::Drawing::Color::DarkCyan;
			this->Next->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Next->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Next->Location = System::Drawing::Point(137, 461);
			this->Next->Name = L"Next";
			this->Next->Size = System::Drawing::Size(101, 29);
			this->Next->TabIndex = 15;
			this->Next->Text = L"NEXT";
			this->Next->UseVisualStyleBackColor = false;
			this->Next->DoubleClick += gcnew System::EventHandler(this, &Supplies::Next_Click);
			this->Next->Click += gcnew System::EventHandler(this, &Supplies::Next_Click);
			// 
			// Exit
			// 
			this->Exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Exit->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Exit->Location = System::Drawing::Point(383, 461);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(114, 29);
			this->Exit->TabIndex = 14;
			this->Exit->Text = L"EXIT";
			this->Exit->UseVisualStyleBackColor = false;
			this->Exit->Click += gcnew System::EventHandler(this, &Supplies::Exit_Click);
			// 
			// SupplyGridView
			// 
			this->SupplyGridView->AllowUserToAddRows = false;
			this->SupplyGridView->AllowUserToDeleteRows = false;
			this->SupplyGridView->AllowUserToResizeColumns = false;
			this->SupplyGridView->AllowUserToResizeRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->SupplyGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->SupplyGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->SupplyGridView->DefaultCellStyle = dataGridViewCellStyle2;
			this->SupplyGridView->Location = System::Drawing::Point(26, 189);
			this->SupplyGridView->Name = L"SupplyGridView";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->SupplyGridView->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->SupplyGridView->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->SupplyGridView->Size = System::Drawing::Size(472, 252);
			this->SupplyGridView->TabIndex = 27;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label2->Location = System::Drawing::Point(21, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(110, 21);
			this->label2->TabIndex = 24;
			this->label2->Text = L"Сотрудник:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label4->Location = System::Drawing::Point(21, 148);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(140, 21);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Дата продажи:";
			// 
			// strSupplyButton
			// 
			this->strSupplyButton->BackColor = System::Drawing::Color::DodgerBlue;
			this->strSupplyButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->strSupplyButton->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->strSupplyButton->Location = System::Drawing::Point(244, 461);
			this->strSupplyButton->Name = L"strSupplyButton";
			this->strSupplyButton->Size = System::Drawing::Size(133, 29);
			this->strSupplyButton->TabIndex = 32;
			this->strSupplyButton->Text = L"Подробнее";
			this->strSupplyButton->UseVisualStyleBackColor = false;
			this->strSupplyButton->Click += gcnew System::EventHandler(this, &Supplies ::strOfSupply_Click);
			// 
			// Supplies
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(524, 521);
			this->Controls->Add(this->strSupplyButton);
			this->Controls->Add(this->SupplyGridView);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->ToggleChangesOff);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->ToggleChange);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->Prev);
			this->Controls->Add(this->Next);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->DateMaskedBox);
			this->Controls->Add(this->EmployeeBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Supplies";
			this->Text = L"Поставки";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Supplies::Supplies_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Supplies::Supplies_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SupplyGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void Supplies_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Supplies_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void Box_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Prev_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Next_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e);
	//private: System::Void Delete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToggleChange_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Box_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Box_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void strOfSupply_Click(System::Object^ sender, System::EventArgs^ e);
};
}
