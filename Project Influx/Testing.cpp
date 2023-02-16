// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
//     string s1, s2;

//     getline(cin, s1, '\n');
//     getline(cin, s2, '\n');

//     cout << "First string: " << s1 << endl;
//     cout << "Second string: " << s2 << endl;

//     return 0;
// }


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void saveLoginDataToFile() {
    string username;
    string password;

    // Get the username and password from the user
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Enter your password: ";
    getline(cin, password);

    // Open the file for writing
    fstream file("Database.txt", ios::app);
    //fstream database("Database.txt", ios::app);

    // Write the username and password to the file
    file << "Username: " << username << "\n";
    file << "Password: " << password << "\n";

    // Close the file
    file.close();
}
