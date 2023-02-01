#include "matching_brackets.h"

linklist_t *createLinkedList(void);
void pushchar(char c, linklist_t *list);
void popit(linklist_t *list);
bool popchar(char c, linklist_t *list);
void freelist(linklist_t *list);

linklist_t *createLinkedList(void) {
  linklist_t *list = malloc(sizeof(*list));
  list->count = 0;
  list->node = NULL;
  return list;
}

void pushchar(char c, linklist_t *list) {
  node_t *node = malloc(sizeof(*node));
  node->c = c;
  node->next = list->node;
  list->node = node;
  list->count += 1;
}

void popit(linklist_t *list) {
  node_t *popped = NULL;
  popped = list->node;
  list->node = popped->next;
  list->count -= 1;
  free(popped);
}

bool popchar(char c, linklist_t *list) {
  if(list->count == 0){
    return false;
  }
  switch(c) {
    case ')':
      if(list->node->c == '(') {
        popit(list);
        return true;
      }
      break;
    case ']':
      if(list->node->c == '[') {
        popit(list);
        return true;
      }
      break;
    case '}':
      if(list->node->c == '{') {
        popit(list);
        return true;
      }
      break;
  }
  return false;
}

void freelist(linklist_t *list) {
  while(list->count) {
    popit(list);
  }
  free(list);
}

bool is_paired(const char *input) {
  linklist_t *list = createLinkedList();
  for(int i = 0; i < (int)strlen(input); i++) {
    if(input[i] == '(' || input[i] == '[' || input[i] == '{') {
      pushchar(input[i], list);
    }
    if(input[i] == ')' || input[i] == ']' || input[i] == '}') {
      if(popchar(input[i], list) == false) {
        freelist(list);
        return false;
      }
    }
  }
  bool rtn = !(list->count);
  freelist(list);
  return rtn;
}
