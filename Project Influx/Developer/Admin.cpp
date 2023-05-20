#include <iostream>
#include "Admin.h"

using namespace std;

//A vector Function that is used in the editProduct() below it.

void Admin::edit_Buyer_Seller_INFO(){
    
    cout << "This is Edit Panel of Buyer..." << endl << endl;
    while(true){
        cout << endl << endl << "[A] Change Information" << endl << "[B] Delete Account" << endl << "[C] Exit/Return " << endl << endl;
        cout << "Awating Response =>  ";
        char choose_action;
        cin >> choose_action;
        if(choose_action == 'C' || choose_action == 'c'){
            break;
        }
        if(choose_action != 'A' && choose_action != 'a' && choose_action != 'B' && choose_action != 'b'){
            cout << endl << "Invalid Input Provided ..." << endl << "Please Check and Try Again " << endl << endl << "Awating Response =>  ";

            continue;
        }

        int choose_file;
        cout << "Edit Information," << endl << "1. Buyer" << endl << "2. Seller"  << endl << "3. Go Back ..." << endl << endl << "Awaiting Response => ";
        cin >> choose_file;

        //conditions for choose files

        if(choose_file == 3){
            continue;
        }

        string file_path;
        if(choose_file == 1){
            file_path = "Users/Buyer.txt";
        }
        if(choose_file == 2){
            file_path = "Users/Seller.txt";
        }

        //NEXT STOP HERE
        ifstream file_reader(file_path);
        vector<string> file_lines;

        string single_line;

        while (getline(file_reader, single_line)) {
            file_lines.push_back(single_line);
        }
            
        file_reader.close();

        //Test Code for Current Content
        cout << "Current contents of file:\n";
        int count = 0;
        for (auto& single_line : file_lines) {
            cout << "___________________________________________________________________________";
            cout << count+1 << ". " << single_line << '\n';
            count++;
        }
        

        if(choose_action == 'A' || choose_action == 'a'){
            //Change Logic
            
            // Get the line number and field number of the entry to be modified
            int lineNumber = 0;
            int fieldNumber = 0;
            cout << endl << endl << "Enter the line number (starting from 1) of the entry to be modified: ";
            cin >> lineNumber;
            cout << "Enter the field number (starting from 1) of the value to be modified: ";
            cin >> fieldNumber;

            // Modify the required field
            string& entry = file_lines[lineNumber - 1];
            
            //Reading String Till Comma
            vector<string> FullLines = split(entry, ',');
            cout << "Current value of field " << fieldNumber << " is: " << FullLines[fieldNumber - 1] << '\n';

            cin.ignore();
            cout << "Enter the new value for field " << fieldNumber << ": ";
            string newValue;
            getline(cin, newValue);

            FullLines[fieldNumber - 1] = newValue;
            entry = FullLines[0];
            for (int i = 1; i < FullLines.size(); i++) {
                entry += ',' + FullLines[i];
            }
        }
        if(choose_action == 'B' || choose_action == 'b'){
            //Delete Logic

            int lineToDelete;
            cout << endl << endl << "Enter the Index of Line You Want to Delete" << endl << "ENTER -1 to EXIT DELETE MODE" << endl << "Awating Response =>  ";
            cin >> lineToDelete;

            if(lineToDelete == -1){
                continue;
            }

            char final_choice;
            while(true){
                cout << "Are You Sure You Want to Delete Your Account" << endl << endl << "[Y] YES\t[N] NO";
                cout << "Awaiting Response =>  ";
                cin >> final_choice;

                if(final_choice == 'Y' || final_choice == 'y'){
                    if (lineToDelete >= 1 && lineToDelete <= file_lines.size()) {
                        file_lines.erase(file_lines.begin() + lineToDelete - 1);
                    } else {
                        cerr << "Error: Line number is out of range\n";
                    }
                }
                if(final_choice == 'N' || final_choice == 'n'){
                    break;
                }
                if(choose_action != 'Y' || choose_action != 'y' || choose_action != 'N' || choose_action != 'n'){
                    cout << endl << "Invalid Input Provided ..." << endl << "Please Check and Try Again " << endl << endl << "Awating Response =>  ";
                }

            }
            // if(final_choice == 'N' || final_choice == 'n'){
            //     continue;
            // }
            
                    
            //Test Code for Printing
            //     for (auto& single_line : file_lines) {
            //     cout << "___________________________________________________________________________";
            //     cout << count+1 << ". " << single_line << '\n';
            //     count++;
            // }
        }

        ofstream file_writer(file_path);

        // Write the updated contents back to the file
        for (auto& line : file_lines) {
            file_writer << line << '\n';
        }
        file_writer.close();

        cout << "Updated contents of file:\n";

    }

    cout << endl << endl << "Buyer Entries Has Been Updated in Influx Database ..." << endl << "Ciao..." << endl;

    return;
}
//DONE
void Admin::edit_Product_INFO(){
    Product access_product;
    access_product.editProduct();
}
//DONE
void Admin::edit_Inventory_INFO(){
    Inventory access_inventory;
    access_inventory.edit_Inventory();
}
//DONE
string Admin::check_Person() const{
    return "admin";
}
//DONE
void Admin::print_info() const {
    cout << "Admin Name : " << getName() << endl << "username : " << getUsername() << endl << "password : " << getPassword() << endl;
}

void Admin::editINFO(){
    //Empty Implementation
}