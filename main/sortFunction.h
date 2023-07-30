#include <iostream>

using namespace std;

class SortFunction
{
public:
    SortFunction()
    {
        cout << "Sort Function Object is Constructing." << endl
             << endl;
    }

    ~SortFunction()
    {
        cout << "Sort Function Object is Deconstructing." << endl
             << endl;
    }

    void BubbleSortRentalFee(vector<vector<string> >& data);

    void mergeLocation(std::vector<std::vector<std::string> >& arr, std::vector<int>& indices, int left, int middle, int right);

    void mergeSortLocation(std::vector<std::vector<std::string> >& arr, std::vector<int>& indices, int left, int right);

    void mergeSize(std::vector<std::vector<std::string> >& arr, std::vector<int>& indices, int left, int middle, int right);

    void mergeSortSize(std::vector<std::vector<std::string> >& arr, std::vector<int>& indices, int left, int right);

};