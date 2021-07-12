// merge two sorted linked list
// https://leetcode.com/problems/merge-two-sorted-lists/

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