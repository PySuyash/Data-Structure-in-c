// write down procedure of DeleteList(Position p, ListEntry *x, List *list), RetriveList(Position p, ListEntry *x, List *list) and ReplaceList(Position p, ListEntry x, List *list)  for singular linklist, circular linklist and for singular linklist where structure List have information of last accessed node position and address of node in current node pointer variable.

#include <stdio.h>
#include <stdlib.h>

typedef int ListEntry; // Change if needed
typedef int Position;

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

/* ---------- Insert ---------- */
void InsertList(Position p, ListEntry x, List *list) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->entry = x;

    // Case 1: Empty list
    if (list->head == NULL) {
        newNode->next = newNode; // circular self-link
        list->head = newNode;
        list->curPtr = newNode;
        list->curPos = 0;
        list->size = 1;
        return;
    }

    // Case 2: Insert at head
    if (p == 0) {
        Node *last = list->head;
        if (list->curPos == list->size - 1) {
            last = list->curPtr; // optimization
        } else {
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
    if (p > list->curPos) {
        prev = list->curPtr;
        startPos = list->curPos;
    } else {
        prev = list->head;
        startPos = 0;
    }
    for (int i = startPos; i < p - 1; i++)
        prev = prev->next;

    newNode->next = prev->next;
    prev->next = newNode;
    list->curPtr = newNode;
    list->curPos = p;
    list->size++;
}

/* ---------- Delete ---------- */
void DeleteList(Position p, ListEntry *x, List *list) {
    if (p < 0 || p >= list->size || list->head == NULL) return;

    Node *temp;
    if (p == 0) {
        Node *last = list->head;
        while (last->next != list->head)
            last = last->next;
        temp = list->head;
        *x = temp->entry;
        if (list->size == 1) {
            list->head = NULL;
            list->curPtr = NULL;
            list->curPos = -1;
        } else {
            last->next = temp->next;
            list->head = temp->next;
            list->curPtr = list->head;
            list->curPos = 0;
        }
    } else {
        Node *prev;
        int startPos;
        if (p > list->curPos) {
            prev = list->curPtr;
            startPos = list->curPos;
        } else {
            prev = list->head;
            startPos = 0;
        }
        for (int i = startPos; i < p - 1; i++)
            prev = prev->next;

        temp = prev->next;
        *x = temp->entry;
        prev->next = temp->next;
        list->curPtr = prev;
        list->curPos = p - 1;
    }
    free(temp);
    list->size--;
}

/* ---------- Retrieve ---------- */
void RetrieveList(Position p, ListEntry *x, List *list) {
    if (p < 0 || p >= list->size || list->head == NULL) return;

    Node *cur;
    int startPos;
    if (p >= list->curPos) {
        cur = list->curPtr;
        startPos = list->curPos;
    } else {
        cur = list->head;
        startPos = 0;
    }
    for (int i = startPos; i < p; i++)
        cur = cur->next;

    *x = cur->entry;
    list->curPos = p;
    list->curPtr = cur;
}

/* ---------- Replace ---------- */
void ReplaceList(Position p, ListEntry x, List *list) {
    if (p < 0 || p >= list->size || list->head == NULL) return;

    Node *cur;
    int startPos;
    if (p >= list->curPos) {
        cur = list->curPtr;
        startPos = list->curPos;
    } else {
        cur = list->head;
        startPos = 0;
    }
    for (int i = startPos; i < p; i++)
        cur = cur->next;

    cur->entry = x;
    list->curPos = p;
    list->curPtr = cur;
}

/* ---------- Utility ---------- */
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

/* ---------- Main Demo ---------- */
int main() {
    List myList = {NULL, NULL, -1, 0};
    ListEntry val;

    InsertList(0, 10, &myList);
    InsertList(1, 20, &myList);
    InsertList(1, 15, &myList);
    InsertList(0, 5, &myList);
    InsertList(4, 25, &myList);
    PrintList(&myList);

    DeleteList(2, &val, &myList);
    printf("Deleted: %d\n", val);
    PrintList(&myList);

    RetrieveList(2, &val, &myList);
    printf("Retrieved: %d\n", val);

    ReplaceList(1, 99, &myList);
    PrintList(&myList);

    return 0;
}
