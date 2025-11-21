#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void inputset(int set[]);
void displaySet(int set[]);
void setUnion(int set1[], int set2[], int result[]);
void setIntersection(int set1[],int set2[] ,int result[]);
void setDifference(int set1[],int set2[] ,int result[]);

int main(){
    int set1[SIZE]= {0}, set2[SIZE]= {0},result[SIZE]={0};
    int choice;
    printf("enter elements(set1):\n");inputset(set1);
    printf("enter elements(set2):\n");inputset(set2);
    while(1){
        printf("1. Display sets\n");
        printf("2. Union\n");
        printf("3. Intersection\n");
        printf("4. Difference\n");
        printf("5.Exit\n");
        printf("Enter your Choice:");
        scanf("%d",&choice);

        switch (choice){
            case1:
            printf("set1=");
            displayset(set1);
            printf("set2=");
            displayset(set2);
            break;

            case2:
            setUnion(set1,set2,result);
            printf("Union :");
            displayset(result);
            break;

            case3:
            setIntersection(set1,set2,result);
            printf("Intersection:");
            displayset(result);
            break;

            case4:
            setDifference(set1,set2,result);
            printf("Difference:");
            displayset(result);
            break;

            case5:
            exit(0);
            default:
            printf("Invalid choice! try again.\n");
        }
    }
    return 0;
}

void inputset(int set[]){
    int n, element;
    printf("how many elements?");
    scanf("%d", &n);
    printf("Enter elements(0to %d):",SIZE - 1);
    for (int i = 0; i<n;i++){
        scanf("%d", &element);
        if (element>=0 && element < SIZE)
        {set [element]=1;}else{printf ("Invalid Element!! %d\n", element);}
    }
}

void displayset(int set[])
{
    printf("{");
    for (int i=0; i< SIZE; i++){
        if (set[i]==1)
        printf("%d",i);
    }printf("}\n");
}

void setUnion(int set1[], int set2[], int result[]){
    for (int i=0; i< SIZE; i++)
    result[i]=set1[i] | set2[i];
}

void setIntersection(int set1[], int set2[],int result[]){
    for (int i=0; i< SIZE; i++)
    result[i]=set1[i] & set2[i];
}

void setDifference(int set1[],int set2[], int result[]){
    for (int i=0; i< SIZE; i++)
    result[i]=set1[i] & (!set2[i]);
}
