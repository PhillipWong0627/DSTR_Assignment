#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H
#pragma once

#include <iostream>
#include "LinkedList.h"

using namespace std;

class LinearSearch {

public:
    Node* linearSearchForAr(Node* head, double value);
    Node* linearSearchForFsr(Node* head, double value);
    Node* linearSearchForEr(Node* head, double value);
};

#endif
