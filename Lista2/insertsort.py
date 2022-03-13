#!/usr/bin/python3
import json


def insertion_sort(a):
    global number_of_switches
    global number_of_comparisons
    global show_steps
    for i in range(1, len(a)):
        key = a[i]
        j = i - 1
        while j >= 0 and a[j] > key:
            a[j + 1] = a[j]
            j -= 1
            number_of_comparisons += 1
        if j >= 0:
            number_of_comparisons += 1
        a[j + 1] = key
        if j != i - 1:
            number_of_switches += 1
            if show_steps:
                print(a)
    return a


if __name__ == '__main__':
    number_of_switches = 0
    number_of_comparisons = 0
    show_steps = False

    len_x = input()
    x = input()
    if int(len_x) < 50:
        show_steps = True
    x = json.loads(x)

    if show_steps:
        print("Tablica wejsciowa:", x)
        print("\nStany tablicy w istotnych momentach:")
    insertion_sort(x)
    if show_steps:
        print("\nPosortowana tablica:", x)

    print("Liczba porownan:", number_of_comparisons)
    print("Liczba przestawien:", number_of_switches)
