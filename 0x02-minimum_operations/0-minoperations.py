#!/usr/bin/python3
""" Minimum Operations Module """


def minOperations(n: int) -> int:
    """ Finds and returns minimum number of operations required """

    if not n or n <= 1:
        return 0
    op_count = 0
    loop_count = 1

    while loop_count < n:
        if n % loop_count == 0:
            loop_count += loop_count
            op_count += 1
        op_count += 1
    return op_count
