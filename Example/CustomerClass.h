#ifndef CUSTOMERCLASS_H
#define CUSTOMERCLASS_H
#pragma once

#include <iostream>
// #include <iomanip>
#include <string>

#include "LinkedList.h"
#include "Stack.h"
#include "Input.h"

using namespace std;

class CustomerClass {
private:
    string userName;
public:

    string getUserName();
    void setUserName(string userName);
    bool userNameExist(CusNode* cusHead, string userName);
    bool feedbackIDExist(FeedbackNode* feedbackHead, string feedbackID);
    string returnDate();
    void registerCustomer(CusNode* cusHead);
    bool cusLogin(CusNode* cusHead);
    bool checkRankExistInFavList(FavNode* favHead,int rank);
    void saveAsFav(FavNode* favHead);
    void sendFeedback(string userName, FeedbackNode*& feedbackHead);
    void readFeedback(string userName, FeedbackNode* feedbackHead);
    
    
    // ~CustomerClass(){
    //     cout<<"deleted"<<endl;
    // }

};

#endif