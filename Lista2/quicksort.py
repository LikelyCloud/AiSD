#!/usr/bin/python3
import json


def quick_sort(a):
    if len(a) == 0:
        return []
    elif len(a) == 1:
        return a
    else:
        return quick_sort([x for x in a[1:] if x <= a[0]]) + [a[0]] + quick_sort([x for x in a[1:] if x > a[0]])


if __name__ == '__main__':
    len_x = input()
    x = input()
    x = json.loads(x)
    print(x)
    print(quick_sort(x))
