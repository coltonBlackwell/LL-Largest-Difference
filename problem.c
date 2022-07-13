#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node node_t;

typedef struct 
{
    node_t* head;
    node_t* tail;
    int size;
}LL_t;

LL_t* LLcreate() {
    LL_t* ret = malloc(sizeof(LL_t));
    if (ret == NULL)
        return NULL;
    
    ret->size = 0;
    ret->head = NULL;
    ret->tail = NULL;
    return ret;
}

int main(){
    return 0;
}