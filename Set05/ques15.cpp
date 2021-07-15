// Sort a linked list
// https://leetcode.com/problems/sort-list/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    
    ListNode* l3;
    
    if(l1->val<=l2->val){
        l3 = l1;
        l1 = l1->next;
    }
    else{
        l3 = l2;
        l2 = l2->next;
    }
    ListNode *l3Head = l3;
    
    while(l1!=NULL && l2!=NULL){
        if(l1->val<=l2->val){
            l3->next = l1;
            l1 = l1->next;
        }
        else{
            l3->next = l2;
            l2 = l2->next;
        }
        l3 = l3->next;
    }
    
    while(l1!=NULL){
        l3->next = l1;
        l1 = l1->next;
        l3 = l3->next;
    }
    while(l2!=NULL){
        l3->next = l2;
        l2 = l2->next;
        l3 = l3->next;
    }       
    
    return l3Head;
}

ListNode* getMid(ListNode* head){
    ListNode* slow = head, *fast = head;
    ListNode* prev = NULL;
    
    while(fast!=NULL && fast->next!=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    return slow;
}


ListNode* sortList(ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;
    
    ListNode* mid = getMid(head);
    
    ListNode* l = sortList(head);
    ListNode* r = sortList(mid);
    
    return mergeTwoLists(l,r);
}