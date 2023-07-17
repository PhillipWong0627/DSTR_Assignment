#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#pragma once
#include <iostream>
#include "LinkedList.h"

using namespace std;

class InsertionSort {

public:
    Node* insertionSortForUniName(Node* head, int order);
    Node* insertionSortForFsr(Node* head, int order);
    FavNode* insertionSortForFavUni(FavNode* head);
};

#endif