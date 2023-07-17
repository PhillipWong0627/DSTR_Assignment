#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono> //time library

#include "LinkedList.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "CustomerClass.h"
#include "AdminClass.h"
#include "Input.h"
#include "BinarySearch.h"
#include "Output.h"
# include "LinearSearch.h"

using namespace std;
using namespace std::chrono;

void mainMenu(Node* head, CusNode*& cusHead,AdmNode* admHead,FavNode* favHead, FeedbackNode*& feedbackHead);
void cusMenu(string userName,Node* head, CusNode* cushead, FavNode* favHead, FeedbackNode*& feedbackHead);
void adminMenu(Node* head, CusNode*& cusHead, FavNode* favHead, FeedbackNode* feedbackHead);
void displaySpecific(Node* n);
void displayUniInfo(Node* n);
void choiceOfSortUniByName(Node* head);
void choiceOfSearchUniDetail(Node* head);
int choiceOfAttr();
double enterSearchValue();
void displayForAr(Node* n, double value);
void displayForFsr(Node* n, double value);
void displayForEr(Node* n, double value);

int main()
{
	Input* inputUni = new Input;
	Node* uniHead = inputUni->inputUniInfo();
	delete inputUni;

	Input* inputCus = new Input;
	Output* outputCus = new Output;
	CusNode* cusHead = inputCus->inputCusInfo();
	delete inputCus;

	Input* inputAdm = new Input;
	AdmNode* admHead = inputAdm->inputAdmInfo();
	delete inputAdm;

	Input* inputFav = new Input;
	Output* outputFav = new Output;
	FavNode* favHead = inputFav->inputFavUniInfo();
	delete inputFav;
	/*FavNode* curr = favHead;
	while (curr!=NULL) {
		cout << curr->rank <<" "<<curr->number << endl;
		curr = curr->next;
	}*/

	Input* inputFeedback = new Input;
	Output* outputFeedback = new Output;
	FeedbackNode* feedbackHead = inputFeedback->inputFeedbackInfo();
	delete inputFeedback;
	/*FeedbackNode* curr = feedbackHead;
	while (curr!=NULL) {
		cout << curr->feedbackID <<" "<<curr->userName << endl;
		curr = curr->next;
	}*/


	mainMenu(uniHead, cusHead,admHead, favHead, feedbackHead);

	outputCus->writeCusListToFile(cusHead,"cusInfo.txt");
	outputFav->writeFavListToFile(favHead, "favouriteUni.txt");
	outputFeedback->writeFeedbackListToFile(feedbackHead,"feedback.txt");
	return 0;
}

void mainMenu(Node* head,CusNode*& cusHead, AdmNode* admHead, FavNode* favHead, FeedbackNode*& feedbackHead)
{
	int choice = 0;
	while (true)
	{
		cout << endl;
		cout << "Welcome to the UniSystem" << endl;
		cout << string(50, '-') << endl;
		cout << "1. Display universities' information" << endl;
		cout << "2. Sort university information in ascending order by university name" << endl;
		cout << "3. Search individual university details" << endl;
		cout << "4. Registration" << endl;
		cout << "5. Login as customer" << endl;
		cout << "6. Login as admin" << endl;
		cout << "7. Display Specific University" << endl;
		cout << "8. Exit" << endl;
		cout << "Please select: ";
		cin >> choice;

		while (cin.fail() || choice < 1 || choice > 8)
		{
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect input!";
			cout << endl;
			cout << "Welcome to the UniSystem" << endl;
			cout << string(50, '-') << endl;
			cout << "1. Display universities' information" << endl;
			cout << "2. Sort university information in ascending order by university name" << endl;
			cout << "3. Search individual university details" << endl;
			cout << "4. Registration" << endl;
			cout << "5. Login as customer" << endl;
			cout << "6. Login as admin" << endl;
			cout << "7. Display Specific University" << endl;
			cout << "8. Exit" << endl;
			cout << "Please select: ";
			cin >> choice;
		}
		
		if (choice == 1)
		{
			displayUniInfo(head);
		}
		else if (choice == 2)
		{
			choiceOfSortUniByName(head);
		}
		else if (choice == 3)
		{
			choiceOfSearchUniDetail(head);
		}
		else if (choice == 4)
		{
			CustomerClass* customerClass = new CustomerClass;
			customerClass->registerCustomer(cusHead);
			delete customerClass;
		}
		else if (choice == 5)
		{
			CustomerClass* customerLogin = new CustomerClass;
			if (customerLogin->cusLogin(cusHead)) {
				system("cls");
				cout << "Login successfully!" << endl;
				cout << "Welcome back " << customerLogin->getUserName()<<"!" << endl<<endl;
				cusMenu(customerLogin->getUserName(),head,cusHead, favHead, feedbackHead);
			}else {
				system("cls");
				cout << "Incorrect username or password!" << endl;
			}
			delete customerLogin;
			
		}
		else if (choice == 6)
		{
			AdminClass* adminLogin = new AdminClass;
			if (adminLogin->admLogin(admHead)) {
				system("cls");
				cout << "Login successfully!" << endl;
				adminMenu(head, cusHead, favHead, feedbackHead);
			}
			else {
				system("cls");
				cout << "Incorrect username or password!" << endl;
			}
			delete adminLogin;
		}
		else if (choice == 7)
		{
			displaySpecific(head);
		}
		else if (choice == 8)
		{
			return;
		}
	}
}

