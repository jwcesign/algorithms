#include<stdio.h>

// 宏定义
// main part:start
#define len(arr) (sizeof(arr)/sizeof(arr[0]))
int insertion_sort(int *arr,int length)
{
  int j, i, key;
  for (j=1; j<length; j++)
  {
    key = arr[j];
    i = j-1;
    // >为升序，反之为降
    while(i > -1 && arr[i] > key)
    {
      arr[i+1] = arr[i];
      i = i-1;
    }
    arr[i+1] = key;
  }
}
// main part:end

int main(int argc, char const *argv[]) {
  // 验证
  int array[10] = {1,5,2,7,98,1123,654,0,44,77};
  int i;
  printf("The origin array: ");
  for (i=0; i<10; i++)
  {
    printf("%d ",array[i]);
  }
  printf("\nThe sorted array: ");
  insertion_sort(array,len(array));
  for (i=0; i<10; i++)
  {
    printf("%d ",array[i]);
  }
  return 0;
}
