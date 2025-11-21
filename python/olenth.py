s = input("Enter a string (odd length > 7): ")

if len(s) <= 7 or len(s) % 2 == 0:
    print("Invalid input")
else:
    mid = len(s) // 2
    result = s[mid-1 : mid+2]
    print(result)
