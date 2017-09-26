## 伪代码(最大子数组问题)
* FIND-MAX-CROSSING-SUBARRAY(A,low,mid,high)
~~~
left-summ = -inf
sum = 0
for i = mid downto low
  sum = sum+A[i]
  if sum > left-summ
    left-summ = sum
    max-left = i
right-sum = -inf
sum = 0
for j = mid+1 to high
  sum = sum+A[j]
  if sum > right-sum
    right-sum = sum
    max-right = j
return (max-left,max-right,left-sum+right-sum)
~~~
* FIND-MAXIMUM-SUBARRAY(A,low,high)
~~~
if high == low
  return (low,high,A[low])
else
  mid = floor((low+high)/2)
  (left-low,left-high,left-sum) = FIND-MAXIMUM-SUBARRAY(A,low,mid)
  (right-low,right-high,right-sum) = FIND-MAXIMUM-SUBARRAY(A,mid+1,high)
  (cross-low,cross-high,cross-sum) = FIND-MAX-CROSSING-SUBARRAY(A,low,mid,high)
  if left-sum >= right-sum and left-sum >= cross-sum
    return (left-low,left-high,left-sum)
  elseif right-sum >= left-sum and right-sum >= cross-sum
    return (right-low,right-high,right-sum)
  else
    return (cross-low,cross-high,cross-sum)
~~~
* 问题描述：一个数组中存在负数元素，求出最大和的子数组。
