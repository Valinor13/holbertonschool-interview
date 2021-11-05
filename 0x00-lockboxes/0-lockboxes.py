#!/usr/bin/python3
""" This module contains a solution to the lockboxes problem """


from typing import List


def canUnlockAll(boxes: List[List[int]]) -> bool:

    """ Can Unlock All: Checks to see if all boxes can be unlocked
            Params:
                boxes: List[List[int]] - List of lists containing ints
                                        representing keys that open more boxes
            Variables:
                key_dict: dict - stores keys with the boxes they are found in
                sig: int - signals if a box is accessed before its key
                box_num: int - tracks box number to store with keys in dict
                box: List[int] - each list stored in boxes
            Return:
                Boolean indicating success of attempt to open all boxes """

    key_dict = {}
    sig = 0

    for box_num, box in enumerate(boxes):
        for key in box:
            key_dict[key] = box_num

    for i in range(1, len(boxes)):
        if key_dict[i] <= i:
            sig = 1
            break

    if sig == 1:
        return False

    return True
