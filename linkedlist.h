#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void Push(struct Node** headRef, int newData);
int Length(struct Node* head);
void ChangeToNull(struct Node** headRef);
struct Node* BuildListAtHead();
struct Node* BuildListWithTailPointer();
struct Node* BuildListWithLocalRef();
int Pop(struct Node** headRef);
int GetNthElement(struct Node* head, int n);
void DeleteList(struct Node** headRef);
void DisplayList(struct Node* head);
int CountElements(struct Node* head);
void InsertNth(struct Node** headRef, int index, int data);
void SortedInsert(struct Node** headRef, struct Node* newNode);
void InsertSort(struct Node** headRef);
void Append(struct Node** aRef, struct Node** bRef);
void RemoveDuplicates(struct Node* head);

#endif
