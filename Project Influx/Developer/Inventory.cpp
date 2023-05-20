#include <iostream>
#include <fstream>
#include <sstream>
#include "Inventory.h"

using namespace std;

string Inventory::inventory_files[7] = {"Products/Inventories/KAR101.txt", "Products/Inventories/LAH102.txt", "Products/Inventories/ISB103.txt", "Products/Inventories/PEW104.txt", "Products/Inventories/QET105.txt", "Products/Inventories/NYC106.txt", "Products/Inventories/DXB108.txt"};

string Inventory::inventories[7] = {"KAR101", "LHE102", "ISB103", "PEW104", "QET105", "NYC106", "DXB108"};

void Inventory::setStock(int stock){
    this->stock = stock;
}
int Inventory::getStock() const{
    return stock;
}

void Inventory::setLocation(string location){
    this->location = location;
}
string Inventory::getLocation() const{
    return location;
}

void Inventory::setID(string Inventory_ID){
    this->Inventory_ID = Inventory_ID;
}
string Inventory::getID() const{
    return Inventory_ID;
}


bool Inventory::checkPerson_Call(string PersonCheck){
    if(PersonCheck == "admin")
        return true;
    else
        return false;
}

void Inventory::view_Inventory(){
    //Remove admin, it was inserted for testing purposes
    if(!checkPerson_Call("admin")){
        cout << "Sorry, You can't Access this part of Influx." << endl <<  "This is Restricted Area (ONLY ADMIN)" << endl;
        //exit the function
        return;
    }

    // list<Product> products_list;
    // Product listed_in_list_product;

    cout << "Choose Options Below" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6.New York" << endl << "7.Dubai" << endl << "8. Print/View All (Choose it, ONLY if you can handle large amount of data) " << endl << "Awaiting Response => ";

    int input;
    cin >> input;

    //Reading Algorithm
    string line;
    istringstream read_string;
    string IID, Stock, temp;
    int count = 0;

    if(input > 0 && input < 8){
        fstream file_reader_inventory(inventory_files[input-1],ios::in); 

        if(!file_reader_inventory.is_open()){
            cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
        }    
        
        //read_string.str(line);
        while(getline(file_reader_inventory,line)){
            count++;
            Product show_product_info;
            istringstream read_string(line);

            count++;
            getline(read_string >> ws, IID, ',');
            getline(read_string >> ws, temp, ',');
            show_product_info.setProductID(temp);
            getline(read_string >> ws, Stock, ',');
            getline(read_string >> ws, temp, ',');
            show_product_info.setBrand(temp);
            getline(read_string >> ws, temp, ',');
            show_product_info.setName(temp);
            getline(read_string >> ws, temp, ',');
            show_product_info.setPrice(stoi(temp));

            cout << "***************" << endl << " | " << count << ". "<< " | " << "Inventory ID: " << IID << " | " << "Stock: " << Stock << " | "<< show_product_info << endl;
        }

        file_reader_inventory.close();
    }
    if(input == 8){

        for(int i = 0; i < 7 ; i++){
            count = 0;
            fstream file_reader_inventory(inventory_files[i-1],ios::in); 

            if(!file_reader_inventory.is_open()){
                cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
            }   

            cout << endl << endl << "***********" << endl;
            cout << "***********" << endl;
            cout << "***********" << endl;
            cout << "Opened Inventory: " << inventories[i-1] << endl;
            cout << "***********" << endl;
            cout << "***********" << endl;
            cout << "***********" << endl << endl << endl;
             

            while(getline(file_reader_inventory,line)){
                count++;
                Product show_product_info;
                istringstream read_string(line);

                getline(read_string >> ws, IID, ',');
                getline(read_string >> ws, temp, ',');
                show_product_info.setProductID(temp);
                getline(read_string >> ws, Stock, ',');
                getline(read_string >> ws, temp, ',');
                show_product_info.setBrand(temp);
                getline(read_string >> ws, temp, ',');
                show_product_info.setName(temp);
                getline(read_string >> ws, temp, ',');
                show_product_info.setPrice(stoi(temp));

                cout << "***************" << endl << " | " << count << ". "<< " | " << "Inventory ID: " << IID << " | " << "Stock: " << Stock << show_product_info << endl;

            }
            file_reader_inventory.close();
        }
    }

    return;
}
/*
void Inventory::search_Inventory(){
    //Wants to find certain thing from certain location
    Product *search = new Product;
    string search_product_name, search_brand_name;
    string IID, PID, Stock, Brand, Name, Price, Description;
    bool product_found_check = false;
    bool check_brand = true;
    fstream file_reader_product;

    cout << "Which Location Would you Prefer(Select the one near you for quick Deleveries)," << endl;
    cout << "1. Karachi, Pakistan:" << endl << "2. Lahore, Pakistan:"<< endl << "3. Islamabad, Pakistan:"<< endl << "4. Peshawar, Pakistan:"<< endl << "5. Quetta, Pakistan:"<< endl << "6. New York, USA:" << endl << "8. Dubai, UAE:" << "Awaiting Response => " << endl;

    int input;
    while(1){
        cin >> input;
        if(input <= 0 || input > 8){
            cout << endl << "Invalid Input ... " << endl << "Please Choose Correctly from above mentioned Categories" << endl << endl;
        }
        if(input > 0 || input <= 8){
            break;
        }
    }

    cout << "Before the Search Begins, Please Provide following Information" << endl,

    cin.ignore();
    cout << "Brand => ";
    getline(cin,search_brand_name);
    if(search_brand_name == "" || search_brand_name == "\n" || search_brand_name == " "){
        check_brand = false;
    }
    cout << "Name => ";
    getline(cin,search_product_name);

    cout << endl << "Let the Magic Search Begin ... " << endl << endl;

    cout << "Searching the Product : " << search_product_name << endl;

    for(int i = 0; i < 8 ; i++){
        //Opening File
        file_reader_product.open(inventory_files[i],ios::in);

        //Checking for File Existence
        if(!file_reader_product.is_open()){
            cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
        }    

        //Reading Algorithm
        string line;
        istringstream read_string;
            //read_string.str(line);
        while(getline(file_reader_product,line)){
            istringstream read_string(line);

            getline(read_string >> ws, IID, ',');
            getline(read_string >> ws, PID, ',');
            getline(read_string >> ws, Stock, ',');
            getline(read_string >> ws, Brand, ',');
            getline(read_string >> ws, Name, ',');
            getline(read_string >> ws, Price, ',');
            //Specific Category wise attributes can be defined here
            getline(read_string >> ws, Description, '\n');

            if(check_brand){
                if(search_product_name == Name && search_brand_name == Brand){
                    product_found_check = true;
                    //cout << "Inventory ID: " << IID;
                    //cout << endl << "Product ID: " <<     PID;
                    //cout << "Stock: " << Stock;
                    cout << endl << "Brand: " << Brand  << endl << "Name: " << Name << endl  << "Price: $" << Price << endl << "Description : " << Description;
                    
                    break;
                }
            }
            else{
                if(search_product_name == Name){
                    product_found_check = true;
                    //cout << "Inventory ID: " << IID;
                    //cout << endl << "Product ID: " << PID;
                    //cout << "Stock: " << Stock;
                    cout << endl << "Brand: " << Brand << endl << "Name: " << Name << endl << "Price: $" << Price << endl << "Description : " << Description;

                    break;
                }
            }
        }

        file_reader_product.close();

        if(product_found_check){
            search->setProductID(PID);
            search->setBrand(Brand);
            search->setName(Name);
            int price = stoi(Price);
            search->setPrice(price);
            search->setDescription(Description);

            break;
        }
    }
    
    if(!product_found_check){
        cout << endl << "Sorry, We couldn't find your product" << endl << "Checkout Influx next week when new stock arrives," << endl << "You might find what you are looking for" << endl << "Ciao..." << endl << endl;
    }

    //Testing Code
    // cout << "Calling by the Search Ptr : " << endl;
    // cout << endl << "Product ID : " << search->getProductID() << endl << "Brand : " << search->getBrand()<< endl << "Name : " << search->getName()<< endl << "Price : " << search->getPrice();

    return search;
}
*/
/*
void Inventory::search_Inventory(){
    vector<string> displayed_products;

    string search_product_name, search_brand_name;
    string IID, Stock, temp;
    bool product_found_check = false;
    bool check_brand = true;

    fstream file_reader_product;

    cout << "Searching for products..." << endl << "Provide Information about products" << endl;

    cin.ignore();
    cout << "Brand => ";
    getline(cin,search_brand_name);
    if(search_brand_name == "" || search_brand_name == "\n" || search_brand_name == " "){
        check_brand = false;
    }
    cout << "Name => ";
    getline(cin,search_product_name);

    cout << endl << "Let the Magic Search Begin ... " << endl << endl;


    cout << "Searching the Product : " << search_product_name << endl;

    //Algorithm to Open Multiple Files and check in each one of them
    for(int i = 0; i < 8 ; i++){
        //Opening File
        file_reader_product.open(inventory_files[i],ios::in);

        //Checking for File Existence
        if(!file_reader_product.is_open()){
            cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
        }    

        //Reading Algorithm
        string line;
        istringstream read_string;
            //read_string.str(line);
        while(getline(file_reader_product,line)){
            Pro
            istringstream read_string(line);

            getline(read_string >> ws, IID, ',');
            getline(read_string >> ws, productID, ',');
            getline(read_string >> ws, Stock, ',');
            getline(read_string >> ws, brand, ',');
            getline(read_string >> ws, product_name, ',');
            getline(read_string >> ws, temp, ',');
            price = stoi(temp);
            //Specific Category wise attributes can be defined here
            getline(read_string >> ws, description, '\n');

            if(check_brand){
                if(search_product_name == product_name && search_brand_name == brand){
                    product_found_check = true;
                    displayed_products.push_back(line);
                }
            }
            else{
                if(search_product_name == product_name){
                    product_found_check = true;
                    displayed_products.push_back(line);
                }
            }
        }

        file_reader_product.close();
    }
   
    if(!product_found_check){
        cout << endl << "Sorry, We couldn't find your product" << endl << "Checkout Influx next week when new stock arrives," << endl << "You might find what you are looking for" << endl << "Ciao..." << endl << endl;
    }

    for(int i = 0 ; i < displayed_products.size() ; i++){
        cout << i+1 << ". " << displayed_products[i] << endl;
    }

    //Testing Code
    // cout << "Calling by the Search Ptr : " << endl;
    // cout << endl << "Product ID : " << search->getProductID() << endl << "Brand : " << search->getBrand()<< endl << "Name : " << search->getName()<< endl << "Price : " << search->getPrice();

    return;
    //delete the search object where its called, after the use of search object,.
}
*/
//Below are 2 file logic member functions

