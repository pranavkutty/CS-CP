// clone with linked list with random pointers
// https://leetcode.com/problems/copy-list-with-random-pointer/

Node* copyRandomList(Node* head) {
    if(head==NULL) return NULL;
    Node* head1 = NULL;
    
    Node* curr = head;
    
    while(curr!=NULL){
        Node* temp = curr->next;
        curr->next = new Node(curr->val);
        curr->next->next = temp;
        curr = temp;           
    }
    
    head1 = head->next;
    
    curr = head;
    
    while(curr!=NULL){
        Node* curr1 = curr->next;
        if(curr->random!=NULL) curr1->random = curr->random->next;            
        curr = curr->next->next;
    }
    
    curr = head;
    
    while(curr!=NULL){
        Node* curr1 = curr->next;
        curr->next = curr1->next;
        
        if(curr->next!=NULL) curr1->next = curr->next->next;
        
        curr = curr->next;
    }
    
    return head1;       
}