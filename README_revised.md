# DSA Submissions - Comprehensive Documentation

A repository of Data Structures and Algorithms implementations in C++, covering linked lists, stacks, queues, sorting algorithms, trees, and classic algorithmic problems.

---

## Table of Contents

1. [Singly Linked List](#1-singly-linked-list)
2. [Doubly Linked List](#2-doubly-linked-list)
3. [Stack Using Array](#3-stack-using-array)
4. [Stack Using Linked List](#4-stack-using-linked-list)
5. [Queue Using Array](#5-queue-using-array)
6. [Circular Queue Using Array](#6-circular-queue-using-array)
7. [Queue Using Linked List](#7-queue-using-linked-list)
8. [Merge Sort](#8-merge-sort)
9. [Quick Sort](#9-quick-sort)
10. [Radix Sort](#10-radix-sort)
11. [Heap Sort](#11-heap-sort)
12. [Bucket Sort](#12-bucket-sort)
13. [K Smallest Elements (Partitioning)](#13-k-smallest-elements-partitioning)
14. [Bin Sort](#14-bin-sort)
15. [Tower of Hanoi](#15-tower-of-hanoi)
16. [Binary Trees](#16-binary-trees)
17. [Binary Search Tree](#17-binary-search-tree)
18. [AVL Trees](#18-avl-trees)
19. [Parentheses Matching](#19-parentheses-matching)

---

## Overview & Tech Stack

- **Language:** C++
- **Core concepts:** Linked lists, stacks, queues, sorting, partitioning, recursion, binary trees, and balanced search trees.
- **Standard libraries commonly used:** `<iostream>`, `<vector>`, `<algorithm>`, and `<stack>`.

---

## 1. Singly Linked List

---

### [LinkedListImp.cpp](LinkedListImp.cpp)

#### Description
Implements a Singly Linked List in which each node stores data and a pointer to the next node. Typical operations include insertion, deletion, searching, and traversal.

#### Algorithm
1. Define a node containing a data field and a `next` pointer.
2. Maintain a `head` pointer to the first node.
3. To traverse, start at `head` and follow `next` until `nullptr`.
4. To insert at the head, point the new node to the current head and update `head`.
5. To delete a node, locate it, reconnect the surrounding links, and release the removed node's memory.

#### Complexity
- **Time Complexity:**
  - Insert/delete at head: `O(1)`
  - Search/traversal: `O(N)`
  - Insert/delete at a position: `O(N)` in the general case
- **Space Complexity:** `O(N)` for the nodes.

#### Test Cases
- **Test Case 1:**
  - **Input:** `10 20 30`
- **Output:** `10 -> 20 -> 30 -> NULL`

---

## 2. Doubly Linked List

---

### [doubleLinkedList.cpp](doubleLinkedList.cpp)

#### Description
Implements a Doubly Linked List where each node stores data and two pointers: `next` to the following node and `prev` (or `back`) to the preceding node. It supports forward and backward traversal.

#### Algorithm
1. Define each node with `data`, `next`, and `prev` fields.
2. When inserting a node, update both the preceding node's `next` and the following node's `prev`.
3. When deleting a node, reconnect its previous and next nodes.
4. Traverse forward using `next` or backward using `prev`.

#### Complexity
- **Time Complexity:**
  - Insert/delete at head when the head is known: `O(1)`
  - Search/traversal: `O(N)`
  - Insert/delete at a position: `O(N)` to locate the position
- **Space Complexity:** `O(N)` for the nodes; each node stores an additional pointer compared with a singly linked list.

#### Test Cases
- **Test Case 1:**
  - **Input:** `10 20 30`
- **Output (forward):** `10 <-> 20 <-> 30 <-> NULL`

---

## 3. Stack Using Array

---

### [stackUsingArray.cpp](stackUsingArray.cpp)

#### Description
Implements a Stack using an array. A stack follows **LIFO (Last In, First Out)**: the most recently inserted element is removed first. The `top` variable tracks the top element.

#### Algorithm
1. Initialize `top = -1`.
2. **Push:** If the stack is full, report overflow; otherwise increment `top` and store the value.
3. **Pop:** If `top == -1`, report underflow; otherwise return/remove the top value and decrement `top`.
4. **Peek:** Read the element at `arr[top]` when the stack is not empty.
5. **Display:** Print elements from `top` down to index `0`.

#### Complexity
- **Time Complexity:** Push, pop, and peek: `O(1)`; display: `O(N)`.
- **Space Complexity:** `O(K)`, where `K` is the array capacity.

#### Test Cases
- **Operations:** Push `10`, push `20`, pop.
- **Output:** Removed element: `20`; remaining stack: `10`

---

## 4. Stack Using Linked List

---

### [stackUsingLL.cpp](stackUsingLL.cpp)

#### Description
Implements a dynamically sized Stack using a linked list. The head pointer represents the top of the stack, so push and pop operations can be performed without shifting elements.

#### Algorithm
1. Maintain a pointer `top`, initially `nullptr`.
2. **Push:** Create a node, link it to the current top, and update `top`.
3. **Pop:** If the stack is empty, report underflow; otherwise remove the top node and move `top` to the next node.
4. **Peek:** Read the data stored at `top`.
5. **Display:** Traverse from `top` to `nullptr`.

#### Complexity
- **Time Complexity:** Push, pop, and peek: `O(1)`; display: `O(N)`.
- **Space Complexity:** `O(N)` for the nodes currently in the stack.

#### Test Cases
- **Operations:** Push `100`, push `200`, pop.
- **Output:** Removed element: `200`; top element: `100`

---

## 5. Queue Using Array

---

### [queueUsingArray.cpp](queueUsingArray.cpp)

#### Description
Implements a linear Queue using an array. A queue follows **FIFO (First In, First Out)**: the earliest inserted element is removed first. A simple linear implementation may shift elements during dequeue or may track `front` and `rear` indices.

#### Algorithm
1. Initialize the queue as empty.
2. **Enqueue:** Check capacity, then insert the new element at the rear.
3. **Dequeue:** If empty, report underflow; otherwise remove the front element. In a shifting implementation, move remaining elements one position left.
4. **Front:** Return the element at the front index.
5. **Display:** Print elements in queue order.

#### Complexity
- **Time Complexity:** Enqueue: `O(1)` in a rear-index implementation; dequeue: `O(N)` if elements are shifted (`O(1)` if only the front index advances); display: `O(N)`.
- **Space Complexity:** `O(K)`, where `K` is the array capacity.

#### Test Cases
- **Operations:** Enqueue `10`, enqueue `20`, dequeue.
- **Output:** Removed element: `10`; remaining queue: `20`

---

## 6. Circular Queue Using Array

---

### [CircularQueueUsingArray.cpp](CircularQueueUsingArray.cpp)

#### Description
Implements a Circular Queue using an array. The last array position wraps around to the first position, allowing freed slots to be reused without shifting elements.

#### Algorithm
1. Track `front` and `rear`; use a defined empty-state representation such as `front = rear = -1`.
2. **Enqueue:** Check whether the queue is full. If empty, initialize both indices; otherwise update `rear = (rear + 1) % capacity`.
3. **Dequeue:** If empty, report underflow. If the last element is removed, reset the empty state; otherwise update `front = (front + 1) % capacity`.
4. **Display:** Traverse from `front` to `rear`, wrapping with modulo arithmetic.

#### Complexity
- **Time Complexity:** Enqueue, dequeue, and front: `O(1)`; display: `O(N)`.
- **Space Complexity:** `O(K)` for an array of capacity `K`.

#### Test Cases
- **Operations:** Enqueue `10`, enqueue `20`, dequeue, enqueue `30`.
- **Output:** Remaining queue: `20 30`

---

## 7. Queue Using Linked List

---

### [queueUsingLL.cpp](queueUsingLL.cpp)

#### Description
Implements a Queue using linked nodes and `front` and `rear` pointers. It can grow dynamically until memory or any explicitly configured capacity limit is reached.

#### Algorithm
1. Initialize `front = rear = nullptr`.
2. **Enqueue:** Create a node. If empty, set both pointers to it; otherwise link it after `rear` and update `rear`.
3. **Dequeue:** If empty, report underflow; otherwise remove the front node and advance `front`.
4. If the queue becomes empty after deletion, also set `rear = nullptr`.
5. **Display:** Traverse from `front` to `nullptr`.

#### Complexity
- **Time Complexity:** Enqueue and dequeue: `O(1)` when both pointers are maintained; display: `O(N)`.
- **Space Complexity:** `O(N)` for the nodes.

#### Test Cases
- **Operations:** Enqueue `5`, enqueue `15`, dequeue.
- **Output:** Removed element: `5`; remaining queue: `15`

---

## 8. Merge Sort

---

### [MergeSort.cpp](MergeSort.cpp)

#### Description
Implements Merge Sort, a stable divide-and-conquer sorting algorithm. It divides the array into smaller halves, sorts them recursively, and merges the sorted halves.

#### Algorithm
1. Find the midpoint of the current range.
2. Recursively sort the left half and right half.
3. Compare the first unmerged element of each half and copy the smaller one into a temporary array.
4. Copy any remaining elements from either half.
5. Copy the merged result back to the original range.

#### Complexity
- **Time Complexity:** Best, average, and worst case: `O(N log N)`.
- **Space Complexity:** `O(N)` auxiliary storage, plus `O(log N)` recursion depth.

#### Test Cases
- **Test Case 1:**
  - **Input:** `5 2 3 1 4`
- **Output:** `1 2 3 4 5`

---

## 9. Quick Sort

---

### [QuickSort.cpp](QuickSort.cpp)

#### Description
Implements Quick Sort using partitioning. A pivot is selected, elements are rearranged around it, and the resulting subarrays are sorted recursively.

#### Algorithm
1. Select a pivot from the current array range.
2. Partition the range so that elements on one side are smaller than or equal to the pivot and elements on the other side are larger, according to the chosen partition scheme.
3. Place the pivot in its final position.
4. Recursively sort the left and right partitions.

#### Complexity
- **Time Complexity:**
  - Best/average: `O(N log N)`
  - Worst: `O(N^2)` when partitions are repeatedly very unbalanced
- **Space Complexity:** Average `O(log N)` recursion stack; worst-case `O(N)`.

#### Test Cases
- **Test Case 1:**
  - **Input:** `10 7 8 9 1 5`
- **Output:** `1 5 7 8 9 10`

---

## 10. Radix Sort

---

### [RadixSort.cpp](RadixSort.cpp)

#### Description
Implements Least Significant Digit (LSD) Radix Sort for non-negative integers. It sorts values digit by digit, beginning with the units place and moving to tens, hundreds, and higher places.

#### Algorithm
1. Find the maximum value to determine the number of digit positions.
2. Apply a **stable** sort, commonly Counting Sort, to the units digit.
3. Repeat for tens, hundreds, and each remaining digit position.
4. Stop when all digit positions have been processed.

#### Complexity
- **Time Complexity:** `O(d(N + b))`, where `d` is the number of digits and `b` is the digit base (10 for decimal).
- **Space Complexity:** `O(N + b)` for the output and counting arrays.
- **Note:** This standard LSD version assumes non-negative integers unless signed-number handling is added.

#### Test Cases
- **Test Case 1:**
  - **Input:** `170 45 75 90 802 24 2 66`
- **Output:** `2 24 45 66 75 90 170 802`

---

## 11. Heap Sort

---

### [heapSort.cpp](heapSort.cpp)

#### Description
Implements Heap Sort using a binary max-heap. The largest element is kept at the root; it is swapped with the last unsorted element, and the reduced heap is restored.

#### Algorithm
1. Build a max-heap from the input array.
2. Swap the root (maximum value) with the last element in the heap.
3. Reduce the heap size by one.
4. Apply max-heapify to restore the max-heap property.
5. Repeat until the heap contains one element.

#### Complexity
- **Time Complexity:** Best, average, and worst case: `O(N log N)`; building the heap takes `O(N)`.
- **Space Complexity:** `O(1)` auxiliary array space for iterative heapify; recursive heapify may use up to `O(log N)` call-stack space.

#### Test Cases
- **Test Case 1:**
  - **Input:** `12 11 13 5 6 7`
- **Output:** `5 6 7 11 12 13`

---

## 12. Bucket Sort

---

### [BucketSort.cpp](BucketSort.cpp)

#### Description
Implements Bucket Sort by distributing values into separate buckets, sorting each bucket, and combining the buckets in order. Performance depends on the distribution of input values and the bucket-index mapping used.

#### Algorithm
1. Determine the range of input values and choose the number of buckets.
2. Map each input value to an appropriate bucket.
3. Sort each bucket independently.
4. Concatenate the buckets in order to reconstruct the sorted array.

#### Complexity
- **Time Complexity:** Often close to `O(N + K)` for suitably distributed data and an appropriate bucket sort; can degrade to `O(N^2)` if a simple per-bucket sorting method is used and many elements land in one bucket.
- **Space Complexity:** `O(N + K)`, where `K` is the number of buckets.

#### Test Cases
- **Test Case 1:**
  - **Input:** `30 40 10 80 5 12 70`
- **Output:** `5 10 12 30 40 70 80`

---

## 13. K Smallest Elements (Partitioning)

---

### [kSmallestElements.cpp](kSmallestElements.cpp)

#### Description
Finds the `k` smallest elements using a partition-based selection technique such as Quickselect. Unlike a complete sort, Quickselect focuses only on the partition containing the target position. The exact output order depends on the implementation; the selected elements may need an additional sort if sorted output is required.

#### Algorithm
1. Validate that `k` is within the allowed range.
2. Choose a pivot and partition the array around it.
3. Let `p` be the pivot's final index.
4. If `p` is `k - 1`, the first `k` positions contain the `k` smallest elements.
5. If `p` is greater than `k - 1`, repeat on the left partition; otherwise repeat on the right partition.
6. Optionally sort the first `k` elements if ascending output is required.

#### Complexity
- **Time Complexity:** Expected/average `O(N)` for Quickselect; worst case `O(N^2)` with consistently poor pivots. Sorting the selected `k` elements adds `O(k log k)`.
- **Space Complexity:** `O(1)` auxiliary space for an iterative in-place partition, excluding recursion stack if recursion is used.

#### Test Cases
- **Test Case 1:**
  - **Input:** Array `7 10 4 3 20 15`, `k = 3`
- **Output (three smallest values, sorted for display):** `3 4 7`

---

## 14. Bin Sort

---

### [binSort.cpp](binSort.cpp)

#### Description
Implements Bin Sort for integer keys by counting how many times each value occurs, then rebuilding the array in ascending order. This frequency-array version is suitable when the key range is manageable and values are non-negative.

#### Algorithm
1. Find the maximum value `M` in the array.
2. Create a frequency array of size `M + 1`, initialized to zero.
3. For every value `x`, increment `frequency[x]`.
4. Traverse the frequency array from `0` through `M` and write each value back as many times as its frequency indicates.

#### Complexity
- **Time Complexity:** `O(N + M)`, where `N` is the number of values and `M` is the maximum value.
- **Space Complexity:** `O(M)` for the frequency array.
- **Note:** Negative values require an adjusted indexing strategy.

#### Test Cases
- **Test Case 1:**
  - **Input:** `3 2 10 5 4 7 8 9 1 6`
- **Output:** `1 2 3 4 5 6 7 8 9 10`

---

## 15. Tower of Hanoi

---

### [towerOfHanoi.cpp](towerOfHanoi.cpp)

#### Description
Solves the Tower of Hanoi puzzle recursively. The goal is to move all disks from a source rod to a destination rod using an auxiliary rod, never placing a larger disk on a smaller one.

#### Algorithm
1. **Base case:** If there is one disk, move it directly from source to destination.
2. Recursively move `n - 1` disks from source to auxiliary, using destination as temporary storage.
3. Move the largest remaining disk from source to destination.
4. Recursively move the `n - 1` disks from auxiliary to destination, using source as temporary storage.

#### Complexity
- **Time Complexity:** `O(2^N)` moves; the minimum number of moves is `2^N - 1`.
- **Space Complexity:** `O(N)` recursion stack depth.

#### Test Cases
- **Test Case 1:**
  - **Input:** `n = 2`, source `A`, auxiliary `B`, destination `C`
- **Output:**
  ```text
  Move disk 1 from A to B
  Move disk 2 from A to C
  Move disk 1 from B to C
  ```

---

## 16. Binary Trees

---

### [BT.cpp](BT.cpp)

#### Description
Implements a Binary Tree, in which each node can have at most two children: a left child and a right child. A general binary tree does not require its values to follow a sorting order. Common operations include creation, insertion, deletion, and tree traversals.

#### Algorithm
1. Define a node with `data`, `left`, and `right` pointers.
2. Create or insert nodes according to the implementation's chosen method (recursive creation or level-order insertion).
3. Perform traversals:
   - **Inorder:** Left → Root → Right
   - **Preorder:** Root → Left → Right
   - **Postorder:** Left → Right → Root
4. For level-order operations, use a queue to visit nodes breadth-first.
5. If deleting by deepest-node replacement, locate the target and deepest rightmost node, copy the deepest node's value to the target, then remove the deepest node.

#### Complexity
- **Time Complexity:** Traversal: `O(N)`; search and level-order insertion/deletion: generally `O(N)`.
- **Space Complexity:** `O(N)` in the worst case for a traversal queue or stored nodes; recursive traversal uses `O(H)` call-stack space.

#### Test Cases
For a tree with root `1`, left child `2`, and right child `3`:
- **Inorder:** `2 1 3`
- **Preorder:** `1 2 3`
- **Postorder:** `2 3 1`

---

## 17. Binary Search Tree

---

### [BST.cpp](BST.cpp)

#### Description
Implements a Binary Search Tree (BST), where values smaller than a node are placed in its left subtree and values larger than a node are placed in its right subtree. This ordering supports efficient search, insertion, and deletion when the tree is reasonably balanced.

#### Algorithm
1. **Search:** Compare the target with the current node; move left if smaller and right if larger.
2. **Insert:** Follow the same comparisons until an appropriate empty child position is found.
3. **Delete:** Handle one of three cases:
   - Leaf node: remove it directly.
   - One child: link the parent to the node's child.
   - Two children: replace the node's value with its inorder successor or predecessor, then remove that replacement node.
4. **Inorder traversal:** Visit left subtree, root, then right subtree to print values in ascending order.

#### Complexity
- **Time Complexity:** Search/insert/delete average `O(log N)`; worst case `O(N)` for a skewed tree. Traversal: `O(N)`.
- **Space Complexity:** `O(H)` recursion stack, where `H` is tree height.

#### Test Cases
- **Test Case 1:**
  - **Input:** Insert `50 30 70 20 40`
- **Output (inorder):** `20 30 40 50 70`

---

## 18. AVL Trees

---

### [AVLtrees.cpp](AVLtrees.cpp)

#### Description
Implements or demonstrates an AVL Tree, a self-balancing Binary Search Tree. For each node, the height difference between the left and right subtrees (balance factor) must remain between `-1` and `1`.

#### Algorithm
1. Insert a key using standard BST insertion.
2. Update the height of each ancestor node.
3. Calculate the balance factor: `height(left) - height(right)`.
4. If a node becomes unbalanced, restore balance using one of four cases:
   - **LL:** Right rotation
   - **RR:** Left rotation
   - **LR:** Left rotation on the left child, then right rotation
   - **RL:** Right rotation on the right child, then left rotation
5. Return the updated subtree root after rotation.

#### Complexity
- **Time Complexity:** Search, insertion, and deletion are `O(log N)` in a properly maintained AVL tree; each individual rotation takes `O(1)`.
- **Space Complexity:** `O(log N)` recursion stack for recursive operations.

#### Test Cases
- **Test Case 1:**
  - **Input:** Insert `30 20 10` (LL imbalance)
- **Expected balanced root:** `20`, with left child `10` and right child `30`.

---

## 19. Parentheses Matching

---

### [ParenthesesMatching.cpp](ParenthesesMatching.cpp)

#### Description
Checks whether brackets in an expression are balanced and correctly nested. A stack is suitable because the most recently opened bracket must be the first one closed. Common bracket pairs are `()`, `[]`, and `{}`.

#### Algorithm
1. Initialize an empty stack.
2. Scan the expression from left to right.
3. When an opening bracket `(`, `[` or `{` is found, push it onto the stack.
4. When a closing bracket `)`, `]` or `}` is found:
   - If the stack is empty, the expression is unbalanced.
   - Otherwise, pop the top opening bracket and verify that it matches the closing bracket.
5. After scanning the expression, it is balanced only if no mismatch occurred and the stack is empty.

#### Complexity
- **Time Complexity:** `O(N)`, where `N` is the expression length.
- **Space Complexity:** `O(N)` in the worst case when all characters are opening brackets.

#### Test Casess
- **Test Case 1:**
  - **Input:** `{[()]}`
  - **Output:** `Balanced`
- **Test Case 2:**
  - **Input:** `([)]`
  - **Output:** `Not balanced`

---

## How to Compile and Run

For a single C++ source file, compile with a C++ compiler such as `g++`:

```bash
g++ filename.cpp -o program
./program
```

On Windows PowerShell, the run command may be:

```powershell
g++ filename.cpp -o program.exe
.\program.exe
```

Replace `filename.cpp` with the actual source filename. Check that each filename and sample input/output matches the implementation in your repository before submitting.
