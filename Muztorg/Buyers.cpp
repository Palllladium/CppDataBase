#include "Buyers.h"

System::Void Muztorg::Buyers::Buyers_Load(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;

    NameBox->ReadOnly = true;
    PhoneBox->ReadOnly = true;

    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;

    this->CurrentPtr = this->BuyerBase->getHead();

    smallString = this->CurrentPtr->getData().get_FullName();
    BigString = Convert_string_to_String(smallString);
    NameBox->Text = BigString;

    smallString = this->CurrentPtr->getData().getPhoneNumber();
    BigString = Convert_string_to_String(smallString);
    PhoneBox->Text = BigString;

    return System::Void();
}

System::Void Muztorg::Buyers::Buyers_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Form^ form = Application::OpenForms[0];
    form->Show();
    return System::Void();
}

System::Void Muztorg::Buyers::NameBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (this->BoxActive == true)
        this->DataChanged = true;
    return System::Void();
}

System::Void Muztorg::Buyers::NameBox_Enter(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = true;
    return System::Void();
}

System::Void Muztorg::Buyers::NameBox_Leave(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = false;
    return System::Void();
}

System::Void Muztorg::Buyers::Next_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;

    this->AddMode = false;
    NameBox->ReadOnly = true;
    PhoneBox->ReadOnly = true;

    //-----------------------------------------------------------------
    if (this->DataChanged == true)
    {
        Buyer value;
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
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
    }
    //-----------------------------------------------------------------

    if (this->CurrentPtr->getNext() == NULL)
        this->CurrentPtr = BuyerBase->getHead();
    else this->CurrentPtr = this->CurrentPtr->getNext();

    //Вывод данных CurrentPtr
    //-----------------------------------------------------------------
    smallString = this->CurrentPtr->getData().get_FullName();
    BigString = Convert_string_to_String(smallString);
    NameBox->Text = BigString;

    smallString = this->CurrentPtr->getData().getPhoneNumber();
    BigString = Convert_string_to_String(smallString);
    PhoneBox->Text = BigString;
    //-----------------------------------------------------------------
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
        this->AddMode = false;
        this->DataChanged = false;
        return System::Void();
    }
    //-----------------------------------------------------------------
    if (this->DataChanged == true)
    {
        Buyer value;
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
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
    }
    //-----------------------------------------------------------------

    NameBox->Clear();
    PhoneBox->Clear();

    NameBox->ReadOnly = false;
    PhoneBox->ReadOnly = false;
    this->AddMode = true;

    return System::Void();
}

System::Void Muztorg::Buyers::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;

    this->AddMode = false;
    NameBox->ReadOnly = true;
    PhoneBox->ReadOnly = true;

    //-----------------------------------------------------------------
    if (this->DataChanged == true)
    {
        Buyer value;
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
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
    }
    //-----------------------------------------------------------------

    if (this->CurrentPtr->getPrev() == NULL)
        this->CurrentPtr = BuyerBase->getTail();
    else this->CurrentPtr = this->CurrentPtr->getPrev();

    //Вывод данных CurrentPtr
    //-----------------------------------------------------------------
    smallString = this->CurrentPtr->getData().get_FullName();
    BigString = Convert_string_to_String(smallString);
    NameBox->Text = BigString;

    smallString = this->CurrentPtr->getData().getPhoneNumber();
    BigString = Convert_string_to_String(smallString);
    PhoneBox->Text = BigString;
    //-----------------------------------------------------------------
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

    //Блок сохранения данных
    //-----------------------------------------------------------------
    if (this->DataChanged == true)
    {
        Buyer value;
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
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
    }
    //-----------------------------------------------------------------
    return System::Void();
}

System::Void Muztorg::Buyers::Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    int eraseFlag;
    string errorMessage;
    String^ BigString;
    string smallString;

    Unit<Buyer>* erasePtr;

    if (this->AddMode == true)
    {
        this->AddMode = false;
        NameBox->ReadOnly = true;
        PhoneBox->ReadOnly = true;


        //Вывод данных CurrentPtr
   //-----------------------------------------------------------------
        smallString = this->CurrentPtr->getData().get_FullName();
        BigString = Convert_string_to_String(smallString);
        NameBox->Text = BigString;

        smallString = this->CurrentPtr->getData().getPhoneNumber();
        BigString = Convert_string_to_String(smallString);
        PhoneBox->Text = BigString;
        //-----------------------------------------------------------------
        return System::Void();
    }

    if (MessageBox::Show("Вы уверенны что хотите удалить эту запить? Отменить это действие будет невозможно.", "Подтверждение удаления", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
        ::System::Windows::Forms::DialogResult::No)
        return System::Void();

    erasePtr = this->CurrentPtr;

    if (this->CurrentPtr->getNext() == NULL)
        this->CurrentPtr = BuyerBase->getHead();
    else this->CurrentPtr = this->CurrentPtr->getNext();

    eraseFlag = BuyerBase->erase(erasePtr);

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

    //Вывод данных CurrentPtr
   //-----------------------------------------------------------------
    smallString = this->CurrentPtr->getData().get_FullName();
    BigString = Convert_string_to_String(smallString);
    NameBox->Text = BigString;

    smallString = this->CurrentPtr->getData().getPhoneNumber();
    BigString = Convert_string_to_String(smallString);
    PhoneBox->Text = BigString;
    //-----------------------------------------------------------------
    return System::Void();
}

System::Void Muztorg::Buyers::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    return System::Void();
}
