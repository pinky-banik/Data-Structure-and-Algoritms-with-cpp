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

struct Test
{
    int position[1000];

};

void insertAtTail(Node* &head, int val);
void insertAtHead(Node* &head, int val);
void display(Node *n);
int countLength(Node* &head);
void insertionAtSpacificPosition(Node *&head,int pos,int val);
int searchByValueUnique(Node* &head,int val);
void searchByValueDuplicate(Node *&head,int key);
Test serchByValueDuplicateReturn(Node *&head,int key);
void searchByValueUnique(Node *&head,int searchValue,int value);
void deletionAtHead(Node* &head);
void deletionAtTail(Node* &head);
void deletionAtSpecificPosition(Node* &head,int position);
void deletionByValueUnique(Node *&head,int value);
Node *reverseNounRecursive(Node* &head);
Node *reverseRecursive(Node* &head);
int  findMid(Node* &head);



void insertAtTail(Node *&head, int val)
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
void insertAtHead(Node *&head, int val)
{
    //s1:newNode creation
    Node * newNode = new Node(val);
    //s2:Update of newnode next
    newNode->Next = head;
    //s3:Update of head
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

int searchByValueUnique(Node *&head,int key)
{
    Node *temp = head;
    int count = 1;

    if(temp == NULL)
    {
        return -1;
    }

    while(temp->value != key)
    {
        if(temp -> Next==NULL)
        {
            return -1;
        }
        temp = temp->Next;
        count++;
    }

    return count;
}

void searchByValueDuplicate(Node *&head,int key)
{
    Node* temp = head;
    int size;
    size = countLength(head);
    int position[size+1], k = 1;
    int count = 1;
    int flag=0;

    while(temp != NULL)
    {
        if(temp->value==key)
        {
            //cout << count <<" ";
            position[k]=count;
            k++;
            flag = 1;

        }
        temp = temp->Next;
        count++;
    }
    if(flag==0)
    {
        cout<<"The Searched Value is not yet in the List"<<endl;
    }
    else
    {
        position[0]=k;
        cout<< "The value is found at Position: ";
        for(int i = 1; i<position[0]; i++)
        {
            cout<< position[i];
            if(i<position[0]-1) cout<<",";
        }
        cout<<endl;
    }
}

Test serchByValueDuplicateReturn(Node *&head,int key)
{
    Node* temp = head;
    Test T;
    int k = 1;
    int count = 1;


    while(temp != NULL)
    {
        if(temp->value==key)
        {
            //cout << count <<" ";
            T.position[k]=count;
            k++;


        }
        temp = temp->Next;
        count++;
    }
    T.position[0]=k;
    return T;
}

void searchByValueUnique(Node *&head,int searchValue,int value)
{
    int position;
    position=searchByValueUnique(head,searchValue);
    insertionAtSpacificPosition(head,position+1,value);
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

void deletionByValueUnique(Node *&head,int value)
{
    int position;
    position = searchByValueUnique(head,value);
    if(position==-1)
    {
        cout<<"value not found in the linkd list"<<endl;
    }
    else
    {
        deletionAtSpecificPosition(head,position);
    }

}

Node *reverseNonRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if(head==NULL)
    {
        cout <<"The Linked List is Empty" << endl;
        return head;
    }

    Node *next = head->Next;

    while(true)
    {
        current->Next = prev;
        prev=current;
        current=next;
        if(current==NULL)
            break;
        next=next->Next;
    }
    return prev;

}

Node *reverseRecursive(Node* &head)
{
    if(head==NULL || head->Next == NULL)
    {
      if(head==NULL) cout <<"The Linked List is Empty" << endl;
        return head;
    }
    Node* newHead = reverseRecursive(head->Next);
    head->Next->Next = head;
    head->Next = NULL;

    return newHead;
}
int  findMid(Node* &head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast->Next!=NULL)
    {
        slow=slow->Next;
        fast=fast->Next->Next;
    }

    return slow->value;
}

