
def gcd_naive(a, b):
    for i in range(min(a, b), 0, -1):
        if a % i == 0 and b % i == 0:
            return i
    return 1
def gcd_euclidean(a, b):
    if a < b:
        a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a

def gcd_recursive(a, b):
    if a == 0:
        return b
    if b == 0:
        return a
    return gcd_recursive(b, a % b)

def gcd_binary(a, b):
    if a == 0:
        return b
    if b == 0:
        return a
    if a == b:
        return a
    if a % 2 == 0 and b % 2 == 0:
        return 2 * gcd_binary(a // 2, b // 2)
    if a % 2 == 0:
        return gcd_binary(a // 2, b)
    if b % 2 == 0:
        return gcd_binary(a, b // 2)
    if a > b:
        return gcd_binary((a - b) // 2, b)
    return gcd_binary((b - a) // 2, a)

def gcd_extended(a, b):
    if a<b:
        a, b = b, a
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = gcd_extended(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y