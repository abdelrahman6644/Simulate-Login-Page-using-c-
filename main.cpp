#include <iostream>
#include <string>
#include <array>
#include "Person1.h"
#include "Student1.h"
#include "Teacher.h"
#include "Assistant_Teacher.h"
using namespace std;



// DataBase
Student ss[30] = {
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

array<string, 5> Mat = { "comp1", "comp2", "comp3", "", "" };
array<string, 5> Mat1 = { "comp4", "comp5", "comp6", "", "" };
array<string, 5> Mat2 = { "comp7", "comp8", "comp9", "", "" };

Teacher TT[30] = {
    Teacher("Khaled", 50, 'M', "Khaled50@example.com", Mat2, 3, "123456TTT", 7000),
    Teacher("Mohamed", 45, 'M', "Mohamed45@example.com", Mat1, 3, "123456TT", 6500),
    Teacher("Atef", 40, 'M', "Atef40@example.com", Mat, 3, "123456T", 6000)
};
array<string, 5> Mat3 = { "comp1", "comp4", "comp7", "", "" };
array<string, 5> Mat4 = { "comp2", "comp6", "comp8", "", "" };
array<string, 5> Mat5 = { "comp3", "comp7", "comp9", "", "" };

Assistant_Teacher ATT[30] = {
    Assistant_Teacher("Khaled", 29, 'M', "Khaled29@example.com", Mat5, 3, "123456AT2", 3.8, "Graduate", 2500),
    Assistant_Teacher("Abdelrahman", 28, 'M', "Abdelrahman28@example.com", Mat4, 3, "123456AT1", 3.7, "Graduate", 2500),
    Assistant_Teacher("Ahmed", 26, 'M', "Ahmed26@example.com", Mat3, 3, "123456AT", 3.6,"Graduate", 2500)
};

void loginPage(string& Email, string& Password) {
    cout << "Hello, This Program is to show the Student or Teacher or Assistant Teacher Details in our Faculty\n";
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
    int choose;
    int numStudet = 10;
    int numTeacher = 3;
    int numAssistant = 3;
    while (true) {
        cout << "1.Sign in\n";
        cout << "2.Sign up\n";
        cout << "3.Exit\n";
        cin >> choose;
        if (choose == 1){
            while (ccheck) {
                loginPage(Email, Password);
                string check;
                int index;

                if ((index = findinstudent(ss, numStudet, Email, Password)) != -1) {
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
                else if ((index = findinteacher(TT, numTeacher, Email, Password)) != -1) {
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
                else if ((index = findinassistant(ATT, numAssistant, Email, Password)) != -1) {
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
        }
        else if (choose == 2) {
            int ch;
            cout << "choose the Type of Email\n";
            cout << "1.Teacher\n";
            cout << "2.Assisstant Teacher\n";
            cout << "3.Student\n";
            cin >> ch;             
            string name;
            cout << "Name : "; cin >> name;
            int age;
            cout << "Age : "; cin >> age;
            char gender;
            cout << "Gender : "; cin >> gender;
            string mail;
            cout << "Mail : "; cin >> mail;
            string password;
            cout << "password : "; cin >> password;

            if (ch == 1) {
                cout << "choose the material : \n";
                cout << "1. Mat3 = { comp1, comp4, comp7}\n2. Mat4 = { comp2, comp6, comp8}\n3. Mat5 = { comp3, comp7, comp9}\n";
                cin >> ch;
                if (ch == 1)
                    TT[numTeacher] = Teacher(name, age, gender, mail, Mat3, 5, password, 5000);
                    
                else if(ch == 2)
                    TT[numTeacher] = Teacher(name, age, gender, mail, Mat4, 5, password, 5000);
                else
                    TT[numTeacher] = Teacher(name, age, gender, mail, Mat5, 5, password, 5000);

                numTeacher++;
            }
            else if (ch == 2) {
                cout << "choose the material : \n";
                cout << "1. Mat3 = { comp1, comp4, comp7}\n2. Mat4 = { comp2, comp6, comp8}\n3. Mat5 = { comp3, comp7, comp9}\n";
                cin >> ch;
                if (ch == 1)
                    ATT[numAssistant] = Assistant_Teacher(name, age, gender, mail, Mat3, 5, password, 5000);

                else if (ch == 2)
                    ATT[numAssistant] = Assistant_Teacher(name, age, gender, mail, Mat4, 5, password, 5000);
                else
                    ATT[numAssistant] = Assistant_Teacher(name, age, gender, mail, Mat5, 5, password, 5000);

                numAssistant++;
            }
            else if (ch == 3) {
                ss[numStudet] = Student(name, age, gender, mail, password);
                numStudet++;
            }
        }
        else 
            return 0;
    }
    return 0;
}