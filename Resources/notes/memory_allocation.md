
# Memory Allocation – KTU Notes

---

## Introduction
Memory allocation in C programming refers to reserving a portion of memory (RAM) for program variables and data structures during execution.
There are two broad categories:
1. Static (Compile-time) Allocation
2. Dynamic (Run-time) Allocation

Efficient memory allocation is crucial for performance and avoiding wastage or errors like segmentation faults.

---

## Static Memory Allocation
- Done at compile time.
- Size of variables/arrays must be known beforehand.
- Memory cannot be resized while the program runs.
- Example:
  ```c
  int arr[10];   // size fixed
  ```

**Pros**:

- Simple and fast.
- Memory assigned once, no overhead.

**Cons**:

- Wastage if array not fully used.
- Inflexible (cannot expand/shrink).

---

## Dynamic Memory Allocation

- Done at runtime using heap memory.
- Provides flexibility to allocate as much memory as needed.
- Implemented via pointers.

In C, dynamic memory functions are defined in `<stdlib.h>`:

1. malloc() – memory allocation
2. calloc() – contiguous allocation
3. realloc() – resize allocated memory
4. free() – release memory

---

## malloc()

- Allocates memory block of given size (in bytes).
- Returns a pointer to the allocated memory (void*).
- Memory is uninitialized (contains garbage values).

**Syntax:**

```c
ptr = (int*) malloc(n * sizeof(int));
```

**Example:**

```c
int *arr;
arr = (int*) malloc(5 * sizeof(int));  // allocates array of 5 integers
```

---

## calloc()

- Similar to malloc() but initializes memory to zero.
- Allocates multiple blocks and sets them to zero.

**Syntax:**

```c
ptr = (int*) calloc(n, sizeof(int));
```

**Example:**

```c
int *arr;
arr = (int*) calloc(5, sizeof(int));  // allocates array of 5 integers initialized to 0
```

---

## realloc()

- Changes size of previously allocated memory.
- Useful when we need to expand or shrink arrays dynamically.

**Syntax:**

```c
ptr = (int*) realloc(ptr, new_size);
```

**Example:**

```c
arr = (int*) realloc(arr, 10 * sizeof(int)); // resize array to hold 10 integers
```

---

## free()

- Releases dynamically allocated memory back to system.
- Prevents memory leaks.

**Syntax:**

```c
free(ptr);
```

**Example:**

```c
free(arr);
```

---

## Memory Allocation in C – Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i;
	int *arr;

	printf("Enter size: ");
	scanf("%d", &n);

	arr = (int*) malloc(n * sizeof(int));

	if (arr == NULL) {
		printf("Memory not allocated\n");
		return 1;
	}

	for (i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	printf("Array: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	free(arr);
	return 0;
}
```

---

## Memory Allocation Types in OS

1. Contiguous Allocation
   - Memory assigned in a continuous block.
   - Simple but causes fragmentation.

2. Non-Contiguous Allocation
   - Pages/segments stored at different memory locations.
   - Requires mapping techniques (paging/segmentation).

---

## Common Errors

- Dangling Pointer: Using pointer after memory freed.
- Memory Leak: Not freeing allocated memory.
- Double Free: Freeing already freed memory.
- Buffer Overflow: Writing beyond allocated memory.

---

## Complexity

- malloc/calloc/realloc: O(1) average, may vary with system.
- free: O(1).

---

## Applications

- Used in linked lists, trees, graphs (dynamic data structures).
- Required for implementing dynamic arrays.
- Essential in OS memory management, DBMS, compilers.

---
