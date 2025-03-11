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

    // For Deleation write a destructor for dlelete
    ~Node(){
        cout<<" Node with Value:"<<this->data<<"delete"<<endl;;
    }
};
void inseartAtHead(Node* &head, Node* &tail, int data){
    // If LL is Empty
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
void inseartAtTail(Node* &head, Node* &tail, int data){
    // If LL is Empty
    if(head==NULL){
        Node* newNode= new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node* newNode=new Node(data);
    tail->next=newNode;
    newNode->next=NULL;
    tail=newNode;
}
int findLength(Node* &head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
void insertAtPosition(int data,int position, Node* &head, Node* &tail){
    // If LL is Empty
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    // Step1: Find previous and current Node
    if (position==0){
        return inseartAtHead(head, tail, data);
    }
    int len=findLength(head);
    if(position>=len){
        return inseartAtTail(head, tail, data);
    }
    int i=1;
    Node* previous=head;
    while(i<position){
        previous=previous->next;
        i++;
    }
    Node* current=previous->next;
    // Step2
    Node* newNode=new Node(data);
    // Step3
    newNode->next=current;
    // Step4
    previous->next=newNode;
}

void deleteNode(int position, Node* &head, Node* &tail){
    // is empty
    if(head==NULL){
        cout<<"Can't Delete Node";
        return;
    }
    // Deleting first Node
    if(position==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
    // Deleting last Node
    int len=findLength(head);
    if(position==len){
        // Find previous Node
        int i=1;
        Node* previous=head;
        while(i<position-1){
            previous=previous->next;
            i++;
        }
        // step2
        previous->next=NULL;
        // step3
        Node* temp=tail;
        // Step4 
        tail=previous;
        delete temp;
        return;
    }
    // Deleting Middle Node
    int i=1;
    Node* previous=head;
    while(i<position-1){
        previous=previous->next;
        i++;
    }
    Node* current=previous->next;
    // Step 2
    previous->next=current->next;
    // Step 3
    current->next=NULL;
    // Step4
    delete current;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    inseartAtHead(head,tail, 10);
    inseartAtHead(head,tail, 20);
    inseartAtHead(head,tail, 30);
    inseartAtTail(head,tail, 50);
    print(head);
    
    // insertAtPosition(100, 2, head, tail);
    // cout<<endl;
    // print(head);
    // cout<<endl;
    deleteNode(2, head, tail);
    cout<<endl;
    print(head);
    cout<<endl;
   
return 0;
}