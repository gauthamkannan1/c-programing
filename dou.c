#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->prev = n->next = NULL;
    return n;
}

void insertFirst(struct Node** head, int data) {
    struct Node* n = createNode(data);
    n->next = *head;
    if (*head) (*head)->prev = n;
    *head = n;
}

void insertEnd(struct Node** head, int data) {
    struct Node* n = createNode(data);
    if (*head == NULL) { *head = n; return; }
    struct Node* t = *head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void insertPos(struct Node** head, int data, int pos) {
    if (pos == 0) { insertFirst(head, data); return; }
    struct Node* n = createNode(data);
    struct Node* t = *head;
    
    // Navigate to position pos-1
    for (int i = 0; t && i < pos - 1; i++) t = t->next;
    
    // If t is NULL, position is out of range
    if (!t) { printf("Invalid position\n"); free(n); return; }
    
    // Insert n between t and t->next
    n->next = t->next;
    n->prev = t;
    if (t->next) t->next->prev = n;
    t->next = n;
}

void deleteFirst(struct Node** head) {
    if (!*head) { printf("List empty\n"); return; }
    struct Node* t = *head;
    *head = (*head)->next;
    if (*head) (*head)->prev = NULL;
    free(t);
}

void deleteEnd(struct Node** head) {
    if (!*head) { printf("List empty\n"); return; }
    if (!(*head)->next) { free(*head); *head = NULL; return; }
    struct Node* t = *head;
    while (t->next) t = t->next;
    t->prev->next = NULL;
    free(t);
}

void deletePos(struct Node** head, int pos) {
    if (!*head) { printf("List empty\n"); return; }
    if (pos == 0) { deleteFirst(head); return; }
    
    struct Node* t = *head;
    
    // Navigate to position pos
    for (int i = 0; t && i < pos; i++) t = t->next;
    
    // If t is NULL, position is out of range
    if (!t) { printf("Invalid position\n"); return; }
    
    // Update links to bypass t
    if (t->prev) t->prev->next = t->next;
    if (t->next) t->next->prev = t->prev;
    free(t);
}

void printList(struct Node* head) {
    if (!head) { printf("List empty\n"); return; }
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int ch, num, pos;

    while (1) {
        printf("\n1.Insert First  \n2.Insert End  \n3.Insert Pos");
        printf("\n4.Delete First  \n5.Delete End  \n6.Delete Pos");
        printf("\n7.Print  \n8.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Number: "); scanf("%d", &num);
            insertFirst(&head, num);
        }
        else if (ch == 2) {
            printf("Number: "); scanf("%d", &num);
            insertEnd(&head, num);
        }
        else if (ch == 3) {
            printf("Number: "); scanf("%d", &num);
            printf("Position: "); scanf("%d", &pos);
            insertPos(&head, num, pos);
        }
        else if (ch == 4) deleteFirst(&head);
        else if (ch == 5) deleteEnd(&head);
        else if (ch == 6) {
            printf("Position: "); scanf("%d", &pos);
            deletePos(&head, pos);
        }
        else if (ch == 7) printList(head);
        else if (ch == 8) break;
        else printf("Invalid choice\n");
    }
    return 0;
}
