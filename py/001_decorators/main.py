print 'sss'

def dec(func):
    def impl(*args, **kwargs):
        print('before')
        func(*args, **kwargs)
        print('after')
    return impl


@dec
def foo(x):
    print('foo()')
    print(x)

def bar():
    print('bar()')

bar = dec(bar)

foo(5)
bar()
