#include <iostream>
#include <limits>
#include "importdata.h"
#include "tenant.h"
#include "property.h"
#include "manager.h"

using namespace std;

// Function prototypes
void mainMenu();
void regCustomer();
void loginManager();
void loginAdmin();
void tenantMenu();
void sortTenant();
void searchPorperty();
void searchDetails(int);
void displayPorperty();
void saveFavorite();
void placeRent();
void displayFavorite();
void rentHistory();
bool managerLogin(string username, string password);

string loginTenant();
string currentUsername;

// havent know got use or not
//void displayRent();
//void printData();
//void printTable(const std::vector<std::vector<std::string>>& rows);

PropertyList propertyList;
DoublyLinkedList<string> favList;
TenantList tenantList;
Manager manager;

int main(){
    mainMenu();

    return 0;
}

void mainMenu(){
   	int choice = 0;
	while (true)
	{
		cout << endl;
		cout << "Welcome to the Private Accommodation Rent System" << endl;
		cout << string(50, '-') << endl;
		cout << "1. Registration as Tenant" << endl;
		cout << "2. Login as Tenant" << endl;
        cout << "3. Login as Manager" << endl;
		cout << "4. Login as Admin" << endl;
		cout << "5. Exit" << endl;
		cout << "Please select: ";
		cin >> choice;

		while (cin.fail() || choice < 1 || choice > 5)
		{
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect input!";
			cout << endl;
            cout << "1. Registration as Tenant" << endl;
            cout << "2. Login as Tenant" << endl;
            cout << "3. Login as Manager" << endl;
            cout << "4. Login as Admin" << endl;
            cout << "5. Exit" << endl;
            cout << "Please select: ";
			cin >> choice;
		}
		
		if (choice == 1)
		{
			regCustomer();
		}
		else if (choice == 2)
		{
            string loggedInUsername = loginTenant(); // Receive the username from loginTenant function
            if (!loggedInUsername.empty()) {
                currentUsername = loggedInUsername; // Store the current username in the global variable
                cout << "Login successful! Welcome, " << currentUsername << "!" << endl;
                cout << string(50, '-') << endl;
                tenantMenu(); // Proceed with tenantMenu or other actions
            } else {
                // Handle failed login (e.g., show error message, return to main menu, etc.)
                cout << "Login failed. Please try again." << endl;
            }
		}
		else if (choice == 3)
		{
			string username, password;
            cout << "Please Enter manager name: " << endl;
            cin>> username;
            
            cout << "Please Enter manager password" << endl;
            cin  >> password;

            bool valid = manager.managerLogin(username,password);
            
            
            


            if(valid){
                cout << "Welcome Back Manager: " << username << endl;
                // managerMenu();
                manager.managerMenu();

            }
            else
            {
                cout << "Inavlid username/password " << endl;
            }
		}
		else if (choice == 4)
		{
			loginAdmin();
		}
		else if (choice == 5)
		{
            return;
			
		}
	}
}

void regCustomer(){
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    tenantList.registerTenant(username, password);

    cout << "Registration successful!" << endl;
}

string loginTenant() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    bool loginStatus = tenantList.loginTenant(username, password);
    if (loginStatus) {
        return username; // Return the username after successful login
    }
    return ""; // Return an empty string if login failed
}

void loginManager(){
    cout << "loginManager" << endl;
}

void loginAdmin(){
    cout << "loginAdmin" << endl;
}

void tenantMenu() {
	while (true) {
		int choice;
		
        cout << "1. Sort and display property information" << endl;
        cout << "2. Search and display property details" << endl;
        cout << "3. Display all property details" << endl;
        cout << "4. Save their favorite property" << endl;
        cout << "5. Place a rent request the desired property that is stored in the favorite list" << endl;
        cout << "6. Display property renting history" << endl;
        cout << "7. Logout" << endl;
		cout << "Please select: ";
		cin >> choice;
		while (cin.fail() || choice < 1 || choice > 7)
		{
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect input!";
			cout << endl;
            cout << "1. Sort and display property information" << endl;
            cout << "2. Search and display property details" << endl;
            cout << "3. Display all property details" << endl;
            cout << "4. Save their favorite property" << endl;
            cout << "5. Place a rent request the desired property that is stored in the favorite list" << endl;
            cout << "6. Display property renting history" << endl;
            cout << "7. Logout" << endl;
            cout << "Please select: ";
			cin >> choice;
		}
		if (choice == 1) {
            cout << "sortTenant" << endl;
		}
		else if (choice == 2) {
            searchPorperty();
		}
		else if (choice == 3) {
            displayPorperty();
		}
        else if (choice == 4) {
            saveFavorite();
		}
		else if (choice == 5) {
            placeRent();
		}
		else if (choice == 6) {
            rentHistory();
		}
		else if (choice == 7) {
			system("cls");
			cout << "Logout successfully!" << endl;
			return;
		}
	}
}

