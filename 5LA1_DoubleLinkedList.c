#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*start = NULL, *last = NULL;

void main()
{
    int i, n, items, flag, choice, pos;
    printf("Enter 0 to exit or 1 to continue: ");
    scanf("%d", &flag);
    while (flag == 1)
    {
        printf("\n");
        printf("***MENU***\n");
        printf("Create new node [1]\n");
        printf("Display [2]\n");
        printf("Insert a node at a position [3]\n");
        printf("Delete a node [4]\n");
        printf("Search for an element [5]\n");
        printf("Sort List [6]\n");
        printf("Reverse List [7]\n");
        printf("Exit [0]\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            flag = 0;
            break;
        }

        else if (choice == 1)
        {
            printf("Enter data: ");
            scanf("%d", &items);
            create_node(items);
        }
        else if (choice == 2)
        {
            traverse();
        }
        else if (choice == 3)
        {
            printf("Enter data: ");
            scanf("%d", &items);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertnode(pos, items);
        }
        else if (choice == 4)
        {
            printf("Enter data: ");
            scanf("%d", &items);
            deletenode(items);
        }
        else if (choice == 5)
        {
            printf("Enter element to be searched: ");
            scanf("%d", &items);
            search(items);
        }
        else if (choice == 6)
        {
            sort();
        }
        else if (choice == 7)
        {
            reverse();
        }
        else
        {
            printf("Invalid choice");
        }
    }
}
void create_node(int items)
{
    struct node *temp;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = items;
    new_node->next = NULL;
    new_node->prev = NULL;


    if (start == NULL)
    {
        start = new_node;
        last = new_node;
    }
    else
    {
        last->next= new_node;
        new_node->prev = last;
        last = new_node;
    }
}

void traverse()
{
    struct node *temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


void deletenode(item)
{
    struct node *temp = start;
    struct node *temp1 = start;

    int i,pos=1;
    if (temp->data == item)
    {
        start = temp->next;
        free(temp);
        printf("First node containing value [%d] deleted.",item);
    }
    while (temp->data != item && temp != NULL)
    {
        temp = temp->next;
        pos++;
    }
    if (temp == NULL)
    {
        printf("Element doesn't exist");
    }
    else if (temp->data == item)
    {
        // to make it reach the node before the node to be deleted
        for (i = 0; i < pos - 2; i++)
        {
            temp1 = temp1->next;
        }
        // assigning required node to new temp variable
        struct node *temp2 = temp1->next;
        // changing next address value in the node before
        temp1->next = temp2->next;
        // deleting node
        free(temp2);
        printf("Node containing value [%d] deleted.",item);
    }
}

void insertnode(pos, data)
{
    struct node *temp = start;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    int i;
    if (pos == 1)
    {
        new_node->next = temp->next;
        start = new_node;
    }
    else
    {
        // to make it reach the node before the node to be deleted
        for (i = 0; i < pos - 2; i++)
        {
            temp = temp->next;
        }
        // assigning current next node address to new node
        new_node->next = temp->next;
        // changing next address value in the node before to newnode
        temp->next = new_node;
        printf("Node Inserted at %d", pos);
    }
}

void search(item)
{
    struct node *temp = start;
    int i, count = 1;
    while (temp->data != item && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        printf("Element doesn't exist");
    }
    else
    {
        printf("Element found at node: %d", count);
    }
}

void sort()
{
    struct node *head = start;
    struct node *next1;
    next1 = head;
    int temp;

    while (next1 != NULL)
    {
        for (head = next1->next; head != NULL; head = head->next)
        {
            if (head->data < next1->data)
            {
                temp = head->data;
                head->data = next1->data;
                next1->data = temp;
            }
        }
        next1 = next1->next;
    }
    printf("Sorted List:\n");
    traverse();
}

void reverse()
{
    struct node *temp1 = start;
    struct node *temp2=last;
    while (temp1 != temp2 && temp1->prev != temp2)
    {
        // Swapping data between last and first
        int temp = temp1->data;
        temp1->data = temp2->data;
        temp2->data = temp;
        // Moving start pointer forward and last pointer backward
        temp1 = temp1->next;
        temp2 = temp2->prev;
    }
    printf("Reversed List:\n");
    traverse();
}