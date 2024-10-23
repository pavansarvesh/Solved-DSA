#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *concat(struct Node *head1, struct Node *head2) {
    if (head1 == NULL)
        return head2;

    struct Node *curr = head1;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = head2;
    return head1;
}
void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
struct Node *createNode(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node *head1 = createNode(2);
    head1->next = createNode(4);
    head1->next->next = createNode(6);
    head1->next->next->next = createNode(8);
    head1->next->next->next->next = createNode(10);


    struct Node *head2 = createNode(3);
    head2->next = createNode(5);
    head2->next->next = createNode(7);
    head2->next->next->next = createNode(8);
    head2->next->next->next->next = createNode(9);
    head2->next->next->next->next->next = createNode(20000);



    printf("List 1: ");
    printList(head1);


    printf("List 2: ");
    printList(head2);


    struct Node *concatHead = concat(head1, head2);


    printf("Concatenated List: ");
    printList(concatHead);

    return 0;
}