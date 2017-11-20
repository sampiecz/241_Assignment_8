#ifndef MERGESORT_H
#define MERGESORT_H

template <class T>
class Mergesort 
{
    // Data members
    private:

    // Method prototypes
    public:
        void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
        void mergeSort(vecotr<T>& set, int low, int high, bool (*compare)(const T&, const T&))
        void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
};

template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{

}

template <class T>
void mergeSort(vecotr<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{

}

template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{

}


#endif