void sortTenant(){
    cout << "sortTenant" << endl;
}

void searchPorperty(){
    int choice;
    cout << "Searching" << endl;
    cout << "1. Ads ID" << endl;
    cout << "2. Property Name" << endl;
    cout << "3. Completion Year" << endl;
    cout << "4. Monthly Rent" << endl;
    cout << "5. Location" << endl;
    cout << "6. Property Type" << endl;
    cout << "7. Rooms" << endl;
    cout << "8. Parking" << endl;
    cout << "9. Bathroom" << endl;
    cout << "10. Size" << endl;
    cout << "11. Furnished" << endl;
    cout << "12. Facilities" << endl;
    cout << "13. Additional Facilities" << endl;
    cout << "14. Back to Main Menu" << endl;
    cout << "Please select: ";
    cin >> choice;
    while (cin.fail() || choice < 1 || choice > 14)
    {
        system("cls");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect input!";
        cout << endl;
        cout << "Searching" << endl;
        cout << "1. Ads ID" << endl;
        cout << "2. Property Name" << endl;
        cout << "3. Completion Year" << endl;
        cout << "4. Monthly Rent" << endl;
        cout << "5. Location" << endl;
        cout << "6. Property Type" << endl;
        cout << "7. Rooms" << endl;
        cout << "8. Parking" << endl;
        cout << "9. Bathroom" << endl;
        cout << "10. Size" << endl;
        cout << "11. Furnished" << endl;
        cout << "12. Facilities" << endl;
        cout << "13. Additional Facilities" << endl;
        cout << "13. Back to Main Menu" << endl;
        cout << "Please select: ";
        cin >> choice;
    }
    if (choice > 1 || choice < 13) {
        searchDetails(choice);
    }
    else if (choice == 14) {
        system("cls");
        cout << "Back to Main Menu!" << endl;
        return;
    }
    
}

void searchDetails(int choice){

    // Import data from CSV
    vector<vector<string>> data = importdata();

    string targetProperty;
    string result;

    if (choice == 1 || choice == 2 || choice == 3 || choice == 5 || choice == 6 || choice == 7 || choice == 8 || choice == 9 || choice == 11 || choice == 12 || choice == 13) {
        cout << "Enter the property details: ";
        cin >> targetProperty;
    }
    else if (choice == 4) {      
        cout << "Enter the property details: ";
        cin >> targetProperty;
        int count = 0;

        // Loop through the input string from the back
        for (int i = targetProperty.size() - 1; i >= 0; --i) {
            result = targetProperty[i] + result; // Add the current character to the result

            // Increment the count and add a space after every 3 digits
            if (++count == 3 && i > 0) {
                result = " " + result;
                count = 0;
            }
        }
        targetProperty = "RM " + result + " per month";
    }
    else if (choice == 10) {      
        cout << "Enter the property details: ";
        cin >> targetProperty;
        targetProperty = targetProperty + " sq.ft.";
    }

    // Assuming you have read the CSV file and stored the data in the 'data' vector
    string targetName = targetProperty;  // Specify the name you want to search for

    vector<vector<string>> matchingRows;  // Vector to store matching rows

    // // Search for the target name and store the matching rows
    for (const auto& row : data) {
        for (const auto& value : row) {
            if (value == targetName) {
                matchingRows.push_back(row);
                break;
            }
        }
    }

    //Display the stored matching rows
    cout << "Rows containing the name '" << targetName << "':" << endl;
    for (const auto& row : matchingRows) {
        for (const auto& val : row) {
            cout << val << "\t";
        }
        cout << endl;
        cout << string(50, '-') << endl;
    }

    saveFavorite();

}

