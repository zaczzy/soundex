PROBLEM SPECIFICATION:
Using the definition on Wikipedia, there exists two versions of American Soundex with differences:
ALGORITHM 0:
1. Retain the first letter of the name and drop all other occurrences of a, e, i, o, u, y, h, w.

2. Replace consonants with digits as follows (after the first letter):
      b, f, p, v → 1
      c, g, j, k, q, s, x, z → 2
      d, t → 3
      l → 4
      m, n → 5
      r → 6
3. If two or more letters with the same number are adjacent in the original name (before step 1), only retain the first letter; 
also two letters with the same number separated by 'h' or 'w' are coded as a single number, whereas such letters separated by a vowel are coded twice. 
This rule also applies to the first letter.

4. If you have too few letters in your word that you can't assign three numbers, append with zeros until there are three numbers. 
If you have more than 3 letters, just retain the first 3 numbers.


Using this algorithm, both "Robert" and "Rupert" return the same string "R163" while "Rubin" yields "R150". 
"Ashcraft" and "Ashcroft" both yield "A261" and not "A226" 
(the chars 's' and 'c' in the name would receive a single number of 2 and not 22 since an 'h' lies in between them). 
"Tymczak" yields "T522" not "T520" (the chars 'z' and 'k' in the name are coded as 2 twice since a vowel lies in between them). 
"Pfister" yields "P236" not "P123" (the first two letters have the same number and are coded once as 'P'), and "Honeyman" yields "H555".


ALGORITHM 1:
The following algorithm is followed by most SQL languages (excluding PostgreSQL[example needed]):

1. Save the first letter. Remove all occurrences of a, e, i, o, u, y, h, w.
2. Replace all consonants (include the first letter) with digits as in [2.] above.
3. Replace all adjacent same digits with one digit.
4. If the saved letter's digit is the same as the resulting first digit, remove the digit (keep the letter).
5. Append 3 zeros if result contains less than 3 digits. Remove all except first letter and 3 digits after it (This step same as [4.] in explanation above).

The two algorithms above do not return the same results in all cases primarily because of the difference between when the vowels are removed. 
The first algorithm is used by most programming languages and the second is used by SQL. 
As examples, both "Robert" and "Rupert" yield "R163", while "Tymczak" yields "T520" and "Honeyman" yields "H500". 


TO RUN THE PROGRAM:
  $ ./soundex input1 input2 ... inputn mode
  mode is a mandatory input that can either be 0 or 1, indicating which algorithm to run.

DEPENDENCIES:
<unistd.h> <string.h> <stdlib.h>

The program is compiled with clang by running `make` in the directory of Makefile.