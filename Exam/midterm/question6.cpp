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
void insertValue(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if(head==NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while(temp->Next!=NULL)
    {
        temp = temp->Next;
    }
    temp->Next=newNode;
}
void changeValue(Node *n)
{

    while(n!=NULL)
    {
       
        if(n->value %2 ==0)
        {
            n->value=-1;
        }
        n=n->Next;
    }
}
void display(Node *n)
{

    while(n!=NULL)
    {
       
        cout<< n->value;
        if(n->Next!=NULL)
            cout<<" => ";
        n=n->Next;
    }
    cout<<endl<<endl;
}
int main()
{
    Node *head = NULL;
    int x,n;

    cin>>x;
    while(x--)
    {
         cin>>n;
        insertValue(head,n);     
    }
    

    changeValue(head);
    display(head);

    return 0;
}