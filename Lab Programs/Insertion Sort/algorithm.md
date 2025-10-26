# Insertion Sort

---

## Aim
Sort an array using Insertion Sort and report the number of steps (shifts + placements).

---

## Algorithm
1. Read n and arr[0..n-1].
2. For i = 1 to n-1:
   - key = arr[i]; j = i-1
   - While j >= 0 and arr[j] > key:
       - shift arr[j] to arr[j+1]
       - j--
   - place key at arr[j+1]
3. Array sorted.

---

## Complexity
- Worst / Average: O(n^2)
- Best (already sorted): O(n)

---

## Example
Input: [12, 11, 13, 5, 6]

Sorted: [5, 6, 11, 12, 13]
