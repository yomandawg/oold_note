'''
Heap Sort
* comparison based sorting technique based on binary heap
* similart o selection sort
* repeat the same process for remaining element
'''

# To heapify subtree rooted at index i
# n is size of heap
def heapify(arr, n, i):
    largest = i # initialize largest as root
    l = 2*i+1 # left = 2*i+1
    r = 2*i+2 # right = 2*i+2

    # see if left child of root exists and is greater than root
    if l < n and arr[i] < arr[l]:
        largest = l

    # see if right child of root exists and is greater than root
    if r < n and arr[largest] < arr[r]:
        largest = r

    # change root, if needed
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i] # swap
    
        # heapify the root
        heapify(arr, n, largest)


def heapSort(arr):
    n = len(arr)

    # build a maxheap
    for i in range(n, -1, -1):
        heapify(arr, n, i)
    
    # one by one extract elements
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i] # swap
        heapify(arr, i, 0)