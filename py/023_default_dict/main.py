#!/usr/bin/python

import collections as c

class MyDD(c.defaultdict):
    def __init__(self, default_value, other_dict):
        super().__init__(lambda: default_value, other_dict)

d = dict(value1='1', value2='2')
m = MyDD('default', d)
print(m['value1'])
print(m['value2'])
print(m['value3'])
