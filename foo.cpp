#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
bool check_product(string ent_word){
    string word;
/*Open The File  */
    ifstream file;
    file.open("product.txt", ios::app);

    if (file.is_open())
    {
        cout<<"The File Is open Successfully!!!"<<endl;
        while (getline(file,word))
        {
          cout<<"The The Word is: "<<word<<endl;
            if(ent_word == word)
            {
                cout<<"Product is Successfully Found"<<endl;
                break;
            }
            else
            {
               cout<<"Sorry This Product is Not Avalible"<<endl;
            }
        }
    }
    else
    {
        cout<<"The File Does Not Existing"<<endl;
    }
    file.close();
    return 0;
}
int main(){
    /*Taking The Name of The Product From The User*/
    string Product_name;
    cout<<"Please Enter The Product Name :"<<endl;
    getline(cin,Product_name);

    /*Passing The Name Of The Product To The Function */
    check_product(Product_name);    
    return 0;
}