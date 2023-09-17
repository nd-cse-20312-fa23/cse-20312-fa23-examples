#!/usr/bin/env python3

import sys

previous = 0
for current in map(int, sys.stdin):
    if previous > current:
        print('RIP')
