
# Binary Expression Tree from Postfix Expression

---

## Aim
Construct a binary expression tree for a postfix arithmetic expression (single-digit operands, binary operators) and output its infix, prefix, and postfix forms using tree traversals.

---

## Problem Statement
Given a postfix expression, build its binary expression tree and print:
- Infix expression (inorder traversal, parentheses at internal nodes)
- Prefix expression (preorder traversal)
- Postfix expression (postorder traversal)

---

## Input Constraints
- Input is a single-line postfix expression
- Operands: single digits (0–9) or single letters (a–z)
- Operators: +, -, *, /

---

## Data Structures Used
- Stack (array of pointers to tree nodes)
- Binary tree node (stores symbol, left and right child)

---

## Stepwise Algorithm

### 1. Start

### 2. Initialize
- Create an empty stack for tree nodes
- Set root to NULL

### 3. Read Postfix Expression
- Accept postfix expression as a string

### 4. Build Expression Tree
- For each symbol in the postfix expression:
    - If symbol is an operand:
        - Create a new tree node with the symbol
        - Push the node onto the stack
    - If symbol is an operator:
        - Pop two nodes from the stack (right, then left)
        - Create a new node with the operator
        - Set left and right children to the popped nodes
        - Push the new node onto the stack
- After processing all symbols, the node at the top of the stack is the root

### 5. Menu-Driven Operations
- Repeat until user chooses exit:
    1. **Create tree**: Read postfix, build tree
    2. **Print infix expression**: Inorder traversal with parentheses at internal nodes
    3. **Print prefix expression**: Preorder traversal
    4. **Print postfix expression**: Postorder traversal
    5. **Clear tree**: Free all nodes
    6. **Exit**

### 6. Traversal Algorithms
- **Inorder (infix):**
    - If node is internal (has both children), print '('
    - Traverse left subtree
    - Print node data
    - Traverse right subtree
    - If node is internal, print ')'
- **Preorder (prefix):**
    - Print node data
    - Traverse left subtree
    - Traverse right subtree
- **Postorder (postfix):**
    - Traverse left subtree
    - Traverse right subtree
    - Print node data

### 7. Clear Tree
- Recursively free all nodes in the tree

### 8. End

---

## Example

**Input:**
```
23+45-*
```

**Tree Structure:**
```
      *
     / \
    +   -
   / \ / \
  2  3 4  5
```

**Infix:** ((2+3)*(4-5))
**Prefix:** *+23-45
**Postfix:** 23+45-*

---

## Notes
- Use stack for tree construction as per postfix rules
- Traversals map directly to required notations
- Free memory after clearing tree
- Handle invalid input gracefully

---

## End