#include "Employees.h"

System::Void Muztorg::Employees::ToggleChanges_Click(System::Object^ sender, System::EventArgs^ e)
{
    NameBox->ReadOnly = false;
    GenderBox->ReadOnly = false;
    BDateBox->ReadOnly = false;

    ToggleChanges->Visible = false;
    ToggleChangesOff->Visible = true;
    return System::Void();
}

System::Void Muztorg::Employees::Employees_Load(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;


    NameBox->ReadOnly = true;
    GenderBox->ReadOnly = true;
    BDateBox->ReadOnly = true;
    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;

    this->CurrentPtr = this->EmployeeBase->getHead();

    smallString = this->CurrentPtr->getData().get_FullName();
    BigString = Convert_string_to_String(smallString);
    NameBox->Text = BigString;

    smallString = this->CurrentPtr->getData().get_Gender();
    BigString = Convert_string_to_String(smallString);
    GenderBox->Text = BigString;

    smallString = this->CurrentPtr->getData().get_BDate();
    BigString = Convert_string_to_String(smallString);
    BDateBox->Text = BigString;

    return System::Void();
}

System::Void Muztorg::Employees::Employees_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Form^ form = Application::OpenForms[0];
    form->Show();
    return System::Void();
}

System::Void Muztorg::Employees::NameBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{

    if (this->BoxActive == true)
        this->DataChanged = true;
    return System::Void();
}

System::Void Muztorg::Employees::NameBox_Enter(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = true;
    return System::Void();
}

System::Void Muztorg::Employees::NameBox_Leave(System::Object^ sender, System::EventArgs^ e)
{
    this->BoxActive = false;
    return System::Void();
}

System::Void Muztorg::Employees::Prev_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;

    this->AddMode = false;
    NameBox->ReadOnly = true;
    GenderBox->ReadOnly = true;
    BDateBox->ReadOnly = true;

    //Блок сохранения данных
    //-----------------------------------------------------------------
    if (this->DataChanged == true)
    {
        Employee value;
        this->DataChanged = false;
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            value.set_ID(this->CurrentPtr->getData().get_ID());
            BigString = NameBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FullName(smallString);
            BigString = GenderBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Gender(smallString);
            BigString = BDateBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_BDate(smallString);

            this->CurrentPtr->setData(value);
        }
    }
    //-----------------------------------------------------------------

    if (this->CurrentPtr->getPrev() == NULL)
        this->CurrentPtr = EmployeeBase->getTail();
    else this->CurrentPtr = this->CurrentPtr->getPrev();

    //Вывод данных CurrentPtr
    //-----------------------------------------------------------------
    smallString = this->CurrentPtr->getData().get_FullName();
    BigString = Convert_string_to_String(smallString);
    NameBox->Text = BigString;

    smallString = this->CurrentPtr->getData().get_Gender();
    BigString = Convert_string_to_String(smallString);
    GenderBox->Text = BigString;

    smallString = this->CurrentPtr->getData().get_BDate();
    BigString = Convert_string_to_String(smallString);
    BDateBox->Text = BigString;
    //-----------------------------------------------------------------
    return System::Void();
}

System::Void Muztorg::Employees::ToggleChangesOff_Click(System::Object^ sender, System::EventArgs^ e)
{
    NameBox->ReadOnly = true;
    GenderBox->ReadOnly = true;
    BDateBox->ReadOnly = true;

    ToggleChanges->Visible = true;
    ToggleChangesOff->Visible = false;
    return System::Void();
}

System::Void Muztorg::Employees::Next_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;

    this->AddMode = false;
    NameBox->ReadOnly = true;
    GenderBox->ReadOnly = true;
    BDateBox->ReadOnly = true;

    //Блок сохранения данных
    //-----------------------------------------------------------------
    if (this->DataChanged == true)
    {
        Employee value;
        this->DataChanged = false;
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            value.set_ID(this->CurrentPtr->getData().get_ID());
            BigString = NameBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FullName(smallString);
            BigString = GenderBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Gender(smallString);
            BigString = BDateBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_BDate(smallString);

            this->CurrentPtr->setData(value);
        }
    }
    //-----------------------------------------------------------------

    if (this->CurrentPtr->getNext() == NULL)
        this->CurrentPtr = EmployeeBase->getHead();
    else this->CurrentPtr = this->CurrentPtr->getNext();

    //Вывод данных CurrentPtr
    //-----------------------------------------------------------------
    smallString = this->CurrentPtr->getData().get_FullName();
    BigString = Convert_string_to_String(smallString);
    NameBox->Text = BigString;

    smallString = this->CurrentPtr->getData().get_Gender();
    BigString = Convert_string_to_String(smallString);
    GenderBox->Text = BigString;

    smallString = this->CurrentPtr->getData().get_BDate();
    BigString = Convert_string_to_String(smallString);
    BDateBox->Text = BigString;
    //-----------------------------------------------------------------
    return System::Void();
}

