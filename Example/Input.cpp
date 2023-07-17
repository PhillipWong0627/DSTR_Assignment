#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

#include "Input.h"

using namespace std;

string Input::changeComma(string str) {
	int count = 0, cnt = 0;
	for (int j = 0; j < size(str); j++) {
		if (str[j] == ',') {
			count += 1;
		}
	}
	if (count >= 21) {
		for (int i = 0; i < size(str); i++) {
			if (str[i] == ',') {
				cnt += 1;
				if (cnt == 2) {
					str[i] = '.';
					break;
				}
			}
		}
	}
	return str;
}

Node* Input::inputUniInfo() {

	LinkedList* linkedList=new LinkedList;;

	string filename = "2023 QS World University Rankings.csv";
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "File " << filename << " not found!!" << endl;
		return 0;
	}

	string line;
	Node* head = NULL;
	int lineCount = 0;
	getline(file, line);
	while (getline(file, line))
	{
		// deal with comma problem
		string res = changeComma(line);
		if (lineCount==1271) {
			int cnt = 0;
			for (int i = 0; i < size(res); i++) {
				if (res[i] == ',') {
					cnt += 1;
					if (cnt == 2) {
						res[i] = '.';
						break;
					}
				}
			}
		}
		/*,'Manipal Academy of Higher Education. Manipal, Karnataka, India'*/
		if (lineCount == 770) {
			int cnt = 0;
			for (int i = 0; i < size(res); i++) {
				if (res[i] == ',') {
					cnt += 1;
					if (cnt>1 && cnt < 4) {
						res[i] = '.';
					}
					else if (cnt==1) {
						continue;
					}
					else {
						break;
					}
				}
			}
		}
		// end of "deal with comma problem"

		// Parse the CSV line into individual fields
		stringstream ss(res);
		string rank, institution, locationCode,
			location, arScore, arRank,
			erScore, erRank, fsrScore,
			fsrRank, cpfScore, cpfRank,
			ifrScore, ifrRank, isrScore,
			isrRank, irnScore, irnRank,
			gerScore, gerRank, scoreScaled;

		getline(ss, rank, ',');
		getline(ss, institution, ',');
		getline(ss, locationCode, ',');
		getline(ss, location, ',');
		getline(ss, arScore, ',');
		getline(ss, arRank, ',');
		getline(ss, erScore, ',');
		getline(ss, erRank, ',');
		getline(ss, fsrScore, ',');
		getline(ss, fsrRank, ',');
		getline(ss, cpfScore, ',');
		getline(ss, cpfRank, ',');
		getline(ss, ifrScore, ',');
		getline(ss, ifrRank, ',');
		getline(ss, isrScore, ',');
		getline(ss, isrRank, ',');
		getline(ss, irnScore, ',');
		getline(ss, irnRank, ',');
		getline(ss, gerScore, ',');
		getline(ss, gerRank, ',');
		getline(ss, scoreScaled, ',');

		// Insert a new node for this row into the linked list
		int Intrank = stoi(rank);
		linkedList->insertNodeAtTheEndUni(&head, Intrank, institution, locationCode,
			location, arScore, arRank,
			erScore, erRank, fsrScore,
			fsrRank, cpfScore, cpfRank,
			ifrScore, ifrRank, isrScore,
			isrRank, irnScore, irnRank,
			gerScore, gerRank, scoreScaled);
		lineCount += 1;
	}
	delete linkedList;
	return head;
}

CusNode* Input::inputCusInfo() {
	LinkedList* linkedList=new LinkedList;

	string filename = "cusInfo.txt";
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "File " << filename << " not found!!" << endl;
		return 0;
	}

	string line;
	CusNode* head = NULL;
	getline(file, line);
	while (getline(file, line))
	{
		// Parse the CSV line into individual fields
		stringstream ss(line);
		string userName, password, name,age, accCreatedDate, lastLoginDate;

		getline(ss, userName, ';');
		getline(ss, password, ';');
		getline(ss, name, ';');
		getline(ss, age, ';');
		getline(ss, accCreatedDate, ';');
		getline(ss, lastLoginDate, ';');

		int Intage = stoi(age);
		// Insert a new node for this row into the linked list
		linkedList->insertNodeAtTheEndCus(&head, userName, password, name, Intage, accCreatedDate, lastLoginDate);
	}
	delete linkedList;
	return head;
}

AdmNode* Input::inputAdmInfo() {
	LinkedList* linkedList = new LinkedList;

	string filename = "admInfo.txt";
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "File " << filename << " not found!!" << endl;
		return 0;
	}

	string line;
	AdmNode* head = NULL;
	getline(file, line);
	while (getline(file, line))
	{
		// Parse the CSV line into individual fields
		stringstream ss(line);
		string userName, password, name, age;

		getline(ss, userName, ';');
		getline(ss, password, ';');
		getline(ss, name, ';');
		getline(ss, age, ';');

		int Intage = stoi(age);
		// Insert a new node for this row into the linked list
		linkedList->insertNodeAtTheEndAdm(&head, userName, password, name, Intage);
	}
	delete linkedList;
	return head;
}

FavNode* Input::inputFavUniInfo() {
	LinkedList* linkedList = new LinkedList;

	string filename = "favouriteUni.txt";
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "File " << filename << " not found!!" << endl;
		return 0;
	}

	string line;
	FavNode* head = NULL;
	FavNode* tail = NULL;
	getline(file, line);
	while (getline(file, line))
	{
		// Parse the CSV line into individual fields
		stringstream ss(line);
		string rank,number;

		getline(ss, rank, ';');
		getline(ss, number, ';');

		int Intrank = stoi(rank);
		int Intnumber = stoi(number);

		// Insert a new node for this row into the linked list
		linkedList->insertNodeAtTheEndFav(&head,&tail,Intrank, Intnumber);
	}
	delete linkedList;
	return head;
}

FeedbackNode* Input::inputFeedbackInfo() {
	
	Stack* feedbackStack = new Stack("Feedback Stack");
	string filename = "feedback.txt";
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "File " << filename << " not found!!" << endl;
		return 0;
	}

	string line;
	FeedbackNode* head = NULL;

	getline(file, line);
	while (getline(file, line))
	{
		// Parse the CSV line into individual fields
		stringstream ss(line);
		string feedbackID, userName, message, reply, sendDate, replyDate;

		getline(ss, feedbackID, ';');
		getline(ss, userName, ';');
		getline(ss, message, ';');
		getline(ss, reply, ';');
		getline(ss, sendDate, ';');
		getline(ss, replyDate, ';');

		// Push a new node into the linked list (Stack)
		feedbackStack->Push(&head,feedbackID, userName,message, reply, sendDate, replyDate);
	}

	return head;

}
