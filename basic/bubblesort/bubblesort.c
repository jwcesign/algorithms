#include <stdio.h>

// function start
#define len(arr) (sizeof(arr)/sizeof(arr[0]))
void bubblesort(int *A,int arrr_length)
{
  int tmp = 0;
  for (int i=0; i<arrr_length-1;i++)
  {
    for (int j=arrr_length-1;j>i;j--)
    {
      if (A[j] < A[j-1])
      {
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
      }
    }
  }
}
// function end

// test part
int main(int argc, char const *argv[]) {
  int A[10] = {1,2,3,6,5,4,7,8,9,6};
  int arr_len = len(A);
  bubblesort(A,arr_len);
  for (int i=0;i<arr_len;i++)
  {
    printf("%d\t", A[i]);
  }
  return 0;
}
