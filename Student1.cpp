#include "Student1.h"

Student::Student() {
    GPA = 4.0;
    Level = "1";
}

Student::Student(string name, int age, char gender, string mail, string pass, float gpa, string level) :
    Person(name, age, gender, mail, pass), GPA(gpa), Level(level) {}

void Student::EditLevel(string level) { Level = level; }

void Student::Print() {
    cout << "Welcome, " << Name << endl;
    cout << "Here are your details\n";
    Person::Print();
    cout << "GPA = " << GPA << endl;
    cout << "Level = " << Level << endl;
}

int findinstudent(Student S[], int size, string mail, string pass) {
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
