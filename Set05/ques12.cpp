//  Reorder Linked List
// https://leetcode.com/problems/reorder-list/

void reorderListHelper(ListNode** curr1, ListNode* curr, int n, int &count, bool &flag){
    if(curr->next!=NULL){
        reorderListHelper(curr1,curr->next,n,count,flag);
    }
    
    if(count>(n/2)){
        count = -1;
        flag = true;
        if(n%2==0)
            (*curr1)->next = NULL;
        else
            (*curr1)->next = NULL;
    }
    
    if(!flag){
        ListNode* temp = (*curr1)->next;
        (*curr1)->next = curr;
        curr->next = temp;
        *curr1 = temp;
        count++;
    }
    
}

void reorderList(ListNode* head) {
    int n = 0;
    ListNode* curr = head;
    while(curr!=NULL){
        n++;
        curr = curr->next;
    }
    if(n<=2)
        return;
    ListNode** curr1 = &head;
    curr = head;
    int count = 1;
    bool flag = false;
    reorderListHelper(curr1, curr, n, count, flag);
}