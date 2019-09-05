import os

def ignore_except(func):
    def impl(*args, **kwargs):
        try:
            return func(*args, **kwargs)
        except:
            pass

    return impl


@ignore_except
def foo():
    raise Exception()


@ignore_except
def bar(arg):
    print(int(arg))


foo()
bar('aaa')
bar('123')

os.remove('djkfa')
