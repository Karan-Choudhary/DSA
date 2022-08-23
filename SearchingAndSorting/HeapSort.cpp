/*
Problem - Perform a HeapSort.

Algorithm - 
1. Swap the first and last element.
2. Decrease the size of the heap by 1.
3. Call the heapify function.
4. Repeat the steps 1-3 until the size of the heap is 1.

************************
Note - We follow 1-based indexing.
************************
************************
if you want to follow 0-based indexing then:
left = 2*i+1;
right = 2*i+2;

left < n and arr[largest] < arr[left]
right < n and arr[largest] < arr[right]


Time Compelxity - O(nlog(n))
*/

#include<bits/stdc++.h>
using namespace std;

class heap{
        public:
        int arr[100];
        int size=0;

        void insert(int val)
        {
            size++;
            int index = size;

            arr[index] = val;

            while(index>1)
            {
                int parent = index/2;
                if(arr[parent] < arr[index])
                {
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else
                {
                    return;
                }
            }
        }

        void deletion()
        {
            if(size == 0)
            {
                cout<<"empty"<<endl;
                return;
            }

            arr[1] = arr[size];
            size--;

            // take root node to its correct position
            int i=1;
            while(i<size)
            {
                int leftIndex = 2*i;
                int rightIndex = 2*i+1;

                if(leftIndex < size and arr[i] < arr[leftIndex])
                {
                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;
                }
                else if(rightIndex < size and arr[i] < arr[rightIndex])
                {
                    swap(arr[i], arr[rightIndex]);
                    i = rightIndex;
                }
                else
                {
                    return;
                }
            }
        }

        void print()
        {
            for(int i=1; i<=size; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n and arr[largest] < arr[left])
        largest = left;
    if(right <= n and arr[largest] < arr[right])
        largest = right;

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;

    while(size > 1)
    {
        // Step 1
        swap(arr[1], arr[size]);
        
        // Step 2
        size--;

        // Step 3
        heapify(arr, size, 1);
    }
}

int main()
{
    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = sizeof(arr)/sizeof(arr[0])-1;

    // heap creation
    for(int i = n/2; i>0; i--)
    {
        heapify(arr, n, i);
    }

    // Sorting using heap sort
    heapSort(arr, n);

    // Printing the sorted array
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}