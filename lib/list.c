#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init(NODE** head) {
    *head = NULL;
}

void print_list(NODE* head) {
    NODE * temp;
    for (temp = head; temp; temp = temp->next)
        printf("[%d:%s]->", temp->type,temp->name);
    printf("NULL\n");
}

NODE* add(NODE* node, int t, char* n) {
    NODE* temp = (NODE*) malloc(sizeof (NODE));
    if (temp == NULL) {
        exit(0); // no memory available
    }
    temp->type = t;
    temp->name= n;
    temp->next = node;
    node = temp;
    return node;
}