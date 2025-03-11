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
void inseartAtHead(Node* &head, int data){
    Node* newNode=new Node(data);
    newNode->next=head;
    head=newNode;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    Node* head= NULL;
    inseartAtHead(head, 10);
    inseartAtHead(head, 20);
    inseartAtHead(head, 30);
    print(head);

return 0;
}