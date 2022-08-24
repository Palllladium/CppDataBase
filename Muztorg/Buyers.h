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
	/// Сводка для Buyers
	/// </sumOfSale>
	public ref class Buyers : public System::Windows::Forms::Form
	{
	public:
		Buyers(void)
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
		~Buyers()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		List<Buyer>* BuyerBase;
		List<Employee>* EmployeeBase;
		List<Guitar>* GuitarBase;
		Sales_list* SaleBase;
		StructsOfSales_list* StructOfSaleBase;
		Supplies_list* SupplyBase;
		StructsOfSupplies_list* StructOfSupplyBase;
		Unit<Buyer>* CurrentPtr;
		bool DataChanged;
		bool BoxActive;
		bool AddMode;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ PhoneBox;

	private: System::Windows::Forms::TextBox^ NameBox;
	private: System::Windows::Forms::Button^ Delete;
	private: System::Windows::Forms::Button^ ToggleChangesOff;
	private: System::Windows::Forms::Button^ Save;
	private: System::Windows::Forms::Button^ Add;
	private: System::Windows::Forms::Button^ Prev;
	private: System::Windows::Forms::Button^ Next;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ ToggleChanges;
	private: System::Windows::Forms::Button^ Exit;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PhoneBox = (gcnew System::Windows::Forms::TextBox());
			this->NameBox = (gcnew System::Windows::Forms::TextBox());
			this->Delete = (gcnew System::Windows::Forms::Button());
			this->ToggleChangesOff = (gcnew System::Windows::Forms::Button());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->Prev = (gcnew System::Windows::Forms::Button());
			this->Next = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->ToggleChanges = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Телефон";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 18;
			this->label1->Text = L"ФИО клиента";
			// 
			// PhoneBox
			// 
			this->PhoneBox->Location = System::Drawing::Point(105, 38);
			this->PhoneBox->Name = L"PhoneBox";
			this->PhoneBox->ReadOnly = true;
			this->PhoneBox->Size = System::Drawing::Size(271, 20);
			this->PhoneBox->TabIndex = 17;
			this->PhoneBox->TextChanged += gcnew System::EventHandler(this, &Buyers::NameBox_TextChanged);
			this->PhoneBox->Enter += gcnew System::EventHandler(this, &Buyers::NameBox_Enter);
			this->PhoneBox->Leave += gcnew System::EventHandler(this, &Buyers::NameBox_Leave);
			// 
			// NameBox
			// 
			this->NameBox->Location = System::Drawing::Point(105, 12);
			this->NameBox->Name = L"NameBox";
			this->NameBox->ReadOnly = true;
			this->NameBox->Size = System::Drawing::Size(271, 20);
			this->NameBox->TabIndex = 16;
			this->NameBox->TextChanged += gcnew System::EventHandler(this, &Buyers::NameBox_TextChanged);
			this->NameBox->Enter += gcnew System::EventHandler(this, &Buyers::NameBox_Enter);
			this->NameBox->Leave += gcnew System::EventHandler(this, &Buyers::NameBox_Leave);
			// 
			// Delete
			// 
			this->Delete->Location = System::Drawing::Point(382, 64);
			this->Delete->Name = L"Delete";
			this->Delete->Size = System::Drawing::Size(98, 20);
			this->Delete->TabIndex = 26;
			this->Delete->Text = L"Удалить";
			this->Delete->UseVisualStyleBackColor = true;
			this->Delete->Click += gcnew System::EventHandler(this, &Buyers::Delete_Click);
			// 
			// ToggleChangesOff
			// 
			this->ToggleChangesOff->Location = System::Drawing::Point(186, 64);
			this->ToggleChangesOff->Name = L"ToggleChangesOff";
			this->ToggleChangesOff->Size = System::Drawing::Size(109, 35);
			this->ToggleChangesOff->TabIndex = 25;
			this->ToggleChangesOff->Text = L"Запретить изменения";
			this->ToggleChangesOff->UseVisualStyleBackColor = true;
			this->ToggleChangesOff->Click += gcnew System::EventHandler(this, &Buyers::ToggleChangesOff_Click);
			// 
			// Save
			// 
			this->Save->Location = System::Drawing::Point(382, 12);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(98, 20);
			this->Save->TabIndex = 24;
			this->Save->Text = L"Сохранить";
			this->Save->UseVisualStyleBackColor = true;
			this->Save->Click += gcnew System::EventHandler(this, &Buyers::Save_Click);
			// 
			// Add
			// 
			this->Add->Location = System::Drawing::Point(382, 38);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(98, 20);
			this->Add->TabIndex = 23;
			this->Add->Text = L"Добавить";
			this->Add->UseVisualStyleBackColor = true;
			this->Add->Click += gcnew System::EventHandler(this, &Buyers::Add_Click);
			// 
			// Prev
			// 
			this->Prev->Location = System::Drawing::Point(-106, 162);
			this->Prev->Name = L"Prev";
			this->Prev->Size = System::Drawing::Size(75, 23);
			this->Prev->TabIndex = 22;
			this->Prev->Text = L"Назад";
			this->Prev->UseVisualStyleBackColor = true;
			// 
			// Next
			// 
			this->Next->Location = System::Drawing::Point(301, 64);
			this->Next->Name = L"Next";
			this->Next->Size = System::Drawing::Size(75, 35);
			this->Next->TabIndex = 21;
			this->Next->Text = L"Вперед";
			this->Next->UseVisualStyleBackColor = true;
			this->Next->Click += gcnew System::EventHandler(this, &Buyers::Next_Click);
			// 
			// Exit
			// 
			this->Exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Exit->Location = System::Drawing::Point(471, 117);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(75, 23);
			this->Exit->TabIndex = 20;
			this->Exit->Text = L"Выход";
			this->Exit->UseVisualStyleBackColor = false;
			this->Exit->Click += gcnew System::EventHandler(this, &Buyers::Exit_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(105, 64);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 35);
			this->button1->TabIndex = 27;
			this->button1->Text = L"Назад";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Buyers::button1_Click);
			// 
			// ToggleChanges
			// 
			this->ToggleChanges->Location = System::Drawing::Point(186, 64);
			this->ToggleChanges->Name = L"ToggleChanges";
			this->ToggleChanges->Size = System::Drawing::Size(109, 35);
			this->ToggleChanges->TabIndex = 28;
			this->ToggleChanges->Text = L"Разрешить изменения";
			this->ToggleChanges->UseVisualStyleBackColor = true;
			this->ToggleChanges->Click += gcnew System::EventHandler(this, &Buyers::ToggleChanges_Click);
			// 
			// Buyers
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(558, 146);
			this->Controls->Add(this->ToggleChanges);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Delete);
			this->Controls->Add(this->ToggleChangesOff);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->Prev);
			this->Controls->Add(this->Next);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->PhoneBox);
			this->Controls->Add(this->NameBox);
			this->Name = L"Buyers";
			this->Text = L"Buyers";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Buyers::Buyers_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Buyers::Buyers_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Buyers_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Buyers_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void NameBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void NameBox_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void NameBox_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Next_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToggleChanges_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Delete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
