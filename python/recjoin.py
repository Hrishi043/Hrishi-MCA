def join_recursive(lst):
    if not lst:
        return ""
    if len(lst) == 1:
        return str(lst[0])
    return str(lst[0]) + "-" + join_recursive(lst[1:])
print(join_recursive(["a", "b", "c", "d"]))