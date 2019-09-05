#! /usr/bin/python

import sys

class FibCalculator:
    def __init__(self):
        self.cache = {
            0: 0,
            1: 1,
        }

    def __call__(self, n):
        result = self.cache.get(n)
        if result is None:
            self.cache[n] = self(n - 1) + self(n - 2)
        return self.cache[n]

    def __str__(self):
        return self.cache.__str__()
        return 'cache size = {}'.format(len(self.cache))

print('fuck')

f = FibCalculator()

print(sys.getrecursionlimit())
sys.setrecursionlimit(10000)
print(sys.getrecursionlimit())

print(f(50))
# print(f(1000))
print(f)
