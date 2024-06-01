#include <iostream>
#include <string>
#include <array>

using namespace std;

class Person {
protected:
    string Name;
    int Age;
    char Gender; // F , M
public:
    string Mail;
    string Password;
    Person(string name, int age, char gender, string mail, string pass = "1234567") :
        Name(name), Age(age), Gender(gender), Mail(mail), Password(pass) {}
    void EditName(string name) { Name = name; }
    void EditAge(int age) { Age = age; }
    void EditMail(string mail) { Mail = mail; }
    void EditPassword(string pass) { Password = pass; }
    void Print() {
        cout << "Name : " << Name << endl;
        cout << "Age : " << Age << endl;
        cout << "Gender: " << (Gender == 'F' ? "Female" : "Male") << endl;
    }
};

class Student : public virtual Person {
protected:
    float GPA;
    string Level;
public:
    Student(string name, int age, char gender, string mail, string pass, float gpa, string level) :
        Person(name, age, gender, mail, pass), GPA(gpa), Level(level) {}
    void Print() {
        cout << "Welcome, " << Name << endl;
        cout << "There are your details\n";
        Person::Print();
        cout << "GPA = " << GPA << endl;
        cout << "Level = " << Level << endl;
    }
    friend int findinstudent(Student S[], int size, string mail, string pass);
};

class Teacher : public virtual Person {
protected:
    float Salary;
    array<string, 5> Materials;
    int NoOfMaterials;
public:
    Teacher(string name, int age, char gender, string mail, string pass, float salary, array<string, 5> materials, int no) :
        Person(name, age, gender, mail, pass), Salary(salary), Materials(materials), NoOfMaterials(no) {}
    void Print() {
        cout << "Welcome, Doctor " << Name << endl;
        cout << "There are your details\n";
        Person::Print();
        cout << "Salary : " << Salary << endl;
        cout << "-------The Materials-------\n";
        for (int i = 0; i < NoOfMaterials; i++)
            cout << "Material " << i + 1 << " : " << Materials[i] << endl;
    }
    friend int findinteacher(Teacher S[], int size, string mail, string pass);
};

class Assistant_Teacher : public Teacher, public Student {
public:
    Assistant_Teacher(string name, int age, char gender, string mail, string pass, float gpa,
        string level, float salary, array<string, 5> materials, int No) :
        Person(name, age, gender, mail, pass),
        Student(name, age, gender, mail, pass, gpa, level),
        Teacher(name, age, gender, mail, pass, salary, materials, No) {}

    void Print() {
        cout << "Welcome, " << Person::Name << endl;
        cout << "There are your details\n";
        Person::Print();
        cout << "GPA = " << GPA << endl;
        cout << "Level = " << Level << endl;
        cout << "Salary : " << Salary << endl;
        cout << "-------The Materials-------\n";
        for (int i = 0; i < NoOfMaterials; i++)
            cout << "Material " << i + 1 << " : " << Materials[i] << endl;
    }
    friend int findinassistant(Assistant_Teacher S[], int size, string mail, string pass);
};

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

