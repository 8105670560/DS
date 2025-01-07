// Function to reverse the linked list between positions left and right
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right) return head;

    // Create a dummy node to simplify edge cases (like when left is 1)
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;

    // Step 1: Move prev to the node just before the 'left' position
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    // Step 2: Reverse the sublist from left to right
    struct ListNode* curr = prev->next; // This is the first node to be reversed
    struct ListNode* next = NULL;
    for (int i = 0; i < right - left; i++) {
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    // Return the new head of the list
    struct ListNode* result = dummy->next;
    free(dummy);  // Free the dummy node to avoid memory leak
    return result;
}
