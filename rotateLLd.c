#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate the linked list by k places
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;  // No rotation needed for empty list or single node
    }

    // Step 1: Calculate the length of the linked list
    struct ListNode* temp = head;
    int length = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Step 2: Connect the last node to the head to make it circular
    temp->next = head;

    // Step 3: Find the new head after rotating
    k = k % length;  // In case k is larger than the length
    if (k == 0) {
        temp->next = NULL;  // No rotation needed
        return head;
    }

    // Find the new head (n - k)th node
    struct ListNode* newTail = head;
    for (int i = 1; i < length - k; i++) {
        newTail = newTail->next;
    }

    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;  // Break the circular link

    return newHead;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Helper function to free the linked list memory
void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Example 1: Rotating [1, 2, 3, 4, 5] by 2
    struct ListNode* l1 = createNode(1);
    l1->next = createNode(2);
    l1->next->next = createNode(3);
    l1->next->next->next = createNode(4);
    l1->next->next->next->next = createNode(5);

    printf("Original List: ");
    printList(l1);

    struct ListNode* rotated1 = rotateRight(l1, 2);
    printf("Rotated List (k=2): ");
    printList(rotated1);

    // Free memory
    freeList(rotated1);

    // Example 2: Rotating [0, 1, 2] by 4
    struct ListNode* l2 = createNode(0);
    l2->next = createNode(1);
    l2->next->next = createNode(2);

    printf("Original List: ");
    printList(l2);

    struct ListNode* rotated2 = rotateRight(l2, 4);
    printf("Rotated List (k=4): ");
    printList(rotated2);

    // Free memory
    freeList(rotated2);

    return 0;
}
