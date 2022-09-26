#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node *next;

        // constructor creation
        Node(int val) {
            value = val;
            next = NULL;
        }
};

void display(Node *n) {
    while(n != NULL) {
        cout << n->value;
        if (n->next != NULL) cout << "--> ";
        n = n->next;
    }
    cout << endl;
}

int countLength(Node* &head){
    int count = 0;
    Node * temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    } 
    return count;
}


void insertion_at_tail(Node* &head, int value) {
    Node *new_node = new Node(value);
    
    if (head == NULL) {
        head = new_node;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertion_at_head(Node* &head, int val) {
    // step: 1 -> new node creation
    Node *new_node = new Node(val);

    // step: 2 -> update new node next
    new_node->next = head;

    // step: 3 -> update to head
    head = new_node;
}

insertion_at_specific_position(Node* &head)
{
  
}

int main() {
    Node *head = NULL;

    int value;
    
    cout << "Choice 1: Insertion at Head" << endl << "Choice 2: Insertion at tail" << endl << "Choice 3: Exit" << endl;

    int choice = 2;

    while(choice != 0) {
        switch (choice)
        {
        case 1:
          cout << "Enter the value: ";
          cin >> value;
          insertion_at_head(head,value);
          break;
        case 2:
          cout << "Enter the value: ";
          cin >> value;
          insertion_at_tail(head,value);
          break;
        case 3:
          cout << "Enter the value: ";
          cin >> value;
          insertion_at_tail(head,value);
          break;
        default:
          break;
        }
        display(head);
        cout << "Next Choice: (1/2) ";
        cin >> choice;
    }
    cout << "Linked list : ";
    display(head);
    cout <<"Length of the list : " << countLength(head) << endl;
    return 0;
}