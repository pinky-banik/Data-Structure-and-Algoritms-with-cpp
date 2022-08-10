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
        Next = Null;
    }
};
void insertAtTail(Node* &head,int val)
{
    Node *newNode = new Node(val);
    if(head ==Null)
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

    char choice = 'Y';
    while(choice == 'Y')
    {
        cin<<"Enter the Value: ";
         cin>>n;
        insertAtTail(head,n);
        cout<<"Do you want to Continue:(Y/N)";
        cin>choice;
    }

    insetAtTail(head ,1);
    insetAtTail(head ,5);
    insetAtTail(head ,8);
    insetAtTail(head ,9);
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
