#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct item {
  char line[15];
  bool used; 
} item;

// bad but works
int main() {
  int o, c;
  int index_c = 0;
  int index_o = 0;
  int c02_count = 0;
  int oxygen_count = 0;
  item c02[1000];
  item oxygen[1000];
  for (int j = 0; j < 1000; j++) { 
    c02[j].used = false;
    oxygen[j].used = false;
  }
  char buf[15];
  char *end;
  char bit_criteria = ' ';
  FILE* fp = fopen("Day3_input1", "r");
  while (fgets(buf, sizeof buf, fp) != NULL) {
    strcpy(c02[index_c].line,buf);
    strcpy(oxygen[index_o].line,buf);
    c02[index_c].used = true;
    oxygen[index_o].used = true;
    index_c++;
    index_o++;
  }
  for (int i = 0; i < 12; i++) {
    oxygen_count = 0;
    for (int j = 0; j < 1000; j++) {
      if (oxygen[j].used) {
        if (oxygen[j].line[i] == '1') {
          oxygen_count ++;
        }
        else {
          oxygen_count--;
        }
      }
    }
    if (oxygen_count >= 0) {
      bit_criteria = '1';
    }
    else {
      bit_criteria = '0';
    }
    for (int j = 0; j < 1000; j++) {
      if (oxygen[j].used) {
        if (oxygen[j].line[i] != bit_criteria) {
          oxygen[j].used = false;
          index_o--;
        }
      }
    }
    if (index_o == 1) {
      for (int j = 0; j < 1000; j++) {
        if (oxygen[j].used) {
          printf("%s\n", oxygen[j].line);
          o = strtoul(oxygen[j].line, &end, 2);
          break;
        }
      }
      break;
    }
    printf("Ox: %d %d %d %c\n", i, index_o, oxygen_count, bit_criteria);
  }
  for (int i = 0; i < 12; i++) {
    c02_count = 0;
    for (int j = 0; j < 1000; j++) {
      if (c02[j].used) {
        if (c02[j].line[i] == '1') {
          c02_count++;
        }
        else {
          c02_count--;
        }
      }
    }
    if (c02_count < 0) {
      bit_criteria = '1';
    }
    else {
      bit_criteria = '0';
    }
    for (int j = 0; j < 1000; j++) {
      if (c02[j].used) {
        if (c02[j].line[i] != bit_criteria) {
          c02[j].used = false;
          index_c--;
        }
      }
    }
    printf("c02: i=%d index_c=%d count=%d bit=%c\n", i, index_c, c02_count, bit_criteria);
    if (index_c == 1) {
      for (int j = 0; j < 1000; j++) {
        if (c02[j].used) {
          printf("%s\n", c02[j].line);
          c = strtoul(c02[j].line, &end, 2);
          break;
        }
      }
      break;
    }
  }
  printf("Oxygen: %d\tCO2: %d\tAnswer: %d\n", o, c, o*c);
  fclose(fp);
  return 0;
}
