#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Sorts
{
    // Data members
    private:

    // Method prototypes
    public:
        // Part 1
        void buildList(vector<T>& set, const char* fileName);
        void printList(const vector<T>& set, int itemWidth, int numPerLine);

        // Part 2
        bool lessThan(const T& item1, const T& item2);
        bool greaterThan(const T& item1, const T& item2);

};

/***************************************************************
 Name 

 Use: 

 Parameters: 

 Returns: 
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
 Name 

 Use: 

 Parameters: 

 Returns: 
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
 Name 

 Use: 

 Parameters: 

 Returns: 
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
 Name 

 Use: 

 Parameters: 

 Returns: 
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
