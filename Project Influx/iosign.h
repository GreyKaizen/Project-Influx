#ifndef IO_SIGN
#define IO_SIGN

// #include "Presentes the header in present file"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//this header file is used to define all the classes and structs being used by the sign in/up process.

void Sign_in(){
    string username, password;

    cout << "Enter Username :";
    getline(cin, username, '\n');
    //cout << "Enter Password : ";
    getline(cin, password, '\n');

    fstream database("Database.txt", ios::app);
    //database.open("Database.txt");

    if(database.is_open()){
        //database << "Successfully opened Database.txt" << endl;
        cout << "Database Opened" << endl;
    }
    else{
        cout << "Failure Error : Database not opening" << endl;
    }

    //cin.putback('\n');   //Without this the program will not take input for the first string and jumps to the next string input

    //cin.ignore(1000,'\n');

    //database << left << setw(16) << "username:" << username;
    //database << "\t" << left << setw(16) << "password:" << password << endl;

    database << setw(30) << left << "username:" + username << right << "password:" + password << endl;

    database.close();

    //cout << "Database Closed" << endl;
    //cout << "Data is being saved to the database" << endl;

    cout << endl << "Successfully Registered"<< endl << "Try to Login with your account credentials" << endl << endl;

}
void Sign_up(){
    string username, password;

}

#endif
