class Flower:
    def __init__(self, name):
        self.name = name
name = input("Enter flower name: ")
f = Flower(name)


add_color = input("Do you want to add petal color? (yes/no): ").strip().lower()

if add_color == "yes":
    color = input("Enter petal color: ")
    f.petalColor = color   


if hasattr(f, "petalColor"):
    print(f"{f.petalColor} {f.name}")
else:
    print("Unknown Flower")