#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;    
} NODE;

NODE *head = NULL;

void print_list(void);
void create_node (int value);
void reverse_list (void);

void create_node (int value)
{
    NODE *new_node;

    new_node = (NODE *) malloc (sizeof(NODE));
    if(new_node == NULL)
    {
        printf("\n malloc failed while creating the node \n");
        return;
    }

    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        NODE *cur = head;
        NODE *prev = NULL;

        while (cur)
        {
            prev = cur;
            cur = cur ->next;
        }
        
        prev->next = new_node;

        /*
         inserting in last 
        new_node->next = head;
        head = new_node; */
    }    
}

void print_list(void)
{
    NODE *cur = head;

    printf("\n");
    while(cur)
    {
        printf("%d-> ", cur->value);
        cur = cur ->next;
    }
    printf("\n");
}

void sort_list (void)
{
    NODE *cur = head;

    while(cur)
    {
        cur->value 
    }
}

int main()
{
    create_node(8);
    create_node(18);
    create_node(28);
    create_node(38);
    create_node(84);
    create_node(58);

    print_list();
}