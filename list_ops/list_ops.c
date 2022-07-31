#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[]){
  list_t *list = malloc(sizeof (list_t) + (sizeof (list_element_t) * length));
  list->length = length;
  for(size_t i = 0; i < length; i++) {
    list->elements[i] = elements[i];
  }
  return list;
}

void delete_list(list_t *list) {
  free(list);
}

list_t *append_list(list_t *list1, list_t *list2) {
  int total_length = list1->length + list2->length;
  list_t *list =
      malloc(sizeof(list_t) + (sizeof(list_element_t) * total_length));
  list->length = total_length;
  for(size_t i = 0; i < list1->length; i++){
    list->elements[i] = list1->elements[i];
  }
  for(int i = list1->length; i < total_length; i++){
    list->elements[i] = list2->elements[i - list1->length];
  }
  return list;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
  list_t *filteredList =
    malloc(sizeof (list_t) + (sizeof(list_element_t) * list->length));
  int count = 0;
  filteredList->length = 0;
  for(size_t i = 0; i < list->length; i++) {
    if((*filter)(list->elements[i])) {
      filteredList->length++;
      filteredList->elements[count] = list->elements[i];
      count++;
    }
  }
  filteredList =
    realloc(filteredList, (sizeof (list_t) +
    (sizeof(list_element_t) * filteredList->length)));
  return filteredList;
}

size_t length_list(list_t *list) {
  return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
  list_t *mapList =
    malloc(sizeof (list_t) + (sizeof (list_element_t) * list->length));
  mapList->length = list->length;
  for(size_t i = 0; i < list->length; i++) {
    mapList->elements[i] = (*map)(list->elements[i]);
  }
  return mapList;
}

list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
  for(size_t i = 0; i < list->length; i++){
    initial = (*foldl)(list->elements[i], initial);
  }
  return initial;
}

list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
  for(size_t i = list->length; i > 0; i--){
    initial = (*foldl)(list->elements[i - 1], initial);
  }
  return initial;
}

list_t *reverse_list(list_t *list) {
  list_t *revList =
    malloc(sizeof (list_t) + (sizeof (list_element_t) * list->length));
  revList->length = 0;
  for(size_t i = list->length; i > 0; i--){
    revList->elements[revList->length] = list->elements[i - 1];
    revList->length++;
  }
  return revList;
}
