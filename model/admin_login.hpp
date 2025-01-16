#include<iostream>
#include <iomanip> // For std::setw
#include <windows.h>
#include <chrono>
#include <conio.h>
#include <thread>
#include"../design/admin_design.hpp"
using namespace std;

//use when we input pass it show the exact number of pass
string getHiddenInput() {
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

void loadingAdmin(int totalSteps) {
    int barWidth = 50; // Width of the progress bar
    int this_thread;
cout<<"\n";
    for (int step = 0; step <= totalSteps; ++step) {
        // Calculate percentage
        float progress = static_cast<float>(step) / totalSteps;
       
        // Print the progress bar
        cout << "\t\t\t\t Loading[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) {
                cout << "=";
            } else if (i == pos) {
                cout << ">";
            } else {
                cout << " ";
            }
        }
        cout << "] " << int(progress * 100.0) << " %\r";
        cout.flush();
        this_thread::sleep_for(std::chrono::milliseconds(30));
    }
        // Simulate some work with a delay
    cout <<endl; 
} 

void adminLogin(){
    string name;
    string pass;
    designAdminLogin(text1,numColumn);
    cout<<"\n";
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
cout<<"\t\t\t\t\t  ||                           LOGIN                       ||"<<endl;
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
do{ 
    cout<<"\n";
    cout<<"\t\t\t\t\t Please enter admin name: ";
    cin>>name;
    cout<<"\n";
    cout<<"\t\t\t\t\t Please enter admin password: ";
    pass= getHiddenInput();
    if(name == "admin" && pass == "1234"){
        int totalSteps = 100;
         loadingAdmin(totalSteps);
        cout<<"\n";
       cout<<"\t\t\t\t\t Your login successfully."<<endl; 
    }
    else if(name == "admin" && pass != "1234"){
        cout<<"\t\t\t\t\t Wrong password!!\n";
        
        cout<<"\t\t\t\t\t Please log in again.\n";
    }
    else if(name != "admin" && pass == "1234"){
        cout<<"\t\t\t\t\t Wrong name!!\n";

        cout<<"\t\t\t\t\t Please log in again.\n";
        
    }
    else{
        cout<<"\t\t\t\t\t Login unsucess!!!!!\n";

    cout<<"\t\t\t\t\t Please try again.\n";
    }
   }while(name != "admin" || pass != "1234"); 
}

void adminMenu(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(h, 6);
 system("cls");
 cout<<"\n";
cout<<"\t\t\t\t\t   ||=========================================================||"<<endl;
cout<<"\t\t\t\t\t   ||               Welcome to Admin Menu                     ||"<<endl;
cout<<"\t\t\t\t\t   ||=========================================================||"<<endl; 
cout<<"\t\t\t\t\t   ||             1. List all student record                  ||"<<endl;   
cout<<"\t\t\t\t\t   ||             2. Search student record                    ||"<<endl;
cout<<"\t\t\t\t\t   ||             3. Input student score                      ||"<<endl;
cout<<"\t\t\t\t\t   ||             4. Update student score                     ||"<<endl;
cout<<"\t\t\t\t\t   ||             5. Delete student score                     ||"<<endl;
cout<<"\t\t\t\t\t   ||             0. Logout                                   ||"<<endl;
cout<<"\t\t\t\t\t   ||=========================================================||"<<endl;                                                               
cout<<"\n" ;
}

void adminOption(){
    int num;
    cout<<"\n";
        system("cls");
        adminLogin();
        adminMenu();
    cout<<"\t\t\t\t\t Please choose number: "; cin>>num;

}




