#include "Sales.h"

System::Void Muztorg::Sales::Sales_Load(System::Object^ sender, System::EventArgs^ e)
{
    double sumOfSale = 0.0;
    String^ tmpSum;

    BuyerBox->Enabled = false;
    EmployeeBox->Enabled = false;
    DateMaskedBox->ReadOnly = true;
    SaleGridView->ReadOnly = true;
    SaleGridView->AllowUserToAddRows = false;
    ToggleChange->Visible = true;
    ToggleChangesOff->Visible = false;
    this->DataChanged = false;

    DataGridViewComboBoxColumn^ Title = gcnew DataGridViewComboBoxColumn();
    Title->HeaderText = "Товар";
    Title->ReadOnly = true;
    Title->Width = 335;
    Title->Name = "Title";
    Title->CellTemplate = gcnew DataGridViewComboBoxCell();

    /*for each (DataGridViewRow ^ row in SaleGridView->Rows)
    {
        row->ReadOnly = true;
    }

    dataGridView1.Rows[1].ReadOnly = false;*/

    /*DataGridViewColumn^ Title = gcnew DataGridViewColumn();
    Title->HeaderText = "Товар";
    Title->ReadOnly = true;
    Title->Width = 335;
    Title->Name = "Title";
    Title->CellTemplate = gcnew DataGridViewTextBoxCell();*/

    DataGridViewColumn^ Price = gcnew DataGridViewColumn();
    Price->HeaderText = "Цена";
    Price->ReadOnly = true;
    Price->Width = 135;
    Price->Name = "Price";
    Price->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Amount = gcnew DataGridViewColumn();
    Amount->HeaderText = "Кол-во";
    Amount->ReadOnly = true;
    Amount->Width = 65;
    Amount->Name = "Amount";
    Amount->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Sum = gcnew DataGridViewColumn();
    Sum->HeaderText = "Сумма";
    Sum->ReadOnly = true;
    Sum->Width = 135;
    Sum->Name = "Sum";
    Sum->CellTemplate = gcnew DataGridViewTextBoxCell();

    Unit<Buyer>* bPtr = this->BuyerBase->getHead();
    while (bPtr != NULL)
    {
        BuyerBox->Items->Add(Convert_string_to_String(bPtr->getData().get_FullName()));
        bPtr = bPtr->getNext();
    }

    Unit<Employee>* ePtr = this->EmployeeBase->getHead();
    while (ePtr != NULL)
    {
        EmployeeBox->Items->Add(Convert_string_to_String(ePtr->getData().get_FullName()));
        ePtr = ePtr->getNext();
    }

    Unit<Guitar>* gPtr = this->GuitarBase->getHead();
    while (gPtr != NULL)
    {
        Title->Items->Add(Convert_string_to_String(gPtr->getData().get_Title()));
        gPtr = gPtr->getNext();
    }

    SaleGridView->Columns->Add(Title);
    SaleGridView->Columns->Add(Price);
    SaleGridView->Columns->Add(Amount);
    SaleGridView->Columns->Add(Sum);
    SaleGridView->ReadOnly = true;

    this->CurrentPtr = this->SaleBase->getHead();
    BuyerBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_BuyerPtr()->getData().get_FullName());
    EmployeeBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_EmployeePtr()->getData().get_FullName());
    DateMaskedBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Date());

    this->CurrentStrPtr = this->StructOfSaleBase->_search_Sale(this->CurrentPtr->getData().get_ID());
    if (this->CurrentStrPtr->getHead() != NULL) {
        Unit<Unit<StructOfSale>*>* strPtr = this->CurrentStrPtr->getHead();
        String^ title;
        String^ price;
        String^ amount;
        String^ summary;

        while (strPtr != NULL) {
            title = Convert_string_to_String(strPtr->getData()->getData().get_GuitarPtr()->getData().get_Title());
            price = Convert_string_to_String(strPtr->getData()->getData().get_GuitarPtr()->getData().get_Price());
            amount = Convert_string_to_String(strPtr->getData()->getData().get_Amount());
            summary = (Convert::ToDouble(price) * Convert::ToDouble(amount)).ToString();
            sumOfSale += Convert::ToDouble(summary);
            SaleGridView->Rows->Add(title, price = String::Format("{0} $", price), 
                amount, summary = String::Format("{0} $", summary));
            strPtr = strPtr->getNext();
        }
    }
    
    tmpSum = sumOfSale.ToString();
    tmpSum = String::Format("{0} $", tmpSum);
    SumBox->Text = tmpSum;
    return System::Void();
}

