#include "Guitars.h"

System::Void Muztorg::Guitars::Guitars_Load(System::Object^ sender, System::EventArgs^ e)
{
    int tmpSum = 0;
    string count;

    TitleBox->ReadOnly = true;
    PriceBox->ReadOnly = true;
    DescriptionBox->ReadOnly = true;
    ColorBox->ReadOnly = true;
    FormBox->ReadOnly = true;
    MaterialBox->ReadOnly = true;
    FretsBox->ReadOnly = true;
    BeakerBox->ReadOnly = true;
    CountBox->ReadOnly = true;

    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;
    this->DataChanged = false;

    this->CurrentPtr = this->GuitarBase->getHead();

    TitleBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Title());
    String^ tmp = Convert_string_to_String(this->CurrentPtr->getData().get_Price());
    PriceBox->Text = tmp = String::Format("{0} $", tmp);
    DescriptionBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Description());
    ColorBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Color());
    FormBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_FormOfDeck());
    MaterialBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_MaterialOfDeck());
    FretsBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_AmountOfFret());
    BeakerBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Beaker());

    List<Unit<StructOfSale>*>* StrSaleList = this->StructOfSaleBase->_search_Guitar(this->CurrentPtr->getData().get_ID());
    List<Unit<StructOfSupply>*>* StrSupplyList = this->StructOfSupplyBase->_search_Guitar(this->CurrentPtr->getData().get_ID());

    if (StrSupplyList->getHead() != NULL) {

        Unit<Unit<StructOfSupply>*>* strSupplyPtr = StrSupplyList->getHead();
        String^ amount;

        while (strSupplyPtr != NULL) {

            amount = Convert_string_to_String(strSupplyPtr->getData()->getData().get_Amount());
            tmpSum += Convert::ToInt32(amount);
            strSupplyPtr = strSupplyPtr->getNext();
        }
    }

    if (StrSaleList->getHead() != NULL) {

        Unit<Unit<StructOfSale>*>* strSalePtr = StrSaleList->getHead();
        String^ amount;

        while (strSalePtr != NULL) {

            amount = Convert_string_to_String(strSalePtr->getData()->getData().get_Amount());
            tmpSum += Convert::ToInt32(amount) * (-1);
            strSalePtr = strSalePtr->getNext();
        }
    }

    count = to_string(tmpSum) + " штук";
    CountBox->Text = Convert_string_to_String(count);
    return System::Void();
}

System::Void Muztorg::Guitars::Guitars_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Form^ form = Application::OpenForms[0];
    form->Show();
    return System::Void();
}

System::Void Muztorg::Guitars::Box_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (this->BoxActive == true)
        this->DataChanged = true;
    return System::Void();
}

System::Void Muztorg::Guitars::Box_Enter(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = true;
    return System::Void();
}

System::Void Muztorg::Guitars::Box_Leave(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = false;
    return System::Void();
}

