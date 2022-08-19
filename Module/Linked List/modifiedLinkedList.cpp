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
void insertAtTail(Node* &head,int val)// when its not first time we call this function, head is not Null , its the pointer of the previous node
{
    cout<<"here we get head "<<head <<"value"<<val<<endl;
    Node *newNode = new Node(val);
    cout<<"Now we create a newNode calling the constructor and the val as the parameteres of constructor"<<val<<endl;
    cout<<"So the newNode Is"<<endl<<"newNode {"<<endl<<"value :"<<val<<","<<endl<<"Next: NULL"<<endl<<"}"<<endl;
    // newNode {
    //     value : 1,
    //     Next :Null
    // }
    if(head ==NULL)
    {
        cout<<"At the First time head = newNode"<<endl;
        cout<< "means head ="<<"newNode {"<<endl<<"value :"<<val<<","<<endl<<"Next: NULL"<<endl<<"}"<<endl<<"and  its return from the if block and do the further operation"<<endl;

        head = newNode; 
         return; //the first time calling insertAtTail function its return from here and will not do any further operation.
    }
    
    //The codes below will work only when its not the first time we call insertAtTail function
    Node *temp = head;

    while(temp->Next!= NULL) // this code will not work at first time calling insertAtTail funciton.. because,, here temp->Next==Null; 
    { 
        temp = temp->Next;
    }

}
void display(Node* n)
{
    while(n!= NULL){
        cout << n->value;
        if(n->Next!=NULL)
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
        cout <<"Enter the Value: ";//
         cin>>n;
        cout<<"before calling insertAtTail Function "<<"head is"<<head<<endl;
        insertAtTail(head,n);
        cout<<"After calling insertAtTail Function "<<head<<endl;
        cout<<"Do you want to Continue:(Y/N)";
        
        cin>>choice;
    }

    // insertAtTail(head ,1);
    // insertAtTail(head ,5);
    // insertAtTail(head ,8);
    // insertAtTail(head ,9);
    /*Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* forth = new Node();
    */

    // head->value =1;
    // second->value=5;
    // third->value=8;
    // forth->value=9;

    // head->Next =second;
    // second->Next=third;
    // third->Next=forth;
    // forth->Next=NULL;

    display(head);

    return 0;
}
//int a=10;
// int *p = &a;