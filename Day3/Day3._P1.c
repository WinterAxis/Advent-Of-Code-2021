#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  char buf[15], gamma_s[15], epsilon_s[15];
  char *end;
  int counts[12] = {0}; 
  unsigned long gamma, epsilon;
  FILE* fp = fopen("Day3_input1", "r");
  while (fgets(buf, sizeof buf, fp) != NULL) {
    for (int i = 0; i < 12; i++) {
      if (buf[i] == '1') {
        counts[i]++;
      }
      else {
        counts[i]--;
      }
    }
  }
  printf("%d %d %d\n", counts[0], counts[1], counts[2]);
  for (int i = 0; i < 12; i++) {
    if (counts[i]> 0) {
      gamma_s[i] = '1';
      epsilon_s[i] = '0';
    }
    else {
      gamma_s[i] = '0';
      epsilon_s[i] = '1';
    }
  }
  buf[12] = '\0';
  gamma = strtoul(gamma_s, &end, 2);
  epsilon = strtoul(epsilon_s, &end, 2);
  printf("Gamma: %d\tEpsilon: %d\tAnswer: %d\n", gamma, epsilon, gamma*epsilon);
  fclose(fp);
  return 0;
}