void cusMenu(string userName,Node* head, CusNode* cusHead, FavNode* favHead, FeedbackNode*& feedbackHead) {
	Node* sortedAr;
	LinkedList linkedList;

	while (true) {
		Node* temp = linkedList.clone(head);
		int choice;
		
		cout << "1. Sort university information in descending order" << endl;
		cout << "2. Search universities details" << endl;
		cout << "3. Save favorite universities" << endl;
		cout << "4. Send feedback to MoHE" << endl;
		cout << "5. Read feedback reply" << endl;
		cout << "6. Display Specific Unversity" << endl;
		cout << "7. Logout" << endl;
		cout << "Please select: ";
		cin >> choice;
		while (cin.fail() || choice < 1 || choice > 7)
		{
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect input!";
			cout << endl;
			cout << "Welcome back!" << endl;
			cout << "1. Sort university information in descending order" << endl;
			cout << "2. Search universities details" << endl;
			cout << "3. Save favorite universities" << endl;
			cout << "4. Send feedback to MoHE" << endl;
			cout << "5. Read feedback reply" << endl;
			cout << "6. Display Specific Unversity" << endl;
			cout << "7. Logout" << endl;
			cout << "Please select: ";
			cin >> choice;
		}
		if (choice == 1) {
			MergeSort* mergeSort = new MergeSort;
			sortedAr = mergeSort->mergeSort(temp, 1, "arFsrEr");
			delete mergeSort;
			displayUniInfo(sortedAr);
			delete temp;
		}
		else if (choice == 2) {
			choiceOfSearchUniDetail(head);
		}
		else if (choice == 3) {
			CustomerClass* saveFav = new CustomerClass;
			saveFav->saveAsFav(favHead);
		}
		else if (choice == 4) {
			CustomerClass* sendFeedback = new CustomerClass;
			sendFeedback->sendFeedback(userName, feedbackHead);
		}
		else if (choice == 5) {
			CustomerClass* readFeedback = new CustomerClass;
			readFeedback->readFeedback(userName, feedbackHead);
		}
		else if (choice == 6) {
			displaySpecific(head);
		}
		else if (choice == 7) {
			system("cls");
			cout << "Logout successfully!" << endl;
			return;
		}
	}
}

