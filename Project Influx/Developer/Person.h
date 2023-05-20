#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person{
    protected:
        string name;
        string username, password;
        int PhoneNumber;
        string date_of_joining;

    public:
        // Person(string, string, string, string, int, int, int, int): name(string,string), date_of_joining(int,int,int);

        void setName(string);
        string getName() const; //use print_name() of nameType.h

        void setUsername(string);
        string getUsername() const;

        void setPassword(string);
        string getPassword() const;

        void setPhoneNumber(int);
        int getPhoneNumber() const;

        void setDateOfJoining();
        string getDateOfJoining() const;//use print_date() of dateType.h

        //OVERRIDE Methods
        virtual void print_info() const = 0;
        virtual string check_Person() const = 0;
        virtual void editINFO() = 0;
};

#endif