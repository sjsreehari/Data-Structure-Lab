
# Aim

    To implement queue operations using arrays in C.

# Algorithm

    Step 1: Start

    Step 2: Define Data Structure
        Define an array queue[MAX] to store elements
        front → integer index for front
        rear  → integer index for rear
        MAX   → maximum size of queue

    Step 3: Initialize Queue (initializeQueue)
        Set front = 0, rear = -1
        Queue is now empty

    Step 4: Check if Queue is Full (isFull)
        If rear == MAX - 1:
            Return true
        Else:
            Return false

    Step 5: Check if Queue is Empty (isEmpty)
        If front > rear:
            Return true
        Else:
            Return false

    Step 6: Enqueue Operation (enqueue)
        If queue is full:
            Display overflow message
        Else:
            Increment rear
            Insert element at queue[rear]
            Display success message

    Step 7: Dequeue Operation (dequeue)
        If queue is empty:
            Display underflow message
        Else:
            Remove element from queue[front]
            Increment front
            Display success message

    Step 8: Peek Operation (peek)
        If queue is empty:
            Display empty message
        Else:
            Display element at queue[front]

    Step 9: Display Queue (displayQueue)
        If queue is empty:
            Display empty message
        Else:
            Print elements from front to rear

    Step 10: Stop
