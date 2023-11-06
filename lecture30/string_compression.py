#!/usr/bin/env python3

# Constants

CHARS = {
    'aabbccc': 'a2b2c3',
    'a': 'a',
    'abbbbbbbbbbbb': 'ab12',
}

# Class

class Solution:

    def compress(self, chars: list[str]) -> int:
        reader = 0
        writer = 0
        char   = None
        length = 0

        while reader < len(chars):
            char    = chars[reader]
            length  = 1
            reader += 1

            while reader < len(chars) and char == chars[reader]:
                length += 1
                reader += 1

            chars[writer] = char
            writer       += 1

            if length > 1:
                for digit in str(length):
                    chars[writer] = digit
                    writer       += 1

        return writer

# Main Execution

def main() -> None:
    solution = Solution()

    for char_string, output in CHARS.items():
        chars  = list(char_string)
        result = solution.compress(chars)
        print(f'{"".join(chars[:result])} -> {result} (expected: {output}, {len(output)})')

if __name__ == '__main__':
    main()
