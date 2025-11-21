def print_alternate(s):
    if len(s) == 0:
        return
    print(s[0], end="")
    print_alternate(s[2:])
text = "Hello World"
print_alternate(text)
print()