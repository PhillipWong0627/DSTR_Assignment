#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip> 
#include <algorithm>

using namespace std;

// vector<vector<string>> importdata() {
//     //data variable stores the csv file
//     vector<vector<string>> data;  // 2D vector to store CSV data

//     ifstream file("data.csv");  // Replace "data.csv" with your CSV file name

//     if (file.is_open()) {
//         string line;
//         while (getline(file, line)) {

//             vector<string> row;  // Vector to store each row of data

//             istringstream ss(line);  // Use istringstream to split the line
//             string value;
//             while (getline(ss, value, ',')) {
//                 // If the value contains semicolons (due to previous replacements), convert them back to commas
//                 size_t pos;
//                 while ((pos = value.find(';')) != string::npos) {
//                     value.replace(pos, 1, ",");
//                 }
//                 if (value.empty()) { // Check if the value is empty
//                     value = "-"; // Replace empty value with hyphen
//                 }
//                 row.push_back(value);  // Add each value to the row vector
//             }

//             data.push_back(row);  // Add the row to the data vector
//         }

//         file.close();
//     } else {
//         cout << "Unable to open the file." << endl;
//         return data;  // Return empty data vector on error
//     }

//     return data;
// }

vector<vector<string>> importdata() {
    vector<vector<string>> data;  // 2D vector to store CSV data

    ifstream file("data.csv");  // Replace "data.csv" with your CSV file name

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> row;  // Vector to store each row of data

            istringstream ss(line);  // Use istringstream to split the line
            string value;
            while (getline(ss, value, ',')) {
                // If the value contains semicolons (due to previous replacements), convert them back to commas
                size_t pos;
                while ((pos = value.find(';')) != string::npos) {
                    value.replace(pos, 1, ",");
                }
                if (value.empty()) { // Check if the value is empty
                    value = "-"; // Replace empty value with hyphen
                }
                row.push_back(value);  // Add each value to the row vector
            }

            data.push_back(row);  // Add the row to the data vector
        }

        file.close();
    } else {
        cout << "Unable to open the file." << endl;
        return data;  // Return empty data vector on error
    }

    return data;
}
