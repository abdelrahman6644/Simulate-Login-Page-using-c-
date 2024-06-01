#ifndef TEACHER_H
#define TEACHER_H

#include "Person1.h"
#include <array>

class Teacher : public virtual Person {
protected:
    float Salary;
    array<string, 5> Materials;
    int NoOfMaterials;
public:
    Teacher();
    Teacher(string name, int age, char gender, string mail, array<string, 5> materials, int no = 5, string pass = "1234567", float salary = 5000);
    void Print();
    friend int findinteacher(Teacher S[], int size, string mail, string pass);
};

#endif