#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[]) {
  list_t *returnList = malloc(sizeof *returnList + (sizeof *elements * length));
  if (!returnList) {
    perror("Error: Failed to allocate memory");
    exit(EXIT_FAILURE);
  }
  returnList->length = length;
  if (elements != NULL) {
    memcpy(returnList->elements, elements, sizeof *elements * length);
  }
  return returnList;
}

void delete_list(list_t *list) {
  free(list);
}

list_t *append_list(list_t *list1, list_t *list2) {
  int total_length = list1->length + list2->length;
  list_t *returnList = new_list(total_length, NULL);
  memcpy(returnList->elements, list1->elements,
         sizeof *returnList->elements * list1->length);
  memcpy(returnList->elements + list1->length, list2->elements,
         sizeof *returnList->elements * list2->length);
  return returnList;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
  list_t *returnList = new_list(list->length, NULL);
  returnList->length = 0;
  for (size_t i = 0; i < list->length; i++) {
    if (filter(list->elements[i])) {
      returnList->elements[returnList->length++] = list->elements[i];
    }
  }
  list_t *returnListReduced =
    realloc(returnList, (sizeof *returnList +
           (sizeof *returnList->elements * returnList->length)));
  return (!returnListReduced) ? returnList : returnListReduced;
}

size_t length_list(list_t *list) {
  return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
  list_t *returnList = new_list(list->length, list->elements);
  for (size_t i = 0; i < list->length; i++) {
    returnList->elements[i] = map(list->elements[i]);
  }
  return returnList;
}

list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
  for (size_t i = 0; i < list->length; i++) {
    initial = foldl(list->elements[i], initial);
  }
  return initial;
}

list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
  for (size_t i = list->length; i > 0; i--) {
    initial = foldr(list->elements[i - 1], initial);
  }
  return initial;
}

list_t *reverse_list(list_t *list) {
  list_t *returnList = new_list(list->length, NULL);
  returnList->length = 0;
  for (size_t i = list->length; i > 0; i--) {
    returnList->elements[returnList->length++] = list->elements[i - 1];
  }
  return returnList;
}
