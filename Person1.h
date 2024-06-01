#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string Name;
    int Age;
    char Gender; // F , M
public:
    string Mail;
    string Password;
    Person();
    Person(string name, int age, char gender, string mail, string pass = "1234567");
    void EditName(string name);
    void EditAge(int age);
    void EditMail(string mail);
    void EditPassword(string pass);
    void Print();
};

#endif
