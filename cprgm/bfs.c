#include<stdio.h>
#define MAX 100

int queue[MAX],front=-1, rear=-1;
int visited[MAX], adj[MAX][MAX],n;

void enqueue(int v){
    if(rear==MAX-1) return;
    if(front==-1)front=0;
    queue[++rear]=v;
}
int dequeue(){
    if(front==-1|| front>rear)
    return -1;
    return queue[front++];
}

void BFS(int start){
    int i,v;
    enqueue(start);
    visited[start]=1;
    printf("Breadth first search traversal:/n "); 
    while(front<=rear){
        v=dequeue();
        printf("%d",v);
        for(i=0;i<n;i++){
            if(adj[v][i]&&!visited[i]){
                enqueue(i);
                visited[i]=1;
            }
        }
    }
}
int main(){
    int i,j,start;
    printf("enter number of vertices:");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&adj[i][j]);
    printf("enter start vertex: ");
    scanf("%d",&start);
    BFS(start);
    return 0;
}