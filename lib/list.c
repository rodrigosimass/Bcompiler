#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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

int haveElementsInCommon(NODE* fpars, NODE* bpars) {
    NODE * temp;
    NODE * temp2;
    for (temp = bpars; temp; temp = temp->next) {
         for (temp2 = fpars; temp2; temp2 = temp2->next)
            if(strcmp(temp->name,temp2->name)==0 && temp->type==temp2->type)
                return 1;
    }
    return 0;
}