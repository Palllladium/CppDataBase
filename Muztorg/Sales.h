#pragma once
#include "buttonMenu.h"

namespace Muztorg {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <sumOfSale>
	/// Сводка для Sales
	/// </sumOfSale>
	public ref class Sales : public System::Windows::Forms::Form
	{
	public:
		Sales(void)
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
		~Sales()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
	protected:
	private:

		List<Buyer>* BuyerBase;
		List<Employee>* EmployeeBase;
		List<Guitar>* GuitarBase;
		Sales_list* SaleBase;
		StructsOfSales_list* StructOfSaleBase;
		Supplies_list* SupplyBase;
		StructsOfSupplies_list* StructOfSupplyBase;

		Unit<Sale>* CurrentPtr;
		List<Unit<StructOfSale>*>* CurrentStrPtr;

		bool DataChanged;
		bool BoxActive;
		bool AddMode;

	private: System::Windows::Forms::ComboBox^ BuyerBox;
	private: System::Windows::Forms::ComboBox^ EmployeeBox;

	private: System::Windows::Forms::MaskedTextBox^ DateMaskedBox;
	private: System::Windows::Forms::TextBox^ SumBox;

	private: System::Windows::Forms::Button^ Delete;
	private: System::Windows::Forms::Button^ ToggleChange;
	private: System::Windows::Forms::Button^ ToggleChangesOff;
	private: System::Windows::Forms::Button^ Save;
	private: System::Windows::Forms::Button^ Add;
	private: System::Windows::Forms::Button^ Prev;
	private: System::Windows::Forms::Button^ Next;
	private: System::Windows::Forms::Button^ Exit;
	private: System::Windows::Forms::Button^ Bill;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::DataGridView^ SaleGridView;

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
			this->BuyerBox = (gcnew System::Windows::Forms::ComboBox());
			this->EmployeeBox = (gcnew System::Windows::Forms::ComboBox());
			this->DateMaskedBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->Delete = (gcnew System::Windows::Forms::Button());
			this->ToggleChangesOff = (gcnew System::Windows::Forms::Button());
			this->ToggleChange = (gcnew System::Windows::Forms::Button());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->Prev = (gcnew System::Windows::Forms::Button());
			this->Next = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->Bill = (gcnew System::Windows::Forms::Button());
			this->SaleGridView = (gcnew System::Windows::Forms::DataGridView());
			this->SumBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SaleGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// BuyerBox
			// 
			this->BuyerBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->BuyerBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->BuyerBox->FormattingEnabled = true;
			this->BuyerBox->Location = System::Drawing::Point(215, 35);
			this->BuyerBox->Name = L"BuyerBox";
			this->BuyerBox->Size = System::Drawing::Size(323, 25);
			this->BuyerBox->TabIndex = 0;
			this->BuyerBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Sales::Box_SelectedIndexChanged);
			this->BuyerBox->Enter += gcnew System::EventHandler(this, &Sales::Box_Enter);
			this->BuyerBox->Leave += gcnew System::EventHandler(this, &Sales::Box_Leave);
			// 
			// EmployeeBox
			// 
			this->EmployeeBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->EmployeeBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->EmployeeBox->FormattingEnabled = true;
			this->EmployeeBox->Location = System::Drawing::Point(215, 72);
			this->EmployeeBox->Name = L"EmployeeBox";
			this->EmployeeBox->Size = System::Drawing::Size(323, 25);
			this->EmployeeBox->TabIndex = 1;
			this->EmployeeBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Sales::Box_SelectedIndexChanged);
			this->EmployeeBox->Enter += gcnew System::EventHandler(this, &Sales::Box_Enter);
			this->EmployeeBox->Leave += gcnew System::EventHandler(this, &Sales::Box_Leave);
			// 
			// DateMaskedBox
			// 
			this->DateMaskedBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->DateMaskedBox->Location = System::Drawing::Point(215, 110);
			this->DateMaskedBox->Mask = L"00/00/0000";
			this->DateMaskedBox->Name = L"DateMaskedBox";
			this->DateMaskedBox->Size = System::Drawing::Size(323, 23);
			this->DateMaskedBox->TabIndex = 30;
			this->DateMaskedBox->ValidatingType = System::DateTime::typeid;
			this->DateMaskedBox->TextChanged += gcnew System::EventHandler(this, &Sales::Box_SelectedIndexChanged);
			this->DateMaskedBox->Enter += gcnew System::EventHandler(this, &Sales::Box_Enter);
			this->DateMaskedBox->Leave += gcnew System::EventHandler(this, &Sales::Box_Leave);
			// 
			// Delete
			// 
			this->Delete->BackColor = System::Drawing::Color::DarkCyan;
			this->Delete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Delete->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Delete->Location = System::Drawing::Point(672, 107);
			this->Delete->Name = L"Delete";
			this->Delete->Size = System::Drawing::Size(107, 35);
			this->Delete->TabIndex = 21;
			this->Delete->Text = L"Удалить";
			this->Delete->UseVisualStyleBackColor = false;
			this->Delete->Click += gcnew System::EventHandler(this, &Sales::Delete_Click);
			// 
			// ToggleChangesOff
			// 
			this->ToggleChangesOff->BackColor = System::Drawing::Color::DarkCyan;
			this->ToggleChangesOff->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ToggleChangesOff->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->ToggleChangesOff->Location = System::Drawing::Point(559, 66);
			this->ToggleChangesOff->Name = L"ToggleChangesOff";
			this->ToggleChangesOff->Size = System::Drawing::Size(220, 35);
			this->ToggleChangesOff->TabIndex = 20;
			this->ToggleChangesOff->Text = L"Запретить изменения";
			this->ToggleChangesOff->UseVisualStyleBackColor = false;
			this->ToggleChangesOff->Click += gcnew System::EventHandler(this, &Sales::ToggleChangesOff_Click);
			// 
			// ToggleChange
			// 
			this->ToggleChange->BackColor = System::Drawing::Color::DarkCyan;
			this->ToggleChange->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ToggleChange->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->ToggleChange->Location = System::Drawing::Point(559, 66);
			this->ToggleChange->Name = L"ToggleChange";
			this->ToggleChange->Size = System::Drawing::Size(220, 35);
			this->ToggleChange->TabIndex = 18;
			this->ToggleChange->Text = L"Разрешить изменения";
			this->ToggleChange->UseVisualStyleBackColor = false;
			this->ToggleChange->Click += gcnew System::EventHandler(this, &Sales::ToggleChange_Click);
			// 
			// Save
			// 
			this->Save->BackColor = System::Drawing::Color::MediumSeaGreen;
			this->Save->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Save->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Save->Location = System::Drawing::Point(672, 25);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(107, 35);
			this->Save->TabIndex = 19;
			this->Save->Text = L"Сохранить";
			this->Save->UseVisualStyleBackColor = false;
			this->Save->Click += gcnew System::EventHandler(this, &Sales::Save_Click);
			// 
			// Add
			// 
			this->Add->BackColor = System::Drawing::Color::DarkCyan;
			this->Add->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Add->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Add->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->Add->Location = System::Drawing::Point(559, 107);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(107, 35);
			this->Add->TabIndex = 17;
			this->Add->Text = L"Добавить";
			this->Add->UseVisualStyleBackColor = false;
			this->Add->Click += gcnew System::EventHandler(this, &Sales::Add_Click);
			// 
			// Prev
			// 
			this->Prev->BackColor = System::Drawing::Color::DarkCyan;
			this->Prev->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Prev->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Prev->Location = System::Drawing::Point(526, 430);
			this->Prev->Name = L"Prev";
			this->Prev->Size = System::Drawing::Size(75, 29);
			this->Prev->TabIndex = 16;
			this->Prev->Text = L"PREV";
			this->Prev->UseVisualStyleBackColor = false;
			this->Prev->DoubleClick += gcnew System::EventHandler(this, &Sales::Prev_Click);
			this->Prev->Click += gcnew System::EventHandler(this, &Sales::Prev_Click);
			// 
			// Next
			// 
			this->Next->BackColor = System::Drawing::Color::DarkCyan;
			this->Next->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Next->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Next->Location = System::Drawing::Point(607, 430);
			this->Next->Name = L"Next";
			this->Next->Size = System::Drawing::Size(75, 29);
			this->Next->TabIndex = 15;
			this->Next->Text = L"NEXT";
			this->Next->UseVisualStyleBackColor = false;
			this->Next->DoubleClick += gcnew System::EventHandler(this, &Sales::Next_Click);
			this->Next->Click += gcnew System::EventHandler(this, &Sales::Next_Click);
			// 
			// Exit
			// 
			this->Exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Exit->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Exit->Location = System::Drawing::Point(688, 430);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(75, 29);
			this->Exit->TabIndex = 14;
			this->Exit->Text = L"EXIT";
			this->Exit->UseVisualStyleBackColor = false;
			this->Exit->Click += gcnew System::EventHandler(this, &Sales::Exit_Click);
			// 
			// Bill
			// 
			this->Bill->BackColor = System::Drawing::Color::DarkCyan;
			this->Bill->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Bill->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Bill->Location = System::Drawing::Point(559, 25);
			this->Bill->Name = L"Bill";
			this->Bill->Size = System::Drawing::Size(107, 35);
			this->Bill->TabIndex = 22;
			this->Bill->Text = L"Чек";
			this->Bill->UseVisualStyleBackColor = false;
			// 
			// SaleGridView
			// 
			this->SaleGridView->AllowUserToAddRows = true;
			this->SaleGridView->AllowUserToDeleteRows = false;
			this->SaleGridView->AllowUserToResizeColumns = false;
			this->SaleGridView->AllowUserToResizeRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->SaleGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->SaleGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->SaleGridView->DefaultCellStyle = dataGridViewCellStyle2;
			this->SaleGridView->Location = System::Drawing::Point(66, 157);
			this->SaleGridView->Name = L"SaleGridView";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->SaleGridView->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->SaleGridView->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->SaleGridView->Size = System::Drawing::Size(713, 252);
			this->SaleGridView->TabIndex = 27;
			this->SaleGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Sales::SaleGridView_CellContentClick);
			this->SaleGridView->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Sales::SaleGridView_CellEnter);
			this->SaleGridView->CellLeave += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Sales::SaleGridView_CellLeave);
			this->SaleGridView->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &Sales::SaleGridView_EditingControlShowing);
			// 
			// SumBox
			// 
			this->SumBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->SumBox->Location = System::Drawing::Point(261, 433);
			this->SumBox->Name = L"SumBox";
			this->SumBox->ReadOnly = true;
			this->SumBox->Size = System::Drawing::Size(250, 23);
			this->SumBox->TabIndex = 29;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label1->Location = System::Drawing::Point(62, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 21);
			this->label1->TabIndex = 23;
			this->label1->Text = L"Покупатель:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label2->Location = System::Drawing::Point(62, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(110, 21);
			this->label2->TabIndex = 24;
			this->label2->Text = L"Сотрудник:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label3->Location = System::Drawing::Point(75, 433);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(180, 21);
			this->label3->TabIndex = 28;
			this->label3->Text = L"Итого по продаже:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label4->Location = System::Drawing::Point(62, 110);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(140, 21);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Дата продажи:";
			// 
			// Sales
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(847, 485);
			this->Controls->Add(this->SumBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->SaleGridView);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Bill);
			this->Controls->Add(this->Delete);
			this->Controls->Add(this->ToggleChangesOff);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->ToggleChange);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->Prev);
			this->Controls->Add(this->Next);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->DateMaskedBox);
			this->Controls->Add(this->EmployeeBox);
			this->Controls->Add(this->BuyerBox);
			this->Name = L"Sales";
			this->Text = L"Sales";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Sales::Sales_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Sales::Sales_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SaleGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Sales_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Sales_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void Box_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Prev_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Next_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Delete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToggleChange_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e);
	//private: System::Void Bill_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Box_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Box_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TextBox_Changed(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SaleGridView_CellEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void SaleGridView_CellLeave(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void SaleGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void SaleGridView_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e) {
		if (this->SaleGridView->CurrentCell->ColumnIndex == 0)
			e->Control->TextChanged += gcnew System::EventHandler(this, &Sales::TextBox_Changed);
	}
};
}
