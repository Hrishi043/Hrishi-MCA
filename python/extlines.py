def extract_lines(filename):
    with open(filename, "r") as file:
        for line in file:
            words = line.split()
            for w in words:
                if len(w) >= 2 and w[0].lower() == 's' and w[-1].lower() == 'e':
                    print(line.strip())
                    break
extract_lines("test.txt")