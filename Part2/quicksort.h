#ifndef QUICKSORT_H
#define QUICKSORT_H

template <class T>
class Quicksort
{
    // Data members
    private:

    // Method prototypes
    public:
        void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));
        void quickSort(vector<T> & set, int start, int end, bool (*compare)(const T&, const T&))
        int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
};

template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));
{

}

template <class T>
void quickSort(vector<T> & set, int start, int end, bool (*compare)(const T&, const T&))
{

}

template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{

}

#endif
