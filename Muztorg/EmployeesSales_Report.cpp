#include "EmployeesSales_Report.h"

System::Void Muztorg::EmployeesSales_Report::EmployeesSales_Report_Load(System::Object^ sender, System::EventArgs^ e)
{
    double sumOfSale = 0.0;

    DataGridViewColumn^ Date = gcnew DataGridViewColumn();
    Date->HeaderText = "Дата";
    Date->ReadOnly = true;
    Date->Width = 122;
    Date->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Title = gcnew DataGridViewColumn();
    Title->HeaderText = "Наименование товара";
    Title->ReadOnly = true;
    Title->Width = 225;
    Title->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Amount = gcnew DataGridViewColumn();
    Amount->HeaderText = "Кол-во";
    Amount->ReadOnly = true;
    Amount->Width = 80;
    Amount->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ BuyerName = gcnew DataGridViewColumn();
    BuyerName->HeaderText = "ФИО покупатель";
    BuyerName->ReadOnly = true;
    BuyerName->Width = 295;
    BuyerName->CellTemplate = gcnew DataGridViewTextBoxCell();

    ReportDgv->Columns->Add(Date);
    ReportDgv->Columns->Add(Title);
    ReportDgv->Columns->Add(Amount);
    ReportDgv->Columns->Add(BuyerName);
    ReportDgv->Rows->Clear();

    List<Unit<Sale>*>* SaleList = this->SaleBase->_search_Employee(this->SearchedEmployee->getData().get_FullName());
    this->NameBox->Text = Convert_string_to_String(this->SearchedEmployee->getData().get_FullName());

    int indexCount = 0;
    int tmpSum = 0;
    String^ sumOfReport;
     
    if (SaleList->getHead() != NULL) {

        Unit<Unit<Sale>*>* salePtr = SaleList->getHead();
        String^ title;
        String^ amount;
        String^ date;
        String^ buyer;

        while (salePtr != NULL) {

            List<Unit<StructOfSale>*>* tmpStrSaleList = this->StructOfSaleBase->_search_Sale(salePtr->getData()->getData().get_ID());
            Unit<Unit<StructOfSale>*>* strSalePtr = tmpStrSaleList->getHead();

            while (strSalePtr != NULL) {

                Unit<Guitar>* tmpGuitar = this->GuitarBase->_search_ID(strSalePtr->getData()->getData().get_GuitarID());
                Unit<Buyer>* tmpBuyer = this->BuyerBase->_search_ID(salePtr->getData()->getData().get_BuyerID());
                title = Convert_string_to_String(tmpGuitar->getData().get_Title());
                amount = Convert_string_to_String(strSalePtr->getData()->getData().get_Amount());
                date = Convert_string_to_String(salePtr->getData()->getData().get_Date());
                buyer = Convert_string_to_String(tmpBuyer->getData().get_FullName());
                ReportDgv->Rows->Add(date, title, amount, buyer);
                strSalePtr = strSalePtr->getNext();
                tmpSum += Convert::ToInt32(amount);
                indexCount++;

            }
            salePtr = salePtr->getNext();
        }

        sumOfReport = Convert_string_to_String(to_string(tmpSum));
        System::Windows::Forms::DataGridViewCellStyle^ boldStyle = (gcnew System::Windows::Forms::DataGridViewCellStyle());
        boldStyle->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
        ReportDgv->Rows->Add("", "Итого продано:", sumOfReport, "",
            sumOfReport = String::Format("{0} $", sumOfReport));
        ReportDgv->Rows[indexCount]->Cells[1]->Style = boldStyle;
        ReportDgv->Rows[indexCount]->Cells[2]->Style = boldStyle;
    }

    else {
        MessageBox::Show("Данный клиент не совершал покупок в магазине.", "Отчет", MessageBoxButtons::OK, MessageBoxIcon::Information);
        this->Close();
        return System::Void();
    }
}

System::Void Muztorg::EmployeesSales_Report::EmployeesSales_Report_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Form^ form = Application::OpenForms[1];
    form->Show();
    return System::Void();
}
