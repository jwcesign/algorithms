# -*- coding:utf-8 -*-

def insertion_sort(array_a):
    for j in range(1,len(array_a)):
        key = array_a[j]
        i = j-1
        # ‘>’为升序，'<'为降序
        while i > -1 and array_a[i] > key:
            array_a[i+1] = array_a[i]
            i = i-1
        array_a[i+1] = key
    return array_a

if __name__ == '__main__':
    TEST_ARRAY = [9,71,3,9,64,612,8,1,0]
    print insertion_sort(TEST_ARRAY)
