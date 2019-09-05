#!/usr/bin/python

# from prettytable import PrettyTable

def X(hyper_dim, face_dim):
    if face_dim > hyper_dim:
        return 0
    if hyper_dim == face_dim:
        return 1
    if face_dim == 0:
        return 2 ** hyper_dim
    return X(hyper_dim - 1, face_dim) * 2 + X(hyper_dim - 1, face_dim - 1)


def formated_args(*args, **kwargs):
    str_args = [str(a) for a in args]
    str_kwargs = [str(k) + '=' + str(kwargs[k]) for k in kwargs]
    str_all = str_args
    str_all.extend(str_kwargs)
    return ', '.join(str_all)


def pretty_str(obj, *args, **kwargs):
    return '{}({}) = {}'.format(
        obj.__name__,
        formated_args(*args, **kwargs),
        obj(*args, **kwargs)
    )


def pretty(obj, *args, **kwargs):
    print(pretty_str(obj, *args, **kwargs))


for i in range(12, 14):
    for j in range(i + 1):
        pretty(X, i, j)
    print()

dict_ = {}
dict_[(1,'a')] = 10
print(dict_)
# pretty(X, 50, 25)

# print('X(3, {}) = {}'.format(i, X(3, i)))
