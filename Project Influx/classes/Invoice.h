#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>

using namespace std;

class Invoice{
    int invoice_id;
    int return_date;
    int exchange_date;
    //suggestion create an struct for the dateType

    public:
        void setReturnDate(int);
        int getReturnDate();

        void generateInvoice();
};