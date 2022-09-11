#include <bits/stdc++.h>
using namespace std;

//Tree node structure
class treeNode{
public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;

    treeNode(int value){
        data=value;
        leftChild=NULL;
        rightChild=NULL   ;
    }
};
void printTree(treeNode* root,int level);
void spacePrint(int level);
/*
Root : 0
Left : 
    Root:1
    Left:3
    Right:4
Right:
    Root:5
        Left:7
        Right:8
    Right:6

*/
void printTree(treeNode* root,int level)
{
    if(root==NULL){ // when the tree is empty
        return;
    }
    if(root->leftChild==NULL && root->rightChild==NULL){ //case 1
        cout<<root->data<<endl;
        return;
    }
    else{ //case 2
        cout<<endl;
        spacePrint(level);
        cout <<"Root: "<<root->data<<endl;
    }
    if(root->leftChild!=NULL){ //handle left child
        spacePrint(level);
        cout<<"Left: ";
        printTree(root->leftChild,level+1);
    }
    
    if(root->rightChild != NULL) //handle right child
    {
        spacePrint(level);
        cout<<"Right: ";
        printTree(root->rightChild,level+1);
    }
    

}

void spacePrint(int level){
    for(int i=0;i<level;i++)
    {
        cout << "   ";
    }
}

int main(){
    // treeNode* n1 = new treeNode(0);
    // treeNode* n2 = new treeNode(1);
    // n1->leftChild=n2;
    //-------------------------
    int n;
    cin>>n;
    treeNode *allNodes[n];
    for(int i =0;i<n;i++){
        allNodes[i]= new treeNode(-1);
    }

    for(int i=0;i<n;i++)
    {
        int value,left,right;
        cin>>value>>left>>right;
        allNodes[i]->data=value;
        if (left>n-1 || right>n-1)
        {
            cout<<"Input Index"<<endl;
            break;1
        }
        if(left!=-1)
        {
            allNodes[i]->leftChild=allNodes[left];
        }
        if(right!=-1){
            allNodes[i]->rightChild=allNodes[right];
        }
    }
    printTree(allNodes[0],0);
    return 0;
}

/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

Root : 0
Left : 
    Root:1
    Left:3
    Right:4
Right:
    Root:5
        Left:7
        Right:8
    Right:6

*/