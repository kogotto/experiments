#!/usr/bin/python


import re


def accepted():
    for i in range(10000000):
        yield str(i)

def rejected():
    yield 'abc'

pattern = '\d+'
matcher = re.compile(pattern)

print(all([matcher.match(x) for x in accepted()]))
print(not any([matcher.match(x) for x in rejected()]))


# for r in rejected():
#     print(r)

# for a in accepted():
#     print(a)
