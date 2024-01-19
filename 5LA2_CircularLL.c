#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *start = NULL;

void create_node(int items)
{
    struct node *temp;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = items;

    if (start == NULL)
    {
        start = new_node;
        start->next = start;
    }
    else
    {
        temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = start;
    }
}