#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int importdata() {

    //data variable store the csv file
    vector<vector<string>> data;  // 2D vector to store CSV data

    ifstream file("data.csv");  // Replace "data.csv" with your CSV file name

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> row;  // Vector to store each row of data
            
            //ss - variable name
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
    // for (const auto &row : data) {
    //     for (const auto& value : row) {
    //         cout << value << "\t";
    //     }
    //     cout << endl;
    // }

    // Accessing values using indices
    // string value1 = data[1][0];  // Value at row 1, column 0
    // string value2 = data[2][3];  // Value at row 2, column 3

    // cout << "Value at row 1, column 0: " << value1 << endl;
    // cout << "Value at row 2, column 3: " << value2 << endl;

    // Displaying all values in row 1
    // cout << "Values in row 1:" << endl;
    // for (const auto& value : data[1]) {
    //     cout << value << "\t";
    // }
    // cout << endl;

    // Assuming you have read the CSV file and stored the data in the 'data' vector
    string targetName = "100323185";  // Specify the name you want to search for

    bool found = false;  // Flag to check if the name is found

    // Search for the target name and display the matching rows
    cout << "Rows containing the name '" << targetName << "':" << endl;
    for (const auto& row : data) {
        for (const auto& value : row) {
            if (value == targetName) {
                // The name is found in this row
                found = true;
                for (const auto& val : row) {
                    cout << val << "\t";
                }
                cout << endl;
                break;
            }
        }
    }

    if (!found) {
        cout << "No rows found with the name '" << targetName << "'." << endl;
    }


    return 0;
}
