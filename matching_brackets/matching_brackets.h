#ifndef MATCHING_BRACKETS_H
#define MATCHING_BRACKETS_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node {
  char c;
  struct node *next;
} node_t;

typedef struct linklist {
  uint16_t count;
  node_t *node;
} linklist_t;

bool is_paired(const char *input);

#endif
