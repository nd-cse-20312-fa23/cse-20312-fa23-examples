#!/usr/bin/env python3

import sys

# Main Execution

def main():
    numbers = []
    for argument in sys.argv[1:]:
        numbers.append(int(argument))

    average = sum(numbers) / len(numbers)
    print(f'Average of {numbers} is {average}')

if __name__ == '__main__':
    main()
