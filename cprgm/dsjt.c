#include<stdio.h>
#define MAX 10
int parent [MAX], int rank [MAX]
void create(){
    for (int i=0; i<MAX; i++){
        parent[i]= i;
        rank[i]=0;
    }
}
int find(int x){
    if (parent[x]!=x)
    parent[x]= find(parent[x]);
    return parent[x];
}
void Union(int x,int y){
    int rootX= find(root(X));
    int rootY= find(root(Y));
    if(rootX!=rootY){
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        printf("Union AUB : %d & %d\n", x, y);
    } else {
        printf("%d & %d are already in the same set.\n", x, y);
    }
}
