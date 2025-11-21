class Book:
    def __init__(self, title, author):
        self.title = title
        self.author = author
b1 = Book("1984", "George Orwell")
b1.publisher = "Secker & Warburg"
def print_book_info(book):
    if hasattr(book, 'publisher'):
        print(f"{book.title} written by {book.author} is published by {book.publisher}")
    else:
        print("Unknown Publisher")
print_book_info(b1)
b2 = Book("To Kill a Mockingbird", "Harper Lee")
print_book_info(b2)