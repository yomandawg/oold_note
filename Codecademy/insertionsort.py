'''
Insertion Sort
* like a card game
* pick an element and insert it into sorted sequence
'''

def insertionSort(arr):
    # traverse through 1 to len(arr)
    for idx in range(1, len(arr)):
        current_val = arr[idx]

        # move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        position = idx
        while position > 0 and arr[position-1] > current_val:
            arr[position] = arr[position-1]
            position -= 1
        arr[position] = current_val

'''
avg case: O(n^2)
worst case: O(n^2)
best case: O(n) - in case for an already sorted list

* shifting vs. exchanging: shifting(1/3 of processing work)
'''