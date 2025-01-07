#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to delete duplicates from a sorted linked list
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;

    // Traverse the list
    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            // Duplicate found, skip the next node
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp); // Free the memory of the skipped node
        } else {
            current = current->next; // Move to the next node
        }
    }

    return head;
}

// Helper function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Helper function to free the list
void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Create a sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3
    struct ListNode* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    printf("Original list:\n");
    printList(head);

    // Remove duplicates
    head = deleteDuplicates(head);

    printf("List after removing duplicates:\n");
    printList(head);

    // Free the list memory
    freeList(head);

    return 0;
}
