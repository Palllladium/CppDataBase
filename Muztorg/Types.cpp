#include "Types.hpp"

void Buyer::fillElement(fstream& fin)
{
	string temp;
	getline(fin, temp);
	this->set_ID(stoi(temp));
	getline(fin, temp);
	this->set_FullName(temp);
	getline(fin, temp);
	this->set_PhoneNumber(temp);
}

void Buyer::printElement(fstream& fout)
{
	fout << this->get_ID() << "\n";
	fout << this->get_FullName() << "\n";
	fout << this->getPhoneNumber();
}

void Employee::fillElement(fstream& fin)
{
	string temp;
	getline(fin, temp);
	this->set_ID(stoi(temp));
	getline(fin, temp);
	this->set_FullName(temp);
	getline(fin, temp);
	this->set_Gender(temp);
	getline(fin, temp);
	this->set_BDate(temp);
}

void Employee::printElement(fstream& fout)
{
	fout << this->get_ID() << "\n";
	fout << this->get_FullName() << "\n";
	fout << this->get_Gender() << "\n";
	fout << this->get_BDate();
}

void Guitar::fillElement(fstream& fin)
{
	string temp;
	getline(fin, temp);
	this->set_ID(stoi(temp));
	getline(fin, temp);
	this->set_Title(temp);
	getline(fin, temp);
	this->set_Description(temp);
	getline(fin, temp);
	this->set_Price(temp);
	getline(fin, temp);
	this->set_Color(temp);
	getline(fin, temp);
	this->set_FormOfDeck(temp);
	getline(fin, temp);
	this->set_MaterialOfDeck (temp);
	getline(fin, temp);
	this->set_AmountOfFret(temp);
	getline(fin, temp);
	this->set_Beaker(temp);
}

void Guitar::printElement(fstream& fout)
{
	fout << this->get_ID() << "\n";
	fout << this->get_Title() << "\n";
	fout << this->get_Description() << "\n";
	fout << this->get_Price() << "\n";
	fout << this->get_Color() << "\n";
	fout << this->get_FormOfDeck() << "\n";
	fout << this->get_MaterialOfDeck() << "\n";
	fout << this->get_AmountOfFret() << "\n";
	fout << this->get_Beaker();
}

void Sale::fillElement(fstream& fin)
{
	string temp;
	getline(fin, temp);
	this->set_ID(stoi(temp));
	getline(fin, temp);
	this->set_BuyerID(temp);
	getline(fin, temp);
	this->set_EmployeeID(temp);
	getline(fin, temp);
	this->set_Date(temp);
}

void Sale::printElement(fstream& fout)
{
	fout << this->get_ID() << "\n";
	fout << this->get_BuyerID() << "\n";
	fout << this->get_EmployeeID() << "\n";
	fout << this->get_Date();
}

Sale Sale::set_Pointers(List<Buyer>* BuyerBase, List<Employee>* EmployeeBase)
{
	Sale result;
	result.set_ID(this->get_ID());
	result.set_BuyerID(this->BuyerID);
	result.set_BuyerPtr(BuyerBase->_search_ID(this->BuyerID));
	result.set_EmployeeID(this->EmployeeID);
	result.set_EmployeePtr(EmployeeBase->_search_ID(this->EmployeeID));
	result.set_Date(this->Date);
	return result;
}

Sale Sale::update_IDs()
{
	Sale result;
	result.set_ID(this->get_ID());
	result.set_BuyerID(to_string(this->BuyerPtr->getData().get_ID()));
	result.set_BuyerPtr(this->BuyerPtr);
	result.set_EmployeeID(to_string(this->EmployeePtr->getData().get_ID()));
	result.set_EmployeePtr(this->EmployeePtr);
	result.set_Date(this->Date);
	return result;
}

List<Unit<Sale>*>* Sales_list::_search_Employee(string value)
{
	List<Unit<Sale>*>* resultList = new List<Unit<Sale>*>;
	Unit<Sale>* ptr;

	ptr = this->getHead();
	while (ptr != NULL) {
		if (ptr->getData().get_EmployeePtr()->getData().get_FullName() == value)
			resultList->push_back(ptr);
		ptr = ptr->getNext();
	}
	return resultList;
}

List<Unit<Sale>*>* Sales_list::_search_Buyer(string value)
{
	List<Unit<Sale>*>* resultList = new List<Unit<Sale>*>;
	Unit<Sale>* ptr;

	ptr = this->getHead();
	while (ptr != NULL) {
		if (ptr->getData().get_BuyerPtr()->getData().get_FullName() == value)
			resultList->push_back(ptr);
		ptr = ptr->getNext();
	}
	return resultList;
}

