from random import randint
n = int(input())


def f(x):
    return (x**2 + 1) % n


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def rho(n):
    x = randint(1, n - 2)
    y = x
    cnt = int(n**0.25) * 3
    while(abs(gcd(n, x - y))) in [1, n] and cnt > 0:
        x = f(f(x))
        y = f(y)
        cnt -= 1

    return abs(gcd(n, x - y))


def squre_fact(n):
    a = 2
    while a**2 <= n:
        if n % a == 0:
            return a
        a += 1

    return 1


if n < 10 ** 9:
    ans = squre_fact(n)
else:
    ans = rho(n)

if abs(ans) in [1, n]:
    print("IMPOSSIBLE")
else:
    ans = abs(ans)
    print(ans, n // ans)