System::Void Muztorg::Sales::Sales_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Form^ form = Application::OpenForms[0];
    form->Show();
    return System::Void();
}

System::Void Muztorg::Sales::Box_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (BoxActive)
        DataChanged = true;
    return System::Void();
}

System::Void Muztorg::Sales::Box_Enter(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = true;
    return System::Void();
}

System::Void Muztorg::Sales::Box_Leave(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = false;
    return System::Void();
}

System::Void Muztorg::Sales::SaleGridView_OnCellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    this->BoxActive = false;
    return System::Void();
}

System::Void Muztorg::Sales::SaleGridView_OnCellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e)
{
    this->BoxActive = true;
    return System::Void();
}

System::Void Muztorg::Sales::SaleGridView_OnCellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (BoxActive)
        DataChanged = true;
    return System::Void();
}

System::Void Muztorg::Sales::SaleGridView_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e)
{
    e->Control->TextChanged -= gcnew System::EventHandler(this, &Sales::TextBox_Changed);
    e->Control->TextChanged += gcnew System::EventHandler(this, &Sales::TextBox_Changed);
}

System::Void Muztorg::Sales::TextBox_Changed(System::Object^ sender, System::EventArgs^ e)
{
    string smallString;
    String^ BigString;
    String^ formatString;

    int row = this->SaleGridView->CurrentCell->RowIndex;
    auto currentRow = this->SaleGridView->Rows[row];

    BigString = currentRow->Cells["Title"]->EditedFormattedValue->ToString();
    Convert_String_to_string(BigString, smallString);
    Unit<Guitar>* currentGuitar = GuitarBase->_search_Title(smallString);
    String^ price = Convert_string_to_String(currentGuitar->getData().get_Price());

    formatString = String::Format("{0} $", price);
    currentRow->Cells["Price"]->Value = formatString;

    if (!String::IsNullOrEmpty(currentRow->Cells["Amount"]->
        EditedFormattedValue->ToString()))
    { 
        int sumOfSale = 0;
        if (!String::IsNullOrEmpty(SumBox->Text)) 
        {
            BigString = SumBox->Text;
            Convert_String_to_string(BigString, smallString);
            sumOfSale = stoi(smallString);
        }

        if (!String::IsNullOrEmpty(currentRow->Cells["Sum"]->
            EditedFormattedValue->ToString()))
        {
            BigString = currentRow->Cells["Sum"]->EditedFormattedValue->ToString();
            Convert_String_to_string(BigString, smallString);
            int oldSumOfGuitar = stoi(smallString);
            sumOfSale = sumOfSale - oldSumOfGuitar;
        }

        String^ amount = currentRow->Cells["Amount"]->EditedFormattedValue->ToString();
        String^ summary = (Convert::ToInt32(price) * Convert::ToDouble(amount)).ToString();
        currentRow->Cells["Sum"]->Value = formatString = String::Format("{0} $", summary);

        sumOfSale += Convert::ToInt32(summary);
        SumBox->Text = formatString = String::Format("{0} $", sumOfSale);
    }
}

