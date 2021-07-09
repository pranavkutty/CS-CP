// detect and remove loop from linked list
// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

void removeLoop(Node* head)
{
    if(head==NULL || head->next==NULL)
        return ;
    Node* slow = head->next, *fast = head->next->next;
    Node *prev = slow;
    
    while(fast!=slow && (fast!=NULL && fast->next!=NULL)){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(fast==NULL || fast->next==NULL)
        return ;
    
    fast = head;
    while(fast!=slow){
        prev = slow;
        fast = fast->next;
        slow = slow->next;
    }
    
    prev->next = NULL;
}