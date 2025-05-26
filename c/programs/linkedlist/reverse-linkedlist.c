#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} NODE;

void create_node(int value, NODE** head, NODE** tail);
void print_node (NODE *head);
void reverse_node(NODE **head, NODE **tail);
void delete_node(NODE **head, NODE** tail);

void create_node(int value, NODE** head, NODE** tail)
{
    NODE *new_node = (NODE*) malloc(sizeof(NODE));
    if(new_node == NULL)
    {
        printf("\n malloc failed \n");
        return;
    }

    new_node ->value = value;
    new_node ->next  = NULL;

    if (!*head)
    {
        *head = *tail = new_node;
    }
    else
    {
        new_node->next = *head;
        *head = new_node;
    }
}

void print_node (NODE *head)
{
    NODE *temp = head;

    printf("\n printing the linked list node\n");
    while(temp)
    {   
        printf("%d ", temp->value);
        temp = temp ->next;
    }
    printf("\n");
}

void reverse_node(NODE **head, NODE **tail)
{
    NODE *temp, *rev_node, *org_head;

    rev_node = temp = NULL;

    org_head = *head;

    while (org_head)
    {
        temp = org_head ->next;

        if (!rev_node)
        {
            rev_node = org_head;
            rev_node ->next = NULL;
        }
        else
        {
            org_head ->next = rev_node;
            rev_node = org_head;
        }

        org_head = temp;
    }

    *tail = *head;
    *head = rev_node;    
}

void delete_node(NODE **head, NODE** tail)
{
    NODE *next;
    
    while(*head)
    {
        next = (*head)->next;
        free(*head);
        *head = next;
    }

    *head = *tail = NULL;
}

int main()
{
    NODE *head, *tail;

    head = tail = NULL;

    create_node(8, &head, &tail);
    create_node(3, &head, &tail);
    create_node(4, &head, &tail);
    create_node(5, &head, &tail);
    create_node(7, &head, &tail);
    create_node(99, &head, &tail);
    create_node(22, &head, &tail);

    print_node(head);

    reverse_node(&head, &tail);

    print_node(head);

    delete_node(&head, &tail);
}

