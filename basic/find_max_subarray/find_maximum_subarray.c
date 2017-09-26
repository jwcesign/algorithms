#include<stdio.h>

// 长度获取
#define len(arr) (sizeof(arr)/sizeof(arr[0]))

// 用于返回多个值
struct Data
{
  int low;
  int high;
  float sum;
};

struct Data find_max_crossing_subarray(int *A,int low,int mid,int high)
{
  int left_sum = -10000;
  int right_sum = -10000;
  int sum = 0;
  int i = mid;
  int j = mid+1;
  int max_right = mid+1;
  int max_left = mid;
  // 用于返回数据
  struct Data re;

  while (i >= low)
  {
    sum = sum+A[i];
    if(sum > left_sum)
    {
      left_sum = sum;
      max_left = i;
    }
    i -= 1;
  }
  sum = 0;
  while (j <= high)
  {
    sum = sum+A[j];
    if(sum > right_sum)
    {
      right_sum = sum;
      max_right = j;
    }
    j += 1;
  }
  re.low = max_left;
  re.high = max_right;
  re.sum = (right_sum+left_sum);
  return re;
}

struct Data find_maximum_subarray(int *A,int low,int high)
{
  int mid;
  int left_low,left_high,right_low,right_high,cross_low,cross_high;
  float left_sum,right_sum,cross_sum;
  struct Data re;
  if (high == low)
  {
    re.low = low;
    re.high = high;
    re.sum = A[low];
    return re;
  }
  else
  {
    mid = (low+high)/2;
    re = find_maximum_subarray(A,low,mid);
    left_low = re.low;
    left_high = re.high;
    left_sum = re.sum;

    re = find_maximum_subarray(A,mid+1,high);
    right_low = re.low;
    right_high = re.high;
    right_sum = re.sum;

    re = find_max_crossing_subarray(A,low,mid,high);
    cross_low = re.low;
    cross_high = re.high;
    cross_sum = re.sum;

    if (left_sum >= right_sum && left_sum >= cross_sum)
    {
      re.low = left_low;
      re.high = left_high;
      re.sum = left_sum;
      return re;
    }
    else
    {
      if (right_sum >= left_sum && right_sum >= cross_sum)
      {
        re.low = right_low;
        re.high = right_high;
        re.sum = right_sum;
        return re;
      }
      else
      {
        re.low = cross_low;
        re.high = cross_high;
        re.sum = cross_sum;
        return re;
      }
    }
  }
}
// 测试部分
int main(int argc, char const *argv[]) {
  int a[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
  struct Data m;
  m = find_maximum_subarray(a,0,15);
  printf("%d---%d---%f", m.low,m.high,m.sum);
  return 0;
}
