#ifndef INPUT_H
#define INPUT_H
#pragma once

#include <iostream>
#include "LinkedList.h"
#include "Stack.h"

using namespace std;

class Input {

public:
    
    Node* inputUniInfo();
    CusNode* inputCusInfo();
    AdmNode* inputAdmInfo();
    FavNode* inputFavUniInfo();
    FeedbackNode* inputFeedbackInfo();
    string changeComma(string str);
};

#endif