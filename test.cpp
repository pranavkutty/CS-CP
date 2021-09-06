#include<bits/stdc++.h>

struct Node{
    public:
    int row, col, val;
    Node(int row,int col, int val){
        this->row = row;
        this->col = col;
        this->val = val;
    }
};

static bool myCmp(Node *a,Node *b){
    if((a->row) == (b->row))
        return (a->val) < (b->val);

    return (a->row) < (b->row);
}

int main(){
    map<int,vector<Node>> m;
}