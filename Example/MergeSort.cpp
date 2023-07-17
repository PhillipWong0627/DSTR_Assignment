#include <iostream>
#include <string>

#include "MergeSort.h"

using namespace std;

// Merge two sorted linked lists back
Node* MergeSort::mergeSortForUniName(Node* left, Node* right) {
    Node* result = NULL;
    if (left == NULL) {
        return right;
    }
    else if (right == NULL) {
        return left;
    }
    if (left->institution <= right->institution) {
        result = left;
        result->next = mergeSortForUniName(left->next, right);
    }
    else {
        result = right;
        result->next = mergeSortForUniName(left, right->next);
    }
    return result;
}

// sort for ArFsrEr Score
//Node* MergeSort::mergeSortForArFsrEr(Node* left, Node* right) {
//    Node* result = NULL;
//    if (left == NULL) {
//        return right;
//    }
//    else if (right == NULL) {
//        return left;
//    }
//    // color1 < color2  || (color1 == color2 && rank1 < rank2)
//    if (stod(left->arScore) > stod(right->arScore) || 
//        (stod(left->arScore) == stod(right->arScore) && stod(left->fsrScore) > stod(right->fsrScore)) || 
//        (stod(left->arScore) == stod(right->arScore) && stod(left->fsrScore) == stod(right->fsrScore) && stod(left->erScore) > stod(right->erScore))) {
//        result = left;
//        result->next = mergeSortForArFsrEr(left->next, right);
//    }
//    else{
//        result = right;
//        result->next = mergeSortForArFsrEr(left, right->next);
//    }
//    return result;
//}



Node* MergeSort::mergeSortForArFsrEr(Node* left, Node* right) {
    Node* result = NULL;
    if (left == NULL) {
        return right;
    }
    else if (right == NULL) {
        return left;
    }
    
    if (stod(left->arScore) > stod(right->arScore)){
        result = left;
        result->next = mergeSortForArFsrEr(left->next, right);
    }
    else if(stod(left->arScore) < stod(right->arScore)){
        result = right;
        result->next = mergeSortForArFsrEr(left, right->next);
    }
    else{
        if (stod(left->fsrScore) > stod(right->fsrScore)){
            result = left;
            result->next = mergeSortForArFsrEr(left->next, right);
        }
        else if(stod(left->fsrScore) < stod(right->fsrScore)){
            result = right;
            result->next = mergeSortForArFsrEr(left, right->next);
        }
        else{
            if (stod(left->erScore) > stod(right->erScore)){
                result = left;
                result->next = mergeSortForArFsrEr(left->next, right);
            }
            else{
                result = right;
                result->next = mergeSortForArFsrEr(left, right->next);
            }
        }
    }
    return result;
}



Node* MergeSort::mergeSortForAr(Node* left, Node* right) {
    Node* result = NULL;
    if (left == NULL) {
        return right;
    }
    else if (right == NULL) {
        return left;
    }
    if (stod(left->arScore) <= stod(right->arScore)) {
        result = left;
        result->next = mergeSortForAr(left->next, right);
    }
    else {
        result = right;
        result->next = mergeSortForAr(left, right->next);
    }
    return result;
}

Node* MergeSort::mergeSortForFsr(Node* left, Node* right) {
    Node* result = NULL;
    if (left == NULL) {
        return right;
    }
    else if (right == NULL) {
        return left;
    }
    if (stod(left->fsrScore) <= stod(right->fsrScore)) {
        result = left;
        result->next = mergeSortForFsr(left->next, right);
    }
    else {
        result = right;
        result->next = mergeSortForFsr(left, right->next);
    }
    return result;
}

Node* MergeSort::mergeSortForEr(Node* left, Node* right) {
    Node* result = NULL;
    if (left == NULL) {
        return right;
    }
    else if (right == NULL) {
        return left;
    }
    if (stod(left->erScore) <= stod(right->erScore)) {
        result = left;
        result->next = mergeSortForEr(left->next, right);
    }
    else {
        result = right;
        result->next = mergeSortForEr(left, right->next);
    }
    return result;
}


// Merge sort algorithm for linked list
Node* MergeSort::mergeSort(Node* head, int order, string type) {

    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    Node* right = mergeSort(slow->next, order, type);
    slow->next = NULL;
    Node* left = mergeSort(head, order, type);
    if (type == "universityName") {
        return mergeSortForUniName(left, right);
    }else if (type == "arFsrEr") {
        return mergeSortForArFsrEr(left, right);
    }
    else if (type == "ar") {
        return mergeSortForAr(left, right);
    }
    else if (type == "fsr") {
        return mergeSortForFsr(left, right);
    }
    else if (type == "er") {
        return mergeSortForEr(left, right);
    }
 

    // can be ignored
    return head;
}
