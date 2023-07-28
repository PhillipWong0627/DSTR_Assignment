#include <iostream>
#include <limits>
#include "importdata.h"
#include "tenant.h"
#include "property.h"

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
void pendingRent();
void makePayment(); 

string loginTenant();
string currentUsername;
string ads_id;
string inputadsid();

// manager part
void changeApprove();
void changeRented();

PropertyList propertyList;
DoublyLinkedList<string> favList;
TenantList tenantList;

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

		while (cin.fail() || choice < 1 || choice > 7)
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
                cout << string(50, '-') << endl;
                cout << "Login successful! Welcome, " << currentUsername << "!" << endl;
                cout << string(50, '-') << endl;
                tenantMenu(); // Proceed with tenantMenu or other actions
            } else {
                // Handle failed login (e.g., show error message, return to main menu, etc.)
                cout << string(50, '-') << endl;
                cout << "Login failed. Please try again." << endl;
                cout << string(50, '-') << endl;
            }
		}
		else if (choice == 3)
		{
			loginManager();
		}
		else if (choice == 4)
		{
			loginAdmin();
            // displayPorperty();
		}
		else if (choice == 5)
		{
            return;
			
		}
        else if (choice == 6)
		{
            changeApprove();
		}
        else if (choice == 7)
		{
            changeRented();	
		}
	}
}

void regCustomer(){
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // check register status
    bool registerStatus = tenantList.registerTenant(username, password);
    if (registerStatus) {
        cout << string(50, '-') << endl;
        cout << "Registration successful!" << endl;
        cout << string(50, '-') << endl;
        return;
    }
    else{
        system("cls");
        cout << string(50, '-') << endl;
        cout << "Username already exists. Please choose a different username." << endl;
        cout << string(50, '-') << endl;
        return;
    }

}

string loginTenant() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    bool loginStatus = tenantList.loginTenant(username, password);
    if (loginStatus) {
        return username;
    }
    return "";
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
        cout << "7. Make Payment for the rent property" << endl;
        cout << "8. Logout" << endl;
		cout << "Please select: ";
		cin >> choice;
		while (cin.fail() || choice < 1 || choice > 8)
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
            cout << "7. Make Payment for the rent property" << endl;
            cout << "8. Logout" << endl;
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
        else if (choice == 7)
		{
            makePayment();
		}
		else if (choice == 8) {
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
        cout << "14 Back to Main Menu" << endl;
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

    char choices;
    cout << "Do you want to add to favorite? (y/n): ";
    cin >> choices;

    if (choices == 'n' || choices == 'N') {
        return;
    } else if (choices == 'y' || choices == 'Y') {
        saveFavorite();
        return;
    } else {
        return; 
    }
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
            // Assuming you have read the CSV file and stored the data in the 'data' vector

            // Displaying all values in row 1
            cout << "Property ID: " << data[i][0] << endl;
            for (const auto& value : data[i]) {
                cout << value << "\t";
            }
            cout << endl;

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
            return;
        }
    }
}

void saveFavorite(){
    string targetProperty = inputadsid();

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

    // Check if any matching rows were found
    if (matchingRows.empty()) {
        // Ask the user if they want to see more entries
        char choice;
        cout << "No matching rows found for ads id: " << targetProperty << endl;
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            return;
        } else if (choice == 'y' || choice == 'Y') {
            cout << "Please enter a valid ads id." << endl;
            saveFavorite(); // Ask the user to enter the ads id again
            return; // Exit the function to avoid further processing
        } else {
            cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
            saveFavorite();
            return; // Exit the function to avoid further processing
        }

    }

    string ads_ids; 
    bool foundFavorite;
    string monthlyrent;
    int rentValue = 0;

    // Insert the matchingRows into the DoublyLinkedList
    for (const auto& row : matchingRows) {
        ads_id = matchingRows[0][0];
        monthlyrent = matchingRows[0][3];

        // Create a stringstream to extract the integer
        monthlyrent.erase(remove(monthlyrent.begin(), monthlyrent.end(), ' '), monthlyrent.end());

        bool foundDigit = false;

        for (char c : monthlyrent) {
            if (std::isdigit(c)) {
                rentValue = rentValue * 10 + (c - '0');
                foundDigit = true;
            } else if (foundDigit) {
                break;
            }
        }

        ostringstream oss;
        for (const auto& value : row) {
            if (!oss.str().empty()) {
                oss << " "; // Separate values by tab character
            }
            oss << value;
        }
        if (!ads_ids.empty()) {
            ads_ids += "\n"; // Separate rows by a new line character
        }
        ads_ids += oss.str();

        PropertyInfo property1 = {ads_id, ads_ids, currentUsername, "Favorited", rentValue};

        foundFavorite = propertyList.insertAtbeginning(property1);

    }

    if (foundFavorite) {
        propertyList.displayStatus(ads_id, "Favorited");
        cout << string(50, '-') << endl;
        cout << "Add successfully " << endl;
        cout << string(50, '-') << endl;
        return;
    }
    else{
        // Ask the user if they want to see more entries
        char choice;
        cout << "Do you search again? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            tenantMenu();
            return;
        } else if (choice == 'y' || choice == 'Y') {
            saveFavorite();
            return;
        } else {
            cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
            saveFavorite();
            return;
        }
    }
}

