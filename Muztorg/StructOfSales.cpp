#include "StructOfSales.h"
#include "Sales.h"

System::Void Muztorg::StructOfSales::StructOfSales_Load(System::Object^ sender, System::EventArgs^ e)
{
    string smallString;
    String^ BigString;
    TitleBox->Enabled = false;
    AmountBox->ReadOnly = true;

    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;

    Unit<Guitar>* gPtr = GuitarBase->getHead();
    while (gPtr != NULL)
    {
        smallString = gPtr->getData().get_Title();
        BigString = Convert_string_to_String(smallString);
        TitleBox->Items->Add(BigString);
        gPtr = gPtr->getNext();
    }

    this->CurrentList = this->StructOfSaleBase->_search_Sale(this->SearchedSale->getData().get_ID());
    this->CurrentPtr = this->CurrentList->getHead();

    TitleBox->Text = Convert_string_to_String(CurrentPtr->getData()->getData().get_GuitarPtr()->getData().get_Title());
    AmountBox->Text = Convert_string_to_String(this->CurrentPtr->getData()->getData().get_Amount());
    return System::Void();
}

System::Void Muztorg::StructOfSales::ToggleChanges_Click(System::Object^ sender, System::EventArgs^ e)
{
    TitleBox->Enabled = true;
    AmountBox->ReadOnly = false;

    ToggleChanges->Visible = false;
    ToggleChangesOff->Visible = true;
    return System::Void();
}

System::Void Muztorg::StructOfSales::ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e)
{
    TitleBox->Enabled = false;
    AmountBox->ReadOnly = true;

    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;
    return System::Void();
}

System::Void Muztorg::StructOfSales::StructOfSales_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Form^ form = Application::OpenForms[1];
    form->Show();
    return System::Void();
}

System::Void Muztorg::StructOfSales::Box_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (this->BoxActive == true)
        this->DataChanged = true;
    return System::Void();
}

System::Void Muztorg::StructOfSales::Box_Enter(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = true;
    return System::Void();
}

System::Void Muztorg::StructOfSales::Box_Leave(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = false;
    return System::Void();
}

System::Void Muztorg::StructOfSales::Prev_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->AddMode = false;
    TitleBox->Enabled = false;
    AmountBox->ReadOnly = true;
    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;

    if (this->DataChanged == true)
    {
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            StructOfSale value;
            String^ BigString;
            string smallString;

            this->DataChanged = false;

            value.set_ID(this->CurrentPtr->getData()->getData().get_ID());
            value.set_SalePtr(this->SaleBase->_search_Sale
            (stoi(this->CurrentPtr->getData()->getData().get_SaleID())));

            BigString = TitleBox->SelectedItem->ToString();
            Convert_String_to_string(BigString, smallString);
            value.set_GuitarPtr(this->GuitarBase->_search_Title(smallString));

            BigString = AmountBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Amount(smallString);

            this->CurrentPtr->getData()->setData(value);
        }
        else this->DataChanged = false;
    }

    if (this->CurrentPtr->getPrev() == NULL)
        this->CurrentPtr = CurrentList->getTail();
    else this->CurrentPtr = this->CurrentPtr->getPrev();

    TitleBox->Text = Convert_string_to_String(CurrentPtr->getData()->getData().get_GuitarPtr()->getData().get_Title());
    AmountBox->Text = Convert_string_to_String(this->CurrentPtr->getData()->getData().get_Amount());
    return System::Void();
}

System::Void Muztorg::StructOfSales::Next_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->AddMode = false;
    TitleBox->Enabled = false;
    AmountBox->ReadOnly = true;
    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;

    if (this->DataChanged == true)
    {
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            StructOfSale value;
            String^ BigString;
            string smallString;

            this->DataChanged = false;

            value.set_ID(this->CurrentPtr->getData()->getData().get_ID());
            value.set_SalePtr(this->SaleBase->_search_Sale
            (stoi(this->CurrentPtr->getData()->getData().get_SaleID())));

            BigString = TitleBox->SelectedItem->ToString();
            Convert_String_to_string(BigString, smallString);
            value.set_GuitarPtr(this->GuitarBase->_search_Title(smallString));

            BigString = AmountBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Amount(smallString);

            this->CurrentPtr->getData()->setData(value);
        }
        else this->DataChanged = false;
    }

    if (this->CurrentPtr->getNext() == NULL)
        this->CurrentPtr = CurrentList->getHead();
    else this->CurrentPtr = this->CurrentPtr->getNext();

    TitleBox->Text = Convert_string_to_String(CurrentPtr->getData()->getData().get_GuitarPtr()->getData().get_Title());
    AmountBox->Text = Convert_string_to_String(this->CurrentPtr->getData()->getData().get_Amount());
    return System::Void();
}

System::Void Muztorg::StructOfSales::Save_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (this->DataChanged == true)
    {
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            StructOfSale value;
            String^ BigString;
            string smallString;

            this->DataChanged = false;

            value.set_ID(this->CurrentPtr->getData()->getData().get_ID());
            value.set_SalePtr(this->SaleBase->_search_Sale
            (stoi(this->CurrentPtr->getData()->getData().get_SaleID())));

            BigString = TitleBox->SelectedItem->ToString();
            Convert_String_to_string(BigString, smallString);
            value.set_GuitarPtr(this->GuitarBase->_search_Title(smallString));

            BigString = AmountBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Amount(smallString);

            this->CurrentPtr->getData()->setData(value);
        }
        else this->DataChanged = false;
    }

    return System::Void();
}

System::Void Muztorg::StructOfSales::Add_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;
    StructOfSale value;

    if (this->AddMode == true)
    {
        if (TitleBox->SelectedIndex == -1)
        {
            MessageBox::Show("Заполните поле \"Название\"");
            return System::Void();
        }
        if (AmountBox->Text == "")
        {
            MessageBox::Show("Заполните поле \"Кол-во\"");
            return System::Void();
        }

        value.set_ID(this->StructOfSaleBase->getTail()->getData().get_ID() + 1);
        value.set_SalePtr(this->SaleBase->_search_Sale
        (stoi(this->CurrentPtr->getData()->getData().get_SaleID())));

        BigString = TitleBox->SelectedItem->ToString();
        Convert_String_to_string(BigString, smallString);
        value.set_GuitarPtr(this->GuitarBase->_search_Title(smallString));

        BigString = AmountBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_Amount(smallString);

        StructOfSaleBase->push_back(value);

        TitleBox->Enabled = false;
        AmountBox->ReadOnly = true;
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
            StructOfSale value;

            this->DataChanged = false;

            value.set_ID(this->CurrentPtr->getData()->getData().get_ID());
            value.set_SalePtr(this->SaleBase->_search_Sale
            (stoi(this->CurrentPtr->getData()->getData().get_SaleID())));

            BigString = TitleBox->SelectedItem->ToString();
            Convert_String_to_string(BigString, smallString);
            value.set_GuitarPtr(this->GuitarBase->_search_Title(smallString));

            BigString = AmountBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Amount(smallString);

            this->CurrentPtr->getData()->setData(value);
        }
        else this->DataChanged = false;
    }

    AmountBox->Clear();
    TitleBox->SelectedIndex = -1;
    TitleBox->Enabled = true;
    AmountBox->ReadOnly = false;
    ToggleChanges->Visible = false;
    ToggleChangesOff->Visible = true;
    this->AddMode = true;
    this->DataChanged = false;

    return System::Void();
}

System::Void Muztorg::StructOfSales::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    return System::Void();
}