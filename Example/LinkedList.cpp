#include <iostream>
// #include <iomanip>
// #include <limits>
// #include <string>
// #include <fstream>
// #include <sstream>

#include "LinkedList.h"
using namespace std;

void LinkedList::insertNodeAtTheEndUni(Node** head, int rank, string institution, string locationCode,
	string location, string arScore, string arRank,
	string erScore, string erRank, string fsrScore,
	string fsrRank, string cpfScore, string cpfRank,
	string ifrScore, string ifrRank, string isrScore,
	string isrRank, string irnScore, string irnRank,
	string gerScore, string gerRank, string scoreScaled)
{

	Node* newNode = new Node;

	newNode->rank = rank;
	newNode->institution = institution;
	newNode->locationCode = locationCode;
	newNode->location = location;
	newNode->arScore = arScore;
	newNode->arRank = arRank;
	newNode->erScore = erScore;
	newNode->erRank = erRank;
	newNode->fsrScore = fsrScore;
	newNode->fsrRank = fsrRank;
	newNode->cpfScore = cpfScore;
	newNode->cpfRank = cpfRank;
	newNode->cpfScore = cpfScore;
	newNode->cpfRank = cpfRank;
	newNode->ifrScore = ifrScore;
	newNode->ifrRank = ifrRank;
	newNode->isrScore = isrScore;
	newNode->isrRank = isrRank;
	newNode->gerScore = gerScore;
	newNode->gerRank = gerRank;
	newNode->scoreScaled = scoreScaled;

	newNode->next = NULL;
	// If linked list is empty, newNode will be a head node
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		Node* curr = *head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		// Insert newNode after last node (at the end)
		curr->next = newNode;
	}
}

void LinkedList::insertNodeAtTheEndCus(CusNode** head, string userName, string password, string name, int age, string accCreatedDate, string lastLoginDate) {
	CusNode* newNode = new CusNode;

	newNode->userName = userName;
	newNode->password = password;
	newNode->name = name;
	newNode->age = age;
	newNode->accCreatedDate = accCreatedDate;
	newNode->lastLoginDate = lastLoginDate;

	newNode->next = NULL;
	// If linked list is empty, newNode will be a head node
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		CusNode* curr = *head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		// Insert newNode after last node (at the end)
		curr->next = newNode;
	}
}

void LinkedList::insertNodeAtTheEndAdm(AdmNode** head, string userName, string password, string name, int age) {
	AdmNode* newNode = new AdmNode;

	newNode->userName = userName;
	newNode->password = password;
	newNode->name = name;
	newNode->age = age;

	newNode->next = NULL;
	// If linked list is empty, newNode will be a head node
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		AdmNode* curr = *head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		// Insert newNode after last node (at the end)
		curr->next = newNode;
	}
}

void LinkedList::insertNodeAtTheEndFav(FavNode** head, FavNode** tail,int rank, int number) {
	FavNode* newNode = new FavNode;

	newNode->rank = rank;
	newNode->number = number;

	newNode->next = NULL;
	// If linked list is empty, newNode will be a head node
	if (*head == NULL)
	{
		*head = *tail = newNode;
	}
	else
	{
		(*tail)->next = newNode;
		(*tail) = newNode;
	}
}

void LinkedList::addFavNode(FavNode** head, int rank, int number) {
	FavNode* newNode = new FavNode;

	newNode->rank = rank;
	newNode->number = number;

	newNode->next = NULL;
	// If linked list is empty, newNode will be a head node
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		FavNode* curr = *head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		// Insert newNode after last node (at the end)
		curr->next = newNode;
	}
}

Node* LinkedList::clone(Node* head) {
	if (head == NULL) return NULL;

	Node* result = new Node;

	result->rank = head->rank;
	result->institution = head->institution;
	result->locationCode = head->locationCode;
	result->location = head->location;
	result->arScore = head->arScore;
	result->arRank = head->arRank;
	result->erScore = head->erScore;
	result->erRank = head->erRank;
	result->fsrScore = head->fsrScore;
	result->fsrRank = head->fsrRank;
	result->cpfScore = head->cpfScore;
	result->cpfRank = head->cpfRank;
	result->cpfScore = head->cpfScore;
	result->cpfRank = head->cpfRank;
	result->ifrScore = head->ifrScore;
	result->ifrRank = head->ifrRank;
	result->isrScore = head->isrScore;
	result->isrRank = head->isrRank;
	result->gerScore = head->gerScore;
	result->gerRank = head->gerRank;
	result->scoreScaled = head->scoreScaled;

	if (result->fsrScore == "") {
		result->fsrScore = "0";
	}
	else if (result->erScore == "") {
		result->erScore = "0";
	}

	result->next = clone(head->next);
	return result;
}

FavNode* LinkedList::cloneFav(FavNode* head) {
	if (head == NULL) return NULL;

	FavNode* result = new FavNode;

	result->rank = head->rank;
	result->number = head->number;
	
	result->next = cloneFav(head->next);
	return result;
}


