# 🌳 Event-Tree

<p align="center">
  <strong>A Binary Search Tree based Event Management System</strong>
</p>

<p align="center">
  An educational C++ project focused on understanding and applying Tree Data Structures through a practical event-management scenario.
</p>

<p align="center">

![C++](https://img.shields.io/badge/C%2B%2B-11%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

![Data Structure](https://img.shields.io/badge/Data%20Structure-Binary%20Search%20Tree-6A5ACD?style=for-the-badge)

![Project Type](https://img.shields.io/badge/Project-Educational-2EA44F?style=for-the-badge)

![Status](https://img.shields.io/badge/Status-In%20Development-orange?style=for-the-badge)

</p>

---

## 📖 About

**Event-Tree** is an educational **C++ project** designed to demonstrate the implementation and practical usage of a **Binary Search Tree (BST)**.

Instead of treating a tree as only an abstract data structure, this project uses a real-world concept — **events organized by timestamp** — to demonstrate how tree-based structures can be used for:

- Event insertion
- Event deletion
- Timestamp-based searching
- Chronological traversal
- Time-range queries
- Finding the closest event
- Category analysis
- Tree statistics
- Comparison counting

The project is primarily focused on learning **Data Structures, Algorithms, Recursion, Pointers, and Complexity Analysis**.

---

## 🎯 Project Goals

The main educational goals of this project are:

- Understand how a Binary Search Tree works internally.
- Practice implementing tree operations from scratch.
- Understand recursive algorithms.
- Work with dynamically allocated nodes.
- Analyze the time complexity of tree operations.
- Apply a data structure to a practical problem.
- Experiment with different tree shapes and their performance.
- Understand how tree structure affects algorithm efficiency.

---

## 🧩 How It Works

Each event contains a timestamp, and the timestamp is used as the **ordering key** of the Binary Search Tree.

```mermaid
flowchart TD
    A[Event] --> B[Timestamp]
    B --> C{Compare with Current Node}

    C -->|Smaller| D[Left Subtree]
    C -->|Greater or Equal| E[Right Subtree]

    D --> F[Continue Searching]
    E --> F