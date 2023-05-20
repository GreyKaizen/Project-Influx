#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Session.h"
#include <iomanip>


using namespace std;

string Session::file_paths[20] = {"Users/All_User.txt", "Users/Admin.txt", "Users/Buyer.txt", "Users/Seller.txt", "Products/All_Product.txt", "Products/Categories/ELC101.txt", "Products/Categories/FSH102.txt","Products/Categories/BPC103.txt", "Products/Categories/SPO104.txt", "Products/Categories/MED105.txt", "Products/Categories/TNG106.txt","Products/Categories/PET107.txt", "Products/Categories/AUT108.txt","Products/Inventories/KAR101.txt", "Products/Inventories/LAH102.txt", "Products/Inventories/ISB103.txt", "Products/Inventories/PEW104.txt", "Products/Inventories/QET105.txt", "Products/Inventories/NYC106.txt", "Products/Inventories/DXB108.txt"};

// function which is used in login
// string Session :: findMatchingLine(const string& filename, const string& str1, const string& str2)
string Session :: findMatchingLine(string& filename,string& str1,string& str2)  {
    //filename should be removes from the parameter list
    //for(int i = 0 ; i < 19 ; i++){
        ifstream file(filename);
        string line;

        // Check if the file opened successfully
        if (!file) {
            cerr << "Error: Failed to open the  file\n";
            return "";
        }

        while (getline(file, line)) {
            istringstream iss(line);
            string token;
            bool matchFound = false;

            while (getline(iss, token, ',')) {
                // Trim whitespace from the token
                token.erase(0, token.   find_first_not_of(" \t\r\n"));
                token.erase(token.find_last_not_of  (" \t\r\n") + 1);

                // Check if both strings match in   the line
                if (token == str1 || token ==   str2) {
                    matchFound = true;
                    break;
                }
            }

            if (matchFound) {
                file.close();
                return line;
            }
        }

        file.close();
    //}
    return "";
}

void Session::Register() {


        int input;

        while (true){
        cout << endl;
        cout << "Aap kis Sarif ki hesiat se idraj krna chahte hen :"<<endl;
        cout << "1. Khareedar "<<endl<< "2. Sodagar"<<endl<<"3.Exit"<<endl<<endl;
        cout << "System jawab ka muntazir he =>  ";
        cin >> input;
        if (input == 1){
            while (true){
            cout << "Khareedar men aap kia banna chahte hen :"<<endl;
            cout << "1. Mayari Khareedar "<<endl<<"2. Khasusi Khareedar"<<endl;
            cout << endl << "System jawab ka muntazir he =>  ";
            
            cin >> input;

            if(input == 1){
                Standard_Buyer buyer;
                cin >> buyer;
                buyer.write();
            }

            else if(input == 2){
                EliteBuyer buyer;
                cin >> buyer;
                buyer.write();}

            else if (input == 3){
                break;
                
            }
            
            else {
                cout << "Invalid input!! Please provide valid input."<<endl;
                continue;
            }
            }
        
        }
  
        if (input == 2){
            while (true){
            cout << "Sodagar men aap kia banna chahte hen :"<<endl;
            cout << "1. Aaam sodagar (Commonseller) "<<endl<<"2. Khorda farosh (Wholesaler)"<<endl;
            cout << endl << "System jawab ka muntazir he =>  ";

            cin >> input;


            // boy seller complete hoga to ye 2 kam krna shuru krdenge
            if(input == 1){
                CommonSeller seller;
                cin >> seller;
                seller.write();
            }
            else if(input == 2){
                WholeSaler seller;
                cin >> seller;
                seller.write();
            } 
            else if(input == 3){
                break;
            }
                else {
                cout << "Invalid input!! Please provide valid input."<<endl;
                continue;
            }}
        
        }

        if (input == 3){
        break;
        }
        if(input < 1 || input > 3){
                cout << "Invalid input!! Please provide valid input."<< endl; 
                continue;
        }
        }

        cout << "Aap ka idraj ho chuka he ab Login kren. Shukriya"<<endl;


        return;
}

// 3 alphabets return krega
// string Session::matchStrings(string& filename, string& str1, string& str2) {
//     ifstream file(filename);
//     string line;
//     while (getline(file, line)) {
//         istringstream iss(line);
//         string token;
//         bool found_str1 = false;
//         bool found_str2 = false;
//         while (iss >> token) {
//             if (token == str1) {
//                 found_str1 = true;
//             }
//             if (token == str2) {
//                 found_str2 = true;
//             }
//         }
//         if (found_str1 && found_str2) {
//             return line;
//         }
//     }
//     return "";
// }