void Inventory::edit_Inventory() {
    //Check Person Call
    //checkPerosn_Call(string);

    cout << "This is Edit Panel of Product..." << endl;
    while(true){
        cout << endl << endl << "[A] Change Information" << endl << "[B] Delete Product" << endl << "[C] Exit/Return " << endl << endl;
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
        cout << "Select from the Following Categories," << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl << "7. Dubai" << endl << "8. Go Back ..." << endl << endl << "Awaiting Response => ";
        cin >> choose_file;

        //conditions for choose files

        if(choose_file == 8){
            continue;
        }
        while(true){
            if(choose_file > 0 && choose_file < 8){
                break;
            }
            if(choose_file < 0 && choose_file >8){
                cout << endl << "OOPS! " << endl << "Please Provide the Correct the file name" << endl << endl << "Awaiting Response =>  " ;
            }
            cin >> choose_file;
        }

        //fstream file_reader(product_files(input-1), ios::in);

        ifstream file_reader(inventory_files[choose_file-1]);
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

            // while(true){
            //     char final_choice;
            //     cout << "Are You Sure You Want to Delete This Product" << endl << endl << "[Y] YES\t[N] NO";
            //     cout << "Awaiting Response =>  ";

            //     if(final_choice == 'N' || final_choice == 'n'){
            //         break;
            //     }
            //     if(choose_action != 'Y' && choose_action != 'y' && choose_action != 'N' && choose_action != 'n'){
            //         cout << endl << "Invalid Input Provided ..." << endl << "Please Check and Try Again " << endl << endl << "Awating Response =>  ";
            //     }

            // }

            if (lineToDelete >= 1 && lineToDelete <= file_lines.size()) {
                file_lines.erase(file_lines.begin() + lineToDelete - 1);
            } else {
                cerr << "Error: Line number is out of range\n";
            }
        //     for (auto& single_line : file_lines) {
        //     cout << "___________________________________________________________________________";
        //     cout << count+1 << ". " << single_line << '\n';
        //     count++;
        // }
        }

        ofstream file_writer(inventory_files[choose_file-1]);

        // Write the updated contents back to the file
        for (auto& line : file_lines) {
            file_writer << line << '\n';
        }
        file_writer.close();

        cout << "Updated contents of file:\n";

    }

    cout << endl << endl << "Product List Has Been Updated in Influx Database ..." << endl << "Ciao..." << endl;

    return;
    //delete product;
}

