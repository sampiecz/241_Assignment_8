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
        bool lessThan(const T& item1, const T& item2)
        bool greaterThan(const T& item1, const T& item2)

};

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

    while (getline(inFile, set))
    {
        set.push_back(item);
       
    }

    // Close the input file
    inFile.close();
}

template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
    for (int i = 0; i < numPerLine; i++)
    {
        cout << setw(itemWidth) << set[i] << " ";
    }
}

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
