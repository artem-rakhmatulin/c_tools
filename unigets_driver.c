/* unigets_driver.c - driver for unigets function
 * Artem Rakhmatulin, 14.02.21
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *unigets(void);

static bool debug;

int main(int argc, char **argv)
{
  if (argc == 2)
    if (strcmp(argv[1], "debug") == 0)
      debug = true;
  char *str = unigets();
  puts(str);

  return 0;
}

char *unigets(void)
{
  for (int i = 2; (i * 2) < INT_MAX; i *= 2)
  {
    if (debug)
    printf("i = %d\n", i);
      char *s1 = (char *) calloc(1, i);
    for (int j = 0; j < i; j++)
    {
      if (debug)
        printf("j = %d\n", j);
      char ch = getchar();
      if (debug)
        if (ch != '\n')
          printf("ch = \'%c\'\n", ch);
        else
          puts("ch = \'\\n\'");
      if (j == i - 1 && ch != '\n')
      {
        if (debug)
        {
          puts("s1 is too small");
          printf("Unget char: \'%c\' to stdin\n", ch);
        }
        ungetc(ch, stdin);
        for (int k = j - 1; k >= 0; k--)
        {
          if (debug)
            printf("Unget char: \'%c\' to stdin\n", s1[k]);
          ungetc(s1[k], stdin);
        }
        break;
      } else if (ch == '\n') {
        s1[j] = '\0';
        char *s2 = (char *) malloc(j + 1);
        strcpy(s2, s1);
        if (debug)
        {
          printf("Finally s1: \"%s\"\n", s1);
          printf("Finally s2: \"%s\"\n", s2);
        }
        return s2;
      } else {
        s1[j] = ch;
        if (debug)
          printf("Now s1: \"%s\"\n", s1);
      }
    }
  }
  return NULL;
}
