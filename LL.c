#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "LL.h"


// Creates and returns a new, empty list
LL_t* LLcreate() {
    LL_t* ret = malloc(sizeof(LL_t));
    if (ret == NULL)
        return NULL;
    
    ret->size = 0;
    ret->head = NULL;
    ret->tail = NULL;
    return ret;
}


// Adds the element to the head of the list
void LL_add_to_head(LL_t* list, int value) {

  // create a new node
  node_t* newNode = (node_t*) malloc(sizeof(node_t));
  if (newNode == NULL)
    return;

  // set the data in the new node
  newNode->data = value;
  newNode->next = list->head;

  if (list->size == 0) { // empty list
    list->head = newNode;
    list->tail = newNode;
  }
  else {
    list->head = newNode;
  }

  list->size++; // update size
}

// Adds a new element to the tail of a list
void LL_add_to_tail(LL_t* list, int value) {
 
  // create a new node
  node_t* newNode = (node_t*) malloc(sizeof(node_t));
  if (newNode == NULL)
    return;

  // set the data in the new node
  newNode->data = value;
  newNode->next = NULL;

  if (list->size == 0) {
    list->head = newNode;
    list->tail = newNode;
  }
  else {
    list->tail->next = newNode;
    list->tail = newNode;
  }

  list->size++; // update size
}



// assumption: list is not empty
int LL_remove_from_head(LL_t* list) {
  node_t* prev_head = list->head;
  int ret = prev_head->data;

  list->head = list->head->next;
  (list->size)--;

  if ((list->size)==0)
    list->tail = NULL;

  free(prev_head);

  return ret;
}

// assumption: list is not empty
int LL_remove_from_tail(LL_t* list) {
  int ret = list->tail->data;

  // take care of the case when list size is 1
  if (list->head == list->tail) {
    free(list->tail);
    list->head = NULL;
    list->tail = NULL;
  }
  else {
    node_t* cur = list->head;
    while (cur->next != list->tail)
      cur = cur->next;
    // here cur->next = list->tail;
    // update cur->next to be null, and update the tail
    free(list->tail);
    cur->next = NULL; // this is the new last element
    list->tail = cur;
  }
  (list->size)--;
  return ret;
}


// Returns the size of the list
int LL_size(const LL_t* list) {
  return list->size;
}


// Prints the elements in the list from head to tail
void LL_print(const LL_t* list) {
  node_t* current = list->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}




// releases the memore used by list
void LL_free(LL_t* list) {
  node_t* cur;
  while (list->head != NULL) {
    cur = list->head;
    list->head = cur->next;
    free(cur); 
  }
  free(list);
}


