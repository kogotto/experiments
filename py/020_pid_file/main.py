#!/usr/bin/python


import pid
import time


def main():
    print('hi')
    time.sleep(10)
    print('bye')


if __name__ == '__main__':
    with pid.PidFile():
        main()