System::Void Muztorg::Employees::Save_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ BigString;
    string smallString;

    //Блок сохранения данных
    //-----------------------------------------------------------------
    if (this->DataChanged == true)
    {
        Employee value;
        this->DataChanged = false;
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            value.set_ID(this->CurrentPtr->getData().get_ID());
            BigString = NameBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FullName(smallString);
            BigString = GenderBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Gender(smallString);
            BigString = BDateBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_BDate(smallString);

            this->CurrentPtr->setData(value);
        }
    }
    //-----------------------------------------------------------------
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
        if (BDateBox->Text == "")
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
        BigString = BDateBox->Text;
        Convert_String_to_string(BigString, smallString);
        value.set_BDate(smallString);

        value.set_ID(EmployeeBase->getTail()->getData().get_ID() + 1);
        EmployeeBase->push_back(value);

        NameBox->ReadOnly = true;
        GenderBox->ReadOnly = true;
        BDateBox->ReadOnly = true;
        this->AddMode = false;
        this->DataChanged = false;
        return System::Void();
    }
    //Блок сохранения данных
    //-----------------------------------------------------------------
    if (this->DataChanged == true)
    {
        Employee value;
        this->DataChanged = false;
        if (MessageBox::Show("Сохранить внесенные изменения?", "Несохраненные изменения", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
            ::System::Windows::Forms::DialogResult::Yes)
        {
            value.set_ID(this->CurrentPtr->getData().get_ID());
            BigString = NameBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_FullName(smallString);
            BigString = GenderBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_Gender(smallString);
            BigString = BDateBox->Text;
            Convert_String_to_string(BigString, smallString);
            value.set_BDate(smallString);

            this->CurrentPtr->setData(value);
        }
    }
    //-----------------------------------------------------------------

    NameBox->Clear();
    GenderBox->Clear();
    BDateBox->Clear();
    NameBox->ReadOnly = false;
    GenderBox->ReadOnly = false;
    BDateBox->ReadOnly = false;
    this->AddMode = true;

    return System::Void();
}

System::Void Muztorg::Employees::Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    int eraseFlag;
    string errorMessage;
    String^ BigString;
    string smallString;

    Unit<Employee>* erasePtr;

    if (this->AddMode == true)
    {
        this->AddMode = false;
        NameBox->ReadOnly = true;
        GenderBox->ReadOnly = true;
        BDateBox->ReadOnly = true;

        //Вывод данных CurrentPtr
   //-----------------------------------------------------------------
        smallString = this->CurrentPtr->getData().get_FullName();
        BigString = Convert_string_to_String(smallString);
        NameBox->Text = BigString;

        smallString = this->CurrentPtr->getData().get_Gender();
        BigString = Convert_string_to_String(smallString);
        GenderBox->Text = BigString;

        smallString = this->CurrentPtr->getData().get_BDate();
        BigString = Convert_string_to_String(smallString);
        BDateBox->Text = BigString;
        //-----------------------------------------------------------------
        return System::Void();
    }

    if (MessageBox::Show("Вы уверенны что хотите удалить эту запить? Отменить это действие будет невозможно.", "Подтверждение удаления", MessageBoxButtons::YesNo, MessageBoxIcon::Information) ==
        ::System::Windows::Forms::DialogResult::No)
        return System::Void();

    erasePtr = this->CurrentPtr;

    if (this->CurrentPtr->getNext() == NULL)
        this->CurrentPtr = EmployeeBase->getHead();
    else this->CurrentPtr = this->CurrentPtr->getNext();

    eraseFlag = EmployeeBase->erase(erasePtr);

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

    smallString = this->CurrentPtr->getData().get_Gender();
    BigString = Convert_string_to_String(smallString);
    GenderBox->Text = BigString;

    smallString = this->CurrentPtr->getData().get_BDate();
    BigString = Convert_string_to_String(smallString);
    BDateBox->Text = BigString;
    //-----------------------------------------------------------------
    return System::Void();
}

System::Void Muztorg::Employees::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    return System::Void();
}
