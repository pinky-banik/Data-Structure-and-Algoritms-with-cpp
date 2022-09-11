#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
	Node(int val)
    {
        data = val;
        next = NULL;
    }
};


/* Function to print linked list */
void printList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout<<temp->data;
		if(temp->next!=NULL)
            cout<<" => ";
		temp = temp->next;
	}
	cout<<endl;
}

void skip_and_delete(Node *head, int M, int N)
{
	Node *current = head, *t;
	int count;


	while (current)
	{
		// Skip M nodes
		for (count = 1; count < M &&
				current!= NULL; count++)
			current = current->next;

		// If we reached end of list, then return
		if (current == NULL)
			return;

		// Start from next node and delete N nodes
		t = current->next;
		for (count = 1; count<=N && t!= NULL; count++)
		{
			Node *temp = t;
			t = t->next;
			free(temp);
		}
		
		// Link the previous list with remaining nodes
		current->next = t;

		// Set current pointer for next iteration
		current = t;
	}
}
void insertValue(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if(head==NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=newNode;
}

int main()
{
	Node* head = NULL;
	int k,value,m,n;
    cin>>k>>m>>n;
	while(k--)
    {
        cin>>value;
        insertValue(head,value);
    }
	skip_and_delete(head, m, n);

	printList(head);

	return 0;
}

