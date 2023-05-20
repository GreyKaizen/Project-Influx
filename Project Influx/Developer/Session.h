#ifndef SESSION_H
#define SESSION_H

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include "Buyer.h"
#include "Seller.h"
#include "Admin.h"

using namespace std;

class Session{
    static string file_paths[20];
    
    public:
        // Session(){
        //     decryptData();
        // }
        string login();
        void Register();
        void checkout(vector<Cart>&);
        string findMatchingLine(string& ,string& ,string& );
        // void logout();
        Buyer BuyerExtractinfo(string);
        Seller SellerExtractinfo(string);
        string determineuser(string) ;
        Admin AdminExtractinfo(string);
        // void Endofsession();

        // object constructor of session  will call decrypt
        // implement files
        void encryptData();
        // object destructor of session will call encrypt
        // implement files
        void decryptData();
        string matchStrings(string& , string& , string& );
};

#endif 