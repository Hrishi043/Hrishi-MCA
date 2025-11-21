#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int parent[MAX];
int cost[MAX][MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;  
        return 1;
    }
    return 0;
}

int main() {
    int i, j, n, V1, V2, u, v;
    int c = 0, mincost = 0;
    int edgecount = 1;  

    printf("Enter the total number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 9999;  
            }
    for (i = 1; i <= n; i++)
        parent[i] = i;  

    while (edgecount < n) {
        c = 9999;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < c) {
                    c = cost[i][j];
                    V1 = i;
                    V2 = j;
                }

        u = find(V1);
        v = find(V2);

        if (uni(u, v)) {
            printf("Edge %d: (%d --> %d) cost = %d\n", edgecount, V1, V2, c);
            edgecount++;
            mincost += c;
        }

        cost[V1][V2] = cost[V2][V1] = 9999;
    }

    printf("Minimum Cost = %d\n", mincost);
    return 0;
}
