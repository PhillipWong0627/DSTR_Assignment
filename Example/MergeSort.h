#ifndef MERGESORT_H
#define MERGESORT_H
#pragma once
#include <iostream>
#include "LinkedList.h"
using namespace std;

class MergeSort {

public:

    // Merge two sorted linked lists
    Node* mergeSortForUniName(Node* left, Node* right);

    Node* mergeSortForArFsrEr(Node* left, Node* right);
    Node* mergeSortForAr(Node* left, Node* right);
    Node* mergeSortForFsr(Node* left, Node* right);
    Node* mergeSortForEr(Node* left, Node* right);

    Node* mergeSort(Node* head, int order, string type); 

};

#endif