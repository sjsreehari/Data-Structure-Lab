# Simple Garbage Collector Demo

---

## Aim
Demonstrate a simple memory management simulation using a doubly linked list of memory blocks with allocation (first-fit), deallocation, and garbage collection (coalescing free blocks).

---

## Data Structures
- Doubly linked list of `Block` structs. Each block has `size`, `is_free`, `prev`, `next`, and `data` pointer.

---

## Algorithm (Overview)
1. `allocate(size)`: Search the list for the first free block with sufficient size. If found, mark it allocated and return pointer to `data`. Otherwise, create a new block and append it.
2. `deallocate(ptr)`: Find the block whose `data` matches `ptr` and mark it free.
3. `garbage_collect()`: Traverse the list and merge adjacent free blocks by coalescing their sizes and freeing the extra nodes.
4. `display_blocks()`: Print list of blocks and their allocation status.

---

## Notes
- This is a pedagogical simulation; in real systems, allocators use more sophisticated metadata and strategies.
- The demo creates three blocks and shows deallocation and merging.
