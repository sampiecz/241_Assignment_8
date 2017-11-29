//*********************************************************************
//// FILE:        sorts.h
//// AUTHOR:      Samuel Piecz
//// LOGON ID:    Z1732715
//// DUE DATE:    11/29/17
////
//// PURPOSE:      
////********************************************************************
#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <fstream>
using namespace std;

// Part 1
template <class T> void buildList(vector<T>& set, const char* fileName);
template <class T> void printList(const vector<T>& set, int itemWidth, int numPerLine);

// Part 2
template <class T> bool lessThan(const T& item1, const T& item2);
template <class T> bool greaterThan(const T& item1, const T& item2);

/***************************************************************
 Name: buildList 

 Use: Opens file, reads through items, closes file. 

 Parameters: A reference to a vector of type template, and a
 pointer to a constant char. 

 Returns: No return 
***************************************************************/
template <class T>
void buildList(vector<T>& set, const char* fileName)
{
    T item;
    ifstream inFile;

    inFile.open(fileName);
    if (!inFile)
    {
        cerr << "Unable to open input file." << endl;
        exit(1);
    }

    inFile >> item;
    // Loop through every item in input file
    while (inFile)
    {
        set.push_back(item);

        // Read item from input file 
        inFile >> item;
    }

    // Close the input file
    inFile.close();
}

/***************************************************************
 Name: printList 

 Use: Prints out a list. 

 Parameters: Reference to a constant vector of type template,
 and two integers. 

 Returns: No return 
***************************************************************/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
    int i = 0;
    while (i < (int) set.size())
    {
        cout << setw(itemWidth) << set[i] << ' ';
        i++;
        if (i % numPerLine == 0)
        {
            cout << endl;
        }
    }

    if (i % numPerLine != 0)
    {
        cout << endl;
    }
}

/***************************************************************
 Name: lessThan 

 Use: Compares two items and checks if item1 is less than item2. 

 Parameters: Two references to constant type T objects. 

 Returns: A bool. 
***************************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2)
{
    if (item1 < item2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/***************************************************************
 Name: greaterThan 

 Use: Compare item1 and item 2, see if item1 is greater than
 item 2. 

 Parameters: Two references to constant objects of type T. 

 Returns: A bool. 
***************************************************************/
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
    if (item1 > item2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif
