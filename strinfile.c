/* strinfile.c - find string in file
 * Artem Rakhmatulin, 10.02.2021
 */

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define MAX_STR_LENGTH 256

int main(int argc, char **argv)
{
  FILE *fp = NULL;
  char str[MAX_STR_LENGTH] = {'\0'};

  if (argc != 3)
    exit(EXIT_FAILURE);

  fp = fopen(argv[1], "r");

  if (NULL == fp)
    exit(EXIT_FAILURE);

  while (fgets(str, MAX_STR_LENGTH, fp))
    if (strstr(str, argv[2]))
      fputs(str, stdout);

  fclose(fp);

  return 0;
}