void adminMenu(Node* head, CusNode*& cusHead, FavNode* favHead, FeedbackNode* feedbackHead) {
	while (true) {

		int choice;
		cout << "Welcome back Admin!" << endl;
		cout << "1. Display registered users" << endl;
		cout << "2. Modify user details" << endl;
		cout << "3. Delete user account" << endl;
		cout << "4. Read users feedback reply" << endl;
		cout << "5. Reply users feedbacks" << endl;
		cout << "6. Summarize TOP10 university" << endl;
		cout << "7. Display Specific University" << endl;
		cout << "8. Logout" << endl;
		cout << "Please select: ";
		cin >> choice;
		while (cin.fail() || choice < 1 || choice > 8)
		{
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect input!";
			cout << endl;
			cout << "Welcome back Admin!" << endl;
			cout << "1. Display registered users" << endl;
			cout << "2. Modify user details" << endl;
			cout << "3. Delete user account" << endl;
			cout << "4. Read users feedback reply" << endl;
			cout << "5. Reply users feedbacks" << endl;
			cout << "6. Summarize TOP10 university" << endl;
			cout << "7. Display Specific University" << endl;
			cout << "8. Logout" << endl;
			cout << "Please select: ";
			cin >> choice;
		}
		if (choice == 1) {
			AdminClass* adminClass = new AdminClass;
			adminClass->displayRegisteredCus(cusHead);
		}
		else if (choice == 2) {
			AdminClass* adminClass = new AdminClass;
			adminClass->modifyCus(cusHead);
		}
		else if (choice == 3) {
			AdminClass* adminClass = new AdminClass;
			adminClass->displayInactiveCus(cusHead);
			adminClass->deleteAcc(cusHead);
		}
		else if (choice == 4) {
			AdminClass* adminClass = new AdminClass;
			adminClass->readFeedback(feedbackHead);
		}
		else if (choice == 5) {
			AdminClass* adminClass = new AdminClass;
			adminClass->replyFeedback(feedbackHead);
		}
		else if (choice == 6) {
			// clone Fav list
			LinkedList* ls = new LinkedList;
			FavNode* temp = ls->cloneFav(favHead);
			// summarize top 10 uni
			AdminClass* summarize = new AdminClass;
			summarize->summarizeUni(temp);
		}
		else if (choice == 7) {
			displaySpecific(head);
		}
		else if (choice == 8) {
			system("cls");
			cout << "Logout successfully!" << endl;
			return;
		}
	}
}

void displaySpecific(Node* n) {
	int choice;
	cout << "What university rank you want look into (-999 to reject): ";
	cin >> choice;
	if (choice == -999) {
		return;
	}
	while (cin.fail() || choice < 1 || choice > 1422)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
		cout << "Please enter number (1-1422)!" << endl;
		cout << "What university rank you want look into (-999 to reject): ";
		cin >> choice;
		if (choice == -999) {
			return;
		}
	}
	Node* curr = n;
	while (curr!=NULL) {
		if (curr->rank == choice) {
			cout << endl;
			cout << "Rank: " << curr->rank << endl;
			cout << "Institution: " << curr->institution << endl;
			cout << "Location Code: " << curr->locationCode << endl;
			cout << "Location: " << curr->location << endl;
			cout << "ArScore: " << curr->arScore << endl;

			cout << "ArRank: " << curr->arRank << endl;
			cout << "ErScore: " << curr->erScore << endl;
			cout << "ErRank: " << curr->erRank << endl;
			cout << "FsrScore: " << curr->fsrScore << endl;
			cout << "FsrRank: " << curr->fsrRank << endl;

			cout << "CpfScore: " << curr->cpfScore << endl;
			cout << "CpfRank: " << curr->cpfRank << endl;
			cout << "IfrScore: " << curr->ifrScore << endl;
			cout << "IfrRank: " << curr->ifrRank << endl;
			cout << "IsrScore: " << curr->isrScore << endl;

			cout << "IsrRank: " << curr->isrRank << endl;
			cout << "IrnScore: " << curr->irnScore << endl;
			cout << "IrnRank: " << curr->irnRank << endl;
			cout << "GerScore: " << curr->gerScore << endl;
			cout << "GerRank: " << curr->gerRank << endl;

			cout << "ScoreScaled: " << curr->scoreScaled << endl;
			cout << endl;
			system("pause");
			system("cls");
			return;
		}
		curr = curr->next;
	}
}

