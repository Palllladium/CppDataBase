#pragma once
#include "buttonMenu.h"
#include "EmployeesSales_Report.h"
#include "EmployeesSupplies_Report.h"

namespace Muztorg {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <sumOfSale>
	/// ?????? ??? Employees
	/// </sumOfSale>
	public ref class Employees : public System::Windows::Forms::Form
	{
	public:
		Employees(void)
		{
			InitializeComponent();
			//
			//TODO: ???????? ??? ????????????
			//
		}

	protected:
		/// <sumOfSale>
		/// ?????????? ??? ???????????? ???????.
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
	private: System::Windows::Forms::Button^ SuppliesReport;
	private: System::Windows::Forms::Button^ SalesReport;
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
		/// ???????????? ?????????? ????????????.
		/// </sumOfSale>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <sumOfSale>
		/// ????????? ????? ??? ????????? ???????????? ? ?? ????????? 
		/// ?????????? ????? ?????? ? ??????? ????????? ????.
		/// </sumOfSale>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Employees::typeid));
			this->ToggleChanges = (gcnew System::Windows::Forms::Button());
			this->Prev = (gcnew System::Windows::Forms::Button());
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
			this->SuppliesReport = (gcnew System::Windows::Forms::Button());
			this->SalesReport = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ToggleChanges
			// 
			this->ToggleChanges->BackColor = System::Drawing::Color::DarkCyan;
			this->ToggleChanges->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ToggleChanges->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->ToggleChanges->Location = System::Drawing::Point(271, 28);
			this->ToggleChanges->Name = L"ToggleChanges";
			this->ToggleChanges->Size = System::Drawing::Size(116, 60);
			this->ToggleChanges->TabIndex = 40;
			this->ToggleChanges->Text = L"????????? ?????????";
			this->ToggleChanges->UseVisualStyleBackColor = false;
			this->ToggleChanges->Click += gcnew System::EventHandler(this, &Employees::ToggleChanges_Click);
			// 
			// Prev
			// 
			this->Prev->BackColor = System::Drawing::Color::DarkCyan;
			this->Prev->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Prev->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Prev->Location = System::Drawing::Point(84, 208);
			this->Prev->Name = L"Prev";
			this->Prev->Size = System::Drawing::Size(114, 29);
			this->Prev->TabIndex = 39;
			this->Prev->Text = L"PREV";
			this->Prev->UseVisualStyleBackColor = false;
			this->Prev->Click += gcnew System::EventHandler(this, &Employees::Prev_Click);
			// 
			// ToggleChangesOff
			// 
			this->ToggleChangesOff->BackColor = System::Drawing::Color::DarkCyan;
			this->ToggleChangesOff->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ToggleChangesOff->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->ToggleChangesOff->Location = System::Drawing::Point(271, 28);
			this->ToggleChangesOff->Name = L"ToggleChangesOff";
			this->ToggleChangesOff->Size = System::Drawing::Size(116, 60);
			this->ToggleChangesOff->TabIndex = 37;
			this->ToggleChangesOff->Text = L"????????? ?????????";
			this->ToggleChangesOff->UseVisualStyleBackColor = false;
			this->ToggleChangesOff->Click += gcnew System::EventHandler(this, &Employees::ToggleChangesOff_Click);
			// 
			// Save
			// 
			this->Save->BackColor = System::Drawing::Color::MediumSeaGreen;
			this->Save->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Save->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Save->Location = System::Drawing::Point(393, 28);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(120, 29);
			this->Save->TabIndex = 36;
			this->Save->Text = L"?????????";
			this->Save->UseVisualStyleBackColor = false;
			this->Save->Click += gcnew System::EventHandler(this, &Employees::Save_Click);
			// 
			// Add
			// 
			this->Add->BackColor = System::Drawing::Color::Gold;
			this->Add->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Add->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Add->Location = System::Drawing::Point(393, 59);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(120, 29);
			this->Add->TabIndex = 35;
			this->Add->Text = L"????????";
			this->Add->UseVisualStyleBackColor = false;
			this->Add->Click += gcnew System::EventHandler(this, &Employees::Add_Click);
			// 
			// Next
			// 
			this->Next->BackColor = System::Drawing::Color::DarkCyan;
			this->Next->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Next->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Next->Location = System::Drawing::Point(204, 208);
			this->Next->Name = L"Next";
			this->Next->Size = System::Drawing::Size(114, 29);
			this->Next->TabIndex = 34;
			this->Next->Text = L"NEXT";
			this->Next->UseVisualStyleBackColor = false;
			this->Next->Click += gcnew System::EventHandler(this, &Employees::Next_Click);
			// 
			// Exit
			// 
			this->Exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Exit->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Exit->Location = System::Drawing::Point(324, 208);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(114, 29);
			this->Exit->TabIndex = 33;
			this->Exit->Text = L"EXIT";
			this->Exit->UseVisualStyleBackColor = false;
			this->Exit->Click += gcnew System::EventHandler(this, &Employees::Exit_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(22, 165);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(160, 21);
			this->label2->TabIndex = 32;
			this->label2->Text = L"??? ??????????:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(22, 102);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(160, 21);
			this->label1->TabIndex = 31;
			this->label1->Text = L"??? ??????????:";
			// 
			// GenderBox
			// 
			this->GenderBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->GenderBox->Location = System::Drawing::Point(188, 165);
			this->GenderBox->Name = L"GenderBox";
			this->GenderBox->ReadOnly = true;
			this->GenderBox->Size = System::Drawing::Size(325, 23);
			this->GenderBox->TabIndex = 30;
			this->GenderBox->TextChanged += gcnew System::EventHandler(this, &Employees::Box_TextChanged);
			this->GenderBox->Enter += gcnew System::EventHandler(this, &Employees::Box_Enter);
			this->GenderBox->Leave += gcnew System::EventHandler(this, &Employees::Box_Leave);
			// 
			// NameBox
			// 
			this->NameBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->NameBox->Location = System::Drawing::Point(188, 102);
			this->NameBox->Name = L"NameBox";
			this->NameBox->ReadOnly = true;
			this->NameBox->Size = System::Drawing::Size(325, 23);
			this->NameBox->TabIndex = 29;
			this->NameBox->TextChanged += gcnew System::EventHandler(this, &Employees::Box_TextChanged);
			this->NameBox->Enter += gcnew System::EventHandler(this, &Employees::Box_Enter);
			this->NameBox->Leave += gcnew System::EventHandler(this, &Employees::Box_Leave);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(22, 134);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(150, 21);
			this->label3->TabIndex = 42;
			this->label3->Text = L"???? ????????:";
			// 
			// BDateMaskedBox
			// 
			this->BDateMaskedBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->BDateMaskedBox->Location = System::Drawing::Point(188, 134);
			this->BDateMaskedBox->Name = L"BDateMaskedBox";
			this->BDateMaskedBox->ReadOnly = true;
			this->BDateMaskedBox->Size = System::Drawing::Size(325, 23);
			this->BDateMaskedBox->TabIndex = 41;
			this->BDateMaskedBox->TextChanged += gcnew System::EventHandler(this, &Employees::Box_TextChanged);
			this->BDateMaskedBox->Enter += gcnew System::EventHandler(this, &Employees::Box_Enter);
			this->BDateMaskedBox->Leave += gcnew System::EventHandler(this, &Employees::Box_Leave);
			// 
			// SuppliesReport
			// 
			this->SuppliesReport->BackColor = System::Drawing::Color::DarkCyan;
			this->SuppliesReport->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SuppliesReport->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->SuppliesReport->Location = System::Drawing::Point(26, 28);
			this->SuppliesReport->Name = L"SuppliesReport";
			this->SuppliesReport->Size = System::Drawing::Size(115, 60);
			this->SuppliesReport->TabIndex = 43;
			this->SuppliesReport->Text = L"????? ?? ?????????";
			this->SuppliesReport->UseVisualStyleBackColor = false;
			this->SuppliesReport->Click += gcnew System::EventHandler(this, &Employees::SuppliesReport_Click);
			// 
			// SalesReport
			// 
			this->SalesReport->BackColor = System::Drawing::Color::DarkCyan;
			this->SalesReport->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SalesReport->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->SalesReport->Location = System::Drawing::Point(147, 28);
			this->SalesReport->Name = L"SalesReport";
			this->SalesReport->Size = System::Drawing::Size(118, 60);
			this->SalesReport->TabIndex = 44;
			this->SalesReport->Text = L"????? ?? ????????";
			this->SalesReport->UseVisualStyleBackColor = false;
			this->SalesReport->Click += gcnew System::EventHandler(this, &Employees::SalesReport_Click);
			// 
			// Employees
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(538, 266);
			this->Controls->Add(this->SalesReport);
			this->Controls->Add(this->SuppliesReport);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->BDateMaskedBox);
			this->Controls->Add(this->ToggleChanges);
			this->Controls->Add(this->Prev);
			this->Controls->Add(this->ToggleChangesOff);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->Next);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->GenderBox);
			this->Controls->Add(this->NameBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Employees";
			this->Text = L"??????????";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Employees::Employees_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Employees::Employees_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ToggleChanges_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Employees_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Employees_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void Box_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Box_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Box_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Prev_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Next_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SalesReport_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SuppliesReport_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
