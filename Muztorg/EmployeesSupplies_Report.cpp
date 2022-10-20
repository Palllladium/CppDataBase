#include "EmployeesSupplies_Report.h"

System::Void Muztorg::EmployeesSupplies_Report::EmployeesSupplies_Report_Load(System::Object^ sender, System::EventArgs^ e)
{
    double sumOfSale = 0.0;

    DataGridViewColumn^ Date = gcnew DataGridViewColumn();
    Date->HeaderText = "Дата";
    Date->ReadOnly = true;
    Date->Width = 196;
    Date->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Title = gcnew DataGridViewColumn();
    Title->HeaderText = "Наименование товара";
    Title->ReadOnly = true;
    Title->Width = 390;
    Title->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Amount = gcnew DataGridViewColumn();
    Amount->HeaderText = "Кол-во";
    Amount->ReadOnly = true;
    Amount->Width = 136;
    Amount->CellTemplate = gcnew DataGridViewTextBoxCell();

    ReportDgv->Columns->Add(Date);
    ReportDgv->Columns->Add(Title);
    ReportDgv->Columns->Add(Amount);
    ReportDgv->Rows->Clear();

    List<Unit<Supply>*>* SupplyList = this->SupplyBase->_search_Employee(this->SearchedEmployee->getData().get_FullName());
    this->NameBox->Text = Convert_string_to_String(this->SearchedEmployee->getData().get_FullName());

    int indexCount = 0;
    int tmpSum = 0;
    String^ sumOfReport;

    if (SupplyList->getHead() != NULL) {

        Unit<Unit<Supply>*>* supplyPtr = SupplyList->getHead();
        String^ title;
        String^ amount;
        String^ date;

        while (supplyPtr != NULL) {

            List<Unit<StructOfSupply>*>* tmpStrSupplyList = this->StructOfSupplyBase->_search_Supply(supplyPtr->getData()->getData().get_ID());
            Unit<Unit<StructOfSupply>*>* strSupplyPtr = tmpStrSupplyList->getHead();

            while (strSupplyPtr != NULL) {

                Unit<Guitar>* tmpGuitar = this->GuitarBase->_search_ID(strSupplyPtr->getData()->getData().get_GuitarID());
                title = Convert_string_to_String(tmpGuitar->getData().get_Title());
                amount = Convert_string_to_String(strSupplyPtr->getData()->getData().get_Amount());
                date = Convert_string_to_String(supplyPtr->getData()->getData().get_Date());
                ReportDgv->Rows->Add(date, title, amount);
                strSupplyPtr = strSupplyPtr->getNext();
                tmpSum += Convert::ToInt32(amount);
                indexCount++;

            }
            supplyPtr = supplyPtr->getNext();
        }

        sumOfReport = Convert_string_to_String(to_string(tmpSum));
        System::Windows::Forms::DataGridViewCellStyle^ boldStyle = (gcnew System::Windows::Forms::DataGridViewCellStyle());
        boldStyle->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
        ReportDgv->Rows->Add("", "Итого поставлено:", sumOfReport, "",
            sumOfReport = String::Format("{0} $", sumOfReport));
        ReportDgv->Rows[indexCount]->Cells[1]->Style = boldStyle;
        ReportDgv->Rows[indexCount]->Cells[2]->Style = boldStyle;
    }

    else {
        MessageBox::Show("Данный сотрудник не принимал поставок в магазине.", "Отчет", MessageBoxButtons::OK, MessageBoxIcon::Information);
        this->Close();
        return System::Void();
    }
}

System::Void Muztorg::EmployeesSupplies_Report::EmployeesSupplies_Report_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Form^ form = Application::OpenForms[1];
    form->Show();
    return System::Void();
}