void displayUniInfo(Node* n)
{
	char cont;
	cout << string(175, '-') << endl;
	cout << "|" << setw(4) << "Rank|" << setw(91) << "Institution|" << setw(26) << "ArScore|";
	cout << setw(26) << "FsrScore|" << setw(26) << "ErScore|";
	cout << endl;
	cout << string(175, '-') << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << "|" << setw(4) << n->rank << "|" << setw(90) << n->institution << "|" << setw(25) << n->arScore << "|";
		cout << setw(25) << n->fsrScore << "|" << setw(25) << n->erScore << "|";
		cout << endl;
		n = n->next;
		if (n==NULL) {
			cout << "Display completed!" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (i == 19) {
			cout << "Do you want to continue (y/n): ";
			cin >> cont;
			if ((cont == 'y') || (cont == 'Y')) {
				i = -1;
				continue;
			}else{
				system("cls");
				return;
			}
		}
	}
}

void displayForAr(Node* n,double value)
{
	char cont;
	cout << string(175, '-') << endl;
	cout << "|" << setw(4) << "Rank|" << setw(91) << "Institution|" << setw(26) << "ArScore|";
	cout << setw(26) << "FsrScore|" << setw(26) << "ErScore|";
	cout << endl;
	cout << string(175, '-') << endl;
	for (int i = 0; i < 20; i++)
	{
		if (stod(n->arScore) == value) {
			cout << "|" << setw(4) << n->rank << "|" << setw(90) << n->institution << "|" << setw(25) << n->arScore << "|";
			cout << setw(25) << n->fsrScore << "|" << setw(25) << n->erScore << "|";
			cout << endl;
			n = n->next;
			if (n == NULL) {
				cout << "Display completed!" << endl;
				system("pause");
				system("cls");
				return;
			}
			if (i == 19) {
				cout << "Do you want to continue (y): ";
				cin >> cont;
				if ((cont == 'y') || (cont == 'Y')) {
					i = -1;
					continue;
				}
				else {
					system("cls");
					return;
				}
			}
		}
	}
}

void displayForFsr(Node* n, double value)
{
	char cont;
	cout << string(175, '-') << endl;
	cout << "|" << setw(4) << "Rank|" << setw(91) << "Institution|" << setw(26) << "ArScore|";
	cout << setw(26) << "FsrScore|" << setw(26) << "ErScore|";
	cout << endl;
	cout << string(175, '-') << endl;
	for (int i = 0; i < 20; i++)
	{
		if (stod(n->fsrScore) == value) {
			cout << "|" << setw(4) << n->rank << "|" << setw(90) << n->institution << "|" << setw(25) << n->arScore << "|";
			cout << setw(25) << n->fsrScore << "|" << setw(25) << n->erScore << "|";
			cout << endl;
			n = n->next;
			if (n == NULL) {
				cout << "Display completed!" << endl;
				system("pause");
				system("cls");
				return;
			}
			if (i == 19) {
				cout << "Do you want to continue (y): ";
				cin >> cont;
				if ((cont == 'y') || (cont == 'Y')) {
					i = -1;
					continue;
				}
				else {
					system("cls");
					return;
				}
			}
		}
	}
}

void displayForEr(Node* n, double value)
{
	char cont;
	cout << string(175, '-') << endl;
	cout << "|" << setw(4) << "Rank|" << setw(91) << "Institution|" << setw(26) << "ArScore|";
	cout << setw(26) << "FsrScore|" << setw(26) << "ErScore|";
	cout << endl;
	cout << string(175, '-') << endl;
	for (int i = 0; i < 20; i++)
	{
		if (stod(n->erScore) == value) {
			cout << "|" << setw(4) << n->rank << "|" << setw(90) << n->institution << "|" << setw(25) << n->arScore << "|";
			cout << setw(25) << n->fsrScore << "|" << setw(25) << n->erScore << "|";
			cout << endl;
			n = n->next;
			if (n == NULL) {
				cout << "Display completed!" << endl;
				system("pause");
				system("cls");
				return;
			}
			if (i == 19) {
				cout << "Do you want to continue (y): ";
				cin >> cont;
				if ((cont == 'y') || (cont == 'Y')) {
					i = -1;
					continue;
				}
				else {
					system("cls");
					return;
				}
			}
		}
	}
}

