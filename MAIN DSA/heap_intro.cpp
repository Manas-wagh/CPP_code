#include <bits/stdc++.h>
using namespace std;

//--------------------------------------- HEAP --------------------------------------------//
// it is always a complete binary tree.
// hamesha left to right bharenge
// it is always stored in array

//---index of left child of i th node = 2*i + 1
//---index of right child of i th node = 2*i + 2
//---index of parent  of i th node = floor of (i - 1)/2
//---maximum number of nodes at height h =ceil of n / 2^h + 1 ;

//----------- MIN HEAP
// complete binary tree with smallest value at node then uske child me usse badi then and so on

//----------- MAX HEAP
// complete binary tree with largest value at node then uske child me usse choti then and so on

//--- IMPLEMENTATION

class minheap
{
public:
    int size;
    int capacity;
    int *arr;
    minheap()
    {
    }
    minheap(int s)
    {
        capacity = s;
        arr = new int[s];
        size = 0;
    }

    int left_ind(int i)
    {
        return 2 * i + 1;
    }
    int right_ind(int i)
    {
        return 2 * i + 2;
    }
    int parent_ind(int i)
    {
        return (i - 1) / 2;
    }
    void insertnode(int data)
    {
        if (size == capacity)
        {
            cout << "heap full" << endl;
            return;
        }
        size++;
        arr[size - 1] = data;
        for (int i = size - 1; i != 0 && arr[parent_ind(i)] > arr[i]; i = parent_ind(i))
        {
            swap(arr[i], arr[parent_ind(i)]);
        }
    }
    void minheapify(int i)
    {
        int left = left_ind(i);
        int right = right_ind(i);
        int smallest = i;
        if (left < size && arr[left] < arr[i])
        {
            smallest = left;
        }
        if (right < size && arr[right] < arr[smallest])
        {
            smallest = right;
        }
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minheapify(smallest);
        }
    }
    int extract_min()
    {
        if (size == 0)
        {
            cout << " no heap found " << endl;
            return INT16_MAX;
        }
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        minheapify(0);
        return arr[size];
    }
    void decrease_key(int index, int data)
    {
        arr[index] = data;
        int i = index;
        while (i != 0 && arr[parent_ind(i)] > arr[i])
        {
            swap(arr[parent_ind(i)], arr[i]);
            i = parent_ind(i);
        }
    }
    void deletekey(int index)
    {
        decrease_key(index, INT16_MIN);
        extract_min();
    }
    void buildheap() // starts from bottommost rightmost internal node....then keeps on minheapifing
    {
        for (int i = (size - 2) / 2; i >= 0; i--) // to get it we write (last ele ind - 1)/2
        {
            minheapify(i);
        }
    }
};

// inserting in min heap
// first we insert element at last index
// then we keep on comparing it with its parent and if parent is bigger then swap them or stop
// we keep doing this until we get a smaller parent or we reach root node;

// min heapify: one possible violation in min heap...we have to fix this
// iske liye jo index pass kiya hei uske childs dekhenge and smallest ke sath swap karenge
//...phir swapped position ke liye recursively tree chalayenge

// extract min : to remove the smallest ele in heap....ie mostly node

// decrease key : to decrease the value at perticular index ...since it will violate min heap we furthur use heapify on it

// delete key : to delete a node in tree.

// build heap : to convert a given array into min heap wala array........it has time complexity of O(n);

// heap sort : build a max heap from given array----swap first(largest) element with last node...ie largest ko last bhej diya
//             then we call max heapify....which again creates a max heap and we continue this till all are sorted...
//           : time complexity O(nlog(n))

// priority queue : it is max heap which behaves like queue..hence has all functions like queue
//                  q.top will always give root wala....q.push will act like insertnode...and so on

class maxheap
{
public:
    int size;
    int capacity;
    int *arr;
    maxheap()
    {
    }
    maxheap(int s)
    {
        capacity = s;
        arr = new int[s];
        size = 0;
    }

    int left_ind(int i)
    {
        return 2 * i + 1;
    }
    int right_ind(int i)
    {
        return 2 * i + 2;
    }
    int parent_ind(int i)
    {
        return (i - 1) / 2;
    }
    void insertnode(int data)
    {

        if (size == capacity)
        {
            cout << "heap full" << endl;
            return;
        }
        size++;
        arr[size - 1] = data;
        for (int i = size - 1; i != 0 && arr[parent_ind(i)] < arr[i]; i = parent_ind(i))
        {
            swap(arr[i], arr[parent_ind(i)]);
        }
    }
    void maxheapify(int i)
    {
        int left = left_ind(i);
        int right = right_ind(i);
        int largest = i;
        if (left < size && arr[left] > arr[i])
        {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            maxheapify(largest);
        }
    }
    int extract_max()
    {
        if (size == 0)
        {
            cout << " no heap found " << endl;
            return INT16_MIN;
        }
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        maxheapify(0);
        return arr[size];
    }
    void decrease_key(int index, int data)
    {
        arr[index] = data;
        int i = index;
        while (i != 0 && arr[parent_ind(i)] < arr[i])
        {
            swap(arr[parent_ind(i)], arr[i]);
            i = parent_ind(i);
        }
    }
    void deletekey(int index)
    {
        decrease_key(index, INT16_MAX);
        extract_max();
    }
    void buildheap()
    {
        for (int i = (size - 2) / 2; i >= 0; i--)
        {
            maxheapify(i);
        }
    }
};

// HEAP SORT

void heapsort(maxheap &s)
{

    int sz = s.size;
    for (int i = 0; i < sz; i++)
    {
        swap(s.arr[0], s.arr[s.size - 1]);
        s.size--;
        s.maxheapify(0);
    }
}

int main()
{
    // minheap h(10);

    // h.insertnode(10);
    // h.insertnode(20);
    // h.insertnode(15);
    // h.insertnode(40);
    // h.insertnode(50);
    // h.insertnode(100);
    // h.insertnode(25);

    // h.minheapify(0);
    // cout << h.extract_min();
    // cout << h.extract_min();
    // cout << h.extract_min();
    // cout << h.extract_min();
    // cout << h.extract_min();
    // cout << h.extract_min();
    // cout << h.extract_min();

    cout << endl;

    int n;
    cin >> n;
    maxheap final(n);

    for (int i = 0; i < n; i++)
    {

        int data;
        cin >> data;
        final.insertnode(data);
    }

    heapsort(final);

    for (int i = 0; i < n; i++)
    {
        cout << final.arr[i] << " ";
    }

    //-----PRIORITY QUEUE-----//

    priority_queue<int> pq;                            // creates max heap
    priority_queue<int, vector<int>, greater<int>> pq; // creates min heap
    // priority_queue<int> pq(arr,arr+n);                            // creates max heap using existing array
    // priority_queue<int> pq(v.begin,v.end);                        // creates max heap using existing vector

    return 0;
}