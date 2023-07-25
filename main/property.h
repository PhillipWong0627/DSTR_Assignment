#include <iostream>

using namespace std;

struct PropertyInfo {
    string adsid;
    string userid;
    string status;
};

template <class T>
class Property {
public:
    T data;
    Property<T> *prev;
    Property<T> *next;
};

class PropertyList {
public:
    Property<PropertyInfo> *head;
    Property<PropertyInfo> *tail;
    int size;

    // ... Other member functions ...

    void insertAtbeginning(const PropertyInfo& property) {
        Property<PropertyInfo>* newNode = new Property<PropertyInfo>;
        newNode->data = property;
        newNode->next = head;
        newNode->prev = nullptr;

        if (tail == nullptr) {
            tail = newNode;
        } else {
            head->prev = newNode;
        }

        head = newNode;
        size++;
    }

    void insertAtEnd(const PropertyInfo& property) {
        Property<PropertyInfo>* newNode = new Property<PropertyInfo>;
        newNode->data = property;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
        size++;
    }

    // void displayStatus(const string& adsid) const {
    //     Property<PropertyInfo>* current = head;
    //     while (current != nullptr) {
    //         if (current->data.adsid == adsid) {
    //             cout << string(50, '-') << endl;
    //             cout << "Status for adsid:" << adsid << endl;
    //             cout << "Tenant:" << current->data.userid << endl;
    //             cout << "Status:" << current->data.status << endl;
    //             cout << string(50, '-') << endl;
    //             return;
    //         }
    //         current = current->next;
    //     }
    //     cout << "AdsID not found!" << endl;
    // }

    void displayStatus(const string& searchKey) const {
        Property<PropertyInfo>* current = head;
        bool found = false;

        while (current != nullptr) {
            if (current->data.adsid == searchKey || current->data.userid == searchKey) {
                found = true;
                cout << string(50, '-') << endl;
                cout << "Status for adsid/userid: " << searchKey << endl;
                cout << "AdsID: " << current->data.adsid << endl;
                cout << "Tenant: " << current->data.userid << endl;
                cout << "Status: " << current->data.status << endl;
                cout << string(50, '-') << endl;
            }
            current = current->next;
        }

        if (!found) {
            cout << "No properties found for adsid/userid: " << searchKey << endl;
        }
    }


    bool changeStatus(const string& adsid, const string& newStatus) {
        Property<PropertyInfo>* current = head;
        while (current != nullptr) {
            if (current->data.adsid == adsid) {
                current->data.status = newStatus;
                cout << "Status for adsid " << adsid << " updated to: " << newStatus << endl;
                return true;
            }
            current = current->next;
        }
        cout << "AdsID not found! Status not updated." << endl;
        return false;
    }

};
