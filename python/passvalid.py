def is_valid_password(pwd):
    if not (6 <= len(pwd) <= 16):
        return False

    has_lower = False
    has_upper = False
    has_digit = False
    has_special = False
    special_chars = "$#@"

    for ch in pwd:
        if ch.islower():
            has_lower = True
        elif ch.isupper():
            has_upper = True
        elif ch.isdigit():
            has_digit = True
        elif ch in special_chars:
            has_special = True

    return has_lower and has_upper and has_digit and has_special


password = input("Enter password: ")

if is_valid_password(password):
    print("Valid Password")
else:
    print("Invalid Password")