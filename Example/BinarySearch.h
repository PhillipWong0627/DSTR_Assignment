#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#pragma once
#include <iostream>
#include <string>

#include "LinkedList.h"

using namespace std;

class BinarySearch {

public:
    Node* findMiddle(Node* start, Node* last);
    Node* binarySearchForAr(Node* head, double value);
    Node* binarySearchForFsr(Node* head, double value);
    Node* binarySearchForEr(Node* head, double value);
    
};
#endif