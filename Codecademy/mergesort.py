'''
Merge sorting takes two steps:
1. splitting the data into "runs" or smaller components
2. re-combining those runs into sorted lists(merge)

* when splitting the data, we divide the input to our sort in half.
* then, recursively calls the sort on each of those halves
* the process continues until all of the lists contain only a single element
* then begin merging: when merging two single-element lists, we check if the first element is smaller or larger than the other
* then we return the two-element list with the smaller element followed by the larger element

Merging
* When merging larger pre-sorted lists, we build the list similarly to how we did with single-element lists
* let's call the two lists `left` and `right
* both `left` and `right` are already sorted.
    - we want to combine them(merge them) into a larger sorted list
    - we'll need to iterate through both with two indices
    - at first `left_index` and `right_index` both point to the start of their respective lists
    - `left_index` points to the smallest element of `left` and `right_index` so on.
    - the smaller of these two elements should be the first element of both
    - this process of "look at the two next-smallest elements of each list and add the smaller one to our resulting list" continues on for as long as both lists have elements to compare
    - once one list is exhausted, say every element from `left` has been added to the result, then we know that all the elmenets of the other list `right` shoud go at the end of the resulting list

Performance - O(nlog(n))
* best, worst, avg time complexity are all the same: O(nlog(n))
* almost-sorted list will take the same amount of time as a completely out of order list
* worst-case scenario is as fast as a sorting algorithm can be
* improve by looking for "runs" that are already pre-sorted
    - Timsort(use pre-sorted data in a list to the sorting algorithm's advantage: best-case O(n))
* also requires space
    - each separation requires temporary array(N)
    - worst case space complexity of merge sort: O(N)
'''

'''
Separation
1. separate the data into smaller lists
2. break those lists into even smaller lists
'''


def merge_sort(items):
    if len(items) <= 1:
        return items

    middle_index = len(items) // 2
    left_split = items[:middle_index]
    right_split = items[middle_index:]

    left_sorted = merge_sort(left_split)
    right_sorted = merge_sort(right_split)

    return merge(left_sorted, right_sorted)


def merge(left, right):
    result = []
    
    while (left and right):
        if left[0] < right[0]:
            result.append(left[0])
            left.pop(0)
        else:
            result.append(right[0])
            right.pop(0)

    if left:
        result += left
    if right:
        result += right
        
    return result