string Session::matchStrings(string& filename, string& str1, string& str2) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string token;
        bool found_str1 = false;
        bool found_str2 = false;
        string field3, field4;
        int field_count = 0;
        while (getline(iss, token, ',')) {

            // cout << token << endl;
            field_count++;
            if (field_count == 3) {
                field3 = token;
            } else if (field_count == 4) {
                field4 = token;
            }
            if (token == str1) {
                found_str1 = true;
            }
            if (token == str2) {
                found_str2 = true;
            }
        }
        if (found_str1 && found_str2) {
            return line;
        }
    }
    return "";
}

// int main() {
//     std::string filename = "example.txt"; // Example filename
//     std::string str1 = "hello"; // Example first string to match
//     std::string str2 = "world"; // Example second string to match
//     std::string result = matchStrings(filename, str1, str2);
//     if (result == "admin") {
//         std::cout << "The strings \"" << str1 << "\" and \"" << str2 << "\" were found in the file.\n";
//     } else {
//         std::cout << "The strings \"" << str1 << "\" and \"" << str2 << "\" were not found in the file.\n";
//     }
//     return 0;
// }

// string Session::login(){
//     string str1, str2;

//     // Get the two strings from the user
//     cout << "Username: ";
//     getline(cin >> ws, str1);
//     cout << "Password: ";
//     getline(cin >> ws, str2);

//     string File_Users[4] = {"Users/Buyer.txt", "Users/Seller.txt", "Users/Admin.txt", "Users/All_User.txt"};

//     string matchingLine;
//     // Find the matching line in the file
//     for (int i = 0; i < 4; i++) {
//         if(File_Users[i] == "Users/Admin.txt"){
//             matchingLine = matchStrings(File_Users[i],str1,str2);

//             cout << "Here is the Line That Matched" << endl << matchingLine;
//         }
//         else{
//             matchingLine = findMatchingLine(File_Users[i], str1, str2);
//         }
//     }



string Session::login(){
    string str1, str2;

    // Get the two strings from the user
    cout << "Username: ";
    getline(cin >> ws, str1);
    cout << "Password: ";
    getline(cin >> ws, str2);

    string File_Users[4] = {"Users/Buyer.txt", "Users/Seller.txt", "Users/Admin.txt", "Users/All_User.txt"};

    string matchingLine;
    bool foundMatch = false; // add this variable
    
    // Find the matching line in the file
    for (int i = 0; i < 4; i++) {
        if(File_Users[i] == "Users/Admin.txt"){
            matchingLine = matchStrings(File_Users[i],str1,str2);

            //cout << "Here is the Line That Matched" << endl << matchingLine;
        }
        else{
            matchingLine = findMatchingLine(File_Users[i], str1, str2);
        }
        if (!matchingLine.empty()) {
            foundMatch = true;
            break; // break out of the loop if a match is found
        }
    }
        
    if (foundMatch) { // check the value of foundMatch
        return matchingLine;
    } 
    else {
        cout << "The username and password do not match any existing accounts. Please register a new account." << endl;
        cout << "Do you want to register a new account?\n[1] Yes, register now\t [2] No, register later" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            Register();
        } 
        else {
            return "";
        }
    }
}
        
//     cout << "Outside Loop : ";
//     cout << matchingLine;
//         // if (!matchingLine.empty() && File_Users[i] == "/classes/Users/Admin.txt") {
//         //     return "admin";
//         // } 
//     if (!matchingLine.empty()) {
//         return matchingLine;
//     } 
//     else {
//         cout << "The username and password do not match any existing accounts. Please register a new account." << endl;
//         cout << "Do you want to register a new account?\n[1] Yes, register now\t [2] No, register later" << endl;
//         int choice;
//         cin >> choice;

//         if (choice == 1) {
//             Register();
//         } 
//         else {
//             return "";
//         }
//     }
// }

void Session::checkout(vector<Cart>& cart) {
    //insert files
    for(int i = 0; i < 20 ; i++){

        string filename = file_paths[i];
        ifstream file(filename);
        string line;

        // Check if the file opened successfully
        if (!file) {
            cerr << "Error: Failed to open the file\n";
            return;
        }

        // Read the file line by line
        vector<string> fileLines;
        while (getline(file, line)) {
            fileLines.push_back(line);
        }

        // Update the balance for each item in the cart
        for (int i = 0; i < cart.size(); i++) {
            string str1 = cart[i].product.getName();
            string str2 = to_string(cart[i].product.getPrice());
            int Qty = cart[i].quantity;

            // Search the file for a matching line
            for (int j = 0; j < fileLines.size(); j++) {
                istringstream iss(fileLines[j]);
                string token;
                int stock;

                // Get the stock from the third position of the line
                getline(iss, token, ',');
                getline(iss, token, ',');
                if (getline(iss, token, ',')) {
                    stock = stoi(token);
                }

                // Check if the two strings match the line
                if (str1 == token && getline(iss, token, ',') && str2 == token) {
                    // Deduct the price from the balance and update the line in the file
                    stock -= Qty;
                    stringstream ss;
                    ss << str1 << "," << str2 << "," << stock;
                    fileLines[j] = ss.str();
                }
            }   
        }

        file.close();

        // Write the updated lines back to the file
        ofstream outFile;
        outFile.open(filename, ios::out | ios::trunc);
        if (outFile.is_open()) {
            for (int i = 0; i < fileLines.size(); i++) {
                outFile << fileLines[i] << endl;
            }
        } else {
            cerr << "Error: Failed to open the file for writing\n";
            return;
        }

        outFile.close();
    }
}

