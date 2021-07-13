// Swap K nodes from the end
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

void swapNodesHelper(ListNode* node1, ListNode* prev1, ListNode* node2, ListNode* prev2, const int &k, int &count){
    if(node2->next!=NULL){
        swapNodesHelper(node1,prev1,node2->next,node2,k,count);
    }
    
    if(count==k){
        if(node1->next==node2){
            prev1->next = node2;
            node1->next = node2->next;
            node2 ->next = node1;
        }
        else if(node2->next == node1){
            prev2->next = node1;
            node2->next = node1->next;
            node1->next = node2;
        }
        else{
            ListNode* next2 = node2->next;
            if (prev1!=NULL) prev1->next = node2;
            node2->next = node1->next;
            if(prev2!=NULL) prev2->next = node1;
            node1->next = next2;
        }
    }
    count++;
}


ListNode* swapNodes(ListNode* head, int k) {
    if(head->next==NULL) return head;
    ListNode* sentinelNode = new ListNode();
    sentinelNode->next = head;
    ListNode *prev1 = sentinelNode, *node1 = head, *prev2 = sentinelNode, *node2 = head;
    int count = k;
    while(--count){
        prev1 = node1;
        node1 = node1->next;
    }
    count = 1;
    
    swapNodesHelper(node1,prev1,node2,prev2,k,count);
    
    return sentinelNode->next;        
}