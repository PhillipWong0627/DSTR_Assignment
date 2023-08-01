#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono> // Include the chrono library

using namespace std;

// Function to import data from CSV file
vector<vector<string> > importdata() {
    vector<vector<string> > data;

    ifstream file("data.csv"); // Replace "data.csv" with your CSV file name

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> row;
            istringstream ss(line);
            string value;
            while (getline(ss, value, ',')) {
                size_t pos;
                while ((pos = value.find(';')) != string::npos) {
                    value.replace(pos, 1, ",");
                }
                if (value.empty()) {
                    value = "-";
                }
                row.push_back(value);
            }
            data.push_back(row);
        }
        file.close();
    } else {
        cout << "Unable to open the file." << endl;
    }

    return data;
}

// convert the string to the integer type
int stringToInteger(const string &str) {
    int num = 0;
    for (char ch : str) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0'); // to get the integer value of that digit
        }
    }
    return num;
}

void BubbleSortPropertyId(vector<vector<string> >& data, chrono::high_resolution_clock::time_point& start_time, chrono::high_resolution_clock::time_point& end_time) {
    // Record the start time before the sorting begins
    start_time = chrono::high_resolution_clock::now();

    for (size_t i = 0; i < data.size(); i++) {
        for (size_t j = 0; j < data.size() - 1 - i; j++) {

            // Extract numbers from the strings and convert them to integers
            int num1 = stringToInteger(data[j][0]);
            int num2 = stringToInteger(data[j + 1][0]);

            // cout << "num1 = " << num1 << endl;
            // cout << "num2 = " << num2 << endl;

            // swap the entire row of data
            if (num1 > num2) {
                swap(data[j], data[j + 1]);
            }
        }
    }

    // Record the end time after the sorting is done
    end_time = chrono::high_resolution_clock::now();
}

// void binarySearchAllRentalFee(vector<vector<string> > &data, int targetFee)
// {
//     vector<vector<string> > resultFound;
//     int low, high;
//     low = 0;
//     high = data.size() - 1;

//     while(low <= high)
//     {
//         int mid = (low + high) / 2;

//          // Extract the rental fee from the string and convert it to an integer
//         int midFee = stringToInteger(data[mid][3]); 

//         if(midFee == targetFee)
//         {
//             resultFound.push_back()
//         }

//     }
// }

int binarySearchFirst(const vector<vector<string> >& data, int propertyId, chrono::high_resolution_clock::time_point& start_time, chrono::high_resolution_clock::time_point& end_time) {

    // Record the start time before the sorting begins
    start_time = chrono::high_resolution_clock::now();
    
    int result = -1;

    int low, high;
    low = 0;
    high = data.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        // Extract the rental fee from the string and convert it to an integer
        int midPropertyId = stringToInteger(data[mid][0]); // Assuming the rental fee is in the 4th element (index 3)
        cout <<  "midPropertyId = " << midPropertyId << endl;
        if (midPropertyId == propertyId) {
            // Found a matching rental fee, store the index and continue searching on the low side
            result = mid;
            high = mid - 1;
        } else if (midPropertyId < propertyId) {
            low = mid + 1; // Target fee is in the high half of the current range
        } else {
            high = mid - 1; // Target fee is in the left half of the current range
        }
    }

    // Record the end time after the binary search is done
    end_time = chrono::high_resolution_clock::now();

    return result;

}


void displaySortedPropertyIdInPages(vector<vector<string> > &data, int numEntriesPerPage)
{
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

        // Sort the current 30 data entries based on the rental fee
        vector<vector<string> > currentData(data.begin() + startIndex, data.begin() + endIndex);
        chrono::high_resolution_clock::time_point sort_start, sort_end;
        BubbleSortPropertyId(currentData, sort_start, sort_end);

       // Calculate the duration of sorting in seconds
        auto sort_duration = chrono::duration<double>(sort_end - sort_start).count();

        


        // Display the sorted data for the current page
        for (size_t i = 1; i < currentData.size(); ++i) {
            // Loop through the columns of the current row
            for (const auto& value : currentData[i]) {
                cout << value << " ";
            }
            cout << endl;

            // Print the line of dashes after each row
            cout << '\n' << string(30, '-') << endl;
            count++;
        }

        // Display the duration of sorting
        cout << "Sorting time using bubble sort : " << sort_duration << " seconds" << endl;

        // Ask the user to enter a rental fee to search for
        int propertyId;
        cout << "Enter the property id to search for: ";
        cin >> propertyId;

        chrono::high_resolution_clock::time_point search_start, search_end;

        // Perform binary search to find the first occurrence
        int result = binarySearchFirst(currentData, propertyId, search_start, search_end);

        // Display the search result
        if (result != -1) {
            cout << "Property ID " << propertyId << " found at index: " << result << endl;
            // Display the details for the matching row
            for (const auto& value : data[result]) {
                cout << value << " ";
            }
            cout << endl;
        } else {
            cout << "Property ID " << propertyId << " not found in this page." << endl;
        }

        // Calculate the duration of binary search in seconds
        auto search_duration = chrono::duration<double>(search_end - search_start).count();

        // Display the duration of binary search in seconds
        cout << "Search time using binary search: " << search_duration << " seconds" << endl;


        // Ask the user if they want to see more entries
        // cout << "Current Displayed Data = " << count << endl;
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
            cout << "Invalid choice. Please enter 'y' or 'n' to continue." << endl;
        }
    }
}

int main()
{

    vector<vector<string> > data = importdata();

    // remove first row
    if (!data.empty()) {
        data.erase(data.begin()); // Removes the first row (element) from the data vector
    }

    // set how many data entries to the algorithm
    displaySortedPropertyIdInPages(data, 5000);

    return 0;
}