#include <stdio.h>
#define len(arr) (sizeof(arr)/sizeof(arr[0]))

void merge(int a[], int p, int q, int r)
{
  int n1 = q-p+1;
  int n2 = r-q;
  int L[n1];
  int R[n2];
  int i, j;
  j = i = 0;
  for (int i=0; i < n1; i++)
  {
    L[i] = a[p+i];
  }
  for (int j=0; j<n2; j++)
  {
    R[j] = a[q+j+1];
  }
  // 优化最后需要设置最到大值
  for (int k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			if(i==(n1-1))
			{
				for(k++;k<=r&&(j<=(n2-1));k++)
				{
					a[k]=R[j];
					j++;
				}
				break;
			}
			i++;
		}
		else
    {
			a[k]=R[j];
			if(j==(n2-1))
			{
				for(k++;k<=r&&(i<=(n1-1));k++)
				{
					a[k]=L[i];
					i++;
				}
				break;
			}
			j++;
		}

  }
}

void mergeSort(int a[], int p, int r)
{
  if (p < r)
  {
    int q = (p+r)/2;
    mergeSort(a, p, q);
    mergeSort(a, q+1, r);
    merge(a, p, q, r);
  }
}

int main(int argc, char const *argv[]) {
  int a[10] = {1,23,3,45,78,11,44,78,1234,56};

  printf("The origin array: ");
  for (int i = 0;i < 10; i++)
  {
    printf("%d ", a[i]);
  }

  printf("\nThe sorted array: ");
  mergeSort(a, 0, len(a)-1);
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", a[i]);
  }

  return 0;
}
