#!/usr/bin/python3

import sys
import random
if __name__ == '__main__':
    n = int(sys.argv[1])
    generated = [round(random.uniform(0, 1) * (2 * n - 1)) for _ in range(n)]
    print(n)
    print(generated)
