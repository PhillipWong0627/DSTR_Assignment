#include <iostream>
#include <string>

#include "InsertionSort.h"
//#include "LinkedList.h"

using namespace std;


Node* InsertionSort::insertionSortForUniName(Node* head, int order)
{
    Node* sorted = NULL;
    if (order == 0){
        Node* current = head;
        while (current != NULL)
        {
            Node* next = current->next;
            if (sorted == NULL || sorted->institution >= current->institution)
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {
                Node* temp = sorted;
                while ((temp->next != NULL) && (temp->next->institution < current->institution)) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
    }
    return sorted;
}

Node* InsertionSort::insertionSortForFsr(Node* head, int order)
{
    Node* sorted = NULL;
    if (order == 1) {
        Node* current = head;
        while (current != NULL)
        {
            Node* next = current->next;   
            if (sorted == NULL || stod(sorted->fsrScore) <= stod(current->fsrScore))
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {
                Node* temp = sorted;
                while ((temp->next != NULL) && (stod(temp->next->fsrScore) > stod(current->fsrScore))) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
            
            
        }
    }
    return sorted;
}

FavNode* InsertionSort::insertionSortForFavUni(FavNode* head) {
    FavNode* sorted = NULL;
    
    FavNode* current = head;
    while (current != NULL)
    {
        FavNode* next = current->next;
        if (sorted == NULL || sorted->number <= current->number)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            FavNode* temp = sorted;
            while ((temp->next != NULL) && (temp->next->number > current->number)) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

