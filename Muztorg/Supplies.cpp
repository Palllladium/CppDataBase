#include "Supplies.h"

System::Void Muztorg::Supplies::Supplies_Load(System::Object^ sender, System::EventArgs^ e)
{
    EmployeeBox->Enabled = false;
    DateMaskedBox->ReadOnly = true;
    ToggleChange->Visible = true;
    ToggleChangesOff->Visible = false;
    this->DataChanged = false;

    DataGridViewColumn^ Title = gcnew DataGridViewColumn();
    Title->HeaderText = "Товар";
    Title->ReadOnly = true;
    Title->Width = 320;
    Title->Name = "Title";
    Title->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Amount = gcnew DataGridViewColumn();
    Amount->HeaderText = "Кол-во";
    Amount->ReadOnly = true;
    Amount->Width = 110;
    Amount->Name = "Amount";
    Amount->CellTemplate = gcnew DataGridViewTextBoxCell();

    Unit<Employee>* ePtr = this->EmployeeBase->getHead();
    while (ePtr != NULL)
    {
        EmployeeBox->Items->Add(Convert_string_to_String(ePtr->getData().get_FullName()));
        ePtr = ePtr->getNext();
    }

    SupplyGridView->Columns->Add(Title);
    SupplyGridView->Columns->Add(Amount);
    SupplyGridView->ReadOnly = true;

    this->CurrentPtr = this->SupplyBase->getHead();
    EmployeeBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_EmployeePtr()->getData().get_FullName());
    DateMaskedBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Date());

    List<Unit<StructOfSupply>*>* StrList = this->StructOfSupplyBase->_search_Supply(this->CurrentPtr->getData().get_ID());
    if (StrList->getHead() != NULL) {
        Unit<Unit<StructOfSupply>*>* strPtr = StrList->getHead();
        String^ title;
        String^ amount;
        while (strPtr != NULL) {
            title = Convert_string_to_String(strPtr->getData()->getData().get_GuitarPtr()->getData().get_Title());
            amount = Convert_string_to_String(strPtr->getData()->getData().get_Amount());
            SupplyGridView->Rows->Add(title, amount);
            strPtr = strPtr->getNext();
        }
    }

    return System::Void();
}

System::Void Muztorg::Supplies::Supplies_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Form^ form = Application::OpenForms[0];
    form->Show();
    return System::Void();
}

System::Void Muztorg::Supplies::Box_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (BoxActive)
        DataChanged = true;
    return System::Void();
}

System::Void Muztorg::Supplies::Box_Enter(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = true;
    return System::Void();
}

System::Void Muztorg::Supplies::Box_Leave(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = false;
    return System::Void();
}

System::Void Muztorg::Supplies::Prev_Click(System::Object^ sender, System::EventArgs^ e)
{

    this->AddMode = false;
    EmployeeBox->Enabled = false;
    DateMaskedBox->ReadOnly = true;
    ToggleChange->Visible = true;
    ToggleChangesOff->Visible = false;

    if (this->DataChanged == true)
    {

        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Supply sValue;
            String^ BigString;
            string smallString;

            this->DataChanged = false;
            sValue.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = EmployeeBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_EmployeePtr(EmployeeBase->_search_FullName(smallString));

            BigString = DateMaskedBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_Date(smallString);

            this->CurrentPtr->setData(sValue);
            MessageBox::Show("test");
        }
        else this->DataChanged = false;
    }

    if (this->CurrentPtr->getPrev() == NULL)
        this->CurrentPtr = SupplyBase->getTail();
    else this->CurrentPtr = this->CurrentPtr->getPrev();

    SupplyGridView->Rows->Clear();
    EmployeeBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_EmployeePtr()->getData().get_FullName());
    DateMaskedBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Date());

    List<Unit<StructOfSupply>*>* StrList = this->StructOfSupplyBase->_search_Supply(this->CurrentPtr->getData().get_ID());
    if (StrList->getHead() != NULL) {
        Unit<Unit<StructOfSupply>*>* strPtr = StrList->getHead();
        String^ title;
        String^ amount;
        while (strPtr != NULL) {
            title = Convert_string_to_String(strPtr->getData()->getData().get_GuitarPtr()->getData().get_Title());
            amount = Convert_string_to_String(strPtr->getData()->getData().get_Amount());
            SupplyGridView->Rows->Add(title, amount);
            strPtr = strPtr->getNext();
        }
    }

    return System::Void();
}

