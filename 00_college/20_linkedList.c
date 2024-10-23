#include <stdio.h>
#include <conio.h>

typedef struct node {
    int data;
    struct node*next;
}node;

node n1,n2;
node *one,*temp;

int main(){
    n1.data = 20;
    n1.next = &n2;
    n2.data = 30;
    n2.next = NULL;
    one = &n1;
    temp = one;
    while(temp!=NULL)
    {

        printf("\n %d",temp -> data);
        temp = temp -> next;
    }
    getchar();


}
