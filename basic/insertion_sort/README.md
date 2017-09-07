## 伪代码
* 初始化，保持，终止的概念
~~~
INSERTION-SORT(A)
  for j = 2 to A.length
    key = A[j]
    // Insert A[j] into the sorted sequence A[1..j-1]
    i = j-1
    // ‘>’为升序，'<'为降序
    while i > 0 and A[i] > key
      A[i+1] = A[i]
      i = i-1
    A[i+1] = key
~~~
