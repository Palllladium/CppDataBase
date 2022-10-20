#include "GuitarsSupplies_Report.h"

System::Void Muztorg::GuitarsSupplies_Report::ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    return System::Void();
}

System::Void Muztorg::GuitarsSupplies_Report::GuitarsSupplies_Report_Load(System::Object^ sender, System::EventArgs^ e)
{
    DataGridViewColumn^ Date = gcnew DataGridViewColumn();
    Date->HeaderText = "Дата";
    Date->ReadOnly = true;
    Date->Width = 120;
    Date->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ NumOfSupply = gcnew DataGridViewColumn();
    NumOfSupply->HeaderText = "Номер поставки";
    NumOfSupply->ReadOnly = true;
    NumOfSupply->Width = 140;
    NumOfSupply->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Amount = gcnew DataGridViewColumn();
    Amount->HeaderText = "Кол-во";
    Amount->ReadOnly = true;
    Amount->Width = 80;
    Amount->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Fullname = gcnew DataGridViewColumn();
    Fullname->HeaderText = "ФИО сотрудника";
    Fullname->ReadOnly = true;
    Fullname->Width = 325;
    Fullname->CellTemplate = gcnew DataGridViewTextBoxCell();

    ReportDgv->Columns->Add(Date);
    ReportDgv->Columns->Add(NumOfSupply);
    ReportDgv->Columns->Add(Amount);
    ReportDgv->Columns->Add(Fullname);
    ReportDgv->Rows->Clear();

    List<Unit<StructOfSupply>*>* StrList = this->StructOfSupplyBase->_search_Guitar(this->SearchedGuitar->getData().get_ID());
    TitleBox->Text = Convert_string_to_String(SearchedGuitar->getData().get_Title());

    if (StrList->getHead() != NULL) {

        Unit<Unit<StructOfSupply>*>* strPtr = StrList->getHead();
        String^ date;
        String^ amount;
        String^ numOfSupply;
        String^ fullname;
        double tmpSum = 0.0;
        int indexCount = 0;

        while (strPtr != NULL) {

            Unit<Supply>* tmpSupplyUnit = this->SupplyBase->_search_ID(strPtr->getData()->getData().get_SupplyPtr()->getData().get_ID());

            date = Convert_string_to_String(tmpSupplyUnit->getData().get_Date());
            amount = Convert_string_to_String(strPtr->getData()->getData().get_Amount());
            numOfSupply = Convert_string_to_String(to_string(tmpSupplyUnit->getData().get_ID()));
            fullname = Convert_string_to_String(tmpSupplyUnit->getData().get_EmployeePtr()->getData().get_FullName());
            tmpSum += Convert::ToDouble(amount);

            ReportDgv->Rows->Add(date, numOfSupply, amount, fullname);
            strPtr = strPtr->getNext();
            indexCount++;
        }

        System::Windows::Forms::DataGridViewCellStyle^ boldStyle = (gcnew System::Windows::Forms::DataGridViewCellStyle());
        boldStyle->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
        ReportDgv->Rows->Add("", "Итого поставлено:", tmpSum, "");
        ReportDgv->Rows[indexCount]->Cells[1]->Style = boldStyle;
        ReportDgv->Rows[indexCount]->Cells[2]->Style = boldStyle;
    }

    else {
        MessageBox::Show("Поставки по этому товару не найдены.", "Отчет", MessageBoxButtons::OK, MessageBoxIcon::Information);
        this->Close();
        return System::Void();
    }
}

System::Void Muztorg::GuitarsSupplies_Report::GuitarsSupplies_Report_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Form^ form = Application::OpenForms[1];
    form->Show();
    return System::Void();
}