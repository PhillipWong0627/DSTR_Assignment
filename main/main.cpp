#include <iostream>
#include <limits>
#include "import.cpp"

using namespace std;

// Function prototypes
void mainMenu();
void regCustomer();
void loginTenant();
void loginManager();
void loginAdmin();
int importdata();
void tenantMenu();
void searchTenant();
void saveFavorite();
void placeRent();
void displayHistory();

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
			// regCustomer();
            importdata();
		}
		else if (choice == 2)
		{
            loginTenant();
		}
		else if (choice == 3)
		{
			loginManager();
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
    cout << "regCustomer" << endl;
}

void loginTenant(){
    tenantMenu();
}

void tenantMenu() {
	// Node* sortedAr;
	// LinkedList linkedList;

	while (true) {
		// Node* temp = linkedList.clone(head);
		int choice;
		
		cout << "1. Sort and display property information" << endl;
		cout << "2. Search and display property details" << endl;
		cout << "3. Save their favorite property" << endl;
		cout << "4. Place a rent request the desired property that is stored in the favorite list" << endl;
		cout << "5. Display property renting history" << endl;
		cout << "6. Logout" << endl;
		cout << "Please select: ";
		cin >> choice;
		while (cin.fail() || choice < 1 || choice > 6)
		{
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect input!";
			cout << endl;
            cout << "1. Sort and display property information" << endl;
            cout << "2. Search and display property details" << endl;
            cout << "3. Save their favorite property" << endl;
            cout << "4. Place a rent request the desired property that is stored in the favorite list" << endl;
            cout << "5. Display property renting history" << endl;
            cout << "6. Logout" << endl;
            cout << "Please select: ";
			cin >> choice;
		}
		if (choice == 1) {
            cout << "sortTenant" << endl;
		}
		else if (choice == 2) {
            cout << "searchTenant" << endl;
		}
		else if (choice == 3) {
            cout << "saveFavorite" << endl;
		}
		else if (choice == 4) {
            cout << "placeRent" << endl;
		}
		else if (choice == 5) {
            cout << "displayHistory" << endl;
		}
		else if (choice == 6) {
			system("cls");
			cout << "Logout successfully!" << endl;
			return;
		}
	}
}

void sortTenant(){
    cout << "sortTenant" << endl;
}

void loginManager(){
    cout << "loginManager" << endl;
}

void loginAdmin(){
    cout << "loginAdmin" << endl;
}