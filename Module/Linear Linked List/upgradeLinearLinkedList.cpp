#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int value;
    Node* Next;

    //constructor creation
    Node(int val){
      value= val;
      Next = NULL;
    }
};
void insertAtTail(Node* &head,int val){
  Node *newNode = new Node(val); //object creation using Class Node
  if(head==NULL){
    head = newNode;
    return;
  }
  Node *temp = head;
  while(temp->Next!=NULL){
    temp= temp->Next;
  }
  temp->Next = newNode;

}
void display(Node* n)
{
    while(n!= NULL){
        cout << n->value;
        if(n->Next !=NULL)
            cout << " -> ";
            n= n->Next;
    }
}

int main()
{
    Node *head = NULL;

    int n;
    char choice = 'y';
    while(choice == 'y'){
      cout <<"Enter the value: "<<endl;
      cin>>n;
      insertAtTail(head,n);
      cout <<"Do you want to continue:(y/n)"<<endl;;
      cin>>choice;
    }

    display(head);

    return 0;
}
