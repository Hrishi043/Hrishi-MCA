#1. Accept full name and display in reverse order with space between the words.
'''def reversed_name(full_name):
    words=full_name.split()
    rev_words=words[::-1]
    rev_name="".join(rev_words)
    return rev_name
name=input("Enter your name:")
print("reversed order: ",reversed_name(name))'''

#2.	 Accept a list of single digit numbers as input string. Concatenate the elements of the list as a single number.
'''def concatenate_Num(num_list):
    result=''.join(str(num)for num in num_list)
    return int(result)
numbers=input("Enter single  digit: ").split()
print("concatentate_num: ",concatenate_Num(numbers))'''

#3.	Write a program to search an item in a given list and display the number of occurrences of the given item. 
def count(item, lst):
    return lst.count(item)
my_list = [1, 2, 3, 4, 1, 2, 1, 5, 1]
item = int(input("Enter the item : "))
occurrences = count(item, my_list)
print(f"The item {item} appears {occurrences} times in the list.")
