#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<vector<string> > importdata()
{
    // data variable stores the csv file
    vector<vector<string> > data; // 2D vector to store CSV data

    cout << "importing data" << endl;

    ifstream file("data.csv"); // Replace "data.csv" with your CSV file name

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {

            vector<string> row; // Vector to store each row of data

            istringstream ss(line); // Use istringstream to split the line

            string value;
            while (getline(ss, value, ','))
            {
                // If the value contains semicolons (due to previous replacements), convert them back to commas
                size_t pos;
                while ((pos = value.find(';')) != string::npos)
                {
                    value.replace(pos, 1, ",");
                }
                if (value.empty())
                {                // Check if the value is empty
                    value = "-"; // Replace empty value with hyphen
                }
                row.push_back(value); // Add each value to the row vector
            }

            data.push_back(row); // Add the row to the data vector
        }

        file.close();
    }
    else
    {
        cout << "Unable to open the file." << endl;
        return data; // Return empty data vector on error
    }

    return data;
}

int stringToInteger(const string &str)
{
    int num = 0;
    for (char ch : str)
    {
        if (isdigit(ch))
        {
            num = num * 10 + (ch - '0');
        }
    }
    return num;
}

void BubbleSortRentalFee(vector<vector<string> >& data) {
    for (size_t i = 0; i < data.size(); i++) {
        for (size_t j = 0; j < data.size() - 1 - i; j++) {
            // Extract numbers from the strings and convert them to integers
            int num1 = stringToInteger(data[j][3]);
            int num2 = stringToInteger(data[j + 1][3]);

            if (num1 < num2) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

// void BubbleSortRentalFee(vector<vector<string> > &data, int startIndex, int endIndex)
// {
//     for (size_t j = 0; j < endIndex - 1 - startIndex; j++)
//     {
//         // Extract numbers from the strings and convert them to integers
//         int num1 = stringToInteger(data[j][3]);
//         int num2 = stringToInteger(data[j + 1][3]);

//         if (num1 > num2)
//         {
//             swap(data[j], data[j + 1]);
//         }
//     }

//     // size_t n = min(data.size(), static_cast<size_t>(100));

//     // for (size_t i = 0; i < n; i++) {
//     //     for (size_t j = 0; j < n - 1 - i; j++) {
//     //         // Extract numbers from the strings and convert them to integers
//     //         int num1 = stringToInteger(data[j][3]);
//     //         int num2 = stringToInteger(data[j + 1][3]);

//     //         if (num1 > num2) {
//     //             swap(data[j], data[j + 1]);
//     //         }
//     //     }
//     // }

//     // cout << "After sort:" << endl;
//     // for (size_t i = 0; i < startIndex; i++) {
//     //     // Print the entire row of the data vector
//     //     for (const auto& value : data[i]) {
//     //         cout << value << " ";
//     //     
//     //     cout << endl;
//     // }

//     // cout << "After sort:" << endl;
//     // for (size_t i = 0; i < startIndex; i++) {
//     //     cout << data[i][3] << endl;
//     // }
// }

void displayInPages(vector<vector<string> > &data, int numEntriesPerPage)
{
    // int numEntriesPerPage = 30;
    int currentPage = 1;
    int count = 0;

    // Calculate the number of pages
    int totalPages = (data.size() + numEntriesPerPage - 1) / numEntriesPerPage;


    // Display the stored matching rows in a table
    while (currentPage <= totalPages)
    {
        // Calculate the start and end indices for the current page
        int startIndex = (currentPage - 1) * numEntriesPerPage;
        int endIndex = min(startIndex + numEntriesPerPage, static_cast<int>(data.size()));

        // for (size_t i = 0; i < endIndex; i++)
        // {
        //     // Bubble Sort the rental fee here
        //     BubbleSortRentalFee(data, i, endIndex);
        // }

        // Sort the current 30 data entries based on the rental fee
        vector<vector<string> > currentData(data.begin() + startIndex, data.begin() + endIndex);
        BubbleSortRentalFee(currentData);

        // Display the sorted data for the current page
        for (size_t i = 0; i < currentData.size(); ++i) {
            // Loop through the columns of the current row
            for (const auto& value : currentData[i]) {
                cout << value << " ";
            }
            cout << endl;

            // Print the line of dashes after each row
            cout << '\n' << string(30, '-') << endl;
            count++;
        }

        // Ask the user if they want to see more entries
        cout << "Current Displayed Data = " << count << endl;
        char choice;
        cout << "Show more entries? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N')
        {
            break; // Exit the loop if the user doesn't want to see more entries
        }
        else if (choice == 'y' || choice == 'Y')
        {
            currentPage++; // Move to the next page
        }
        else
        {
            cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
        }
    }
}

int main()
{
    vector<vector<string> > data = importdata();

    displayInPages(data, 30);

    return 0;
}
