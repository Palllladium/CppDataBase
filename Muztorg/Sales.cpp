#include "Sales.h"

System::Void Muztorg::Sales::Sales_Load(System::Object^ sender, System::EventArgs^ e)
{
    double sumOfSale = 0.0;
    String^ tmpSum;

    BuyerBox->Enabled = false;
    EmployeeBox->Enabled = false;
    DateBox->ReadOnly = true;
    SumBox->ReadOnly = true;
    ToggleChange->Visible = true;
    ToggleChangesOff->Visible = false;

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

    DataGridViewComboBoxColumn^ Title = gcnew DataGridViewComboBoxColumn();
    Title->HeaderText = "�����";
    Title->ReadOnly = true;
    Title->Width = 200;
    Title->Name = "Title";

    Unit<Guitar>* gPtr = this->GuitarBase->getHead();
    while (gPtr != NULL)
    {
        Title->Items->Add(Convert_string_to_String(gPtr->getData().get_Title()));
        gPtr = gPtr->getNext();
    }

    DataGridViewColumn^ Price = gcnew DataGridViewColumn();
    Price->HeaderText = "����";
    Price->ReadOnly = true;
    Price->Width = 100;
    Price->Name = "Price";
    Price->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Amount = gcnew DataGridViewColumn();
    Amount->HeaderText = "���-��";
    Amount->ReadOnly = true;
    Amount->Width = 100;
    Amount->Name = "Amount";
    Amount->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Sum = gcnew DataGridViewColumn();
    Sum->HeaderText = "�����";
    Sum->ReadOnly = true;
    Sum->Width = 100;
    Sum->Name = "Sum";
    Sum->CellTemplate = gcnew DataGridViewTextBoxCell();

    SaleGridView->Columns->Add(Title);
    SaleGridView->Columns->Add(Price);
    SaleGridView->Columns->Add(Amount);
    SaleGridView->Columns->Add(Sum);
    SaleGridView->ReadOnly = true;

    this->CurrentPtr = this->SaleBase->getHead();

    BuyerBox->Text = Convert_string_to_String(this->CurrentPtr->
        getData().get_BuyerPtr()->getData().get_FullName());

    EmployeeBox->Text = Convert_string_to_String(this->CurrentPtr->
        getData().get_EmployeePtr()->getData().get_FullName());

    DateBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Date());

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

System::Void Muztorg::Sales::SaleGridView_CellEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    this->BoxActive = true;
    return System::Void();
}

System::Void Muztorg::Sales::SaleGridView_CellLeave(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    this->BoxActive = false;
    return System::Void();
}

System::Void Muztorg::Sales::SaleGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

    if (BoxActive)
        DataChanged = true;
    return System::Void();
}

