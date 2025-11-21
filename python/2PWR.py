def is_power_of_two(n):
    if n < 0:
        raise ValueError("Negative numbers are not allowed")
    if n == 0:
        return False

    return (n & (n - 1)) == 0
try:
    num = int(input("Enter a number: "))
    if is_power_of_two(num):
        print("Power of 2")
    else:
        print("Not a power of 2")
except ValueError as e:
    print("Error:", e)