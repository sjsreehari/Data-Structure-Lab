# Bubble Sort

---

## Aim
Sort an array using Bubble Sort and report the number of steps (comparisons + swaps).

---

## Algorithm (Iterative)
1. Read n and the array arr[0..n-1].
2. For i = 0 to n-2:
   - For j = 0 to n-i-2:
     - Compare arr[j] and arr[j+1]. If arr[j] > arr[j+1], swap them.
3. After the loops, the array is sorted.

---

## Complexity
- Worst / Average: O(n^2)
- Best (already sorted): O(n)

---

## Notes
- This program counts a "step" for each comparison and for each swap.

---

## Complexity
- Worst / Average: O(n^2)
- Best (already sorted): O(n)

---

## Example
Input: [5,1,4,2,8]

Sorted: [1,2,4,5,8]
