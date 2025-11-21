#include <stdio.h>
#define MAX 10

int parent[MAX], rank[MAX];

void Create() {
    for (int i = 0; i < MAX; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

void unionMultiple(int n) {
    if (n < 2) {
        printf("Need at least 2 elements!\n");
        return;
    }
    int first, elem;
    printf("Enter %d elements (0 to %d): ", n, MAX - 1);
    scanf("%d", &first);
    for (int i = 1; i < n; i++) {
        scanf("%d", &elem);
        if (first >= 0 && first < MAX && elem >= 0 && elem < MAX)
            unionSet(first, elem);
        else
            printf("Invalid element %d ignored.\n", elem);
    }
    printf("All %d elements merged into a set.\n", n);
}

void checkConnected(int x, int y) {
    if (find(x) == find(y))
        printf("%d and %d are in the same set.\n", x, y);
    else
        printf("%d and %d are in different sets.\n", x, y);
}

int main() {
    int choice, x, y, n;
    Create();
    while (1) {
        printf("\nMenu:\n");
        printf("1. Union (multiple elements)\n");
        printf("2. Check connection\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many elements do you want to union (>=2)? ");
                scanf("%d", &n);
                unionMultiple(n);
                break;

            case 2:
                printf("Enter two elements (0 to %d): ", MAX - 1);
                scanf("%d %d", &x, &y);
                if (x >= 0 && x < MAX && y >= 0 && y < MAX)
                    checkConnected(x, y);
                else
                    printf("Invalid input! Try again.\n");
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