System::Void Muztorg::Sales::Prev_Click(System::Object^ sender, System::EventArgs^ e)
{

    this->AddMode = false;
    BuyerBox->Enabled = false;
    EmployeeBox->Enabled = false;
    DateBox->ReadOnly = true;
    SumBox->ReadOnly = true;
    SaleGridView->ReadOnly = true;
    ToggleChange->Visible = true;
    ToggleChangesOff->Visible = false;

    if (this->DataChanged == true)
    {

        if (MessageBox::Show("��������� ��������� ���������?", "������������� ���������", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Sale sValue;
            String^ BigString;
            string smallString;
            StructOfSale strValue;
            Unit<StructOfSale>* tmpSumUnit;
            List<Unit<StructOfSale>*>* tmpSumList;
            Unit<Unit<StructOfSale>*>* strPtr;

            this->DataChanged = false;
            sValue.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = BuyerBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_BuyerPtr(BuyerBase->_search_FullName(smallString));

            BigString = EmployeeBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_EmployeePtr(EmployeeBase->_search_FullName(smallString));

            BigString = DateBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_Date(smallString);

            this->CurrentPtr->setData(sValue);

            if (this->CurrentStrPtr->getHead() != NULL) {
                strPtr = this->CurrentStrPtr->getHead();
                auto counter = 0;
                while (strPtr != NULL) {

                    strValue.set_SalePtr(CurrentPtr);

                    BigString = SaleGridView["Title", counter]->Value->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_GuitarPtr(GuitarBase->_search_Title(smallString));

                    BigString = SaleGridView["Amount", counter]->Value->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_Amount(smallString);
                    
                    tmpSumUnit->setData(strValue);
                    tmpSumList->push_back(tmpSumUnit);
                    counter++;
                }
            }

            this->CurrentStrPtr = tmpSumList;
            MessageBox::Show("��� ��������� ������� ������ ������� ���������� ������� � ��������������� �����.", "��������� � ����");
        }
    }

    if (this->CurrentPtr->getPrev() == NULL)
        this->CurrentPtr = SaleBase->getTail();
    else this->CurrentPtr = this->CurrentPtr->getPrev();

    String^ tmpSum;
    auto sumOfSale = 0.0;

    BuyerBox->Text = Convert_string_to_String(this->CurrentPtr->
        getData().get_BuyerPtr()->getData().get_FullName());

    EmployeeBox->Text = Convert_string_to_String(this->CurrentPtr->
        getData().get_EmployeePtr()->getData().get_FullName());

    DateBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Date());

    SaleGridView->Rows->Clear();

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
    DateBox->ReadOnly = true;
    SumBox->ReadOnly = true;
    SaleGridView->ReadOnly = true;
    ToggleChange->Visible = true;
    ToggleChangesOff->Visible = false;

    if (this->DataChanged == true)
    {

        if (MessageBox::Show("��������� ��������� ���������?", "������������� ���������", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Sale sValue;
            String^ BigString;
            string smallString;
            StructOfSale strValue;
            Unit<StructOfSale>* tmpSumUnit;
            List<Unit<StructOfSale>*>* tmpSumList;
            Unit<Unit<StructOfSale>*>* strPtr;

            this->DataChanged = false;
            sValue.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = BuyerBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_BuyerPtr(BuyerBase->_search_FullName(smallString));

            BigString = EmployeeBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_EmployeePtr(EmployeeBase->_search_FullName(smallString));

            BigString = DateBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_Date(smallString);

            this->CurrentPtr->setData(sValue);

            if (this->CurrentStrPtr->getHead() != NULL) {
                strPtr = this->CurrentStrPtr->getHead();
                auto counter = 0;
                while (strPtr != NULL) {

                    strValue.set_SalePtr(CurrentPtr);

                    BigString = SaleGridView["Title", counter]->Value->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_GuitarPtr(GuitarBase->_search_Title(smallString));

                    BigString = SaleGridView["Amount", counter]->Value->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_Amount(smallString);

                    tmpSumUnit->setData(strValue);
                    tmpSumList->push_back(tmpSumUnit);
                    counter++;
                }
            }

            this->CurrentStrPtr = tmpSumList;
            MessageBox::Show("��� ��������� ������� ������ ������� ���������� ������� � ��������������� �����.", "��������� � ����");
        }
    }

    if (this->CurrentPtr->getPrev() == NULL)
        this->CurrentPtr = SaleBase->getTail();
    else this->CurrentPtr = this->CurrentPtr->getPrev();

    String^ tmpSum;
    auto sumOfSale = 0.0;

    BuyerBox->Text = Convert_string_to_String(this->CurrentPtr->
        getData().get_BuyerPtr()->getData().get_FullName());

    EmployeeBox->Text = Convert_string_to_String(this->CurrentPtr->
        getData().get_EmployeePtr()->getData().get_FullName());

    DateBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Date());

    SaleGridView->Rows->Clear();

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
    Unit<Unit<StructOfSale>*>* strPtr;
    String^ BigString;
    string smallString;
    Sale sValue;

    if (this->AddMode == true)
    {
        if (BuyerBox->SelectedIndex == -1)
        {
            MessageBox::Show("��������� ���� \"����������\"");
            return System::Void();
        }
        if (EmployeeBox->SelectedIndex == -1)
        {
            MessageBox::Show("��������� ���� \"���������\"");
            return System::Void();
        }
        if (DateBox->Text == "")
        {
            MessageBox::Show("��������� ���� \"���� �������\"");
            return System::Void();
        }

        BigString = BuyerBox->Text;
        Convert_String_to_string(BigString, smallString);
        sValue.set_BuyerPtr(BuyerBase->
            _search_FullName(smallString));

        BigString = EmployeeBox->Text;
        Convert_String_to_string(BigString, smallString);
        sValue.set_EmployeePtr(EmployeeBase->
            _search_FullName(smallString));

        BigString = DateBox->Text;
        Convert_String_to_string(BigString, smallString);
        sValue.set_Date(smallString);

        sValue.set_ID(SaleBase->getTail()->getData().get_ID() + 1);
        SaleBase->push_back(sValue);

        MessageBox::Show("��� ��������� ������� ������ ������� ���������� ������� � ��������������� �����.", "��������� � ����");

        BuyerBox->Enabled = false;
        EmployeeBox->Enabled = false;
        DateBox->ReadOnly = true;
        SumBox->ReadOnly = true;
        SaleGridView->ReadOnly = true;
        ToggleChange->Visible = true;
        ToggleChangesOff->Visible = false;
        this->AddMode = false;
        this->DataChanged = false;
        return System::Void();
    }

    if (this->DataChanged == true)
    {
        Sale sValue;
        StructOfSale strValue;
        Unit<StructOfSale>* tmpSumUnit;
        List<Unit<StructOfSale>*>* tmpSumList;

        if (MessageBox::Show("��������� ��������� ���������?", "������������� ���������", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            this->DataChanged = false;
            sValue.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = BuyerBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_BuyerPtr(BuyerBase->
                _search_FullName(smallString));

            BigString = EmployeeBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_EmployeePtr(EmployeeBase->
                _search_FullName(smallString));

            BigString = DateBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_Date(smallString);

            this->CurrentPtr->setData(sValue);
            if (this->CurrentStrPtr->getHead() != NULL) {
                strPtr = this->CurrentStrPtr->getHead();
                auto counter = 0;
                while (strPtr != NULL) {

                    strValue.set_SalePtr(CurrentPtr);

                    BigString = SaleGridView["Title", counter]->Value->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_GuitarPtr(GuitarBase->
                        _search_Title(smallString));

                    BigString = SaleGridView["Amount", counter]->Value->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_Amount(smallString);

                    tmpSumUnit->setData(strValue);
                    tmpSumList->push_back(tmpSumUnit);
                    counter++;
                }
            }

            this->CurrentStrPtr = tmpSumList;
            MessageBox::Show("��� ��������� ������� ������ ������� ���������� ������� � ��������������� �����.", "��������� � ����");
        }
    }

    DateBox->Clear();
    SumBox->Clear();
    SaleGridView->Rows->Clear();
    BuyerBox->SelectedIndex = -1;
    EmployeeBox->SelectedIndex = -1;
    BuyerBox->Enabled = true;
    EmployeeBox->Enabled = true;
    DateBox->ReadOnly = false;
    SumBox->ReadOnly = true;
    SaleGridView->ReadOnly = false;
    SaleGridView->Columns["Price"]->ReadOnly = true;
    SaleGridView->Columns["Sum"]->ReadOnly = true;
    ToggleChange->Visible = false;
    ToggleChangesOff->Visible = true;
    this->AddMode = true;
    return System::Void();
}

System::Void Muztorg::Sales::Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    int eraseFlag;
    string errorMessage;
    String^ BigString;
    string smallString;

    Unit<Sale>* erasePtr;

    if (this->AddMode == true)
    {
        this->AddMode = false;
        BuyerBox->Enabled = false;
        EmployeeBox->Enabled = false;
        DateBox->ReadOnly = true;
        SumBox->ReadOnly = true;
        SaleGridView->ReadOnly = true;
        ToggleChange->Visible = true;
        ToggleChangesOff->Visible = false;

        Unit<Unit<StructOfSale>*>* strPtr;
        String^ title;
        String^ price;
        String^ amount;
        String^ summary;
        String^ tmpSum;
        auto sumOfGuitars = 0.0;
        auto sumOfSale = 0.0;

        smallString = this->CurrentPtr->
            getData().get_BuyerPtr()->getData().get_FullName();
        BigString = Convert_string_to_String(smallString);
        BuyerBox->Text = BigString;

        smallString = this->CurrentPtr->
            getData().get_EmployeePtr()->getData().get_FullName();
        BigString = Convert_string_to_String(smallString);
        EmployeeBox->Text = BigString;

        smallString = this->CurrentPtr->getData().get_Date();
        BigString = Convert_string_to_String(smallString);
        DateBox->Text = BigString;

        SaleGridView->Rows->Clear();

        this->CurrentStrPtr = this->StructOfSaleBase->
        _search_Sale(this->CurrentPtr->getData().get_ID());
        if (this->CurrentStrPtr->getHead() != NULL) {
            strPtr = this->CurrentStrPtr->getHead();
            auto counter = 0;
            while (strPtr != NULL) {
                smallString = strPtr->getData()->
                    getData().get_GuitarPtr()->getData().get_Title();
                title = Convert_string_to_String(smallString);
                smallString = strPtr->getData()->
                    getData().get_GuitarPtr()->getData().get_Price();
                price = Convert_string_to_String(smallString);
                smallString = strPtr->getData()->getData().get_Amount();
                amount = Convert_string_to_String(smallString);
                summary = (Convert::ToDouble(price) * Convert::ToDouble(amount)).ToString();
                sumOfSale += Convert::ToDouble(summary);
                SaleGridView->Rows->Add(title, price = String::Format("{0} $", price),
                    amount, summary = String::Format("{0} $", summary));
                strPtr = strPtr->getNext();
                counter++;
            }
        }

        tmpSum = sumOfSale.ToString();
        tmpSum = String::Format("{0} $", tmpSum);
        SumBox->Text = tmpSum;
        return System::Void();
    }

    if (MessageBox::Show("�� �������� ��� ������ ������� ��� ������? �������� ��� �������� ����� ����������.", "������������� ��������", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
        ::System::Windows::Forms::DialogResult::No)
        return System::Void();

    erasePtr = this->CurrentPtr;

    if (this->CurrentPtr->getNext() == NULL)
        this->CurrentPtr = SaleBase->getHead();
    else this->CurrentPtr = this->CurrentPtr->getNext();

    eraseFlag = SaleBase->erase(erasePtr);

    if (eraseFlag == 500) {
        MessageBox::Show("500");
        this->CurrentPtr = erasePtr;
        return System::Void();
    }
    if (eraseFlag == 404) {
        MessageBox::Show("404");
        this->CurrentPtr = erasePtr;
        return System::Void();
    }

    // ������� StructOfSale ����� ����, ������� StructOfSale � ptr, ��� ������� �������� �� SaleID

    Unit<Unit<StructOfSale>*>* strPtr;
    String^ title;
    String^ price;
    String^ amount;
    String^ summary;
    String^ tmpSum;
    auto sumOfGuitars = 0.0;
    auto sumOfSale = 0.0;

    smallString = this->CurrentPtr->
        getData().get_BuyerPtr()->getData().get_FullName();
    BigString = Convert_string_to_String(smallString);
    BuyerBox->Text = BigString;

    smallString = this->CurrentPtr->
        getData().get_EmployeePtr()->getData().get_FullName();
    BigString = Convert_string_to_String(smallString);
    EmployeeBox->Text = BigString;

    smallString = this->CurrentPtr->getData().get_Date();
    BigString = Convert_string_to_String(smallString);
    DateBox->Text = BigString;

    SaleGridView->Rows->Clear();

    this->CurrentStrPtr = this->StructOfSaleBase->
        _search_Sale(this->CurrentPtr->getData().get_ID());
    if (this->CurrentStrPtr->getHead() != NULL) {
        strPtr = this->CurrentStrPtr->getHead();
        auto counter = 1;
        while (strPtr != NULL) {
            smallString = strPtr->getData()->
                getData().get_GuitarPtr()->getData().get_Title();
            title = Convert_string_to_String(smallString);
            smallString = strPtr->getData()->
                getData().get_GuitarPtr()->getData().get_Price();
            price = Convert_string_to_String(smallString);
            smallString = strPtr->getData()->getData().get_Amount();
            amount = Convert_string_to_String(smallString);
            summary = (Convert::ToDouble(price) * Convert::ToDouble(amount)).ToString();
            sumOfSale += Convert::ToDouble(summary);
            SaleGridView->Rows->Add(title, price = String::Format("{0} $", price),
                amount, summary = String::Format("{0} $", summary));
            strPtr = strPtr->getNext();
            counter++;
        }
    }

    tmpSum = sumOfSale.ToString();
    tmpSum = String::Format("{0} $", tmpSum);
    SumBox->Text = tmpSum;
    return System::Void();
}

System::Void Muztorg::Sales::ToggleChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    BuyerBox->Enabled = true;
    EmployeeBox->Enabled = true;
    DateBox->ReadOnly = false;
    SumBox->ReadOnly = true;
    SaleGridView->ReadOnly = false;
    SaleGridView->Columns["Price"]->ReadOnly = true;
    SaleGridView->Columns["Sum"]->ReadOnly = true;
    ToggleChange->Visible = false;
    ToggleChangesOff->Visible = true;
    return System::Void();
}

