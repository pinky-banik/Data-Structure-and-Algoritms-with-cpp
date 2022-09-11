#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int val;
    node* next;
    node* prev;
    node(int data)
    {
        this->val = data;
        this->next = NULL;
        this->prev = NULL;
    }
};


void insertAtHead(node* &head, int data)
{
    node* newNode = new node(data);

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(node* &head, int data)
{
    node* newNode = new node(data);

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

int searchUniqueList(node* head, int key)
{
    int i = 0;
    while(head != NULL)
    {
        ++i;
        if(head->val==key)
        {
            return i;
        }
        head = head->next;
    }
    return -1;
}

int countLength(node* head)
{
    int count = 0;
    while(head != NULL)
    {
        ++count;
        head = head->next;
    }
    return count;
}


void insertAtSpecificPosition(node* &head, int position, int check)
{
    node* newNode = new node(check);
    int size = countLength(head);
    if(position < 1 || position > size + 1)
    {
        return;
    }

    if(position == 1)
    {
        insertAtHead(head,check);
    }
    else if(position == size+1)
    {
        insertAtTail(head,check);
    }
    else
    {
        int i = 0;
        node* temp = head;
        while(i < position - 2)
        {
            ++i;
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next->prev = newNode;
    }
}

void insertAfterSpecificValue(node* &head, int value, int check)
{
    int position = searchUniqueList(head, value);
    insertAtSpecificPosition(head, position + 1, check);
}

void insertBeforeSpecificValue(node* &head, int value, int check)
{
    int position = searchUniqueList(head, value);
    insertAtSpecificPosition(head, position, check);
}
void display(node* head)
{
    while(head != NULL)
    {
        cout << head->val;
        if(head->next != NULL)
        {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node* head = new node(1);
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;
    if(a!=0)
    {
        insertBeforeSpecificValue(head, 1, a);
    }
    if(b != 0)
    {
        insertAfterSpecificValue(head, 1, b);
    }
    for(int i = 2; i <= n; i++)
    {
        if(searchUniqueList(head, i) == -1)
        {
            insertAtHead(head, i);
        }
        cin >> a >> b;
        node* temp = head;
        while(temp->val != i)
        {
            temp = temp->next;
        }
        if(a != 0)
        {
            if(temp->prev == NULL || temp->prev->val!= a)
                insertBeforeSpecificValue(head,i,a);
        }
        if(b != 0)
        {
            if(temp->next==NULL || temp->next->val!=b)
                insertAfterSpecificValue(head,i,b);
        }
    }
    for(int i=1; i<=n; i++)
    {
        node* temp=head;
        while(temp->val != i)
        {
            temp = temp->next;
        }
        if(temp->prev == NULL)
        {
            cout<<"0 ";
        }
        else cout<<temp->prev->val<< " ";
        if(temp->next==NULL)
        {
            cout<<"0";
        }
        else cout<<temp->next->val<<endl;
    }
    return 0;
}