void makeCycle(Node* &head,int pos)
{
    Node* temp=head;
    Node* startNode;
    int count = 1;

    while(temp->Next!=NULL)
    {
        if(count==pos)
            startNode=temp;
        temp=temp->Next;
        count++;
    }
    temp->Next=startNode;
}

bool detectCycle(Node * &head)
{
    Node* slow = head;
    Node* fast = head;

     while(fast!= NULL && fast->Next!=NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
        if(slow->Next==fast->Next)
        {
            return true;
        }
    }
    return false;
}


int main()
{
    Node *head = NULL;

    int value,position;

    cout<<"Choice 1: Insertaion at Head" <<endl
        <<"Choice 2: Insertaion at Tail"<< endl
        <<"Choice 3: Insertaion at specific position"<< endl
        <<"Choice 4: Search a value (Unique List)"<< endl
        <<"Choice 5: Search a value (Duplicate enable List)"<< endl
        <<"Choice 6: Insertion after specific value (Unique List)"<< endl
        <<"Choice 7: Delete at Head"<< endl
        <<"Choice 8: Delete at Tail"<< endl
        <<"Choice 9: DeletionAtSpecificPosition"<<endl
        <<"Choice 10:DeleteByValue(Uniqe List) "<<endl
        <<"Choice 11:Reversal of List Non-Recursive "<<endl
        <<"Choice 12:Finding the Mid(Slow Fast Pointer Method "<<endl
        <<"Choice 13:Make a Cycle at k POsition "<<endl
        <<"Choice 14:Detect a Cycle in the List "<<endl
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
        case 3:
            cout<< "Enter the Desired Position: ";
            cin>>position;
            cout<<"Enter the value: ";
            cin>>value;
            insertionAtSpacificPosition(head,position,value);
            break;
        case 4:
            cout<<"Enter the value to Search: ";
            cin>>value;
            position = searchByValueUnique(head,value);
            if(position!=-1)
            {
                cout<< "The number is at Position "<< position <<endl;
            }
            else
            {
                cout<< "The number is not yet the List" << endl;
            }
            break;
        case 5:
            cout<<"Enter the value to Search: ";
            cin>>value;
            //searchByValueDuplicate(head,value);
            Test T;
            T=serchByValueDuplicateReturn(head,value);
            if(T.position[0]==1)
            {
                cout << "The Search value is not yet in the List" << endl;
            }
            else
            {
                int size = T.position[0];
                cout << "The value is found at Position: ";
                for(int i=1; i<size; i++)
                {
                    cout<< T.position[i];
                    if(i<size-1) cout << ",";
                }
                cout<<endl;
            }
            break;
        case 6:
            cout<<"Enter the value to search: ";
            int searchValue;
            cin>>searchValue;
            cout<<"Enter the value to insert: ";
            cin>>value;
            searchByValueUnique(head,searchValue,value);
            break;
        case 7:
            deletionAtHead(head);
            break;
        case 8:
            deletionAtTail(head);
            break;

        case 9:
            if(head==NULL)
            {
                cout<<"There is no value in the linked list" <<endl;
                break;
            }

            cout <<"Enter the Desired Position: ";
            cin>>position;

            deletionAtSpecificPosition(head,position);
//            cout<<endl;
//
//            display(head);
            break;
        case 10:
            cout<<"Enter the value to Delete: ";
            int delvalue;
            cin>>delvalue;
            deletionByValueUnique(head,delvalue);
            break;
        case 11:
            head = reverseNonRecursive(head);
            //reverseNonRecursive(head);
            break;
        case 12:
            int mid;
            mid = findMid(head);
            if(mid== -1)
                cout<< "The LL is empty" << endl;
            else

                cout<<"Mid value is "<<mid<<endl;
            break;
        case 13:
            cout<< "Enter the Desired Position to Create Cycle: ";
            cin>>position;
            makeCycle(head,position);
            break;
        case 14:
            int cycleStatus;
            cycleStatus = detectCycle(head);
            if(cycleStatus==true)
            {
                cout<< "There is a Cycle in the List"<<endl;
            }
            else{
                cout<< "There is No Cycle in the List"<<endl;
            }
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



















