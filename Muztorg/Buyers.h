#pragma once
#include "buttonMenu.h"
#include "BuyersSales_Report.h"

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
	private: System::Windows::Forms::Button^ ToggleChangesOff;
	private: System::Windows::Forms::Button^ ToggleChanges;
	private: System::Windows::Forms::Button^ Save;
	private: System::Windows::Forms::Button^ Add;
	private: System::Windows::Forms::Button^ PurchaseReport;
	private: System::Windows::Forms::Button^ Exit;
	private: System::Windows::Forms::Button^ Prev;
	private: System::Windows::Forms::Button^ Next;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Buyers::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PhoneBox = (gcnew System::Windows::Forms::TextBox());
			this->NameBox = (gcnew System::Windows::Forms::TextBox());
			this->ToggleChangesOff = (gcnew System::Windows::Forms::Button());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->ToggleChanges = (gcnew System::Windows::Forms::Button());
			this->PurchaseReport = (gcnew System::Windows::Forms::Button());
			this->Prev = (gcnew System::Windows::Forms::Button());
			this->Next = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(17, 131);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 21);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Телефон:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(17, 99);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 21);
			this->label1->TabIndex = 18;
			this->label1->Text = L"ФИО клиента:";
			// 
			// PhoneBox
			// 
			this->PhoneBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->PhoneBox->Location = System::Drawing::Point(153, 131);
			this->PhoneBox->Name = L"PhoneBox";
			this->PhoneBox->ReadOnly = true;
			this->PhoneBox->Size = System::Drawing::Size(325, 23);
			this->PhoneBox->TabIndex = 17;
			this->PhoneBox->TextChanged += gcnew System::EventHandler(this, &Buyers::Box_TextChanged);
			this->PhoneBox->Enter += gcnew System::EventHandler(this, &Buyers::Box_Enter);
			this->PhoneBox->Leave += gcnew System::EventHandler(this, &Buyers::Box_Leave);
			// 
			// NameBox
			// 
			this->NameBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->NameBox->Location = System::Drawing::Point(153, 99);
			this->NameBox->Name = L"NameBox";
			this->NameBox->ReadOnly = true;
			this->NameBox->Size = System::Drawing::Size(325, 23);
			this->NameBox->TabIndex = 16;
			this->NameBox->TextChanged += gcnew System::EventHandler(this, &Buyers::Box_TextChanged);
			this->NameBox->Enter += gcnew System::EventHandler(this, &Buyers::Box_Enter);
			this->NameBox->Leave += gcnew System::EventHandler(this, &Buyers::Box_Leave);
			// 
			// ToggleChangesOff
			// 
			this->ToggleChangesOff->BackColor = System::Drawing::Color::DarkCyan;
			this->ToggleChangesOff->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ToggleChangesOff->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->ToggleChangesOff->Location = System::Drawing::Point(174, 24);
			this->ToggleChangesOff->Name = L"ToggleChangesOff";
			this->ToggleChangesOff->Size = System::Drawing::Size(167, 60);
			this->ToggleChangesOff->TabIndex = 25;
			this->ToggleChangesOff->Text = L"Запретить изменения";
			this->ToggleChangesOff->UseVisualStyleBackColor = false;
			this->ToggleChangesOff->Click += gcnew System::EventHandler(this, &Buyers::ToggleChangesOff_Click);
			// 
			// Save
			// 
			this->Save->BackColor = System::Drawing::Color::MediumSeaGreen;
			this->Save->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Save->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Save->Location = System::Drawing::Point(347, 24);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(131, 27);
			this->Save->TabIndex = 24;
			this->Save->Text = L"Сохранить";
			this->Save->UseVisualStyleBackColor = false;
			this->Save->Click += gcnew System::EventHandler(this, &Buyers::Save_Click);
			// 
			// Add
			// 
			this->Add->BackColor = System::Drawing::Color::Gold;
			this->Add->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Add->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Add->Location = System::Drawing::Point(347, 57);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(131, 27);
			this->Add->TabIndex = 23;
			this->Add->Text = L"Добавить";
			this->Add->UseVisualStyleBackColor = false;
			this->Add->Click += gcnew System::EventHandler(this, &Buyers::Add_Click);
			// 
			// ToggleChanges
			// 
			this->ToggleChanges->BackColor = System::Drawing::Color::DarkCyan;
			this->ToggleChanges->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ToggleChanges->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->ToggleChanges->Location = System::Drawing::Point(174, 24);
			this->ToggleChanges->Name = L"ToggleChanges";
			this->ToggleChanges->Size = System::Drawing::Size(167, 60);
			this->ToggleChanges->TabIndex = 28;
			this->ToggleChanges->Text = L"Разрешить изменения";
			this->ToggleChanges->UseVisualStyleBackColor = false;
			this->ToggleChanges->Click += gcnew System::EventHandler(this, &Buyers::ToggleChanges_Click);
			// 
			// PurchaseReport
			// 
			this->PurchaseReport->BackColor = System::Drawing::Color::DarkCyan;
			this->PurchaseReport->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PurchaseReport->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->PurchaseReport->Location = System::Drawing::Point(21, 24);
			this->PurchaseReport->Name = L"PurchaseReport";
			this->PurchaseReport->Size = System::Drawing::Size(147, 60);
			this->PurchaseReport->TabIndex = 33;
			this->PurchaseReport->Text = L"Отчёт по покупкам";
			this->PurchaseReport->UseVisualStyleBackColor = false;
			this->PurchaseReport->Click += gcnew System::EventHandler(this, &Buyers::PurchaseReport_Click);
			// 
			// Prev
			// 
			this->Prev->BackColor = System::Drawing::Color::DarkCyan;
			this->Prev->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Prev->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Prev->Location = System::Drawing::Point(74, 174);
			this->Prev->Name = L"Prev";
			this->Prev->Size = System::Drawing::Size(114, 29);
			this->Prev->TabIndex = 27;
			this->Prev->Text = L"PREV";
			this->Prev->UseVisualStyleBackColor = false;
			this->Prev->Click += gcnew System::EventHandler(this, &Buyers::Prev_Click);
			// 
			// Next
			// 
			this->Next->BackColor = System::Drawing::Color::DarkCyan;
			this->Next->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Next->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Next->Location = System::Drawing::Point(194, 174);
			this->Next->Name = L"Next";
			this->Next->Size = System::Drawing::Size(114, 29);
			this->Next->TabIndex = 21;
			this->Next->Text = L"NEXT";
			this->Next->UseVisualStyleBackColor = false;
			this->Next->Click += gcnew System::EventHandler(this, &Buyers::Next_Click);
			// 
			// Exit
			// 
			this->Exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Exit->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Exit->Location = System::Drawing::Point(314, 174);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(114, 29);
			this->Exit->TabIndex = 20;
			this->Exit->Text = L"EXIT";
			this->Exit->UseVisualStyleBackColor = false;
			this->Exit->Click += gcnew System::EventHandler(this, &Buyers::Exit_Click);
			// 
			// Buyers
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(502, 226);
			this->Controls->Add(this->PurchaseReport);
			this->Controls->Add(this->ToggleChanges);
			this->Controls->Add(this->Prev);
			this->Controls->Add(this->ToggleChangesOff);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->Next);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->PhoneBox);
			this->Controls->Add(this->NameBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Buyers";
			this->Text = L"Покупатели";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Buyers::Buyers_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Buyers::Buyers_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Buyers_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Buyers_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void Box_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Box_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Box_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Next_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Prev_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToggleChanges_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void PurchaseReport_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
