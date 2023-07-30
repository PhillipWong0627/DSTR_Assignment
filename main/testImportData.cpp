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

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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


// Merge two sorted arrays into one sorted array
void mergeSize(std::vector<std::vector<std::string> >& arr, std::vector<int>& indices, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftIndices(n1);
    std::vector<int> rightIndices(n2);

    for (int i = 0; i < n1; i++) {
        leftIndices[i] = indices[left + i];
    }

    for (int j = 0; j < n2; j++) {
        rightIndices[j] = indices[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        // Extract the size square per feet strings for comparison
        const string& size1_str = arr[leftIndices[i]][9]; // Assuming size is in the 6th element (index 5)
        const string& size2_str = arr[rightIndices[j]][9];

        // Convert the size strings to integers for comparison
        int size1 = stringToInteger(size1_str);
        int size2 = stringToInteger(size2_str);

        if (size1 >= size2) { // Change the comparison to '>=' for descending order
            indices[k] = leftIndices[i];
            i++;
        } else {
            indices[k] = rightIndices[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        indices[k] = leftIndices[i];
        i++;
        k++;
    }

    while (j < n2) {
        indices[k] = rightIndices[j];
        j++;
        k++;
    }
}

// Merge Sort function for sorting data based on size square per feet
void mergeSortSize(std::vector<std::vector<std::string> >& arr, std::vector<int>& indices, int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;
    mergeSortSize(arr, indices, left, middle);
    mergeSortSize(arr, indices, middle + 1, right);
    mergeSize(arr, indices, left, middle, right);
}

// Function to display sorted data in pages
void displaySortedSizeInPages(std::vector<std::vector<std::string> >& data, int numEntriesPerPage) {
    // Calculate the number of pages
    int totalPages = (data.size() + numEntriesPerPage - 1) / numEntriesPerPage;

    // Display the stored matching rows in a table
    int currentPage = 1;
    while (currentPage <= totalPages) {
        // Calculate the start and end indices for the current page
        int startIndex = (currentPage - 1) * numEntriesPerPage;
        int endIndex = std::min(startIndex + numEntriesPerPage, static_cast<int>(data.size()));

        // Sort the current page data based on the size square per feet
        std::vector<std::vector<std::string> > currentData(data.begin() + startIndex, data.begin() + endIndex);
        std::vector<int> indices(currentData.size());
        for (size_t i = 0; i < indices.size(); i++) {
            indices[i] = i;
        }

        // Implementation of merge sort
        mergeSortSize(currentData, indices, 0, indices.size() - 1);

        // Display the sorted data for the current page
        for (const auto& index : indices) {
            for (const auto& value : currentData[index]) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
            // Print the line of dashes after each row
            std::cout << '\n' << std::string(30, '-') << std::endl;
        }

        // Ask the user if they want to see more entries
        char choice;
        std::cout << "Show more entries? (y/n): ";
        std::cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break; // Exit the loop if the user doesn't want to see more entries
        } else if (choice == 'y' || choice == 'Y') {
            currentPage++; // Move to the next page
        } else {
            std::cout << "Invalid choice. Please enter 'y' or 'n' to continue." << std::endl;
        }
    }
}

int main() {
    // Import data
    std::vector<std::vector<std::string> > data = importdata();

    // Display sorted data in pages based on size square per feet
    displaySortedSizeInPages(data, 30);

    return 0;
}
