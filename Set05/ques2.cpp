// palindromic linked list - recursive
// https://leetcode.com/problems/palindrome-linked-list/

bool isPalindromeHelper(ListNode* head, ListNode* curr, ListNode** prev, bool &done){
    if(curr==NULL){
        return true;
    }
    
    bool nxt = isPalindromeHelper(head,curr->next,prev,done);
    if(done) return nxt;
    if(nxt){
        if((*prev)==curr || curr->next==(*prev)){
            done = true;
            return true;
        }
        if((*prev)->val==curr->val){
            (*prev) = (*prev)->next;
            return true;
        }
        else
            return false;
    }
    else
        return false;        
}
bool isPalindrome(ListNode* head) {
    if(head==NULL || head->next==NULL) return true;
    ListNode** prev = &head;
    bool done = false;
    return isPalindromeHelper(head,head,prev,done);
}