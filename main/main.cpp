#include <iostream>
#include <limits>
#include "importdata.h"
#include "tenant.h"
#include "property.h"
#include "manager.h"
#include "manager_linkedlist.h"
#include "sortFunction.h"

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
void adminmenu();
void registermanager();
bool managerLogin(string username, string password);
int stringToInteger(const string &str);
void displaySortedRentalFeeInPages(vector<vector<string> > &data, int numEntriesPerPage);
void displaySortedLocationInPages(std::vector<std::vector<std::string> >& data, int numEntriesPerPage);

string loginTenant();
string currentUsername;
string ads_id;
string inputadsid();


// manager part
void changeApprove();
void changeRented();

// havent know got use or not
// void displayRent();
// void printData();
// void printTable(const std::vector<std::vector<std::string>>& rows);

PropertyList propertyList;
DoublyLinkedList<string> favList;
ManagerLinkedList<string> managerlist;
TenantList tenantList;
Manager manager;
SortFunction sortFunction;

int main()
{
    mainMenu();

    return 0;
}

void mainMenu()
{
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
            if (!loggedInUsername.empty())
            {
                currentUsername = loggedInUsername; // Store the current username in the global variable
                cout << string(50, '-') << endl;
                cout << "Login successful! Welcome, " << currentUsername << "!" << endl;
                cout << string(50, '-') << endl;
                tenantMenu(); // Proceed with tenantMenu or other actions
            }
            else
            {
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
			adminmenu();
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

void regCustomer()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // check register status
    bool registerStatus = tenantList.registerTenant(username, password, "active");
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

    /////////////////////////////////////////////////////////double check/////////////////////////////////////////////
    //tenantList.registerTenant(username, password, "active");
    //tenantList.displayAll();

}

string loginTenant()
{
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

void loginManager()
{
    string name = "";
    string pass = "";
    cout << "Manager pages (Enter 3 to Exits this pages)" << endl
         << endl;

    cout << "Enter your Manager name" << endl;
    cin >> name;

    
    if (name == "3")
    {
        cout << "Exiting" << endl;
        return;
    }
    cout << "Enter your passcode" << endl;
    cin >> pass;

    if(managerlist.validatemanager(name,pass)==true){
        cout<<"Welcome "<< name << endl;
        manager.managerMenu();
    }else{
        cout<<" Invalid Credentials or Ur Account Has Been Disabled " << endl;
    }


}

void loginAdmin()
{
    string username = "admin";
    string passcode = "admin123";
    string name = "";
    string pass = "";
    cout << "Admin pages (Enter 3 to Exits this pages)" << endl
         << endl;

    cout << "Enter your admin name" << endl;
    cin >> name;

    if (name == "3")
    {
        cout << "Exiting" << endl;
        main();
    }

    cout << "Enter your passcode" << endl;
    cin >> pass;

    if (name != username || pass != passcode)
    {
        cout << endl
             << "Invalid Credentials" << endl;

        loginAdmin();
    }
    else
    {
        cout << endl
             << "Welcome" << name << endl;
        adminmenu();
    }
}

void adminmenu()
{
    int choice;

    cout << "1. Add New Manager" << endl;
    cout << "2. Modify Manager Status" << endl;
    cout << "3. Display Tenants" << endl;
    cout << "4. Display Property Information" << endl;
    cout << "5. Log Out" << endl;
    cout << "Please Select" << endl;

    cin >> choice;
    do
    {
        if (choice == 1)
        {
            registermanager();
            adminmenu();
        }
        else if (choice == 2)
        {   
            cout<< " Managers list "<<endl;
            managerlist.showForward();
            adminmenu();
            // updatestatus();
            break;
        }
        else if (choice == 3)
        {
            // displaytenants();
            break;
        }
        else if (choice == 4)
        {
            // displaytenants();
            break;
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid input please select the correct input" << endl
                 << endl;
            adminmenu();
            break;
        }

    } while (choice < 0 || choice > 6);
}
void registermanager()
{
    string name, pass;
    string status = "active";
    cout << "Enter Username" << endl;
    cin >> name;
    cout << "Enter Password" << endl;
    cin >> pass;
    if (managerlist.validate(name) == true)
    {
        managerlist.insertAtEnd(name, pass, status);
        cout << endl
             << "Manager successfully inserted" << endl;
    }
    else
    {
        cout << endl
             << "Same name existed" << endl;
    }

    managerlist.showForward();
}

void tenantMenu()
{
    while (true)
    {
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
        if (choice == 1)
        {
            sortTenant();
        }
        else if (choice == 2)
        {
            searchPorperty();
        }
        else if (choice == 3)
        {
            displayPorperty();
        }
        else if (choice == 4)
        {
            saveFavorite();
        }
        else if (choice == 5)
        {
            placeRent();
        }
        else if (choice == 6)
        {
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

void sortTenant()
{
    // import data
    vector<vector<string> > data = importdata();

    int choice = 0;

    cout << "Sort By" << endl;
    cout << "1) Rental Fee" << endl;
    cout << "2) Location" << endl;
    cout << "3) Demo" << endl;
    cin >> choice;

    while (cin.fail() || choice < 1 || choice > 3)
    {
        system("cls");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect Input!" << endl;
        cout << "1) Rental Fee" << endl;
        cout << "2) Location" << endl;
        cout << "3) Demo" << endl;
        cout << "Please select: " << endl;
        cin >> choice;
    }


    if(choice == 1)
    {
        displaySortedRentalFeeInPages(data, 30);
    }
    else if (choice == 2)
    {
        displaySortedLocationInPages(data, 30);
    }
    else if (choice == 3)
    {
        cout << "demo" << endl;
    }
    else
    {
        return;
    }


}

void searchPorperty()
{
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
    if (choice > 1 || choice < 13)
    {
        searchDetails(choice);
    }
    else if (choice == 14)
    {
        system("cls");
        cout << "Back to Main Menu!" << endl;
        return;
    }
}

void searchDetails(int choice)
{

    // Import data from CSV
    vector<vector<string> > data = importdata();

    string targetProperty;
    string result;

    if (choice == 1 || choice == 2 || choice == 3 || choice == 5 || choice == 6 || choice == 7 || choice == 8 || choice == 9 || choice == 11 || choice == 12 || choice == 13)
    {
        cout << "Enter the property details: ";
        cin >> targetProperty;
    }
    else if (choice == 4)
    {
        cout << "Enter the property details: ";
        cin >> targetProperty;
        int count = 0;

        // Loop through the input string from the back
        for (int i = targetProperty.size() - 1; i >= 0; --i)
        {
            result = targetProperty[i] + result; // Add the current character to the result

            // Increment the count and add a space after every 3 digits
            if (++count == 3 && i > 0)
            {
                result = " " + result;
                count = 0;
            }
        }
        targetProperty = "RM " + result + " per month";
    }
    else if (choice == 10)
    {
        cout << "Enter the property details: ";
        cin >> targetProperty;
        targetProperty = targetProperty + " sq.ft.";
    }

    // Assuming you have read the CSV file and stored the data in the 'data' vector
    string targetName = targetProperty; // Specify the name you want to search for

    vector<vector<string> > matchingRows; // Vector to store matching rows

    // // Search for the target name and store the matching rows
    for (const auto &row : data)
    {
        for (const auto &value : row)
        {
            if (value == targetName)
            {
                matchingRows.push_back(row);
                break;
            }
        }
    }

    // Display the stored matching rows
    cout << "Rows containing the name '" << targetName << "':" << endl;
    for (const auto &row : matchingRows)
    {
        for (const auto &val : row)
        {
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

void displayPorperty()
{
    // DoublyLinkedList<string> favList;

    // Import data from CSV
    vector<vector<string> > data = importdata();

    int numEntriesPerPage = 30;
    int currentPage = 1;

    // Display the stored matching rows in a table
    while (true)
    {
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
            return;
        }
    }
}

void saveFavorite(){
    string targetProperty = inputadsid();

    // // Import data from CSV
    vector<vector<string> > data = importdata();

    // // Assuming you have read the CSV file and stored the data in the 'data' vector
    string targetName = targetProperty; // Specify the name you want to search for

    vector<vector<string> > matchingRows; // Vector to store matching rows

    // // Search for the target name and store the matching rows
    for (const auto &row : data)
    {
        for (const auto &value : row)
        {
            if (value == targetName)
            {
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
    for (const auto &row : matchingRows)
    {
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

void SortFunction::BubbleSortRentalFee(vector<vector<string> >& data) {
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

void displaySortedRentalFeeInPages(vector<vector<string> > &data, int numEntriesPerPage)
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
        sortFunction.BubbleSortRentalFee(currentData);

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

// Merge two sorted arrays into one sorted array
void SortFunction::mergeLocation(std::vector<std::vector<std::string> >& arr, std::vector<int>& indices, int left, int middle, int right) {
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
        // Extract the location strings for comparison
        const string& location1 = arr[leftIndices[i]][4]; // Assuming location is in the 6th element (index 5)
        const string& location2 = arr[rightIndices[j]][4];

        if (location1 >= location2) {
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

// Merge Sort function for sorting data based on rental fee
void SortFunction::mergeSortLocation(std::vector<std::vector<std::string> >& arr, std::vector<int>& indices, int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;
    sortFunction.mergeSortLocation(arr, indices, left, middle);
    sortFunction.mergeSortLocation(arr, indices, middle + 1, right);
    sortFunction.mergeLocation(arr, indices, left, middle, right);
}

// Function to display sorted data in pages
void displaySortedLocationInPages(std::vector<std::vector<std::string> >& data, int numEntriesPerPage) {
    // Calculate the number of pages
    int totalPages = (data.size() + numEntriesPerPage - 1) / numEntriesPerPage;

    // Display the stored matching rows in a table
    int currentPage = 1;
    while (currentPage <= totalPages) {
        // Calculate the start and end indices for the current page
        int startIndex = (currentPage - 1) * numEntriesPerPage;
        int endIndex = std::min(startIndex + numEntriesPerPage, static_cast<int>(data.size()));

        // Sort the current page data based on the rental fee
        std::vector<std::vector<std::string> > currentData(data.begin() + startIndex, data.begin() + endIndex);
        std::vector<int> indices(currentData.size());
        for (size_t i = 0; i < indices.size(); i++) {
            indices[i] = i;
        }
        
        // implementation of merge sort
        sortFunction.mergeSortLocation(currentData, indices, 0, indices.size() - 1);

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
