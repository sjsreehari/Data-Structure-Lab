# Trees

---

## Definition
A **Tree** is a non-linear data structure consisting of nodes connected by edges, with the following properties:
- One node is designated as the root.
- Every node (except root) has exactly one parent.
- A tree with n nodes has exactly n-1 edges.
- No cycles exist in a tree.

---

## Terminology
- **Root**: The topmost node (no parent).
- **Parent & Child**: Directly connected nodes.
- **Siblings**: Nodes with the same parent.
- **Leaf**: Node with no children.
- **Height of a node**: Length of longest path to a leaf.
- **Height of tree**: Height of root node.
- **Depth of node**: Distance from root.

---

## Types of Trees
1. General Tree: No restriction on number of children.
2. Binary Tree: Each node has at most 2 children.
3. Full Binary Tree: Every node has 0 or 2 children.
4. Complete Binary Tree: All levels filled except last, filled left to right.
5. Perfect Binary Tree: All internal nodes have 2 children, all leaves at same depth.
6. Binary Search Tree (BST): Left < Root < Right.
7. AVL Tree: Self-balancing BST with balance factor = {-1, 0, 1}.

---

## Binary Tree Traversals
### Depth First Traversals (DFS)
- Inorder (Left, Root, Right)
- Preorder (Root, Left, Right)
- Postorder (Left, Right, Root)

### Breadth First Traversal (BFS)
- Level Order traversal using queue.

**Example Tree:**

        A
       / \
      B   C
     / \
    D   E

- Preorder: A B D E C
- Inorder: D B E A C
- Postorder: D E B C A
- Level-order: A B C D E

---

## Binary Search Tree (BST)
- Each node has a key.
- Left subtree < Root < Right subtree.
- Operations:
  - Search: O(h), where h = height.
  - Insert: O(h).
  - Delete: O(h) (3 cases: leaf, one child, two children).

---

## Balanced Trees
- Aim: reduce height to log(n).
- Examples: AVL tree, Red-Black tree, B-Trees.
- AVL Rotation Types:
  1. LL Rotation
  2. RR Rotation
  3. LR Rotation
  4. RL Rotation

---

## Applications of Trees
- Hierarchical file systems
- Expression parsing
- Database indexing (B-trees, AVL)