Unit<Sale>* Sales_list::_search_Sale(int value)
{
	Unit<Sale>* ptr;
	ptr = this->getHead();

	while (ptr != NULL) {
		if (ptr->getData().get_ID() == value)
			break;
		ptr = ptr->getNext();
	}
	return ptr;
}

void Sales_list::set_Pointers(List<Buyer>* BuyerBase, List<Employee>* EmployeeBase)
{
	Unit<Sale>* ptr;
	Sale value;
	ptr = this->getHead();
	while (ptr != NULL) {
		value = ptr->getData().set_Pointers(BuyerBase, EmployeeBase);
		ptr->setData(value);
		ptr = ptr->getNext();
	}
}

void Sales_list::update_Pointers()
{
	Sale value;
	Unit<Sale>* ptr;
	ptr = this->getHead();
	while (ptr != NULL) {
		value = ptr->getData().update_IDs();
		ptr->setData(value);
		ptr = ptr->getNext();
	}
}

void StructOfSale::fillElement(fstream& fin)
{
	string temp;
	getline(fin, temp);
	this->set_SaleID(temp);
	getline(fin, temp);
	this->set_GuitarID(temp);
	getline(fin, temp);
	this->set_Amount(temp);
}

void StructOfSale::printElement(fstream& fout)
{
	fout << this->get_SaleID() << "\n";
	fout << this->get_GuitarID() << "\n";
	fout << this->get_Amount();
}

StructOfSale StructOfSale::set_Pointers(List<Sale>* SaleList, List<Guitar>* GuitarBase)
{
	StructOfSale result;
	result.set_SaleID(this->SaleID);
	result.set_SalePtr(SaleList->_search_ID(this->SaleID));
	result.set_GuitarID(this->GuitarID);
	result.set_GuitarPtr(GuitarBase->_search_ID(this->GuitarID));
	result.set_Amount(this->Amount);
	return result;
}

StructOfSale StructOfSale::update_IDs()
{
	StructOfSale result;
	result.set_SaleID(to_string(this->SalePtr->getData().get_ID()));
	result.set_SalePtr(this->SalePtr);
	result.set_GuitarID(to_string(this->GuitarPtr->getData().get_ID()));
	result.set_GuitarPtr(this->GuitarPtr);
	result.set_Amount(this->Amount);
	return result;
}

List<Unit<StructOfSale>*>* StructsOfSales_list::_search_Sale(int value)
{
	List<Unit<StructOfSale>*>* resultList = new List<Unit<StructOfSale>*>;
	Unit<StructOfSale>* ptr;

	ptr = this->getHead();
	while (ptr != NULL) {
		if (ptr->getData().get_SalePtr()->getData().get_ID() == value)
			resultList->push_back(ptr);
		ptr = ptr->getNext();
	}
	return resultList;
}

List<Unit<StructOfSale>*>* StructsOfSales_list::_search_Guitar(int value) 
{
	List<Unit<StructOfSale>*>* resultList = new List<Unit<StructOfSale>*>;
	Unit<StructOfSale>* ptr;

	ptr = this->getHead();
	while (ptr != NULL) {
		if (ptr->getData().get_GuitarPtr()->getData().get_ID() == value)
			resultList->push_back(ptr);
		ptr = ptr->getNext();
	}
	return resultList;
}

void StructsOfSales_list::set_Pointers(Sales_list* SaleBase, List<Guitar>* GuitarBase)
{
	Unit<StructOfSale>* ptr;
	StructOfSale value;
	ptr = this->getHead();
	while (ptr != NULL) {
		value = ptr->getData().set_Pointers(SaleBase, GuitarBase);
		ptr->setData(value);
		ptr = ptr->getNext();
	}
}

void StructsOfSales_list::update_Pointers()
{
	StructOfSale value;
	Unit<StructOfSale>* ptr;
	ptr = this->getHead();
	while (ptr != NULL) {
		value = ptr->getData().update_IDs();
		ptr->setData(value);
		ptr = ptr->getNext();
	}
}

void Supply::fillElement(fstream& fin)
{
	string temp;
	getline(fin, temp);
	this->set_ID(stoi(temp));
	getline(fin, temp);
	this->set_EmployeeID(temp);
	getline(fin, temp);
	this->set_Date(temp);
}

void Supply::printElement(fstream& fout)
{
	fout << this->get_ID() << "\n";
	fout << this->get_EmployeeID() << "\n";
	fout << this->get_Date();
}

Supply Supply::set_Pointers(List<Employee>* EmployeeBase)
{
	Supply result;
	result.set_ID(this->get_ID());
	result.set_EmployeeID(this->EmployeeID);
	result.set_EmployeePtr(EmployeeBase->_search_ID(this->EmployeeID));
	result.set_Date(this->Date);
	return result;
}

