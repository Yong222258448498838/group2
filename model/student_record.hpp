#include <iomanip> // For std::setw
#include <windows.h>
#include <chrono>
#include <conio.h>
#include"../design/welcome.hpp"
#include"admin_login.hpp"
#include"student_login.hpp"

using namespace std;

void studentTable(){
 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(h, 6);
 system("cls");

     desingStuRecord(text, numColumns);
     
cout<<"\n";
cout<<"\t\t\t\t\t   ||=========================================================||"<<endl;
cout<<"\t\t\t\t\t   ||               Welcome to Student Record System          ||"<<endl;
cout<<"\t\t\t\t\t   ||=========================================================||"<<endl; 
cout<<"\t\t\t\t\t   ||             1. Admin option                             ||"<<endl;   
cout<<"\t\t\t\t\t   ||             2. Student option                           ||"<<endl;
cout<<"\t\t\t\t\t   ||             0. Exit                                     ||"<<endl;
cout<<"\t\t\t\t\t   ||=========================================================||"<<endl;                                                               
cout<<"\n" ;
}

void studentSystem(){
    int number;
       studentTable(); //student record
       cout<<"\t\t\t\t\t  Please choose number to see the option: " ; cin>>number;
    cout<<"\n";
switch(number){
    case 1:{
        system("cls");
        adminOption();
   break;
  } 
  case 2:{
    system("cls");
    studentOption();
   

    
    // cout<<"User already logout.....!! " ;
    // cout<<"\n";
    // cout << "\t\t\t\t\t Press enter to contine......";
    // cin.ignore();
    // cin.get();
    // studentRecordTable();
    // adminOption();

  }
   break;
  }
  
}