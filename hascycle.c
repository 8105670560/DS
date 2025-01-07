#include <stdio.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to detect a cycle in the linked list
bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return false;
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // Traverse the list with two pointers
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // Move slow pointer by 1 step
        fast = fast->next->next;     // Move fast pointer by 2 steps
        
        // If slow and fast pointers meet, there is a cycle
        if (slow == fast) {
            return true;
        }
    }
    
    return false; // If we reach the end of the list, there is no cycle
}

// Helper function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Example usage
int main() {
    // Example 1: Creating a linked list with a cycle
    struct ListNode* head = createNode(3);
    head->next = createNode(2);
    head->next->next = createNode(0);
    head->next->next->next = createNode(-4);
    head->next->next->next->next = head->next; // Creating a cycle (tail points to second node)

    printf("Has cycle: %d\n", hasCycle(head)); // Output: 1 (true)

    // Example 2: Creating a linked list without a cycle
    struct ListNode* head2 = createNode(1);
    head2->next = createNode(2);

    printf("Has cycle: %d\n", hasCycle(head2)); // Output: 0 (false)

    return 0;
}
