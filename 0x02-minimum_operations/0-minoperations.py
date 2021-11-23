#!/usr/bin/python3
""" Minimum Operations Module """


def minOperations(n: int) -> int:
    """ Finds and returns minimum number of operations required """

    if not n or n <= 1:
        return 0
    loop_count = n
    op_count = 2
    while loop_count != 1:
        if loop_count % 2 == 0:
            loop_count /= 2
            op_count += 2
        else:
            loop_count -= 1
            op_count += 1
    return op_count
