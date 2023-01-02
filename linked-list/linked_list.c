#include "linked_list.h"
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>

#define FOREACH(L, F, N, C) struct list_node *_node = NULL;\
                            struct list_node *C = NULL;\
  for(C = _node = L->F; _node != NULL; C = _node = _node->N)

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
  struct list *list = malloc(sizeof(struct list));
  assert(list);
  list->first = list->last = NULL;
  list->count = 0;
  return list;
}

// counts the items on a list
size_t list_count(const struct list *list){
  return list->count;
}

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data) {
  struct list_node *node = malloc(sizeof(struct list_node));
  assert(node);
  node->data = item_data;
  list->count++;

  if (list->first == NULL) {
      list->first = node;
      node->prev = node->next = NULL;
    } else if (list->last == NULL) {
      node->prev = list->first;
      list->last = node;
    } else {
      node->prev = list->last;
      list->last = node;
    }
}

// removes item from back of a list
ll_data_t list_pop(struct list *list) {
  struct list_node *node = list->last;
  ll_data_t popped = node->data;
  list->count--;

  if (list->last->prev == list->first) {
      list->last = NULL;
    } else {
      list->last = node->prev;
      list->last->next = NULL;
    }

  free(node->prev);
  free(node->next);
  free(node);
  return popped;
}

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data) {
  struct list_node *node = malloc(sizeof(struct list_node));
  assert(node);
  node->data = item_data;
  list->count++;

  if (list->first == NULL) {
      list->first = node;
      node->prev = node->next = NULL;
    } else {
      node->next = list->first;
      node->prev = NULL;
      list->first->prev = node;
      list->first = node;
    }
}

// removes item from front of a list
ll_data_t list_shift(struct list *list) {
  struct list_node *node = list->first;
  ll_data_t shift = node->data;
  list->count--;

  if (list->first->next == NULL) {
      list->first = NULL;
    } else {
      list->first = node->next;
      list->first->prev = NULL;
    }

  free(node->prev);
  free(node->next);
  free(node);
  return shift;
}

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data) {
  FOREACH(list, first, next, node) {
    if (node->data == data) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      if (list->first == node) {
          list->first = node->next;
        } else if (list->last == node) {
          list->last = node->prev;
        }
      if (list->first == list->last) {
          list->last = NULL;
        }
      list->count--;
      free(node->next);
      free(node->prev);
      free(node);
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
