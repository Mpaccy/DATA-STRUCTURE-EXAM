============================================
SIMPLE GRAPH REPRESENTATION PROJECT – README
============================================

Project Title: Simple Graph Representation using C++

---

## ASSIGNED TASK DESCRIPTION

Each student was required to individually select a unique programming project. For this task, I was assigned to implement a basic Graph Representation System in C++.

The objective of the project was to:

* Represent a graph using adjacency lists stored in arrays or dynamic structures
* Allow interaction through a menu interface
* Support both directed and undirected graphs
* Implement basic operations such as adding/removing vertices, adding edges, and displaying the graph
* Use beginner-friendly C++ code with clear structure and comments
* Create a README file explaining the code
* Include screenshots of the program output

---

## HOW THE PROJECT WAS COMPLETED

1. I created a simple program in C++ using only basic constructs (arrays, structs, loops, functions).
2. I defined two data structures: Vertex and Edge.

   * Each vertex stores an ID and a list of connected edges.
   * Each edge stores the ID of the destination vertex and a weight.
3. I created a Graph structure that contains an array of vertices and a flag to determine whether it is directed or undirected.
4. I implemented the following functions:

   * initGraph: Initialize the graph
   * addVertex: Add a new vertex
   * addEdge: Add a new edge with a weight between two vertices
   * removeVertex: Remove a vertex and all connected edges
   * displayGraph: Display all vertices and their connections
5. I added a user-friendly main menu that allows the user to perform all operations interactively.

All code lines include comments explaining what they do to help other beginners understand the logic.

---

## PROJECT FEATURES

✔ Supports both directed and undirected graphs
✔ Menu-driven interface
✔ Input-based graph construction (no hardcoded values)
✔ Beginner-friendly code (no advanced OOP, no modern C++ features)
✔ Clean output formatting using simple console printing
✔ Easily extendable for future enhancements (like deleting edges)

---

## CODE DOCUMENTATION

All code is properly commented, with every function and major logic section explained in simple English. This includes:

* What each variable and structure is used for
* Step-by-step logic of adding/removing vertices and edges
* How the graph is stored and displayed
* Why specific implementation choices were made (e.g., arrays instead of pointers)

---

SCREENSHOTS OF OUTPUT

Screenshots showing the following program behaviors have been manually attached with this submission:

1. Adding Vertices
2. Adding Edges
3. Displaying the Graph
4. Removing a Vertex

---

COMPLETION CHECKLIST

Task selected and implemented individually
README file created explaining the task and solution
Code fully annotated with comments
Program works correctly with multiple test inputs
