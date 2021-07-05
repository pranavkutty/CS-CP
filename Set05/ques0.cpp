#include<bits/stdc++.h>

using namespace std;

class sllNode{
    public:
    int data;
    sllNode* next;

    sllNode(){
        sllNode(0);
    }

    sllNode(int data){
        this->data = data;
        this->next = NULL;
    }
};
class dllNode{
    public:
    int data;
    dllNode* next;
    dllNode* prev;

    dllNode(){
        sllNode(0);
    }

    dllNode(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class cllNode{
    public:
    int data;
    cllNode* next;

    cllNode(){
        cllNode(0);
    }

    cllNode(int data){
        this->data = data;
        this->next = this;
    }
};

class singlyLinkedList{
    public:
    sllNode* head;
    
    singlyLinkedList(){
        this->head = NULL;
    }

    void insertAtEnd(int data){
        if(this->head==NULL){
            head = new sllNode(data);
            return;
        }
        sllNode* curr = this->head;

        while(curr->next!=NULL)
            curr = curr->next;
        
        curr->next = new sllNode(data);
    }

    void insertAtBeg(int data){
        if(this->head==NULL){
            head = new sllNode(data);
            return;
        }

        sllNode* temp = new sllNode(data);
        temp->next = this->head;
        head = temp;   
    }

    void deleteAtBeg(){
        if(this->head==NULL)
            return;
        sllNode* prevHead = this->head;
        this->head = this->head->next;
        delete prevHead;
    }

    void deleteAtEnd(){
        if(this->head==NULL)
            return;
        sllNode* curr = this->head;

        if(curr->next==NULL){
            delete curr;
            this->head = NULL;
            return;
        }

        while(curr->next->next!=NULL)
            curr = curr->next;
        
        delete curr->next;
        curr->next = NULL;        
    }

    void printList(){
        sllNode* curr = head;

        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
    }
};


class doublyLinkedList{
    public:
    dllNode* head;
    
    doublyLinkedList(){
        this->head = NULL;
    }

    void insertAtEnd(int data){
        if(this->head==NULL){
            head = new dllNode(data);
            return;
        }
        dllNode* curr = this->head;

        while(curr->next!=NULL)
            curr = curr->next;
        
        curr->next = new dllNode(data);
        curr->next->prev = curr;
    }

    void insertAtBeg(int data){
        if(this->head==NULL){
            head = new dllNode(data);
            return;
        }

        dllNode* temp = new dllNode(data);
        temp->next = this->head;
        this->head->prev = temp;
        head = temp;   
    }

    void deleteAtBeg(){
        if(this->head==NULL)
            return;
        dllNode* prevHead = this->head;
        this->head = this->head->next;
        this->head->prev = NULL;
        delete prevHead;
    }

    void deleteAtEnd(){
        if(this->head==NULL)
            return;
        dllNode* curr = this->head;

        if(curr->next==NULL){
            delete curr;
            this->head = NULL;
            return;
        }

        while(curr->next->next!=NULL)
            curr = curr->next;
        
        delete curr->next;
        curr->next = NULL;        
    }

    void printList(){
        dllNode* curr = head;

        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
    }
};