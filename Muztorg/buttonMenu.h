#pragma once
#include "Func.h"

namespace Muztorg {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <sumOfSale>
	/// Сводка для buttonMenu
	/// </sumOfSale>
	public ref class buttonMenu : public System::Windows::Forms::Form
	{
	public:
		buttonMenu(void)
		{
			InitializeComponent();
			BuyerBase = new List<Buyer>;
			EmployeeBase = new List<Employee>;
			GuitarBase = new List<Guitar>;
			SaleBase = new Sales_list;
			StructOfSaleBase = new StructsOfSales_list;
			SupplyBase = new  Supplies_list;
			StructOfSupplyBase = new StructsOfSupplies_list;
		}

	protected:
		/// <sumOfSale>
		/// Освободить все используемые ресурсы.
		/// </sumOfSale>
		~buttonMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Exit;
	protected:
	private:
		List<Buyer>* BuyerBase;
		List<Employee>* EmployeeBase;
		List<Guitar>* GuitarBase;
		Sales_list* SaleBase;
		StructsOfSales_list* StructOfSaleBase;
		Supplies_list* SupplyBase;
		StructsOfSupplies_list* StructOfSupplyBase;
	private: System::Windows::Forms::Button^ GuitarsButton;
	private: System::Windows::Forms::Button^ SuppliesButton;
	private: System::Windows::Forms::Button^ SalesButton;
	private: System::Windows::Forms::Button^ BuyersButton;
	private: System::Windows::Forms::Button^ EmployeesButton;

	protected:

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
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->GuitarsButton = (gcnew System::Windows::Forms::Button());
			this->SuppliesButton = (gcnew System::Windows::Forms::Button());
			this->SalesButton = (gcnew System::Windows::Forms::Button());
			this->BuyersButton = (gcnew System::Windows::Forms::Button());
			this->EmployeesButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Exit
			// 
			this->Exit->Location = System::Drawing::Point(113, 157);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(75, 23);
			this->Exit->TabIndex = 0;
			this->Exit->Text = L"Выход";
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &buttonMenu::Exit_Click);
			// 
			// GuitarsButton
			// 
			this->GuitarsButton->Location = System::Drawing::Point(92, 12);
			this->GuitarsButton->Name = L"GuitarsButton";
			this->GuitarsButton->Size = System::Drawing::Size(117, 23);
			this->GuitarsButton->TabIndex = 1;
			this->GuitarsButton->Text = L"Товары";
			this->GuitarsButton->UseVisualStyleBackColor = true;
			this->GuitarsButton->Click += gcnew System::EventHandler(this, &buttonMenu::GuitarsButton_Click);
			// 
			// SuppliesButton
			// 
			this->SuppliesButton->Location = System::Drawing::Point(92, 128);
			this->SuppliesButton->Name = L"SuppliesButton";
			this->SuppliesButton->Size = System::Drawing::Size(117, 23);
			this->SuppliesButton->TabIndex = 2;
			this->SuppliesButton->Text = L"Поставки";
			this->SuppliesButton->UseVisualStyleBackColor = true;
			this->SuppliesButton->Click += gcnew System::EventHandler(this, &buttonMenu::SuppliesButton_Click);
			// 
			// SalesButton
			// 
			this->SalesButton->Location = System::Drawing::Point(92, 99);
			this->SalesButton->Name = L"SalesButton";
			this->SalesButton->Size = System::Drawing::Size(117, 23);
			this->SalesButton->TabIndex = 4;
			this->SalesButton->Text = L"Продажи";
			this->SalesButton->UseVisualStyleBackColor = true;
			this->SalesButton->Click += gcnew System::EventHandler(this, &buttonMenu::SalesButton_Click);
			// 
			// BuyersButton
			// 
			this->BuyersButton->Location = System::Drawing::Point(92, 41);
			this->BuyersButton->Name = L"BuyersButton";
			this->BuyersButton->Size = System::Drawing::Size(117, 23);
			this->BuyersButton->TabIndex = 3;
			this->BuyersButton->Text = L"Клиенты";
			this->BuyersButton->UseVisualStyleBackColor = true;
			this->BuyersButton->Click += gcnew System::EventHandler(this, &buttonMenu::BuyersButton_Click);
			// 
			// EmployeesButton
			// 
			this->EmployeesButton->Location = System::Drawing::Point(92, 70);
			this->EmployeesButton->Name = L"EmployeesButton";
			this->EmployeesButton->Size = System::Drawing::Size(117, 23);
			this->EmployeesButton->TabIndex = 5;
			this->EmployeesButton->Text = L"Сотрудники";
			this->EmployeesButton->UseVisualStyleBackColor = true;
			this->EmployeesButton->Click += gcnew System::EventHandler(this, &buttonMenu::EmployeesButton_Click);
			// 
			// buttonMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(304, 202);
			this->Controls->Add(this->EmployeesButton);
			this->Controls->Add(this->SuppliesButton);
			this->Controls->Add(this->SalesButton);
			this->Controls->Add(this->BuyersButton);
			this->Controls->Add(this->GuitarsButton);
			this->Controls->Add(this->Exit);
			this->Name = L"buttonMenu";
			this->Text = L"buttonMenu";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &buttonMenu::buttonMenu_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &buttonMenu::buttonMenu_FormClosed);
			this->Load += gcnew System::EventHandler(this, &buttonMenu::buttonMenu_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonMenu_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonMenu_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void buttonMenu_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void GuitarsButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SuppliesButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SalesButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BuyersButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EmployeesButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
