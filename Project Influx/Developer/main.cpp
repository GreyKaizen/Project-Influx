#include <iostream>
#include <fstream>
#include <ctype.h>
#include <ctime>
#include "random"
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Admin.h"
#include "Seller.h"
#include "Buyer.h"
#include "Guest.h"
#include "Session.h"
#include "Product.h"
#include "Inventory.h"

using namespace std;

bool compareStrings(const string str1,const string str2) {
    if(str1 == str2){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    Session session;
    Product product;
    bool exit = false;

    while (!exit) {
        char choice;
        cout << "Welcome to the Influx" << endl;
        cout << "[A] Log in" << endl;
        cout << "[B] Visit as a Guest" << endl;
        cout << "[C] Register" << endl;
        cout << "[D] Exit" << endl;
        cout << "Awaiting Response => ";
        cin >> choice;

        if (choice == 'A' || choice == 'a') {
            string loginLine = session.login();
            string user = session.determineuser(loginLine);

            if (user == "") {
                cout << "Thanks for spending time on Influx" << endl << endl;
                exit = true;
            } else if (user == "ADM") {
                Admin admin = session.AdminExtractinfo(loginLine);
                bool adminExit = false;

                while (!adminExit) {
                    cout << "[A] Change Panel" << endl;
                    cout << "[B] View Admin Account Information" << endl;
                    cout << "[C] Exit" << endl;
                    cout << "Awaiting Response => ";
                    cin >> choice;

                    if (choice == 'A' || choice == 'a') {
                        cout << "Choose which information you want to edit..." << endl;
                        cout << "[A] Buyer and Seller" << endl;
                        cout << "[B] Product" << endl;
                        cout << "[C] Inventory" << endl;
                        cout << "Awaiting Response => ";
                        cin >> choice;

                        if (choice == 'A' || choice == 'a') 
                        {
                            admin.edit_Buyer_Seller_INFO();
                        } 
                        else if (choice == 'B' || choice == 'b') {
                            admin.edit_Product_INFO();
                        } 
                        else if (choice == 'C' || choice == 'c') {
                            admin.edit_Inventory_INFO();
                        } 
                        else {
                            cout << "Invalid choice" << endl;
                        }
                    } else if (choice == 'B' || choice == 'b') {
                        cout << "View Admin Account Information" << endl << endl;
                        admin.print_info();
                    } else if (choice == 'C' || choice == 'c') {
                        cout << "Thanks for spending time on Influx" << endl << endl;
                        adminExit = true;
                    } else {
                        cout << "Invalid choice" << endl;
                    }
                }
            } 
            else if (user == "STD" || user == "ELT") 
            {
                Buyer buyer = session.BuyerExtractinfo(loginLine);
                vector<Cart> cart;
                bool buyerExit = false;

                while (!buyerExit) 
                {
                    cout << "[A] View Products" << endl;
                    cout << "[B] View Personal Information" << endl;
                    cout << "[C] Checkout" << endl;
                    cout << "[D] Exit" << endl;
                    cout << "Awaiting Response => ";
                    cin >> choice;

                    if (choice == 'A' || choice == 'a') 
                    {
                        product.view_Product(cart);
                    } 
                    else if (choice == 'B' || choice == 'b') 
                    {
                        cout << endl;
                        buyer.print_info();
                    } 
                    else if (choice == 'C' || choice == 'c') 
                    {
                        initiate_Order_Quick_Buy(buyer, cart);

                        session.checkout(cart);

                        cart.clear();
                        cart.shrink_to_fit();
                        cout << "Thanks for your purchase!" << endl;
                    } 
                    else if (choice == 'D' || choice == 'd') 
                    {
                        cart.clear();
                        cout << "Thanks for spending time on Influx" << endl << endl;
                        buyerExit = true;
                    } 
                    else 
                    {
                        cout << "Invalid choice" << endl;
                    }
                }
            } 
            else if (user == "WHL" || user == "CMN") {
                Seller seller = session.SellerExtractinfo(loginLine);
                bool sellerExit = false;

                while (!sellerExit) {
                    cout << "[A] Sell Product" << endl;
                    cout << "[B] View Personal Information" << endl;
                    cout << "[C] Exit" << endl;
                    cout << "Awaiting Response => ";
                    cin >> choice;

                    if (choice == 'A' || choice == 'a') {
                        if(user == "WHL"){
                            WholeSaler customer;
                            customer.sell_Product(seller);
                        }
                        if(user == "CMN"){
                            CommonSeller customer;
                            customer.sell_Product();
                        }
                    } 
                    else if (choice == 'B' || choice == 'b') {
                        cout << endl;
                        seller.print_info();
                    } else if (choice == 'C' || choice == 'c') {
                        cout << "Thanks for spending time on Influx" << endl << endl;
                        sellerExit = true;
                    } else {
                        cout << "Invalid choice" << endl;
                    }
                }
            } else {
                cout << "Invalid login credential" << endl;
            }
        } 
        else if (choice == 'B' || choice == 'b') {
            Guest guest;
            cout << "Welcome Guest" << endl;
            vector<Cart> cart;
            product.view_Product(cart);
            cart.clear();
            cart.shrink_to_fit();
            guest.print_Register_toBuy();
        } 
        else if (choice == 'C' || choice == 'c') {
            cout << endl << endl;
            session.Register();
            cout << endl << endl;
        } 
        else if (choice == 'D' || choice == 'd'){
            cout << "Thanks for spending time on Influx" << endl << endl;
            exit = true;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

// int main(){
//     Session session;
//     //session.encryptData();

//     while(true){
//         char choice;
//         Product product;
//         cout << "Welcome to the Influx" << endl;
//         cout << "[A] Log in\n[B] Visit as a Guest\n[C] Exit\n\nAwaiting Response =>  ";
        
//         cin >> choice;

//         //session.decryptData();
        
//         if(choice == 'A' || choice == 'a')
//         {
//             //session.decryptData();
//             string loginLine = session.login();

//             if(compareStrings(session.determineuser(loginLine),""))
//             {
//                 cout << "Thanks For Spending Time on Influx" << endl << endl;

//                 //session.encryptData();
//                 break;
//             }
//             else if(compareStrings(session.determineuser(loginLine),"admin"))
//             {
//                 Admin admin = session.AdminExtractinfo(loginLine);
//                 cout << "[A] Change Panel\n[B] View Admin Account Information\n[C] Exit\n\nAwaiting Response =>  ";
//                 cin >> choice;
//                 if(choice == 'A' == choice == 'a')
//                 {
//                     cout << "Choose Which Information You Want to Edit..." << endl << "[A] Buyer and Seller\n[B] Product\n[C] Inventory\n\nAwaiting Response =>  ";
//                     cin >> choice;
//                     if(choice == 'A' == choice == 'a')
//                     {
//                         admin.edit_Buyer_Seller_INFO();
//                     }
//                     else if(choice == 'B' == choice == 'b')
//                     {
//                         admin.edit_Product_INFO();
//                     }
//                     else if(choice == 'C' == choice == 'c')
//                     {
//                         admin.edit_Inventory_INFO();
//                     }
//                 }
//                 if(choice == 'B' == choice == 'b')
//                 {
//                     //NOT DONE NEED LOGIC HERE
//                     cout << "View Admin Account Information" << endl << endl;
//                     admin.print_info();
//                 }
//             }
//             else if(compareStrings(session.determineuser(loginLine),"STD") || compareStrings(session.determineuser(loginLine),"ELT"))
//             {
//                 Buyer buyer;
//                 buyer = session.BuyerExtractinfo(loginLine);
//                 vector<Cart> cart;
//                 char choice_buyer;
//                 while(true)
//                 {
//                     cout << "[A] View Products\n[B] View Personal Information\n[C] CheckOut\n[D] Exit\n\nAwaiting Response =>  ";
//                     cin >> choice_buyer;
//                     if(choice_buyer == 'A' == choice_buyer == 'a')
//                     {
//                         product.view_Product(cart);
//                     }
//                     if(choice_buyer == 'B' == choice_buyer == 'b')
//                     {
//                         cout << endl << endl;
//                         buyer.print_info();
//                         continue;
//                     }
//                     if(choice_buyer == 'C' || choice_buyer == 'c')
//                     {
//                         initiate_Order_Quick_Buy(buyer,cart);
//                         session.checkout(cart);
//                     }
//                     if(choice_buyer == 'D' || choice_buyer == 'd')
//                     {
//                         cart.clear();
//                         cart.shrink_to_fit();
//                         cout << "Thanks For Spending Time on Influx" << endl << endl;
//                         // session.encryptData();
//                         break;
//                     }
//                 }
//             }
//             else if(compareStrings(session.determineuser(loginLine),"WHL") || compareStrings(session.determineuser(loginLine),"CMN"))
//             {
//                 Seller seller = session.SellerExtractinfo(loginLine);
//                 while(true){
//                     cout << "[A] Sell Product\n[B] View Personal Information\n[C] Exit\n[D] Exit\n\nAwaiting Response =>  ";
//                     cin >> choice;
//                     if(choice == 'A' == choice == 'a'){
//                         seller.sell_Product();
//                     }
//                     if(choice == 'B' == choice == 'b'){
//                         seller.print_info();
//                         cout << endl << endl;
//                         continue;
//                     }
//                     if(choice == 'C' || choice == 'c'){
//                         cout << "Thanks For Spending Time on Influx" << endl << endl;
//                         // session.encryptData();
//                         break;
//                     }
//                 }
//             }
//         }
//         else if(choice == 'B' || choice == 'b')
//         {
//             Guest guest;
//             vector<Cart> cart;
//             while(true){
//                 cout << "[A] View Product\n[B] Register\n[C] Exit\n\nAwaiting Response =>  ";
//                 cin >> choice;
//                 if(choice == 'A' == choice == 'a')
//                 {
//                     product.view_Product(cart);
//                     cout << endl << endl;
//                     //Releasing Memory
//                     cart.clear();
//                     cart.shrink_to_fit();
//                     guest.print_Register_toBuy();

//                     continue;
//                 }
//                 if(choice == 'B' == choice == 'b')
//                 {
//                     guest.register_user();
//                     cout << endl << endl;
//                     continue;
//                 }
//                 if(choice == 'C' || choice == 'c')
//                 {
//                     cout << "Thanks For Spending Time on Influx" << endl << endl;
//                     // session.encryptData();
//                     break;
//                 }
//             }
//         }
//         else if(choice == 'C' || choice == 'c')
//         {
//             cout << "Have a Nice Day!!" << endl;

//             // session.encryptData();
//             break;
//         }
//     }
// }

