
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

int isFull()
{
    return rear == MAX - 1;
}

int isEmpty()
{
    return front == -1 || front > rear;
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue Overflow %d \n", value);
    }
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = value;
        printf("%d enqueued  into queue.  \n", value);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        printf("Dequeued element: %d\n", queue[front++]);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to Insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}