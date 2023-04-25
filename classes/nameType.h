#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

class nameType{
    string first_name, last_name;

    public:
        nameType(string,string);//DONE

        void setFirstName(string);//DONE
        string getFirstName() const;//DONE

        void setLastName(string);//DONE
        string getLastName() const;//DONE

        void print_name() const;//DONE
};