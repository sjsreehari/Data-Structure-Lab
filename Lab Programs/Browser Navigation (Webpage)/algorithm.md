# Browser Navigation (Webpage)

---

## Aim
Implement backward and forward navigation for visited webpages using a doubly linked list.

---

## Algorithm
1. Maintain a doubly linked list of visited pages with `head` and `current` pointers.
2. `visitPage(url)`: Create new node, truncate forward history, append node, set `current` to new node.
3. `goBack()`: If `current->prev` exists, move `current` back.
4. `goForward()`: If `current->next` exists, move `current` forward.
5. `displayCurrentPage()`: Print `current->url`.

---

## Notes
- Uses dynamic allocation for each visited page node.
- Removing forward history frees memory for nodes beyond the current page.
