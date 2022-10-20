#include "Buyers.h"

System::Void Muztorg::Buyers::Buyers_Load(System::Object^ sender, System::EventArgs^ e)
{
    NameBox->ReadOnly = true;
    PhoneBox->ReadOnly = true;
    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;

    this->CurrentPtr = this->BuyerBase->getHead();
    NameBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_FullName());
    PhoneBox->Text = Convert_string_to_String(this->CurrentPtr->getData().getPhoneNumber());
    return System::Void();
}

System::Void Muztorg::Buyers::Buyers_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Form^ form = Application::OpenForms[0];
    form->Show();
    return System::Void();
}

System::Void Muztorg::Buyers::Box_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (this->BoxActive == true)
        this->DataChanged = true;
    return System::Void();
}

System::Void Muztorg::Buyers::Box_Enter(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = true;
    return System::Void();
}

System::Void Muztorg::Buyers::Box_Leave(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = false;
    return System::Void();
}

System::Void Muztorg::Buyers::Next_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->AddMode = false;
    NameBox->ReadOnly = true;
    PhoneBox->ReadOnly = true;
    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;

    if (this->DataChanged == true)
    {
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Buyer value;
            String^ BigString;
            string smallString;

            this->DataChanged = false;
            value.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = NameBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FullName(smallString);

            BigString = PhoneBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_PhoneNumber(smallString);

            this->CurrentPtr->setData(value);
        }
        else this->DataChanged = false;
    }

    if (this->CurrentPtr->getNext() == NULL)
        this->CurrentPtr = BuyerBase->getHead();
    else this->CurrentPtr = this->CurrentPtr->getNext();

    NameBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_FullName());
    PhoneBox->Text = Convert_string_to_String(this->CurrentPtr->getData().getPhoneNumber());
    return System::Void();
}

System::Void Muztorg::Buyers::Prev_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->AddMode = false;
    NameBox->ReadOnly = true;
    PhoneBox->ReadOnly = true;
    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;

    if (this->DataChanged == true)
    {
        Buyer value;
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Buyer value;
            String^ BigString;
            string smallString;

            this->DataChanged = false;
            value.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = NameBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FullName(smallString);

            BigString = PhoneBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_PhoneNumber(smallString);

            this->CurrentPtr->setData(value);
        }
        else this->DataChanged = false;
    }

    if (this->CurrentPtr->getPrev() == NULL)
        this->CurrentPtr = BuyerBase->getTail();
    else this->CurrentPtr = this->CurrentPtr->getPrev();

    NameBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_FullName());
    PhoneBox->Text = Convert_string_to_String(this->CurrentPtr->getData().getPhoneNumber());
    return System::Void();
}

System::Void Muztorg::Buyers::Add_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;
    Buyer value;

    if (this->AddMode == true)
    {
        if (NameBox->Text == "")
        {
            MessageBox::Show("Заполните поле \"ФИО клиента\"");
            return System::Void();
        }
        if (PhoneBox->Text == "")
        {
            MessageBox::Show("Заполните поле \"Номер телефона\"");
            return System::Void();
        }

        BigString = NameBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_FullName(smallString);

        BigString = PhoneBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_PhoneNumber(smallString);

        value.set_ID(BuyerBase->getTail()->getData().get_ID() + 1);
        BuyerBase->push_back(value);

        NameBox->ReadOnly = true;
        PhoneBox->ReadOnly = true;
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
            Buyer value;
            this->DataChanged = false;
            value.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = NameBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FullName(smallString);

            BigString = PhoneBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_PhoneNumber(smallString);

            this->CurrentPtr->setData(value);
        }
        else this->DataChanged = false;
    }

    NameBox->Clear();
    PhoneBox->Clear();

    NameBox->ReadOnly = false;
    PhoneBox->ReadOnly = false;
    ToggleChanges->Visible = false;
    ToggleChangesOff->Visible = true;

    this->AddMode = true;

    return System::Void();
}

System::Void Muztorg::Buyers::ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e)
{
    NameBox->ReadOnly = true;
    PhoneBox->ReadOnly = true;

    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;
    return System::Void();
}

System::Void Muztorg::Buyers::ToggleChanges_Click(System::Object^ sender, System::EventArgs^ e)
{
    NameBox->ReadOnly = false;
    PhoneBox->ReadOnly = false;

    ToggleChanges->Visible = false;
    ToggleChangesOff->Visible = true;
    return System::Void();
}

System::Void Muztorg::Buyers::Save_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;

    if (this->DataChanged == true)
    {
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Buyer value;
            this->DataChanged = false;
            value.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = NameBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FullName(smallString);

            BigString = PhoneBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_PhoneNumber(smallString);

            this->CurrentPtr->setData(value);
        }
        else this->DataChanged = false;
    }

    return System::Void();
}

System::Void Muztorg::Buyers::PurchaseReport_Click(System::Object^ sender, System::EventArgs^ e)
{
    Muztorg::BuyersSales_Report^ form = gcnew BuyersSales_Report(CurrentPtr);
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

System::Void Muztorg::Buyers::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    return System::Void();
}
