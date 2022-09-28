#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buf[10];
  char *end;
  unsigned long count = 0, previous, current;
  FILE* fp = fopen("Day1_P1_input", "r");
  fgets(buf, sizeof buf, fp);
  previous = strtoul(buf, &end, 10);
  while (fgets(buf, sizeof buf, fp) != NULL) {
    current = strtoul(buf, &end, 10);
    if (current > previous) {
      count += 1;
    }
    previous = current;
  }
  printf("Total Count %d", count);
  fclose(fp);
  return 0;
}
