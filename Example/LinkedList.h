#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once
#include <iostream>
// #include <iomanip>
// #include <limits>
// #include <string>
// #include <fstream>
// #include <sstream>

using namespace std;

// Define a node for the linked list
struct Node
{
	int rank;
	string institution;
	string locationCode;
	string location;
	string arScore;
	string arRank;
	string erScore;
	string erRank;
	string fsrScore;
	string fsrRank;
	string cpfScore;
	string cpfRank;
	string ifrScore;
	string ifrRank;
	string isrScore;
	string isrRank;
	string irnScore;
	string irnRank;
	string gerScore;
	string gerRank;
	string scoreScaled;

	Node* next;
};

struct CusNode
{
	string userName;
	string password;
	string name;
	int age;
	string accCreatedDate;
	string lastLoginDate;

	CusNode* next;
};

struct AdmNode
{
	string userName;
	string password;
	string name;
	int age;

	AdmNode* next;
};

// concept of hash map, map key (rank) to value (number)
struct FavNode
{
	int rank;
	int number;

	FavNode* next;
};

struct FeedbackNode
{
	string feedbackID;
	string userName;
	string message;
	string reply;
	string sendDate;
	string replyDate;

	FeedbackNode* next;
	FeedbackNode* prev;
};

class LinkedList {
public:
	void insertNodeAtTheEndUni(Node** head, int rank, string institution, string locationCode,
		string location, string arScore, string arRank,
		string erScore, string erRank, string fsrScore,
		string fsrRank, string cpfScore, string cpfRank,
		string ifrScore, string ifrRank, string isrScore,
		string isrRank, string irnScore, string irnRank,
		string gerScore, string gerRank, string scoreScaled);
	void insertNodeAtTheEndCus(CusNode** head, string userName, string password, string name, 
		int age, string accCreatedDate, string lastLoginDate);
	void insertNodeAtTheEndAdm(AdmNode** head, string userName, string password, string name, int age);
	void insertNodeAtTheEndFav(FavNode** head, FavNode** tail,int rank, int number);
	void addFavNode(FavNode** head,int rank, int number);
	//void insertNodeAtTheFrontFeedback(FeedbackNode** head, string feedbackID,string userName, 
	//string message,string reply,string sendDate,string replyDate);
	Node* clone(Node* head);
	FavNode* cloneFav(FavNode* head);
};

# endif