#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} NODE;

void create_node(int value, NODE** head, NODE** tail);
void print_node (NODE *head);
void nth_node_from_end(NODE *head, int nth_node_value);
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

void nth_node_from_end(NODE *head, int nth_node_value)
{
    NODE *moved_node, *org_node;
    int move = nth_node_value+1;

    moved_node = org_node = head;

    while(moved_node && move)
    {
        moved_node = moved_node->next;
        --move;
    }

    if (move != 0)
    {
        printf("\n short linked list nodes \n"); 
        return;
    }

    while(moved_node)
    {
        moved_node = moved_node ->next;
        org_node = org_node ->next;
    }

    printf("\n value of nth node from the end is: %d", org_node->value);
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

    nth_node_from_end(head, 3);

    delete_node(&head, &tail);
}

