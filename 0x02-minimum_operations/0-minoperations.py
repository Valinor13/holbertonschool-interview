#!/usr/bin/python3
""" Minimum Operations Module """


def minOperations(n: int) -> int:
    """ Finds and returns minimum number of operations required """

    if not n or not isinstance(n, int) or n <= 1:
        return 0
    op_count = 1
    count_list = []
    while n > 1:
        op_count += 1
        while(n % op_count == 0 and n > 1):
            n /= op_count
            count_list.append(op_count)
    return sum(count_list)
