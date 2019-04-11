typedef struct node {
    int type;
    char* name;
    struct node* next;
} NODE;

void init(NODE** head);
void print_list(NODE* head);
NODE* add(NODE* node, int type, char* name);
int haveElementsInCommon(NODE* fpars, NODE* bpars);