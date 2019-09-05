#!/usr/bin/python

s = 'some str'

if s == 'some str' or s == 'another str':
    print('match')
else:
    print('miss')

if s in [
        'some str',
        'another str',
        ]:
    print('match2')
else:
    print('miss2')
