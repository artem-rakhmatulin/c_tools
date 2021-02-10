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
  int cnt = 0;

  if (argc != 3)
  {
    fprintf(stderr, "USAGE: %s filename string\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  fp = fopen(argv[1], "r");

  if (NULL == fp)
  {
    fprintf(stderr, "FILE OPEN ERROR: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while (fgets(str, MAX_STR_LENGTH, fp))
    if (strstr(str, argv[2]))
    {
      fputs(str, stdout);
      cnt++;
    }

  if (!cnt)
    printf("String \"%s\" not found.\n", argv[2]);

  fclose(fp);

  return 0;
}
