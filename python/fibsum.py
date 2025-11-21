def generate_fibonacci(n):
    if n < 0:
        raise ValueError("Number of terms cannot be negative")

    a, b = 0, 1
    fib_series = []

    for _ in range(n):
        fib_series.append(a)
        a, b = b, a + b

    return fib_series


def sum_even_terms(series):
    return sum(x for x in series if x % 2 == 0)


try:
    n = int(input("Enter number of terms: "))
    fib = generate_fibonacci(n)

    print("Fibonacci Series:", *fib)

    even_sum = sum_even_terms(fib)
    print("Sum of even terms:", even_sum)

except ValueError as e:
    print("Error:", e)