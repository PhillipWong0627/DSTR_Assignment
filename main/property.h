#include <iostream>

using namespace std;

struct PropertyInfo {
    string adsid;
    string ads_ids;
    string userid;
    string status;
    int rentPrice;
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

    bool insertAtbeginning(const PropertyInfo& property) {
    // Check if the same ads_id and currentUsername already exist in the list
    Property<PropertyInfo>* current = head;
    while (current != nullptr) {
        if (current->data.adsid == property.adsid && current->data.userid == property.userid) {
            cout << string(50, '-') << endl;
            cout << "Property with the same ads_id and currentUsername already exists. Insertion aborted." << endl;
            cout << string(50, '-') << endl;
            return false;
        }
        current = current->next;
    }

    // If the property is not found, proceed with the insertion
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

    return true;
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

    bool displayStatus(const string& searchKey, const string& statusKey) const {
    Property<PropertyInfo>* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->data.adsid == searchKey || current->data.userid == searchKey) {
            if (current->data.status == "approve") {
                found = true;
                cout << string(50, '-') << endl;
                cout << "Status for adsid/userid: " << searchKey << endl;
                cout << "AdsID: " << current->data.adsid << endl;
                cout << "Ads Details: " << current->data.ads_ids << endl;
                cout << "Tenant: " << current->data.userid << endl;
                cout << "Deposit: " << current->data.rentPrice * 2 << endl;
                cout << "Monthly Rent: " << current->data.rentPrice << endl;
                cout << "Total Pay 2Month + 1Month: " << current->data.rentPrice * 3 << endl;
                cout << "Status: " << current->data.status << endl;
                cout << string(50, '-') << endl;
            }
            else if (current->data.status == statusKey) {
                found = true;
                cout << string(50, '-') << endl;
                cout << "Status for adsid/userid: " << searchKey << endl;
                cout << "AdsID: " << current->data.adsid << endl;
                cout << "Ads Details: " << current->data.ads_ids << endl;
                cout << "Tenant: " << current->data.userid << endl;
                cout << "Monthly Rent: " << current->data.rentPrice << endl;
                cout << "Status: " << current->data.status << endl;
                cout << string(50, '-') << endl;
            }
            else if (statusKey == "displayall"){
                if (current->data.status != "Favorited") {
                    found = true;
                    cout << string(50, '-') << endl;
                    cout << "Status for adsid/userid: " << searchKey << endl;
                    cout << "AdsID: " << current->data.adsid << endl;
                    cout << "Ads Details: " << current->data.ads_ids << endl;
                    cout << "Tenant: " << current->data.userid << endl;
                    cout << "Monthly Rent: " << current->data.rentPrice << endl;
                    cout << "Status: " << current->data.status << endl;
                    cout << string(50, '-') << endl;
                }
            }
        }
        else{
            if (current->data.status == statusKey){
                found = true;
                cout << string(50, '-') << endl;
                cout << "Status for adsid/userid: " << searchKey << endl;
                cout << "AdsID: " << current->data.adsid << endl;
                cout << "Ads Details: " << current->data.ads_ids << endl;
                cout << "Tenant: " << current->data.userid << endl;
                cout << "Monthly Rent: " << current->data.rentPrice << endl;
                cout << "Status: " << current->data.status << endl;
                cout << string(50, '-') << endl;
            } 
                
            
        }
        current = current->next;
    }

    if (!found) {
        cout << string(50, '-') << endl;
        cout << "No properties found for adsid/userid: " << searchKey << endl;
        cout << string(50, '-') << endl;
    }

    return found; // Return true if the property was found, false otherwise
}


    bool changeStatus(const string& adsid, const string& newStatus) {
        Property<PropertyInfo>* current = head;
        while (current != nullptr) {
            if (current->data.adsid == adsid) {
                current->data.status = newStatus;
                //cout << "Status for adsid " << adsid << " updated to: " << newStatus << endl;
                cout << "AdsID: " << current->data.adsid << endl;
                cout << "Ads Details: " << current->data.ads_ids << endl;
                cout << "Tenant: " << current->data.userid << endl;
                cout << "Monthly Rent: " << current->data.rentPrice << endl;
                cout << "Status: " << current->data.status << endl;
                cout << string(50, '-') << endl;
                return true;
            }
            current = current->next;
        }
        cout << "AdsID not found! Status not updated." << endl;
        return false;
    }

};
