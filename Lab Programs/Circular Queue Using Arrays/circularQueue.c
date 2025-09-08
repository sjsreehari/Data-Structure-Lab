#include <stdio.h>
int front = -1, rear = -1;

// Enqueue Operation
void enqueue(int queue[], int size, int value)
{
    if ((rear + 1) % size == front)
    {
        printf("Queue is full (Overflow)\n");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}
// Dequeue Operation
void dequeue(int queue[], int size)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty (Underflow)\n");
    }
    else if (front == rear)
    {
        printf("Deleted element: %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front = (front + 1) % size;
    }
}
// Display Operation
void display(int queue[], int size)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i = front;
        printf("Queue elements: ");
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % size;
        }
        printf("%d\n", queue[rear]);
    }
}
// Main Menu
int main()
{
    int size, choice, value;
    printf("Enter the size of the circular queue: ");
    scanf("%d", &size);
    int queue[size]; // Variable Length Array (VLA)
    while (1)
    {
        printf("\n---- Circular Queue Menu ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(queue, size, value);
            break;
        case 2:
            dequeue(queue, size);
            break;
        case 3:
            display(queue, size);
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}