# -*-coding:utf-8-*-

def bubblesort(A):
    A_length = len(A)
    i = 0
    while i < A_length-1:
        j = A_length-1
        while j > i:
            if A[j] < A[j-1]:
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
            j -= 1
        i += 1
    return A

if __name__ == '__main__':
    A = [1,3,5,2,1,4,7,8,9,6,2,5,4,1,2];
    A = bubblesort(A)
    print A
