#include <stdio.h>
#include <string.h>

void copybuffer(char* input)
{
  char buffer[15];
  strcpy (buffer,input);
}

int main (int argc, char *argv[])
{

  copybuffer(argv[1]);
  return 0;
}


