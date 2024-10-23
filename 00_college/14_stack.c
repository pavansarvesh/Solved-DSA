#include <stdio.h>
#define Array_size 5
int stack[Array_size];
int top = -1;


void push(int x){
    stack[++top] = x;
    printf("%d Pushed!\n",x);
}
void pop(){
    printf("%d popped",stack[top--]);
}
void display(){
    for(int i = 0; i<top;i++){
        if(stack[i])
            printf("%d  ",stack[i]);
    }
    printf("\n");
}

void main(){
    int choice,value;
    while(1){
        printf("Enter Choice : ");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter Value : ");
            scanf("%d",&value);
            push(value);
        }else if (choice == 2){
            pop();
        }
        else if (choice == 3){
            display();
        }
        else if (choice == 4){
            return;
        }
    }
}