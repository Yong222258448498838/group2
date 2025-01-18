#include<iostream>
#include <iomanip> // For std::setw
#include <windows.h>
#include <chrono>
#include <conio.h>
#include <thread>
#include"../design/student_design.hpp"
using namespace std;

void studentOption(){
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(h, 6);
 system("cls");
     designstudentLogin( text2,numCol);
cout<<"\n";
cout<<"\t\t\t\t\t  ||=========================================================||"<<endl;
cout<<"\t\t\t\t\t  ||               Welcome to Student Login                  ||"<<endl;
cout<<"\t\t\t\t\t  ||=========================================================||"<<endl;
cout<<"\t\t\t\t\t  ||            Choice Option                                ||"<<endl;
cout<<"\t\t\t\t\t  ||                1.Login Use Name                         ||"<<endl;
cout<<"\t\t\t\t\t  ||                2.Login Use ID                           ||"<<endl;
cout<<"\t\t\t\t\t  ||=========================================================||"<<endl;

}