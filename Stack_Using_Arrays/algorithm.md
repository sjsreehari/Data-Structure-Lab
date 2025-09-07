
# Aim

    To implement stack operations using arrays in C.

# Algorithm

    Step 1: Start

    Step 2: Define Data Structure
        Define an array stack[MAX] to store elements
        top → integer index for top of stack
        MAX → maximum size of stack

    Step 3: Initialize Stack (initializeStack)
        Set top = -1
        Stack is now empty

    Step 4: Check if Stack is Full (isFull)
        If top == MAX - 1:
            Return true
        Else:
            Return false

    Step 5: Check if Stack is Empty (isEmpty)
        If top == -1:
            Return true
        Else:
            Return false

    Step 6: Push Operation (push)
        If stack is full:
            Display overflow message
        Else:
            Increment top
            Insert element at stack[top]
            Display success message

    Step 7: Pop Operation (pop)
        If stack is empty:
            Display underflow message
        Else:
            Remove element from stack[top]
            Decrement top
            Display success message

    Step 8: Peek Operation (peek)
        If stack is empty:
            Display empty message
        Else:
            Display element at stack[top]

    Step 9: Display Stack (displayStack)
        If stack is empty:
            Display empty message
        Else:
            Print elements from top to 0

    Step 10: Stop
