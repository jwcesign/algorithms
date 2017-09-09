# -*- coding:utf-8 -*-
# 对于排好序的数组执行二分法查找
def binary_search(A,num_find,p,r):
    q = (p+r)/2
    if A[q] == num_find:
         return q
    if A[q] > num_find:
        q = binary_search(A, num_find, 0, q-1)
    if A[q] < num_find:
        q = binary_search(A, num_find, q+1, r)
    return q

# Test part
A = [1,2,3,4,5,6,7,8,9]
num = 8
print binary_search(A,num,0,8)
