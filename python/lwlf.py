def arrange_string(s):
    lower = []
    upper = []

    for ch in s:
        if ch.islower():
            lower.append(ch)
        else:
            upper.append(ch)

    return "".join(lower + upper)

s = input("Enter a string: ")
print(arrange_string(s))
