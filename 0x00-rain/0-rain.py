#!/usr/bin/python3
""" This module counts collected rain water """


def rain(walls):
    """
        rain - function to perform the count
        @walls - incoming list of walls to retain water
        Return - returns the amount of rainwater, 0 if list doesn't exist
    """

    if not walls or len(walls) < 3:
        return 0

    rainwater = 0

    for i in range(0, len(walls)):
        pre = max(walls[:i + 1])
        post = max(walls[i:])
        rainwater += min(pre, post) - walls[i]

    return rainwater
