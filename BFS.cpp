#include <stdio.h>
#include <stdlib.h>

int source_node, Vertex, Edge, visited[10], Graph[10][10];

void BreadthFirstSearch(int start) {
    int queue[10], front = 0, rear = -1;
    int i, node;
    
    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        node = queue[front++];
        printf(" %d->", node + 1);

        for (i = 0; i < Vertex; i++) {
            if (Graph[node][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, v1, v2;

    printf("\t\t\tBreadth_First_Search\n");
    printf("Enter the number of edges: ");
    scanf("%d", &Edge);
    printf("Enter the number of vertices: ");
    scanf("%d", &Vertex);

    for (i = 0; i < Vertex; i++) {
        for (j = 0; j < Vertex; j++) {
            Graph[i][j] = 0;
        }
    }

    for (i = 0; i < Edge; i++) {
        printf("Enter the edges (V1 V2): ");
        scanf("%d%d", &v1, &v2);
        Graph[v1 - 1][v2 - 1] = 1;
    }

    for (i = 0; i < Vertex; i++) {
        for (j = 0; j < Vertex; j++) {
            printf(" %d ", Graph[i][j]);
        }
        printf("\n");
    }

    printf("Enter the source: ");
    scanf("%d", &source_node);

    for (i = 0; i < Vertex; i++) {
        visited[i] = 0;
    }

    BreadthFirstSearch(source_node - 1);

    return 0;
}
