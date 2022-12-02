#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "llist.h"     




void delete();
void create();
void insert_pos();
void delete_pos();
void find_pos();
void find_pos_data(int choice);
void find_data();
struct node *userDataInput();
void createFromText(char fN[20], char lN[20],char pN[20],char eM[20]);
struct node *userDataInputText(char fN[20], char lN[20],char pN[20],char eM[20]);
/*void userDataInput(struct node **temp);*/
 
 


struct node *start=NULL;

int main()      
{
        int choice;
        int amnt = 10;
        for(int cnt = 0; cnt < amnt; cnt++)
        {
                createFromText("Vardas", "Pavard", "1","gmailas");
        }
        while(1){
               
                printf("\n                MENU                             \n");
                printf("\n 1.Display     \n");
                printf("\n 2.Create    \n");
                printf("\n 3.Insert at specified position       \n");
                printf("\n 4.Delete from specified position     \n");
                printf("\n 5.Delete list       \n");
                printf("\n 6.Find by number      \n");
                printf("\n 7.Find by data        \n");
                printf("\n 8.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        display(start);
                                        break;
                        case 2:
                                        create();
                                        break;
                        case 3: 
                                        insert_pos();
                                        break;
                        case 4:
                                        delete_pos();
                                        break;
                        case 5:
                                        delete();
                                        break;
                        case 6:
                                        find_pos();
                                        break;
                        case 7:
                                        find_data();
                                        break;
                        case 8:
                                        delete();
                                        exit(0);
                                        break;
                             
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}

/*
void userDataInput(struct node **temp)
{
    printf("Enter First name:\n");
    scanf("%s",&temp->firstname);
    printf("Enter Last name:\n");
    scanf("%s",&temp->lastname);
    printf("Enter number:\n");
    scanf("%d",&temp->number);
    printf("Enter eMail:\n");
    scanf("%s",&temp->eMail);
}
*/

struct node *userDataInput()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                exit(0);
        }
        printf("\nEnter the data value for the node:\n");
        //userDataInput(&temp);
        printf("\nEnter First name:\n");
        scanf("%s",temp->firstname);
        printf("Enter Last name:\n");
        scanf("%s",temp->lastname);
        printf("Enter number:\n");
        scanf("%s",temp->number);
        printf("Enter eMail:\n");
        scanf("%s",temp->eMail);

        temp->next=NULL;
        return temp;
}

struct node *userDataInputText(char fN[20], char lN[20],char pN[20],char eM[20])
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                exit(0);
        }
        //userDataInput(&temp);

        strcpy(temp->firstname, fN);
        strcpy(temp->lastname, lN);
        strcpy(temp->number, pN);
        strcpy(temp->eMail, eM);

        temp->next=NULL;
        return temp;
}




void create()
{
        struct node *temp,*ptr;
        temp = userDataInput();

        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}

void createFromText(char fN[20], char lN[20],char pN[20],char eM[20])
{
        struct node *temp,*ptr;
        temp = userDataInputText(fN, lN,pN, eM);

        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}



void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
        
        temp = userDataInput();

        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++) { ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found:\n");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}




void find_data()
{
        int choice;
        printf("\n           DATA MENU                             \n");
        printf("\n 1.First name     \n");
        printf("\n 2.Last name    \n");
        printf("\n 3.Phone Number      \n");
        printf("\n 4.eMail     \n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch(choice)  
        {
                case 1: /*Name*/
                                find_pos_data(choice);
                                break;
                case 2: /*Last name*/
                                find_pos_data(choice);
                                break;
                case 3: /*Phone number*/
                                find_pos_data(choice);
                                break;
                case 4: /*eMail*/
                                find_pos_data(choice);
                                break;
                        
                default:
                                printf("\n Wrong Choice:\n");
                                break;
        }
}

void find_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nThe List is Empty:\n");
                exit(0);
        }
        else
        {
                printf("\nEnter the position of the node to be found:\t");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=start;
                        printNode(ptr);
                        printf("\n");
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        printNode(ptr);
                        printf("\n");
                }
        }
}

void find_pos_data(int choice)
{
        char *data[20];
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nThe List is Empty:\n");
                exit(0);
        }
        else
        {       
                switch(choice)
                {
                        case 1: /*First name*/
                        {
                                printf("\nEnter the first name of the node to be found:\t");
                                scanf("%s",data);
                                ptr = start;
                                temp = ptr;
                                while(temp != NULL)
                                {
                                        
                                        if(strcmp(temp->firstname,data) == 0)
                                        {
                                                printNode(ptr);
                                                return;
                                        }
                                        if(ptr == NULL)
                                        {
                                                printf("\nNode not Found:\n");
                                                return;
                                        }
                                        ptr = ptr->next;
                                        temp = ptr;
                                }
                                printf("\nNode not Found!\n");
                                return;

                        }
                        case 2 : /*Last name*/
                        {
                                printf("\nEnter the last name of the node to be found:\t");
                                scanf("%s",data);
                                ptr = start;
                                temp = ptr;
                                while(temp != NULL)
                                {
                                        
                                        if(strcmp(temp->lastname,data) == 0)
                                        {
                                                printNode(ptr);
                                                return;
                                        }
                                        if(ptr == NULL)
                                        {
                                                printf("\nNode not Found:\n");
                                                return;
                                        }
                                        ptr = ptr->next;
                                        temp = ptr;
                                }
                                printf("\nNode not Found!\n");
                                return;

                        }
                        case 3: /*Phone number*/
                        {
                                printf("\nEnter the phone number of the node to be found:\t");
                                scanf("%s",data);
                                ptr = start;
                                temp = ptr;
                                while(temp != NULL)
                                {
                                        
                                        if(strcmp(temp->number,data) == 0)
                                        {
                                                printNode(ptr);
                                                return;
                                        }
                                        if(ptr == NULL)
                                        {
                                                printf("\nNode not Found:\n");
                                                return;
                                        }
                                        ptr = ptr->next;
                                        temp = ptr;
                                }
                                printf("\nNode not Found!\n");
                                return;

                        }
                        case 4: /*eMail*/
                        {
                                printf("\nEnter the email of the node to be found:\t");
                                scanf("%s",data);
                                ptr = start;
                                temp = ptr;
                                while(temp != NULL)
                                {
                                        
                                        if(strcmp(temp->eMail,data) == 0)
                                        {
                                                printNode(ptr);
                                                return;
                                        }
                                        if(ptr == NULL)
                                        {
                                                printf("\nNode not Found:\n");
                                                return;
                                        }
                                        ptr = ptr->next;
                                        temp = ptr;
                                        
                                }
                                printf("\nNode not Found!\n");
                                return;
                        }
                        default :
                                printf("\nChoice error!\n");
                                return;
                }
                
        }
}


void delete()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is Empty:\n");
                return;
        }
        while(start != NULL)
        {
                ptr=start;
                start=start->next ;
                free(ptr);
        }
}

void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nThe List is Empty:\n");
                return;
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:\t");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        free(ptr);
                }
        }
}