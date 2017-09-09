#include <stdio.h>

#define len(A) (sizeof(A)/sizeof(A[0]))

int binarySearch(int a[], int num_find, int p, int r)
{
  int q;
  q = (p+r)/2;
  if (a[q] > num_find)
  {
    q = binarySearch(a, num_find, 0, q-1);
  }
  if (a[q] < num_find)
  {
    q = binarySearch(a, num_find, q, r);
  }
  if (a[q] == num_find)
  {
    return q;
  }
  return q;
}

int main(int argc, char const *argv[]) {
  int a[10] = {1,2,3,4,5,6,7,8,9,10};
  int ans;
  ans = binarySearch(a,3,0,len(a)-1);
  printf("The answer is: %d", ans);
  return 0;
}
