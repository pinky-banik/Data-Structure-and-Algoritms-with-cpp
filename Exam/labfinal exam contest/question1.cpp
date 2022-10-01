#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
   int t;
   cin>>t;
 
   for(int i = 0 ; i < t; i++){
       int n, c;
       cin>>n>>c;
 
       int arr[n];
        int flag = 0;
       for(int j = 0; j < n; j++){
           cin>>arr[j];
       }
 
       for(int j = 0; j < n; j++){
           c= arr[j]*2;
 
       }
       if(c > 0) flag = 1;
 
 
 
           if(flag == 1){
               cout<<"Yes"<<endl;
           }
           else{
               cout<<"No"<<endl;
           }
   }
 
 
return 0;
}
