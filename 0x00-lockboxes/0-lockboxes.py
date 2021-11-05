#!/usr/bin/python3
""" This module contains a solution to the lockboxes problem """


from typing import List


def canUnlockAll(boxes: List[List[int]]) -> bool:
    """
    """
    key_dict = {}
    sig = 0

    for box_num, box in enumerate(boxes):
        for key in box:
            key_dict[key] = box_num

    for i in range(1, len(boxes)):
        if key_dict[i] >= i:
            sig = 1
            break

    if sig == 1:
        return False

    return True
