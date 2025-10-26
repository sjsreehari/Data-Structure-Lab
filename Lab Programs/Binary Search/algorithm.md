# Binary Search

---

## Aim
Perform binary search on a sorted array and return the position of a given key.

---

## Algorithm (Iterative Binary Search)
1. Read n and the sorted array arr[0..n-1].
2. Read key to search.
3. Initialize low = 0, high = n-1.
4. While low <= high:
   - mid = (low + high) / 2
   - If arr[mid] == key, return mid
   - If arr[mid] < key, low = mid + 1
   - Else high = mid - 1
5. If not found, return -1.

---

## Input/Output
- Input: number of elements, sorted elements, key
- Output: position (1-based) if found, otherwise "Element not found"
