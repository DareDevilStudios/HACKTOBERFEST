// Program to take 5 values from the user and store them in an array
// Print the elements stored in the array

#include <stdio.h>

int main() {

  int array[5];

  printf("Enter 5 integers: ");
  
  // taking input and storing it in an array
  for(int i = 0; i < 5; ++i) {
     scanf("%d", &array[i]);
  }

  printf("Displaying array elements: ");

  // printing elements of an array
  for(int i = 0; i < 5; ++i) {
     printf("%d\n", array[i]);
  }
  return 0;
}