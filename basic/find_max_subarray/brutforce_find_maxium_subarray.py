# -*-coding:utf-8-*-

def find_maximum_subarray(A,low,high):
    sum = 0
    back_sum = -1000
    last_sum = -1000
    last_max_right = 0
    last_max_left = 0
    max_left = 0
    max_right = 0
    i = 0
    while i < high:
        j = i
        while j <= high:
            sum += A[j]
            if sum > back_sum:
                back_sum = sum
                max_left = i
                max_right = j
            if back_sum > last_sum:
                last_sum = back_sum
                last_max_left = max_left
                last_max_right = max_right
            j += 1
        sum = 0
        i += 1

    return last_max_left,last_max_right,last_sum

if __name__ == '__main__':
    A = [13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7];
    i,j,k = find_maximum_subarray(A,0,len(A)-1)
    print k
