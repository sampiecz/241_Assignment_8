#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <cstring>
using namespace std;

template <class T>
class Quicksort
{
    // Data members
    private:

    // Method prototypes
    public:
        void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));
        void quickSort(vector<T> & set, int start, int end, bool (*compare)(const T&, const T&));
        int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));
        bool (*compare)(const T&, const T&);
};

template <class T>
bool (*compare)(const T& a, const T& b)
{
    if (!strcmp(a, b))
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
    quickSort(set, 0, set.size()-1, compare);
}

template <class T>
void quickSort(vector<T> & set, int start, int end, bool (*compare)(const T&, const T&))
{
    int pivotPoint;

    if (start < end)
    {
        pivotPoint = partition(set, start, end, compare);  // Get the pivot point
        quickSort(set, start, pivotPoint - 1, compare);    // Sort first sublist
        quickSort(set, pivotPoint + 1, end, compare);      // Sort second sublist
    }
}

template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
    int pivotIndex, mid;
    T pivotValue;

    mid = (start + end) / 2;

    // Swap elements start and mid of the vector

    pivotIndex = start;
    pivotValue = set[start];

    for (int scan = start + 1; scan <= end; scan++)
    {
        if (compare(set[scan], pivotValue))
        {
            pivotIndex++;
            // Swap elements pivotIndex and scan of the vector
        }
    }

    // Swap elements start and pivotIndex of the vector

    return pivotIndex;
}

bool (*compare)(int a, int b);

#endif
