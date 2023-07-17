#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int importdata() {
    vector<vector<string>> data;  // 2D vector to store CSV data

    ifstream file("data.csv");  // Replace "data.csv" with your CSV file name

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> row;  // Vector to store each row of data

            istringstream ss(line);  // Use istringstream to split the line
            string value;
            while (getline(ss, value, ',')) {
                row.push_back(value);  // Add each value to the row vector
            }

            data.push_back(row);  // Add the row to the data vector
        }

        file.close();
    } else {
        cout << "Unable to open the file." << endl;
        return 1;
    }

    // Print the data from the array
    for (const auto& row : data) {
        for (const auto& value : row) {
            cout << value << "\t";
        }
        cout << endl;
    }

    return 0;
}