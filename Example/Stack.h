#ifndef STACK_H
#define STACK_H
#pragma once

#include <iostream>
#include "LinkedList.h"

using namespace std;

class Stack {
	
	string stackName = "";

public:
	int size = 0;
	// Constructor
	Stack(string stackName) {
		this->stackName = stackName;
	}
	// Function
	bool isEmpty(FeedbackNode* feedbackHead);
	void Push(FeedbackNode** feedbackHead, string feedbackID, string userName, string message, string reply, string sendDate, string replyDate);
	FeedbackNode* Peek(FeedbackNode* feedbackHead); // to know which is the top item without taking out
};

#endif
