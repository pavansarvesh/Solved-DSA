#include <stdio.h>
# define SIZE 5
void enqueue();
void dequeue();
void displayQueue();
int queue[SIZE];
int rear = - 1;
int front = - 1;
int main()
{
    int ch;
    while (1)
    {
        printf("1.Enqueue \n");
        printf("2.Dequeue \n");
        printf("3.Display Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                return 0;
            default:
                printf("Incorrect choice \n");
        }
    }
}

void enqueue()
{
    int element;
    if (rear == SIZE - 1)
       printf("Overflow \n");
    else
    {
        if (front == - 1)
            front = 0;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &element);
        queue[++rear] = element;
    }
}

void dequeue()
{
    if (front == - 1 || front > rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", queue[front++]);
    }
}

void displayQueue()
{

    if (front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}