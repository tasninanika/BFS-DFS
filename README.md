### Algorithm for the Given Graph Traversal Program

#### **1. Create a Graph:**
- **Input:** Number of nodes in the graph, their values, and adjacency matrix.
- **Steps:**
  1. Prompt the user to input the number of nodes (`numNodes`).
  2. For each node, store its value in the `values` array.
  3. Prompt the user to enter the adjacency matrix and populate `adjMatrix`.
  4. Initialize the `status` array with `1` (ready state) for all nodes.
- **Output:** Graph represented by `values`, `adjMatrix`, and `status`.

#### **2. Breadth-First Search (BFS):**
- **Input:** Starting node (`startNode`).
- **Steps:**
  1. Insert `startNode` into the queue and mark it as "waiting" (`status = 2`).
  2. While the queue is not empty:
     - Dequeue a node (`currentNode`), print its value, and mark it as "processed" (`status = 3`).
     - For all neighbors of `currentNode`:
       - If a neighbor is connected (`adjMatrix[currentNode][i] == 1`) and in the "ready" state (`status[i] == 1`):
         - Enqueue the neighbor and mark it as "waiting" (`status = 2`).
- **Output:** BFS traversal order printed.

#### **3. Depth-First Search (DFS):**
- **Input:** Starting node (`startNode`).
- **Steps:**
  1. Reinitialize `status` to `1` (ready state) for all nodes.
  2. Push `startNode` onto the stack, print its value, and mark it as "waiting" (`status = 2`).
  3. While the stack is not empty:
     - Peek the top node of the stack (`currentNode`).
     - Check for unvisited neighbors:
       - If a neighbor is connected (`adjMatrix[currentNode][i] == 1`) and in the "ready" state (`status[i] == 1`):
         - Push the neighbor onto the stack, print its value, and mark it as "waiting" (`status = 2`).
         - Break the loop to explore this neighbor.
     - If no unvisited neighbors are found:
       - Mark `currentNode` as "processed" (`status = 3`) and pop it from the stack.
- **Output:** DFS traversal order printed.

#### **4. Menu-Driven Program:**
- **Steps:**
  1. Display the menu with the following options:
     - Create Graph
     - BFS Traversal
     - DFS Traversal
     - Exit
  2. Based on the user's choice:
     - Option 1: Call `create()` to construct the graph.
     - Option 2: Prompt the user for the root node and call `BFS(startNode)`.
     - Option 3: Prompt the user for the root node and call `DFS(startNode)`.
     - Option 4: Exit the program.
     - For invalid choices, display an error message and re-display the menu.
  3. Repeat until the user chooses to exit.

#### **Additional Notes:**
- **Status Array Values:**
  - `1` → Ready
  - `2` → Waiting
  - `3` → Processed
- **Queue and Stack:** Used to manage BFS and DFS traversals, respectively.
- **Input Validation:** Ensure that the input for nodes, adjacency matrix, and traversal choices are within valid bounds.
