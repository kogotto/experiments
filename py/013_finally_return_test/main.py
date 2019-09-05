#!/usr/bin/python

def foo():
    try:
        return 1
    finally:
        return 2


print(foo())
