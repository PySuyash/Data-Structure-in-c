// With respect to above procedure create a menu driven code for choosing tpye of linklist (singular linklist, circular linklist and for singular linklist where structure List have information of last accessed node position and address of node in current node pointer variable) for which following operation of creation, insertion, deletion, updation and displaying list performed

#include <stdio.h>
#include <stdlib.h>

typedef int ListEntry;
typedef int Position;

/* ---------- Node ---------- */
typedef struct node {
    ListEntry entry;
    struct node *next;
} Node;

/* ---------- List Types ---------- */
typedef struct {
    Node *head;
    int size;
} SinglyList;

typedef struct {
    Node *head;
    int size;
} CircularList;

typedef struct {
    Node *head;
    Node *curPtr;
    int curPos;
    int size;
} OptSinglyList;

/* ============================================================
   Singly Linked List Functions
   ============================================================ */
void InitSingly(SinglyList *list) {
    list->head = NULL;
    list->size = 0;
}

void InsertSingly(Position p, ListEntry x, SinglyList *list) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->entry = x;

    if (p == 0 || list->head == NULL) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node *prev = list->head;
        for (int i = 0; i < p - 1 && prev->next; i++)
            prev = prev->next;
        newNode->next = prev->next;
        prev->next = newNode;
    }
    list->size++;
}

void DeleteSingly(Position p, ListEntry *x, SinglyList *list) {
    if (p < 0 || p >= list->size) return;
    Node *temp;
    if (p == 0) {
        temp = list->head;
        *x = temp->entry;
        list->head = temp->next;
    } else {
        Node *prev = list->head;
        for (int i = 0; i < p - 1; i++)
            prev = prev->next;
        temp = prev->next;
        *x = temp->entry;
        prev->next = temp->next;
    }
    free(temp);
    list->size--;
}

void ReplaceSingly(Position p, ListEntry x, SinglyList *list) {
    if (p < 0 || p >= list->size) return;
    Node *cur = list->head;
    for (int i = 0; i < p; i++)
        cur = cur->next;
    cur->entry = x;
}

void DisplaySingly(SinglyList *list) {
    Node *cur = list->head;
    while (cur) {
        printf("%d ", cur->entry);
        cur = cur->next;
    }
    printf("\n");
}

/* ============================================================
   Circular Singly Linked List Functions
   ============================================================ */
void InitCircular(CircularList *list) {
    list->head = NULL;
    list->size = 0;
}

void InsertCircular(Position p, ListEntry x, CircularList *list) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->entry = x;
    if (list->head == NULL) {
        newNode->next = newNode;
        list->head = newNode;
    } else if (p == 0) {
        Node *last = list->head;
        while (last->next != list->head) last = last->next;
        newNode->next = list->head;
        last->next = newNode;
        list->head = newNode;
    } else {
        Node *prev = list->head;
        for (int i = 0; i < p - 1; i++)
            prev = prev->next;
        newNode->next = prev->next;
        prev->next = newNode;
    }
    list->size++;
}

void DeleteCircular(Position p, ListEntry *x, CircularList *list) {
    if (p < 0 || p >= list->size || list->head == NULL) return;
    Node *temp;
    if (p == 0) {
        Node *last = list->head;
        while (last->next != list->head) last = last->next;
        temp = list->head;
        *x = temp->entry;
        if (list->size == 1) {
            list->head = NULL;
        } else {
            last->next = temp->next;
            list->head = temp->next;
        }
    } else {
        Node *prev = list->head;
        for (int i = 0; i < p - 1; i++)
            prev = prev->next;
        temp = prev->next;
        *x = temp->entry;
        prev->next = temp->next;
    }
    free(temp);
    list->size--;
}

void ReplaceCircular(Position p, ListEntry x, CircularList *list) {
    if (p < 0 || p >= list->size) return;
    Node *cur = list->head;
    for (int i = 0; i < p; i++)
        cur = cur->next;
    cur->entry = x;
}

void DisplayCircular(CircularList *list) {
    if (!list->head) { printf("Empty\n"); return; }
    Node *cur = list->head;
    for (int i = 0; i < list->size; i++) {
        printf("%d ", cur->entry);
        cur = cur->next;
    }
    printf("\n");
}

/* ============================================================
   Optimized Singly Linked List Functions
   ============================================================ */
void InitOpt(OptSinglyList *list) {
    list->head = NULL;
    list->curPtr = NULL;
    list->curPos = -1;
    list->size = 0;
}

void InsertOpt(Position p, ListEntry x, OptSinglyList *list) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->entry = x;
    if (list->head == NULL) {
        newNode->next = NULL;
        list->head = newNode;
        list->curPtr = newNode;
        list->curPos = 0;
    } else if (p == 0) {
        newNode->next = list->head;
        list->head = newNode;
        list->curPtr = newNode;
        list->curPos = 0;
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
        newNode->next = prev->next;
        prev->next = newNode;
        list->curPtr = newNode;
        list->curPos = p;
    }
    list->size++;
}

void DeleteOpt(Position p, ListEntry *x, OptSinglyList *list) {
    if (p < 0 || p >= list->size) return;
    Node *temp;
    if (p == 0) {
        temp = list->head;
        *x = temp->entry;
        list->head = temp->next;
        list->curPtr = list->head;
        list->curPos = 0;
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

void ReplaceOpt(Position p, ListEntry x, OptSinglyList *list) {
    if (p < 0 || p >= list->size) return;
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

void DisplayOpt(OptSinglyList *list) {
    Node *cur = list->head;
    while (cur) {
        printf("%d ", cur->entry);
        cur = cur->next;
    }
    printf("\n");
}

/* ============================================================
   Main Menu
   ============================================================ */
int main() {
    int type, choice;
    printf("Choose list type:\n1. Singly\n2. Circular\n3. Optimized Singly\n");
    scanf("%d", &type);

    SinglyList sList;
    CircularList cList;
    OptSinglyList oList;
    ListEntry val;
    Position pos;

    if (type == 1) InitSingly(&sList);
    else if (type == 2) InitCircular(&cList);
    else InitOpt(&oList);

    do {
        printf("\n1.Insert\n2.Delete\n3.Replace\n4.Display\n5.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter position and value: ");
                scanf("%d%d", &pos, &val);
                if (type == 1) InsertSingly(pos, val, &sList);
                else if (type == 2) InsertCircular(pos, val, &cList);
                else InsertOpt(pos, val, &oList);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                if (type == 1) DeleteSingly(pos, &val, &sList);
                else if (type == 2) DeleteCircular(pos, &val, &cList);
                else DeleteOpt(pos, &val, &oList);
                printf("Deleted: %d\n", val);
                break;
            case 3:
                printf("Enter position and new value: ");
                scanf("%d%d", &pos, &val);
                if (type == 1) ReplaceSingly(pos, val, &sList);
                else if (type == 2) ReplaceCircular(pos, val, &cList);
                else ReplaceOpt(pos, val, &oList);
                break;
            case 4:
                if (type == 1) DisplaySingly(&sList);
                else if (type == 2) DisplayCircular(&cList);
                else DisplayOpt(&oList);
                break;
        }
    } while (choice != 5);

    return 0;
}
