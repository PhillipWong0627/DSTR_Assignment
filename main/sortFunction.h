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

    void BubbleSort(int arrayToBeSort[], int arraySize);

    // void SortFunction::BubbleSort(int arrayToBeSort[], int arraySize)
    // {
    //     for (int i = 0; i < arraySize; i++)
    //     {
    //         for (int j = 0; j < arraySize - 1 - i; j++)
    //         {
    //             if (arrayToBeSort[j] > arrayToBeSort[j + 1])
    //             {
    //                 swap(arrayToBeSort[j], arrayToBeSort[j + 1]);
    //             }
    //         }
    //     }

    //     cout << "After sort : " << endl;
    //     for (int i = 0; i < arraySize; i++)
    //     {
    //         cout << arrayToBeSort[i] << endl;
    //     }
    // }

    void merge(int arrayToBeSort[], int left, int mid, int right);
    void MergeSort(int arrayToBeSort[], int begin, int end);
};