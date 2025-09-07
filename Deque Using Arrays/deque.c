// ...existing code...

#include <stdio.h>
int front = -1, rear = -1;
int isFull(int size)
{
    return ((rear + 1) % size == front);
}
int isEmpty()
{
    return (front == -1);
}
void push(int deque[], int size, int value)
{
    if (isFull(size))
    {
        printf("Deque is full (Overflow)\n");
    }
    else
    {
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            front = (front - 1 + size) % size;
        }
        deque[front] = value;
        printf("Pushed %d at front\n", value);
    }
}
void inject(int deque[], int size, int value)
{
    if (isFull(size))
    {
        printf("Deque is full (Overflow)\n");
    }
    else
    {
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        deque[rear] = value;
        printf("Injected %d at rear\n", value);
    }
}
void pop(int deque[], int size)
{
    if (isEmpty())
    {
        printf("Deque is empty (Underflow)\n");
    }
    else
    {
        printf("Popped %d from front\n", deque[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
}
void eject(int deque[], int size)
{
    if (isEmpty())
    {
        printf("Deque is empty (Underflow)\n");
    }
    else
    {
        printf("Ejected %d from rear\n", deque[rear]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear = (rear - 1 + size) % size;
        }
    }
}
void display(int deque[], int size)
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Deque elements: ");
        int i;
        for (i = front; i != rear; i = (i + 1) % size)
        {
            printf("%d ", deque[i]);
        }
        printf("%d\n", deque[rear]);
    }
}
int main()
{
    int size, mainChoice, subChoice, value;
    printf("Enter the size of the deque: ");
    scanf("%d", &size);
    int deque[size];
    while (1)
    {
        printf("\n---- Main Menu ----\n");
        printf("1. Input Restricted Deque\n");
        printf("2. Output Restricted Deque\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);
        switch (mainChoice)
        {
        case 1:
            while (1)
            {
                printf("\n-- Input Restricted Deque --\n");
                printf("1. Inject (Insert at rear)\n");
                printf("2. Pop (Delete from front)\n");
                printf("3. Eject (Delete from rear)\n");
                printf("4. Display\n");
                printf("5. Back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);
                switch (subChoice)
                {
                case 1:
                    printf("Enter value to inject: ");
                    scanf("%d", &value);
                    inject(deque, size, value);
                    break;
                case 2:
                    pop(deque, size);
                    break;
                case 3:
                    eject(deque, size);
                    break;
                case 4:
                    display(deque, size);
                    break;
                case 5:
                    goto main_menu;
                default:
                    printf("Invalid choice. Try again.\n");
                }
            }
        case 2:
            while (1)
            {
                printf("\n-- Output Restricted Deque --\n");
                printf("1. Push (Insert at front)\n");
                printf("2. Inject (Insert at rear)\n");
                printf("3. Pop (Delete from front)\n");
                printf("4. Display\n");
                printf("5. Back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);
                switch (subChoice)
                {
                case 1:
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(deque, size, value);
                    break;
                case 2:
                    printf("Enter value to inject: ");
                    scanf("%d", &value);
                    inject(deque, size, value);
                    break;
                case 3:
                    pop(deque, size);
                    break;
                case 4:
                    display(deque, size);
                    break;
                case 5:
                    goto main_menu;
                default:
                    printf("Invalid choice. Try again.\n");
                }
            }
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    main_menu:; // Label to return to main menu
    }
    return 0;
}
