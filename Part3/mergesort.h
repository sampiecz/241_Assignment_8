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
    mergeSort(set, 0, set.size()-1, compare);
}

// This recursive function divides a vector into two subvectors, sorts them, and then merges the two sorted subvectors.
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

// This function merges two sorted subvectors.
template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{
    int i = low;    // Subscript for start of left sorted subvector
    int j = mid+1;  // Subscript for start of right sorted subvector
    int k = 0;      // Subscript for start of merged vector

    // While not at the end of either subvector
    while (i <= mid && j <= high)
    {
        if (compare(set[j], set[i]))
        {
            /*
            Copy element j of set into element k of temp
            Add one to j
            Add one to k
            */
            strcpy(temp[k], set[j]);
            ++j;
            ++k;
        }
        else
        {
            /*
             * Copy element i of set into element k of temp
             * Add one to i
             * Add one to k
             *
             */
            strcpy(temp[k], set[i]);
            ++i;
            ++k;
        }
    }

    // Copy over any remaining elements of left subvector
    while (i <= mid)
    {
        /*
         * Copy element i of set into element k of temp
         * Add one to i
         * Add one to k
         *
         */
        strcpy(temp[k], set[i]);
        ++i;
        ++k;
    }

    // Copy over any remaining elements of right subvector
    while (j <= high)
    {
        /*
         * Copy element j of set into element k of temp
         * Add one to j
         * Add one to k
         *
         */
        strcpy(temp[k], set[j]);
        ++j;
        ++k;
    }

    // Copy merged elements back into original vector
    for (i = 0, j = low; j <= high; i++, j++)
    {
        // Copy element i of temp into element j of set
        strcpy(set[j], temp[i]);
    }
}


#endif
