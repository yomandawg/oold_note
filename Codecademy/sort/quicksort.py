'''
Quicksort

* efficient recursive algorithm for sorting arrays or lists of values
* using "comparison" sort, where values are ordered by a comparison operation
* "divide and conquer" strategy, breaking the problem into smaller sub-problems until the solution is clear

* break the array into sub-arrays containing at most one element
* choose a single `pivot` element from the list.
* every other element is compared with the pivot, which `partitions` the array into three groups
    1. a sub-array of elements smaller than the pivot
    2. the pivot itself
    3. a sub-array of elements greater than the pivot
* the process is repeated on the sub-arrays until they contain zero or one element
    - element in the "smaller than" group are never compared with elements in the "greater than" group
    - if the smaller and greater groupings are roughly equal, this cuts the problem in half with each partition step
* the sub-arrays of one element each are recombined into a new array with sorted ordering

* key to quicksort's runtime efficiency is the division of the array
* the array is partitioned according to comparisons with the pivot element
    - so which pivot is the optimal choice?
* worst case occurs when we have an imbalanced partition like when the first element is continually chosen in a sorted data-set
* popular strategy: take the first, middle, and last elements and choose the median element as the pivot
    - division of the array tends to be more uniform

* worst case: O(n^2), avg case: O(nlogn)
* generally refer to it as O(nlogn)
'''

from random import randrange, shuffle

def quicksort(list, start, end):
    # this portion of list has been sorted
    if start >= end:
        return
    print("Running quicksort on {0}".format(list[start:end+1]))
    # select random element to be pivot
    pivot_idx = randrange(start, end+1)
    pivot_element = list[pivot_idx]
    print("Selected pivot {0}".format(pivot_element))
    # swap random element with last element in sub-lists
    list[end], list[pivot_idx] = list[pivot_idx], list[end]

    # tracks all elements which should be to left (lesser than) pivot
    less_than_pointer = start

    for i in range(start, end):
        # we found an element out of place
        if list[i] < pivot_element:
            # swap element to the right-most portion of lesser elements
            print("Swapping {0} with {1}".format(list[i], pivot_element))
            list[i], list[less_than_pointer] = list[less_than_pointer], list[i]
            # tally that we have one more lesser element
            less_than_pointer += 1
    
    # move pivot element to the right-most portion of lesser elements
    list[end], list[less_than_pointer] = list[less_than_pointer], list[end]
    print("{0} successfully partitioned".format(list[start:end+1]))
    # recursively sort left and right sub-lists
    quicksort(list, start, less_than_pointer-1)
    quicksort(list, less_than_pointer+1, end)

list = [5,3,1,7,4,6,2,8]
shuffle(list)
print("PRE SORT: ", list)
print(quicksort(list, 0, len(list) -1))
print("POST SORT: ", list)
