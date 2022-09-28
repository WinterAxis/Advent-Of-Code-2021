#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buf[25];
  char *instruction = calloc(25, 1);
  char *end;
  unsigned long depth = 0, pos = 0, index, n;
  FILE* fp = fopen("Day2_input1", "r");
  while (fgets(buf, sizeof buf, fp) != NULL) {
    end = strchr(buf, ' ');
    index = (end-buf);
    strncpy(instruction, buf, index);
    instruction[index] = '\0';
    n = strtoul(end, &end, 10);
    if (strcmp(instruction, "forward") == 0)  {
      pos += n;
    } else if (strcmp(instruction, "up") == 0) {
      depth -= n;
    } else if (strcmp(instruction, "down") == 0) {
      depth += n;
    }
  }
  printf("Depth: %d\t Pos: %d\t Answer: %d\n", depth, pos, depth*pos);
  fclose(fp);
  free(instruction);
  return 0;
}
