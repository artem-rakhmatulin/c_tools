// word_length.c -- small tool for counting number of characters in word
// Artem Rakhmatulin, 29.01.2021

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  const char *word;
  unsigned short cnt;

  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s string\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  word = argv[1]; 

  while (*word++)
    cnt++;

  printf("Number of characters in string \"%s\": %hd\n", argv[1], cnt);

  return 0;
}
