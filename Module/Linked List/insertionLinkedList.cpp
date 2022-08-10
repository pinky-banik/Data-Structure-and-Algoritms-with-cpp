#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    //Constructor creation
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};
void insertAtTail(Node* &head,int val)
{
    Node *newNode = new Node(val);
    if(head ==NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->Next!= NULL)
    {
        temp = temp->Next;
    }

}
void insetAtHead(Node *&head,int val)

{
    //step1 :newNode creation
    Node*newNode = new Node(val);
    //step2: Update of newNode->Next
    newNode->Next =head;
    //step3 : Update of head
}
void display(Node* n)
{
    while(n!= NULL){
        cout << n->value;
        if(n-Next!=NULL)
            cout << " -> ";
            n= n->Next;
    }
}
int main()
{
    Node *head = NULL;
    int n;
    // Choice 1 : insertion at head
    // Choice 2 : insertion at tail

    cout <<"Choice 1: Insertion  at Head" <<endl<< "Choice 2 : Insertion at Tail" << endl << "Choice 3:  Exit"<<endl;

    int choice = '2';

    while(choice == '1' || choice == '2' )
    {
        cout<<"Enter the Value: ";
        cin>>n;
        if(choice==1) insetAtHead(head,n);
        else if(choice==2) insertAtTail(head,n);
        cout<<"Next choice: ";
        cin>>choice;
    }

    insertAtTail(head ,1);
    insertAtTail(head ,5);
    insertAtTail(head ,8);
    insertAtTail(head ,9);
    /*Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* forth = new Node();
    */

    head->value =1;
    second->value=5;
    third->value=8;
    forth->value=9;

    head->Next =second;
    second->Next=third;
    third->Next=forth;
    forth->Next=NULL;

    display(head);

    return 0;
}

