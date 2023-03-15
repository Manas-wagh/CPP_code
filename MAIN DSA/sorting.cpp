#include <bits/stdc++.h>
using namespace std;

/*.........................................................BUBBLE SORT.........................................
--->sabse bada element last me jate rehta he
ie pehle pass me sabse bada last me jayega
then 2nd pass me 2nd largest 2nd last me jayega and so on
-- with each pass array ke last element sort hote jate he ...then we dont need to sort them
-- number of passes required is arr->length -1;
-- time comp : n2
-- its stable in nature..ie dosent change relative positions of similar element

*/

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void bubbleSort(int *A, int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++) // For number of pass
    {
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *A, int n) // adaptive codes are use to save time complexity if array is already sorted
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For number of pass
    {
        printf("Working on pass number %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return; // ie if array is sorted then stop the execution
        }
    }
}

//.......................................INSERTION SORT................................................
/*
--with each pass left  side of daandi is instantaneously sorted and right side is mostly not.
--it is adaptive
--need arr->length - 1 passes
worst case o(n^2)
best case o(n);
in place and stable
used for sorting small arrays generally
*/

void insertionSort(int *A, int n)
{
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        // Loop for each pass
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

//.......................................SELECTION SORT................................................
// time comp n2
// not stable and needs less memory writes as compared to other algos
// exact opposite of bubble sort...ie smallest element gets bubbled and goes at first position by swapping.

void selection_sort(int *A, int n)
{
    int min_ind;
    int temp;
    for (int i = 0; i < n - 1; i++) // For number of pass
    {
        min_ind = i;
        for (int j = i + 1; j < n; j++) // For comparison in each pass
        {
            if (A[j] < A[min_ind])
            {
                min_ind = j;
            }
        }
        swap(A[min_ind], A[i]);
    }
}

//.......................................MERGE SORT................................................
// time comp nlogn
// stable and not an in place algo
// its a divide and conquer algorithm
// space complexity n
// but when we use linked list then it works on O(1) auxillary space.
// used in external sorting

void merges(int *A, int *B, int m, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n)
    {
        if (A[i] <= B[j])
        {
            cout << A[i] << " ";

            i++;
            k++;
        }
        else
        {
            cout << B[j] << " ";
            j++;
            k++;
        }
    }
    while (i < m)
    {
        cout << A[i] << " ";
        i++;
        k++;
    }
    while (j < n)
    {
        cout << B[j] << " ";
        j++;
        k++;
    }
}

void merge_one(int *arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1];
    int right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            // cout << A[i] << " ";
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            // cout << B[j] << " ";
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        // cout << A[i] << " ";
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        // cout << B[j] << " ";
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int *A, int l, int r)
{
    int mid;
    if (r > l)
    {
        mid = l + ((r - l) / 2); // we write like this to avoid overflow...ie for larger arrays the calculation l+r may surpass limit
        merge_sort(A, l, mid);
        merge_sort(A, mid + 1, r);
        merge_one(A, l, mid, r);
    }
}

//.......................................QUICK SORT................................................
// time comp nlogn in avg case and n2 in worst
// stable in naive only and  an in place algo
// divide and conquer

// lomuto partition

int lomutopartition(int *a, int l, int h)
{
    int pivot = a[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[h]);
    return (i + 1);
}

// haore partition

// faster than lamuto but dont place the pivot element at its correct possition
// it only returns the index when till index elemnts are small and after it are bigger then pivot
//  ** here first element is taken as pivot
//  i=i-1; j=h+1;
// pivot always goes in larger set
//  both lomuto and haore are unstable

