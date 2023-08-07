#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <limits>
#include "tenant.h"

using namespace std;

/*Defining the tenantList VARIABLE - 
Allocate Memory for the tenantList*/

extern TenantList tenantList;

class Manager
{

public:

    // DoublyLinkedList<Tenant> tenantList;
    string name;
    string password;
    string status = "active";

    void managerRegister()
    {
        //Dynamic Array, enter manager name
        //int *arrayName = new ArrayList<Intger>;
        //

        // string name, password;
        // string status = "active";

        cout << "Enter ManagerName: " << endl;
        cin >> name;
        cout << "Enter Password: " << endl; 
        cin >> password;

    }


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

                cout << "Searching Tenant's details..." << endl;

                string tenantName;
                cout << "Please Enter Tenant Name: " << endl;
                cin >> tenantName;

                Tenant * foundTenant = tenantList.searchTenant(tenantName);

                if(foundTenant != nullptr)
                {   
                    cout << "Tenant has Found!" << endl;
                    cout << "Tenant Details: " << endl;
                    cout << "Username: " << foundTenant->username << endl;
                    cout << "Password: " << foundTenant->password << endl;
                    cout << "Status: " << foundTenant->status << endl;
                }else{
                    cout << "Tenant not found..." << endl;
                }


            }
            else if (choice == 3)
            {
                cout << "Delete tenant account based on inactivity status" << endl;

            }
            else if (choice == 4)
            {
                cout << "Manage Tenancy Process" << endl;
            }
            else if (choice == 5)
            {
                cout << "5. Manage Payment" << endl;
            }
            else if (choice == 6)
            {
                system("cls");
                cout << "Logout successfully!" << endl;
                return;
            }
        }
    }

};


class ManagerArray{
    private:
        Manager *managerArray;
        int capacity;
        int size;

    public:
        ManagerArray(){
            capacity = 10; //Set an initial capacity for the arary
            size = 0;
            managerArray = new Manager[capacity];
        }

        ~ManagerArray(){
            //free allocated memory
            delete[] managerArray; 
        }

        void insertAtEnd(const std::string& name, const std::string& password, const std::string& status){

            // check if the array need to be resized to add new elemenet
            if(size == capacity){
                capacity *= 2;
                Manager *tempArray = new Manager[capacity];
                for(int i =0;i<size;i++){

                    tempArray[i]= managerArray[i];
                }
                delete[] managerArray;
                managerArray = tempArray;

            }

            Manager newManager;
            newManager.name = name;
            newManager.password = password;
            newManager.status = status;
            managerArray[size] = newManager;
            size++;

        }
        
        void displayAll(){
            cout << "--- DISPLAY ALL REGISTERED MANAGERS ---" << endl;
            for(int i =0; i < size; i++){
                cout << "Manager " << i +1 << " - Name: " << managerArray[i].name
                    << ", Password: " << managerArray[i].password
                    << ", Status: " <<  managerArray[i].status << endl;

            }

        }

        bool managerLogin(){
            
            string name, password;
            cout << "Manager Login" << endl;
        
            cout << "Enter your Manager Name (Enter 3 to exit): " << endl;
            cin >> name;

            if(name == "3")
            {
                cout << "Existing " << endl;
                return false;
            }
            cout << "Enter your password" << endl;
            cin >> password;

            bool loggedInSuccessfully = false;

            for(int i =0; i< size; i++){
                if(managerArray[i].name == name && managerArray[i].password == password)
                {
                    cout << "Login succesful! " << endl;
                    cout << "Welcome, Mr./Ms. " << name << endl;
                    loggedInSuccessfully = true;
                    
                    return true;
                    break;

                }

            }
            if(!loggedInSuccessfully)
            {
                cout << "Login failed. Manager not found or incorrect credentials." << endl;
            }

            return false;

        }

        bool usernameExists(const string &name) const
        {
            for(int i=0; i <size; i ++)
            {
                if(managerArray[i].name == name)
                {
                    return true;
                }
            }
            return false;
        }

        int getSize() const{
            return size;
        }

};



#endif 

