#!/usr/bin/python3

"""Recursively count word_list occurrences in hot post titles."""


import requests


def count_words(subreddit, word_list, after=None, counts=None):
    dict_to_lower = {}
    if counts is None:
        counts = {}
    for word in word_list:
        word_to_lower = word.lower()
        if not (dict_to_lower.get(word_to_lower)):
            dict_to_lower[word_to_lower] = 1
        else:
            dict_to_lower[word_to_lower] = dict_to_lower[word_to_lower] + 1

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    response = requests.get(
        url,
        headers={"User-Agent": "korneelloy"},
        allow_redirects=False,
        params={"after": after})
    if response.status_code != 200:
        return

    data = response.json().get('data')

    after = data.get('after')

    posts = data.get('children')

    for post in posts:
        data = post.get('data')
        title = data.get('title')
        title_to_lower = title.lower()
        title_as_list = title_to_lower.split()
        for word in dict_to_lower.keys():
            nb = title_as_list.count(word)
            if not (nb == 0):
                if not (counts.get(word)):
                    counts[word] = nb
                else:
                    counts[word] = counts[word] + nb

    if not (after is None):
        count_words(subreddit, word_list, after=after, counts=counts)
    else:
        final = {}
        for word in counts:
            final[word] = counts[word] * dict_to_lower[word]

        sorted_final = sorted(final.items(), key=lambda x: (-x[1], x[0]))
        for el in sorted_final:
            print("{}: {}".format(el[0], el[1]))
