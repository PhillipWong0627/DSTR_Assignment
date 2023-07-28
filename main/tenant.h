#include <iostream>

using namespace std;

/**
 * with class implementation...
 */

template <class T> // abstract type
class DoublyNode
    {
    public:
        T data;
        DoublyNode<T> *prev;
        DoublyNode<T> *next;
    };

template <class T>
class DoublyLinkedList
    {
    public:
        DoublyNode<T> *head;
        DoublyNode<T> *tail;
        int size;

        DoublyLinkedList()
        {
            //cout << "--- Constructing the Doubly LinkedList object ---" << endl;
            this->size = 0;
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insertAtbeginning(const std::vector<std::string>& row) {
            for (const auto& value : row) {
                insertAtbeginning(value);
            }
        }

        void insertAtbeginning(T elem)
        {
            /* PLACE YOUR CODE HERE */
            // cout << "Inserting = " << elem << endl;
            DoublyNode<T> *newNode = new DoublyNode<T>;
            newNode->data = elem;
            newNode->next = head;
            head = newNode;
            newNode->prev = nullptr;

            if (tail == nullptr)
            {
                tail = newNode;
            }
            else
            {
                newNode->next->prev = newNode;   
            }
                
            size++;
        }

        void insertAtEnd(T elem)
        {
            cout << "Inserting = " << elem << endl;
            DoublyNode<T> *newNode = new DoublyNode<T>;
            newNode->data = elem;
            newNode->next = nullptr;
            newNode->prev = tail;
            tail = newNode;

            if (head == nullptr)
            {
                head = newNode;
            }
            else
            {
                newNode->prev->next = newNode;
            }
            size++;
        }

        void insertItemAt(T elem, int index)
        {
            /**
             * PLACE YOUR CODE HERE
             */
        }

        int getSize()
        {
            return size;
        }

        void showForward()
        {
            DoublyNode<T> *curr = head;
            cout << "\n--- DISPLAY LINKED LIST [FORWARD] = " << size << " elements ---" << endl;
            while (curr != nullptr)
            {
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        }

        void showBackward()
        {
            /* PLACE YOUR CODE HERE */
            DoublyNode<T> *curr = tail;
            cout << "\n--- DISPLAY LINKED LIST [BACKWARD] " << size << " elements ---" << endl;
            while (curr != nullptr)
            {
                cout << curr->data << " ";
                curr = curr->prev;
            }
            cout << endl;
        }

        void sort()
        {
            /* PLACE YOUR CODE HERE */
        }

        
        void find(const T& targetValue) const
        {
            DoublyNode<T>* current = head;
            bool found = false;
            while (current != nullptr)
            {
                // Check if the current element contains the target value
                if (current->data.find(targetValue) != std::string::npos)
                {
                    found = true;
                    cout << "Element found: " << current->data << endl;
                }
                current = current->next;
            }
            if (!found)
            {
                cout << "Element not found!" << endl;
            }
        }

        void filter(const string& targetValue) const {
            DoublyNode<T>* current = head;
            cout << "--- FILTERED VALUES ---" << endl;
            while (current != nullptr) {
                // Check if the current element contains the target value
                if (current->data.find(targetValue) != std::string::npos) {
                    cout << current->data << endl;
                }
                current = current->next;
            }
            cout << "------------------------" << endl;
        }
    };

// Add a new class to represent the Tenant with username and password
class Tenant {
public:
    string username;
    string password;

    // Default constructor
    Tenant() : username(""), password("") {}

    // Parameterized constructor
    Tenant(const string& username, const string& password) : username(username), password(password) {}
};

class TenantList {
public:
    DoublyLinkedList<Tenant> tenantList;

    bool registerTenant(const string& username, const string& password) {
        // Check if the username already exists in the linked list
        DoublyNode<Tenant>* current = tenantList.head;
        while (current != nullptr) {
            if (current->data.username == username) {
                return false;; // Exit the function if the username already exists
            }
            current = current->next;
        }

        // If the username does not exist, create a new tenant and insert it into the linked list
        Tenant newTenant(username, password);
        tenantList.insertAtbeginning(newTenant);

        return true;
    }

    // Function to login a tenant
    bool loginTenant(const string& username, const string& password) {
        DoublyNode<Tenant>* current = tenantList.head;
        while (current != nullptr) {
            if (current->data.username == username && current->data.password == password) {
                //cout << "Login successful!" << endl;
                return true;
            }
            current = current->next;
        }
        cout << "Invalid username or password. Login failed!" << endl;
        return false;
    }
};

