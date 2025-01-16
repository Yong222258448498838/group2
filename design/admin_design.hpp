#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <iomanip> // For std::setw
using namespace std;
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