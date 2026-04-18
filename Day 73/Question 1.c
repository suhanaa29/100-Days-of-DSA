/*Question 1: First Non-Repeating Character*/

def first_non_repeating(s):
    char_count = {}
    
    for char in s:
        char_count[char] = char_count.get(char, 0) + 1
    
    for char in s:
        if char_count[char] == 1:
            return char
            
    return '$'

print(first_non_repeating("geeksforgeeks"))