System::Void Muztorg::Sales::Save_Click(System::Object^ sender, System::EventArgs^ e)
{
    Unit<Unit<StructOfSale>*>* strPtr;
    String^ BigString;
    string smallString;
    Sale sValue;

    if (this->DataChanged == true)
    {

        Sale sValue;
        StructOfSale strValue;
        Unit<StructOfSale>* tmpSumUnit;
        List<Unit<StructOfSale>*>* tmpSumList;

        if (MessageBox::Show("��������� ��������� ���������?", "������������� ���������", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            this->DataChanged = false;
            sValue.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = BuyerBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_BuyerPtr(BuyerBase->
                _search_FullName(smallString));

            BigString = EmployeeBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_EmployeePtr(EmployeeBase->
                _search_FullName(smallString));

            BigString = DateBox->Text;
            Convert_String_to_string(BigString, smallString);
            sValue.set_Date(smallString);

            this->CurrentPtr->setData(sValue);
            if (this->CurrentStrPtr->getHead() != NULL) {
                strPtr = this->CurrentStrPtr->getHead();
                auto counter = 0;
                while (strPtr != NULL) {

                    strValue.set_SalePtr(CurrentPtr);

                    BigString = SaleGridView["Title", counter]->Value->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_GuitarPtr(GuitarBase->
                        _search_Title(smallString));

                    BigString = SaleGridView["Amount", counter]->Value->ToString();
                    Convert_String_to_string(BigString, smallString);
                    strValue.set_Amount(smallString);

                    tmpSumUnit->setData(strValue);
                    tmpSumList->push_back(tmpSumUnit);
                    counter++;
                }
            }

            this->CurrentStrPtr = tmpSumList;
            //MessageBox::Show("��� ��������� ������� ������ ������� ���������� ������� � ��������������� �����.", "��������� � ����");
        }
    }

    return System::Void();
}

//System::Void Muztorg::Sales::Bill_Click(System::Object^ sender, System::EventArgs^ e)
//{
//    string path;
//    path = BillPathCreator(this->CurrentPtr->getData().get_ID());
//    ofstream fout;
//    fout.open(path);
//    if (fout.is_open() == false) {
//        MessageBox::Show("�� ������� ������� �����.\n��� ������: 500", "������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
//        return System::Void();
//    }
//    string HeaderTemplate = "�������� ��� �";
//    HeaderTemplate += to_string(CurrentPtr->getData().get_ID());
//    fout << std::left << setw(20) << "" << setw(20) << HeaderTemplate
//        << setw(35) << CurrentPtr->getData().get_Date() << "\n\n\n";
//    fout << std::left << setw(20) << "��� ������" << setw(30) << "��������" << setw(15) << "����" << "\n";
//    fout << std::left << setw(20) << to_string(CurrentPtr->getData().get_ID())
//        << setw(30) << CurrentPtr->getData().get_GuitarPtr()->getData().get_Title()
//        << setw(15) << CurrentPtr->getData().get_GuitarPtr()->getData().get_Price() << "\n";
//    fout << std::right << setw(55) << "�����: " << CurrentPtr->getData().get_GuitarPtr()->getData().get_Price() << "\n\n\n\n";
//    fout << "������:\n";
//    fout << std::left << setw(20) << "���������:" << setw(50) << CurrentPtr->getData().get_EmployeePtr()->getData().get_FullName() << "\n"
//        << setw(20) << "����������:" << setw(50) << CurrentPtr->getData().get_BuyerPtr()->getData().get_FullName();
//
//    return System::Void();
//}

System::Void Muztorg::Sales::ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e)
{
    BuyerBox->Enabled = false;
    EmployeeBox->Enabled = false;
    DateBox->ReadOnly = true;
    SumBox->ReadOnly = true;
    SaleGridView->ReadOnly = true;
    ToggleChange->Visible = true;
    ToggleChangesOff->Visible = false;
    return System::Void();
}

System::Void Muztorg::Sales::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    return System::Void();
}
