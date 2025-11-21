def nearly_equal(a, b):
    la, lb = len(a), len(b)

    if abs(la - lb) > 1:
        return False

    if la == lb:
        diff = sum(1 for x, y in zip(a, b) if x != y)
        return diff == 1

    if la == lb + 1:
        for i in range(la):
            if a[:i] + a[i+1:] == b:
                return True
        return False

    if lb == la + 1:
        for i in range(lb):
            if b[:i] + b[i+1:] == a:
                return True
        return False
    
s1 = input("Enter first string: ")
s2 = input("Enter second string: ")

print("Nearly equal?", nearly_equal(s1, s2))