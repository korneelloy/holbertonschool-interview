#!/usr/bin/python3


"""unlocking boxed"""


def canUnlockAll(boxes):
    """check if we can unlmock all boxes"""
    list_of_keys = boxes[0]

    closed_boxes = dict(enumerate(boxes))

    del closed_boxes[0]

    for key in list_of_keys:
        for index, keys in closed_boxes.items():
            if key == index:
                list_of_keys.extend(keys)
                del closed_boxes[index]
                break
        if len(closed_boxes) == 0:
            return True
    return False
