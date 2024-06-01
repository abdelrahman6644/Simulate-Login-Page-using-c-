#include "Teacher.h"

Teacher::Teacher() {
    Salary = 5000;
    NoOfMaterials = 5;
}
Teacher::Teacher(string name, int age, char gender, string mail, array<string, 5> materials, int no, string pass, float salary) :
    Person(name, age, gender, mail, pass), Salary(salary), Materials(materials), NoOfMaterials(no) {
    for (int i = 0; i < no; i++) {
        Materials[i] = materials[i];
    }
}

void Teacher::Print() {
    cout << "Welcome, Doctor " << Name << endl;
    cout << "Here are your details\n";
    Person::Print();
    cout << "Salary : " << Salary << endl;
    cout << "-------The Materials-------\n";
    for (int i = 0; i < NoOfMaterials; i++)
        cout << "Material " << i + 1 << " : " << Materials[i] << endl;
}

int findinteacher(Teacher S[], int size, string mail, string pass) {
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
