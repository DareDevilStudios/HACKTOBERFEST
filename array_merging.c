// C Program To Merge Two Arrays 
// using Quaint Methodology
#include <stdio.h>
int main()
{
    int array1 = 5, array2 = 5, merge_array, i, j;
  
    // elements of first Array
    int a[5] = { 1, 2, 3, 4, 5 };
  
    // elements of Second Array
    int b[5] = { 6, 7, 8, 9, 10 };
  
    // resultant Array Size Declaration
    merge_array = array1 + array2;
    int c[merge_array];
  
    // copying array 1 elements into an array
    for (i = 0; i < array1; i++) {
        c[i] = a[i];
    }
  
    // copying array 2 elements into an array
    for (i = 0, j = array1;
         j < merge_array && i < array2; i++, j++) {
        c[j] = b[i];
    }
  
    // Array Elements After Merging
    for (i = 0; i < merge_array; i++) {
        printf("%d ", c[i]);
    }
    return 0;
}