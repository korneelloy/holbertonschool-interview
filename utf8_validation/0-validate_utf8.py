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
    octet_suivants = 0

    for number in data:
        byte = number % 256

        if octet_suivants == 0:
            # 0XXXXXXX ASCII
            if (byte >> 7) == 0:
                continue

            # 110XXXXX
            elif (byte >> 5) == 6:
                octet_suivants = 1

            # 1110xxxx
            elif (byte >> 4) == 14:
                octet_suivants = 2

            # 11110xxx
            elif (byte >> 3) == 30:
                octet_suivants = 3

            else:
                return False

        else:
            # 10xxxxxx
            if (byte >> 6) != 2:
                return False

            octet_suivants -= 1

    return octet_suivants == 0
