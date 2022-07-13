#include <stdio.h>

#include "LL.h"

int largest_diff(const LL_t* lst){

  node_t* previous = lst->head;
  node_t* current = previous->next;

  int max = 0;

  int absValue;


  while(current != NULL){
    
    absValue = abs(current->data - previous->data);

    if(absValue > max){
      max = absValue;
    }
    previous = current;
    current = current->next;
  }

  return max;
}

int main(){

  LL_t* myList = LLcreate();

  LL_add_to_tail(myList, 1);
  LL_add_to_tail(myList, 3);
  LL_add_to_tail(myList, 8);
  LL_add_to_tail(myList, 4);
  LL_add_to_tail(myList, 3);

  // 1->3->8->4->3

  int maxVal = largest_diff(myList);

  printf("\nThis is the max value between two consecutive nodes: %d\n", maxVal);
}