void displayPorperty() {
    // DoublyLinkedList<string> favList;

    // Import data from CSV
    vector<vector<string>> data = importdata();

    int numEntriesPerPage = 30;
    int currentPage = 1;

    // Display the stored matching rows in a table
    while (true) {
        // Calculate the start and end indices for the current page
        int startIndex = (currentPage - 1) * numEntriesPerPage;
        int endIndex = min(startIndex + numEntriesPerPage, static_cast<int>(data.size()));

        // Loop through the rows in the current page
        for (int i = startIndex; i < endIndex; ++i) {
            // Loop through the columns of the current row
            for (size_t j = 0; j < data[i].size(); ++j) {
                // Process the value with double quotes if necessary
                string value = data[i][j];
                // if (value.front() == '"' && value.back() != '"') {
                //     // The value is enclosed in double quotes, but it spans multiple columns
                //     // Combine the values until we find the closing double quote
                //     while (j + 1 < data[i].size() && data[i][j + 1].back() != '"') {
                //         value += ";" + data[i][j + 1];
                //         ++j; // Skip the next column as it's already combined
                //     }
                //     // Add the closing double quote from the last column
                //     value += ";" + data[i][j + 1].substr(0, data[i][j + 1].size() - 1);
                //     ++j; // Skip the next column as it's already combined
                // }

                // if (value.front() == '"') {
                //     value = value.substr(1, value.size() - 2);
                // }

                // // Replace the semicolon back to comma before displaying
                // size_t pos;
                // while ((pos = value.find(';')) != std::string::npos) {
                //     value.replace(pos, 1, ",");
                // }

                //cout << data[0][j] << ": " << value << endl;

                cout << value << endl;
            }
            // Print the line of dashes after each row
            cout << string(30, '-') << endl;
        }

        // Ask the user if they want to see more entries
        char choice;
        cout << "Show more entries? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break; // Exit the loop if the user doesn't want to see more entries
        } else if (choice == 'y' || choice == 'Y') {
            currentPage++; // Move to the next page
        } else {
            cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
        }
    }
}

void saveFavorite(){
    string targetProperty;

    cout << "Enter the property ads id: ";
    cin >> targetProperty;

    // DoublyLinkedList<string> favList;

    // // Import data from CSV
    vector<vector<string>> data = importdata();

    // // Assuming you have read the CSV file and stored the data in the 'data' vector
    string targetName = targetProperty;  // Specify the name you want to search for

    vector<vector<string>> matchingRows;  // Vector to store matching rows

    // // Search for the target name and store the matching rows
    for (const auto& row : data) {
        for (const auto& value : row) {
            if (value == targetName) {
                matchingRows.push_back(row);
                break;
            }
        }
    }

    // Insert the matchingRows into the DoublyLinkedList
    // for (const auto& row : matchingRows) {
    //     favList.insertAtbeginning(row);
    // }

    string ads_id;

    // Insert the matchingRows into the DoublyLinkedList
    for (const auto& row : matchingRows) {
        ads_id = matchingRows[0][0];

        PropertyInfo property1 = {ads_id, currentUsername, "saved"};
        //favList.insertAtbeginning(ads_id+"-"+currentUsername);
        propertyList.insertAtbeginning(property1);
    }

    // Display the favorite properties
    // favList.showBackward();
    propertyList.displayStatus(ads_id);

    cout << "Add successfully " << endl;
    return;
}

void placeRent() {
    string targetElemet;

    //favList.showBackward();
    // favList.filter(currentUsername);
    propertyList.displayStatus(currentUsername);

    cout << "Enter the property ads id: ";
    cin >> targetElemet;

    propertyList.displayStatus(targetElemet);
}

void displayFavorite() {
    string targetElemet;

    //favList.showBackward();
    // favList.filter(currentUsername);
    propertyList.displayStatus(currentUsername);

    cout << "Enter the property ads id: ";
    cin >> targetElemet;

    propertyList.displayStatus(targetElemet);
}

void rentHistory(){

}