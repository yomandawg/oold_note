def factorial(n):
    if n < 0:
        ValueError("Inputs 0 or greater only") 
    if n <= 1:
        return 1
    return n*factorial(n-1)

def fibonacci(n):
    if n < 0:
        ValueError("Input 0 or greater only!")
    if n <= 1:
        return n
    return fibonacci(n-1)+fibonacci(n-2)

def sum_digits(n):
    if n <= 9:
        return n
    last_digit = n%10
    return sum_digits(n//10)+last_digit

def find_min(my_list, min=None):
    if not my_list:
        return min
    if not min or my_list[0] < min:
        min = my_list[0]
    return find_min(my_list[1:], min)

def is_palindrome(str):
    if len(str) < 2:
        return True
    if str[0] != str[-1]:
        return False
    return is_palindrome(str[1:-1])

def multiplication(num_a, num_b):
    if num_a == 0 or num_b == 0:
        return 0
    return num_a + multiplication(num_a, num_b-1)

def depth(tree):
    if not tree:
        return 0
    left_depth = depth(tree["left_child"])
    right_depth = depth(tree["right_child"])
    if left_depth > right_depth:
        return left_depth + 1
    else:
        return right_depth + 1
    
def build_bst(my_list):
    if len(my_list) == 0:
        return None 
    mid_idx = len(my_list) // 2
    mid_val = my_list[mid_idx]
    tree_node = {"data": mid_val}
    tree_node["left_child"] = build_bst(my_list[:mid_idx])
    tree_node["right_child"] = build_bst(my_list[mid_idx+1:])
    return tree_node