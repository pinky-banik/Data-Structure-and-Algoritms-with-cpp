#include<iostream>
using namespace std;
int main(){
    int n;
    int count=0;
    int visited =-1;
    cin>>n;
    int array[n];
    int frequency[n];
    for(int i=0;i<n;i++)
    {
        cin>> array[i];
    }
    for(int i=0;i<n;i++)
    {
        count=1;
       for (int j=i+1;j<n;j++)
       {
        
        if(array[i]==array[j])
        {
            count++;
            frequency[j]=visited;
        }
        
       }
        if(frequency[i] != visited)    
            frequency[i] = count;    
    }  
    for(int i = 0; i < n; i++){    
        if(frequency[i] != visited){    
            cout<<array[i]<<" =>"<<frequency[i]<<endl; 
        }    
    }    
    return 0;
}
