#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;    
}NODE;

void create_node(int value, NODE **head, NODE **tail);
void print_list(NODE *head);
void delete_node(int value, NODE **head, NODE **tail);
void free_list(NODE **head, NODE **tail);

void free_list(NODE **head, NODE **tail)
{
    NODE *cur = *head;
    NODE *next = NULL;

    while (cur)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }

    *head = *tail = NULL;
}

void create_node(int value, NODE **head, NODE **tail)
{
    NODE *new_node;
    
    if(!head || !tail )
    {
        printf("\n invalid head and tail \n");
        return;
    }

    new_node = (NODE *) malloc (sizeof(NODE));
    if(new_node == NULL)
    {
        printf("\n malloc is failed while creating the node\n");
        return;
    }

    new_node->value = value;
    new_node->next  = NULL;

    if (*head == NULL)
    {
        *head = *tail = new_node;
    }
    else
    {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

void print_list(NODE *head)
{
    printf("\n");
    while (head)
    {
        printf("%d -> ", head->value);
        head = head ->next;
    }
    printf("\n");
}

void delete_node(int value, NODE **head, NODE **tail)
{
    NODE *cur = *head;
    NODE *next, *prev;

    next = prev = NULL;

    while(cur)
    {
        next = cur->next;

        if(cur->value == value)
        {
            if((cur == *head)&&(cur==*tail))
            {
                *head = cur->next;
                *tail = cur->next;
            }
            else if(cur == *head)
            {
                *head = cur->next;
            }
            else if(cur == *tail)
            {
                *tail = prev;
                prev->next = NULL;
            }
            else
            {
                prev->next = cur->next;
            }
            
            free(cur);
            cur = NULL;            
        }
        else
        {
            prev = cur;
        }

        cur = next;
    }
}

int main()
{
    NODE *head, *tail;

    head = tail = NULL;

    create_node(6, &head, &tail);
    create_node(6, &head, &tail);
    create_node(8, &head, &tail);
    create_node(6, &head, &tail);
    create_node(9, &head, &tail);
    create_node(24, &head, &tail);
    create_node(6, &head, &tail);

    print_list(head);

    delete_node(6, &head, &tail);

    print_list(head);

    free_list(&head, &tail);
}