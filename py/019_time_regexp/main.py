#!/usr/bin/python


import re


def accepted():
    for h in range(0, 24):
        for m in range(0, 60):
            m_str = '0{}'.format(m) if m < 10 else str(m)
            if h < 10:
                yield '0{}:{}'.format(h, m_str)
            yield '{}:{}'.format(h, m_str)


def rejected():
    for h in range(25, 100):
        for m in range(0, 60):
            if m < 10:
                yield '{}:0{}'.format(h, m)
            yield '{}:{}'.format(h, m)


pattern = '^([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$'

print(all([re.match(pattern, x) for x in accepted()]))
print(not any([re.match(pattern, x) for x in rejected()]))


# for r in rejected():
#     print(r)

# for a in accepted():
#     print(a)
