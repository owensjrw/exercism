#include "linked_list.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>

struct list_node {
  struct list_node *prev, *next;
  ll_data_t data;
};

struct list {
  struct list_node *first, *last;
  size_t count;
};

// constructs a new (empty) list
struct list *list_create(void) {
  return calloc(1, sizeof(struct list));
}

// counts the items on a list
size_t list_count(const struct list *list){
  return list->count;
}

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data) {
  struct list_node *node = calloc(1, sizeof(struct list_node));
  //check_mem(node);
  assert(node);
  node->data = item_data;

  if (list->count == 0) {
      node->next = NULL;    node->prev = NULL;
      list->first = node;   list->last = node;
    } else {
      node->prev = list->last;  node->next = NULL;
      list->last->next = node; list->last = node;
    }

  list->count += 1;
}

// removes item from back of a list
ll_data_t list_pop(struct list *list) {
  if (list->count == 0) {
      fprintf(stderr, "List is empty.");
      return 0;
    }
  struct list_node *node = list->last;
  ll_data_t popped = node->data;
  if (list->count == 1) {
      list->first = NULL;   list->last = NULL;
    } else {
      list->last = node->prev;
      list->last->next = NULL;
    }
  list->count -= 1;
  free(node);
  return popped;
}

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data) {
  struct list_node *node = calloc(1, sizeof(struct list_node));
  //check_mem(node);
  assert(node);
  node->data = item_data;

  if (list->count == 0) {
      node->next = NULL;    node->prev = NULL;
      list->first = node;   list->last = node;
    } else {
      node->next = list->first;   node->prev = NULL;
      list->first->prev = node;   list->first = node;
    }

  list->count += 1;
}

// removes item from front of a list
ll_data_t list_shift(struct list *list) {
  if (list->count == 0) {
      fprintf(stderr, "List is empty.");
      return 0;
    }
  struct list_node *node = list->first;
  ll_data_t popped = node->data;
  if (list->count == 1) {
      list->first = NULL;   list->last = NULL;
    } else {
      list->first = node->next;
      list->first->prev = NULL;
    }
  list->count -= 1;
  free(node);
  return popped;
}

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data) {
  FOREACH(list, first, next, node) {
    if (node->data == data) {
      list->count--;
      break;
    }
  }
}

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list) {
  FOREACH(list, first, next, node) {
    if (node->prev) {
      free(node->prev);
    }
  }

  free(list->last);
  free(list);
}
