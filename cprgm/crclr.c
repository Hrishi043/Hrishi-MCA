#include <stdio.h>
#define SIZE 5

int cqueue[SIZE];
int front=-1,rear=-1;

void enqueue(int value){
    if((front==0 && rear==SIZE-1)||(rear==(front-1)%(SIZE-1))){
        printf("Queue Overflow! cannot Insert%d\n",value);
        return;
    }
    else if(front==-1){
        front=rear=0;
        cqueue[rear]=value;
    } else if(rear== SIZE-1&& front!=0){
        rear=0;
        cqueue[rear]=value;
    }
    else{
        rear++;
        cqueue[rear]=value;
    }
    printf("%d inserted\n",value);
}

void dequeue(){
    if(front==-1){
        printf("Queue Underflow! Cannot delete\n");
        return;
    }
    int data=cqueue[front];
    printf("%d deleted\n",data);
    if (front==rear){
        front=rear=-1;
    } else if(front==SIZE-1){
        front=0;
    }else{
        front++;
    }
}
void Display(){
    if(front==-1){
        printf("Queue is Empty!\n");
        return;
        }
        printf("Queue Elements:");
        if(rear>=front){
            for (int i=front;i<=rear;i++)
            printf("%d",cqueue[i]);
        }
        else{
            for(int i=front;i<SIZE;i++)
            printf("%d",cqueue[1]);
            for(int i=0;i<=rear;i++)
            printf("%d",cqueue[i]);
        }
        printf("\n");
}
int count(){
    if(front==-1)return 0;
    if(rear>=front)return(rear-front+1);
    return(SIZE-front+rear+1);
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    Display();
    printf("count=%d\n",count());

    dequeue();
    dequeue();
    Display();
    printf("count=%d\n",count());

    enqueue(60);
    enqueue(70);
    printf("count=%d\n",count());

    return 0;
}

