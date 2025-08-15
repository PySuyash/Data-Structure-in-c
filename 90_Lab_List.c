//With respect to void InsertList(Position p, ListEntry x, List *list) for singly linklist as discussed in shared file, write down procedure of InsertList for circular linklist and for singular linklist where structure List have information of last accessed node position and address of node in current node pointer variable.

#include <stdio.h>
#include <stdlib.h>

typedef int ListEntry; // change type if needed

typedef struct node {
    ListEntry entry;
    struct node *next;
} Node;

typedef struct {
    Node *head;      // head pointer
    Node *curPtr;    // pointer to last accessed node
    int curPos;      // position of curPtr
    int size;        // number of nodes
} List;

typedef int Position;

// Insert into circular singly linked list with last accessed optimization
void InsertList(Position p, ListEntry x, List *list) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->entry = x;

    // Case 1: Empty list
    if (list->head == NULL) {
        newNode->next = newNode; // points to itself (circular)
        list->head = newNode;
        list->curPtr = newNode;
        list->curPos = 0;
        list->size = 1;
        return;
    }

    // Case 2: Insert at head (position 0)
    if (p == 0) {
        Node *last = list->head;

        // Optimization: if curPtr is at last node, skip full loop
        if (list->curPos == list->size - 1)
            last = list->curPtr;
        else {
            while (last->next != list->head)
                last = last->next;
        }

        newNode->next = list->head;
        last->next = newNode;
        list->head = newNode;

        list->curPtr = newNode;
        list->curPos = 0;
        list->size++;
        return;
    }

    // Case 3: Insert at position p > 0
    Node *prev;
    int startPos;

    // Optimization: start from curPtr if closer to p
    if (p > list->curPos) {
        prev = list->curPtr;
        startPos = list->curPos;
    } else {
        prev = list->head;
        startPos = 0;
    }

    // Move to (p-1)-th node
    for (int i = startPos; i < p - 1; i++) {
        prev = prev->next;
        if (prev == list->head) break; // wrap-around in circular list
    }

    newNode->next = prev->next;
    prev->next = newNode;

    list->curPtr = newNode;
    list->curPos = p;
    list->size++;
}

// Debug print function for circular list
void PrintList(List *list) {
    if (!list->head) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = list->head;
    for (int i = 0; i < list->size; i++) {
        printf("%d ", temp->entry);
        temp = temp->next;
    }
    printf("\n");
}

// Example usage
int main() {
    List myList = {NULL, NULL, -1, 0};

    InsertList(0, 10, &myList); // insert at head
    InsertList(1, 20, &myList); // insert at tail
    InsertList(1, 15, &myList); // insert in middle
    InsertList(0, 5, &myList);  // insert new head
    InsertList(4, 25, &myList); // insert at last position

    PrintList(&myList);
    return 0;
}
