#! /usr/bin/python3

import texttable

def create_ants(left, right):
    result = [
        1 for _ in range(left)
    ]

    result.extend([
        0 for _ in range(right)
    ])

    return result


def count_collisions(ants):
    result = 0
    for i in range(len(ants) - 1):
        if ants[i] == 1 and ants[i + 1] == 0:
            result += 1
    return result


def next_iter(ants):
    # print(ants)
    result = [i for i in ants]
    for i in range(len(ants) - 1):
        if ants[i] == 1 and ants[i + 1] == 0:
            result[i] = 0
            result[i + 1] = 1
    return result


def count(ants):
    result = count_collisions(ants)
    if result != 0:
        result += count(next_iter(ants))
    return result



def sym_ants(n):
    ants = create_ants(n, n)
    return count(ants)


def gen_ants(n, m):
    ants = create_ants(n, m)
    return count(ants)


def test(n, m):
    tab = texttable.Texttable()
    header = ['']
    header.extend([str(i) for i in range(m)])
    tab.header(header)
    for i in range(n):
        row = [i]
        for j in range(m):
            row.append(gen_ants(i, j))
        tab.add_row(row)

    print(tab.draw())


# gen_ants(5, 2)
test(20, 13)
