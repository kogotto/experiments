#!/usr/bin/python3

import os

for i in range(2):
    print(i)
    this_pid = os.getpid()
    pid = os.fork()
    if pid == 0:
        print('i was born by {}, my pid is {}.'
                .format(this_pid, os.getpid()))
    else:
        print('i became a parent of {}, my pid is {}'
                .format(pid, this_pid))
        os.waitpid(pid, 0)
