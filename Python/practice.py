from math import *
from functools import cmp_to_key
from collections import Counter

def nt(n):
    for i in range(2, isqrt(n) + 1):
        if n % i == 0:
            return False
    return n > 1
if __name__ == '__main__':
    n, m = map(int, input().split())
    a = []
    for _ in range(n):
        b = list(map(int, input().split()))
        a.append(b)
    for i in range(n):
        for j in range(m):
            if nt(a[i][j]):
                print(a[i][j], end = " ")
        print()
