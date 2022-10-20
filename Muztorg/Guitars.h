#pragma once
#include "buttonMenu.h"
#include "GuitarsSales_Report.h"
#include "GuitarsSupplies_Report.h"

namespace Muztorg {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <sumOfSale>
	/// Сводка для Guitars
	/// </sumOfSale>
	public ref class Guitars : public System::Windows::Forms::Form
	{
	public:
		Guitars(void)
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
		~Guitars()
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

		Unit<Guitar>* CurrentPtr;

		bool DataChanged;
		bool BoxActive;
		bool AddMode;

	private: System::Windows::Forms::Button^ ToggleChanges;
	private: System::Windows::Forms::Button^ ToggleChangesOff;
	private: System::Windows::Forms::Button^ Save;

	private: System::Windows::Forms::Button^ Add;
	private: System::Windows::Forms::Button^ Prev;
	private: System::Windows::Forms::Button^ Next;
	private: System::Windows::Forms::Button^ Exit;
	private: System::Windows::Forms::Button^ SalesReportButton;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ PriceBox;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ DescriptionBox;
	private: System::Windows::Forms::TextBox^ ColorBox;
	private: System::Windows::Forms::TextBox^ FormBox;
	private: System::Windows::Forms::TextBox^ FretsBox;

	private: System::Windows::Forms::TextBox^ MaterialBox;
	private: System::Windows::Forms::TextBox^ BeakerBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	public: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::Button^ SuppliesGuitarButton;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ CountBox;
	private: System::Windows::Forms::TextBox^ TitleBox;


	public:

		void set_BuyerBase(List<Buyer>* value) { this->BuyerBase = value; }
		void set_EmployeeBase(List<Employee>* value) { this->EmployeeBase = value; }
		void set_GuitarBase(List<Guitar>* value) { this->GuitarBase = value; }
		void set_SaleBase(Sales_list* value) { this->SaleBase = value; }
		void set_StructOfSaleBase(StructsOfSales_list* value) { this->StructOfSaleBase = value; }
		void set_SupplyBase(Supplies_list* value) { this->SupplyBase = value; }
		void set_StructsOfSupplyBase(StructsOfSupplies_list* value) { this->StructOfSupplyBase = value; }

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Guitars::typeid));
			this->ToggleChangesOff = (gcnew System::Windows::Forms::Button());
			this->ToggleChanges = (gcnew System::Windows::Forms::Button());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->Prev = (gcnew System::Windows::Forms::Button());
			this->Next = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->SalesReportButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TitleBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PriceBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->DescriptionBox = (gcnew System::Windows::Forms::TextBox());
			this->ColorBox = (gcnew System::Windows::Forms::TextBox());
			this->FormBox = (gcnew System::Windows::Forms::TextBox());
			this->FretsBox = (gcnew System::Windows::Forms::TextBox());
			this->MaterialBox = (gcnew System::Windows::Forms::TextBox());
			this->BeakerBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->SuppliesGuitarButton = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->CountBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ToggleChangesOff
			// 
			this->ToggleChangesOff->BackColor = System::Drawing::Color::DarkCyan;
			this->ToggleChangesOff->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ToggleChangesOff->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->ToggleChangesOff->Location = System::Drawing::Point(734, 26);
			this->ToggleChangesOff->Name = L"ToggleChangesOff";
			this->ToggleChangesOff->Size = System::Drawing::Size(104, 61);
			this->ToggleChangesOff->TabIndex = 20;
			this->ToggleChangesOff->Text = L"Запретить изменения";
			this->ToggleChangesOff->UseVisualStyleBackColor = false;
			this->ToggleChangesOff->Click += gcnew System::EventHandler(this, &Guitars::ToggleChangesOff_Click);
			// 
			// ToggleChanges
			// 
			this->ToggleChanges->BackColor = System::Drawing::Color::DarkCyan;
			this->ToggleChanges->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ToggleChanges->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->ToggleChanges->Location = System::Drawing::Point(733, 26);
			this->ToggleChanges->Name = L"ToggleChanges";
			this->ToggleChanges->Size = System::Drawing::Size(104, 61);
			this->ToggleChanges->TabIndex = 18;
			this->ToggleChanges->Text = L"Разрешить изменения";
			this->ToggleChanges->UseVisualStyleBackColor = false;
			this->ToggleChanges->Click += gcnew System::EventHandler(this, &Guitars::ToggleChanges_Click);
			// 
			// Save
			// 
			this->Save->BackColor = System::Drawing::Color::MediumSeaGreen;
			this->Save->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Save->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Save->Location = System::Drawing::Point(843, 26);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(109, 31);
			this->Save->TabIndex = 19;
			this->Save->Text = L"Сохранить";
			this->Save->UseVisualStyleBackColor = false;
			this->Save->Click += gcnew System::EventHandler(this, &Guitars::Save_Click);
			// 
			// Add
			// 
			this->Add->BackColor = System::Drawing::Color::Gold;
			this->Add->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Add->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Add->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->Add->Location = System::Drawing::Point(844, 58);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(108, 29);
			this->Add->TabIndex = 17;
			this->Add->Text = L"Добавить";
			this->Add->UseVisualStyleBackColor = false;
			this->Add->Click += gcnew System::EventHandler(this, &Guitars::Add_Click);
			// 
			// Prev
			// 
			this->Prev->BackColor = System::Drawing::Color::DarkCyan;
			this->Prev->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Prev->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Prev->Location = System::Drawing::Point(228, 391);
			this->Prev->Name = L"Prev";
			this->Prev->Size = System::Drawing::Size(177, 29);
			this->Prev->TabIndex = 16;
			this->Prev->Text = L"PREV";
			this->Prev->UseVisualStyleBackColor = false;
			this->Prev->DoubleClick += gcnew System::EventHandler(this, &Guitars::Prev_Click);
			this->Prev->Click += gcnew System::EventHandler(this, &Guitars::Prev_Click);
			// 
			// Next
			// 
			this->Next->BackColor = System::Drawing::Color::DarkCyan;
			this->Next->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Next->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Next->Location = System::Drawing::Point(411, 391);
			this->Next->Name = L"Next";
			this->Next->Size = System::Drawing::Size(177, 29);
			this->Next->TabIndex = 15;
			this->Next->Text = L"NEXT";
			this->Next->UseVisualStyleBackColor = false;
			this->Next->DoubleClick += gcnew System::EventHandler(this, &Guitars::Next_Click);
			this->Next->Click += gcnew System::EventHandler(this, &Guitars::Next_Click);
			// 
			// Exit
			// 
			this->Exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->Exit->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Exit->Location = System::Drawing::Point(594, 391);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(177, 29);
			this->Exit->TabIndex = 14;
			this->Exit->Text = L"EXIT";
			this->Exit->UseVisualStyleBackColor = false;
			this->Exit->Click += gcnew System::EventHandler(this, &Guitars::Exit_Click);
			// 
			// SalesReportButton
			// 
			this->SalesReportButton->BackColor = System::Drawing::Color::DarkCyan;
			this->SalesReportButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SalesReportButton->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->SalesReportButton->Location = System::Drawing::Point(513, 26);
			this->SalesReportButton->Name = L"SalesReportButton";
			this->SalesReportButton->Size = System::Drawing::Size(104, 61);
			this->SalesReportButton->TabIndex = 22;
			this->SalesReportButton->Text = L"Продажи по товару";
			this->SalesReportButton->UseVisualStyleBackColor = false;
			this->SalesReportButton->Click += gcnew System::EventHandler(this, &Guitars::SalesReportButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label2->Location = System::Drawing::Point(21, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 21);
			this->label2->TabIndex = 24;
			this->label2->Text = L"Название:";
			// 
			// TitleBox
			// 
			this->TitleBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->TitleBox->Location = System::Drawing::Point(172, 30);
			this->TitleBox->Name = L"TitleBox";
			this->TitleBox->Size = System::Drawing::Size(325, 23);
			this->TitleBox->TabIndex = 31;
			this->TitleBox->TextChanged += gcnew System::EventHandler(this, &Guitars::Box_TextChanged);
			this->TitleBox->Enter += gcnew System::EventHandler(this, &Guitars::Box_Enter);
			this->TitleBox->Leave += gcnew System::EventHandler(this, &Guitars::Box_Leave);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(21, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 21);
			this->label1->TabIndex = 32;
			this->label1->Text = L"Цена:";
			// 
			// PriceBox
			// 
			this->PriceBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->PriceBox->Location = System::Drawing::Point(172, 62);
			this->PriceBox->Name = L"PriceBox";
			this->PriceBox->Size = System::Drawing::Size(325, 23);
			this->PriceBox->TabIndex = 33;
			this->PriceBox->TextChanged += gcnew System::EventHandler(this, &Guitars::Box_TextChanged);
			this->PriceBox->Enter += gcnew System::EventHandler(this, &Guitars::Box_Enter);
			this->PriceBox->Leave += gcnew System::EventHandler(this, &Guitars::Box_Leave);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(21, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 21);
			this->label3->TabIndex = 34;
			this->label3->Text = L"Описание:";
			// 
			// DescriptionBox
			// 
			this->DescriptionBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->DescriptionBox->Location = System::Drawing::Point(172, 105);
			this->DescriptionBox->Multiline = true;
			this->DescriptionBox->Name = L"DescriptionBox";
			this->DescriptionBox->Size = System::Drawing::Size(780, 147);
			this->DescriptionBox->TabIndex = 35;
			this->DescriptionBox->TextChanged += gcnew System::EventHandler(this, &Guitars::Box_TextChanged);
			this->DescriptionBox->Enter += gcnew System::EventHandler(this, &Guitars::Box_Enter);
			this->DescriptionBox->Leave += gcnew System::EventHandler(this, &Guitars::Box_Leave);
			// 
			// ColorBox
			// 
			this->ColorBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->ColorBox->Location = System::Drawing::Point(10, 67);
			this->ColorBox->Name = L"ColorBox";
			this->ColorBox->Size = System::Drawing::Size(232, 23);
			this->ColorBox->TabIndex = 36;
			this->ColorBox->TextChanged += gcnew System::EventHandler(this, &Guitars::Box_TextChanged);
			this->ColorBox->Enter += gcnew System::EventHandler(this, &Guitars::Box_Enter);
			this->ColorBox->Leave += gcnew System::EventHandler(this, &Guitars::Box_Leave);
			// 
			// FormBox
			// 
			this->FormBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->FormBox->Location = System::Drawing::Point(261, 67);
			this->FormBox->Name = L"FormBox";
			this->FormBox->Size = System::Drawing::Size(194, 23);
			this->FormBox->TabIndex = 37;
			this->FormBox->TextChanged += gcnew System::EventHandler(this, &Guitars::Box_TextChanged);
			this->FormBox->Enter += gcnew System::EventHandler(this, &Guitars::Box_Enter);
			this->FormBox->Leave += gcnew System::EventHandler(this, &Guitars::Box_Leave);
			// 
			// FretsBox
			// 
			this->FretsBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->FretsBox->Location = System::Drawing::Point(668, 67);
			this->FretsBox->Name = L"FretsBox";
			this->FretsBox->Size = System::Drawing::Size(136, 23);
			this->FretsBox->TabIndex = 39;
			this->FretsBox->TextChanged += gcnew System::EventHandler(this, &Guitars::Box_TextChanged);
			this->FretsBox->Enter += gcnew System::EventHandler(this, &Guitars::Box_Enter);
			this->FretsBox->Leave += gcnew System::EventHandler(this, &Guitars::Box_Leave);
			// 
			// MaterialBox
			// 
			this->MaterialBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->MaterialBox->Location = System::Drawing::Point(474, 67);
			this->MaterialBox->Name = L"MaterialBox";
			this->MaterialBox->Size = System::Drawing::Size(174, 23);
			this->MaterialBox->TabIndex = 38;
			this->MaterialBox->TextChanged += gcnew System::EventHandler(this, &Guitars::Box_TextChanged);
			this->MaterialBox->Enter += gcnew System::EventHandler(this, &Guitars::Box_Enter);
			this->MaterialBox->Leave += gcnew System::EventHandler(this, &Guitars::Box_Leave);
			// 
			// BeakerBox
			// 
			this->BeakerBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->BeakerBox->Location = System::Drawing::Point(823, 67);
			this->BeakerBox->Name = L"BeakerBox";
			this->BeakerBox->Size = System::Drawing::Size(87, 23);
			this->BeakerBox->TabIndex = 40;
			this->BeakerBox->TextChanged += gcnew System::EventHandler(this, &Guitars::Box_TextChanged);
			this->BeakerBox->Enter += gcnew System::EventHandler(this, &Guitars::Box_Enter);
			this->BeakerBox->Leave += gcnew System::EventHandler(this, &Guitars::Box_Leave);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label4->Location = System::Drawing::Point(664, 34);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(140, 21);
			this->label4->TabIndex = 41;
			this->label4->Text = L"Кол-во ладов:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label5->Location = System::Drawing::Point(6, 34);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(60, 21);
			this->label5->TabIndex = 42;
			this->label5->Text = L"Цвет:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label6->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label6->Location = System::Drawing::Point(257, 34);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(150, 21);
			this->label6->TabIndex = 43;
			this->label6->Text = L"Форма корпуса:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label7->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label7->Location = System::Drawing::Point(470, 34);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(180, 21);
			this->label7->TabIndex = 44;
			this->label7->Text = L"Материал корпуса:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label8->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label8->Location = System::Drawing::Point(819, 34);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(90, 21);
			this->label8->TabIndex = 45;
			this->label8->Text = L"Мензура:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->ColorBox);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->FormBox);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->MaterialBox);
			this->groupBox1->Controls->Add(this->FretsBox);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->BeakerBox);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->groupBox1->Location = System::Drawing::Point(25, 273);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(927, 100);
			this->groupBox1->TabIndex = 46;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Характеристики гитары:";
			// 
			// SuppliesGuitarButton
			// 
			this->SuppliesGuitarButton->BackColor = System::Drawing::Color::DarkCyan;
			this->SuppliesGuitarButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SuppliesGuitarButton->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->SuppliesGuitarButton->Location = System::Drawing::Point(623, 26);
			this->SuppliesGuitarButton->Name = L"SuppliesGuitarButton";
			this->SuppliesGuitarButton->Size = System::Drawing::Size(104, 61);
			this->SuppliesGuitarButton->TabIndex = 47;
			this->SuppliesGuitarButton->Text = L"Поставки по товару";
			this->SuppliesGuitarButton->UseVisualStyleBackColor = false;
			this->SuppliesGuitarButton->Click += gcnew System::EventHandler(this, &Guitars::SuppliesReportButton_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 12));
			this->label9->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label9->Location = System::Drawing::Point(21, 178);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(110, 21);
			this->label9->TabIndex = 48;
			this->label9->Text = L"В наличии:";
			// 
			// CountBox
			// 
			this->CountBox->Font = (gcnew System::Drawing::Font(L"Cascadia Mono ExtraLight", 9.75F));
			this->CountBox->Location = System::Drawing::Point(25, 211);
			this->CountBox->Name = L"CountBox";
			this->CountBox->Size = System::Drawing::Size(96, 23);
			this->CountBox->TabIndex = 49;
			// 
			// Guitars
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(974, 442);
			this->Controls->Add(this->CountBox);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->SuppliesGuitarButton);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->DescriptionBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->PriceBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TitleBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->SalesReportButton);
			this->Controls->Add(this->ToggleChangesOff);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->ToggleChanges);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->Prev);
			this->Controls->Add(this->Next);
			this->Controls->Add(this->Exit);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Guitars";
			this->Text = L"Гитары";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Guitars::Guitars_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Guitars::Guitars_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void Guitars_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Guitars_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void Box_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Box_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Box_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Prev_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Next_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e);
	//private: System::Void Delete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToggleChanges_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SalesReportButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SuppliesReportButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
