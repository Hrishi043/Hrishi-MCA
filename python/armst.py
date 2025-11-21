for num in range(100, 500):
    s = str(num)
    total = sum(int(d)**3 for d in s)

    if total == num:
        print(num)
