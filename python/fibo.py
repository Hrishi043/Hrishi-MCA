# Fibonacci numbers
x = int(input("Enter your num: "))
a, b = 0, 1
if x <= 0:
    print("Fibonacci not available!")
elif x == 1:
    print("Fibonacci of 1 term:")
    print(a)
else:
    print(f"Fibonacci sequence of {x} terms:")
    for i in range(x):
        print(a, end=" ")
        a, b = b, a + b
    print() 