// string ko compare krne ke liay
bool areStringsEqual(const string& str1, const string& str2) {
    return str1 == str2;
}

string Session::determineuser(string line) {
    if (line.length() >= 3) {
        return line.substr(0, 3);
    } else {
        // If the line has 3 characters, return the entire line
        return line;
    }
}


// void Session :: logout(){}


// void Session :: Endofsession(){}

// Function to encode the data
void Session::encryptData() {
    for(int i = 0 ; i < 20 ; i++){
        // ifstream file(file_paths[i]);
        // string line;
        
        // Open the file for reading and writing
        fstream file(file_paths[i], ios::in | ios::out | ios::binary);

        // Check if the file opened successfully
        if (!file) {
            cout << file_paths[i];
            cout << "Error: Failed to open the  file\n";
            return;
        }

        // Read the contents of the file into a     vector
        vector<char> data(istreambuf_iterator<char> (file), {});

        // Perform the encoding operation on the    data
        // Here, we will simply increment each  character by 1
        transform(data.begin(), data.end(), data.   begin(), [](char c) { return c + 1; });

        // Clear the file contents
        file.seekp(0);
        file.clear();

        // Write the encoded data back to the file
        copy(data.begin(), data.end(),  ostreambuf_iterator<char>(file));

        // Close the file
        file.close();
    }
    return;
}

// Function to decode the data
void Session :: decryptData() {
    for(int i = 0 ; i < 20 ; i++){
        // ifstream file(file_paths[i]);
        // string line;

        //string filename = "gjjgj";
        // Open the file for reading and writing
        fstream file(file_paths[i], ios::in |    ios::out | ios::binary);

        // Check if the file opened successfully
        if (!file) {
            cout << file_paths[i];
            cout << "Error: Failed to open the  file\n";
            return;
        }

        // Read the contents of the file into a     vector
        vector<char> data(istreambuf_iterator<char> (file), {});

        // Perform the decoding operation on the    data
        // Here, we will simply decrement each  character by 1
        transform(data.begin(), data.end(), data.   begin(), [](char c) { return c - 1; });

        // Clear the file contents
        file.seekp(0);
        file.clear();

        // Write the decoded data back to the file
        copy(data.begin(), data.end(),  ostreambuf_iterator<char>(file));

        // Close the file
        file.close();
    }
}


Buyer Session::BuyerExtractinfo(string line){ 
    Buyer buyer;
    istringstream iss(line);
    string token;
    int fieldCount = 0;

    while (getline(iss, token, ',')) {
        switch (fieldCount) { 
            case 0:
                buyer.setBuyerID(token);
            case 1:
                buyer.setName(token);
                break;
            case 2:
                buyer.setPhoneNumber(stoi(token));
                break;
            case 3:
                buyer.setBalance(stod(token));
                break;
            default:
                // Handle additional fields if necessary
                break;
        }

        fieldCount++;
    }

    return buyer;
}

Seller Session :: SellerExtractinfo(string line){ 
    Seller seller;
    istringstream iss(line);
    string token;
    int fieldCount = 0;

    while (getline(iss, token, ',')) {
        switch (fieldCount) {
            case 0:
                seller.setSellerID(token);
            case 1:
                seller.setName(token);
                break;
            case 2:
                seller.setPhoneNumber(stoi(token));
                break;
            case 3:
                seller.setCommissionMargin(stod(token));
                break;
            case 4:
                continue;
            case 5:
                continue;
            case 6:
                continue;
            case 7:
                seller.setBrand(token);
            
            default:
                // Handle additional fields if necessary
                break;
        }

        fieldCount++;
    }

return seller;

}

Admin Session::AdminExtractinfo(string line){
    Admin admin;
    istringstream iss(line);
    string token;
    int fieldCount = 0;

    while (getline(iss, token, ',')) {
        switch (fieldCount) {
            case 0:
                continue;
            case 1:
                admin.setUsername(token);
            case 2:
                admin.setPassword(token);
                break;
            case 3:
                admin.setName(token);
                break;
            
            default:
                // Handle additional fields if necessary
                break;
        }

        fieldCount++;
    }

    return admin;
}
