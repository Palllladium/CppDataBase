#include "BuyersSales_Report.h"

System::Void Muztorg::BuyersSales_Report::BuyersSales_Report_Load(System::Object^ sender, System::EventArgs^ e)
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
    Title->Width = 240;
    Title->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Price = gcnew DataGridViewColumn();
    Price->HeaderText = "Цена товара";
    Price->ReadOnly = true;
    Price->Width = 120;
    Price->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Amount = gcnew DataGridViewColumn();
    Amount->HeaderText = "Кол-во";
    Amount->ReadOnly = true;
    Amount->Width = 110;
    Amount->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Summary = gcnew DataGridViewColumn();
    Summary->HeaderText = "Сумма";
    Summary->ReadOnly = true;
    Summary->Width = 130;
    Summary->CellTemplate = gcnew DataGridViewTextBoxCell();

    ReportDgv->Columns->Add(Date);
    ReportDgv->Columns->Add(Title);
    ReportDgv->Columns->Add(Price);
    ReportDgv->Columns->Add(Amount);
    ReportDgv->Columns->Add(Summary);
    ReportDgv->Rows->Clear();

    List<Unit<Sale>*>* SaleList = this->SaleBase->_search_Buyer(this->SearchedBuyer->getData().get_FullName());
    this->NameBox->Text = " " + Convert_string_to_String(this->SearchedBuyer->getData().get_FullName());

    int indexCount = 0;
    int tmpSum = 0;
    String^ sumOfReport;

    if (SaleList->getHead() != NULL) {

        Unit<Unit<Sale>*>* salePtr = SaleList->getHead();
        String^ date;
        String^ title;
        String^ price;
        String^ amount;
        String^ summary;

        while (salePtr != NULL) {

            List<Unit<StructOfSale>*>* tmpStrSaleList = this->StructOfSaleBase->_search_Sale(salePtr->getData()->getData().get_ID());
            Unit<Unit<StructOfSale>*>* strSalePtr = tmpStrSaleList->getHead();

            while (strSalePtr != NULL) {

                date = Convert_string_to_String(salePtr->getData()->getData().get_Date());
                Unit<Guitar>* tmpGuitar = this->GuitarBase->_search_ID(strSalePtr->getData()->getData().get_GuitarID());
                title = Convert_string_to_String(tmpGuitar->getData().get_Title());
                price = Convert_string_to_String(tmpGuitar->getData().get_Price());
                amount = Convert_string_to_String(strSalePtr->getData()->getData().get_Amount());
                summary = (Convert::ToInt32(price) * Convert::ToInt32(amount)).ToString();
                tmpSum += Convert::ToInt32(summary);
                ReportDgv->Rows->Add(date, title,
                    price = String::Format("{0} $", price), amount,
                    summary = String::Format("{0} $", summary));
                strSalePtr = strSalePtr->getNext();
                indexCount++;

            }
            salePtr = salePtr->getNext();
        }
        
        sumOfReport = Convert_string_to_String(to_string(tmpSum));
        System::Windows::Forms::DataGridViewCellStyle^ boldStyle = (gcnew System::Windows::Forms::DataGridViewCellStyle());
        boldStyle->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
        ReportDgv->Rows->Add("", "", "", "Потрачено:",
            sumOfReport = String::Format("{0} $", sumOfReport));
        ReportDgv->Rows[indexCount]->Cells[3]->Style = boldStyle;
        ReportDgv->Rows[indexCount]->Cells[4]->Style = boldStyle;

    }

    else {
        MessageBox::Show("Данный клиент не совершал покупок в магазине.", "Отчет", MessageBoxButtons::OK, MessageBoxIcon::Information);
        this->Close();
        return System::Void();
    }
}

System::Void Muztorg::BuyersSales_Report::BuyersSales_Report_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Form^ form = Application::OpenForms[1];
    form->Show();
    return System::Void();
}
