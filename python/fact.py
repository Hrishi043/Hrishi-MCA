n=int(input("Enter a Num:"))
fact=1
if n<0:
    print("factorial not available!")
elif n==0:
    print("Factorial of 0 is 1")
else:
    for i in range(1,n+1):
        fact*=i
        print(f"factorial of {n} is {fact}")