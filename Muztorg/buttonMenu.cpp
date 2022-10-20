#include "buttonMenu.h"
#include "Buyers.h"
#include "BuyersSales_Report.h"
#include "Employees.h"
#include "EmployeesSales_Report.h"
#include "EmployeesSupplies_Report.h"
#include "Guitars.h"
#include "GuitarsSales_Report.h"
#include "GuitarsSupplies_Report.h"
#include "Sales.h"
#include "Supplies.h"
#include "Check_Report.h"
#include "StructOfSales.h"
#include "StructOfSupplies.h"


#define BUYERS "buyers.txt"
#define EMPLOYEES "employees.txt"
#define GUITARS "guitars_list.txt"
#define SUPPSTRUCT "struct_of_supplies.txt"
#define SALESTRUCT "struct_of_sales.txt"
#define SALES "sales.txt"
#define SUPPLIES "supplies.txt"


using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Muztorg::buttonMenu form;
	Application::Run(% form);
	return 0;
}

System::Void Muztorg::buttonMenu::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	return System::Void();
}

System::Void Muztorg::buttonMenu::buttonMenu_Load(System::Object^ sender, System::EventArgs^ e)
{
	Buyer bValue;
	Employee eValue;
	Guitar gValue;
	Sale sValue;
	StructOfSale stslValue;
	Supply supValue;
	StructOfSupply stspValue;
	this->BuyerBase->listFromFile(bValue, BUYERS);
	this->EmployeeBase->listFromFile(eValue, EMPLOYEES);
	this->GuitarBase->listFromFile(gValue, GUITARS);
	this->SaleBase->listFromFile(sValue, SALES);
	this->SaleBase->set_Pointers(BuyerBase, EmployeeBase);
	this->StructOfSaleBase->listFromFile(stslValue, SALESTRUCT);
	this->StructOfSaleBase->set_Pointers(SaleBase, GuitarBase);
	this->SupplyBase->listFromFile(supValue, SUPPLIES);
	this->SupplyBase->set_Pointers(EmployeeBase);
	this->StructOfSupplyBase->listFromFile(stspValue, SUPPSTRUCT);
	this->StructOfSupplyBase->set_Pointers(SupplyBase, GuitarBase);
	return System::Void();
}

System::Void Muztorg::buttonMenu::buttonMenu_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	Buyer bValue;
	Employee eValue;
	Guitar gValue;
	Sale sValue;
	StructOfSale stslValue;
	Supply supValue;
	StructOfSupply stspValue;
	this->BuyerBase->listToFile(bValue, BUYERS);
	this->EmployeeBase->listToFile(eValue, EMPLOYEES);
	this->GuitarBase->listToFile(gValue, GUITARS);
	this->SaleBase->update_Pointers();
	this->SaleBase->listToFile(sValue, SALES);
	this->StructOfSaleBase->update_Pointers();
	this->StructOfSaleBase->listToFile(stslValue, SALESTRUCT);
	this->SupplyBase->update_Pointers();
	this->SupplyBase->listToFile(supValue, SUPPLIES);
	this->StructOfSupplyBase->update_Pointers();
	this->StructOfSupplyBase->listToFile(stspValue, SUPPSTRUCT);
	return System::Void();
}

System::Void Muztorg::buttonMenu::buttonMenu_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	Application::Exit();
	return System::Void();
}

System::Void Muztorg::buttonMenu::GuitarsButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Muztorg::Guitars^ form = gcnew Guitars();
	form->set_BuyerBase(this->BuyerBase);
	form->set_EmployeeBase(this->EmployeeBase);
	form->set_GuitarBase(this->GuitarBase);
	form->set_SaleBase(this->SaleBase);
	form->set_StructOfSaleBase(this->StructOfSaleBase);
	form->set_SupplyBase(this->SupplyBase);
	form->set_StructsOfSupplyBase(this->StructOfSupplyBase);
	this->Hide();
	form->Show();
	return System::Void();
}

System::Void Muztorg::buttonMenu::SuppliesButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Muztorg::Supplies^ form = gcnew Supplies();
	form->set_BuyerBase(this->BuyerBase);
	form->set_EmployeeBase(this->EmployeeBase);
	form->set_GuitarBase(this->GuitarBase);
	form->set_SaleBase(this->SaleBase);
	form->set_StructOfSaleBase(this->StructOfSaleBase);
	form->set_SupplyBase(this->SupplyBase);
	form->set_StructsOfSuppliesBase(this->StructOfSupplyBase);
	this->Hide();
	form->Show();
	return System::Void();
}

System::Void Muztorg::buttonMenu::SalesButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Muztorg::Sales^ form = gcnew Sales();
	form->set_BuyerBase(this->BuyerBase);
	form->set_EmployeeBase(this->EmployeeBase);
	form->set_GuitarBase(this->GuitarBase);
	form->set_SaleBase(this->SaleBase);
	form->set_StructOfSaleBase(this->StructOfSaleBase);
	form->set_SupplyBase(this->SupplyBase);
	form->set_StructsOfSuppliesBase(this->StructOfSupplyBase);
	this->Hide();
	form->Show();
	return System::Void();
}

System::Void Muztorg::buttonMenu::BuyersButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Muztorg::Buyers^ form = gcnew Buyers();
	form->set_BuyerBase(this->BuyerBase);
	form->set_EmployeeBase(this->EmployeeBase);
	form->set_GuitarBase(this->GuitarBase);
	form->set_SaleBase(this->SaleBase);
	form->set_StructOfSaleBase(this->StructOfSaleBase);
	form->set_SupplyBase(this->SupplyBase);
	form->set_StructsOfSuppliesBase(this->StructOfSupplyBase);
	this->Hide();
	form->Show();
	return System::Void();
}

System::Void Muztorg::buttonMenu::EmployeesButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Muztorg::Employees^ form = gcnew Employees();
	form->set_BuyerBase(this->BuyerBase);
	form->set_EmployeeBase(this->EmployeeBase);
	form->set_GuitarBase(this->GuitarBase);
	form->set_SaleBase(this->SaleBase);
	form->set_StructOfSaleBase(this->StructOfSaleBase);
	form->set_SupplyBase(this->SupplyBase);
	form->set_StructsOfSuppliesBase(this->StructOfSupplyBase);
	this->Hide();
	form->Show();
	return System::Void();
}
