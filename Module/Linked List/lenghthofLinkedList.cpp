int countLength(Node* &head){
    int count =0;
    Node* temp =head;
    while(temp != NULL){
        count++;
        temp= temp->Next;
    }
    return count;
}


int main()
{
    countLength(head);
}