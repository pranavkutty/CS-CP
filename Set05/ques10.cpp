// reverse linkedlist in k groups - recursive
// https://leetcode.com/problems/reverse-nodes-in-k-group/

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL || head->next==NULL) return head;
    ListNode* nextHead = head;  //before reversing
    int count = k;
    while(count--){
        if(nextHead==NULL)
            return head;
        nextHead = nextHead->next;
    }
    ListNode* prev = reverseKGroup(nextHead,k);
    ListNode* curr = head;
    while(k--){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}