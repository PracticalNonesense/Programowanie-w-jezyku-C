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
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void removeByValue(struct Node **head, int value) {
    if (*head == NULL) {
        printf("Lista jest pusta, nie można usunąć elementu.\n");
        return;
    }

    if ((*head)->data == value) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Usunięto pierwszy element o wartości: %d\n", value);
        return;
    }

    struct Node *current = *head;
    struct Node *prev = NULL;
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        prev->next = current->next;
        free(current);
        printf("Usunięto pierwszy element o wartości: %d\n", value);
    } else {
        printf("Nie ma elementu o podanej wartości.\n");
    }
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
    push(&head, 5);

    printf("Lista przed usunięciem elementu: ");
    displayList(head);

    removeByValue(&head, 5);

    printf("Lista po usunięciu elementu: ");
    displayList(head);

    deleteList(&head);

    return 0;
}
