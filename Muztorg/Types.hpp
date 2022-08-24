#pragma once
#include "List.hpp"


class ObjectType
{
private:
	int id;
public:
	void set_ID(int value) { this->id = value; }
	int get_ID() { return this->id; }
	virtual void fillElement(fstream& fin) {  };
	virtual void printElement(fstream& fout) {  };
};

class Buyer : public ObjectType
{
private:
	string FullName;
	string PhoneNumber;
public:
	void set_FullName(string value) { this->FullName = value; }
	void set_PhoneNumber(string value) { this->PhoneNumber = value; }

	string get_FullName() { return this->FullName; }
	string getPhoneNumber() { return this->PhoneNumber; }

	virtual void fillElement(fstream& fin) override;
	virtual void printElement(fstream& fout) override;
};


class Employee : public ObjectType
{
private:
	string FullName;
	string Gender;
	string BDate;
public:
	void set_FullName(string value) { this->FullName = value; }
	void set_Gender(string value) { this->Gender = value; }
	void set_BDate(string value) { this->BDate = value; }

	string get_FullName() { return this->FullName; }
	string get_Gender() { return this->Gender; }
	string get_BDate() { return this->BDate; }

	virtual void fillElement(fstream& fin) override;
	virtual void printElement(fstream& fout) override;
};

class Guitar : public ObjectType
{
private:
	string Title;
	string Description;
	string Price;
	string Color;
	string FormOfDeck;
	string MaterialOfDeck;
	string AmountOfFret;
	string Beaker;
public:
	void set_Title(string value) { this->Title = value; }
	void set_Description(string value) { this->Description = value; }
	void set_Price(string value) { this->Price = value; }
	void set_Color(string value) { this->Color = value; }
	void set_FormOfDeck(string value) { this->FormOfDeck = value; }
	void set_MaterialOfDeck(string value) { this->MaterialOfDeck = value; }
	void set_AmountOfFret(string value) { this->AmountOfFret = value; }
	void set_Beaker(string value) { this->Beaker = value; }

	string get_Title() { return this->Title; }
	string get_Description() { return this->Description; }
	string get_Price() { return this->Price; }
	string get_Color() { return this->Color; }
	string get_FormOfDeck() { return this->FormOfDeck; }
	string get_MaterialOfDeck() { return this->MaterialOfDeck; }
	string get_AmountOfFret() { return this->AmountOfFret; }
	string get_Beaker() { return this->Beaker; }

	virtual void fillElement(fstream& fin) override;
	virtual void printElement(fstream& fout) override;
};

class Sale : public ObjectType
{
private:
	string BuyerID;
	Unit<Buyer>* BuyerPtr;
	string EmployeeID;
	Unit<Employee>* EmployeePtr;
	string Date;
public:
	void set_BuyerID(string value) { this->BuyerID = value; }
	void set_BuyerPtr(Unit<Buyer>* value) { this->BuyerPtr = value; }
	void set_EmployeeID(string value) { this->EmployeeID = value; }
	void set_EmployeePtr(Unit<Employee>* value) { this->EmployeePtr = value; }
	void set_Date(string value) { this->Date = value; }

	string get_BuyerID() { return this->BuyerID; }
	Unit<Buyer>* get_BuyerPtr() { return this->BuyerPtr; }
	string get_EmployeeID() { return this->EmployeeID; }
	Unit<Employee>* get_EmployeePtr() { return this->EmployeePtr; }
	string get_Date() { return this->Date; }

	virtual void fillElement(fstream& fin) override;
	virtual void printElement(fstream& fout) override;

	Sale set_Pointers(List<Buyer>* BuyerBase, List<Employee>* EmployeeBase);
	Sale update_IDs();
};


class Sales_list : public List<Sale>
{
public:
	List<Unit<Sale>*>* _search_Employee(string value);
	List<Unit<Sale>*>* _search_Buyer(string value);
	void set_Pointers(List<Buyer>* BuyerBase, List<Employee>* EmployeeBase);
	void update_Pointers();
};

