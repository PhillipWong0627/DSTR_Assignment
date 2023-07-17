#include <iostream>
// #include <iomanip>
// #include <limits>
#include <string>
// #include <fstream>
// #include <sstream>

# include "LinearSearch.h"
using namespace std;

Node* LinearSearch::linearSearchForAr(Node* head, double value) {
	Node* curr = head;
	while (curr != NULL) {
		if (stod(curr->arScore) == value) {
			return curr;
		}
		curr = curr->next;
	}
	return curr;
}

Node* LinearSearch::linearSearchForFsr(Node* head, double value) {
	Node* curr = head;
	while (curr != NULL) {
		if (stod(curr->fsrScore) == value) {
			return curr;
		}
		curr = curr->next;
	}
	return curr;
}

Node* LinearSearch::linearSearchForEr(Node* head, double value) {
	Node* curr = head;
	while (curr != NULL) {
		if (stod(curr->erScore) == value) {
			return curr;
		}
		curr = curr->next;
	}
	return curr;
}