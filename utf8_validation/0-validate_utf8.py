#!/usr/bin/python3
"""
method that determines if a given data set represents a valid UTF-8 encoding.
Return: True if data is a valid UTF-8 encoding, else return False
A character in UTF-8 can be 1 to 4 bytes long
The data set can contain multiple characters
The data will be represented by a list of integers
Each integer represents 1 byte of data, therefore you only need to handle the
8 least significant bits of each integer
"""


def validUTF8(data):
    """
    valid UTF-8 encoding.
    """
    for number in data:
        if not isinstance(number, int) or number > 255 or number < 0:
            return False
    return True
