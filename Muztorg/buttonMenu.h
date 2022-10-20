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
	private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(buttonMenu::typeid));
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->GuitarsButton = (gcnew System::Windows::Forms::Button());
			this->SuppliesButton = (gcnew System::Windows::Forms::Button());
			this->SalesButton = (gcnew System::Windows::Forms::Button());
			this->BuyersButton = (gcnew System::Windows::Forms::Button());
			this->EmployeesButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// Exit
			// 
			this->Exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Exit->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Exit->Location = System::Drawing::Point(12, 257);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(167, 30);
			this->Exit->TabIndex = 0;
			this->Exit->Text = L"Выход";
			this->Exit->UseVisualStyleBackColor = false;
			this->Exit->Click += gcnew System::EventHandler(this, &buttonMenu::Exit_Click);
			// 
			// GuitarsButton
			// 
			this->GuitarsButton->BackColor = System::Drawing::Color::DarkCyan;
			this->GuitarsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GuitarsButton->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->GuitarsButton->Location = System::Drawing::Point(12, 77);
			this->GuitarsButton->Name = L"GuitarsButton";
			this->GuitarsButton->Size = System::Drawing::Size(167, 30);
			this->GuitarsButton->TabIndex = 1;
			this->GuitarsButton->Text = L"Товары";
			this->GuitarsButton->UseVisualStyleBackColor = false;
			this->GuitarsButton->Click += gcnew System::EventHandler(this, &buttonMenu::GuitarsButton_Click);
			// 
			// SuppliesButton
			// 
			this->SuppliesButton->BackColor = System::Drawing::Color::DarkCyan;
			this->SuppliesButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SuppliesButton->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->SuppliesButton->Location = System::Drawing::Point(12, 221);
			this->SuppliesButton->Name = L"SuppliesButton";
			this->SuppliesButton->Size = System::Drawing::Size(167, 30);
			this->SuppliesButton->TabIndex = 2;
			this->SuppliesButton->Text = L"Поставки";
			this->SuppliesButton->UseVisualStyleBackColor = false;
			this->SuppliesButton->Click += gcnew System::EventHandler(this, &buttonMenu::SuppliesButton_Click);
			// 
			// SalesButton
			// 
			this->SalesButton->BackColor = System::Drawing::Color::DarkCyan;
			this->SalesButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SalesButton->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->SalesButton->Location = System::Drawing::Point(12, 185);
			this->SalesButton->Name = L"SalesButton";
			this->SalesButton->Size = System::Drawing::Size(167, 30);
			this->SalesButton->TabIndex = 4;
			this->SalesButton->Text = L"Продажи";
			this->SalesButton->UseVisualStyleBackColor = false;
			this->SalesButton->Click += gcnew System::EventHandler(this, &buttonMenu::SalesButton_Click);
			// 
			// BuyersButton
			// 
			this->BuyersButton->BackColor = System::Drawing::Color::DarkCyan;
			this->BuyersButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BuyersButton->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->BuyersButton->Location = System::Drawing::Point(12, 113);
			this->BuyersButton->Name = L"BuyersButton";
			this->BuyersButton->Size = System::Drawing::Size(167, 30);
			this->BuyersButton->TabIndex = 3;
			this->BuyersButton->Text = L"Клиенты";
			this->BuyersButton->UseVisualStyleBackColor = false;
			this->BuyersButton->Click += gcnew System::EventHandler(this, &buttonMenu::BuyersButton_Click);
			// 
			// EmployeesButton
			// 
			this->EmployeesButton->BackColor = System::Drawing::Color::DarkCyan;
			this->EmployeesButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->EmployeesButton->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->EmployeesButton->Location = System::Drawing::Point(12, 149);
			this->EmployeesButton->Name = L"EmployeesButton";
			this->EmployeesButton->Size = System::Drawing::Size(167, 30);
			this->EmployeesButton->TabIndex = 5;
			this->EmployeesButton->Text = L"Сотрудники";
			this->EmployeesButton->UseVisualStyleBackColor = false;
			this->EmployeesButton->Click += gcnew System::EventHandler(this, &buttonMenu::EmployeesButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.ErrorImage")));
			this->pictureBox1->ImageLocation = L"D:\\Филиповский\\Muztorg\\Muztorg\\Слой3.png";
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(-7, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(206, 62);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// buttonMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(192, 306);
			this->ControlBox = false;
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->EmployeesButton);
			this->Controls->Add(this->SuppliesButton);
			this->Controls->Add(this->SalesButton);
			this->Controls->Add(this->BuyersButton);
			this->Controls->Add(this->GuitarsButton);
			this->Controls->Add(this->Exit);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"buttonMenu";
			this->ShowIcon = false;
			this->Text = L"Меню";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &buttonMenu::buttonMenu_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &buttonMenu::buttonMenu_FormClosed);
			this->Load += gcnew System::EventHandler(this, &buttonMenu::buttonMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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