System::Void Muztorg::Supplies::Next_Click(System::Object^ sender, System::EventArgs^ e)
{

    this->AddMode = false;
    EmployeeBox->Enabled = false;
    DateMaskedBox->ReadOnly = true;
    ToggleChange->Visible = true;
    ToggleChangesOff->Visible = false;

    if (this->DataChanged == true)
    {

        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Supply sValue;
            String^ BigString;
            string smallString;

            this->DataChanged = false;
            sValue.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = EmployeeBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_EmployeePtr(EmployeeBase->_search_FullName(smallString));

            BigString = DateMaskedBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_Date(smallString);

            this->CurrentPtr->setData(sValue);
            MessageBox::Show("test");
        }

        else this->DataChanged = false;
    }

    if (this->CurrentPtr->getNext() == NULL)
        this->CurrentPtr = SupplyBase->getHead();
    else this->CurrentPtr = this->CurrentPtr->getNext();

    SupplyGridView->Rows->Clear();
    EmployeeBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_EmployeePtr()->getData().get_FullName());
    DateMaskedBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Date());

    List<Unit<StructOfSupply>*>* StrList = this->StructOfSupplyBase->_search_Supply(this->CurrentPtr->getData().get_ID());
    if (StrList->getHead() != NULL) {
        Unit<Unit<StructOfSupply>*>* strPtr = StrList->getHead();
        String^ title;
        String^ amount;
        while (strPtr != NULL) {
            title = Convert_string_to_String(strPtr->getData()->getData().get_GuitarPtr()->getData().get_Title());
            amount = Convert_string_to_String(strPtr->getData()->getData().get_Amount());
            SupplyGridView->Rows->Add(title, amount);
            strPtr = strPtr->getNext();
        }
    }

    return System::Void();
}

System::Void Muztorg::Supplies::Add_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;
    Supply sValue;

    if (this->AddMode == true)
    {
        if (EmployeeBox->SelectedIndex == -1)
        {
            MessageBox::Show("Заполните поле \"Сотрудник\"");
            return System::Void();
        }
        if (!(DateMaskedBox->MaskCompleted))
        {
            MessageBox::Show("Заполните поле \"Дата продажи\"");
            return System::Void();
        }

        BigString = EmployeeBox->Text;
        Convert_String_to_string(BigString, smallString);
        sValue.set_EmployeePtr(EmployeeBase->_search_FullName(smallString));

        BigString = DateMaskedBox->Text;
        Convert_String_to_string(BigString, smallString);
        sValue.set_Date(smallString);

        sValue.set_ID(SupplyBase->getTail()->getData().get_ID() + 1);
        SupplyBase->push_back(sValue);
        //добавить msgbox

        EmployeeBox->Enabled = false;
        DateMaskedBox->ReadOnly = true;
        ToggleChange->Visible = true;
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
            this->DataChanged = false;
            sValue.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = EmployeeBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_EmployeePtr(EmployeeBase->_search_FullName(smallString));

            BigString = DateMaskedBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_Date(smallString);

            this->CurrentPtr->setData(sValue);
            MessageBox::Show("test");
        }
        else this->DataChanged = false;
    }

    DateMaskedBox->Clear();
    SupplyGridView->Rows->Clear();
    EmployeeBox->SelectedIndex = -1;
    EmployeeBox->Enabled = true;
    DateMaskedBox->ReadOnly = false;
    ToggleChange->Visible = false;
    ToggleChangesOff->Visible = true;
    this->AddMode = true;
    return System::Void();
}

