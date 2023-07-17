#ifndef ADMINCLASS_H
#define ADMINCLASS_H
#pragma once

#include <iostream>
// #include <iomanip>
#include <string>

#include "LinkedList.h"
#include "InsertionSort.h"
#include "CustomerClass.h"

using namespace std;

class AdminClass {

public:
	bool admLogin(AdmNode* admHead);
	void displayRegisteredCus(CusNode* cusHead);
	void modifyCus(CusNode* cusHead);
	int dateDiff(string start_date_str, string end_date_str);
	void displayInactiveCus(CusNode* cusHead);
	void deleteAcc(CusNode*& cusHead);
	void summarizeUni(FavNode* favHead);
	void readFeedback(FeedbackNode* feedbackHead);
	void replyFeedback(FeedbackNode* feedbackHead);
};

#endif