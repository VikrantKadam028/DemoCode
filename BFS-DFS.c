#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = -1;

/* BFS Function */
void bfs(int start, int n) {
    int i;
    
    for(i = 0; i < n; i++)
        visited[i] = 0;

    front = 0;
    rear = -1;

    visited[start] = 1;
    queue[++rear] = start;

    while(front <= rear) {
        int v = queue[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++) {
            if(graph[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

/* DFS Function */
void dfs(int v, int n) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for(i = 0; i < n; i++) {
        if(graph[v][i] == 1 && visited[i] == 0) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, start, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nBFS Traversal: ");
    bfs(start, n);

    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    dfs(start, n);

    return 0;
}

