#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "llist.h"     


// void delete();
// void create();
void insert_pos(struct node **list);
void delete_pos(struct node **list);
// void delete_pos();
// void find_pos();
// void find_pos_data(int choice);
// void find_data();
void find_pos(struct node **list);
void find_data(struct node **list);
struct node *userDataInput();
void createFromText(char *name, char *surname, char *phone, char *email);
struct node *userDataInputText(char fN[20], char lN[20],char pN[20],char eM[20]);
/*void userDataInput(struct node **temp);*/

int add_address_to_list(struct node **list);
int add_address_to_list_txt(struct node **list, char *name, char *surname, char* phone, char* email);
int parse_user_input(char *name, char *surname, char *phone, char *email);
 
int daemonize = 1;

void signal_handler()
{
        printf("\nType q to quit!\n");
        daemonize = 0;
}

void print_usage()
{
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
}

int main()      
{
        struct node *list = NULL;
        int choice;
        signal(SIGINT, signal_handler);
        
        for(int cnt = 0; cnt < 10; cnt++)
        {
                add_address_to_list_txt(&list, "vard", "pav", "123456", "gmail");
        }

        print_usage();
        while(daemonize){
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch(choice)
                {
                        case 1:
                                print_address_book(list);
                                break;
                        case 2:
                                add_address_to_list(&list);
                                break;
                        case 3: 
                                insert_pos(&list);
                                break;
                        case 4:
                                delete_pos(&list);
                                break;
                        case 5:
                                delete_list(&list);
                                break;
                        case 6:
                                find_pos(&list);
                                break;
                        case 7:
                                find_data(&list);
                                break;
                        case 8:
                                daemonize = 0;
                                break;
                             
                        default:
                                printf("\n Wrong Choice");
                                break;
                }
                choice = NULL;
        }
        delete_list(&list);
        return 0;
}

int add_address_to_list_txt(struct node **list, char *name, char *surname, char* phone, char* email)
{
        int rc = 0;
        struct node *address = NULL;

        address = create_node(name, surname, phone, email);
        if (address == NULL) {
                printf("Unable to create new address\n");
                return 1;
        }
        add_to_list(list, address);
        return rc;
}

int add_address_to_list(struct node **list)
{
        int rc = 0;
        struct node *address = NULL;
        char name[20], surname[20], phone[20], email[20];

        rc = parse_user_input(name, surname, phone, email);
        if(rc) {
                return rc;
        }
        address = create_node(name, surname, phone, email);
        if (address == NULL) {
                printf("Unable to create new address\n");
                return 1;
        }
        add_to_list(list, address);
        return rc;
}

int parse_user_input(char *name, char *surname, char *phone, char *email)
{
        printf("\nEnter First name: ");
        fscanf(stdin, "%s", name);

        printf("Enter Last name: ");
        fscanf(stdin, "%s", surname);

        printf("Enter number: ");
        fscanf(stdin, "%s", phone);

        printf("Enter eMail: ");
        fscanf(stdin, "%s", email);

        return 0;
}

void insert_pos(struct node **list)
{
        int pos;
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);

        int rc = 0;

        struct node *address = NULL;

        char name[20], surname[20], phone[20], email[20];

        rc = parse_user_input(name, surname, phone, email);
        if(rc) {
                return rc;
        }
        address = create_node(name, surname, phone, email);
        if (address == NULL) {
                printf("Unable to create new address\n");
                return 1;
        }

        add_to_list_pos(list, address,pos);
        return rc;
}

void delete_pos(struct node **list)
{
        int pos;
        printf("\nEnter the position of the node to be deleted:\t");
        scanf("%d",&pos);
        delete_list_pos(list, pos);
}

void find_data(struct node **list)
{
        int choice;
        char data[20];

        printf("\n           DATA MENU                             \n");
        printf("\n 1.First name     \n");
        printf("\n 2.Last name    \n");
        printf("\n 3.Phone Number      \n");
        printf("\n 4.eMail     \n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice:\t");
        scanf("%d",&choice);

        if(*list==NULL)
        {
                printf("\nThe List is Empty:\n");
                return;
        }

        switch(choice)  
        {
                case 1: /*Name*/
                        printf("\nEnter the first name of the node to be found:\t");
                        scanf("%s",data);
                        find_pos_data(list,choice, data);
                        break;
                case 2: /*Last name*/
                        printf("\nEnter the last name of the node to be found:\t");
                        scanf("%s",data);
                        find_pos_data(list,choice, data);
                        break;
                case 3: /*Phone number*/
                        printf("\nEnter the phone number of the node to be found:\t");
                        scanf("%s",data);
                        find_pos_data(list,choice, data);
                        break;
                case 4: /*eMail*/
                        printf("\nEnter the email of the node to be found:\t");
                        scanf("%s",data);
                        find_pos_data(list, choice, data);
                        break;
                default:
                        printf("\n Wrong Choice:\n");
                        break;
        }
}

void find_pos(struct node **list)
{
        int pos;
        printf("\nEnter the position of the node to be found:\t");
        scanf("%d",&pos);
        find_pos_list(list, pos);
}
