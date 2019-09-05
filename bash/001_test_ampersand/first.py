#!/usr/bin/python3

import datetime

while True:
    with open('res', 'a') as f:
        f.write(str(datetime.datetime.utcnow()) + '\n')
