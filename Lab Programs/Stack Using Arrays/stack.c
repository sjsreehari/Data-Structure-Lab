#include <stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;

int isFull()
{
    return top == MAX - 1;
}

int isEmpty()
{
    return top == -1;
}

void push(int value)
{
    if (isFull())
    {
        printf("Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        stack[++top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

void pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow! Nothing to pop.\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top--]);
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}