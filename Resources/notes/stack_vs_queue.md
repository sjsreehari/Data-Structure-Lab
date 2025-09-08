#  Stack vs Queue – KTU Notes

---

## 🔹 Introduction
Both **Stack** and **Queue** are linear data structures, but they differ in how elements are inserted and removed.

- **Stack** → Follows **LIFO (Last In, First Out)** principle.  
- **Queue** → Follows **FIFO (First In, First Out)** principle.  

---

## 🔹 Stack
### Definition
A **stack** is an ordered collection where insertion and deletion happen only at **one end** called the **top**.

### Operations
1. **push(x)** → Insert element at top.  
2. **pop()** → Remove element from top.  
3. **peek() / top()** → Return top element without removing.  
4. **isEmpty() / isFull()** → Check stack status.

### Representation
- Implemented using **arrays** or **linked lists**.  
- Time complexity:  
  - Push/Pop → O(1)  
  - Search (in array) → O(n)

### Applications
- Expression evaluation (infix → postfix).  
- Function call management (recursion).  
- Undo/Redo operations.  
- Syntax checking (balanced parentheses).  

---

## 🔹 Queue
### Definition
A **queue** is an ordered collection where insertion happens at the **rear** and deletion happens at the **front**.

### Operations
1. **enqueue(x)** → Insert element at rear.  
2. **dequeue()** → Remove element from front.  
3. **peek() / front()** → Return element at front.  
4. **isEmpty() / isFull()** → Check queue status.

### Variants
- **Circular Queue** – Rear connects to front (efficient space use).  
- **Double-Ended Queue (Deque)** – Insertion/deletion from both ends.  
- **Priority Queue** – Elements removed based on priority, not arrival.  

### Applications
- Scheduling (CPU, disk, printers).  
- Buffers in IO devices.  
- Networking (packets, bandwidth management).  
- Breadth-first search (BFS) in graphs.  

---

## 🔹 Comparison Table

| Feature            | Stack (LIFO)                         | Queue (FIFO)                        |
|--------------------|---------------------------------------|--------------------------------------|
| Principle          | Last In, First Out                   | First In, First Out                  |
| Insertion          | Only at **Top**                      | Only at **Rear**                     |
| Deletion           | Only from **Top**                    | Only from **Front**                  |
| Main Operations    | push(), pop(), peek()                | enqueue(), dequeue(), front()        |
| Implementation     | Array / Linked List                  | Array / Linked List                  |
| Variants           | –                                    | Circular Queue, Deque, Priority Queue|
| Time Complexity    | Push/Pop → O(1)                      | Enqueue/Dequeue → O(1)               |
| Applications       | Expression evaluation, recursion, undo| Scheduling, buffering, BFS, IO mgmt. |

---

## 🔹 KTU Short Notes Points
- Stack → LIFO; Queue → FIFO.  
- Stack → push/pop; Queue → enqueue/dequeue.  
- Stack used in **recursion, parsing**.  
- Queue used in **scheduling, resource allocation**.  
- Both can be implemented using **arrays** or **linked lists**.  

---