Supply Supply::update_IDs()
{
	Supply result;
	result.set_ID(this->get_ID());
	result.set_EmployeeID(to_string(this->EmployeePtr->getData().get_ID()));
	result.set_EmployeePtr(this->EmployeePtr);
	result.set_Date(this->Date);
	return result;
}

List<Unit<Supply>*>* Supplies_list::_search_Employee(string value)
{
	List<Unit<Supply>*>* resultList = new List<Unit<Supply>*>;
	Unit<Supply>* ptr;

	ptr = this->getHead();
	while (ptr != NULL) {
		if (ptr->getData().get_EmployeePtr()->getData().get_FullName() == value)
			resultList->push_back(ptr);
		ptr = ptr->getNext();
	}
	return resultList;
}

Unit<Supply>* Supplies_list::_search_Supply(int value) 
{
	Unit<Supply>* ptr;
	ptr = this->getHead();

	while (ptr != NULL) {
		if (ptr->getData().get_ID() == value)
			break;
		ptr = ptr->getNext();
	}
	return ptr;
}

void Supplies_list::set_Pointers(List<Employee>* EmployeeBase)
{
	Unit<Supply>* ptr;
	Supply value;
	ptr = this->getHead();
	while (ptr != NULL) {
		value = ptr->getData().set_Pointers(EmployeeBase);
		ptr->setData(value);
		ptr = ptr->getNext();
	}
}

void Supplies_list::update_Pointers()
{
	Supply value;
	Unit<Supply>* ptr;
	ptr = this->getHead();
	while (ptr != NULL) {
		value = ptr->getData().update_IDs();
		ptr->setData(value);
		ptr = ptr->getNext();
	}
}

void StructOfSupply::fillElement(fstream& fin)
{
	string temp;
	getline(fin, temp);
	this->set_SupplyID(temp);
	getline(fin, temp);
	this->set_GuitarID(temp);
	getline(fin, temp);
	this->set_Amount(temp);
}

void StructOfSupply::printElement(fstream& fout)
{
	fout << this->get_SupplyID() << "\n";
	fout << this->get_GuitarID() << "\n";
	fout << this->get_Amount();
}

StructOfSupply StructOfSupply::set_Pointers(List<Supply>* SupplyList, List<Guitar>* GuitarBase)
{
	StructOfSupply result;
	result.set_ID(0);
	result.set_SupplyID(this->SupplyID);
	result.set_SupplyPtr(SupplyList->
		_search_ID(this->SupplyID));
	result.set_GuitarID(this->GuitarID);
	result.set_GuitarPtr(GuitarBase->
		_search_ID(this->GuitarID));
	result.set_Amount(this->Amount);
	return result;
}

StructOfSupply StructOfSupply::update_IDs()
{
	StructOfSupply result;
	result.set_ID(0);
	result.set_SupplyID(to_string(this->
		SupplyPtr->getData().get_ID()));
	result.set_SupplyPtr(this->SupplyPtr);
	result.set_GuitarID(to_string(this->
		GuitarPtr->getData().get_ID()));
	result.set_GuitarPtr(this->GuitarPtr);
	result.set_Amount(this->Amount);
	return result;
}

List<Unit<StructOfSupply>*>* StructsOfSupplies_list::_search_Supply(int value)
{
	List<Unit<StructOfSupply>*>* resultList = new List<Unit<StructOfSupply>*>;
	Unit<StructOfSupply>* ptr;

	ptr = this->getHead();
	while (ptr != NULL) {
		if (ptr->getData().get_SupplyPtr()->getData().get_ID() == value)
			resultList->push_back(ptr);
		ptr = ptr->getNext();
	}
	return resultList;
}

List<Unit<StructOfSupply>*>* StructsOfSupplies_list::_search_Guitar(int value)
{
	List<Unit<StructOfSupply>*>* resultList = new List<Unit<StructOfSupply>*>;
	Unit<StructOfSupply>* ptr;

	ptr = this->getHead();
	while (ptr != NULL) {
		if (ptr->getData().get_GuitarPtr()->getData().get_ID() == value)
			resultList->push_back(ptr);
		ptr = ptr->getNext();
	}
	return resultList;
}

void StructsOfSupplies_list::set_Pointers(Supplies_list* SupplyList, List<Guitar>* GuitarBase)
{
	Unit<StructOfSupply>* ptr;
	StructOfSupply value;
	ptr = this->getHead();
	while (ptr != NULL) {
		value = ptr->getData().set_Pointers(SupplyList, GuitarBase);
		ptr->setData(value);
		ptr = ptr->getNext();
	}
}

void StructsOfSupplies_list::update_Pointers()
{
	StructOfSupply value;
	Unit<StructOfSupply>* ptr;
	ptr = this->getHead();
	while (ptr != NULL) {
		value = ptr->getData().update_IDs();
		ptr->setData(value);
		ptr = ptr->getNext();
	}
}
