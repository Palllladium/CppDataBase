#include "Check_Report.h"

System::Void Muztorg::Check_Report::ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    return System::Void();
}

System::Void Muztorg::Check_Report::Check_Report_Load(System::Object^ sender, System::EventArgs^ e)
{
    double sumOfSale = 0.0;

    DataGridViewColumn^ GuitarCode = gcnew DataGridViewColumn();
    GuitarCode->HeaderText = "Код гитары";
    GuitarCode->ReadOnly = true;
    GuitarCode->Width = 80;
    GuitarCode->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Title = gcnew DataGridViewColumn();
    Title->HeaderText = "Наименование товара";
    Title->ReadOnly = true;
    Title->Width = 250;
    Title->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Amount = gcnew DataGridViewColumn();
    Amount->HeaderText = "Кол-во";
    Amount->ReadOnly = true;
    Amount->Width = 80;
    Amount->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Price = gcnew DataGridViewColumn();
    Price->HeaderText = "Цена товара";
    Price->ReadOnly = true;
    Price->Width = 150;
    Price->CellTemplate = gcnew DataGridViewTextBoxCell();

    DataGridViewColumn^ Summary = gcnew DataGridViewColumn();
    Summary->HeaderText = "Сумма";
    Summary->ReadOnly = true;
    Summary->Width = 162;
    Summary->CellTemplate = gcnew DataGridViewTextBoxCell();

    ReportDgv->Columns->Add(GuitarCode);
    ReportDgv->Columns->Add(Title);
    ReportDgv->Columns->Add(Amount);
    ReportDgv->Columns->Add(Price);
    ReportDgv->Columns->Add(Summary);
    ReportDgv->Rows->Clear();

    List<Unit<StructOfSale>*>* StrList = this->StructOfSaleBase->_search_Sale(this->SearchedSale->getData().get_ID());
    Unit<Employee>* tmpEmpUnit = this->EmployeeBase->_search_ID(this->SearchedSale->getData().get_EmployeeID());
    Unit<Buyer>* tmpBuyerUnit = this->BuyerBase->_search_ID(this->SearchedSale->getData().get_BuyerID());
    CheckIDBox->Text = Convert_string_to_String(to_string(this->SearchedSale->getData().get_ID()));
    DateBox->Text = Convert_string_to_String(this->SearchedSale->getData().get_Date());
    EmployeeBox->Text = Convert_string_to_String(tmpEmpUnit->getData().get_FullName());
    BuyerBox->Text = Convert_string_to_String(tmpBuyerUnit->getData().get_FullName());

    if (StrList->getHead() != NULL) {

        Unit<Unit<StructOfSale>*>* strPtr = StrList->getHead();
        String^ guitarCode;
        String^ title;
        String^ amount;
        String^ price;
        String^ summary;
        int indexCount = 0;

        while (strPtr != NULL) {

            Unit<Guitar>* tmpGuitarUnit = this->GuitarBase->_search_ID(strPtr->getData()->getData().get_GuitarID());

            guitarCode = Convert_string_to_String(strPtr->getData()->getData().get_GuitarID());
            title = Convert_string_to_String(tmpGuitarUnit->getData().get_Title());
            amount = Convert_string_to_String(strPtr->getData()->getData().get_Amount());
            price = Convert_string_to_String(tmpGuitarUnit->getData().get_Price());
            summary = (Convert::ToDouble(price) * Convert::ToDouble(amount)).ToString();
            sumOfSale += Convert::ToDouble(summary);

            ReportDgv->Rows->Add(guitarCode, title, amount, 
                price = String::Format("{0} $", price),
                summary = String::Format("{0} $", summary));
            strPtr = strPtr->getNext();
            indexCount++;
        }

        summary = sumOfSale.ToString();

        System::Windows::Forms::DataGridViewCellStyle^ boldStyle = (gcnew System::Windows::Forms::DataGridViewCellStyle());
        boldStyle->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
        ReportDgv->Rows->Add("", "", "", "Итого:", summary = String::Format("{0} $", summary));
        ReportDgv->Rows[indexCount]->Cells[3]->Style = boldStyle;
        ReportDgv->Rows[indexCount]->Cells[4]->Style = boldStyle;
    }

    else {
        MessageBox::Show("Продажи по этому товару не найдены.", "Отчет", MessageBoxButtons::OK, MessageBoxIcon::Information);
        this->Close();
        return System::Void();
    }
}

System::Void Muztorg::Check_Report::Check_Report_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Form^ form = Application::OpenForms[1];
    form->Show();
    return System::Void();
}

