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

int removeLast(struct Node **head) {
    if (*head == NULL) {
        printf("Lista jest pusta, nie można usunąć elementu.\n");
        return -1;
    }

    if ((*head)->next == NULL) {
        int value = (*head)->data;
        free(*head);
        *head = NULL;
        return value;
    }

    struct Node *secondLast = *head;
    while (secondLast->next->next != NULL) {
        secondLast = secondLast->next;
    }

    int value = secondLast->next->data;

    free(secondLast->next);
    secondLast->next = NULL;

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

    printf("Lista przed usunięciem ostatniego elementu: ");
    displayList(head);

    int deletedValue = removeLast(&head);
    printf("Usunięto ostatni element o wartości: %d\n", deletedValue);

    printf("Lista po usunięciu ostatniego elementu: ");
    displayList(head);

    deleteList(&head);

    return 0;
}
