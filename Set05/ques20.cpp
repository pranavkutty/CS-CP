// Intersection of two sorted linked list
// https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1#

Node* findIntersection(Node* l1, Node* l2)
{
    Node* dummy = new Node(0);
    Node* l3 = dummy;
    
    while(l1!=NULL && l2!=NULL){
        if(l1->data > l2->data)
            l2 = l2->next;
        else if(l2->data > l1->data)
            l1 = l1->next;
        else{
            int val = l1->data;
            l3->next = new Node(val);
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    
    return dummy->next;
    
}