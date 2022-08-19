// #include<iostream>
// using namespace std;
// int main(){
//     int n ,m;
//     cin>>n;
//     int array1[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>array1[n];
//     }
//     cin>>m;
//     int array2[m];
//     for(int i=0;i<m;i++)
//     {
//         cin>>array2[m];
//     }
//     int result[n];
//     for(int i=0, j=0;i<n,j<m;i++,j++)
//     {
//         if(array1[i]!=array2[j])
//         {
//             result[i]==array1[i];
//         }

//     }
//     for(int i=0;i<n;i++)
//     {
//         cout<<result[i]<<' ';
//     }

// }

#include <bits/stdc++.h>
using namespace std;
void relativeComplement(int arr1[], int arr2[],
                               int n, int m) {
 
  int i = 0, j = 0;
  while (i < n && j < m) {
 
    // If current element in arr2[] is
    // greater, then arr1[i] can't be
    // present in arr2[j..m-1]
    if (arr1[i] < arr2[j]) {
      cout << arr1[i] << " ";
      i++;
 
    // Skipping smaller elements of
    // arr2[]
    } else if (arr1[i] > arr2[j]) {
      j++;
 
    // Equal elements found (skipping
    // in both arrays)
    } else if (arr1[i] == arr2[j]) {
      i++;
      j++;
    }
  }
 
  // Printing remaining elements of
  // arr1[]
  while (i < n)
    cout << arr1[i] << " "; 
}
 
// Driver code
int main() {
    int n ,m;
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    cin>>m;
    int arr2[m];
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
  sort(arr1,arr1+n);
  sort(arr2,arr2+m);
  relativeComplement(arr1, arr2, n, m);
  return 0;
}