#include<iostream>
#include<vector>
#include <iomanip> // For std::setw
using namespace std;


void printTable(const vector<vector<string>>& data, const vector<string>& columnNames) {
    const int colWidth = 15; // Adjust column width as needed

    // Print top border
    cout << "+";
    for (size_t i = 0; i < columnNames.size(); ++i) cout << string(colWidth, '-') << "+";
    cout << endl;
    
    // Print headers
    cout << "|";
    for (const string& header : columnNames) {
        cout << setw(colWidth) << left << header << "|";
    }
    cout << endl;

    // Print header-bottom border
    cout << "+";
    for (size_t i = 0; i < columnNames.size(); ++i) cout << string(colWidth, '-') << "+";
    cout << endl;

    // Print rows
    for (const auto& row : data) {
        cout << "|";
        for (const string& cell : row) {
            cout << setw(colWidth) << left << cell << "|";
        }
        cout << endl;

        // Print row border
        cout << "+";
        for (size_t i = 0; i < columnNames.size(); ++i) cout << string(colWidth, '-') << "+";
        cout << endl;
    }
}
