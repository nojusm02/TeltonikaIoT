#ifndef LLIST_HEADER
#define LLIST_HEADER

struct node
{
    char name[20];
    char surname[20];
    char number[20]; 
    char email[20];
    struct node *next;
};

void printNode(struct node *ptr);
void print_address_book(struct node *start);

struct node* create_node(char *name, char *surname, char *number, char *email);

void add_to_list(struct node **list, struct node *address);
void add_to_list_pos(struct node **list, struct node *address, int pos);

void delete_list(struct node **list);
void delete_list_pos(struct node **list, int pos);

void find_pos_list(struct node **list, int pos);
void find_pos_data(struct node **list, int choice, char* data);

#endif