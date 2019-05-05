'''
Radix Sort
> for sorting numbers
* number system
* radix(base)
* use digits to represent different values when they're used in different position
* numbers are bucketed based on the value of digits moving left to right
* non-comparison sort => O(n)

Base Numbering System
* MSD and LSD
* bucketing process
    - organize the input list into ten buckets(one for each digit)
    -  base on the MSD, LSD
    - 2367 => "2" for MSD and "7" for LSD
    - repeated until all digits in the longest number have been considered
* example
    - 23, 25, 126
    (1) '3', '5', '6' for initial LSD bucketing
    (2) '2' for second LSD bucketing
    and so on
    - preserved the order
* performance
    - manages to sort a list of integers without performing any comparisons
        - non-comparison sort
    - continue iterating(n) until we examine each digit
    - we need to iterate for how ever many digits we have
    - avg number of digits == word-size or `w`
    - O(wn) => if treat `w` as a constant factor w => O(n)
'''


'''
max exponent
* utilize string representation of each integer
* count each digit in a number from right-to-left
* some other implementations utilize integer division and modular arithmetic to find each digit
'''

'''
* takes numbers in an input list
* passes through each digit in those numbers, from least to most significant
* looks at the values of those digits
* buckets the input list according to those digits
* renders the results from that bucketing
* repeats this process until the list is sorted
'''

def radix_sort(to_be_sorted):
    maximum_value = max(to_be_sorted)
    max_exponent = len(str(maximum_value))
    being_sorted = to_be_sorted[:]
    
    for exponent in range(max_exponent):
        position = exponent+1
        index = -position

        digits = [[] for _ in range(10)]

        for number in being_sorted:
            number_as_a_string = str(number)
            try:
                digit = number_as_a_string[index]
                digit = int(digit)
            except IndexError:
                digit = 0

            digits[digit].append(number)
        
        being_sorted = []
        for numeral in digits:
            being_sorted.extend(numeral)
        
    return being_sorted


unsorted_list = [830, 921, 163, 373, 961, 559, 89, 199, 535, 959, 40, 641, 355, 689, 621, 183, 182, 524, 1]

print(radix_sort(unsorted_list))