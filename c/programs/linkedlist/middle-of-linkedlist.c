#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} NODE;

void create_node(int value, NODE** head, NODE** tail);
void print_node (NODE *head);
void print_middle_node(NODE *head);
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

void print_middle_node(NODE *head)
{
    NODE *fast_ptr, *slow_ptr;

    fast_ptr = slow_ptr = head;

    if(!fast_ptr)
    {
        printf("\n head is NULL. seems to be nodes are not created \n");
        return;
    }
    
    /* second node printing case*/
    while(fast_ptr && fast_ptr->next)    
    /* first node printing case*/
    //while (fast_ptr->next && fast_ptr->next->next)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    printf("\n middle of node value is :%d", slow_ptr->value);    
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

    print_middle_node(head);

    delete_node(&head, &tail);
}

