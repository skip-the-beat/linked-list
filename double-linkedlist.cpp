#include <iostream>
using namespace std;

class Node{
public:    
    int data;
    Node*prev;
    Node*next;

    Node(int data){
        this->data=data;
        this->prev=NULL;
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
    head->prev=newnode;
    head=newnode;
}

void insertAtTail(Node*&head,int data){
    Node*newnode=new Node(data);
    if(head==NULL){
        head=newnode;
        return;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}

void insertAtPosition(Node*&head,int pos,int data){
    Node*newnode=new Node(data);
    if(head==NULL){
        head=newnode;
        return;
    }
    int count=0;
    Node*temp=head;
    while(count!=pos-2){
        count++;
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next->prev=newnode;
    newnode->prev=temp;
    temp->next=newnode;

}

void deleteAtPosition(Node*&head,int pos){
    if(head==NULL){
        cout<<"Linked list is empty";
        return;
    }
    Node*temp=head;
    int count=0;
    while(count!=pos-2){
        count++;
        temp=temp->next;
    }
    Node*deleteNode=temp->next;
    temp->next=temp->next->next;
    temp->next->next->prev=temp;
    delete deleteNode;

}

void print(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void getLength(Node*head){
    Node*temp=head;
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    cout<<length<<endl;
}

int main(){
    Node*node1=new Node(5);
    Node*head=node1;

    // cout<<node1->data<<endl;
    // cout<<node1->prev<<endl;
    // cout<<node1->next<<endl;    

    insertAtHead(head,1);
    print(head);
    insertAtTail(head,5);
    print(head);
    insertAtPosition(head,2,6);
    print(head);
    insertAtPosition(head,2,4);
    print(head);
    deleteAtPosition(head,2);
    print(head);
    deleteAtPosition(head,3);
    print(head); 
}

// implement conditions for del at head and tail in delatpos
// also,delatpos not working properly
