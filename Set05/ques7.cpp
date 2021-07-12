// Arrangement of Odd And Even Nodes In Linked List
// https://leetcode.com/problems/odd-even-linked-list/

ListNode* oddEvenList(ListNode* head) {
    if(head==NULL || head->next==NULL || head->next->next==NULL)
        return head;
    
    ListNode *oddHead = head, *evenHead = head->next;
    ListNode *odd = oddHead, *even = evenHead;
    
    while(odd->next!=NULL && even->next!=NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    
    odd->next = evenHead;
    
    return oddHead;
}