class StructOfSale : public ObjectType
{
private:
	string SaleID;
	Unit<Sale>* SalePtr;
	string GuitarID;
	Unit<Guitar>* GuitarPtr;
	string Amount;
public:
	void set_SaleID(string value) { this->SaleID = value; }
	void set_SalePtr(Unit<Sale>* value) { this->SalePtr = value; }
	void set_GuitarID(string value) { this->GuitarID = value; }
	void set_GuitarPtr(Unit<Guitar>* value) { this->GuitarPtr = value; }
	void set_Amount(string value) { this->Amount = value; }

	string get_SaleID() { return this->SaleID; }
	Unit<Sale>* get_SalePtr() { return this->SalePtr; }
	string get_GuitarID() { return this->GuitarID; }
	Unit<Guitar>* get_GuitarPtr() { return this->GuitarPtr; }
	string get_Amount() { return this->Amount; }

	virtual void fillElement(fstream& fin) override;
	virtual void printElement(fstream& fout) override;

	StructOfSale set_Pointers(List<Sale>* SaleList, List<Guitar>* GuitarBase);
	StructOfSale update_IDs();
};

class StructsOfSales_list : public List<StructOfSale>
{
public:
	List<Unit<StructOfSale>*>* _search_Sale(int value);
	void set_Pointers(Sales_list* SaleBase, List<Guitar>* GuitarBase);
	void update_Pointers();
};

class Supply : public ObjectType
{
private:
	string EmployeeID;
	Unit<Employee>* EmployeePtr;
	string Date;
public:
	void set_EmployeeID(string value) { this->EmployeeID = value; }
	void set_EmployeePtr(Unit<Employee>* value) { this->EmployeePtr = value; }
	void set_Date(string value) { this->Date = value; }

	string get_EmployeeID() { return this->EmployeeID; }
	Unit<Employee>* get_EmployeePtr() { return this->EmployeePtr; }
	string get_Date() { return this->Date; }

	virtual void fillElement(fstream& fin) override;
	virtual void printElement(fstream& fout) override;

	Supply set_Pointers(List<Employee>* EmployeeBase);
	Supply update_IDs();
};

class Supplies_list : public List<Supply>
{
public:
	List<Unit<Supply>*>* _search_Employee(string value);
	void set_Pointers(List<Employee>* EmployeeBase);
	void update_Pointers();
};

class StructOfSupply : public ObjectType
{
private:
	string SupplyID;
	Unit<Supply>* SupplyPtr;
	string GuitarID;
	Unit<Guitar>* GuitarPtr;
	string Amount;
public:
	void set_SupplyID(string value) { this->SupplyID = value; }
	void set_SupplyPtr(Unit<Supply>* value) { this->SupplyPtr = value; }
	void set_GuitarID(string value) { this->GuitarID = value; }
	void set_GuitarPtr(Unit<Guitar>* value) { this->GuitarPtr = value; }
	void set_Amount(string value) { this->Amount = value; }

	string get_SupplyID() { return this->SupplyID; }
	Unit<Supply>* get_SupplyPtr() { return this->SupplyPtr; }
	string get_GuitarID() { return this->GuitarID; }
	Unit<Guitar>* get_GuitarPtr() { return this->GuitarPtr; }
	string get_Amount() { return this->Amount; }

	virtual void fillElement(fstream& fin) override;
	virtual void printElement(fstream& fout) override;

	StructOfSupply set_Pointers(List<Supply>* SupplyList, List<Guitar>* GuitarBase);
	StructOfSupply update_IDs();
};

class StructsOfSupplies_list : public List<StructOfSupply>
{
public:
	List<Unit<StructOfSupply>*>* _search_Supply(int value);
	void set_Pointers(Supplies_list* SupplyBase, List<Guitar>* GuitarBase);
	void update_Pointers();
};