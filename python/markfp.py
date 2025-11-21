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

    def display(self):
        total = self.maths + self.computer
        percentage = total / 2   
        
        print("---- Student Details ----")
        print(f"Name: {self.name}")
        print(f"Roll: {self.roll}")
        print(f"Maths Marks: {self.maths}")
        print(f"Computer Marks: {self.computer}")
        print(f"Percentage: {percentage}%")
        
        if percentage >= 50:
            print("Result: PASS")
        else:
            print("Result: FAIL")
s1 = Student("Alice", 101, 60, 70)
s1.display()

s2 = Student("Bob", 102, 40, 35)
s2.display()