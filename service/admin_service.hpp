#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <stdexcept>
#include<random>
#include"../view/table.hpp"
using namespace std;



// Function to read existing IDs from the input data file
unordered_set<int> readExistingIDs(const string& filename) {
    unordered_set<int> existingIDs;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        try {
            int id = stoi(token);
            existingIDs.insert(id);
        } catch (const invalid_argument&) {
            // Ignore invalid lines
        }
    }
    return existingIDs;
}

// Function to generate a unique random ID
int generateRandomID(const unordered_set<int>& existingIDs) {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dist(1000, 9999); // IDs between 1000 and 9999

    int newID;
    do {
        newID = dist(gen);
    } while (existingIDs.find(newID) != existingIDs.end());
    return newID;
}

class DepartmentOfComputer {
private:
    int id;
    string departmentName;
    string classs;
    string studentName;
    double scoreCpp;
    double scoreMath;
    double scorePhyton;

public:
    
    DepartmentOfComputer() : id(0), departmentName(""), classs(""), studentName(""), scoreCpp(0), scoreMath(0), scorePhyton(0) {}

    DepartmentOfComputer(const unordered_set<int>& existingIDs)
        : id(generateRandomID(existingIDs)), departmentName(""), classs(""), studentName(""), scoreCpp(0), scoreMath(0), scorePhyton(0) {}

    DepartmentOfComputer(const string& departmentName, const string& classs, const string& studentName, double scoreCpp, double scoreMath, double scorePhyton, const unordered_set<int>& existingIDs)
        : id(generateRandomID(existingIDs)), departmentName(departmentName), classs(classs), studentName(studentName), scoreCpp(scoreCpp), scoreMath(scoreMath), scorePhyton(scorePhyton) {}

    int getid() const { return id; }
    string getdepartmentName() const { return departmentName; }
    string getclasss() const { return classs; }
    string getstudentName() const { return studentName; }
    double getscoreCpp() const { return scoreCpp; }
    double getscoreMath() const { return scoreMath; }
    double getscorePhyton() const { return scorePhyton; }

    void setDepartmentName(const string& newDepartmentName) { departmentName = newDepartmentName; }
    void setClasss(const string& newClasss) { classs = newClasss; }
    void setStudentName(const string& newStudentName) { studentName = newStudentName; }
    void setCpp(double newCpp) { scoreCpp = newCpp; }
    void setMath(double newMath) { scoreMath = newMath; }
    void setPhyton(double newPhyton) { scorePhyton = newPhyton; }

    double totalScore() const { return scoreCpp + scoreMath + scorePhyton; }
    double average() const { return totalScore() / 3; }
    string levels() const {
        double avg = average();
        if (avg >= 90) return "A";
        if (avg >= 80) return "B";
        if (avg >= 70) return "C";
        if (avg >= 60) return "D";
        if (avg >= 50) return "E";
        return "F";
    }

    friend ostream& operator<<(ostream& os, const DepartmentOfComputer& doc) {
        os << doc.id << "," << doc.departmentName << "," << doc.classs << "," << doc.studentName << ","
           << doc.scoreCpp << "," << doc.scoreMath << "," << doc.scorePhyton << ","
           << doc.totalScore() << "," << doc.average() << "," << doc.levels();
        return os;
    }

    friend istream& operator>>(istream& is, DepartmentOfComputer& doc) {
        string line, token;
        if (getline(is, line)) {
            stringstream ss(line);
            try {
                getline(ss, token, ',');
                doc.id = stoi(token);
                getline(ss, doc.departmentName, ',');
                getline(ss, doc.classs, ',');
                getline(ss, doc.studentName, ',');
                getline(ss, token, ','); doc.scoreCpp = stod(token);
                getline(ss, token, ','); doc.scoreMath = stod(token);
                getline(ss, token, ','); doc.scorePhyton = stod(token);
            } catch (const exception&) {
                // Handle invalid data lines
            }
        }
        return is;
    }
};


void writeToFile(const vector<DepartmentOfComputer>& docs) {
    ofstream outFile("DepartmentData.txt");
    if (outFile.is_open()) {
        for (const auto& doc : docs) {
            outFile << doc << "\n";
        }
    } else {
        cerr << "\t\t\t\t\t Error opening file for writing.\n";
    }
}

vector<DepartmentOfComputer> readFromFile() {
    vector<DepartmentOfComputer> docs;
    ifstream inFile("DepartmentData.txt");
    if (inFile.is_open()) {
        DepartmentOfComputer doc;
        while (inFile >> doc) {
            docs.push_back(doc);
        }
    } else {
        cerr << "\t\t\t\t\t Error opening file for reading.\n";
    }
    return docs;
}

