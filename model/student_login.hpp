#include<iostream>
#include <iomanip> // For std::setw
#include <windows.h>
#include <chrono>
#include <conio.h>
#include <thread>
#include"../design/student_design.hpp"
using namespace std;

string correctPw;
string correctName;

void studentMenu(){
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(h, 6);
 system("cls");
     designstudentLogin( text2,numCol);
cout<<"\n";
cout<<"\t\t\t\t\t  ||=========================================================||"<<endl;
cout<<"\t\t\t\t\t  ||               Welcome to Student Menu                   ||"<<endl;
cout<<"\t\t\t\t\t  ||=========================================================||"<<endl;
cout<<"\t\t\t\t\t  ||             1.Register                                  ||"<<endl;
cout<<"\t\t\t\t\t  ||             2.login                                     ||"<<endl;
cout<<"\t\t\t\t\t  ||             3.Logout                                    ||"<<endl;
cout<<"\t\t\t\t\t  ||=========================================================||"<<endl;
}

string getHiddenPass() {
    string pin;
    char ch;
    while ((ch = _getch()) != '\r') {  
        if (ch == '\b') {  
            if (!pin.empty()) {
                cout << "\b \b";  
                pin.pop_back();  
            }
        } else {
            pin.push_back(ch); 
            cout << '*';   
        }
    }
    cout << endl;  
    return pin;
}

//srab function register mun ng login kert
void registerUser(){
   system("cls"); 
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
cout<<"\t\t\t\t\t  ||                         RRGISTER                      ||"<<endl;
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
    cout<<"\n";
    cout << "\t\t\t\t\t Enter Student name: ";
    cin >> correctName;
    cout<<"\n";
    cout << "\t\t\t\t\t Enter Student password: ";
    correctPw = getHiddenPass();
    cout<<"\n";
    cout << "\t\t\t\t\t Confirm password: ";
    string confirmPassword;
    confirmPassword = getHiddenPass();
    while(confirmPassword != correctPw){
        cout<<"\n";
        cout << "\t\t\t\t\t Passwords do not match!" << endl;
        cout<<"\n";
        cout << "\t\t\t\t\t Enter student password: ";
        correctPw = getHiddenPass();
        cout<<"\n";
        cout << "\t\t\t\t\t Confirm password: ";
        confirmPassword = getHiddenPass();
    }
    system("cls");
}

void login(){
    system("cls"); 
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
cout<<"\t\t\t\t\t  ||                          LOGIN                        ||"<<endl;
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;

    string username, password;
    cout<<"\n";
    cout << "\t\t\t\t\t Enter student username: ";
    cin >> username;
    cout<<"\n";
    cout << "\t\t\t\t\t Enter student password: ";
    password = getHiddenPass();

    while((username != correctName) || (password != correctPw)){
        cout<<"\n";
        cout << "\t\t\t\t\t Incorrect username or password!" << endl;
        cout<<"\n";
        cout << "\t\t\t\t\t Enter student name: ";
        cin >> username;
        cout<<"\n";
        cout << "\t\t\t\t\t Enter student password: ";
        password = getHiddenPass();
    }
}

void Logout(){
system("cls"); 
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
cout<<"\t\t\t\t\t  ||                          LOGOUT                       ||"<<endl;
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
    cout<<"\n";
    cout<<"\t\t\t\t\t User is already logout....."<<endl;
    cout<<"\n";
    cout << "\t\t\t\t\t Press enter to contine......";
    cin.ignore();
    cin.get();
    studentMenu();
}

void studentOption(){
    int num;
    studentMenu();
 while(true){
    cout<<"\n";
    cout<<"\t\t\t\t\t Please choose number: ";
    cin>>num;
    cout<<"\n";
switch(num){
    case 1:{
        system("cls");
        registerUser();
        studentMenu();
   break;
 }
 case 2:{
    system("cls");
    login();
cout<<" Please enter your name or class name to view your score: ";
  break;
 }
  case 3:{
   system("cls");
   Logout();
   break;
    }
   }
 }
}