void choiceOfSortUniByName(Node* head)
{
	int choice;
	Node* sorted;
	LinkedList linkedList;
	
	while (true) {
		Node* temp = linkedList.clone(head);
		cout << "Which sorting algorithms?" << endl;
		cout << "1. Insertion sort" << endl;
		cout << "2. Merge sort" << endl;
		cout << "3. Back" << endl;
		cout << "Please select: ";
		cin >> choice;
		while (cin.fail() || choice < 1 || choice > 3)
		{
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter 1 - 3!";
			cout << endl;
			cout << "Which sorting algorithms?" << endl;
			cout << "1. Insertion sort" << endl;
			cout << "2. Merge sort" << endl;
			cout << "3. Back" << endl;
			cout << "Please select: ";
			cin >> choice;
		}
		if (choice == 1)
		{
			InsertionSort* insertionSort = new InsertionSort;

			//start timer when want to do the sort part
			auto start = high_resolution_clock::now();

			sorted = insertionSort->insertionSortForUniName(temp, 0);

			//end timer when finish sort part
			auto stop = high_resolution_clock::now();

			//calculate the execution time
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Time taken by Insertion Sort algorithm : ";
			cout << duration.count() << " microseconds. " << endl;

			delete insertionSort;
			displayUniInfo(sorted);
			delete temp;

		}
		else if (choice == 2)
		{
			MergeSort* mergeSort = new MergeSort;

			//start timer when want to do the sort part
			auto start = high_resolution_clock::now();

			sorted = mergeSort->mergeSort(temp, 0, "universityName");

			//end timer when finish sort part
			auto stop = high_resolution_clock::now();

			//calculate the execution time
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Time taken by Merge Sort algorithm : ";
			cout << duration.count() << " microseconds. " << endl;

			delete mergeSort;
			displayUniInfo(sorted);
			delete temp;

		}
		else if (choice == 3)
		{
			system("cls");
			return;
		}
	}
}

