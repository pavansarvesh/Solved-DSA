#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *head, *first, *temp;
int count = 0;
int choice = 1;

int main() {
    first = 0;
    while (choice) {
        head = (NODE*) malloc(sizeof(NODE));
        if (head == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter the data item: \n");
        scanf("%d", &head->data);

        head->next = NULL;

        if (first != 0) {
            temp->next = head;
            temp = head;
        } else {
            first = temp = head;
        }

        printf("Do you want to continue (0 or 1): \n");
        scanf("%d", &choice);
    }

    temp->next = 0;

    temp = first;
    printf("\nStatus of the linked list is:\n");
    while (temp != 0) {
        printf("%d => ", temp->data);
        count++;
        temp = temp->next;
    }

    printf("NULL\n");
    printf("No. of nodes in the list: %d\n", count);

    return 0;
}