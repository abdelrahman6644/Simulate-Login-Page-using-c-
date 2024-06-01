#include "Person1.h"

Person::Person() {
    Name = "";
    Age = 18;
    Gender = 'M';
    Mail = "No18@example.com";
    Password = "1234567";
}

Person::Person(string name, int age, char gender, string mail, string pass) :
    Name(name), Age(age), Gender(gender), Mail(mail), Password(pass) {}

void Person::EditName(string name) { Name = name; }
void Person::EditAge(int age) { Age = age; }
void Person::EditMail(string mail) { Mail = mail; }
void Person::EditPassword(string pass) { Password = pass; }

void Person::Print() {
    cout << "Name : " << Name << endl;
    cout << "Age : " << Age << endl;
    cout << "Gender: " << (Gender == 'F' ? "Female" : "Male") << endl;
}
