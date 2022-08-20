#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    //Constuctor
    Node(int val)
    {
        value = val;
        Next = NULL;


    }
};



void insertAtTail(Node* &head, int val);
void insertAtHead(Node* &head, int val);
void display(Node *n);
void insertionAtSpacificPosition(Node *&head,int pos,int val);
void deletionAtHead(Node* &head);
void deletionAtTail(Node* &head);
void deletionAtSpecificPosition(Node* &head,int position);




void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if(head==NULL)
    {
        head = newNode;
        newNode->Next=head;
        return;
    }

    Node *temp = head;

    while(temp->Next!=head)
    {
        temp = temp->Next;
    }
    newNode->Next = head; //newNode->Next = temp->Next
    temp->Next=newNode;
}
void insertAtHead(Node *&head, int val)
{
    //s1:newNode creation
    Node *newNode = new Node(val);
    //s2:Update of newnode next
    newNode->Next = head;
    //s3:Update of head
     if(head==NULL)
    {
        head = newNode;
        newNode->Next=head;
        return;
    }
    Node* temp = head;
    while(temp->Next!=head)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
    head = newNode;
}
void display(Node *n)
{
    while(n!=NULL)
    {
        cout<< n->value;
        if(n->Next!=NULL)
            cout<<" -> ";
        n=n->Next;
    }
    cout<<endl<<endl;
}

int countLength(Node* &head)
{
    int count = 0;
    Node* temp = head;
    while(temp!=NULL)
    {
        temp=temp->Next;
        count++;
    }
    return count;
}



void insertionAtSpacificPosition(Node* &head,int pos,int val)
{
    int i = 0;
    Node* temp = head;

    while(i<pos-2)
    {
        temp=temp->Next;
        i++;
    }
    Node *newNode = new Node(val);
    newNode->Next=temp->Next;
    temp->Next = newNode;
}


void deletionAtHead(Node* &head)
{
    Node* temp = head;
    if(temp!=NULL)
    {
        head = temp->Next;
        delete temp;
    }
    else
    {
        cout<<"There is No value in the Linked List"<<endl;
    }
}

void deletionAtTail(Node* &head)
{
    Node *temp = head;
    if(temp!=NULL && temp->Next!=NULL)
    {
        while(temp->Next->Next!=NULL)
        {
            temp=temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next=NULL;
        delete delNode;
    }

    else
    {
        if(temp==NULL)
            cout<<"There is No value in the Linked List"<<endl;

        else
            deletionAtHead(head);

    }
}

void deletionAtSpecificPosition(Node* &head,int position)
{
    Node*temp = head;
    if( position<=countLength(head))
    {
        if(position==1)
        {
            deletionAtHead(head);
        }
        else if(position==countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
            int i=1;
            while(i < position - 1)
            {
                temp = temp->Next;
                i++;
            }
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
        else
        {
//            if(position > countLength(head))
//            {
                cout<<"Position Out of Bound";
//            }


//        else
//            cout << "There is No value in the Linked List" << endl;
//
    }

}


int main()
{
    Node *head = NULL;

    int value,position;

    cout<<"Choice 1: Insertaion at Head" <<endl
        <<"Choice 2: Insertaion at Tail"<< endl
        <<"Choice 3: Insertaion at specific position"<< endl
        <<"Choice 4: Delete at Head"<< endl
        <<"Choice 5: Delete at Tail"<< endl
        <<"Choice 6: DeletionAtSpecificPosition"<<endl
        <<"Choice 0: Exit"<<endl;

    cout<< "Next Choice: ";
    int  choice;
    cin>>choice;

    while(choice!= 0)
    {

        switch(choice)
        {
        case 1:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtHead(head,value);
            break;
        case 2:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtTail(head,value);
            break;

        default:
            break;
        }

        cout<<"Next Choice:";
        cin>>choice;

    }

    cout<<endl<<"Linkd List: ";
    display(head);
    cout<<"Length of the List: " << countLength(head) << endl;


    return 0;

}

















