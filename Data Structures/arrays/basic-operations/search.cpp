//In an unsorted array, the search operation can be performed by linear traversal from the first element to the last element.

// C++ program to implement linear
// search in unsorted array
#include <bits/stdc++.h>
using namespace std;
 
// Function to implement search operation
int findElement(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
     
      // If the key is not found
    return -1;
}
 
// Driver's Code
int main()
{
    int arr[] = { 12, 34, 10, 6, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Using a last element as search element
    int key = 40;
   
      // Function call
    int position = findElement(arr, n, key);
 
    if (position == -1)
        cout << "Element not found";
    else
        cout << "Element Found at Position: "
             << position + 1;
 
    return 0;
}