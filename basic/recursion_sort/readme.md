## 分沿法排序
### 伪代码
~~~
//MERGE(A,p,q,r),归并
n1 = q-p+1
n2 = r-q
let L[1..n1+1] and R[1..n2+1] be new arrays
for i = 1 to n1
  L[i] = A[p+i-1]
for j = 1 to n2
  R[j] = A[q+j]
L[n1+1] = inf
R[n2+1] = inf
i = 1
j = 1
for k = p to r
  if L[i] <= R[j]
    A[k] = L[i]
    i = i+1
  else A[k] = R[j]
    j = j+1
~~~

~~~
//MERGE-SORT(A,p,r)
if p < r
  q = (p+r)/2
  MERGE-SORT(A,p,q)
  MERGE-SORT(A,q+1,r)
  MERGE(A,p,q,r)
~~~

## 二分法查找
~~~
//binary_search(A,num_find,p,r)
q = (p+r)/2
if A[q] > num_find
  q = binary_search(A,1,q-1)
if A[q] < num_find
  q = binary_search(A, q,r)
if A[q] == num_find
  return q
return q
~~~
