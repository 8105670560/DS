struct ListNode* partition(struct ListNode* head, int x) {
    // Create two dummy nodes for the two partitions
    struct ListNode* lessHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* greaterHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    lessHead->next = NULL;
    greaterHead->next = NULL;

    struct ListNode* less = lessHead;
    struct ListNode* greater = greaterHead;

    while (head != NULL) {
        if (head->val < x) {
            less->next = head;
            less = less->next;
        } else {
            greater->next = head;
            greater = greater->next;
        }
        head = head->next;
    }

    // Terminate the greater list
    greater->next = NULL;

    // Connect the two partitions
    less->next = greaterHead->next;

    // Free dummy nodes
    struct ListNode* result = lessHead->next;
    free(lessHead);
    free(greaterHead);

    return result;
}