System::Void Muztorg::Guitars::Add_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;
    Guitar value;

    if (this->AddMode == true)
    {
        if (TitleBox->Text == "")
        {
            MessageBox::Show("Заполните поле \"Название гитары\"");
            return System::Void();
        }
        if (PriceBox->Text == "")
        {
            MessageBox::Show("Заполните поле \"Цена гитары\"");
            return System::Void();
        }
        if (DescriptionBox->Text == "")
        {
            MessageBox::Show("Заполните поле \"Описание\"");
            return System::Void();
        }
        if (ColorBox->Text == "")
        {
            MessageBox::Show("Заполните поле \"Цвет гитары\"");
            return System::Void();
        }
        if (FormBox->Text == "")
        {
            MessageBox::Show("Заполните поле \"Форма корпуса\"");
            return System::Void();
        }
        if (MaterialBox->Text == "")
        {
            MessageBox::Show("Заполните поле \"Материал корпуса\"");
            return System::Void();
        }
        if (FretsBox->Text == "")
        {
            MessageBox::Show("Заполните поле \"Кол-во ладов\"");
            return System::Void();
        }
        if (BeakerBox->Text == "")
        {
            MessageBox::Show("Заполните поле \"Мензура\"");
            return System::Void();
        }

        BigString = TitleBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_Title(smallString);

        BigString = PriceBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_Price(smallString);

        BigString = DescriptionBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_Description(smallString);

        BigString = ColorBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_Color(smallString);

        BigString = FormBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_FormOfDeck(smallString);

        BigString = MaterialBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_MaterialOfDeck(smallString);

        BigString = FretsBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_AmountOfFret(smallString);

        BigString = BeakerBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_Beaker(smallString);

        value.set_ID(GuitarBase->getTail()->getData().get_ID() + 1);
        GuitarBase->push_back(value);

        TitleBox->ReadOnly = true;
        PriceBox->ReadOnly = true;
        DescriptionBox->ReadOnly = true;
        ColorBox->ReadOnly = true;
        FormBox->ReadOnly = true;
        MaterialBox->ReadOnly = true;
        FretsBox->ReadOnly = true;
        BeakerBox->ReadOnly = true;
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
            Guitar value;
            String^ BigString;
            string smallString;

            this->DataChanged = false;
            value.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = TitleBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Title(smallString);

            BigString = PriceBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Price(smallString);

            BigString = DescriptionBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Description(smallString);

            BigString = ColorBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Color(smallString);

            BigString = FormBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FormOfDeck(smallString);

            BigString = MaterialBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_MaterialOfDeck(smallString);

            BigString = FretsBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_AmountOfFret(smallString);

            BigString = BeakerBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Beaker(smallString);

            this->CurrentPtr->setData(value);
        }
        else this->DataChanged = false;
    }

    TitleBox->Clear();
    PriceBox->Clear();
    DescriptionBox->Clear();
    ColorBox->Clear();
    FormBox->Clear();
    MaterialBox->Clear();
    FretsBox->Clear();
    BeakerBox->Clear();
    CountBox->Clear();

    TitleBox->ReadOnly = false;
    PriceBox->ReadOnly = false;
    DescriptionBox->ReadOnly = false;
    ColorBox->ReadOnly = false;
    FormBox->ReadOnly = false;
    MaterialBox->ReadOnly = false;
    FretsBox->ReadOnly = false;
    BeakerBox->ReadOnly = false;
    ToggleChanges->Visible = false;
    ToggleChangesOff->Visible = true;
    this->AddMode = true;

    return System::Void();
}

