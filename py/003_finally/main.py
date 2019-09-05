
def foo():
    try:
        print('before return')
        return
    finally:
        print('finally')


print('hi')
foo()
print('goodbye')
