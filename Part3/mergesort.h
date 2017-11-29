//*********************************************************************
//// FILE:        mergesort.h
//// AUTHOR:      Samuel Piecz
//// LOGON ID:    Z1732715
//// DUE DATE:    11/29/17
////
//// PURPOSE:      
////********************************************************************
#ifndef MERGESORT_H
#define MERGESORT_H

#include <cstring>
#include <vector>
using namespace std;

// Prototypes
template <class T> void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&));
template <class T> void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&));
template <class T> void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&));

/***************************************************************
 Name: mergeSort 

 Use: This function should sort the items in the vector set 
 using the merge sort algorithm. 

 Parameters: The first argument to this 
 function is a reference to a vector object containing the list
 of items to sort. The second argument is a pointer to a 
 comparison function that can be used to compare two items of
 the template type. 

 Returns: No return 
***************************************************************/
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
    mergeSort(set, 0, set.size()-1, compare);
}

/***************************************************************
 Name: mergeSort 

 Use: This recursive function divides a vector into two 
 subvectors, sorts them, and then merges the two sorted subvectors. 

 Parameters: A reference to a vector of type T, and a pointer
 to the compare function which takes two references to constant
 objects of type T, plus two integer variables.

 Returns: No return 
***************************************************************/
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;

        // Divide and conquer
        
        mergeSort(set, low, mid, compare);
        mergeSort(set, mid+1, high, compare);

        // Combine 
        merge(set, low, mid, high, compare);
    }
}

/***************************************************************
 Name: merge 

 Use: This function merges two sorted subvectors. 

 Parameters: A reference to a vector of type T, and a pointer
 to the compare function which takes two references to constant
 objects of type T, plus three integer variables.

 Returns: No return 
***************************************************************/
// This function merges two sorted subvectors.
template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{

    // Create temporary vector to hold merged subvectors
    vector<T> temp(high - low + 1);
    
    int i = low;    // Subscript for start of left sorted subvector
    int j = mid+1;  // Subscript for start of right sorted subvector
    int k = 0;      // Subscript for start of merged vector

    // While not at the end of either subvector
    while (i <= mid && j <= high)
    {

        if (compare(set[j], set[i]))
        {
           temp[k] = set[j];
            j++;
            k++;
        }
        else
        {
           temp[k] = set[i];
            i++;
            k++;
        }
    }

    // Copy over any remaining elements of left subvector
    while (i <= mid)
    {
       temp[k] = set[i];
        i++;
        k++;
    }

    // Copy over any remaining elements of right subvector
    while (j <= high)
    {
       temp[k] = set[j];
        j++;
        k++;
    }

    // Copy merged elements back into original vector
    for (i = 0, j = low; j <= high; i++, j++)
    {
        // Copy element i of temp into element j of set
        set[j] = temp[i];
    }
}


#endif