void choiceOfSearchUniDetail(Node* head)
{
	int choice;
	Node* sorted;
	Node* searched;
	LinkedList linkedList;
	BinarySearch* bs = new BinarySearch;
	LinearSearch* ls = new LinearSearch;

	while (true) {
		Node* temp = linkedList.clone(head);
		cout << "Which searching algorithms?" << endl;
		cout << "1. Binary Search" << endl;
		cout << "2. Linear Search (Sorted Linkedlist)" << endl;
		cout << "3. Back" << endl;
		cout << "Please select: ";
		cin >> choice;
		while (cin.fail() || choice < 1 || choice > 3)
		{
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter 1 - 3!";
			cout << endl;
			cout << "Which searching algorithms?" << endl;
			cout << "1. Binary Search" << endl;
			cout << "2. Linear Search (Sorted Linkedlist)" << endl;
			cout << "3. Back" << endl;
			cout << "Please select: ";
			cin >> choice;
		}
		if (choice == 1)
		{
			// ArScore
			int attrChoice = choiceOfAttr();
			if (attrChoice==1) {
				MergeSort* mergeSort = new MergeSort;
				sorted = mergeSort->mergeSort(temp, 0, "ar");
				double searchValue = enterSearchValue();
				if(searchValue==-1) {
					return;
				}
				else {
					
					//pass in to the binary search

					//start timer when want to do the search part
					auto start = high_resolution_clock::now();

					searched = bs->binarySearchForAr(sorted, searchValue);

					//end timer when finish search part
					auto stop = high_resolution_clock::now();

					//calculate the execution time
					auto duration = duration_cast<microseconds>(stop - start);
					cout << "Time taken by Binary Search algorithm : ";
					cout << duration.count() << " microseconds. " << endl;

					displayForAr(searched, searchValue);
					system("pause");
					system("cls");
				}
				delete mergeSort;
				delete temp;
			}
			else if (attrChoice == 2) {
				// FsrScore
				MergeSort* mergeSort = new MergeSort;
				sorted = mergeSort->mergeSort(temp, 0, "fsr");

				double searchValue = enterSearchValue();
				if (searchValue == -1) {
					return;
				}
				else {
					//pass in to the binary search
					searched = bs->binarySearchForFsr(sorted, searchValue);
					displayForFsr(searched, searchValue);
					system("pause");
					system("cls");
				}
				delete mergeSort;
				delete temp;
			}
			else if (attrChoice == 3) {
				// ErScore
				MergeSort* mergeSort = new MergeSort;
				sorted = mergeSort->mergeSort(temp, 0, "er");

				double searchValue = enterSearchValue();
				if (searchValue == -1) {
					return;
				}
				else {
					//pass in to the binary search
					searched = bs->binarySearchForEr(sorted, searchValue);
					displayForEr(searched, searchValue);
					system("pause");
					system("cls");
				}
				delete mergeSort;
				delete temp;
			}
		}
		else if (choice == 2)
		{
			// ArScore
			int attrChoice = choiceOfAttr();
			if (attrChoice == 1) {
				MergeSort* mergeSort = new MergeSort;
				sorted = mergeSort->mergeSort(temp, 0, "ar");

				double searchValue = enterSearchValue();
				if (searchValue == -1) {
					return;
				}
				else {

					//pass in to the binary search

					//start timer when want to do the search part
					auto start = high_resolution_clock::now();

					searched = ls->linearSearchForAr(sorted, searchValue);

					//end timer when finish search part
					auto stop = high_resolution_clock::now();

					//calculate the execution time
					auto duration = duration_cast<microseconds>(stop - start);
					cout << "Time taken by Linear Search algorithm : ";
					cout << duration.count() << " microseconds. " << endl;

					if (searched == NULL) {
						system("cls");
						cout << "Value not found!" << endl << endl;
						return;
					}
					displayForAr(searched, searchValue);
					system("pause");
					system("cls");
				}
				delete mergeSort;
				delete temp;
			}
			else if (attrChoice == 2) {
				// FsrScore
				MergeSort* mergeSort = new MergeSort;
				sorted = mergeSort->mergeSort(temp, 0, "fsr");

				double searchValue = enterSearchValue();
				if (searchValue == -1) {
					return;
				}
				else {
					//pass in to the binary search
					searched = ls->linearSearchForFsr(sorted, searchValue);
					if (searched == NULL) {
						system("cls");
						cout << "Value not found!" << endl << endl;
						return;
					}
					displayForFsr(searched, searchValue);
					system("pause");
					system("cls");
				}
				delete mergeSort;
				delete temp;
			}
			else if (attrChoice == 3) {
				// ErScore
				MergeSort* mergeSort = new MergeSort;
				sorted = mergeSort->mergeSort(temp, 0, "er");

				double searchValue = enterSearchValue();
				if (searchValue == -1) {
					return;
				}
				else {
					//pass in to the binary search
					searched = ls->linearSearchForEr(sorted, searchValue);
					if (searched == NULL) {
						system("cls");
						cout << "Value not found!" << endl<<endl;
						return;
					}
					displayForEr(searched, searchValue);
					system("pause");
					system("cls");
				}
				delete mergeSort;
				delete temp;
			}
		}
		else if (choice == 3)
		{
			system("cls");
			return;
		}
	}
	
}

int choiceOfAttr() {
	while (true) {
		int choice;
		cout << "Which attribute you want to search?" << endl;
		cout << "1. ArScore" << endl;
		cout << "2. FsrScore" << endl;
		cout << "3. ErScore" << endl;
		cout << "4. Back" << endl;
		cout << "Please select: ";
		cin >> choice;
		while (cin.fail() || choice < 1 || choice > 4)
		{
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter 1 - 4!";
			cout << endl;
			cout << "Which attribute you want to search?" << endl;
			cout << "1. ArScore" << endl;
			cout << "2. FsrScore" << endl;
			cout << "3. ErScore" << endl;
			cout << "4. Back" << endl;
			cout << "Please select: ";
			cin >> choice;
		}
		if (choice == 1)
		{
			return 1;
		}
		else if (choice == 2)
		{
			return 2;
		}
		else if (choice == 3)
		{
			return 3;
		}
		else if (choice == 4)
		{
			system("cls");
			return 0;
		}
	}
}

double enterSearchValue() {
	while (true) {
		double search;
		cout << "Please enter search value (-1 to exit): ";
		cin >> search;
		while (cin.fail() || search<-1 ||search>100)
		{
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter VALID value!" << endl;;
			cout << "Please enter search value (0-100,-1 to exit): ";
			cin >> search;
		}
		if (search == -1)
		{
			system("cls");
			return -1;
		}
		else
		{
			return search;
		}
	}
}





