#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

//user existence twice in database (solved successfully)
//sign in and sign out (solved successfully)

int sign_up(){
    //idatabse = input reading database
    //wdatabase = output writing database
    string username, password;
    string unique_key;
    string key_identifier;
    string line;

    //cin.ignore(10, '\n');
    cout << "Username & Password must contain at least" << endl << "1 Capital Character" << endl << "1 Number" << endl;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);

    
    unique_key = username + "." + password;

    //Removing Whitespace and Assigning it to the key_identifier
    for(char str : unique_key){
        if(str != '\n' && str != ' ' && str != '\t' && str != '\r')
        key_identifier += str;
    }

    unique_key = "username:" + username + "|password:" + password + "|" + key_identifier;

    //file handling to check existant user
    fstream idatabase("Database.txt", ios::in | ios::app);

    if(!idatabase.is_open()){
        cerr << "Failed to open Database" << endl;
        return 1;
    }

    while(getline(idatabase, line)){
        //Testing of keys
        //cout << "Line: " << line << endl;
        //cout << "Uniq: " << unique_key << endl;
        if(unique_key == line){
            cout << "User Already Exists" << endl;
            cout << "Do you wish to sign in?" << endl;
            idatabase.close();
            return 1;
        }
    }
    idatabase.close();

    //File Handling to create user and write data
    //One Declaration of file handling is not working correctly for both read and write purpose (issue # 2)
    fstream wdatabase("Database.txt", ios::in | ios::app);

    if(!wdatabase.is_open()){
        cerr << "Failed to open Database" << endl;
        return 1;
    }

    cout << "Creating new user" << endl;
    wdatabase << "username:" << username << "|password:" << password << "|" << key_identifier << endl;

    wdatabase.close();

    cout << "Key: " << key_identifier << endl;
    //printing data into the file
    cout << "User Successfully Registered " << endl;

}

int sign_in(){
    string username, password;
    string unique_key;
    string key_identifier;
    string line;
    fstream database("Database.txt", ios::in);

    cout << endl << "Please Provide Following Credentials" << endl;
    cout << "Enter Username: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);

    //database Existence checkup
    if(!database.is_open()){
        cout << "Failed to open Database" << endl;
        return 1;
    }


    unique_key = username + "." + password;

    for(char str : unique_key){
        if(str != '\n' && str != ' ' && str != '\t' && str != '\r')
        key_identifier += str;
    }

    //cout << "key_identifier: " << key_identifier << endl;


    //Logic to Find/Match the password
    //reading data from the file.
    while(getline(database, line)){
        //cout << line << endl;
        //cout << line.length() << endl;
        //cout << key_identifier.length() << endl;  
        int point = line.length() - key_identifier.length();

        unique_key = line.substr(point, line.length());

        if(unique_key == key_identifier){
            cout << "Welcome to Influx and Shit";
            break;
        }
    }

    if(unique_key != key_identifier){
        cout << "Password didn't match" << endl << "try again" << endl;
    }
}

int main(){

    sign_up();

    sign_in();
    

    return 0;
}