#!/usr/bin/python

import math

def integers():
    result = 1
    while True:
        yield result
        result += 1


def is_prime(n):
    if n == 1:
        return False
    for i in range(2, int(math.sqrt(n))):
        if n % i == 0:
            return False
    return True


def primes():
    for i in integers():
        if is_prime(i):
            yield i


def nth_prime(n):
    primes_ = primes()
    result = 0
    for i in range(n):
        result = next(primes_)
    return result

def skip(gen, n):
    for i in range(n):
        next(gen)

# primes_ = primes()
# skip(primes_, 100000)
# # print(next(primes_))
# for p in primes_:
#     print(p)


def divisitors(n):
    return [
        i for i in range(1, n + 1) if n % i == 0
    ]


def is_divisible(n, d):
    return n % d == 0


def prime_div(n):
    result = []
    for p in primes():
        if n == 1:
            return result
        while is_divisible(n, p):
            n /= p
            result.append(p)


print(divisitors(10))
for i in range(1, 50):
    print(prime_div(i))
# print(divisitors(115050851))

# for i in range(10):
#     print(nth_prime(i))
