
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node **head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Błąd: Brak pamięci!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

int pop(struct Node **head) {
    if (*head == NULL) {
        printf("Lista jest pusta, nie można usunąć elementu.\n");
        return -1;
    }

    struct Node *temp = *head;
    int value = temp->data;
    *head = (*head)->next;
    free(temp);
    return value;
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

    push(&head, 3);
    push(&head, 5);
    push(&head, 7);

    printf("Lista przed usunięciem pierwszego elementu: ");
    displayList(head);

    int deletedValue = pop(&head);
    printf("Usunięto pierwszy element o wartości: %d\n", deletedValue);

    printf("Lista po usunięciu pierwszego elementu: ");
    displayList(head);

    deleteList(&head);

    return 0;
}
