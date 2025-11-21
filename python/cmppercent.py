class Person:
    def __init__(self, name, roll):
        self.name = name
        self.roll = roll

class Marks:
    def __init__(self, maths, computer):
        self.maths = maths
        self.computer = computer

class Student(Person, Marks):
    def __init__(self, name, roll, maths, computer):
        Person.__init__(self, name, roll)
        Marks.__init__(self, maths, computer)

    def percentage(self):
        return (self.maths + self.computer) / 2

    def display(self):
        pct = self.percentage()
        print("---- Student Details ----")
        print(f"Name: {self.name}")
        print(f"Roll: {self.roll}")
        print(f"Maths Marks: {self.maths}")
        print(f"Computer Marks: {self.computer}")
        print(f"Percentage: {pct}%")
        print("Result:", "PASS" if pct >= 50 else "FAIL")
        print()

s1 = Student("Alice", 101, 60, 70)   # 65%
s2 = Student("Bob", 102, 40, 35)     # 37.5%

s1.display()
s2.display()

if s1.percentage() > s2.percentage():
    print(f"{s1.name} has a higher percentage ({s1.percentage()}%) than {s2.name} ({s2.percentage()}%).")
elif s2.percentage() > s1.percentage():
    print(f"{s2.name} has a higher percentage ({s2.percentage()}%) than {s1.name} ({s1.percentage()}%).")
else:
    print("Both students have the same percentage.")