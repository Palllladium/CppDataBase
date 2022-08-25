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
	/// Сводка для Employees
	/// </sumOfSale>
	public ref class Employees : public System::Windows::Forms::Form
	{
	public:
		Employees(void)
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
		~Employees()
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
		Unit<Employee>* CurrentPtr;
		bool DataChanged;
		bool BoxActive;
		bool AddMode;
	private: System::Windows::Forms::Button^ ToggleChanges;
	private: System::Windows::Forms::Button^ Prev;
	private: System::Windows::Forms::Button^ Delete;
	private: System::Windows::Forms::Button^ ToggleChangesOff;
	private: System::Windows::Forms::Button^ Save;
	private: System::Windows::Forms::Button^ Add;
	private: System::Windows::Forms::Button^ Next;
	private: System::Windows::Forms::Button^ Exit;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ GenderBox;

	private: System::Windows::Forms::TextBox^ NameBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ BDateMaskedBox;
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
			this->ToggleChanges = (gcnew System::Windows::Forms::Button());
			this->Prev = (gcnew System::Windows::Forms::Button());
			this->Delete = (gcnew System::Windows::Forms::Button());
			this->ToggleChangesOff = (gcnew System::Windows::Forms::Button());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->Next = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->GenderBox = (gcnew System::Windows::Forms::TextBox());
			this->NameBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->BDateMaskedBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// ToggleChanges
			// 
			this->ToggleChanges->Location = System::Drawing::Point(188, 90);
			this->ToggleChanges->Name = L"ToggleChanges";
			this->ToggleChanges->Size = System::Drawing::Size(109, 35);
			this->ToggleChanges->TabIndex = 40;
			this->ToggleChanges->Text = L"Разрешить изменения";
			this->ToggleChanges->UseVisualStyleBackColor = true;
			this->ToggleChanges->Click += gcnew System::EventHandler(this, &Employees::ToggleChanges_Click);
			// 
			// Prev
			// 
			this->Prev->Location = System::Drawing::Point(106, 90);
			this->Prev->Name = L"Prev";
			this->Prev->Size = System::Drawing::Size(75, 35);
			this->Prev->TabIndex = 39;
			this->Prev->Text = L"Назад";
			this->Prev->UseVisualStyleBackColor = true;
			this->Prev->Click += gcnew System::EventHandler(this, &Employees::Prev_Click);
			// 
			// Delete
			// 
			this->Delete->Location = System::Drawing::Point(384, 64);
			this->Delete->Name = L"Delete";
			this->Delete->Size = System::Drawing::Size(98, 20);
			this->Delete->TabIndex = 38;
			this->Delete->Text = L"Удалить";
			this->Delete->UseVisualStyleBackColor = true;
			this->Delete->Click += gcnew System::EventHandler(this, &Employees::Delete_Click);
			// 
			// ToggleChangesOff
			// 
			this->ToggleChangesOff->Location = System::Drawing::Point(188, 90);
			this->ToggleChangesOff->Name = L"ToggleChangesOff";
			this->ToggleChangesOff->Size = System::Drawing::Size(109, 35);
			this->ToggleChangesOff->TabIndex = 37;
			this->ToggleChangesOff->Text = L"Запретить изменения";
			this->ToggleChangesOff->UseVisualStyleBackColor = true;
			this->ToggleChangesOff->Click += gcnew System::EventHandler(this, &Employees::ToggleChangesOff_Click);
			// 
			// Save
			// 
			this->Save->Location = System::Drawing::Point(384, 12);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(98, 20);
			this->Save->TabIndex = 36;
			this->Save->Text = L"Сохранить";
			this->Save->UseVisualStyleBackColor = true;
			this->Save->Click += gcnew System::EventHandler(this, &Employees::Save_Click);
			// 
			// Add
			// 
			this->Add->Location = System::Drawing::Point(384, 38);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(98, 20);
			this->Add->TabIndex = 35;
			this->Add->Text = L"Добавить";
			this->Add->UseVisualStyleBackColor = true;
			this->Add->Click += gcnew System::EventHandler(this, &Employees::Add_Click);
			// 
			// Next
			// 
			this->Next->Location = System::Drawing::Point(303, 90);
			this->Next->Name = L"Next";
			this->Next->Size = System::Drawing::Size(75, 35);
			this->Next->TabIndex = 34;
			this->Next->Text = L"Вперед";
			this->Next->UseVisualStyleBackColor = true;
			this->Next->Click += gcnew System::EventHandler(this, &Employees::Next_Click);
			// 
			// Exit
			// 
			this->Exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Exit->Location = System::Drawing::Point(439, 118);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(75, 23);
			this->Exit->TabIndex = 33;
			this->Exit->Text = L"Выход";
			this->Exit->UseVisualStyleBackColor = false;
			this->Exit->Click += gcnew System::EventHandler(this, &Employees::Exit_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(27, 13);
			this->label2->TabIndex = 32;
			this->label2->Text = L"Пол";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 31;
			this->label1->Text = L"ФИО клиента";
			// 
			// GenderBox
			// 
			this->GenderBox->Location = System::Drawing::Point(107, 38);
			this->GenderBox->Name = L"GenderBox";
			this->GenderBox->ReadOnly = true;
			this->GenderBox->Size = System::Drawing::Size(271, 20);
			this->GenderBox->TabIndex = 30;
			this->GenderBox->TextChanged += gcnew System::EventHandler(this, &Employees::NameBox_TextChanged);
			this->GenderBox->Enter += gcnew System::EventHandler(this, &Employees::NameBox_Enter);
			this->GenderBox->Leave += gcnew System::EventHandler(this, &Employees::NameBox_Leave);
			// 
			// NameBox
			// 
			this->NameBox->Location = System::Drawing::Point(107, 12);
			this->NameBox->Name = L"NameBox";
			this->NameBox->ReadOnly = true;
			this->NameBox->Size = System::Drawing::Size(271, 20);
			this->NameBox->TabIndex = 29;
			this->NameBox->TextChanged += gcnew System::EventHandler(this, &Employees::NameBox_TextChanged);
			this->NameBox->Enter += gcnew System::EventHandler(this, &Employees::NameBox_Enter);
			this->NameBox->Leave += gcnew System::EventHandler(this, &Employees::NameBox_Leave);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 67);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 13);
			this->label3->TabIndex = 42;
			this->label3->Text = L"Дата рождения";
			// 
			// BDateMaskedBox
			// 
			this->BDateMaskedBox->Location = System::Drawing::Point(107, 64);
			this->BDateMaskedBox->Name = L"BDateMaskedBox";
			this->BDateMaskedBox->ReadOnly = true;
			this->BDateMaskedBox->Size = System::Drawing::Size(271, 20);
			this->BDateMaskedBox->TabIndex = 41;
			this->BDateMaskedBox->TextChanged += gcnew System::EventHandler(this, &Employees::NameBox_TextChanged);
			this->BDateMaskedBox->Enter += gcnew System::EventHandler(this, &Employees::NameBox_Enter);
			this->BDateMaskedBox->Leave += gcnew System::EventHandler(this, &Employees::NameBox_Leave);
			// 
			// Employees
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(526, 186);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->BDateMaskedBox);
			this->Controls->Add(this->ToggleChanges);
			this->Controls->Add(this->Prev);
			this->Controls->Add(this->Delete);
			this->Controls->Add(this->ToggleChangesOff);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->Next);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->GenderBox);
			this->Controls->Add(this->NameBox);
			this->Name = L"Employees";
			this->Text = L"Employees";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Employees::Employees_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Employees::Employees_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ToggleChanges_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Employees_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Employees_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void NameBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void NameBox_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void NameBox_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Prev_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Next_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Delete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
