typedef struct node {
    int type;
    struct node* next;
} NODE;

void init(NODE** head);
void print_list(NODE* head);
NODE* add(NODE* node, int type);
int haveElementsInCommon(NODE* fpars, NODE* bpars);
int compareLists(NODE *l1, NODE *l2);