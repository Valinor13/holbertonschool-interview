#!/usr/bin/python3
""" This module counts collected rain water """


def rain(walls):
    """
        rain - function to perform the count
        @walls - incoming list of walls to retain water
        Return - returns the amount of rainwater, 0 if list doesn't exist
    """

    if not walls:
        return 0

    raincount = 0

    for i in range(0, len(walls)):
        if walls[i] != 0:
            for j in range(i + 1, len(walls)):
                if walls[j] != 0:
                    if walls[i] <= walls[j]:
                        height = walls[i]
                    else:
                        height = walls[j]
                    raincount += ((j - i) - 1) * height
                    break

    return raincount