void addDepartmentOfComputer() {
    char option;
    do{
        auto existingIDs = readExistingIDs("DepartmentData.txt");
    DepartmentOfComputer departmentOfComputer(existingIDs);
    
    double scoreCpp,scoreMath,scorePhyton;
    string studentName, classs,departmentName;
    cout << "\t\t\t\t\t Enter Department Name: ";
    cin.ignore();
    getline(cin, departmentName);
    cout << "\t\t\t\t\t Enter Class Name: ";
    getline(cin, classs);
    cout << "\t\t\t\t\t Enter Student Name: ";
    getline(cin, studentName);
    cout << "\t\t\t\t\t Enter C++ Score: ";
    cin >> scoreCpp;
    cout << "\t\t\t\t\t Enter Math Score: ";
    cin>>scoreMath;
    cout << "\t\t\t\t\t Enter Python Score: ";
    cin>>scorePhyton;
     
    departmentOfComputer.setDepartmentName(departmentName);
    departmentOfComputer.setClasss(classs);
    departmentOfComputer.setStudentName(studentName);
    departmentOfComputer.setCpp(scoreCpp);
    departmentOfComputer.setMath(scoreMath);
    departmentOfComputer.setPhyton(scorePhyton);
    

    auto departmentOfComputers = readFromFile();
    departmentOfComputers.push_back(departmentOfComputer);
    writeToFile(departmentOfComputers);
    cout << "\t\t\t\t\t DepartmentOfComputer added successfully.\n";
    cout<<"\t\t\t\t\t----------------------------------------------------\n";
    cout << "\t\t\t\t\t Do you want to add more Student?(Y/N): ";
                cin >> option;
            }while((option == 'Y' || option == 'y' ));
    
    
}

void displayAllDepartmentOfComputers() {
	
    auto DepartmentOfComputers = readFromFile();
    if (DepartmentOfComputers.empty()) {
        cout << "\t\t\t\t\t No DepartmentOfComputers found.\n";
        return;
    }

    vector<vector<string>> data;
   
    for (const auto& DepartmentOfComputer : DepartmentOfComputers) {
      
        data.push_back({to_string(DepartmentOfComputer.getid()), DepartmentOfComputer.getdepartmentName(), DepartmentOfComputer.getclasss(), DepartmentOfComputer.getstudentName(), to_string(DepartmentOfComputer.getscoreCpp()), to_string(DepartmentOfComputer.getscoreMath()), to_string(DepartmentOfComputer.getscorePhyton()), to_string(DepartmentOfComputer.totalScore()), to_string(DepartmentOfComputer.average()), DepartmentOfComputer.levels()});
} 
vector<string>columnNames ={ "ID","Department Name","Class","Student Name","ScoreC++", "ScoreMath","ScorePython","Total Score", "Average","Levels"};
printTable(data, columnNames);
}

void searchDepartmentOfComputerByID() {
    int id;
    char option;
    do{
    cout << "\t\t\t\t\t Enter Student ID to search: ";
    cin >> id;
    vector<vector<string>> data;
    auto DepartmentOfComputers = readFromFile();
    for (const auto& DepartmentOfComputer : DepartmentOfComputers) {
        if (DepartmentOfComputer.getid() == id) {
            data.push_back({to_string(DepartmentOfComputer.getid()), DepartmentOfComputer.getdepartmentName(), DepartmentOfComputer.getclasss(), DepartmentOfComputer.getstudentName(), to_string(DepartmentOfComputer.getscoreCpp()), to_string(DepartmentOfComputer.getscoreMath()), to_string(DepartmentOfComputer.getscorePhyton()), to_string(DepartmentOfComputer.totalScore()), to_string(DepartmentOfComputer.average()), DepartmentOfComputer.levels()});
        }
    }
    vector<string> columnNames = { "ID", "Department Name", "Class", "Student Name", "ScoreC++", "ScoreMath", "ScorePython", "Total Score", "Average", "Levels" };
    printTable(data, columnNames);
    if (data.empty()) {
        cout << "\t\t\t\t\t Student ID: " << id << " not found.\n";
    }
    cout << "\t\t\t\t\t Do you want to search more student ?(Y/N): ";
                cin >> option;
    }while((option == 'Y' || option == 'y' ));
    
}

