//*********************************************************************
//// FILE:        quicksort.h
//// AUTHOR:      Samuel Piecz
//// LOGON ID:    Z1732715
//// DUE DATE:    11/29/17
////
//// PURPOSE:     Recursively sort a list of items using quick sort. 
////********************************************************************
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <cstring>
using namespace std;

// Define sorting functions
template <class T> void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));
template <class T> void quickSort(vector<T> & set, int start, int end, bool (*compare)(const T&, const T&));
template <class T> int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

/***************************************************************
 Name: quickSort 

 Use: Recursively call the alternate quickSort function. 

 Parameters: A reference to a vector of type T, and a pointer
 to the compare function which takes two references to constant
 objects of type T. 

 Returns: No return 
***************************************************************/
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
    quickSort(set, 0, set.size()-1, compare);
}

/***************************************************************
 Name: quickSort 

 Use: This is the logic for the quickSort algorithm function.
 This function is then called recursively via the other 
 quicksort function.

 Parameters:  A reference to a vector of type T, and a pointer
 to the compare function which takes two references to constant
 objects of type T, plus two integer variables.

 Returns: No return 
***************************************************************/
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

/***************************************************************
 Name: partition 

 Use: This function selects a pivot element and then partitions
 the vector around the pivot. 

 Parameters:  A reference to a vector of type T, and a pointer
 to the compare function which takes two references to constant
 objects of type T, plus two integer variables.

 Returns: pivotIndex 
***************************************************************/
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
    int pivotIndex, mid;
    T pivotValue;
    T temp;

    mid = (start + end) / 2;

    // Swap elements start and mid of the vector
    temp = set[start];
    set[start] = set[mid];
    set[mid] = temp;

    pivotIndex = start;
    pivotValue = set[start];

    for (int scan = start + 1; scan <= end; scan++)
    {
        if (compare(set[scan], pivotValue))
        {
            pivotIndex++;
            // Swap elements pivotIndex and scan of the vector
            temp = set[pivotIndex];
            set[pivotIndex] = set[scan];
            set[scan] = temp;
        }
    }

    // Swap elements start and pivotIndex of the vector
    temp = set[start];
    set[start] = set[pivotIndex];
    set[pivotIndex] = temp;

    return pivotIndex;
}

#endif
