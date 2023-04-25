#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>
#include "datetype.h"

using namespace std;

class Invoice{
    int invoice_id;
    dateType return_date;
    string Invoice_Type;

    //suggestion create an struct for the dateType

    public:
        void generate_invoiceID();//DONE
        void setInvoiceID();//DONE
        int getInvoiceID() const;//DONE


        void generate_ReturnDate();
        int getReturnDate() const;//DONE

        //First Check for the Status of the Payment if Done by the other than Cash ON Deleivery choice then user would have following options
        //BusinessInvoice(Bulk Buy),NormalInvoice, InternationalInvoice
        void setInvoiceType(string);//DONE
        string getInvoiceType() const;//DONE

        //Call generate_invoiceID,returnDate,invoiceType
        void print_Invoice() const;//DONE but NEED UI
};