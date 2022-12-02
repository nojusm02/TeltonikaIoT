#ifndef LLIST_HEADER
#define LLIST_HEADER

struct node
{
    int info;
    char firstname[20];
    char lastname[20];
    char number[20]; 
    char eMail[20];
    struct node *next;
};

void printNode(struct node *ptr);
void display(struct node *start);

#endif