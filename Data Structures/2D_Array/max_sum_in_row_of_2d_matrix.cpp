#include<bits/stdc++.h>
using namespace std;

int max_sum_row(int arr[][4],int row,int col) {
int max_sum = INT_MIN;
  
  for(int i = 0;i<row;i++) {
    int sum = 0;
    
    for(int j = 0;j<col;j++) {
    sum+=arr[i][j];
    }
    max_sum = max(sum,max_sum);
  }
  return max_sum;
  
}

int main()
{
    int arr[3][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 100},
                     {9, 10, 11, 12}};
                     
       int res = max_sum_row(arr,3,4);
  
      cout<<res<<endl;
                     
  }
