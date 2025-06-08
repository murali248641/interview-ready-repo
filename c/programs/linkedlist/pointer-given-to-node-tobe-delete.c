#include <stdio.h>

void delete_node_singly(NODE *cur)
{
    NODE *temp;

    if(cur==NULL)
    {
        printf("\n invaild input parameter \n");
        return;
    }

    temp = cur->next;

    if (temp)
    {
        cur->value = temp->value;
        cur->next = temp->next;
        free(temp);
    }
    else
    {
        printf("\n given node is last node\n");
    }
}

/* doubly linked list */
void deletenode_doubly(NODE **head, NODE **tail , NODE *cur)
{
    if(cur==NULL)
    {
        printf("\n cur node is null\n");
        return;
    }

    if ((cur ==*head) && (cur == *tail))
    {
        *head = NULL;
        *tail = NULL;
    }
    else if (cur == *head)
    {
        *head = cur->next;
        if(cur->next)
        {
            cur->next->prev = NULL;
        }
    }
    else if (cur == *tail)
    {
        cur->prev->next = NULL;
        *tail = cur->prev;
    }
    else 
    {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }

    free(cur);
}

/* circular linked list */
void delete_node_circular(NODE *cur)
{
    NODE *temp;

    if(cur==NULL)
    {
        printf("\n invaild input parameter \n");
        return;
    }

    temp = cur->next;

    if (temp)
    {
        cur->value = temp->value;
        cur->next = temp->next;
        free(temp);
    }
}


int main()
{

}