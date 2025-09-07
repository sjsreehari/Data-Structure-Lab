
# Aim

    To implement circular queue operations using arrays in C.

# Algorithm

    Step 1: Start

    Step 2: Define Data Structure
        Define an array queue[MAX] to store elements
        front → integer index for front
        rear  → integer index for rear
        MAX   → maximum size of queue

    Step 3: Initialize Queue (initializeQueue)
        Set front = -1, rear = -1
        Queue is now empty

    Step 4: Check if Queue is Full (isFull)
        If (front == (rear + 1) % MAX):
            Return true
        Else:
            Return false

    Step 5: Check if Queue is Empty (isEmpty)
        If front == -1:
            Return true
        Else:
            Return false

    Step 6: Enqueue Operation (enqueue)
        If queue is full:
            Display overflow message
        Else:
            If (front == -1):
                Set front = 0
            rear = (rear + 1) % MAX
            Insert element at queue[rear]
            Display success message

    Step 7: Dequeue Operation (dequeue)
        If queue is empty:
            Display underflow message
        Else:
            Remove element from queue[front]
            If (front == rear):
                Set front = rear = -1
            Else:
                front = (front + 1) % MAX
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
            Print elements from front to rear in circular manner

    Step 10: Stop
