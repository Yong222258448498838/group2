#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <iomanip> // For std::setw
using namespace std;
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