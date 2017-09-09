# -*- coding:utf-8 -*-
def merge(arr,p,q,r):
    n1 = q-p+1
    n2 = r-q
    L = []
    R = []
    i = 0
    j = 0
    while i <n1:
        L.append(arr[p+i])
        i += 1

    while j < n2:
        R.append(arr[q+j+1])
        j += 1
    #数字视情况定
    L.append(100000)
    R.append(100000)
    i = 0
    j = 0
    for k in range(p,r+1):
        if L[i] <= R[j]:
            arr[k] = L[i]
            i = i+1
        else:
            arr[k] = R[j]
            j = j+1

def merge_sort(arr,p,r):
    if (p<r):
        q = (p+r)/2
        merge_sort(arr,p,q)
        merge_sort(arr,q+1,r)
        merge(arr,p,q,r)

if __name__ == '__main__':
    a = [1,2,5,7,1,4,8,43,56,7,1,5]
    merge_sort(a,0,len(a)-1)
    print len(a)
    print a
