#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} NODE;

void create_node(int value, NODE** head, NODE** tail);
void print_node (NODE *head);
void detect_loop_in_linkedlist(NODE *head);
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

void detect_loop_in_linkedlist(NODE *head)
{
    NODE *fast_ptr, *slow_ptr;

    fast_ptr = slow_ptr = head;

    while(fast_ptr && fast_ptr->next)
    {
       fast_ptr = fast_ptr->next->next;
       slow_ptr = slow_ptr->next;

       if (slow_ptr == fast_ptr)
       {
            printf("\n loop detected in linked list\n");
            return;
       }
    }
    
    printf("\n Loop not deteced in linked list");    
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

    tail->next = head;

    detect_loop_in_linkedlist(head);

    //delete_node(&head, &tail);
}

