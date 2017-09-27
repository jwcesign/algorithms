# 冒泡排序（伪代码）
* 低效率
* BUBBLESORT(A)
~~~
for i = 1 to A.length-1
  for j = A.length downto i+1
    if A[j] < A[j-1]
      exchange A[j] with A[j-1]
~~~
