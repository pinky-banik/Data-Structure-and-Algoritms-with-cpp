#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,d,q;
    cin>>t;
    while(t--)
    {
        cin>>d;
        int income[d];
        int spent[d];
        for(int i=0;i<d;i++)
        {
            cin>>income[i];
        }
        for(int i=0;i<d;i++)
        {
            cin>>spent[i];
        }
        cin>>q;
        int query[q];
        int result[q];
        int sum =0;
        for(int i=0;i<q;i++)
        {
            cin >>query[i]; //input the queries done here
        }
        for(int i=0;i<q;i++)
        {
            sum =0;
            // cout<<"at query=>"<<query[i]<<endl;
            for(int j=0;j<=query[i];j++)
            {
                // cout << "at query "<<query[i]<<" of day "<<j<<endl;
                // cout<<"sum =>"<<sum<<'+'<<income[j]<<'-'<<spent[j]<<endl;
                sum =sum+(income[j]-spent[j]);
                // cout<<"value of sum =>"<<sum<<endl;
            }
            if(sum<0)
            {
                result[i]=0;
            }
            else
            {
                result[i]=1;
            }
        }
        for(int i=0;i<q;i++)
        {
            cout<<result[i]<<' ';
        }
    }
    return 0;

}
