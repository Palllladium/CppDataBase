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
	/// Сводка для StructOfSupply
	/// </summary>
	public ref class StructOfSupplies : public System::Windows::Forms::Form
	{
	public:
		StructOfSupplies(Unit<Supply>* data)
		{
			InitializeComponent();
			this->SearchedSupply = data;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~StructOfSupplies()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		Unit<Supply>* SearchedSupply;
		Unit<Unit<StructOfSupply>*>* CurrentPtr;
		List<Unit<StructOfSupply>*>* CurrentList;
		List<Buyer>* BuyerBase;
		List<Employee>* EmployeeBase;
		List<Guitar>* GuitarBase;
		Sales_list* SaleBase;
		StructsOfSales_list* StructOfSaleBase;
		Supplies_list* SupplyBase;
		StructsOfSupplies_list* StructOfSupplyBase;

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
	private: System::Windows::Forms::ComboBox^ TitleBox;
	private: System::Windows::Forms::TextBox^ AmountBox;

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
			this->ToggleChangesOff = (gcnew System::Windows::Forms::Button());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->Next = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->AmountBox = (gcnew System::Windows::Forms::TextBox());
			this->TitleBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// ToggleChanges
			// 
			this->ToggleChanges->BackColor = System::Drawing::Color::DarkCyan;
			this->ToggleChanges->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ToggleChanges->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->ToggleChanges->Location = System::Drawing::Point(26, 28);
			this->ToggleChanges->Name = L"ToggleChanges";
			this->ToggleChanges->Size = System::Drawing::Size(250, 60);
			this->ToggleChanges->TabIndex = 40;
			this->ToggleChanges->Text = L"Разрешить изменения";
			this->ToggleChanges->UseVisualStyleBackColor = false;
			this->ToggleChanges->Click += gcnew System::EventHandler(this, &StructOfSupplies::ToggleChanges_Click);
			// 
			// Prev
			// 
			this->Prev->BackColor = System::Drawing::Color::DarkCyan;
			this->Prev->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Prev->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Prev->Location = System::Drawing::Point(84, 178);
			this->Prev->Name = L"Prev";
			this->Prev->Size = System::Drawing::Size(114, 29);
			this->Prev->TabIndex = 39;
			this->Prev->Text = L"PREV";
			this->Prev->UseVisualStyleBackColor = false;
			this->Prev->Click += gcnew System::EventHandler(this, &StructOfSupplies::Prev_Click);
			// 
			// ToggleChangesOff
			// 
			this->ToggleChangesOff->BackColor = System::Drawing::Color::DarkCyan;
			this->ToggleChangesOff->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ToggleChangesOff->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->ToggleChangesOff->Location = System::Drawing::Point(26, 28);
			this->ToggleChangesOff->Name = L"ToggleChangesOff";
			this->ToggleChangesOff->Size = System::Drawing::Size(250, 60);
			this->ToggleChangesOff->TabIndex = 37;
			this->ToggleChangesOff->Text = L"Запретить изменения";
			this->ToggleChangesOff->UseVisualStyleBackColor = false;
			this->ToggleChangesOff->Click += gcnew System::EventHandler(this, &StructOfSupplies::ToggleChangesOff_Click);
			// 
			// Save
			// 
			this->Save->BackColor = System::Drawing::Color::MediumSeaGreen;
			this->Save->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Save->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Save->Location = System::Drawing::Point(282, 28);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(231, 29);
			this->Save->TabIndex = 36;
			this->Save->Text = L"Сохранить";
			this->Save->UseVisualStyleBackColor = false;
			this->Save->Click += gcnew System::EventHandler(this, &StructOfSupplies::Save_Click);
			// 
			// Add
			// 
			this->Add->BackColor = System::Drawing::Color::Gold;
			this->Add->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Add->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Add->Location = System::Drawing::Point(282, 59);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(231, 29);
			this->Add->TabIndex = 35;
			this->Add->Text = L"Добавить";
			this->Add->UseVisualStyleBackColor = false;
			this->Add->Click += gcnew System::EventHandler(this, &StructOfSupplies::Add_Click);
			// 
			// Next
			// 
			this->Next->BackColor = System::Drawing::Color::DarkCyan;
			this->Next->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Next->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Next->Location = System::Drawing::Point(204, 178);
			this->Next->Name = L"Next";
			this->Next->Size = System::Drawing::Size(114, 29);
			this->Next->TabIndex = 34;
			this->Next->Text = L"NEXT";
			this->Next->UseVisualStyleBackColor = false;
			this->Next->Click += gcnew System::EventHandler(this, &StructOfSupplies::Next_Click);
			// 
			// Exit
			// 
			this->Exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Exit->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Exit->Location = System::Drawing::Point(324, 178);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(114, 29);
			this->Exit->TabIndex = 33;
			this->Exit->Text = L"EXIT";
			this->Exit->UseVisualStyleBackColor = false;
			this->Exit->Click += gcnew System::EventHandler(this, &StructOfSupplies::Exit_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(22, 133);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 21);
			this->label2->TabIndex = 32;
			this->label2->Text = L"Кол-во:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(22, 102);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 21);
			this->label1->TabIndex = 31;
			this->label1->Text = L"Название:";
			// 
			// AmountBox
			// 
			this->AmountBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->AmountBox->Location = System::Drawing::Point(125, 133);
			this->AmountBox->Name = L"AmountBox";
			this->AmountBox->ReadOnly = true;
			this->AmountBox->Size = System::Drawing::Size(388, 23);
			this->AmountBox->TabIndex = 30;
			this->AmountBox->TextChanged += gcnew System::EventHandler(this, &StructOfSupplies::Box_TextChanged);
			this->AmountBox->Enter += gcnew System::EventHandler(this, &StructOfSupplies::Box_Enter);
			this->AmountBox->Leave += gcnew System::EventHandler(this, &StructOfSupplies::Box_Leave);
			// 
			// TitleBox
			// 
			this->TitleBox->BackColor = System::Drawing::SystemColors::Control;
			this->TitleBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->TitleBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->TitleBox->FormattingEnabled = true;
			this->TitleBox->Location = System::Drawing::Point(125, 102);
			this->TitleBox->Name = L"TitleBox";
			this->TitleBox->Size = System::Drawing::Size(388, 25);
			this->TitleBox->TabIndex = 42;
			// 
			// StructOfSupplies
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(538, 230);
			this->Controls->Add(this->TitleBox);
			this->Controls->Add(this->ToggleChanges);
			this->Controls->Add(this->Prev);
			this->Controls->Add(this->ToggleChangesOff);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->Next);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->AmountBox);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"StructOfSupplies";
			this->Text = L"Структура поставки";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &StructOfSupplies::StructOfSupplies_FormClosed);
			this->Load += gcnew System::EventHandler(this, &StructOfSupplies::StructOfSupplies_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ToggleChanges_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void StructOfSupplies_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void StructOfSupplies_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void Box_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Box_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Box_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Prev_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Next_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