System::Void Muztorg::Guitars::Next_Click(System::Object^ sender, System::EventArgs^ e)
{
    int tmpSum = 0;
    string count;

    this->AddMode = false;
    TitleBox->ReadOnly = true;
    PriceBox->ReadOnly = true;
    DescriptionBox->ReadOnly = true;
    ColorBox->ReadOnly = true;
    FormBox->ReadOnly = true;
    MaterialBox->ReadOnly = true;
    FretsBox->ReadOnly = true;
    BeakerBox->ReadOnly = true;
    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;

    if (this->DataChanged == true)
    {
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Guitar value;
            String^ BigString;
            string smallString;

            this->DataChanged = false;
            value.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = TitleBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Title(smallString);

            BigString = PriceBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Price(smallString);

            BigString = DescriptionBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Description(smallString);

            BigString = ColorBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Color(smallString);

            BigString = FormBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FormOfDeck(smallString);

            BigString = MaterialBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_MaterialOfDeck(smallString);

            BigString = FretsBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_AmountOfFret(smallString);

            BigString = BeakerBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Beaker(smallString);

            this->CurrentPtr->setData(value);
        }
        else this->DataChanged = false;
    }

    if (this->CurrentPtr->getNext() == NULL)
        this->CurrentPtr = GuitarBase->getHead();
    else this->CurrentPtr = this->CurrentPtr->getNext();

    TitleBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Title());
    String^ tmp = Convert_string_to_String(this->CurrentPtr->getData().get_Price());
    PriceBox->Text = tmp = String::Format("{0} $", tmp);
    DescriptionBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Description());
    ColorBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Color());
    FormBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_FormOfDeck());
    MaterialBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_MaterialOfDeck());
    FretsBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_AmountOfFret());
    BeakerBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Beaker());

    List<Unit<StructOfSale>*>* StrSaleList = this->StructOfSaleBase->_search_Guitar(this->CurrentPtr->getData().get_ID());
    List<Unit<StructOfSupply>*>* StrSupplyList = this->StructOfSupplyBase->_search_Guitar(this->CurrentPtr->getData().get_ID());

    if (StrSupplyList->getHead() != NULL) {

        Unit<Unit<StructOfSupply>*>* strSupplyPtr = StrSupplyList->getHead();
        String^ amount;

        while (strSupplyPtr != NULL) {

            amount = Convert_string_to_String(strSupplyPtr->getData()->getData().get_Amount());
            tmpSum += Convert::ToInt32(amount);
            strSupplyPtr = strSupplyPtr->getNext();
        }
    }

    if (StrSaleList->getHead() != NULL) {

        Unit<Unit<StructOfSale>*>* strSalePtr = StrSaleList->getHead();
        String^ amount;

        while (strSalePtr != NULL) {

            amount = Convert_string_to_String(strSalePtr->getData()->getData().get_Amount());
            tmpSum += Convert::ToInt32(amount) * (-1);
            strSalePtr = strSalePtr->getNext();
        }
    }

    count = to_string(tmpSum) + " штук";
    CountBox->Text = Convert_string_to_String(count);
    return System::Void();
}

System::Void Muztorg::Guitars::Prev_Click(System::Object^ sender, System::EventArgs^ e)
{
    int tmpSum = 0;
    string count;

    this->AddMode = false;
    TitleBox->ReadOnly = true;
    PriceBox->ReadOnly = true;
    DescriptionBox->ReadOnly = true;
    ColorBox->ReadOnly = true;
    FormBox->ReadOnly = true;
    MaterialBox->ReadOnly = true;
    FretsBox->ReadOnly = true;
    BeakerBox->ReadOnly = true;
    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;

    if (this->DataChanged == true)
    {
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Guitar value;
            String^ BigString;
            string smallString;

            this->DataChanged = false;
            value.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = TitleBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Title(smallString);

            BigString = PriceBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Price(smallString);

            BigString = DescriptionBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Description(smallString);

            BigString = ColorBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Color(smallString);

            BigString = FormBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FormOfDeck(smallString);

            BigString = MaterialBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_MaterialOfDeck(smallString);

            BigString = FretsBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_AmountOfFret(smallString);

            BigString = BeakerBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Beaker(smallString);

            this->CurrentPtr->setData(value);
        }
        else this->DataChanged = false;
    }

    if (this->CurrentPtr->getPrev() == NULL)
        this->CurrentPtr = GuitarBase->getTail();
    else this->CurrentPtr = this->CurrentPtr->getPrev();

    TitleBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Title());
    String^ tmp = Convert_string_to_String(this->CurrentPtr->getData().get_Price());
    PriceBox->Text = tmp = String::Format("{0} $", tmp);
    DescriptionBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Description());
    ColorBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Color());
    FormBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_FormOfDeck());
    MaterialBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_MaterialOfDeck());
    FretsBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_AmountOfFret());
    BeakerBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Beaker());

    List<Unit<StructOfSale>*>* StrSaleList = this->StructOfSaleBase->_search_Guitar(this->CurrentPtr->getData().get_ID());
    List<Unit<StructOfSupply>*>* StrSupplyList = this->StructOfSupplyBase->_search_Guitar(this->CurrentPtr->getData().get_ID());

    if (StrSupplyList->getHead() != NULL) {

        Unit<Unit<StructOfSupply>*>* strSupplyPtr = StrSupplyList->getHead();
        String^ amount;

        while (strSupplyPtr != NULL) {

            amount = Convert_string_to_String(strSupplyPtr->getData()->getData().get_Amount());
            tmpSum += Convert::ToInt32(amount);
            strSupplyPtr = strSupplyPtr->getNext();
        }
    }

    if (StrSaleList->getHead() != NULL) {

        Unit<Unit<StructOfSale>*>* strSalePtr = StrSaleList->getHead();
        String^ amount;

        while (strSalePtr != NULL) {

            amount = Convert_string_to_String(strSalePtr->getData()->getData().get_Amount());
            tmpSum += Convert::ToInt32(amount) * (-1);
            strSalePtr = strSalePtr->getNext();
        }
    }

    count = to_string(tmpSum) + " штук";
    CountBox->Text = Convert_string_to_String(count);
    return System::Void();
}

