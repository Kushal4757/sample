#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Function to display the menu and get user choice
int displayMenu() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Push an element at head\n");
    printf("2. Pop an element from head\n");
    printf("3. Display the list\n");
    printf("4. Get the length of the list\n");
    printf("5. Get N-th element\n");
    printf("6. Delete the entire list\n");
    printf("7. Insert at N-th position\n");
    printf("8. Sorted Insert\n");
    printf("9. Insert Sort\n");
    printf("10. Append two lists\n");
    printf("11. Remove duplicates\n");
    printf("12. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    struct Node* head = NULL; // Initialize the head of the list
    struct Node* head2 = NULL; // Initialize another list for appending
    int choice, value, n;

    // Build the initial linked list
    head = BuildListAtHead();

    while (1) {
        choice = displayMenu(); // Show the menu and get user choice

        switch (choice) {
            case 1: // Push an element at head
                printf("Enter value to push at head: ");
                scanf("%d", &value);
                Push(&head, value);
                break;

            case 2: // Pop an element from head
                value = Pop(&head);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 3: // Display the list
                DisplayList(head);
                break;

            case 4: // Get the length of the list
                printf("Length of the list: %d\n", Length(head));
                break;

            case 5: // Get N-th element
                printf("Enter the index of the element you want to retrieve (0-based index): ");
                scanf("%d", &n);
                value = GetNthElement(head, n);
                if (value != -1) {
                    printf("The %d-th element in the list: %d\n", n, value);
                }
                break;

            case 6: // Delete the entire list
                DeleteList(&head);
                printf("The list has been deleted.\n");
                break;

            case 7: // Insert at N-th position
                printf("Enter index to insert: ");
                scanf("%d", &n);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                InsertNth(&head, n, value);
                break;

            case 8: // Sorted Insert
                printf("Enter value to insert in sorted order: ");
                scanf("%d", &value);
                {
                    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                    newNode->data = value;
                    newNode->next = NULL;
                    SortedInsert(&head, newNode);
                }
                break;

            case 9: // Insert Sort
                InsertSort(&head);
                printf("The list has been sorted.\n");
                break;

            case 10: // Append two lists
                printf("Building second list for appending...\n");
                head2 = BuildListWithTailPointer();
                Append(&head, &head2);
                printf("The two lists have been appended.\n");
                break;

            case 11: // Remove duplicates
                RemoveDuplicates(head);
                printf("Duplicates have been removed from the list.\n");
                break;

            case 12: // Exit
                DeleteList(&head); // Clean up before exiting
                printf("Exiting the program.\n");
                exit(0);

            default: // Invalid choice
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
