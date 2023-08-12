#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct PropertyInfo {
    string adsid;
    string ads_ids;
    string userid;
    string status;
    int rentPrice;


    friend std::ostream& operator<<(std::ostream& os, const PropertyInfo& property) {
        os << "AdsID: " << property.adsid << ", Ads Details: " << property.ads_ids << ", Tenant: " << property.userid
           << ", Monthly Rent: " << property.rentPrice << ", Status: " << property.status;
        return os;
    }

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
        else if (searchKey == "hiisme"){
            if (current->data.status == statusKey){
                found = true;
                cout << string(50, '-') << endl;
                //cout << "Status for adsid/userid: " << searchKey << endl;
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

    bool seconddisplayStatus(const string& searchKey, const string& user_id, const string& statusKey) const {
    Property<PropertyInfo>* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->data.adsid == searchKey || current->data.userid == searchKey) {
            if (current->data.status == "approve" && current->data.userid == user_id) {
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
            else if (current->data.status == statusKey && current->data.userid == user_id) {
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
                if (current->data.status != "Favorited" && current->data.userid == user_id) {
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
        else if (searchKey == "hiisme"){
            if (current->data.status == statusKey){
                found = true;
                cout << string(50, '-') << endl;
                //cout << "Status for adsid/userid: " << searchKey << endl;
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

    bool managerchangeStatus(const string& adsid, const string& user_id, const string& newStatus) {
        Property<PropertyInfo>* current = head;
        while (current != nullptr) {
            if (current->data.adsid == adsid && current->data.userid == user_id) {
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

    void showForward()
    {
        Property<PropertyInfo> *curr = head;
        cout << "\n--- DISPLAY LINKED LIST [FORWARD] = " << size << " elements ---" << endl;

        while(curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    void displayAll() const {
        Property<PropertyInfo> *curr = head;
        bool found = false;

        cout << "--- DISPLAY ALL FAVOURITE LIST ---" << endl;
        while(curr != nullptr)
        {

            cout << "Ads ID: " << curr->data.adsid << endl;
            cout << "Ads Details: " <<  curr->data.ads_ids << endl;
            cout << "Monthly Rent: " << curr->data.rentPrice << endl;
            cout << "Tenant: " << curr->data.userid << endl;
            cout << "Status: " << curr->data.status << endl;

            found = true;
            curr = curr->next;
        }

        if(!found)
        {
            cout <<"No tenants registered!" << endl; // Display this message if no tenants are registered
        }
        cout << endl;

    }

    void generateTopFavoritesReport() const
    {
        // Count the occurrences of each property (ads_id) in the list
        map<string, int> propertyCount;
        Property<PropertyInfo> *current = head;
        while (current != nullptr)
        {
            if (current->data.status == "Favorited")
            {
                propertyCount[current->data.adsid]++;
            }
            current = current->next;
        }

        // Create a vector of pairs for sorting
        vector<pair<string, int>> sortedProperties(propertyCount.begin(), propertyCount.end());
        // Sort the vector in descending order based on counts
        sort(sortedProperties.begin(), sortedProperties.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
            return a.second > b.second;
        });

        // Display the top 10 favorite properties along with their counts
        cout << "\n--- TOP 10 FAVORITE PROPERTIES ---" << endl;
        int count = 0;
        for (const auto &entry : sortedProperties)
        {
            if (count >= 10)
            {
                break;
            }
            cout << "AdsID: " << entry.first << ", Favorite Count: " << entry.second << endl;
            count++;
        }
        cout << "-----------------------------------" << endl;
    }

};

#endif // PROPERTY_H