System::Void Muztorg::Guitars::ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e)
{
    TitleBox->ReadOnly = true;
    PriceBox->ReadOnly = true;
    DescriptionBox->ReadOnly = true;
    ColorBox->ReadOnly = true;
    FormBox->ReadOnly = true;
    MaterialBox->ReadOnly = true;
    FretsBox->ReadOnly = true;
    BeakerBox->ReadOnly = true;

    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;
    return System::Void();
}

System::Void Muztorg::Guitars::ToggleChanges_Click(System::Object^ sender, System::EventArgs^ e)
{
    TitleBox->ReadOnly = false;
    PriceBox->ReadOnly = false;
    DescriptionBox->ReadOnly = false;
    ColorBox->ReadOnly = false;
    FormBox->ReadOnly = false;
    MaterialBox->ReadOnly = false;
    FretsBox->ReadOnly = false;
    BeakerBox->ReadOnly = false;

    ToggleChanges->Visible = false;
    ToggleChangesOff->Visible = true;
    return System::Void();
}

System::Void Muztorg::Guitars::Save_Click(System::Object^ sender, System::EventArgs^ e)
{

    if (this->DataChanged == true)
    {
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            Guitar value;
            String^ BigString;
            string smallString;

            this->DataChanged = false;
            value.set_ID(this->CurrentPtr->getData().get_ID());

            BigString = TitleBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Title(smallString);

            BigString = PriceBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Price(smallString);

            BigString = DescriptionBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Description(smallString);

            BigString = ColorBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Color(smallString);

            BigString = FormBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FormOfDeck(smallString);

            BigString = MaterialBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_MaterialOfDeck(smallString);

            BigString = FretsBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_AmountOfFret(smallString);

            BigString = BeakerBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Beaker(smallString);

            this->CurrentPtr->setData(value);
        }
        else this->DataChanged = false;
    }

    return System::Void();
}