System::Void Muztorg::Sales::Prev_Click(System::Object^ sender, System::EventArgs^ e)
{

    this->AddMode = false;
    BuyerBox->Enabled = false;
    EmployeeBox->Enabled = false;
    DateMaskedBox->ReadOnly = true;
    SaleGridView->ReadOnly = true;
    SaleGridView->AllowUserToAddRows = false;
    ToggleChange->Visible = true;
    ToggleChangesOff->Visible = false;

    if (this->DataChanged == true)
    {

        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Sale sValue;
            String^ BigString;
            string smallString;

            this->DataChanged = false;
            sValue.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = BuyerBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_BuyerPtr(BuyerBase->_search_FullName(smallString));

            BigString = EmployeeBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_EmployeePtr(EmployeeBase->_search_FullName(smallString));

            BigString = DateMaskedBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_Date(smallString);

            this->CurrentPtr->setData(sValue);

            Unit<Unit<StructOfSale>*>* strPtr = this->CurrentStrPtr->getHead();
            StructOfSale strValue;

            if (this->CurrentStrPtr->getHead() != NULL) {
                for each (DataGridViewRow ^ row in SaleGridView->Rows) {
                    strValue.set_SalePtr(CurrentPtr);

                    BigString = row->Cells["Title"]->EditedFormattedValue->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_GuitarPtr(GuitarBase->_search_Title(smallString));

                    BigString = row->Cells["Amount"]->EditedFormattedValue->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_Amount(smallString);

                    strPtr->getData()->setData(strValue);
                    strPtr = strPtr->getNext();
                }
            }
        }
        else this->DataChanged = false;
    }

    if (this->CurrentPtr->getPrev() == NULL)
        this->CurrentPtr = SaleBase->getTail();
    else this->CurrentPtr = this->CurrentPtr->getPrev();

    String^ tmpSum;
    auto sumOfSale = 0.0;
    SaleGridView->Rows->Clear();

    BuyerBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_BuyerPtr()->getData().get_FullName());
    EmployeeBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_EmployeePtr()->getData().get_FullName());
    DateMaskedBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Date());

    this->CurrentStrPtr = this->StructOfSaleBase->_search_Sale(this->CurrentPtr->getData().get_ID());
    if (this->CurrentStrPtr->getHead() != NULL) {
        Unit<Unit<StructOfSale>*>* strPtr = this->CurrentStrPtr->getHead();
        String^ title;
        String^ price;
        String^ amount;
        String^ summary;
        while (strPtr != NULL) {
            title = Convert_string_to_String(strPtr->getData()->getData().get_GuitarPtr()->getData().get_Title());
            price = Convert_string_to_String(strPtr->getData()->getData().get_GuitarPtr()->getData().get_Price());
            amount = Convert_string_to_String(strPtr->getData()->getData().get_Amount());
            summary = (Convert::ToDouble(price) * Convert::ToDouble(amount)).ToString();
            sumOfSale += Convert::ToDouble(summary);
            SaleGridView->Rows->Add(title, price = String::Format("{0} $", price),
                amount, summary = String::Format("{0} $", summary));
            strPtr = strPtr->getNext();
        }
    }

    tmpSum = sumOfSale.ToString();
    tmpSum = String::Format("{0} $", tmpSum);
    SumBox->Text = tmpSum;
    return System::Void();
}

