#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,x;
    cin>>m>>x;
    int a[m][x];
    int freq[10]= {0};

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<x; j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<x; j++)
        {
            if(freq[a[i][j]] > 0) a[i][j]=-1;

            else freq[a[i][j]]++;

            cout<<a[i][j]<<" ";
        }
        cout<<endl;

    }
}