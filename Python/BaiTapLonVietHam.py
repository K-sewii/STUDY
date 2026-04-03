from math import *
from sys import stdin
#Ham 1
def ham1(n):
    for i in range(2, isqrt(n) + 1):
        if n % i == 0:
            return False
    return n > 1
#ham 2
def ham2(n):
    tong = 0
    while(n != 0):
        tong += n % 10
        n //= 10
    return tong
#ham 3
def ham3(n):
    tong = 0
    while n != 0:
        if n % 10 % 2:
            tong += n % 10
        n //= 10
    return tong
#ham 4
def ham4(n):
    tong = 0
    while n != 0:
        r = n % 10
        if r == 2 or r == 3 or r == 5 or r == 7:
            tong += r
        n //= 10
    return tong
#ham 5
def ham5(n):
    rev = 0
    while n != 0:
        rev += rev*10 + n % 10
        n //= 10
    return rev
#ham 6
def ham6(n):
    dem = 0
    for i in range(2, isqrt(n) + 1):
        if n % i == 0:
            dem += 1
            while n % i == 0:
                n //= i
    if n > 1:
        dem += 1
    return dem 
# ham 7
def ham7(n):
    res = -1
    for i in range(2, isqrt(n) + 1):
        if n % i == 0:
            res = i
            while n % i == 0:
                n //= i
    if n > 1:
        res = n 
    return res 
# ham 8
def ham8(n):
    while n != 0:
        if n % 10 == 6:
            return 1
        n //= 10
    return 0
#ham 9
def ham9(n):
    tong = 0
    while n != 0:
        tong += n % 10
        n //= 10
    if tong == 8:
        return 1
    else: return 0
# ham 10
def ham10(n):
    tong = 0
    while n != 0:
        tong += factorial(n % 10)
        n //= 10
    return tong
#ham 11
def ham11(n):
    donvi = n % 10
    while n != 0:
        if donvi != n % 10:
            return 0
        n //= 10
    return 1
#ham 12
def ham12(n):
    donvi = n % 10
    while n != 0:
        if donvi < n % 10:
            return 0
        n //= 10
    return 1
#ham 13
def ham13(n):
    m = n
    cnt = 0
    while n != 0:
        cnt += 1
        n //= 10
    tong = 0
    while m != 0:
        tong += (m % 10) ** cnt
        m //= 10
    return tong
if __name__ == '__main__':
    # for s in stdin:
        # a += list(map(int, s.split()))
    n = int(input())
    print(ham1(n))
    print(ham2(n))
    print(ham3(n))
    print(ham4(n))
    print(ham5(n))
    print(ham6(n))
    print(ham7(n))
    print(ham8(n))
    print(ham9(n))
    print(ham10(n))
    print(ham11(n))
    print(ham12(n))
    print(ham13(n))

