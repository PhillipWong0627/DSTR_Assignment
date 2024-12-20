#include <iostream>

using namespace std;

/**
 * with class implementation...
 */

template <class T> // abstract type
class ManagerDoublyNode
    {
    public:
        T name;
        T password;
        T status;
        ManagerDoublyNode<T> *prev;
        ManagerDoublyNode<T> *next;
    };

template <class T>
class ManagerLinkedList
    {
    public:
        ManagerDoublyNode<T> *head;
        ManagerDoublyNode<T> *tail;
        int size;

        ManagerLinkedList()
        {
            cout << "--- Constructing the Doubly LinkedList object ---" << endl;
            this->size = 0;
            this->head = nullptr;
            this->tail = nullptr;
        }

        // void insertAtbeginning(const std::vector<std::string>& row) {
        //     for (const auto& value : row) {
        //         insertAtbeginning(value);
        //     }
        // }

        void insertAtbeginning(T elem)
        {
            /* PLACE YOUR CODE HERE */
            // cout << "Inserting = " << elem << endl;
            ManagerDoublyNode<T> *newNode = new ManagerDoublyNode<T>;
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
       

        void insertAtEnd(T name, T password, T status )
        {
            cout << "Inserting = " << name <<" "<<password<<" "<<status << endl;
            ManagerDoublyNode<T> *newNode = new ManagerDoublyNode<T>;
            newNode->name = name;
            newNode->password = password;
            newNode->status = status;
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
        bool validate(T name){
            ManagerDoublyNode<T> *curr = head;
            
            while (curr != nullptr)
            {   
                if(name== curr->name){
                    return false;
                    break;
                }
                
                curr = curr->next;

            }
            return true;
        }
        bool  validatemanager(T name, T pass){

            ManagerDoublyNode<T> *curr = head;
            while (curr != nullptr)
            {   
                if(name == curr->name && pass == curr->password && curr->status =="active"){
                        return true;
                        break;
                }
                
                curr = curr->next;

            }
            return false;
            
        }
        void showForward()
        {   
            ManagerDoublyNode<T> *curr = head;
            cout << "\n--- DISPLAY LINKED LIST [FORWARD] = " << size << " elements ---" << endl;
            if(curr == nullptr){
                cout<< "No Managers Record" << endl;
               
               
            }else{
                while (curr != nullptr)
            {
                cout << curr->name << " ";
                cout << curr->password<< " ";
                cout << curr->status << endl; 
                curr = curr->next;
            }
            }
           
            cout << endl;
        }
        bool showForwardandvalidate()
        {   
            ManagerDoublyNode<T> *curr = head;
            cout << "\n--- DISPLAY LINKED LIST [FORWARD] = " << size << " elements ---" << endl;
            if(curr ==nullptr){
                cout<< "No Managers Record" << endl;
                cout << endl;
                return false;
               
            }else{
                    while (curr != nullptr)
                {
                    cout << curr->name << " ";
                    cout << curr->password<< " ";
                    cout << curr->status << endl; 
                    curr = curr->next;
                }
                return true;
            }
           
            cout << endl;
        }

        
        void changestatus(T name){
            ManagerDoublyNode<T> *curr = head;
            bool found = false;
            while (curr!=nullptr){
                if(curr->name == name){
                    if(curr->status =="active"){
                        curr->status="inactive";
                    }else{
                        curr->status="active";
                    }  
                    cout <<curr->name<< "-> Current Status =" <<curr->status << endl;
                    found = true;
                   
                }
                curr = curr->next;
            }
            if (!found) {
                cout << name<<" are not in the lists." << endl; // Display this message if no tenants are found matching the filter criteria
                
            }
            cout << endl;
        }

        void showBackward()
        {
            /* PLACE YOUR CODE HERE */
            ManagerDoublyNode<T> *curr = tail;
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
            ManagerDoublyNode<T>* current = head;
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
            ManagerDoublyNode<T>* current = head;
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