/*System::Void Muztorg::Guitars::Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    int eraseFlag;
    int tmpSum = 0;
    string count;
    Unit<Guitar>* erasePtr;


    if (this->AddMode == true)
    {
        this->AddMode = false;
        TitleBox->ReadOnly = true;
        PriceBox->ReadOnly = true;
        DescriptionBox->ReadOnly = true;
        ColorBox->ReadOnly = true;
        FormBox->ReadOnly = true;
        MaterialBox->ReadOnly = true;
        FretsBox->ReadOnly = true;
        BeakerBox->ReadOnly = true;

        TitleBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Title());
        String^ tmp = Convert_string_to_String(this->CurrentPtr->getData().get_Price());
        PriceBox->Text = tmp = String::Format("{0} $", tmp);
        DescriptionBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Description());
        ColorBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Color());
        FormBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_FormOfDeck());
        MaterialBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_MaterialOfDeck());
        FretsBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_AmountOfFret());
        BeakerBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Beaker());

        List<Unit<StructOfSale>*>* StrSaleList = this->StructOfSaleBase->_search_Guitar(this->CurrentPtr->getData().get_ID());
        List<Unit<StructOfSupply>*>* StrSupplyList = this->StructOfSupplyBase->_search_Guitar(this->CurrentPtr->getData().get_ID());

        if (StrSupplyList->getHead() != NULL) {

            Unit<Unit<StructOfSupply>*>* strSupplyPtr = StrSupplyList->getHead();
            String^ amount;

            while (strSupplyPtr != NULL) {

                amount = Convert_string_to_String(strSupplyPtr->getData()->getData().get_Amount());
                tmpSum += Convert::ToInt32(amount);
                strSupplyPtr = strSupplyPtr->getNext();
            }
        }

        if (StrSaleList->getHead() != NULL) {

            Unit<Unit<StructOfSale>*>* strSalePtr = StrSaleList->getHead();
            String^ amount;

            while (strSalePtr != NULL) {

                amount = Convert_string_to_String(strSalePtr->getData()->getData().get_Amount());
                tmpSum += Convert::ToInt32(amount) * (-1);
                strSalePtr = strSalePtr->getNext();
            }
        }

        count = to_string(tmpSum) + " штук";
        CountBox->Text = Convert_string_to_String(count);
        return System::Void();
    }

    if (MessageBox::Show("Вы уверенны что хотите удалить эту запить? Отменить это действие будет невозможно.", "Подтверждение удаления", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
        ::System::Windows::Forms::DialogResult::No)
        return System::Void();

    erasePtr = this->CurrentPtr;

    if (this->CurrentPtr->getNext() == NULL)
        this->CurrentPtr = GuitarBase->getHead();
    else this->CurrentPtr = this->CurrentPtr->getNext();

    eraseFlag = GuitarBase->erase(erasePtr);

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

    TitleBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Title());
    String^ tmp = Convert_string_to_String(this->CurrentPtr->getData().get_Price());
    PriceBox->Text = tmp = String::Format("{0} $", tmp);
    DescriptionBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Description());
    ColorBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Color());
    FormBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_FormOfDeck());
    MaterialBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_MaterialOfDeck());
    FretsBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_AmountOfFret());
    BeakerBox->Text = Convert_string_to_String(this->CurrentPtr->getData().get_Beaker());

    List<Unit<StructOfSale>*>* StrSaleList = this->StructOfSaleBase->_search_Guitar(this->CurrentPtr->getData().get_ID());
    List<Unit<StructOfSupply>*>* StrSupplyList = this->StructOfSupplyBase->_search_Guitar(this->CurrentPtr->getData().get_ID());

    if (StrSupplyList->getHead() != NULL) {

        Unit<Unit<StructOfSupply>*>* strSupplyPtr = StrSupplyList->getHead();
        String^ amount;

        while (strSupplyPtr != NULL) {

            amount = Convert_string_to_String(strSupplyPtr->getData()->getData().get_Amount());
            tmpSum += Convert::ToInt32(amount);
            strSupplyPtr = strSupplyPtr->getNext();
        }
    }

    if (StrSaleList->getHead() != NULL) {

        Unit<Unit<StructOfSale>*>* strSalePtr = StrSaleList->getHead();
        String^ amount;

        while (strSalePtr != NULL) {

            amount = Convert_string_to_String(strSalePtr->getData()->getData().get_Amount());
            tmpSum += Convert::ToInt32(amount) * (-1);
            strSalePtr = strSalePtr->getNext();
        }
    }

    count = to_string(tmpSum) + " штук";
    CountBox->Text = Convert_string_to_String(count);
    return System::Void();
}*/

System::Void Muztorg::Guitars::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    return System::Void();
}

System::Void Muztorg::Guitars::SalesReportButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    Muztorg::GuitarsSales_Report^ form = gcnew GuitarsSales_Report(CurrentPtr);
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

System::Void Muztorg::Guitars::SuppliesReportButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    Muztorg::GuitarsSupplies_Report^ form = gcnew GuitarsSupplies_Report(CurrentPtr);
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