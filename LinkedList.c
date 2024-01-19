#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *start = NULL;

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
        printf("Count nodes [3]\n");
        printf("Insert a node at a position [4]\n");
        printf("Delete a node at a position [5]\n");
        printf("Search for an element [6]\n");
        printf("Sort List [7]\n");
        printf("Reverse List [8]\n");
        printf("Sum [9]\n");
        printf("Average [10]\n");
        printf("Max [11]\n");
        printf("Remove ODD [12]\n");
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
            count_nodes();
        }
        else if (choice == 4)
        {
            printf("Enter data: ");
            scanf("%d", &items);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertnode(pos, items);
        }
        else if (choice == 5)
        {
            printf("Enter data: ");
            scanf("%d", &items);
            deletenode(items);
        }
        else if (choice == 6)
        {
            printf("Enter element to be searched: ");
            scanf("%d", &items);
            lin_search(items);
        }
        else if (choice == 7)
        {
            sort();
        }
        else if (choice == 8)
        {
            reverse();
        }
        else if (choice == 9)
        {
            sum();
        }
        else if (choice == 10)
        {
            average();
        }
        else if (choice == 11)
        {
            max();
        }
        else if (choice == 12)
        {
            delodd();
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

    if (start == NULL)
    {
        start = new_node;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
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
void count_nodes()
{
    struct node *temp = start;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes: %d", count);
}

void deletenode(pos)
{
    struct node *temp = start;
    int i;
    // Shift start pointer to 2nd node and delete first node 
    if (pos == 1)
    {
        start = temp->next;
        free(temp);
    }
    else
    {
        // to make it reach the node before the node to be deleted
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        // assigning required node to new temp variable
        struct node *temp2 = temp->next;
        // changing next address value in the node before
        temp->next = temp2->next;
        // deleting node
        free(temp2);
        printf("Node Deleted at %d", pos);
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
        // New_node now points to original first node pointed by start previously
        new_node->next = temp;
        // start points to New_node now
        start = new_node;
    }
    else
    {
        // to make it reach the node before the node to be deleted
        for (i = 1; i < pos-1; i++)
        {
            temp = temp->next; // 1 -> node2, 2 -> node3 for pos = 4
        }
        // assigning current next node address to new node
        new_node->next = temp->next; //next = 5
        // changing next address value in the node before to newnode
        temp->next = new_node; // node3->next = newnode
        printf("Node Inserted at %d", pos);
    }
}

void delodd()
{
    struct node *temp = start;
    struct node *oddprev = NULL; // this node will point to node right before last node containing odd data

    // to make it reach the node before the node to be deleted
    while (temp->next != NULL)
    {
        if (temp == start && temp->data % 2 == 1)
        {
            start = start->next;
            free(temp);
        }
        else if (temp->next->data % 2 == 1)// Move oddprev pointer to node right before odd data node
        {
            oddprev = temp;
            printf(" After %d", oddprev->data);
            struct node *temp2 = oddprev->next;
            oddprev->next = temp2->next;
            free(temp2);
        }
        temp = temp->next;
    }
    // assigning required node to new temp variable    
}

void removelastodd()
{
    struct node *temp = start;
    struct node *oddprev = NULL; // this node will point to node right before last node containing odd data

    // to make it reach the node before the node to be deleted
    while (temp->next != NULL)
    {
        if (temp->next->data % 2 == 1)// Move oddprev pointer to node right before odd data node
        {
            oddprev = temp;
            printf(" After %d", oddprev->data);
        }
        temp = temp->next;
    }
    // assigning required node to new temp variable
    struct node *temp2 = oddprev->next;
    // changing next address value in the node before
    oddprev->next = temp2->next;
    // deleting node
    free(temp2);
}


void lin_search(item)
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



void sum()
{
    struct node *temp = start;
    int i, sum = 0;
    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum: %d", sum);
    
}

void average()
{
    struct node *temp = start;
    int i, sum = 0, count = 0;
    while (temp != NULL)
    {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    printf("Average: %d", sum/count);
}

void max()
{
    struct node *temp = start;
    int i, max = 0;
    while (temp != NULL)
    {
        if (temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    printf("Max: %d",max);
}

void sort()
{
    struct node *head = start;
    struct node *next1;
    next1 = head;
    int temp;
    // while (next1 != NULL)
    // {
    //
    //     head = head->next;
    //     next1 = head->next;
    // }
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
    printf("List Sorted");
}

void reverse()
{
    // current node
    struct node *head = start;
    // stores address of node before current
    struct node *prev=NULL;
    // stores address of node after current
    struct node *next1;
    // check when we reach last node where after updating head address, it has NULL address for next link
    while (head != NULL)
    {
        // Moving next pointer forward once from current position (moving towards end)
        next1 = head->next;
        // Updating current position link to previous node's address [NULL for first node] (reversing the links)
        head->next = prev;
        // Prev points to the node before current node always
        prev = head;
        // Updating the current pointer to move to the next node
        head = next1;
    }
    // Since currently start points to original first node, update start to point to the last node which is stored in prev after loop
    start = prev;
    printf("Linked List Reversed.\n");
    traverse();
}