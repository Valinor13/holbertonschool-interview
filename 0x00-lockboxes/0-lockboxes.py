#!/usr/bin/python3
""" This module contains a solution to the lockboxes problem
        Global Variables:
            key_dict: dict - stores bool determination of key availability """


from typing import List


key_dict: dict = {}


def key_path(key: int, boxes: List[List[int]]):
    """ Key Path: Recursively follows the path of each key in box 0
            Params:
                key: int - the key path being traced
                boxes: List[List[int]] - List of lists containing ints
                                        representing keys that open more boxes
            Variables:
                new_key: int - the next key in the path to trace
            Return:
                Updates key_dict if necessary and returns void """

    if key_dict[key] is False:
        key_dict[key] = True
        for new_key in boxes[key]:
            key_path(new_key, boxes)


def canUnlockAll(boxes: List[List[int]]) -> bool:
    """ Can Unlock All: Checks to see if all boxes can be unlocked
            Params:
                boxes: List[List[int]] - List of lists containing ints
                                        representing keys that open more boxes
            Return:
                Boolean indicating success of attempt to open all boxes """

    for i in range(0, len(boxes)):
        key_dict[i] = False

    for key in boxes[0]:
        key_path(key, boxes)

    del key_dict[0]

    for value in key_dict.values():
        if value is False:
            return False

    return True
