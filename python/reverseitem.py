def reverse_items(lst):
    new_list = []
    for item in lst:
        new_list.append(item[::-1])
    return new_list
data = ["apple", "banana", "cat"]
result = reverse_items(data)
print(result)