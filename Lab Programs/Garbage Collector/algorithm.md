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

---

## Data Structures
- Doubly linked list of `Block` nodes with fields: `size`, `is_free`, `prev`, `next`, `data`.

---

## Operations (detailed)
1. `create_block(size)`: Allocate a new `Block` node and `data` buffer of given size.
2. `allocate(size)`: Search the list for the first free block with sufficient size (first-fit). If none found, append a new block.
3. `deallocate(ptr)`: Mark the block containing `ptr` as free.
4. `garbage_collect()`: Traverse the list and coalesce adjacent free blocks by merging sizes and removing extra nodes.
5. `display_blocks()`: Print block list with allocation status.

---

## Complexity
- Allocation (first-fit): O(m) where m = number of blocks in list.
- Deallocation: O(m) to locate block.
- Garbage collection (one pass): O(m).

---

## Example (program flow)
1. Allocate three blocks (100, 200, 150).
2. Display blocks.
3. Deallocate second and third blocks.
4. Display blocks.
5. Run `garbage_collect()` to merge adjacent free blocks.
6. Display resulting blocks.
