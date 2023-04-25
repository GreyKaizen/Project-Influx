#include <iostream>
#include "Invoice.h"
#include <time.h>
#include "dateType.h"
#include <cstdlib>

using namespace std;

void Invoice::generate_invoiceID(){
    //To generate unique each time it executes
    srand(time(0));
    int random_generate = rand()%100000000001;
    //return to the set function
    return random_generate;
}

void Invoice::setInvoiceID(){
    invoice_id = generate_invoiceID();
}

int Invoice::getInvoiceID() const {
    return invoice_id;
}

void Invoice::invoiceType(string Invoice_Type{
    this->Invoice_Type = Invoice_Type;
}

void Invoice::getInvoiceType() const {
    return Invoice_Type;
}

void Invoice::print_Invoice() const {
    cout << "Invoice ID : " << invoice_id << endl << "Invoice Type : " << Invoice_Type << endl << "Return Date : " << return_date;
}

void Invoice::getReturnDate(){
    return return_date;
}

void Invoice::generate_ReturnDate(){
    
}