#!/usr/bin/python3

""" This module contains a solution to the lockboxes problem """


from typing import List


key_dict = {}


def key_path(key: int, boxes: List[List[int]]):
    if key_dict[key] is False:
        key_dict[key] = True
        for new_key in boxes[key]:
            key_path(new_key, boxes)


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

    for i in range(0, len(boxes)):
        key_dict[i] = False

    for key in boxes[0]:
        key_path(key, boxes)

    if 0 in key_dict.keys():
        del key_dict[0]

    for value in key_dict.values():
        if value is False:
            return False

    return True
