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

---

## Notes and Complexity
- Time complexity: O(log n)
- Space complexity: O(1)
- Assumes the input array is sorted. Sort before searching if not.

---

## Example
Input: n=5, arr = [2,4,6,8,10], key = 6

Output: Element found at position 3
