#!/usr/bin/python3

"""In a text file, there is a single character H.
only two operationspossible :Copy All and Paste.
method that calculates the fewest number of operations needed
to result in exactly n H characters in the file.
"""


def minOperations(n):
    """min operations copy / paste"""
    if n <= 1:
        return 0
    nb_ops = 0
    current = 1
    now_in_memory = 0

    while current < n:
        if (n % current == 0):
            nb_ops += 1
            now_in_memory = current
        current += now_in_memory
        nb_ops += 1

    return nb_ops
