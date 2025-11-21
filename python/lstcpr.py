l1 = input("Enter first list (comma separated): ").split(",")
l2 = input("Enter second list (comma separated): ").split(",")
l1 = [x.strip() for x in l1]
l2 = [x.strip() for x in l2]
if l1 == l2:
    print("Lists are equal")
else:
    print("Lists are NOT equal")
