#include <iostream>
#include <iomanip>
// #include <limits>
#include <string>
#include <chrono>
#include <sstream>
// #include <fstream>
// #include <sstream>

# include "AdminClass.h"
using namespace std;

bool AdminClass::admLogin(AdmNode* admHead) {
    string userName, password;

    cout << "Please enter username: ";
    getline(cin >> ws, userName);

    cout << "Please enter password: ";
    cin >> password;
    AdmNode* curr = admHead;
    while (curr != NULL) {
        if ((curr->userName == userName) && (curr->password == password)) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void AdminClass::displayRegisteredCus(CusNode* cusHead) {
	CusNode* current = cusHead;
	cout << string(152, '-') << endl;
	cout << "|" << setw(16) << "Username|" << setw(31) << "Password|" << setw(26) << "Customer Name|";
	cout << setw(26) << "Age|" << setw(26) << "Account Created Date|" << setw(26) << "Last Login Date|";
	cout << endl;
	cout << string(152, '-') << endl;
	while (current != NULL) {
		cout << "|" << setw(15) << current->userName << "|" << setw(30) << current->password << "|" << setw(25) << current->name << "|";
		cout << setw(25) << current->age << "|" << setw(25) << current->accCreatedDate << "|" << setw(25) << current->lastLoginDate << "|";
		cout << endl;
		current = current->next;
	}
	system("pause");
	system("cls");
	return;
}

void AdminClass::modifyCus(CusNode* cusHead) {
	string userName;

	cout << "Please enter customer username:";
	getline(cin >> ws, userName);
	CusNode* curr = cusHead;
	while (curr!=NULL) {
		if (curr->userName == userName) {
			break;
		}
		curr = curr->next;
	}
	if (curr==NULL) {
		cout << "Customers do not exist!" << endl;
		system("pause");
		system("cls");
	}
	else {
		int choice;
		string newPassword,newName, newAccCreatedDate, newLastLoginDate;
		int newAge;
		cout << "Which part you want to modify?" << endl;
		cout << "1. Password" << endl;
		cout << "2. Name" << endl;
		cout << "3. Age" << endl;
		cout << "4. Account created date" << endl;
		cout << "5. Last login date" << endl;
		cout << "6. Back" << endl;
		cout << "Please select: ";
		cin >> choice;

		while (cin.fail() || choice < 1 || choice > 6)
		{
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect input!";
			cout << endl;
			cout << "Which part you want to modify?" << endl;
			cout << "1. Password" << endl;
			cout << "2. Name" << endl;
			cout << "3. Age" << endl;
			cout << "4. Account created date" << endl;
			cout << "5. Last login date" << endl;
			cout << "6. Back" << endl;
			cout << "Please select: ";
			cin >> choice;
		}

		if (choice == 1) {
			cout << "Please enter NEW password: ";
			getline(cin >> ws, newPassword);
			curr->password = newPassword;
		}
		else if (choice == 2) {
			cout << "Please enter NEW name: ";
			getline(cin >> ws, newName);
			curr->name = newName;
		}
		else if (choice == 3) {
			cout << "Please enter NEW age: ";
			cin >> newAge;
			curr->age = newAge;
		}
		else if (choice == 4) {
			cout << "Please enter NEW account created date: ";
			getline(cin >> ws, newAccCreatedDate);
			curr->accCreatedDate = newAccCreatedDate;
		}
		else if (choice == 5) {
			cout << "Please enter NEW last login date: ";
			getline(cin >> ws, newLastLoginDate);
			curr->lastLoginDate = newLastLoginDate;
		}
		else if (choice == 6) {
			system("cls");
			return;
		}
	}
	system("cls");
	cout << "Update successful!" << endl;
	return;
}

int AdminClass::dateDiff(string start_date_str, string end_date_str) {
	tm start = {};
	tm end = {};

	istringstream ss(start_date_str);
	ss >> get_time(&start, "%d/%m/%Y");

	ss = istringstream(end_date_str);
	ss >> get_time(&end, "%d/%m/%Y");

	auto start_time = chrono::system_clock::from_time_t(mktime(&start));
	auto end_time = chrono::system_clock::from_time_t(mktime(&end));

	auto diff = chrono::duration_cast<chrono::duration<int,ratio<86400>>>(end_time - start_time);

	return diff.count();
}

void AdminClass::displayInactiveCus(CusNode* cusHead) {
	CusNode* current = cusHead;
	
	cout << string(152, '-') << endl;
	cout << "|" << setw(16) << "Username|" << setw(31) << "Password|" << setw(26) << "Customer Name|";
	cout << setw(26) << "Age|" << setw(26) << "Account Created Date|" << setw(26) << "Last Login Date|";
	cout << endl;
	cout << string(152, '-') << endl;
	while (current != NULL) {
		if (dateDiff(current->accCreatedDate, current->lastLoginDate) >= 365) {
			cout << "|" << setw(15) << current->userName << "|" << setw(30) << current->password << "|" << setw(25) << current->name << "|";
			cout << setw(25) << current->age << "|" << setw(25) << current->accCreatedDate << "|" << setw(25) << current->lastLoginDate << "|";
			cout << endl;
		}
		current = current->next;
	}
}

void AdminClass::deleteAcc(CusNode*& cusHead) {
	string userName;
	CusNode* curr = cusHead;
	CusNode* prev = NULL;

	cout << "Please enter username to delete: ";
	getline(cin >> ws, userName);

	
	
	if (prev==NULL && curr->userName == userName) {
		cusHead = curr->next;
		system("cls");
		cout << "Deleted " << userName << "'s account!" << endl<<endl;
		delete curr;
		return;
	}
	while (curr != NULL) {
		if (curr->userName == userName && prev != NULL) {
			// algorithm to delete a node in linked list
			prev->next = curr->next;

			system("cls");
			cout << "Deleted " << userName << "'s account!" << endl << endl;
			delete curr;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	
	system("cls");
	cout << "Customers do not exist!" << endl << endl;
	return;
}

void AdminClass::summarizeUni(FavNode* favHead) {
	InsertionSort* is = new InsertionSort;
	FavNode* sorted = is->insertionSortForFavUni(favHead);

	cout << string(27, '-') << endl;
	cout << "|" << setw(4) << "Rank|" << setw(21) << "Number of favourites|";
	cout << endl;
	cout << string(27, '-') << endl;
	while (sorted != NULL) {
		cout << "|" << setw(4) << sorted->rank << "|" << setw(20) << sorted->number << "|";
		cout << endl;
		sorted = sorted->next;
	}
	system("pause");
	system("cls");
	return;
}

// Use recursive concept to move back and forward
void AdminClass::readFeedback(FeedbackNode* feedbackHead) {
	FeedbackNode* curr = feedbackHead;
	int choice;
	
	cout << endl;
	cout << "FeedbackID: " << curr->feedbackID << endl;
	cout << "Username: " << curr->userName << endl;
	cout << "Message: " << curr->message << endl;
	cout << "Reply: " << curr->reply << endl;
	cout << "Customer Send Date: " << curr->sendDate << endl;
	cout << "Admin Reply Date: " << curr->replyDate << endl;
	cout << endl;
		
	cout << "1. Back" << endl;
	cout << "2. Next" << endl;
	cout << "3. Exit" << endl;
	cout << "Please select: ";
	cin >> choice;
	if (choice == 1 && curr->prev != NULL) {
		system("cls");
		readFeedback(curr->prev);
	}
	else if (choice == 2 && curr->next != NULL) {
		system("cls");
		readFeedback(curr->next);
	}
	else if (choice == 3) {
		system("pause");
		system("cls");
		return;
	}
	else {
		system("cls");
		cout << "Nothing new... ..." << endl << endl;
		readFeedback(curr);
	}
}

void AdminClass::replyFeedback(FeedbackNode* feedbackHead) {
	string feedbackID;
	cout << "Please enter FeedbackID: ";
	cin >> feedbackID;
	FeedbackNode* curr = feedbackHead;
	while (curr!=NULL) {
		if(feedbackID == curr->feedbackID) {
			cout << "Message from " << curr->userName << ": " << curr->message << endl;
			cout << "Reply: ";
			getline(cin >> ws, curr->reply);

			CustomerClass* getDate = new CustomerClass;
			curr->replyDate = getDate->returnDate();
			system("pause");
			system("cls");
			return;
		}
		curr = curr->next;
	}
	system("cls");
	cout << "FeedbackID not found!"<<endl;
}
