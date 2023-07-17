#include <iostream>
// #include <iomanip>
// #include <limits>
#include <string>
// #include <fstream>
// #include <sstream>

# include "BinarySearch.h"
using namespace std;

Node* BinarySearch::findMiddle(Node* start, Node* last)
{
    
    if (start == NULL) {
        return NULL;
    }
    Node* slow = start;
    Node* fast = start->next;
    while (fast != last)
    {
        
        fast = fast->next;
        if (fast != last)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

// Function for binary search
// Search on linked list
Node* BinarySearch::binarySearchForAr(Node* head, double value)
{
    Node* start = head;
    Node* last = NULL;
    Node* searched = NULL;
    LinkedList* linkedList = new LinkedList;
    do{
        // find middle
        Node* mid = findMiddle(start, last);

        // middle is empty
        if (mid == NULL) {
            return NULL;
        }
        // value is at middle
        if (stod(mid->arScore) == value) {
            return mid;
        }
        else if (stod(mid->arScore) < value) {
            start = mid->next;
        }
        else{
            last = mid;
        }
    } while (last == NULL || last != start);
}

Node* BinarySearch::binarySearchForFsr(Node* head, double value)
{
    Node* start = head;
    Node* last = NULL;
    Node* searched = NULL;
    LinkedList* linkedList = new LinkedList;
    do {
        // find middle
        Node* mid = findMiddle(start, last);

        // middle is empty
        if (mid == NULL) {
            return NULL;
        }
        // value is at middle
        if (stod(mid->fsrScore) == value) {
            return mid;
        }
        else if (stod(mid->fsrScore) < value) {
            start = mid->next;
        }
        else {
            last = mid;
        }
    } while (last == NULL || last != start);
}

Node* BinarySearch::binarySearchForEr(Node* head, double value)
{
    Node* start = head;
    Node* last = NULL;
    Node* searched = NULL;
    LinkedList* linkedList = new LinkedList;
    do {
        Node* mid = findMiddle(start, last);

        if (mid == NULL) {
            return NULL;
        }
        if (stod(mid->erScore) == value) {
            return mid;
        }
        else if (stod(mid->erScore) < value) {
            start = mid->next;
        }
        else {
            last = mid;
        }
    } while (last == NULL || last != start);
}