System::Void Muztorg::Sales::Next_Click(System::Object^ sender, System::EventArgs^ e)
{

    this->AddMode = false;
    BuyerBox->Enabled = false;
    EmployeeBox->Enabled = false;
    DateMaskedBox->ReadOnly = true;
    SaleGridView->ReadOnly = true;
    SaleGridView->AllowUserToAddRows = false;
    ToggleChange->Visible = true;
    ToggleChangesOff->Visible = false;

    if (this->DataChanged == true)
    {

        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Sale sValue;
            String^ BigString;
            string smallString;

            this->DataChanged = false;
            sValue.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = BuyerBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_BuyerPtr(BuyerBase->_search_FullName(smallString));

            BigString = EmployeeBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_EmployeePtr(EmployeeBase->_search_FullName(smallString));

            BigString = DateMaskedBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_Date(smallString);

            this->CurrentPtr->setData(sValue);

            Unit<Unit<StructOfSale>*>* strPtr = this->CurrentStrPtr->getHead();
            StructOfSale strValue;

            if (this->CurrentStrPtr->getHead() != NULL) {
                for each (DataGridViewRow ^ row in SaleGridView->Rows) {
                    strValue.set_SalePtr(CurrentPtr);

                    BigString = row->Cells["Title"]->EditedFormattedValue->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_GuitarPtr(GuitarBase->_search_Title(smallString));

                    BigString = row->Cells["Amount"]->EditedFormattedValue->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_Amount(smallString);

                    strPtr->getData()->setData(strValue);
                    strPtr = strPtr->getNext();
                }
            }
        }
        else this->DataChanged = false;
    }

    if (this->CurrentPtr->getNext() == NULL)
        this->CurrentPtr = SaleBase->getHead();
    else this->CurrentPtr = this->CurrentPtr->getNext();

    String^ tmpSum;
    auto sumOfSale = 0.0;
    SaleGridView->Rows->Clear();

    BuyerBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_BuyerPtr()->getData().get_FullName());
    EmployeeBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_EmployeePtr()->getData().get_FullName());
    DateMaskedBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Date());

    this->CurrentStrPtr = this->StructOfSaleBase->_search_Sale(this->CurrentPtr->getData().get_ID());
    if (this->CurrentStrPtr->getHead() != NULL) {
        Unit<Unit<StructOfSale>*>* strPtr = this->CurrentStrPtr->getHead();
        String^ title;
        String^ price;
        String^ amount;
        String^ summary;
        while (strPtr != NULL) {
            title = Convert_string_to_String(strPtr->getData()->getData().get_GuitarPtr()->getData().get_Title());
            price = Convert_string_to_String(strPtr->getData()->getData().get_GuitarPtr()->getData().get_Price());
            amount = Convert_string_to_String(strPtr->getData()->getData().get_Amount());
            summary = (Convert::ToDouble(price) * Convert::ToDouble(amount)).ToString();
            sumOfSale += Convert::ToDouble(summary);
            SaleGridView->Rows->Add(title, price = String::Format("{0} $", price),
                amount, summary = String::Format("{0} $", summary));
            strPtr = strPtr->getNext();
        }
    }

    tmpSum = sumOfSale.ToString();
    tmpSum = String::Format("{0} $", tmpSum);
    SumBox->Text = tmpSum;
    return System::Void();
}

System::Void Muztorg::Sales::Add_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;
    StructOfSale strValue;
    Sale sValue;

    if (this->AddMode == true)
    {
        SaleGridView->AllowUserToAddRows = false;
        if (BuyerBox->SelectedIndex == -1)
        {
            MessageBox::Show("Заполните поле \"Покупатель\"");
            return System::Void();
        }
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
        if (SaleGridView["Title", 0]->Value == NULL)
        {
            MessageBox::Show("Заполните поле \"Название товара\"");
            return System::Void();
        }
        if (SaleGridView["Amount", 0]->Value == NULL)
        {
            MessageBox::Show("Заполните поле \"Название товара\"");
            return System::Void();
        }

        BigString = BuyerBox->Text;
        Convert_String_to_string(BigString, smallString);
        sValue.set_BuyerPtr(BuyerBase->_search_FullName(smallString));

        BigString = EmployeeBox->Text;
        Convert_String_to_string(BigString, smallString);
        sValue.set_EmployeePtr(EmployeeBase->_search_FullName(smallString));

        BigString = DateMaskedBox->Text;
        Convert_String_to_string(BigString, smallString);
        sValue.set_Date(smallString);

        sValue.set_ID(SaleBase->getTail()->getData().get_ID() + 1);
        SaleBase->push_back(sValue);

        for each (DataGridViewRow ^ row in SaleGridView->Rows) {
            strValue.set_SalePtr(SaleBase->_search_Sale(sValue.get_ID()));

            BigString = row->Cells["Title"]->EditedFormattedValue->ToString();
            Convert_String_to_string(BigString, smallString);
            strValue.set_GuitarPtr(GuitarBase->_search_Title(smallString));

            BigString = row->Cells["Amount"]->EditedFormattedValue->ToString();
            Convert_String_to_string(BigString, smallString);
            strValue.set_Amount(smallString);

            StructOfSaleBase->push_back(strValue);
        }

        BuyerBox->Enabled = false;
        EmployeeBox->Enabled = false;
        DateMaskedBox->ReadOnly = true;
        SaleGridView->ReadOnly = true;
        SaleGridView->AllowUserToAddRows = false;
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

            BigString = BuyerBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_BuyerPtr(BuyerBase->_search_FullName(smallString));

            BigString = EmployeeBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_EmployeePtr(EmployeeBase->_search_FullName(smallString));

            BigString = DateMaskedBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_Date(smallString);

            this->CurrentPtr->setData(sValue);

            Unit<Unit<StructOfSale>*>* strPtr = this->CurrentStrPtr->getHead();
            StructOfSale strValue;

            if (this->CurrentStrPtr->getHead() != NULL) {
                //CurrentStrPtr->clear();
                for each (DataGridViewRow ^ row in SaleGridView->Rows) {
                    strValue.set_SalePtr(CurrentPtr);

                    BigString = row->Cells["Title"]->EditedFormattedValue->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_GuitarPtr(GuitarBase->_search_Title(smallString));

                    BigString = row->Cells["Amount"]->EditedFormattedValue->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_Amount(smallString);

                    strPtr->getData()->setData(strValue);
                    //CurrentStrPtr->push_back(strPtr->getData());
                    strPtr = strPtr->getNext();
                }
            }
        }
        else this->DataChanged = false;
    }

    DateMaskedBox->Clear();
    SumBox->Clear();
    SaleGridView->Rows->Clear();
    BuyerBox->SelectedIndex = -1;
    EmployeeBox->SelectedIndex = -1;
    BuyerBox->Enabled = true;
    EmployeeBox->Enabled = true;
    DateMaskedBox->ReadOnly = false;
    SaleGridView->ReadOnly = false;
    SaleGridView->AllowUserToAddRows = true;
    ToggleChange->Visible = false;
    ToggleChangesOff->Visible = true;
    this->AddMode = true;
    return System::Void();
}

