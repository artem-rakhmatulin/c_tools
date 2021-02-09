/* favg.c - avarage value of double numbers
 * Artem Rakhmatulin, 09.02.21
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{
  FILE *fp;
  double avg = 0.0, sum = 0.0;
  int cnt = 0;

  switch (argc)
  {
    case 1:
      fp = stdin;
      break;
    case 2:
      fp = fopen(argv[1], "r");
      if (!fp)
        exit(EXIT_FAILURE);
      break;
    default:
      exit(EXIT_FAILURE);
      break;
  }

  while(!feof(fp))
  {
    double num;
    if (fscanf(fp, "%lf", &num) == 1)
    {
      sum += num;
      cnt++;
    } else {
      char ch;
      while((ch = getc(fp)) && !(isspace(ch)) && !(feof(fp)))
        continue;
    }
  }

  avg = sum / cnt;

  printf("Avarage value: %.3f\n", avg);

  return 0;
}
