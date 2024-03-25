#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtIndex(struct Node **head, int value, int index) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Błąd: Brak pamięci!\n");
        return;
    }
    newNode->data = value;

    if (index == 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    struct Node *prev = NULL;
    int currentIndex = 0;

    while (current != NULL && currentIndex < index) {
        prev = current;
        current = current->next;
        currentIndex++;
    }

    prev->next = newNode;
    newNode->next = current;
}

void displayList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteList(struct Node **head) {
    struct Node *current = *head;
    struct Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    struct Node *head = NULL;

    insertAtIndex(&head, 3, 0);
    insertAtIndex(&head, 5, 1);
    insertAtIndex(&head, 7, 2);

    printf("Lista przed dodaniem nowego elementu: ");
    displayList(head);

    insertAtIndex(&head, 10, 1);

    printf("Lista po dodaniu nowego elementu na indeksie 1: ");
    displayList(head);

    deleteList(&head);

    return 0;
}
