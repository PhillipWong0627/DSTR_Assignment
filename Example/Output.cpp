#include <iostream>
#include <fstream>

#include "Output.h"

using namespace std;

void Output::writeCusListToFile(CusNode* head,const string& filename) {
    ofstream outFile(filename, ios::trunc);
    if (!outFile) {
        cerr << "Unable to open file " << filename << endl;
        return;
    }

    const CusNode* curr = head;
    outFile << "userName;password;name;age;accCreatedDate;lastLoginDate" << endl;
    while (curr != NULL) {
        outFile << curr->userName << ';' << curr->password << ';' << curr->name << ';' << curr->age << ';' << curr->accCreatedDate << ';' << curr->lastLoginDate << endl;
        curr = curr->next;
    }

    outFile.close();
}

void Output::writeFavListToFile(FavNode* head, const string& filename) {
    ofstream outFile(filename, ios::trunc);
    if (!outFile) {
        cerr << "Unable to open file " << filename << endl;
        return;
    }

    const FavNode* curr = head;
    outFile << "rank;number" << endl;
    while (curr != NULL) {
        outFile << curr->rank << ';' << curr->number << endl;
        curr = curr->next;
    }

    outFile.close();
}

void Output::writeFeedbackListToFile(FeedbackNode* head, const string& filename) {
    ofstream outFile(filename, ios::trunc);
    if (!outFile) {
        cerr << "Unable to open file " << filename << endl;
        return;
    }

    const FeedbackNode* curr = head;

    outFile << "feedbackID;userName;message;reply;sendDate;replyDate" << endl;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    while (curr != NULL) {
        outFile << curr->feedbackID << ';' << curr->userName << ';' << curr->message << ';' << curr->reply << ';' << curr->sendDate << ';' << curr->replyDate << endl;
        curr = curr->prev;
    }

    outFile.close();
}