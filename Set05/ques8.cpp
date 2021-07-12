// Remove all occurrences of duplicates from a sorted Linked List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;
    
    ListNode* dummy = new ListNode();
    dummy->next = head;
    
    ListNode* curr = head;
    ListNode* prev = dummy;
    while(curr!=NULL){
        bool flag = false;
        while(curr->next!=NULL && curr->val==curr->next->val){
            flag = true;
            curr = curr->next;
        }
        if(flag) prev->next = curr->next;
        else{
            prev->next = curr;
            prev = curr;
        }
        curr = curr->next;
    }
    
    return dummy->next;
}