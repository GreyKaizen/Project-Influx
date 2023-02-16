#include <iostream>
#include <string>
#include "iosign.h"


using namespace std;

int main(){
    int input;

    while(1){
        cout << "1.Sign in" << endl;
        cout << "2.Sign Up" << endl;
        cout << "3.Forgot Password" << endl;
        cout << "4.Exit the Shop" << endl;

        cin >> input;

        if(input == 1){ // Enter the Sign in

        }
        if(input == 2){ // Enter the Sign Up
            Sign_in();
        }
        if(input == 3){ // Enter the Forgot Password

        }
        if(input == 4){ // Enter the Sign in
            cout << endl << "Goodbye have a nice day!" << endl << endl;
            return 1;
        }
        if(input > 4 || input < 1){
            cout << endl << "Invalid Input" << endl << endl;
        }
    }
}
