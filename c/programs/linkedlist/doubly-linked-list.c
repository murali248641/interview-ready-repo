#include <stdio.h>
#include <stdlib.h>

typedef struct  node
{
    int value;
    struct node *next;
    struct node *prev;
}NODE;

NODE *head = NULL;
NODE *tail = NULL;

void create_node(int value);
void print_list(void);
void print_list_using_tail(void);
void reverse_list(void);
void free_list(void);

void create_node(int value)
{
    NODE *new_node = (NODE *) malloc(sizeof(NODE));
    if(new_node==NULL)
    {
        printf("\n malloc is failed while creating the node \n");
        return;
    }
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(NULL == head)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

void print_list(void)
{
    NODE *cur = head;

    printf("\n");
    while(cur)
    {
        printf("%d ->", cur->value);
        cur = cur ->next;
    }
    printf("\n");
}

void print_list_using_tail(void)
{
    NODE *cur = tail;

    printf("\n");
    while(cur)
    {
        printf("%d<- ", cur->value);
        cur = cur ->prev;
    }
    printf("\n");    
}

void reverse_list(void)
{
    NODE *cur = head;
    NODE *temp = NULL;

    while(cur)
    {
        temp = cur->prev;

        cur->prev = cur->next;
        cur->next = temp;

        cur = cur->prev;
    }

    if (temp)
    {
        temp = head;
        head = tail;
        tail = temp;
    }
}

void free_list(void)
{
    NODE *cur = head;
    NODE *temp = NULL;

    while(cur)
    {
        temp = cur->next;
        free(cur);
        cur=temp;
    }    

    head = tail = NULL;    
}

int main()
{
    create_node(8);
    create_node(6);
    create_node(8);
    create_node(22);
    create_node(833);

    print_list();
    print_list_using_tail();

    reverse_list();

    print_list();
    print_list_using_tail();

    free_list();

    print_list();
    print_list_using_tail();
}