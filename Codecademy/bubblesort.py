'''
O(n^2)

* bubble sort swaps elements if the element on the left is larger than the one on the right
* for nearly sorted lists: few operations since it only performs a swap when elements are out of order

* swaps repeatedly until the largest element in the list is placed at the greatest index
'''

'''
optimize unnecessary iteration
to simplify to (n^2-n)/2
'''

nums = [9, 8, 7, 6, 5, 4, 3, 2, 1]
print("PRE SORT: {0}".format(nums))

def swap(arr, index_1, index_2):
    temp = arr[index_1]
    arr[index_1] = arr[index_2]
    arr[index_2] = temp

def bubble_sort_unoptimized(arr):
    iteration_count = 0
    for el in arr:
        for index in range(len(arr)-1):
            iteration_count += 1
            if arr[index] > arr[index+1]:
                swap(arr, index, index+1)    
    print("PRE-OPTIMIZED ITERATION COUNT: {0}".format(iteration_count))

def bubble_sort(arr):
    iteration_count = 0
    for i in range(len(arr)):
        for idx in range(len(arr)-i-1):
            iteration_count += 1
            if arr[idx] > arr[idx+1]:
                arr[idx], arr[idx+1] = arr[idx+1], arr[idx]
    print("POST-OPTIMIZED ITERATION COUNT: {0}".format(iteration_count))

bubble_sort_unoptimized(nums.copy())
bubble_sort(nums)
print("POST SORT: {0}".format(nums))