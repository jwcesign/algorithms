# -*-coding:utf-8-*-

def find_max_crossing_subarray(A,low,mid,high):
    # 这个数根据具体情况设置
    left_sum = -100000
    sum = 0
    i = mid
    max_left = i
    while i>= low:
        sum = sum+A[i]
        if sum > left_sum:
            left_sum = sum
            max_left = i
        i -= 1
    right_sum = -100000
    sum = 0
    j = mid+1
    max_right = i
    while j <= high:
        sum = sum+A[j]
        if sum > right_sum:
            right_sum = sum
            max_right = j
        j += 1
    return max_left,max_right,left_sum+right_sum

def find_maximum_subarray(A,low,high):
    if high == low:
        return low,high,A[low]
    else:
        mid = (low+high)/2
        left_low,left_high,left_sum = find_maximum_subarray(A,low,mid)
        right_low,right_high,right_sum = find_maximum_subarray(A,mid+1,high)
        cross_low,cross_high,cross_sum = find_max_crossing_subarray(A,low,mid,high)
        if left_sum >= right_sum and left_sum >= cross_sum:
            return left_low,left_high,left_sum
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return right_low,right_high,right_sum
        else:
            return cross_low,cross_high,cross_sum

# test part
if __name__ == '__main__':
    a=[13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7]
    # l为其最大子数组的索引开始,h为结束，s为其最大和
    l,h,s = find_maximum_subarray(a,0,len(a)-1)
    print l
    print h
    print s