/*System::Void Muztorg::Supplies::Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    int eraseFlag;
    Unit<Supply>* erasePtrSale;
    Unit<StructOfSupply>* erasePtrStr;

    if (this->AddMode == true)
    {
        this->AddMode = false;
        EmployeeBox->Enabled = false;
        DateMaskedBox->ReadOnly = true;
        ToggleChange->Visible = true;
        ToggleChangesOff->Visible = false;

        EmployeeBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_EmployeePtr()->getData().get_FullName());
        DateMaskedBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Date());

        List<Unit<StructOfSupply>*>* StrList = this->StructOfSupplyBase->_search_Supply(this->CurrentPtr->getData().get_ID());
        if (StrList->getHead() != NULL) {
            Unit<Unit<StructOfSupply>*>* strPtr = StrList->getHead();
            String^ title;
            String^ amount;
            while (strPtr != NULL) {
                title = Convert_string_to_String(strPtr->getData()->getData().get_GuitarPtr()->getData().get_Title());
                amount = Convert_string_to_String(strPtr->getData()->getData().get_Amount());
                SupplyGridView->Rows->Add(title, amount);
                strPtr = strPtr->getNext();
            }
        }

        return System::Void();
    }

    if (MessageBox::Show("Вы уверенны что хотите удалить эту запить? Отменить это действие будет невозможно.", "Подтверждение удаления", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
        ::System::Windows::Forms::DialogResult::No)
        return System::Void();

    erasePtrSale = this->CurrentPtr;

    if (this->CurrentPtr->getNext() == NULL)
        this->CurrentPtr = SupplyBase->getHead();
    else this->CurrentPtr = this->CurrentPtr->getNext();

    eraseFlag = SupplyBase->erase(erasePtrSale);

    if (eraseFlag == 500) {
        MessageBox::Show("500");
        this->CurrentPtr = erasePtrSale;
        return System::Void();
    }
    if (eraseFlag == 404) {
        MessageBox::Show("404");
        this->CurrentPtr = erasePtrSale;
        return System::Void();
    }

    EmployeeBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_EmployeePtr()->getData().get_FullName());
    DateMaskedBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Date());

    List<Unit<StructOfSupply>*>* StrList = this->StructOfSupplyBase->_search_Supply(this->CurrentPtr->getData().get_ID());
    if (StrList->getHead() != NULL) {
        Unit<Unit<StructOfSupply>*>* strPtr = StrList->getHead();
        String^ title;
        String^ amount;
        while (strPtr != NULL) {
            title = Convert_string_to_String(strPtr->getData()->getData().get_GuitarPtr()->getData().get_Title());
            amount = Convert_string_to_String(strPtr->getData()->getData().get_Amount());
            SupplyGridView->Rows->Add(title, amount);
            strPtr = strPtr->getNext();
        }
    }

    return System::Void();
}*/

System::Void Muztorg::Supplies::ToggleChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    EmployeeBox->Enabled = true;
    DateMaskedBox->ReadOnly = false;
    ToggleChange->Visible = false;
    ToggleChangesOff->Visible = true;
    return System::Void();
}

System::Void Muztorg::Supplies::Save_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;

    if (this->DataChanged == true)
    {

        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Supply sValue;
            String^ BigString;
            string smallString;

            this->DataChanged = false;
            sValue.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = EmployeeBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_EmployeePtr(EmployeeBase->_search_FullName(smallString));

            BigString = DateMaskedBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_Date(smallString);

            this->CurrentPtr->setData(sValue);
            MessageBox::Show("test");
        }

        else this->DataChanged = false;
    }

    return System::Void();
}

System::Void Muztorg::Supplies::strOfSupply_Click(System::Object^ sender, System::EventArgs^ e)
{
    Muztorg::StructOfSupplies ^ form = gcnew StructOfSupplies(CurrentPtr);
    form->set_StructsOfSuppliesBase(this->StructOfSupplyBase);
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

System::Void Muztorg::Supplies::ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e)
{
    EmployeeBox->Enabled = false;
    DateMaskedBox->ReadOnly = true;
    ToggleChange->Visible = true;
    ToggleChangesOff->Visible = false;
    return System::Void();
}

System::Void Muztorg::Supplies::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    return System::Void();
}