int findinassistant(Assistant_Teacher S[], int size, string mail, string pass) {
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

// DataBase
// 10 students
Student ss[10] = {
    Student("Ahmed", 20, 'M', "Ahmed20M@example.com", "123456mn", 3.0,"3"),
    Student("Mohamed", 19, 'M', "Mohamed19M@example.com", "123456qa", 3.5, "2"),
    Student("Abdelrahman", 22, 'M', "Abdelrahman22M@example.com", "123456Av", 2.5, "4"),
    Student("Moaaz", 20, 'M', "Moaaz20M@example.com", "123456po", 3.5, "2"),
    Student("Khaled", 21, 'M', "Khaled21M@example.com", "123456jh", 3.1, "3"),
    Student("Taha", 20, 'M', "Taha20M@example.com", "123456yu", 2.0, "2"),
    Student("Farid", 23, 'M', "Farid23M@example.com", "123456aa", 2.3, "4"),
    Student("Farah", 20, 'F', "Farah20F@example.com", "123456bb", 2.73, "2"),
    Student("Salma", 23, 'F', "Salma23F@example.com", "123456cc", 2.47, "4"),
    Student("Reem", 23, 'F', "Reem23F@example.com", "123456dd", 2.365, "4")
};

// 3 Teachers
array<string, 5> Mat = { "comp1", "comp2", "comp3", "", "" };
array<string, 5> Mat1 = { "comp4", "comp5", "comp6", "", "" };
array<string, 5> Mat2 = { "comp7", "comp8", "comp9", "", "" };

Teacher TT[3] = {
    Teacher("Khaled", 50, 'M', "Khaled50@example.com", "123456TTT", 7000, Mat2, 3),
    Teacher("Mohamed", 45, 'M', "Mohamed45@example.com", "123456TT", 6500, Mat1, 3),
    Teacher("Atef", 40, 'M', "Atef40@example.com", "123456T", 6000, Mat, 3)
};

// 3 Assistant Teachers
array<string, 5> Mat3 = { "comp1", "comp4", "comp7", "", "" };
array<string, 5> Mat4 = { "comp2", "comp6", "comp8", "", "" };
array<string, 5> Mat5 = { "comp3", "comp7", "comp9", "", "" };

Assistant_Teacher ATT[3] = {
    Assistant_Teacher("Khaled", 29, 'M', "Khaled29@example.com", "123456AT2", 3.8, "Graduate", 2500, Mat5, 3),
    Assistant_Teacher("Abdelrahman", 28, 'M', "Abdelrahman28@example.com", "123456AT1", 3.7, "Graduate", 2500, Mat4, 3),
    Assistant_Teacher("Ahmed", 26, 'M', "Ahmed26@example.com", "123456AT", 3.6,"Graduate", 2500, Mat3, 3)
};

void loginPage(string& Email, string& Password) {
    cout << "Hello, This Program is to show the Student or Teacher or Assistant Teacher in our Faculty\n";
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "Email: "; cin >> Email;
    cout << "Password: "; cin >> Password;
}


void showOptions() {
    cout << "Choose what you need :\n";
    cout << "1.Edit Name\n";
    cout << "2.Edit Age\n";
    cout << "3.Edit Mail \n";
    cout << "4.Edit Password\n";
}
int main() {
    string Email, Password;
    bool ccheck = true;
    while (ccheck) {
        loginPage(Email, Password);
        string check;
        int index;
        if ((index = findinstudent(ss, 10, Email, Password)) != -1) {
            ss[index].Print();
            cout << "Are you need to edit your Details (yes/no)? : "; cin >> check;
            if (check == "yes" || check == "YES" || check == "Y" || check == "y") {
                while (true) {
                    int num;
                    showOptions();
                    cin >> num;
                    if (num == 1) {
                        cout << "type edited name : ";
                        string name;
                        cin >> name;
                        ss[index].EditName(name);
                    }
                    else if (num == 2) {
                        cout << "type edited Age : ";
                        int age;
                        cin >> age;
                        ss[index].EditAge(age);
                    }
                    else if (num == 3) {
                        cout << "type edited Mail : ";
                        string mail;
                        cin >> mail;
                        ss[index].EditMail(mail);
                    }
                    else if (num == 4) {
                        cout << "type edited Password : ";
                        string Password;
                        cin >> Password;
                        ss[index].EditPassword(Password);
                    }
                    else {
                        cout << "-----------------------------------------------------\n";
                        break;
                    }
                    cout << "Edit anyelse (yes/no)??";
                    cin >> check;
                    if (!(check == "yes" || check == "YES" || check == "Y" || check == "y")) {
                        cout << "-----------------------------------------------------\n";
                        break;
                    }
                }
            }
            cout << "Exit??(yes/no) : "; cin >> check;
            if (check == "yes" || check == "YES" || check == "Y" || check == "y") {
                return 0;
            }
        }
        else if ((index = findinteacher(TT, 3, Email, Password)) != -1) {
            TT[index].Print();

            cout << "Are you need to edit your Details (yes/no)? : "; cin >> check;
            if (check == "yes" || check == "YES" || check == "Y" || check == "y") {
                while (true) {
                    int num;
                    showOptions();
                    cin >> num;
                    if (num == 1) {
                        cout << "type edited name : ";
                        string name;
                        cin >> name;
                        TT[index].EditName(name);
                    }
                    else if (num == 2) {
                        cout << "type edited Age : ";
                        int age;
                        cin >> age;
                        TT[index].EditAge(age);
                    }
                    else if (num == 3) {
                        cout << "type edited Mail : ";
                        string mail;
                        cin >> mail;
                        TT[index].EditMail(mail);
                    }
                    else if (num == 4) {
                        cout << "type edited Password : ";
                        string Password;
                        cin >> Password;
                        TT[index].EditPassword(Password);
                    }
                    else {
                        cout << "-----------------------------------------------------\n";
                        break;
                    }
                    cout << "Edit anyelse (yes/no)??";
                    cin >> check;
                    if (!(check == "yes" || check == "YES" || check == "Y" || check == "y")) {
                        cout << "-----------------------------------------------------\n";
                        break;
                    }
                }
            }
            cout << "Exit??(yes/no)"; cin >> check;
            if (check == "yes" || check == "YES" || check == "Y" || check == "y") {
                return 0;
            }
        }
        else if ((index = findinassistant(ATT, 3, Email, Password)) != -1) {
            ATT[index].Print();
            cout << "Are you need to edit your Details (yes/no)? : "; cin >> check;
            if (check == "yes" || check == "YES" || check == "Y" || check == "y") {
                while (true) {
                    int num;
                    showOptions();
                    cin >> num;
                    if (num == 1) {
                        cout << "type edited name : ";
                        string name;
                        cin >> name;
                        ATT[index].EditName(name);
                    }
                    else if (num == 2) {
                        cout << "type edited Age : ";
                        int age;
                        cin >> age;
                        ATT[index].EditAge(age);
                    }
                    else if (num == 3) {
                        cout << "type edited Mail : ";
                        string mail;
                        cin >> mail;
                        ATT[index].EditMail(mail);
                    }
                    else if (num == 4) {
                        cout << "type edited Password : ";
                        string Password;
                        cin >> Password;
                        ATT[index].EditPassword(Password);
                    }
                    else {
                        cout << "-----------------------------------------------------\n";
                        break;
                    }
                    cout << "Edit anyelse (yes/no)??";
                    cin >> check;
                    if (!(check == "yes" || check == "YES" || check == "Y" || check == "y")) {
                        cout << "-----------------------------------------------------\n";
                        break;
                    }
                }
            }
            cout << "Exit??(yes/no)"; cin >> check;
            if (check == "yes" || check == "YES" || check == "Y" || check == "y") {
                return 0;
            }
        }
        else {
            cout << "The Email or The Password or Both is not Correct\n";
            cout << "Do you need to try again (y/n)? "; cin >> check;
            if (check != "y" && check != "Y") {
                cout << "Thank You for using our service\n";
                return 0;
            }
        }
    }
    return 0;
}
