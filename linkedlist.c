#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Function to Push a Node at the Head
void Push(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;  // Link the old head to the new node
    *headRef = newNode;        // Move the head to point to the new node
}

// Function to Calculate Length of the List
int Length(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to Change Head Pointer to NULL
void ChangeToNull(struct Node** headRef) {
    *headRef = NULL;
}

// Build List Using Push at Head
struct Node* BuildListAtHead() {
    struct Node* head = NULL;
    for (int i = 1; i < 6; i++) {
        Push(&head, i);
    }
    return head;  // Returns head pointing to {5, 4, 3, 2, 1}
}

// Build List Using Tail Pointer
struct Node* BuildListWithTailPointer() {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 1; i < 6; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;  // First node is head
            tail = head;     // Set tail to the first node
        } else {
            tail->next = newNode;  // Link new node to the last node
            tail = newNode;        // Update tail
        }
    }
    return head;  // Returns head pointing to {1, 2, 3, 4, 5}
}

// Build List Using Local Reference
struct Node* BuildListWithLocalRef() {
    struct Node* head = NULL;
    struct Node** lastPtrRef = &head;  // Points to head pointer

    for (int i = 1; i < 6; i++) {
        Push(lastPtrRef, i);  // Add node at last pointer
        lastPtrRef = &((*lastPtrRef)->next);  // Advance to new last pointer
    }
    return head;  // Returns head pointing to {1, 2, 3, 4, 5}
}

// Function to Pop the Head Node
int Pop(struct Node** headRef) {
    if (*headRef == NULL) {
        // List is empty
        printf("List is empty, cannot pop.\n");
        return -1; // Return an indicator of failure
    }
    
    struct Node* temp = *headRef;
    int poppedData = temp->data;
    *headRef = (*headRef)->next; // Move head to the next node
    free(temp); // Free the old head
    return poppedData; // Return the data of the popped node
}

// Get N-th Element
int GetNthElement(struct Node* head, int n) {
    struct Node* current = head;
    int count = 0;

    while (current != NULL) {
        if (count == n) {
            return current->data; // Return data at the N-th position
        }
        count++;
        current = current->next;
    }

    printf("Index out of range.\n");
    return -1; // Return an indicator of failure
}

// Delete the entire list
void DeleteList(struct Node** headRef) {
    struct Node* current = *headRef;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    *headRef = NULL; // Set head to NULL after deletion
}

// Display the list
void DisplayList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Count elements in the list
int CountElements(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count; // Return the count of elements
}

// Insert at N-th position
void InsertNth(struct Node** headRef, int index, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    if (index == 0) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }
    
    struct Node* current = *headRef;
    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Index out of bounds.\n");
        free(newNode);
        return;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

// Sorted Insert
void SortedInsert(struct Node** headRef, struct Node* newNode) {
    if (*headRef == NULL || (*headRef)->data >= newNode->data) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

    struct Node* current = *headRef;
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Insert Sort
void InsertSort(struct Node** headRef) {
    struct Node* sorted = NULL;
    struct Node* current = *headRef;

    while (current != NULL) {
        struct Node* next = current->next;
        SortedInsert(&sorted, current);
        current = next;
    }

    *headRef = sorted;
}

// Append two lists
void Append(struct Node** aRef, struct Node** bRef) {
    if (*aRef == NULL) {
        *aRef = *bRef;
    } else {
        struct Node* current = *aRef;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = *bRef;
    }
    *bRef = NULL; // Set b to NULL
}

// Remove duplicates from a sorted list
void RemoveDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* nextNode = current->next->next;
            free(current->next);
            current->next = nextNode;
        } else {
            current = current->next;
        }
    }
}
