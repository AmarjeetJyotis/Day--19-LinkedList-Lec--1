#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data=0;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
 void inseartAtHead(Node* &head, Node* &tail,int data){
    // Cheack for LL is Empty
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
     
    Node* newNode=new Node(data);
    newNode->next=head;
    head=newNode;
 }

void inseartAtTail(Node* &head, Node* &tail,int data){
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node* newNode=new Node(data);
    tail->next=newNode;
    tail=newNode;

}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    Node* head= NULL;
    Node* tail=NULL;
    inseartAtHead(head,tail,10);
    inseartAtHead(head,tail,20);
    inseartAtHead(head,tail,30);
    inseartAtTail(head,tail, 50);
    print(head);
return 0;
}