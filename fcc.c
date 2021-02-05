/*
 * fcc.c - count printable characters in file
 * Artem Rakhmatulin, 05.02.2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{
  FILE * fp;
  int cnt;
  char ch;

  if (argc != 2)
  {
    printf("Using: %s filename\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  fp = fopen(argv[1], "r");

  if (NULL == fp)
  {
    puts("File open error.\n");
    exit(EXIT_FAILURE);
  }

  while ((ch = getc(fp)) != EOF)
    if (isprint(ch))
      cnt++;

  printf("Number of printable characters: %d\n", cnt);

  return 0;
}
