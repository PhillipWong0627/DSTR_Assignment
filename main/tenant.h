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
            cout << "--- Constructing the Doubly LinkedList object ---" << endl;
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
    };

