// C program to traverse the array
 
#include <stdio.h>
 
// Function to traverse and print the array
void printArray(int* arr, int n)
{
    int i;
 
    printf("Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
 
// Driver program
int main()
{
    int array[] = { 2, -1, 5, 6, 0, -3 };
    int n = sizeof(array) / sizeof(array[0]);
 
    printArray(array, n);
 
    return 0;
}