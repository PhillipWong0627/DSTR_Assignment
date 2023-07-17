#include <iostream>
// #include <iomanip>
// #include <limits>
#include <string>
#include <chrono>
#include <sstream>
// #include <fstream>
// #include <sstream>

# include "CustomerClass.h"

using namespace std;

bool CustomerClass::userNameExist(CusNode* cusHead, string userName) {
    CusNode* curr = cusHead;
    while (curr!=NULL) {
        if (curr->userName== userName) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool CustomerClass::feedbackIDExist(FeedbackNode* feedbackHead, string feedbackID) {
    FeedbackNode* curr = feedbackHead;
    while (curr != NULL) {
        if (curr->feedbackID == feedbackID) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

string CustomerClass::returnDate() {
    //dealing with date
    // current date/time based on current system
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm tm;
    gmtime_s(&tm, &t);

    // concatenate individual components of the date into a string
    ostringstream oss;
    oss << tm.tm_mday << '/'
        << tm.tm_mon + 1 << '/'
        << tm.tm_year + 1900;
    string date_str = oss.str();
    return date_str;
}

void CustomerClass::registerCustomer(CusNode* cusHead)
{
    string userName, password, name, accCreatedDate, lastLoginDate;
    int age;
    system("cls");
    cout << endl;
    cout << "Customer Registration" << endl;
    cout << string(50, '-') << endl;

    cout << "Please enter username: ";
    getline(cin >> ws, userName);

    while (userNameExist(cusHead,userName)) {
        cout << "Username - " << userName << " exist!!" << endl;
        cout << "Please enter username: ";
        getline(cin >> ws, userName);
    }

    cout << "Please enter password: ";
    cin >> password;

    cout << "Please enter name: ";
    getline(cin >> ws, name);

    cout << "Please enter age: ";
    cin >> age;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << "Please enter number!" << endl;
        cout << "Please enter age: ";
        cin >> age;
    }

    
    accCreatedDate = returnDate();
    lastLoginDate = returnDate();
    system("cls");
    // add to linked-list
    LinkedList* linkedList = new LinkedList;
    linkedList->insertNodeAtTheEndCus(&cusHead, userName, password, name, age, accCreatedDate, lastLoginDate);
    cout << "Register successfully!" << endl;
}

bool CustomerClass::cusLogin(CusNode* cusHead) {
    string userName, password;

    cout << "Please enter username: ";
    getline(cin >> ws, userName);

    cout << "Please enter password: ";
    cin >> password;
    CusNode* curr = cusHead;
    while (curr != NULL) {
        if ((curr->userName == userName) && (curr->password==password)) {
            curr->lastLoginDate = returnDate();
            setUserName(userName);
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool CustomerClass::checkRankExistInFavList(FavNode* favHead, int rank) {
    FavNode* curr = favHead;
    while (curr!=NULL) {
        if (curr->rank == rank) {
            curr->number = curr->number + 1;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void CustomerClass::saveAsFav(FavNode* favHead) {
    int rank;
    cout << "Please enter University rank that you liked: ";
    cin >> rank;
    while (cin.fail() || rank < 1 || rank > 1422)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << "Please enter number (1-1422)!" << endl;
        cout << "Please enter University rank that you liked: ";
        cin >> rank;
    }
    if(checkRankExistInFavList(favHead, rank)) {
        system("cls");
        cout << "Save successfully!" << endl<<endl;
    }
    else {
        LinkedList* linkedList = new LinkedList;
        linkedList->addFavNode(&favHead,rank, 1);
        system("cls");
        cout << "Save successfully!" << endl << endl;
    }
}

void CustomerClass::sendFeedback(string userName, FeedbackNode*& feedbackHead) {
    string feedbackID, message, reply, sendDate, replyDate;

    cout << "Please enter feedbackID: ";
    cin >> feedbackID;

    while (feedbackIDExist(feedbackHead,feedbackID)) {
        cout << "FeedbackID - " << feedbackID << " exist!!" << endl;
        cout << "Please enter feedbackID: ";
        cin >> feedbackID;
    }

    cout << "Please enter message: ";
    getline(cin >> ws, message);

    reply = "-";

    sendDate = returnDate();

    replyDate = "-";

    Stack* stackPush = new Stack("Feedback Stack");
    stackPush->Push(&feedbackHead,feedbackID, userName, message, reply, sendDate, replyDate);
}

void CustomerClass::readFeedback(string userName, FeedbackNode* feedbackHead) {
    FeedbackNode* curr = feedbackHead;
    while (curr!= NULL) {
        if (curr->userName == userName) {
            cout << endl;
            cout << "FeedbackID: " << curr->feedbackID << endl;
            cout << "Username: " << curr->userName << endl;
            cout << "Message: " << curr->message << endl;
            cout << "Reply: " << curr->reply << endl;
            cout << "Customer Send Date: " << curr->sendDate << endl;
            cout << "Admin Reply Date: " << curr->replyDate << endl;
            cout << endl;
        }
        curr = curr->next;
    }
    system("pause");
    system("cls");
}

string CustomerClass::getUserName() {
    return userName;
}

void CustomerClass::setUserName(string userName) {
    this->userName = userName;
}



// ~CustomerClass(){
//     cout<<"deleted"<<endl;
// }

