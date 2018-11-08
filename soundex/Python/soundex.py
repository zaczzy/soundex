import sys

parse_mode = sys.argv[len(sys.argv) - 1]
if parse_mode == '0':
    parse_mode = 0
elif parse_mode == '1':
    parse_mode = 1
else:
    sys.exit('Mode invalid: not 0 nor 1.')


def parse(word, mode):
    parsed_count = 0
    soundex = ""
    char2type = {'a': 0, 'e': 0, 'i': 0, 'o': 0, 'u': 0, 'y': 0,
                 'h': -1, 'w': -1,
                 'b': 1, 'f': 1, 'p': 1, 'v': 1,
                 'c': 2, 'g': 2, 'j': 2, 'k': 2, 'q': 2, 's': 2, 'x': 2, 'z': 2,
                 'd': 3, 't': 3,
                 'l': 4,
                 'm': 5, 'n': 5,
                 'r': 6
                 }
    if mode == 0:
        type_second_last = None
        type_last = None
        for char_i in word:
            char_lower = char_i.lower()
            if char_lower in char2type:
                type_i = char2type[char_lower]
                if parsed_count == 0:
                    soundex += char_i
                    parsed_count += 1
                    type_last = type_i
                elif parsed_count < 4:
                    if type_i > 0:
                        if not (type_last == type_i or type_second_last and type_last == -1 and type_second_last == type_i):
                            soundex += str(type_i)
                            parsed_count += 1
                    type_second_last = type_last
                    type_last = type_i
                else:
                    return soundex
            else:
                sys.exit('Invalid word: contains not-alphabetical character.')
        if parsed_count < 4:
            while parsed_count < 4:
                soundex += '0'
                parsed_count += 1
        return soundex
    else:
        # step 1
        letter0 = word[0]
        type0 = char2type[letter0.lower()]

        word = word.lower()
        ignore = {'a', 'e', 'i', 'o', 'u', 'y', 'h', 'w'}
        word = ''.join([c for c in word if c not in ignore])

        # step 2
        types = [char2type[c] for c in word]

        # step 3
        for i in range(len(types) - 1, 0, -1):
            if types[i] == types[i - 1]:
                types[i] = 0
        types = [type for type in types if type != 0]
        # step 4
        if type0 == types[0]:
            types = types[1:]
        # step 5
        for i in range(len(types), 3, 1):
            types.append(0)
        result = letter0
        for type in types:
            result += str(type)
        return result


if __name__ == "__main__":
    result = ""
    for i, arg in enumerate(sys.argv):
        if 0 < i < len(sys.argv) - 1:
            result = result + parse(arg, parse_mode) + " "
    print(result[:-1])