int haorepartition(int *arr, int l, int h)
{
    int pivot = arr[l];
    int i = i - 1;
    int j = h + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

// use lomuto
void H_quick_sort(int *a, int l, int h)
{
    if (l < h) // implies that agar ek ya usse kam ele bache hei toh kuch mat karo;
    {
        int p = haorepartition(a, l, h);
        H_quick_sort(a, l, p);
        H_quick_sort(a, p + 1, h);
    }
}

// use haore
void L_quick_sort(int *a, int l, int h)
{
    if (l < h) // implies that agar ek ya usse kam ele bache hei toh kuch mat karo;
    {
        int p = lomutopartition(a, l, h);
        L_quick_sort(a, l, p - 1);
        L_quick_sort(a, p + 1, h);
    }
}

// now we make it more better
// we use random function which will give us a random pivot, hence saving us from sorted arrays;

int randompvt(int l, int h)
{
    return (l + h) / 2;
}

// using any partition;

int haorepartitionmod(int *arr, int l, int h)
{
    swap(arr[l], arr[randompvt(l, h)]); // bcoz we need first ele as pivot, we swap it with random val;,,lomuto ke liye r se swap karenge
    int pivot = arr[l];
    int i = i - 1;
    int j = h + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

// quick select

int kthelement(int *arr, int l, int h, int ind)
{

    if (lomutopartition(arr, l, h) == ind)
    {
        return arr[lomutopartition(arr, l, h)];
    }
    else if (lomutopartition(arr, l, h) > ind)
    {
        kthelement(arr, l, lomutopartition(arr, l, h) - 1, ind);
    }
    else
    {
        kthelement(arr, lomutopartition(arr, l, h) + 1, h, ind);
    }
}

// CYCLE SORT

// Function sort the array using Cycle sort
void cycleSort(int arr[], int n)
{
    // count number of memory writes
    int writes = 0;

    // traverse array elements and put it to on
    // the right place
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++)
    {
        // initialize item as starting point
        int item = arr[cycle_start];

        // Find position where we put the item. We basically
        // count all smaller elements on right side of item.
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++)
            if (arr[i] < item)
                pos++;

        // If item is already in correct position
        if (pos == cycle_start)
            continue;

        // ignore all duplicate elements
        while (item == arr[pos])
            pos += 1;

        // put the item to it's right position
        if (pos != cycle_start)
        {
            swap(item, arr[pos]);
            writes++;
        }

        // Rotate rest of the cycle
        while (pos != cycle_start)
        {
            pos = cycle_start;

            // Find position where we put the element
            for (int i = cycle_start + 1; i < n; i++)
                if (arr[i] < item)
                    pos += 1;

            // ignore all duplicate elements
            while (item == arr[pos])
                pos += 1;

            // put the item to it's right position
            if (item != arr[pos])
            {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }

    // Number of memory writes or swaps
    // cout << writes << endl ;
}

// COUNT SORT

void countsort(int *arr, int n, int k)
{
    int count[k];
    int output[n];

    for (int i = 0; i < k; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i < k; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// RADIX SORT

void countsortradix(int *arr, int n, int exp)
{
    int count[10];
    int output[n];

    for (int i = 0; i < 10; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixsort(int *arr, int n)
{
    int max = arr[0]; // first we find largest ele;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp = exp * 10)
    {
        countsortradix(arr, n, exp);
    }
}

// BUCKET SORT

void bucketsort(int *arr, int n, int k)
{
    int maxval = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        maxval = max(maxval, arr[i]);
    }
    maxval++;

    vector<int> bucket[k]; // array of vectors;

    for (int i = 0; i < n; i++)
    {
        int ind = (k * arr[i]) / maxval;
        bucket[ind].push_back(arr[i]);
    }
    for (int i = 0; i < k; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[index++] = bucket[i][j];
        }
    }
}

int main()
{
    // int A[] = {12, 54, 65, 7, 23, 9};
    // int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    // // int A[] = {1, 2, 3, 4, 5, 6};
    // int n = 11;
    // printArray(A, n); // Printing the array before sorting
    // bubbleSort(A, n); // Function to sort the array
    // printArray(A, n); // Printing the array before sorting

    //
    // -1   0    1   2   3   4   5
    //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
    //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

    //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
    //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

    //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
    //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
    //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
    //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
    //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

    // Fast forwarding and 4th and 5th pass will give:
    //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
    //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

    //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
    //      07, 09, 12, 23, 54, 65| --> After the 5th pass

    // int B[6] = {12, 5, 65, 7, 72, 95};
    // int n = 6;
    // printArray(A, n);
    // insertionSort(A, n);
    // printArray(A, n);
    // int m = 5;
    // int A[5] = {2, 5, 7, 24, 91};
    // merges(A, B, m, n);

    // merge_one(B, 0, 2, 5);
    // printArray(B, 6);

    // merge_sort(B, 0, 5);
    // printArray(B, 6);

    // cout << randompvt(1, 3);

    int arr[] = {1, 8, 3, 9, 10, 10, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cycleSort(arr, n);
    // radixsort(arr, n);

    bucketsort(arr, n, n / 2);

    cout << "After sort : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
