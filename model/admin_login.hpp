#include<iostream>
#include <iomanip> // For std::setw
#include <windows.h>
#include <chrono>
#include <conio.h>
#include <thread>
#include"../design/admin_design.hpp"
#include"../service/admin_service.hpp"
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
 cout<<"\n";
cout<<"\t\t\t\t\t   ||=========================================================||"<<endl;
cout<<"\t\t\t\t\t   ||               Welcome to Admin Menu                     ||"<<endl;
cout<<"\t\t\t\t\t   ||=========================================================||"<<endl; 
cout<<"\t\t\t\t\t   ||             1. Input student score                      ||"<<endl;
cout<<"\t\t\t\t\t   ||             2. List all student record                  ||"<<endl;   
cout<<"\t\t\t\t\t   ||             3. Search student record                    ||"<<endl;
cout<<"\t\t\t\t\t   ||             4. Update student score                     ||"<<endl;
cout<<"\t\t\t\t\t   ||             5. Delete student score                     ||"<<endl;
cout<<"\t\t\t\t\t   ||             0. Logout                                   ||"<<endl;
cout<<"\t\t\t\t\t   ||=========================================================||"<<endl;                                                               
cout<<"\n" ;
  
}

void adminOption(){
    int choice;
     system("cls");
    do {
         adminMenu();
        cout << "\t\t\t\t\t Enter your choice: ";
        cin >> choice;
        
        switch (choice) {

    case 1:{
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
cout<<"\t\t\t\t\t  ||                  Input student score                  ||"<<endl;
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
    addDepartmentOfComputer();
    break;
   
}
    case 2:{
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
cout<<"\t\t\t\t\t  ||                List all the student score             ||"<<endl;
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
    displayAllDepartmentOfComputers();
    break;
  
}
    case 3:{
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
cout<<"\t\t\t\t\t  ||                Search all the student score           ||"<<endl;
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
    searchDepartmentOfComputerByID();
    break;
   
}
    case 4:{
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
cout<<"\t\t\t\t\t  ||                Update all the student score           ||"<<endl;
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
    updateDepartmentOfComputerByID();
     break;
   
}
    case 5:{
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
cout<<"\t\t\t\t\t  ||                delete all the student score           ||"<<endl;
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
    deleteDepartmentOfComputerByID(); 
    break;
   
}
    case 0: {
cout<<"\t\t\t\t\t User is already logout....."<<endl;
cout<<"\n";
cout << "\t\t\t\t\t Press enter to contine......";
cin.ignore();
cin.get();
    break;
   
}
default: cout << "Invalid choice. Try again.\n";
           
    }
        
} while (choice != 0);


}




