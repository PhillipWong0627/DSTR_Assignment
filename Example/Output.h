#ifndef OUTPUT_H
#define OUTPUT_H
#pragma once

#include <iostream>
#include "LinkedList.h"

using namespace std;

class Output {

public:
    void writeCusListToFile(CusNode* head, const string& filename);
    void writeFavListToFile(FavNode* head, const string& filename);
    void writeFeedbackListToFile(FeedbackNode* head, const string& filename);
};

#endif