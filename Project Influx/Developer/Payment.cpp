#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Payment.h"

using namespace std;

/* Definition OF Constructor For The Payment Class */


/* Definition Of Setter Function For The Payment Class */

// // void Payment::setCoupen(int coup)
// {
//     if(coup >= 0)
//     {
//         Coupon = coup;
//     }
//     else
//     {
//         Coupon = 0;
//     }
// }

// void Payment::setGiftcard(int g_card)
// {
//     if (g_card >= 0)
//     {
//         Gift_Card = g_card;
//     }
//     else
//     {
//         Gift_Card = 0;
//     }
// }

Invoice Payment::getInvoice(){
    return invoice;
}

void Payment::setShipcharge(string BuyerType)
{
    int charges;
    
    string user_id = BuyerType;

    string check_user = user_id.substr(0, 3);

    if (check_user == "STD"){

    int bill = getTotalBill();

        if (bill >= 500 && bill < 2000 )
        {
            charges = 100;
        }
        else if ( bill > 2000 && bill < 5000)
        {
            charges = 250;
        }
        else if ( bill >= 5000 && bill < 1000)
        {
            charges = 500;
        }
        else if ( bill >= 10000 )
        {
            charges = 1000;
        }

        double t_bill = bill + charges;
        setTotalBill(t_bill);
    }
    else
    {
        return;
    }
}

void Payment::setTransactionID(){
    transaction_ID = generate_TransactionID();

}

void Payment::setTotalBill(double bil){
    if (bil >= 0)
    {
        total_bill = bil;
    }
    else
    {
        total_bill = 0.0;
    }  
}

void Payment::setPaymentMethod(string Pay_Method){
    this->Pay_Method = Pay_Method;
}

// string Payment :: set_check_coupon(string coupon)
// {
//     bool check = check_Coupon(coupon);
//     if (check == true)
//     {
//         cout<<"valid"<<endl;
//     }
//     else
//     {
//         cout<<"The Coupon is invalid"<<endl;
//     }
//     return coupon;
// }
// int Payment :: getcoupen()
// {
//     return Coupon;
// }
int Payment :: getShippingCharges() const
{
    return shipping_charges;
}
double Payment::getTotalBill() const{
    return total_bill;
}

void Payment :: set_check_giftcard(string g_card)
{
    bool check_g_card = check_gift_card(g_card);

    if (check_g_card == true)
    {
        cout<<"You Gift Card Applied On Your Total Bill"<<endl;
    }
    else
    {
        cout<<"Your Car Was Not Valid Your Total Bill Will Remain The Same"<<endl;
    }
}

// int Payment :: getgiftcard()
// {
//     return Gift_Card;
// }
int Payment::generate_TransactionID(){
    //To generate unique each time it executes
    srand(time(0));
    int random_generate = rand()%100000000001;
    //return to the set function
    return random_generate;
}
int Payment::getTransactionID() const
{
    return transaction_ID;
}

void Payment::select_PaymentMethod(){
    int input;
    string Methods_of_Payment[5] = {"COD", "Mobile Payment", "MasterCard/VISA", "Credit Card", "Debit Card"};
    cout<<"Please Select One The Following Option \n 1. COD \n 2. Mobile Payment \n 3. MasterCard/VISA \n 4. Credit Card \n 5. Debit Card "<<endl;
    cin>>input;

    switch(input)
    {
    case 1:
        setPaymentMethod(Methods_of_Payment[1]);
        break;
    case 2:
        setPaymentMethod(Methods_of_Payment[2]);
        break;
    case 3:
        setPaymentMethod(Methods_of_Payment[3]);
        break;
    case 4:
        setPaymentMethod(Methods_of_Payment[4]);
        break;
    case 5:
        setPaymentMethod(Methods_of_Payment[5]);
        break;
    default:
        cout<<"Invalid Medthod Selected \nBy Default COD is Selected"<<endl;
        setPaymentMethod(Methods_of_Payment[1]);
        break;
    }
    //this sets the selected method of payment to the data member
}

string Payment::getPaymentMethod() const {
    return Pay_Method;
}

// void Payment::check_shipping_charges()
// {
//     // if(total_bill>2000){
//     //     shipping_charges = 0;
//     // }
//     // else{
//     //     shipping_charges = 400;
//     // }

//     //above reflects the same condition
//     //i used one liner
//     // shipping_charges = total_bill>2000 ? 0 : 400;
//     //setShipcharge();S
// }

bool Payment::check_Payment(){
    return !(Pay_Method.empty());
}

void Payment :: ApplyDiscount()
{
    string discount_code;
    int discount;

    while(1){
        cout << "Select One Option : \n\t 1.Apply Coupon Card \n\t 2. Apply Gift Card "<<endl;
        int choose;
        cin>>choose;

        if(choose > 2 || choose < 1){
            cout << "Invalid Input, Please Provide Correct Input."<< endl << endl;
        }

        if (choose == 1)
        {
            cout<<"Please Enter The Coupon Code : ";
            getline(cin,discount_code);
            discount = check_Coupon(discount_code);
        }
        if ( choose == 2)
        {
            cout<<"Please Enter The Gift Card Code : ";
            getline(cin,discount_code);
            discount = check_gift_card(discount_code);
        }
        
        total_bill = total_bill-(total_bill*(discount/100));
    }
}

int Payment :: check_Coupon(string C_code){  
    /*User will enter coupen if it is valid
    Set Coupen Function will cal inside the function to set the 
    Amount Of coupen discout which will be use further */

    //fstream usage to read file and match the coupon in the file
    //Will Reduce the amount of Total Bill
    //Save the coupon in the following format
    //PEHLAORDER2022.20
    //20 in the end represent amount of discount the coupon will give
    ifstream read_file;
    string temp,coupon;
    read_file.open("Coupen.txt", ios::app);
    bool flag;
    int discout;
    string price_code;
    if(read_file.is_open())
    {
        while (getline(read_file,temp))
        {
            stringstream ss(temp);
            getline(ss,coupon,';');
            getline(ss,price_code,';');

            if(C_code == coupon)
            {
                discout = stoi(price_code);
                flag = true;
                break;
            }
            else
            {
                discout = 0;
                flag = false;
            }
        }

    }
    else
    {
        cout<<"The File Does Not Existing"<<endl;
    }            
    read_file.close();
    
    return discout;
}
int Payment :: check_gift_card(string gft_card)
{
    ifstream read_f_file;
    string temp_line,gft_code;
    read_f_file.open("gift_card", ios::app);
    bool flag = false;
    int discout;
    string price_code;
    
    if(read_f_file.is_open())
    {
        while (getline(read_f_file,temp_line))
        {
            stringstream ss(temp_line);
            getline(ss,gft_code,';');
            getline(ss,price_code,';');
            
            if(gft_card == gft_code)
            {
                discout = stoi(price_code);
                flag = true;
                break;
            }
            else
            {
                flag = false;
                discout = 0;
            }
        }
    }
    else
    {
        cout<<"The File Does Not Existing"<<endl;
    }            
    read_f_file.close();
    return discout;
}
// void Payment :: setPayMethod(){
//     setTransactionID();
//     select_PaymentMethod();
//     ApplyDiscount();    
// }
// void Payment :: Order_info(const Buyer& buyer,const Order& order,vector<Cart>&)
// {
//     Payment_info(buyer,order);
// }