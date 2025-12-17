/**************************************************************
 * Author        : Aravind Potluri <aravindswami135@gmail.com>
 * Description   : Clone of hexdump (Big Endian)
 ***************************************************************/

// Required headers
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define width 0x10

// Entry point for the program
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: hexview <file>\n\n");
    return 1;
  }

  FILE *fptr = fopen(argv[1], "rb");
  if (!fptr)
  {
    perror("Error reading file.\n");
    return 1;
  }
  int ch;
  int offset = 0;
  unsigned char buff[width + 1] = {0};

  while ((ch = fgetc(fptr)) != EOF)
  {
    if (offset % width == 0)
    {
      memset(buff, 0, sizeof(buff));
      printf("%08x: ", offset);
    }

    printf("%02x ", (unsigned char)ch);

    buff[offset % width] = isprint((unsigned char)ch) ? ch : '.';
    offset++;

    if (offset % width == 0)
      printf("|%s|\n", buff);
  }
  if (offset % width != 0)
  {
    offset = width - offset % width;
    printf("%*s", 3 * offset, " ");
    printf("|%s|\n", buff);
  }
  fclose(fptr);
}