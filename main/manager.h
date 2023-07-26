#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <limits>
#include "tenant.h"
// #include "DoublyLinkedList.h"

using namespace std;

extern TenantList tenantList;

class Manager
{

public:

    // DoublyLinkedList<Tenant> tenantList;
    string name;
    string password;
    string status;
    
    

    
    void managerMenu()
    {
        
        int choice = 0;
        while (true)
        {
            cout << endl;

            // Create a static to get manager name........
            cout << "====================Manager Menu====================" << endl;
            cout << "1. Display all registered tenant' details" << endl;
            cout << "2. Search tenant's details" << endl;
            cout << "3. Delete tenant accounts baed on inactivity status" << endl;
            cout << "4. Manage Tenancy Process" << endl;
            cout << "5. Manage Payment" << endl;
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
                cout << "1. Display all registered tenant' details" << endl;
                cout << "2. Search tenant's details" << endl;
                cout << "3. Delete tenant accounts baed on inactivity status" << endl;
                cout << "4. Manage Tenancy Process" << endl;
                cout << "5. Manage Payment" << endl;
                cout << "6. Logout" << endl;
                cout << "Please select: ";
                cin >> choice;
            }

            if (choice == 1)
            {
                cout << "All Registered Tenants: " << endl;

            
                tenantList.displayAll();
            }
            else if (choice == 2)
            {

                string tenantName, pw;
                bool active;

                cout << "Enter Name:  " << endl;
                cin >> tenantName;
                
                cout << "Enter Password: " << endl;
                cin >> pw;

                // tenantList.insertAtEnd(TenantTest(tenantName,pw));



            }
            else if (choice == 3)
            {
            }
            else if (choice == 4)
            {
            }
            else if (choice == 5)
            {
            }
            else if (choice == 6)
            {
                system("cls");
                cout << "Logout successfully!" << endl;
                return;
            }
        }
    }

    bool managerLogin(string username, string password)
    {

        if (username == "Tee" && password == "123")
        {

            return true;
        }

        return false;
    }
};

#endif 