System::Void Muztorg::Sales::ToggleChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    BuyerBox->Enabled = true;
    EmployeeBox->Enabled = true;
    DateMaskedBox->ReadOnly = false;
    SaleGridView->ReadOnly = false;
    SaleGridView->AllowUserToAddRows = true;
    ToggleChange->Visible = false;
    ToggleChangesOff->Visible = true;
    return System::Void();
}

System::Void Muztorg::Sales::Save_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;

    if (this->DataChanged == true)
    {

        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Sale sValue;
            String^ BigString;
            string smallString;

            this->DataChanged = false;
            sValue.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = BuyerBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_BuyerPtr(BuyerBase->_search_FullName(smallString));

            BigString = EmployeeBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_EmployeePtr(EmployeeBase->_search_FullName(smallString));

            BigString = DateMaskedBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_Date(smallString);

            this->CurrentPtr->setData(sValue);
            
            Unit<Unit<StructOfSale>*>* strPtr = this->CurrentStrPtr->getHead();
            StructOfSale strValue;

            if (this->CurrentStrPtr->getHead() != NULL) {
                //CurrentStrPtr->clear();
                for each (DataGridViewRow ^ row in SaleGridView->Rows) {
                    strValue.set_SalePtr(CurrentPtr);

                    BigString = row->Cells["Title"]->EditedFormattedValue->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_GuitarPtr(GuitarBase->_search_Title(smallString));

                    BigString = row->Cells["Amount"]->EditedFormattedValue->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_Amount(smallString);

                    strPtr->getData()->setData(strValue);
                    //CurrentStrPtr->push_back(strPtr->getData());
                    strPtr = strPtr->getNext();
                }
            }
        }
        else this->DataChanged = false;
    }

    return System::Void();
}

System::Void Muztorg::Sales::Check_Click(System::Object^ sender, System::EventArgs^ e)
{
    Muztorg::Check_Report^ form = gcnew Check_Report(CurrentPtr);
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

System::Void Muztorg::Sales::strOfSale_Click(System::Object^ sender, System::EventArgs^ e)
{
    Muztorg::StructOfSales^ form = gcnew StructOfSales(CurrentPtr);
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

System::Void Muztorg::Sales::ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e)
{
    BuyerBox->Enabled = false;
    EmployeeBox->Enabled = false;
    DateMaskedBox->ReadOnly = true;
    SaleGridView->ReadOnly = true;
    SaleGridView->AllowUserToAddRows = false;
    ToggleChange->Visible = true;
    ToggleChangesOff->Visible = false;
    return System::Void();
}

System::Void Muztorg::Sales::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    return System::Void();
}
