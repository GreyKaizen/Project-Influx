#include <iostream>
#include <string>
#include "nameType.h"
#include "dateType.h"

using namespace std;

class Person{
    nameType name;
    string username, password;
    int PhoneNumber;
    dateType date_of_joining;

    public:
        Person(string, string, string, string, int, int, int, int): name(string,string), date_of_joining(int,int,int);

        void setName(string, string);
        void getName() const; //use print_name() of nameType.h

        void setUsername(string);
        string getUsername() const;

        void setPassword(string);
        string getPassword() const;

        void setPhoneNumber(int);
        int getPhoneNumber() const;

        void setDateOfJoining(int,int,int);
        void getDateOfJoining() const;//use print_date() of dateType.h

        //OVERRIDE Methods
        virtual void print_info() const = 0;
        virtual string check_Person() const = 0;
        virtual void changeINFO() = 0;
};
