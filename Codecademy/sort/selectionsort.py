'''
Selection Sort
* improvements on the bubble sort by making only one exchange for every pass
* looks for the largest value as it makes a pass
* after completing the pass, places it in the proper location
* * requires n-1 passes to sort n items => O(n^2)
'''

def selectionSort(alist):
    for fillslot in range(len(alist)-1, 0, -1):
        positionOfMax = 0
        for location in range(1, fillslot+1):
            if alist[location] > alist[positionOfMax]:
                positionOfMax = location
        
        alist[fillslot] , alist[positionOfMax] = alist[positionOfMax], alist[fillslot]


# time complexity = O(n^2)