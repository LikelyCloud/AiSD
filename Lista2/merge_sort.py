#!/usr/bin/python3
import json


def merging_sort(a):
    len_a = len(a)

    if len_a == 0:
        return []
    elif len_a == 1:
        return a
    else:
        return merge(merging_sort(a[:len_a // 2]), merging_sort(a[len_a // 2:]))


def merge(b, c):
    len_b = len(b)
    len_c = len(c)
    merged = [0 for _ in range(len_b + len_c)]

    i = 0
    j = 0
    while i < len_b and j < len_c:
        if b[i] <= c[j]:
            merged[i + j] = b[i]
            i += 1
        else:
            merged[i + j] = c[j]
            j += 1

    while i < len_b:
        merged[i + j] = b[i]
        i += 1
    while j < len_c:
        merged[i + j] = c[j]
        j += 1

    return merged


if __name__ == '__main__':
    len_x = input()
    x = input()
    x = json.loads(x)
    print(x)
    print(merging_sort(x))
