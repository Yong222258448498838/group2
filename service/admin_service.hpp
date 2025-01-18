#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include"../view/table.hpp"
using namespace std;

class DepartmentOfComputer {
private:
    static int idCounter;
    int id;
    string departmentName;
    string classs;
    string studentName;
    double scoreCpp;
    double scoreMath;
    double scorePhyton;

public:
    DepartmentOfComputer() : id(0), departmentName(""), classs(""), studentName(""), scoreCpp(0), scoreMath(0), scorePhyton(0) {
        id = idCounter++;
    }

    DepartmentOfComputer(const string& departmentName, const string& classs, const string& studentName, double scoreCpp, double scoreMath, double scorePhyton)
        : id(idCounter++), departmentName(departmentName), classs(classs), studentName(studentName), scoreCpp(scoreCpp), scoreMath(scoreMath), scorePhyton(scorePhyton) {}

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

    double totalScore() const {
        return scoreCpp + scoreMath + scorePhyton;
    }

    double average() const {
        return totalScore() / 3;
    }

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
           << doc.scoreCpp << "," << doc.scoreMath << "," << doc.scorePhyton << "," << doc.totalScore() << ","
           << doc.average() << "," << doc.levels();
        return os;
    }

    friend istream& operator>>(istream& is, DepartmentOfComputer& doc) {
        string line, token;
        if (getline(is, line)) {
            stringstream ss(line);
            getline(ss, token, ','); doc.id = stoi(token);
            getline(ss, doc.departmentName, ',');
            getline(ss, doc.classs, ',');
            getline(ss, doc.studentName, ',');
            getline(ss, token, ','); doc.scoreCpp = stod(token);
            getline(ss, token, ','); doc.scoreMath = stod(token);
            getline(ss, token, ','); doc.scorePhyton = stod(token);
        }
        return is;
    }
};

int DepartmentOfComputer::idCounter = 1;

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
    DepartmentOfComputer departmentOfComputer;
    
    double scoreCpp,scoreMath,scorePhyton,scoreWriting,scoreEnglish;
    string studentName, classs,departmentName;
    cout << "\t\t\t\t\t Inter Department Name: ";
    cin.ignore();
    getline(cin, departmentName);
    cout << "\t\t\t\t\t Enter Class Name: ";
    getline(cin, classs);
    cout << "\t\t\t\t\t Enter Name Student: ";
    getline(cin, studentName);
    cout << "\t\t\t\t\t Enter score Cpp: ";
    cin >> scoreCpp;
    cout << "\t\t\t\t\t Enter Score Math: ";
   cin>>scoreMath;
    cout << "\t\t\t\t\t Enter Score Phyton: ";
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
vector<string>columnNames ={ "ID","Department Name","Class","Student Name","ScoreCpp", "ScoreMath","ScorePhyton","Total Score", "Average","Levels"};
printTable(data, columnNames);
}


void searchDepartmentOfComputerByID() {
    int id;
    cout << "\t\t\t\t\t Enter Student ID to search: ";
    cin >> id;
vector<vector<string>> data;
    auto DepartmentOfComputers = readFromFile();
    for (const auto& DepartmentOfComputer : DepartmentOfComputers) {
        if (DepartmentOfComputer.getid() == id) {
            data.push_back({to_string(DepartmentOfComputer.getid()), DepartmentOfComputer.getdepartmentName(), DepartmentOfComputer.getclasss(), DepartmentOfComputer.getstudentName(), to_string(DepartmentOfComputer.getscoreCpp()), to_string(DepartmentOfComputer.getscoreMath()), to_string(DepartmentOfComputer.getscorePhyton()), to_string(DepartmentOfComputer.totalScore()), to_string(DepartmentOfComputer.average()), DepartmentOfComputer.levels()});
} 
vector<string>columnNames ={ "ID","Department Name","Class","Student Name","ScoreCpp", "ScoreMath","ScorePhyton","Total Score", "Average","Levels"};
printTable(data, columnNames);
             return;
        }
    
    cout << "\t\t\t\t\t studenrt ID :" << id << " not found.\n";
}

void searchDepartmentOfComputerByName() {
    string studentName;
    cout << "\t\t\t\t\t Enter Full Name to search: ";
    cin.ignore();getline(cin,studentName);
vector<vector<string>> data;
    auto DepartmentOfComputers = readFromFile();
    for (const auto& DepartmentOfComputer : DepartmentOfComputers) {
        if (DepartmentOfComputer.getstudentName() == studentName) {
            data.push_back({to_string(DepartmentOfComputer.getid()), DepartmentOfComputer.getdepartmentName(), DepartmentOfComputer.getclasss(), DepartmentOfComputer.getstudentName(), to_string(DepartmentOfComputer.getscoreCpp()), to_string(DepartmentOfComputer.getscoreMath()), to_string(DepartmentOfComputer.getscorePhyton()), to_string(DepartmentOfComputer.totalScore()), to_string(DepartmentOfComputer.average()), DepartmentOfComputer.levels()});
} 
vector<string>columnNames ={ "ID","Department Name","Class","Student Name","ScoreCpp", "ScoreMath","ScorePhyton","Total Score", "Average","Levels"};
printTable(data, columnNames);
             return;
        }
    
    cout << "\t\t\t\t\t Stundet Name: " << studentName << " not found.\n";
}


void deleteDepartmentOfComputerByID() {
    int id;
    cout << "\t\t\t\t\t Enter stduent ID to delete: ";
    cin >> id;
    auto DepartmentOfComputers = readFromFile();
    auto it = remove_if(DepartmentOfComputers.begin(), DepartmentOfComputers.end(), [id](const DepartmentOfComputer& s) { return s.getid() == id; });
    if (it != DepartmentOfComputers.end()) {
        DepartmentOfComputers.erase(it, DepartmentOfComputers.end());
        writeToFile(DepartmentOfComputers);
        cout << "\t\t\t\t\t Studnet ID: " << id << "deleted successfully.\n";
    } else {
        cout << "\t\t\t\t\t Student ID: " << id << " not found.\n";
    }
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
   
cout << "\t\t\t\t\t Enter Student ID to update: ";
cin >> id;

auto departmentOfComputers = readFromFile();
auto it = find_if(departmentOfComputers.begin(), departmentOfComputers.end(), [id](const DepartmentOfComputer& s) { return s.getid() == id; });
if (it != departmentOfComputers.end()) {
    DepartmentOfComputer& departmentOfComputer = *it;

    cout << "\t\t\t\t\t Inter Department Name: ";
    cin.ignore();
    getline(cin, departmentName);
    cout << "\t\t\t\t\t Enter Class Name: ";
    getline(cin, classs);
    cout << "\t\t\t\t\t Enter Name Student: ";
    getline(cin, studentName);
    cout << "\t\t\t\t\t Enter score Cpp: ";
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

cout << "\t\t\t\t\t Student ID: " << id << " not found.\n";

}