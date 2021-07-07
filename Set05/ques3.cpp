// add two numbers in linked list
// https://leetcode.com/problems/add-two-numbers/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *a=l1, *b=l2, *l3=new ListNode(0);
    
    ListNode* c = NULL;
    int carry = 0;
    while(l1!=NULL && l2!=NULL){
        int sum = l1->val+l2->val+carry;
        carry = sum/10;
        sum = sum%10;
        
        if(c==NULL){
            l3->val = sum;
            c = l3;
        }
        else{
            c->next = new ListNode(sum);
            c = c->next;                
        } 
        l1 = l1->next;
        l2 = l2->next;
    }
    
    while(l1!=NULL){
        int sum = l1->val+carry;
        carry = sum/10;
        sum = sum%10;
        if(c==NULL){
            l3->val = sum;
            c = l3;
        }
        else{
            c->next = new ListNode(sum);
            c = c->next;                
        } 
        l1 = l1->next;
    }
    while(l2!=NULL){
        int sum = l2->val+carry;
        carry = sum/10;
        sum = sum%10;
        if(c==NULL){
            l3->val = sum;
            c = l3;
        }
        else{
            c->next = new ListNode(sum);
            c = c->next;                
        }             
        l2 = l2->next;
    }
    
    
    if(carry>0){
        c->next = new ListNode(carry);
    }        
    
    return l3;
}