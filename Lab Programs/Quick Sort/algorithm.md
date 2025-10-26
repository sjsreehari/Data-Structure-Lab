# Quick Sort

---

## Aim
Sort an array using Quick Sort (Divide and Conquer, Lomuto partition scheme).

---

## Algorithm
1. Choose pivot (here arr[high]).
2. Partition array around pivot using `partition()`.
3. Recursively sort left and right subarrays.

---

## Complexity
- Average: O(n log n)
- Worst-case: O(n^2)

---

## Notes
- Use `partition()` to place pivot in correct position and return index.
- For better worst-case behavior, choose pivot using median-of-three or randomized pivot.

---

## Example
Input: arr = [10, 7, 8, 9, 1, 5]

Sorted: [1,5,7,8,9,10]
