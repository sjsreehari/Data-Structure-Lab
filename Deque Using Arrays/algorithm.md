
# Aim

    To implement deque (double-ended queue) operations using arrays in C.

# Algorithm

    Step 1: Start

    Step 2: Define Data Structure
        Define an array deque[MAX] to store elements
        front → integer index for front
        rear  → integer index for rear
        MAX   → maximum size of deque

    Step 3: Initialize Deque (initializeDeque)
        Set front = -1, rear = -1
        Deque is now empty

    Step 4: Check if Deque is Full (isFull)
        If (front == (rear + 1) % MAX):
            Return true
        Else:
            Return false

    Step 5: Check if Deque is Empty (isEmpty)
        If front == -1:
            Return true
        Else:
            Return false

    Step 6: Insert at Front (insertFront)
        If deque is full:
            Display overflow message
        Else:
            If (front == -1):
                Set front = rear = 0
            Else if (front == 0):
                Set front = MAX - 1
            Else:
                Decrement front
            Insert element at deque[front]
            Display success message

    Step 7: Insert at Rear (insertRear)
        If deque is full:
            Display overflow message
        Else:
            If (rear == -1):
                Set front = rear = 0
            Else if (rear == MAX - 1):
                Set rear = 0
            Else:
                Increment rear
            Insert element at deque[rear]
            Display success message

    Step 8: Delete from Front (deleteFront)
        If deque is empty:
            Display underflow message
        Else:
            Remove element from deque[front]
            If (front == rear):
                Set front = rear = -1
            Else if (front == MAX - 1):
                Set front = 0
            Else:
                Increment front
            Display success message

    Step 9: Delete from Rear (deleteRear)
        If deque is empty:
            Display underflow message
        Else:
            Remove element from deque[rear]
            If (front == rear):
                Set front = rear = -1
            Else if (rear == 0):
                Set rear = MAX - 1
            Else:
                Decrement rear
            Display success message

    Step 10: Peek Front (peekFront)
        If deque is empty:
            Display empty message
        Else:
            Display element at deque[front]

    Step 11: Peek Rear (peekRear)
        If deque is empty:
            Display empty message
        Else:
            Display element at deque[rear]

    Step 12: Display Deque (displayDeque)
        If deque is empty:
            Display empty message
        Else:
            Print elements from front to rear in circular manner

    Step 13: Stop
