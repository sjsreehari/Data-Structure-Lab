# Heap Sort (Heap)

---

## Aim
Sort an array using Heap Sort. Build a max-heap then repeatedly extract the maximum.

---

## Algorithm (Heap Sort)
1. Build max-heap from array using `createheap(arr, n, i)` starting from i = n/2 - 1 down to 0.
2. For i = n-1 down to 1:
   - Swap arr[0] and arr[i]
   - Reduce heap size by 1 and call `createheap(arr, i, 0)` to re-heapify.

---

## Notes
- In-place, not stable, O(n log n) time.

---

## Complexity
- Time: O(n log n)
- Space: O(1) additional

---

## Example
Input: arr = [4, 10, 3, 5, 1]

After heapSort -> [1, 3, 4, 5, 10]
