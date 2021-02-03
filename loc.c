#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_MAX 4096

int main(int argc, char **argv) {
  char c;
  char file[FILENAME_MAX];
  int escape_sequence = '\n';
  if (argc == 2) {
    strcpy(file, argv[1]);
  } else {
    printf("loc: Please specify file\n");
  }

  FILE *fp = fopen(file, "r");
  unsigned int numOfLines = 0;
  if (fp == NULL) {  // error reading file
    printf("loc: %s: No such file\n", file);
    return 0;
  }

  for (c = getc(fp); c != EOF; c = getc(fp)) {
    if (c == escape_sequence)
      numOfLines++;
  }

  fclose(fp);
  printf("Found: %u lines in %s\n", numOfLines, file);
  return 0;
}
