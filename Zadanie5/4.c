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

int removeByIndex(struct Node **head, int index) {
    if (*head == NULL) {
        printf("Lista jest pusta, nie można usunąć elementu.\n");
        return -1;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (index == 0) {
        *head = temp->next;
        int value = temp->data;
        free(temp);
        return value;
    }

    for (int i = 0; temp != NULL && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Nie ma elementu o podanym indeksie.\n");
        return -1;
    }

    prev->next = temp->next;
    int value = temp->data;
    free(temp);
    return value;
}

void removeByValue(struct Node **head, int value) {
    struct Node *temp = *head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {

        if (prev == NULL) {
            *head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        printf("Usunięto element o wartości: %d\n", value);
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

    printf("Lista przed usunięciem elementu: ");
    displayList(head);

    int deletedIndex = 1;
    int deletedValue = removeByIndex(&head, deletedIndex);
    if (deletedValue != -1) {
        printf("Usunięto element o indeksie %d o wartości: %d\n", deletedIndex, deletedValue);
    }

    printf("Lista po usunięciu elementu: ");
    displayList(head);

    removeByValue(&head, 5);

    printf("Lista po usunięciu elementu o wartości 5: ");
    displayList(head);

    deleteList(&head);

    return 0;
}
