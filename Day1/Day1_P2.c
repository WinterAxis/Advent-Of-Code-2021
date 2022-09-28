#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buf[10];
  char *end;
  unsigned long count = 0, previous, m1, m2, m3;
  FILE* fp = fopen("Day1_input", "r");
  fgets(buf, sizeof buf, fp);
  m1 = strtoul(buf, &end, 10);
  fgets(buf, sizeof buf, fp);
  m2 = strtoul(buf, &end, 10);
  fgets(buf, sizeof buf, fp);
  m3 = strtoul(buf, &end, 10);
  fgets(buf, sizeof buf, fp);
  do {
    previous = m1+m2+m3;
    m1 = m2;
    m2 = m3;
    m3 = strtoul(buf, &end, 10);
    if (m1+m2+m3 > previous) {
      count += 1;
    }
  } while (fgets(buf, sizeof buf, fp) != NULL);
  printf("Total Count %d", count);
  fclose(fp);
  return 0;
}
