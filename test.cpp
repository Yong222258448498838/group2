#include <iostream>
#include <vector>
#include <iomanip> //ah ng dak table setw and setprecision

using namespace std;
string correctPw;
string correctName;

// Vectors to store student data
vector<string> studentNames;
vector<float> mathScores;
vector<float> khmerScores;
vector<float> englishScores;

#include <iostream>
#include <conio.h>  // For getch()
#pragma once
using namespace std;

string getHiddenInput() {
    string pin;
    char ch;
    
    while ((ch = _getch()) != '\r') {  // '\r' is the Enter key
        if (ch == '\b') {  // Handle backspace
            if (!pin.empty()) {
                cout << "\b \b";  // Erase the last asterisk
                pin.pop_back();  // Remove last character from the string
            }
        } else {
            pin.push_back(ch);  // Add character to the string
            cout << '*';   // Print asterisk
        }
    }

    cout << endl;  // Move to the next line after Enter is pressed
    return pin;
}

void menu(){
    cout << "====| Options |====" << endl;
    cout << "1. Log in" << endl;
    cout << "2. Register" << endl;
    cout << "0. Exit" << endl;
    cout << "=======================" << endl;
    cout << "Enter your choice: ";
}

//pel register hz yg login ban
void login(){
    system("cls"); 
    cout << "====| Log in |====" << endl;
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    password = getHiddenInput();

    while((username != correctName) || (password != correctPw)){
        cout << "Incorrect username or password!" << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        password = getHiddenInput();
    }
}

//srab function register mun ng login kert
void registerUser(){
    cout << "====| Register |====" << endl;
    cout << "Enter username: ";
    cin >> correctName;
    cout << "Enter password: ";
    correctPw = getHiddenInput();
    cout << "Confirm password: ";
    string confirmPassword;
    confirmPassword = getHiddenInput();
    while(confirmPassword != correctPw){
        cout << "Passwords do not match!" << endl;
        cout << "Enter password: ";
        correctPw = getHiddenInput();
        cout << "Confirm password: ";
        confirmPassword = getHiddenInput();
    }
    system("cls");
}

//rk avg
float gradeAvg(float math, float khmer, float english){
    return (math + khmer + english) / 3.0;
}

//oy letter grade
string gradeLetter(float gpa){
    if (gpa >= 90) {
        return "A";
    } else if (gpa >= 80) {
        return "B";
    } else if (gpa >= 70) {
        return "C";
    } else if (gpa >= 60) {
        return "D";
    } else {
        return "F";
    }
}

//pjol data bos students and dak vea knong vectors
void addStudentData(){
    string studentName;
    float mathScore, khmerScore, englishScore;

    cin.ignore(); // Ignore leftover newline character

    cout << "Enter student name: ";
    getline(cin, studentName);

    cout << "Enter Math score: ";
    cin >> mathScore;

    cout << "Enter Khmer score: ";
    cin >> khmerScore;

    cout << "Enter English score: ";
    cin >> englishScore;

    // Add the student's data to the vectors
    studentNames.push_back(studentName);
    mathScores.push_back(mathScore);
    khmerScores.push_back(khmerScore);
    englishScores.push_back(englishScore);

    cout << "Student data added successfully!" << endl;
}

//pjenh data tang os ng jea table mk vinh srul mer
void displayAllStudents(){
    system("cls");
    if(studentNames.empty()){
        cout << "No students added yet!" << endl;
        return;
    }

    //kbal table 
    cout << left << setw(15) << "Student Name" 
         << setw(10) << "Math" 
         << setw(10) << "Khmer" 
         << setw(10) << "English" 
         << setw(10) << "GPA" 
         << setw(10) << "Grade" 
         << endl;
    cout << "---------------------------------------------------------------" << endl;

    
    for(size_t i = 0; i < studentNames.size(); ++i){
        float gpa = gradeAvg(mathScores[i], khmerScores[i], englishScores[i]);
        string grade = gradeLetter(gpa);

        
        cout << left << setw(15) << studentNames[i] 
             << setw(10) << fixed << setprecision(2) << mathScores[i]
             << setw(10) << fixed << setprecision(2) << khmerScores[i] 
             << setw(10) << fixed << setprecision(2) << englishScores[i] 
             << setw(10) << fixed << setprecision(2) << gpa 
             << setw(10) << grade 
             << endl;
    }
}

int main(){
    system("cls");
    int option;

    //run code ng mdong sin hz ban komnot leakhan check
    do {
        menu();
        cin >> option;

        switch (option) {
            case 1: {
                login();
                int addMore = 1;
                do {
                    system("cls");
                    addStudentData();
                    cout << "Would you like to add another student? (1 for Yes, 0 for No): ";
                    cin >> addMore;
                } while (addMore == 1);

                displayAllStudents();
                return 0; //doch teh ng break ng eng 
            }
            case 2: {
                registerUser();
                break;
            }
            case 0: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid Option!" << endl;
                break;
            }
        }
    } while (option != 0);

    return 0;
}
