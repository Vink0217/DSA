// Queue: FIFO; insertion from last, deletion from first
//Circular queue made to avoid wastage of deleted empty spaces
// Front and rear have a space of 1 data block so that f = r condition doesnt clash
// Size of circular queue = size input - 1
// (front/rear + 1)%size always provides the value of next index for either index pointers to ensure they remain circular

#include <stdio.h>
#include <stdlib.h>

struct Queue //Circular
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->Q = (int *)malloc(q->size * sizeof(int));
    q->front = q->rear = 0;

    printf("Created circular queue of size %d.\n", q->size);
}

void enqueue(struct Queue *q, int data) //O(1)
{
    if((q->rear+1)%q->size == q->front)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear] = data;// inserting data at new rear position
    }
}

int dequeue(struct Queue *q) //O(1)
{
    int x = -1;
    if (q->rear==q->front)
        printf("Queue is empty\n");
    else
    {
        q->front=(q->front+1)%q->size; //Moving front to position of element to delete
        x = q->Q[q->front]; // storing value
    }
    return x;// empty position for deleted element
}

int isEmpty(struct Queue q)
{
    if(q.front == q.rear)
        return 1;
    else
        return 0;
}

int isFull(struct Queue q)
{
    if(q.front == (q.rear+1)%q.size)
        return 1;
    else
        return 0;
}

int front(struct Queue q)
{
    return q.Q[q.front];
}

int rear(struct Queue q)
{
    return q.Q[q.rear];
}

void display(struct Queue q)
{
    int i = q.front + 1;
    printf("Queue:\n");
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    printf("\n");
} 

// ------------- DEQueue --------------------

void InsertFromRear(struct Queue *q, int x)
{
    if (q->rear == q->size)
    {
        printf("Queue is Full from Back\n");
    }
    else if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->Q[q->rear] = x;
        q->rear = q->rear + 1;
    }else{
        q->Q[q->rear] = x;
        q->rear = q->rear + 1;
    }
}
 
// for deleting from front
void DeleteFromFront(struct Queue *q)
{
    // Checks for empty array
    if (q->rear == -1 && q->front == -1 || q->front == q->rear)
    {
        printf("Queue is Empty\n");
        q->front = -1;
        q->rear = -1;
    }else{
        printf("%d has been deleted from queue\n", q->Q[q->front]); //line shifted above
        q->front = q->front + 1;
        
    }
}

// for inserting from front 
void InsertFromFront(struct Queue *q, int x)
{
    
    if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->Q[q->rear] = x;
        q->rear = q->rear + 1;
    }
    else if (q->front == 0)
    {
        printf("Queue is Full from front\n");
    }
    else
    {
        // first assign value to x and then move rear pointer
        
        //changes here
        q->Q[q->front-1] = x;
        q->front = q->front- 1;
    }
}
 
// for deleting from rear
void DeleteFromRear(struct Queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("Queue is Empty");
    }else
    {
        if (q->rear <= q->front)
        {
            printf("Queue is Empty");
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            printf("%d has been deleted from queue\n", q->Q[q->rear-1]);
            q->rear = q->rear - 1;
            // q->size = q->size - 1; //removed this line
        }
    }
}

void main()
{
    struct Queue q1;

    create(&q1, 5);

    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    enqueue(&q1, 4);
    enqueue(&q1, 5); // Queue full
    enqueue(&q1, 6); // Queue full


    display(q1);

    if (isFull(q1))
        printf("Queue is Full.\n");
    else
        printf("Queue is not Full.\n");
    
    printf("Deleted %d\n", dequeue(&q1));
    printf("Deleted %d\n", dequeue(&q1));
    printf("Deleted %d\n", dequeue(&q1));

    if (isEmpty(q1))
        printf("Queue is Empty.");
    else
        printf("Queue is not Empty.");


// ------- DEQueue --------------

    struct Queue q;
    create(&q,10);
 
    printf("Inserted from Rear\n");
    InsertFromRear(&q,1);
    InsertFromRear(&q,2);
    InsertFromRear(&q,3);
    InsertFromRear(&q,4);
    Display(q);
    
    printf("Deleted from front\n");
    DeleteFromFront(&q);
    Display(q);
 
    printf("Inserted from Front\n");
    InsertFromFront(&q,5);
 
    Display(q);
    printf("%d  you are storing here (q.front )\n",q.front); 

 
    printf("Deleted from Rear\n");
    DeleteFromRear(&q);
    DeleteFromRear(&q);
    Display(q);
 
    // why I can't insert from front
    InsertFromFront(&q,1);
    // printf("Inserted 1 from front but gets inserted from rear\n");
    Display(q);

}