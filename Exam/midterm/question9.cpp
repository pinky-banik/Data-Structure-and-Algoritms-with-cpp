#include<bits/stdc++.h>
using namespace std;

class doublyNode
{
public:

    int val;
    doublyNode* prev;
    doublyNode* next;

    doublyNode(int val)
    {
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtTail(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);

    if(head==NULL)
    {
        head = newNode;
        return;
    }

    doublyNode *temp = head;

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void insertAtHead(doublyNode *&head, int val)
{
     //s1:newNode creation
    doublyNode *newNode = new doublyNode(val);
    //update of head->prev
    head ->prev = newNode;
    //s3:Update of newnode next
    newNode->next = head;
    //s4:Update of head
    head = newNode;
}

void display(doublyNode* n)
{
    while(n!=NULL)
    {
        cout<< n->val;
        if(n->next!=NULL)
            cout<<" ----> ";
        n=n->next;
    }
    cout<<endl<<endl;
}
void displayReverse(doublyNode* &head)
{
    doublyNode* temp = head;

    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    while(temp != NULL)
    {
        cout<< temp->val;
        if(temp->prev!=NULL)
            cout<<" ----> ";
        temp=temp->prev;
    }
    cout<<endl
        <<endl;
}

int countLength(doublyNode *&head)
{
    int count = 0;
    doublyNode *temp = head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}


int main()
{
    doublyNode *head = NULL;

    int value,position;

    cout<< "Choice 1:Insertaion at Head" <<endl
        << "Choice 2:Insertaion at Tail" <<endl
        << "Choice 3:Reverse Print" <<endl
        << "Choice 0:Exit"<<endl;

    cout<< "Next Choice: ";
    int  choice;
    cin>>choice;

    while(choice!= 0)
    {

        switch(choice)
        {
        case 1:
            cout<< "Enter the value: ";
            cin>>value;
            insertAtHead(head,value);
            break;
        case 2:
            cout<< "Enter the value: ";
            cin>>value;
            insertAtTail(head,value);
            break;
        case 3:
//            cout<< "Enter the value: ";
//            cin>>value;
            displayReverse(head);
            break;


        default:
            break;
        }

        cout<<"Next Choice:";
        cin>>choice;

    }

    cout<<endl<<"Doubly Linked List: ";
    display(head);
    cout<<"Length of the Doubly Linked List: " << countLength(head) << endl;
//solve by array
int a[1001],b[1001];


    int n;
	cin>>n;
    int ans;

	for(int i=1;i<=n;i++)
	{
	    cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
	    if(a[i]==0)
		{
		    b[ans]=i,a[i]=ans,ans=i;
		}
		while(b[ans])
		{
		    ans=b[ans];
		}
	}
	for(int i=1;i<=n;i++)
	{
	    cout<<a[i]<<" "<<b[i]<<endl;
	}
    return 0;

}
