#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

void print_address_book(struct node *list)
{
    struct node *temp = list;
    if (temp == NULL) {
        printf("\nList is empty:\n");
        return;
    }
    while (temp != NULL) {
        printNode(temp);
        temp = temp->next;
    }
}

void find_pos_list(struct node **list, int pos)
{
    struct node *temp = *list;
    if(temp==NULL)
    {
        printf("\nThe List is Empty!\n");
        return;
    }
    else
    {
        if(pos == 0)
        {
            printNode(temp);
        }
        else
        {
            int i = 0; 
            for(i=0;i<pos;i++) 
            {
                temp = temp->next;
                if(temp==NULL)
                {
                    printf("\nPosition not found!\n");
                    return;
                }
            }
            printNode(temp);
        }
    }

}

void find_pos_data(struct node **list, int choice, char* data)
{
    //enum {firstname = 0, lastname = 1, number = 2, eMail = 3} entryType; // sita
    //enum entryType entry;

    struct node *temp = *list;
    struct node *ptr = temp;
    
    switch(choice)
    {
        case 1:
            while(temp != NULL)
            {
                if(strcmp(temp->name, data) == 0)
                {
                    printNode(ptr);
                    return;
                }
                if(temp == NULL)
                {
                    printf("\nNode not Found:\n");
                    return;
                }
                ptr = ptr->next;
                temp = ptr;
            }
            printf("\nNode not Found!\n");
            return;
        case 2:
            while(temp != NULL)
            {
                if(strcmp(temp->surname,data) == 0)
                {
                        printNode(temp);
                        return;
                }
                if(temp == NULL)
                {
                        printf("\nNode not Found:\n");
                        return;
                }
                temp = temp->next;
            }
            printf("\nNode not Found!\n");
            return;
        case 3:
            while(temp != NULL)
            {
                if(strcmp(temp->number,data) == 0)
                {
                        printNode(temp);
                        return;
                }
                if(temp == NULL)
                {
                        printf("\nNode not Found:\n");
                        return;
                }
                temp = temp->next;
            }
            printf("\nNode not Found!\n");
            return;
        case 4:
            while(temp != NULL)
            {
                if(strcmp(temp->email,data) == 0)
                {
                        printNode(temp);
                        return;
                }
                if(temp == NULL)
                {
                        printf("\nNode not Found:\n");
                        return;
                }
                temp = temp->next;
            }
            printf("\nNode not Found!\n");
            return;
    }

    // while(temp != NULL)
    // {
    //     if(strcmp(temp->entryType,data) == 0)
    //     {
    //             printNode(temp);
    //             return;
    //     }
    //     if(temp == NULL)
    //     {
    //             printf("\nNode not Found:\n");
    //             return;
    //     }
    //     temp = temp->next;
    // }
    // printf("\nNode not Found!\n");
    // return;
}

void printNode(struct node *address)
{
    printf("%s ",address->name);
    printf("%s ",address->surname);
    printf("%s ",address->number);
    printf("%s ",address->email);
    printf("\n");
}

struct node* create_node(char *name, char *surname, char *number, char *email)
{
    struct node *address = NULL;
    address = (struct node*) malloc(sizeof(struct node));
    if (address == NULL) {
        return NULL;
    }
    strcpy(address->name, name);
    strcpy(address->surname, surname);
    strcpy(address->number, number);
    strcpy(address->email, email);
    address->next = NULL;
    return address;
}

void add_to_list(struct node **list, struct node *address)
{
    struct node* temp = *list;
    if (temp == NULL) {
        *list = address;
        return; 
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = address;


}

void add_to_list_pos(struct node **list, struct node *address, int pos)
{
    struct node* temp = *list;
    if (temp == NULL && pos == 0) {
        *list = address;
        return; 
    }
    else if(temp != NULL && pos == 0)
    {
        address->next = *list;
        *list = address;
    }

    else if(temp != NULL)
    {
        int i = 0;
        for(i=0;i<pos-1;i++) 
        {
            temp=temp->next;
            if(temp==NULL)
            {
                printf("\nPosition not found:\n");
                return;
            }
        }
        address->next = temp->next;
        temp->next = address;
    }
}

void delete_list(struct node **list)
{
    struct node *current = *list;
    struct node *next;
    if(current == NULL)
    {
        printf("\nList is Empty:\n");
        return; 
    }
    while (current!=NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *list = NULL;
}

void delete_list_pos(struct node **list, int pos)
{
    struct node *current = *list;
    struct node *next;
    if(current == NULL)
    {
        printf("\nThe List is Empty:\n");
        return;
    }
    else if(pos == 0 && current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
        *list = current;
    }
    else
    {
        int i = 0;
        for(i=0;i<pos - 1;i++) 
        {
            current = current->next;
            if(current==NULL)
            {
                printf("\nPosition not found:\n");
                return;
            }
        }
        struct node *del = current->next;
        current->next = current->next->next;
        del->next = NULL;
        free(del);
    }
}