n=int(input("Enter no of Rows:"))
for i in range(1, n+1):
    print("   "*(n-i),end=" ")
    print(" * " *(2*i-1))