#include <iostream>
#include <fstream>

#include "Stack.h"

using namespace std;

void Stack::Push(FeedbackNode** feedbackHead, string feedbackID, string userName, string message, string reply, string sendDate, string replyDate) {
	FeedbackNode* newNode = new FeedbackNode;
	newNode->feedbackID = feedbackID;
	newNode->userName = userName;
	newNode->message = message;
	newNode->reply = reply;
	newNode->sendDate = sendDate;
	newNode->replyDate = replyDate;

	newNode->prev = NULL;
	newNode->next = NULL;

	if (*feedbackHead == NULL) {
		*feedbackHead = newNode;
	}
	else {
		newNode->next = *feedbackHead;
		(*feedbackHead)->prev = newNode;
		*feedbackHead = newNode;
	}
	size++;
}

//bool Stack::isEmpty(FeedbackNode* feedbackHead) {
//	if (feedbackHead == NULL)
//		return true;
//	return false;
//}
//
//FeedbackNode* Stack::Peek(FeedbackNode* feedbackHead) {
//	FeedbackNode* data;
//	if (isEmpty(feedbackHead)) {
//		return data;
//	}
//	return feedbackHead; // return node
//}
