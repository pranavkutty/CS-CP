// reverse linked list: rec+itr
// https://leetcode.com/problems/reverse-linked-list/

// recursive
ListNode* reverseListHelper(ListNode* head, ListNode* prev){
    if(head==NULL){
        return prev;
    }
    ListNode* temp = head->next;
    head->next = prev;

    return reverseListHelper(temp,head);
}

ListNode* reverseList(ListNode* head) {
    return reverseListHelper(head,NULL);
}

// iterative
ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;
    
    ListNode* curr = head, *prev = NULL;
    
    while(curr!=NULL){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    
    return prev;
}