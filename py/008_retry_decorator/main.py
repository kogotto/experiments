#!  /usr/bin/python3


def test(*args, **kwargs):
    print('args')
    for arg in args:
        print(arg)
    print('kwargs')
    for key in kwargs:
        print(key, kwargs[key])


def retry(count, cls=Exception):

    def decor(func):

        def retrying(*args, **kwargs):
            exceptions = []
            for _ in range(count):
                try:
                    return func(*args, **kwargs)
                except cls as e:
                    exceptions.append(e)
                    print('try #{} failed'.format(_))
            raise Exception(*exceptions)

        return retrying

    return decor


def generator():
    for i in range(10) :
        yield i


@retry(5)
def foo(gen):
    n = next(gen)
    if n == 0:
        return 5 / n
        raise TypeError()
    elif n == 1:
        raise ValueError(n)
    else:
        raise KeyError()
    print(n)


try:
    foo(generator())
except Exception as e:
    print(e)
    for ex in e.args:
        print(ex)

# try:
#     print('start')
#     raise Exception
# except Exception:
#     print('catch Exception')
# finally:
#     print('finally')
