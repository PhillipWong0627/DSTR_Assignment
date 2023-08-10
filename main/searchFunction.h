#include <iostream>

using namespace std;

class SearchFunction
{
    public:
    SearchFunction()
    {
        // cout << "Search Function Object is Constructing." << endl
        //      << endl;
    };
    ~SearchFunction(){
        // cout << "Search Function Object is Deconstructing." << endl
        //      << endl;
    };
    int LinearSearch(int arrayToBeSearch[], int arraySize, int searchValue);

    int BinarySearchFirst(const vector<vector<string> >& data, int propertyId, chrono::high_resolution_clock::time_point& start_time, chrono::high_resolution_clock::time_point& end_time);
};