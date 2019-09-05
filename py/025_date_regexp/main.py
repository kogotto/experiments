#!  /usr/local/bin/python3

import re
import datetime

pattern = '^([12]\d{3}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]))$'
matcher = re.compile(pattern)

def get_date_string(year, month, day):
    return '{}-{}-{}'.format(
        str(year).zfill(4),
        str(month).zfill(2),
        str(day).zfill(2)
    )


def datetime_check(year, month, day):
    try:
        datetime.date(year, month, day)
    except ValueError:
        return False
    return True


def matcher_check(date_str):
    return matcher.match(date_str) is not None


# for year in range(1000, 4000):
for year in range(1000, 1001):
    for month in range(1, 13):
        for day in range(1, 32):
            date_str = get_date_string(year, month, day)
            matcher_result = matcher_check(date_str)
            datetime_result = datetime_check(year, month, day)

            if not matcher_result and datetime_result:
                print(date_str)

#             if matcher_result != datetime_result:
#                 print('{} matcher {} datetime {}'.format(
#                     date_str,
#                     matcher_result,
#                     datetime_result
#                 ))
