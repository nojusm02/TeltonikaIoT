#include <stdio.h>
#include <stdlib.h>
#include "llist.h"


void display(struct node *start)
{
        struct node *ptr;
        if(start==NULL) 
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                printf("\nThe List elements are:\n");
                while(ptr!=NULL)
                {
                        printNode(ptr);
                        ptr=ptr->next;

                }
        }
}


void printNode(struct node *ptr)
{
    printf("%s ",ptr->firstname);
    printf("%s ",ptr->lastname);
    printf("%s ",ptr->number);
    printf("%s ",ptr->eMail);
    printf("\n");
}



