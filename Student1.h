#ifndef STUDENT_H
#define STUDENT_H

#include "Person1.h"

class Student : public virtual Person {
protected:
    float GPA;
    string Level;
public:
    Student();
    Student(string name, int age, char gender, string mail, string pass = "1234567", float gpa = 4.0, string level = "1");
    void EditLevel(string level);
    void Print();
    friend int findinstudent(Student S[], int size, string mail, string pass);
};

#endif