void deleteDepartmentOfComputerByID() {
    int id;
    char option;
    do{
        cout << "\t\t\t\t\t Enter student ID to delete: ";
    cin >> id;
    auto DepartmentOfComputers = readFromFile();
    auto it = remove_if(DepartmentOfComputers.begin(), DepartmentOfComputers.end(), [id](const DepartmentOfComputer& s) { return s.getid() == id; });
    if (it != DepartmentOfComputers.end()) {
        DepartmentOfComputers.erase(it, DepartmentOfComputers.end());
        writeToFile(DepartmentOfComputers);
        cout << "\t\t\t\t\t Student ID: " << id << "\t deleted successfully.\n";
    } else {
        cout << "\t\t\t\t\t Student ID: " << id << " \t not found.\n";
    }
    cout<<"\t\t\t\t\t ----------------------------------------------------\n";
    cout << "\t\t\t\t\t Do you want to delete more student?(Y/N): ";
                cin >> option;
    }while((option == 'Y' || option == 'y' ));
}

void updateDepartmentOfComputerByID() {
    DepartmentOfComputer departmentOfComputer;
    int id;
    double scoreCpp;
    double scoreMath;
    double scorePhyton;
    string studentName;
    string departmentName;
    string classs;
    char option;
   
do{
    cout<<"\n";
    int num;
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
cout<<"\t\t\t\t\t  ||           1. Update student score                     ||"<<endl;
cout<<"\t\t\t\t\t  ||           2. Update student record                    ||"<<endl;
cout<<"\t\t\t\t\t  ||=======================================================||"<<endl;
cout<<"\t\t\t\t\t Choose number for update: ";cin>>num;
 
    cout << "\t\t\t\t\t Enter Student ID to update: ";
cin >> id;
if(num==1){
    auto departmentOfComputers = readFromFile();
auto it = find_if(departmentOfComputers.begin(), departmentOfComputers.end(), [id](const DepartmentOfComputer& s) { return s.getid() == id; });
if (it != departmentOfComputers.end()) {
    DepartmentOfComputer& departmentOfComputer = *it;
    cout << "\t\t\t\t\t Updating information for Student: " << id << endl;
    cin.ignore();
    cout << "\t\t\t\t\t Enter score C++: ";
    cin >> scoreCpp;
    cout << "\t\t\t\t\t Enter Score Math: ";
    cin >> scoreMath;
    cout << "\t\t\t\t\t Enter Score Phyton: ";
    cin >> scorePhyton;
    departmentOfComputer.setCpp(scoreCpp);
    departmentOfComputer.setMath(scoreMath);
    departmentOfComputer.setPhyton(scorePhyton);

    writeToFile(departmentOfComputers);
    cout << "\t\t\t\t\t student updated successfully.\n";
    return;
}
}
else if(num==2){
auto departmentOfComputers = readFromFile();
auto it = find_if(departmentOfComputers.begin(), departmentOfComputers.end(), [id](const DepartmentOfComputer& s) { return s.getid() == id; });
if (it != departmentOfComputers.end()) {
    DepartmentOfComputer& departmentOfComputer = *it;
    cout << "\t\t\t\t\t Updating information for Student: " << id << endl;
    cin.ignore();

    cout << "\t\t\t\t\t Inter Department Name: ";
    cin.ignore();
    getline(cin, departmentName);
    cout << "\t\t\t\t\t Enter Class Name: ";
    getline(cin, classs);
    cout << "\t\t\t\t\t Enter Name Student: ";
    getline(cin, studentName);
    cout << "\t\t\t\t\t Enter score C++: ";
    cin >> scoreCpp;
    cout << "\t\t\t\t\t Enter Score Math: ";
    cin >> scoreMath;
    cout << "\t\t\t\t\t Enter Score Phyton: ";
    cin >> scorePhyton;

    departmentOfComputer.setDepartmentName(departmentName);
    departmentOfComputer.setClasss(classs);
    departmentOfComputer.setStudentName(studentName);
    departmentOfComputer.setCpp(scoreCpp);
    departmentOfComputer.setMath(scoreMath);
    departmentOfComputer.setPhyton(scorePhyton);

    writeToFile(departmentOfComputers);
    cout << "\t\t\t\t\t student updated successfully.\n";
    return;
}
}

cout << "\t\t\t\t\t Student ID: " << id << " not found.\n";
cout<<"\t\t\t\t\t ----------------------------------------------------\n";
cout << "\t\t\t\t\t Do you want to update more student?(Y/N): ";
                cin >> option;
    }while((option == 'Y' || option == 'y' ));

}


