#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <iomanip> // For std::setw
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