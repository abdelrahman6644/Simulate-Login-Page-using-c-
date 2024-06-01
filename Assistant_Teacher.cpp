#include "Assistant_Teacher.h"
#include <iostream>

Assistant_Teacher::Assistant_Teacher(std::string name, int age, char gender, std::string mail, std::array<std::string, 5> materials, int No,
    std::string pass, float gpa, std::string level, float salary) :
    Person(name, age, gender, mail, pass),
    Student(name, age, gender, mail, pass, gpa, level),
    Teacher(name, age, gender, mail, materials, No, pass, salary) {}

void Assistant_Teacher::Print() {
    std::cout << "Welcome, " << Person::Name << std::endl;
    std::cout << "There are your details\n";
    Person::Print();
    std::cout << "GPA = " << GPA << std::endl;
    std::cout << "Level = " << Level << std::endl;
    std::cout << "Salary : " << Salary << std::endl;
    std::cout << "-------The Materials-------\n";
    for (int i = 0; i < NoOfMaterials; i++)
        std::cout << "Material " << i + 1 << " : " << Materials[i] << std::endl;
}

int findinassistant(Assistant_Teacher S[], int size, std::string mail, std::string pass) {
    for (int i = 0; i < size; i++) {
        if (S[i].Mail == mail) {
            if (S[i].Password == pass)
                return i;
            else
                return -1;
        }
    }
    return -1;
}
