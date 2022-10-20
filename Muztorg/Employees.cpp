#include "Employees.h"

System::Void Muztorg::Employees::Employees_Load(System::Object^ sender, System::EventArgs^ e)
{
    NameBox->ReadOnly = true;
    GenderBox->ReadOnly = true;
    BDateMaskedBox->ReadOnly = true;
    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;

    this->CurrentPtr = this->EmployeeBase->getHead();

    NameBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_FullName());
    GenderBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Gender());
    BDateMaskedBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_BDate());
    return System::Void();
}

System::Void Muztorg::Employees::ToggleChanges_Click(System::Object^ sender, System::EventArgs^ e)
{
    NameBox->ReadOnly = false;
    GenderBox->ReadOnly = false;
    BDateMaskedBox->ReadOnly = false;

    ToggleChanges->Visible = false;
    ToggleChangesOff->Visible = true;
    return System::Void();
}

System::Void Muztorg::Employees::ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e)
{
    NameBox->ReadOnly = true;
    GenderBox->ReadOnly = true;
    BDateMaskedBox->ReadOnly = true;

    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;
    return System::Void();
}

System::Void Muztorg::Employees::Employees_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Form^ form = Application::OpenForms[0];
    form->Show();
    return System::Void();
}

System::Void Muztorg::Employees::Box_TextChanged(System::Object^ sender, System::EventArgs^ e)
{

    if (this->BoxActive == true)
        this->DataChanged = true;
    return System::Void();
}

System::Void Muztorg::Employees::Box_Enter(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = true;
    return System::Void();
}

System::Void Muztorg::Employees::Box_Leave(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = false;
    return System::Void();
}

System::Void Muztorg::Employees::Prev_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->AddMode = false;
    NameBox->ReadOnly = true;
    GenderBox->ReadOnly = true;
    BDateMaskedBox->ReadOnly = true;
    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;

    if (this->DataChanged == true)
    {
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Employee value;
            String^ BigString;
            string smallString;

            this->DataChanged = false;
            value.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = NameBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FullName(smallString);

            BigString = GenderBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Gender(smallString);

            BigString = BDateMaskedBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_BDate(smallString);

            this->CurrentPtr->setData(value);
        }
        else this->DataChanged = false;
    }

    if (this->CurrentPtr->getPrev() == NULL)
        this->CurrentPtr = EmployeeBase->getTail();
    else this->CurrentPtr = this->CurrentPtr->getPrev();

    NameBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_FullName());
    GenderBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Gender());
    BDateMaskedBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_BDate());
    return System::Void();
}

System::Void Muztorg::Employees::Next_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->AddMode = false;
    NameBox->ReadOnly = true;
    GenderBox->ReadOnly = true;
    BDateMaskedBox->ReadOnly = true;
    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;

    if (this->DataChanged == true)
    {
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Employee value;
            String^ BigString;
            string smallString;

            this->DataChanged = false;
            value.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = NameBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FullName(smallString);

            BigString = GenderBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Gender(smallString);

            BigString = BDateMaskedBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_BDate(smallString);

            this->CurrentPtr->setData(value);
        }
        else this->DataChanged = false;
    }

    if (this->CurrentPtr->getNext() == NULL)
        this->CurrentPtr = EmployeeBase->getHead();
    else this->CurrentPtr = this->CurrentPtr->getNext();

    NameBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_FullName());
    GenderBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Gender());
    BDateMaskedBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_BDate());
    return System::Void();
}

System::Void Muztorg::Employees::Save_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;

    if (this->DataChanged == true)
    {
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Employee value;
            this->DataChanged = false;
            value.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = NameBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FullName(smallString);

            BigString = GenderBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Gender(smallString);

            BigString = BDateMaskedBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_BDate(smallString);

            this->CurrentPtr->setData(value);
        }
        else this->DataChanged = false;
    }

    return System::Void();
}

System::Void Muztorg::Employees::SalesReport_Click(System::Object^ sender, System::EventArgs^ e)
{
    Muztorg::EmployeesSales_Report^ form = gcnew EmployeesSales_Report(CurrentPtr);
    form->set_StructsOfSupplyBase(this->StructOfSupplyBase);
    form->set_StructOfSaleBase(this->StructOfSaleBase);
    form->set_EmployeeBase(this->EmployeeBase);
    form->set_GuitarBase(this->GuitarBase);
    form->set_SupplyBase(this->SupplyBase);
    form->set_BuyerBase(this->BuyerBase);
    form->set_SaleBase(this->SaleBase);
    this->Hide();
    form->Show();
    return System::Void();
}

System::Void Muztorg::Employees::SuppliesReport_Click(System::Object^ sender, System::EventArgs^ e)
{
    Muztorg::EmployeesSupplies_Report^ form = gcnew EmployeesSupplies_Report(CurrentPtr);
    form->set_StructsOfSupplyBase(this->StructOfSupplyBase);
    form->set_StructOfSaleBase(this->StructOfSaleBase);
    form->set_EmployeeBase(this->EmployeeBase);
    form->set_GuitarBase(this->GuitarBase);
    form->set_SupplyBase(this->SupplyBase);
    form->set_BuyerBase(this->BuyerBase);
    form->set_SaleBase(this->SaleBase);
    this->Hide();
    form->Show();
    return System::Void();
}

System::Void Muztorg::Employees::Add_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;
    Employee value;

    if (this->AddMode == true)
    {
        if (NameBox->Text == "")
        {
            MessageBox::Show("Заполните поле \"ФИО сотрудника\"");
            return System::Void();
        }
        if (GenderBox->Text == "")
        {
            MessageBox::Show("Заполните поле \"Пол\"");
            return System::Void();
        }
        if (BDateMaskedBox->Text == "")
        {
            MessageBox::Show("Заполните поле \"Дата рождения\"");
            return System::Void();
        }

        BigString = NameBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_FullName(smallString);

        BigString = GenderBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_Gender(smallString);

        BigString = BDateMaskedBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_BDate(smallString);

        value.set_ID(EmployeeBase->getTail()->getData().get_ID() + 1);
        EmployeeBase->push_back(value);

        NameBox->ReadOnly = true;
        GenderBox->ReadOnly = true;
        BDateMaskedBox->ReadOnly = true;
        ToggleChanges->Visible = true;
        ToggleChangesOff->Visible = false;
        this->AddMode = false;
        this->DataChanged = false;
        return System::Void();
    }

    if (this->DataChanged == true)
    {
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Employee value;
            this->DataChanged = false;
            value.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = NameBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FullName(smallString);

            BigString = GenderBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Gender(smallString);

            BigString = BDateMaskedBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_BDate(smallString);

            this->CurrentPtr->setData(value);
        }
        else this->DataChanged = false;
    }

    NameBox->Clear();
    GenderBox->Clear();
    BDateMaskedBox->Clear();
    NameBox->ReadOnly = false;
    GenderBox->ReadOnly = false;
    BDateMaskedBox->ReadOnly = false;
    ToggleChanges->Visible = false;
    ToggleChangesOff->Visible = true;
    this->AddMode = true;
    this->DataChanged = false;

    return System::Void();
}

System::Void Muztorg::Employees::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    return System::Void();
}
