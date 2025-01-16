#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <iomanip> // For std::setw
#include <windows.h>
#include <chrono>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

void desingStuRecord(const vector<string>& text, size_t numColumns) {
    size_t numRows = (text.size() + numColumns - 1) / numColumns; // Calculate rows needed

    for (size_t row = 0; row < numRows; ++row) {
        for (size_t col = 0; col < numColumns; ++col) {
            size_t index = row + col * numRows; // Index for current column
            if (index < text.size()) {
                cout << setw(60) << left << text[index]; // Print text with fixed width
                this_thread::sleep_for(chrono::milliseconds(50)); // Delay of 50ms
            } else {
                cout << setw(60) << left << ""; // Fill empty space if no text
            }
        }
        cout << endl; // Move to the next row
    }
}
vector<string> text = {
                        "\t\t\t\t   $$$$$$  $$$$$$$ $$  $$  $$$$$   $$$$$$  $$  $$  $$$$$$      $$$$$   $$$$$$  $$$$$   $$$$   $$$$$   $$$$$    ",
                        "\t\t\t\t $$          $$    $$  $$  $$  $$  $$      $$$ $$    $$        $$  $$  $$     $$  $$  $$  $$  $$  $$  $$   $$  ",
                        "\t\t\t\t  $$$$$$     $$    $$  $$  $$  $$  $$$$$   $$ $$$    $$        $$$$    $$$$$  $$      $$  $$  $$$$$   $$   $$  ",
                        "\t\t\t\t       $$    $$    $$  $$  $$  $$  $$      $$  $$    $$        $$  $$  $$     $$  $$  $$  $$  $$ $$   $$   $$  ",
                        "\t\t\t\t  $$$$$$     $$     $$$$   $$$$$   $$$$$$  $$  $$    $$        $$  $$  $$$$$$  $$$$$   $$$$   $$  $$  $$$$$    ",

    };
    size_t numColumns = 1; // Number of columns

void designAdminLogin(const vector<string>& text1, size_t numColumn) {
    size_t numRow = (text1.size() + numColumn - 1) / numColumn; // Calculate rows needed

    for (size_t row = 0; row < numRow; ++row) {
        for (size_t col = 0; col < numColumn; ++col) {
            size_t index = row + col * numRow; // Index for current column
            if (index < text1.size()) {
                cout << setw(60) << left << text1[index]; // Print text with fixed width
                this_thread::sleep_for(chrono::milliseconds(50)); // Delay of 2ms
            } else {
                cout << setw(60) << left << ""; // Fill empty space if no text
            }
        }
        cout << endl; // Move to the next row
    }
}
vector<string> text1 = {
              "\t\t\t\t  $$$$$$   $$$$$$$   $$       $$  $$$$$$  $$    $$        $$         $$$$$$    $$$$$$   $$$$$$  $$    $$   ",
              "\t\t\t\t $$    $$  $$    $$  $$$     $$$    $$    $$$   $$        $$        $$    $$  $$          $$    $$$   $$   ",
              "\t\t\t\t $$$$$$$$  $$    $$  $$ $$ $$ $$    $$    $$ $$ $$        $$        $$    $$  $$  $$$     $$    $$ $$ $$   ",
              "\t\t\t\t $$    $$  $$  _ $$  $$  $$$  $$    $$    $$  $$$$        $$        $$    $$  $$   $$     $$    $$   $$$   ",
              "\t\t\t\t $$    $$  $$$$$$$   $$       $$  $$$$$$  $$    $$        $$$$$$$$   $$$$$$    $$$$$$   $$$$$$  $$    $$   ",
    };
    size_t numColumn = 1; // Number of columns

void designstudentLogin(const vector<string>& text2, size_t numCol) {
    size_t numRow = (text2.size() + numCol - 1) / numCol; // Calculate rows needed

    for (size_t row = 0; row < numRow; ++row) {
        for (size_t col = 0; col < numCol; ++col) {
            size_t index = row + col * numRow; // Index for current column
            if (index < text2.size()) {
                cout << setw(60) << left << text2[index]; // Print text with fixed width
                this_thread::sleep_for(chrono::milliseconds(50)); // Delay of 2ms
            } else {
                cout << setw(60) << left << ""; // Fill empty space if no text
            }
        }
        cout << endl; // Move to the next row
    }
}
vector<string> text2 = {
    "\t\t\t\t   $$$$$$  $$$$$$$ $$  $$  $$$$$   $$$$$$  $$  $$  $$$$$$     $$         $$$$$$    $$$$$$   $$$$$$  $$    $$   ", 
    "\t\t\t\t $$          $$    $$  $$  $$  $$  $$      $$$ $$    $$       $$        $$    $$  $$          $$    $$$   $$   ",
    "\t\t\t\t  $$$$$$     $$    $$  $$  $$  $$  $$$$$   $$ $$$    $$       $$        $$    $$  $$  $$$     $$    $$ $$ $$   ",
    "\t\t\t\t       $$    $$    $$  $$  $$  $$  $$      $$  $$    $$       $$        $$    $$  $$   $$     $$    $$   $$$   ",
    "\t\t\t\t  $$$$$$     $$     $$$$   $$$$$   $$$$$$  $$  $$    $$       $$$$$$$$   $$$$$$    $$$$$$   $$$$$$  $$    $$   ",
    };
    size_t numCol= 1; // Number of columns

//It loading when login sucess
void loadingAdmin(int totalSteps) {
    int barWidth = 50; // Width of the progress bar
    int this_thread;
std::cout<<"\n";
    for (int step = 0; step <= totalSteps; ++step) {
        // Calculate percentage
        float progress = static_cast<float>(step) / totalSteps;
       
        // Print the progress bar
        std::cout << "\t\t\t\t Loading[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) {
                std::cout << "=";
            } else if (i == pos) {
                std::cout << ">";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "] " << int(progress * 100.0) << " %\r";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
        // Simulate some work with a delay

    std::cout << std::endl; // Move to the next line after progress is complete
} 

void welcomeStudentTable(){
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


void studentTable(){
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(h, 6);
 system("cls");
     designstudentLogin( text2,numCol);
cout<<"\n";
cout<<"\t\t\t\t\t  ||=========================================================||"<<endl;
cout<<"\t\t\t\t\t  ||               Welcome to Student option                 ||"<<endl;
cout<<"\t\t\t\t\t  ||=========================================================||"<<endl;
cout<<"\t\t\t\t\t  ||             1.Register                                  ||"<<endl;
cout<<"\t\t\t\t\t  ||             2.login                                     ||"<<endl;
cout<<"\t\t\t\t\t  ||             3.Logout                                    ||"<<endl;
cout<<"\t\t\t\t\t  ||=========================================================||"<<endl;

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

// void adminLogout(){
//     cout<<"\t\t\t\t\t User is already logout....."<<endl;
//     cout<<"\n";
//     cout << "\t\t\t\t\t Press enter to contine......";
//     cin.ignore();
//     cin.get();
//     adminTable();
// }

void adminOption(){
    int num;
    cout<<"\n";
        system("cls");
        adminLogin();
        adminMenu();
    cout<<"\t\t\t\t\t Please choose number: "; cin>>num;

}

void studentOption(){
    int op;



}


void studentSystem(){
    int number;
       welcomeStudentTable(); //student record
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
    studentTable();

    
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


int main(){
    
  studentSystem();

  return 0;
}
  





    
  
        

            

