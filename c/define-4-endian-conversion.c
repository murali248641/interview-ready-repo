#include <stdio.h>

#define CONVERT_ENDIAN(num) ( ((num >>24) & (0x000000FF)) | \
                              ((num >> 8) & (0x0000FF00)) | \
                              ((num << 8) & (0x00FF0000)) | \
                              ((num <<24) & (0xFF000000)) )

int main()
{
  unsigned int  a = 0x11000022;

  printf("\n value is: 0x%x \n", a );

  printf("\n endian conversion value : 0x%x\n", CONVERT_ENDIAN(a));

}