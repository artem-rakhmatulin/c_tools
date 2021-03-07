/* bitValue.c - return value of indicated bit in number
 * 07.03.21 Artem Rakhmatulin
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool bitValue(int, int);

int main(int argc, char **argv)
{
  int num, bitPos;
  bool bitIsOn;

  if (3 != argc)
    exit(EXIT_FAILURE);

  num = atoi(argv[1]);
  bitPos = atoi(argv[2]);

  bitIsOn = bitValue(num, bitPos);

  if (bitIsOn)
    printf("Бит номер %d в числе %d включен.\n", bitPos, num);
  else
    printf("Бит номер %d в числе %d выключен.\n", bitPos, num);
    
  return 0;
}

bool bitValue(int num, int bitPos)
{
  bool bitIsOn;
  const unsigned int MASK = 0x1 << bitPos;

  bitIsOn = (num & MASK) == MASK;

  return bitIsOn;
}
