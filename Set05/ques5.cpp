//Intersection point in the linked list
// https://leetcode.com/problems/intersection-of-two-linked-lists/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int n1 = 0, n2 = 0;
    ListNode* curr = headA;
    
    while(curr!=NULL){
        n1++;
        curr = curr->next;
    }
    curr = headB;
    
    while(curr!=NULL){
        n2++;
        curr = curr->next;
    }
    
    int diff = abs(n1-n2);
    
    if(n1<n2){
        curr = headB;
        ListNode* curr1 = headA;
        while(diff--)
            curr = curr->next;
        while(curr1 != curr){
            curr = curr->next;
            curr1 = curr1->next;
        }
    }
    else{
        curr = headA;
        ListNode *curr1 = headB;
        while(diff--)
            curr = curr->next;
        while(curr1 != curr){
            curr = curr->next;
            curr1 = curr1->next;
        }
    }
    
    return curr;
}