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
			// CustomerClass* customerLogin = new CustomerClass;
			// if (customerLogin->cusLogin(cusHead)) {
			// 	system("cls");
			// 	cout << "Login successfully!" << endl;
			// 	cout << "Welcome back " << customerLogin->getUserName()<<"!" << endl<<endl;
			// 	cusMenu(customerLogin->getUserName(),head,cusHead, favHead, feedbackHead);
			// }else {
			// 	system("cls");
			// 	cout << "Incorrect username or password!" << endl;
			// }
			// delete customerLogin;
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
    cout << "loginTenant" << endl;
}

void loginManager(){
    cout << "loginManager" << endl;
}

void loginAdmin(){
    cout << "loginAdmin" << endl;
}