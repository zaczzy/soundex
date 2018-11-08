#include <unistd.h>
#include <string.h>
#include <stdlib.h>
// #include <stdio.h>
int char2type(char input)
{
  if (input == '*')
    return -2;
  char type_chars[] = "hwHW*aeiouyAEIOUY*bfpvBFPV*cgjkqsxzCGJKQSXZ*dtDT*lL*mnMN*rR";
  int length = 59;
  int i = 0;
  int type = -1;
  while (i < length)
  {
    if (type_chars[i] != input || type_chars[i] == '*')
      i++;
    else
      break;
    if (type_chars[i] == '*')
      type++;
  }
  if (i == length)
    return -2;
  else
    return type;
}

void print_out(const char *msg)
{
  write(STDOUT_FILENO, msg, strlen(msg));
}

int size(char *str)
{
  int p = 0;
  while (str[p])
    p++;
  return p;
}

void parse(char *word, char *result, int start, char mode)
{
  int parsed_count;
  if (mode == '0')
  {
    int type_second_last = -2, type_last = -2;
    int i = 0;
    parsed_count = 0;
    while (word[i])
    {
      int type_i = char2type(word[i]);
      if (type_i == -2)
      {
        print_out("Invalid word: contains non-alphabetical character.\n");
        exit(-1);
      }
      else
      {
        if (!parsed_count)
        {
          // printf("type_i: %d, type_last: %d, type_second_last: %d\n", type_i, type_last, type_second_last);
          result[start] = word[i];
          parsed_count++;
          type_last = type_i;
        }
        else if (parsed_count < 4)
        {
          // printf("type_i: %d, type_last: %d, type_second_last: %d\n", type_i, type_last, type_second_last);
          if (type_i > 0)
          {
            if (!(type_last == type_i || (type_second_last != -2 && type_last == -1 && type_second_last == type_i)))
            {
              result[start + parsed_count++] = '0' + type_i;
            }
          }
          type_second_last = type_last;
          type_last = type_i;
        }
        else
        {
          return;
        }
      }
      i++;
    }

  }
  else
  {
    char letter0 = word[0];
    int type0 = char2type(letter0);
    int wordsize = size(word);
    int *types = malloc(sizeof(int) * wordsize);
    types[0] = type0;
    for (int i = 0; i < wordsize; i++)
    {
      types[i] = char2type(word[i]);
    }
    for (int i = wordsize - 1; i > 0; i--)
    {
      int j = i - 1;
      while (j >= 0 && types[j] <= 0)
        j--;
      if (j >= 0 && types[j] == types[i])
        types[i] = -2;
    }
    for (int i = 0; i < wordsize; i++)
    {
      if (types[i] > 0 && types[i] == type0)
      {
        types[i] = -2;
        break;
      }
    }
    result[start] = letter0;
    parsed_count = 1;
    for (int i = 1; i < wordsize; i++)
    {
      if (types[i] > 0)
      {
        result[start + parsed_count++] = '0' + types[i];
        if (parsed_count == 4)
          break;
      }
    }
    free(types);
  }
  if (parsed_count < 4)
  {
    while (parsed_count < 4)
    {
      result[start + parsed_count++] = '0';
    }
  }
}

int main(int argc, char *argv[])
{
  char mode = argv[argc - 1][0];
  if (mode != '0' && mode != '1')
  {
    print_out("Mode invalid: not 0 or 1.\n");
    exit(-1);
  }
  char *result = malloc(((argc - 2) * 5 + 1) * sizeof(char));
  int start, end;
  for (int i = 0; i < argc - 2; i++)
  {
    start = 5 * i;
    end = start + 4;
    parse(argv[i + 1], result, start, mode);
    result[end] = ' ';
  }
  result[(argc - 2) * 5 - 1] = '\n';
  result[(argc - 2) * 5] = 0;
  print_out(result);
  free(result);
}