void placeRent() {
    bool foundProperty_1 = propertyList.displayStatus(currentUsername, "Favorited");

    if (!foundProperty_1) {
        // Ask the user if they want to see more entries
        cout << string(50, '-') << endl;
        cout << "Do have any favorite property, please add favorite property on choice 4! " << endl;
        cout << string(50, '-') << endl;
        tenantMenu();
        return;
    }

    string targetElemet = inputadsid();

    bool foundProperty = propertyList.displayStatus(targetElemet, "Favorited");

    if (foundProperty) {
        // Ask the user if they want to see more entries
        char choice;
        cout << "Do you want to continue place rent? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            tenantMenu();
            return;
        } else if (choice == 'y' || choice == 'Y') {
            pendingRent();
            return;
        } else {
            cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
            placeRent();
            return;
        }
    }
    else{
        // Ask the user if they want to see more entries
        char choice;
        cout << "Do you search again? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            tenantMenu();
            return;
        } else if (choice == 'y' || choice == 'Y') {
            placeRent();
            return;
        } else {
            cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
            placeRent();
            return;
        }
    }
}

void pendingRent() {
    string amount = "100";

    cout << string(50, '-') << endl;
    cout << "Processing place rent..." << std::endl;
    cout << "Upload successful! Please wait for approval on it!" << std::endl;
    cout << string(50, '-') << endl;

    propertyList.changeStatus(ads_id, "pending");
    cout << string(50, '-') << endl;
}

void displayFavorite() {
    propertyList.displayStatus(currentUsername, "Favorited");

    string targetElemet = inputadsid();

    propertyList.displayStatus(targetElemet, "Favorited");
}


void rentHistory(){
    propertyList.displayStatus(currentUsername, "displayall");
}


string inputadsid() {
    string targetProperty;
    while (true) {
        cout << "Enter the property ads id (8/9-digit integer): ";
        cin >> targetProperty;

        // Check if the input is a 9-digit integer
        bool validInput = true;
        for (char c : targetProperty) {
            if (!isdigit(c)) {
                validInput = false;
                break;
            }
        }

        if (validInput && targetProperty.length() == 9 || validInput && targetProperty.length() == 8) {
            // Input is a valid 9-digit integer, break out of the loop
            break;
        } else {
            cout << "Invalid input. Please enter a 9-digit integer." << endl;
        }
    }
    
    return targetProperty;
}

void changeApprove() {
string targetElemet = inputadsid();
propertyList.changeStatus(targetElemet, "approve");
}

void changeRented() {
string targetElemet = inputadsid();
propertyList.changeStatus(targetElemet, "rented");
}

void makePayment() {
    bool foundProperty = propertyList.displayStatus(currentUsername, "approve");

    if (foundProperty) {
        string targetElemet = inputadsid();

        propertyList.displayStatus(targetElemet, "approve");

        cout << string(50, '-') << endl;
        cout << "Please bank in to this account:" << endl;
        cout << "Bank Details:" << endl;
        cout << "Bank Account: 52165746487982" << endl;
        cout << "Bank Name: Wong Liang Jian" << endl;
        cout << "Bank: Wong Bank" << endl;
        cout << string(50, '-') << endl;

        char choice;
        cout << "Do you done the payment? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            return;
        } else if (choice == 'y' || choice == 'Y') {
            propertyList.changeStatus(targetElemet, "waiting");
            return;
        } else {
            cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
            makePayment();
            return;
        }
    }
    else{
        // Ask the user if they want to see more entries
        cout << string(50, '-') << endl;
        cout << "Do have any approved property, please place rennt on choice 5! " << endl;
        cout << string(50, '-') << endl;
        return;
    }
}
