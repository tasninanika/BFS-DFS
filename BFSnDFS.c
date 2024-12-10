#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

char values[SIZE]; // Stores the values of nodes as characters.
int adjMatrix[SIZE][SIZE];
int status[SIZE];
int queue[SIZE];
int front = -1, rear = -1;
int stack[SIZE];
int top = -1;
int numNodes;

void insert() {
    int i;
    for (i = 0; i < numNodes; i++) {
        printf(" Enter value of Node %d: ", i + 1);
        scanf(" %c", &values[i]);
    }
}

void create() {
    int i, j;
    printf(" How many nodes?: ");
    scanf("%d", &numNodes);

    insert();

    printf(" Enter the adjacency matrix:\n");
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
        status[i] = 1; // Initialize all nodes to the ready state.
    }
}

void qinsert(int node) {
    if (rear == SIZE - 1)
        printf(" Overflow\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = node;
    }
}

int qdelete() {
    int node;
    if (front == -1 || front > rear) {
        printf(" Underflow\n");
        return -1;
    }
    else {
        node = queue[front];
        front++;
        return node;
    }
}

void BFS(int startNode) {
    printf(" BFS Traversal: ");
    qinsert(startNode);
    status[startNode] = 2; // Mark the starting node as waiting.

    while (front != -1 && front <= rear) {
        int currentNode =  qdelete();
        printf("%c ", values[currentNode]);
        status[currentNode] = 3; // Mark the current node as processed.

        for (int i = 0; i < numNodes; i++) {
            if (adjMatrix[currentNode][i] == 1 && status[i] == 1) {
                qinsert(i);
                status[i] = 2; // Mark the neighbor as waiting.
            }
        }
    }
    printf("\n");
}

void push(int node) {
    if (top == SIZE - 1)
        printf(" Overflow\n");
    else {
        top++;
        stack[top] = node;
    }
}

int pop() {
    if (top == -1) {
        printf(" Underflow\n");
        return -1;
    } else {
        int node = stack[top];
        top--;
        return node;
    }
}

void DFS(int startNode) {
    // Reinitialize the status array before starting a new DFS traversal.
    for (int i = 0; i < numNodes; i++) {
        status[i] = 1; // Mark all nodes as ready.
    }

    printf(" DFS Traversal: ");
    push(startNode);
    status[startNode] = 2; // Mark the starting node as waiting.
    printf("%c ", values[startNode]); // Print the starting node.

    while (top != -1) {
        int currentNode = stack[top]; // Peek the top of the stack.
        bool foundUnvisitedNeighbor = false;

        for (int i = 0; i < numNodes; i++) {
            if (adjMatrix[currentNode][i] == 1 && status[i] == 1) {
                push(i);
                status[i] = 2; // Mark the neighbor as waiting.
                printf("%c ", values[i]); // Print the neighbor before exploring its neighbors.
                foundUnvisitedNeighbor = true;
                break; // Break the loop after pushing the first unvisited neighbor.
            }
        }

        if (!foundUnvisitedNeighbor) {
            // If no unvisited neighbor is found, mark the current node as processed and pop it from the stack.
            status[currentNode] = 3; // Mark the current node as processed.
            pop();
        }
    }
    printf("\n");
}

int main() {
    int choice, startNode;
    while (1) {
        printf("\n Menu:\n");
        printf(" 1. Create Graph\n");
        printf(" 2. BFS Traversal\n");
        printf(" 3. DFS Traversal\n");
        printf(" 4. Exit\n");
        printf(" Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            create();
            break;
        case 2:
            printf(" Enter the root node: ");
            scanf("%d", &startNode);
            BFS(startNode);
            break;
        case 3:
            printf(" Enter the root node:  ");
            scanf("%d", &startNode);
            DFS(startNode);
            break;
        case 4:
            printf(" Exiting...\n");
            return 0;
        default:
            printf(" Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
