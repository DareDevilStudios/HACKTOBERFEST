//selection sort
//----------------------------------------------------------------
//The selection sort algorithm sorts an array by repeatedly finding the minimum element 
//from the unsorted part and putting it at the beginning.
//----------------------------------------------------------------
//steps

//step 1 -Initialize minimum value(min_idx) to location 0.
//step 2 -Traverse the array to find the minimum element in the array.
//step 3 -While traversing if any element smaller than min_idx is found then swap both the values.
//step 4 -Then, increment min_idx to point to the next element.
//step 5 -Repeat until the array is sorted.

//----------------------------------------------------------------

// C++ program for implementation of
// selection sort
#include <bits/stdc++.h>
using namespace std;
 
//Swap function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n-1; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        if(min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
}
 
//Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}