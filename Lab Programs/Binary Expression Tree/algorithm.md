
# Binary Expression Tree from Postfix Expression

---

## Aim
Construct a binary expression tree for a postfix arithmetic expression (single-digit operands, binary operators) and output its infix, prefix, and postfix forms using tree traversals.

---


# Binary Expression Tree from Postfix Expression

---

## Aim
Construct a binary expression tree from a postfix expression and print its infix, prefix, postfix, and pyramid forms using tree traversals and visual layout.

---

## Stepwise Algorithm (Code-matching)

### 1. Start

### 2. Data Structures
- Define struct Node with `data`, `left`, and `right` pointers.
- Use a global stack array `stack[100]` and integer `top` for stack operations.

### 3. Input
- Read postfix expression as a space-separated string into `line`.

### 4. Tree Construction
- Tokenize input using `strtok`.
- For each token:
    - If operand (`isdigit` or `isalpha`):
        - Call `newNode(token)` to create a node.
        - Call `push(node)` to push onto stack.
    - If operator:
        - Call `newNode(token)` to create a node.
        - Set `right = pop()`, `left = pop()`.
        - Assign children: `node->left = left`, `node->right = right`.
        - Call `push(node)`.
- After all tokens, `root = pop()`.

### 5. Menu Operations
- Display menu:
    1. Create tree (enter postfix)
    2. Print tree in pyramid form (`printPyramidTree(root)`)
    3. Print infix expression (`inorder(root)`)
    4. Print prefix expression (`preorder(root)`)
    5. Print postfix expression (`postorder(root)`)
    6. Clear tree (`clear(root)`)
    7. Exit

### 6. Traversal Functions
- `inorder(root)`: Print left subtree, node data, right subtree, with parentheses for internal nodes.
- `preorder(root)`: Print node data, left subtree, right subtree.
- `postorder(root)`: Print left subtree, right subtree, node data.

### 7. Pyramid Printing
- `height(root)`: Compute tree height.
- `fillMatrix(node, matrix, row, col, tree_height)`: Fill matrix for visual layout.
- `printPyramidTree(root)`: Print matrix row by row for pyramid effect.

### 8. Clear Tree
- `clear(root)`: Recursively free all nodes.

### 9. End

---

## Example

Input: `23 + 45 - *`

Tree Structure:
      *
     / \
    +   -
   / \ / \
  2  3 4  5

Infix: ((2+3)*(4-5))
Prefix: *+23-45
Postfix: 23+45-*

---

## Notes
- All function names and logic match the code for clarity.
- Pyramid printing uses matrix and spacing for visual output.
- Traversals map to required notations.
- Free memory after clearing tree.

---