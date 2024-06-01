#ifndef ASSISTANT_TEACHER_H
#define ASSISTANT_TEACHER_H

#include "Teacher.h"
#include "Student1.h"

class Assistant_Teacher : public Teacher, public Student {
public:
    Assistant_Teacher() {

    }
    Assistant_Teacher(std::string name, int age, char gender, std::string mail, std::array<std::string, 5> materials, int No,
        std::string pass = "1234567", float gpa = 4.0, std::string level = "Graduate", float salary = 4000);

    void Print();
    friend int findinassistant(Assistant_Teacher S[], int size, std::string mail, std::string pass);
};

#endif // ASSISTANT_TEACHER_H
