# Rubik's Cube Solver Project

![3D Rubik's Cube](https://espresso.codeforces.com/81468de2d38e27a371abfa76db5ecd8938d6437a.png)

## Overview

This project is a comprehensive exploration of solving the Rubik's Cube puzzle through the creation of a computer program. We've successfully built a Rubik's Cube solver by breaking down the problem into manageable components, implementing algorithms, and utilizing object-oriented programming principles.

## Key Achievements

### Model Real-World Objects

We successfully transformed the Rubik's Cube, a real-world object, into a digital representation that the computer can understand. This involved creating data structures and classes to capture the cube's state and manipulate it programmatically.

![2D Rubik's Cube](https://espresso.codeforces.com/acbbacfbb22e480bc2bdcb3e0731504ff698a3f2.png)

### Problem Decomposition

To tackle the complete Rubik's Cube solver, we divided the problem into smaller sub-problems. This approach allowed us to create basic models and controllers, such as Rubik's cube representations and solvers, which could be further extended and refined.

### Object-Oriented Programming

We applied essential concepts of object-oriented programming, including:

1. Defining classes and creating objects.
2. Using virtual functions and abstract classes to enable polymorphism.
3. Leveraging inheritance to create specialized cube representations and solvers.
4. Overloading operators for intuitive cube manipulation.

### Path Finding Algorithms

We successfully built and implemented path-finding algorithms, including BFS (Breadth-First Search), DFS (Depth-First Search), IDDFS (Iterative Deepening Depth-First Search), and IDA* (Iterative Deepening A*). These algorithms proved instrumental in solving the Rubik's Cube and have broader applications in AI.

### Heuristic Search Algorithms

We developed a deep understanding of heuristic search algorithms, such as A* and IDA*, and how to construct pattern databases to provide heuristic estimates for optimizing the Rubik's Cube solving process.

### Miscellaneous Concepts

Throughout the project, we constructed practical skills and concepts, including:

1. Understanding how `unordered_map<>` functions with custom objects.
2. Crafting custom hash functions for data structures.
3. Utilizing bit manipulation to store information efficiently.
4. Implementing file I/O for saving and loading cube states.
5. Grasping the concept of "black boxing," where we define inputs and anticipate specific outputs from a black box system, as demonstrated in our Permutation Indexer.

## Project Structure

The project is structured into various components, including:

1. `RubiksCubeSolver`: The core Rubik's Cube solver that leverages the algorithms and data structures developed during the project.
2. `PatternDatabases`: A module for constructing and managing pattern databases used in heuristic searches.
3. `Algorithms`: Implementation of path-finding algorithms, including BFS, DFS, IDDFS, and IDA*.
4. `Utilities`: Utility functions for custom data types, file I/O, and more.

## Getting Started

To utilize or contribute to this project, follow these steps:

1. Clone the repository to your local machine.
2. Explore the project's structure and the specific components.
3. Study the source code and documentation to grasp the implementation details.
4. Experiment with solving the Rubik's Cube using the provided solver and algorithms.
