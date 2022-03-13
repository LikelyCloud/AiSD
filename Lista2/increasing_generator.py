#!/usr/bin/python3

import sys
import random
from quicksort import quick_sort

if __name__ == '__main__':
    n = int(sys.argv[1])
    generated = [round(random.uniform(0, 1) * (2 * n - 1)) for _ in range(n)]
    generated = quick_sort(generated)
    print(n)
    print(generated)
