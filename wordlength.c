// wordlength.c -- small tool for counting number of characters in word
// Artem Rakhmatulin, 29.01.2021

#include <stdio.h>

int main(int argc, char **argv)
{
  const char *word = NULL;
  unsigned short cnt = 0;

  if (argc != 2)
    return -1;

  word = argv[1]; 

  while (*word++)
    cnt++;

  printf("Number of characters in string \"%s\": %hd\n", argv[1], cnt);

  return 0;
}
