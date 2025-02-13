#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};
struct queue *QueueNode, *front = NULL, *rear = NULL, *temp;

void enqueue();
void dequeue();
void display();

int main()
{
    enqueue(1);
    enqueue(2);
    dequeue();
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    return 0;
}

void enqueue(int value)
{
    QueueNode = (struct queue *)malloc(sizeof(struct queue));
    QueueNode->data = value;
    QueueNode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = temp = QueueNode;
    }
    else
    {
        rear->next = QueueNode;
        rear = QueueNode;
    }
}

void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        temp = front;
        front = rear = NULL;
        free(temp);
    }
    else
    {
        temp = front;
        front = front->next;
        free(temp);
    }
}

void display()
{
    printf("Displaying queue : \n");
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;
        rear->next = NULL;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
