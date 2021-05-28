#!/usr/bin/env python3

import sys

jems = set(sys.stdin.readline().strip())
stones = sys.stdin.readline().strip()

result = 0

for stone in stones:
    if stone in jems:
        result += 1

print(result)
