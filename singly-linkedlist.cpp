#include <iostream>
using namespace std;

class Node{
public:   
    int data;
    Node*next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtHead(Node*&head,int data){
    Node*newnode=new Node(data);
    if(head==NULL){
        head=newnode;
        return;
    }
    newnode->next=head;
    head=newnode;
}

void insertAtTail(Node*&head,Node*&tail,int data){
    Node*newnode=new Node(data);
    if(tail==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    tail->next=newnode;
    tail=newnode;
}

void insertAtPosition(Node*&head,Node*&tail,int pos,int data){
    Node*newnode=new Node(data);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    int count=0;
    Node*temp=head;
    while(count!=pos-2){
        count++;
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void deleteAtPosition(Node*&head,int pos){
    if(head==NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }
    int count=0;
    Node*temp=head;
    while(count!=pos-2){
        count++;
        temp=temp->next;
    }
    Node*deleteNode=temp->next;
    temp->next=temp->next->next;
    delete deleteNode;
}

void print(Node*&head){
    Node*temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;  
}

void getLength(Node*&head){
    Node*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    cout<<count<<endl;
}

int main(){
    Node* node1=new Node(5);
    // cout<<newnode->data<<" "<<newnode->next<<endl;

    Node*head=node1;
    Node*tail=node1;
    print(head);
    insertAtHead(head,10);
    print(head);
    insertAtHead(head,15);
    print(head);
    insertAtTail(head,tail,1);
    print(head);
    insertAtTail(head,tail,2);
    print(head);
    insertAtTail(head,tail,3);
    print(head);
    getLength(head);
    insertAtPosition(head,tail,3,30);
    insertAtPosition(head,tail,5,40);
    print(head);
    getLength(head);
    deleteAtPosition(head,3);
    print(head);
}
