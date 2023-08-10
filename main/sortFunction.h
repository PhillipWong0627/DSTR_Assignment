#include <iostream>

using namespace std;

class SortFunction
{
public:
    SortFunction()
    {
        // cout << "Sort Function Object is Constructing." << endl
        //      << endl;
    }

    ~SortFunction()
    {
        // cout << "Sort Function Object is Deconstructing." << endl
        //      << endl;
    }

    void BubbleSortRentalFee(vector<vector<string> >& data, chrono::high_resolution_clock::time_point& start_time, chrono::high_resolution_clock::time_point& end_time);

    void BubbleSortPropertyId(vector<vector<string> >& data, chrono::high_resolution_clock::time_point& start_time, chrono::high_resolution_clock::time_point& end_time);

    void mergeLocation(vector<vector<string> >& arr, vector<int>& indices, int left, int middle, int right);

    void mergeSortLocation(vector<vector<string> >& arr, vector<int>& indices, int left, int right, chrono::high_resolution_clock::time_point& start_time, chrono::high_resolution_clock::time_point& end_time);

    void mergeSize(vector<vector<string> >& arr, vector<int>& indices, int left, int middle, int right);

    void mergeSortSize(vector<vector<string> >& arr, vector<int>& indices, int left, int right, chrono::high_resolution_clock::time_point& start_time, chrono::high_resolution_clock::time_point& end_time);

};