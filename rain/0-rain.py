#!/usr/bin/python3

"""rain calculation"""


def rain(walls):
    """
    Given a list of non-negative integers representing the heights of walls
    with unit width 1,
    as if viewing the cross-section of a relief map,
    calculate how many square units of water will be retained after it rains.

    walls is a list of non-negative integers.
    Return: Integer indicating total amount of rainwater retained.
    Assume that the ends of the list (before index 0 and after index walls[-1])
    are not walls, meaning they will not retain water.
    If the list is empty return 0.

    """

    length = len(walls)
    if length == 0:
        return 0

    water = 0

    for i in range(len(walls)-1):
        if walls[i] < walls[i+1]:
            continue
        else:
            max_to_left = max(walls[:i+2])
            max_to_right = max(walls[i+1:])
            bricks_in_this_wall = walls[i+1]
            water += min(max_to_left, max_to_right) - bricks_in_this_wall

    return water
