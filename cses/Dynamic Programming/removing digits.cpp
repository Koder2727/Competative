/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> digits;

    int n=0;
    cin>>n;
    int arr[n+1];
    arr[0] = 0;
  //  cout<<n;
    for(int i=1 ; i<=n ; i++){
        //cout<<i<<"here";
        digits.clear();
        int num = i;
        arr[i] = INT_MAX;
        //cout<<arr[i-1];
        while(num != 0){
            digits.push_back(num%10);
            num = num/10;
        }
        for(auto j:digits){
           // cout<<j<<" ";
            if (i-j >=0 and j!=0){
                arr[i] = min(arr[i],arr[i-j]+1);
            }
        }
        //cout<<"\n";
    }
    cout<<arr[n];

    return 0;
}
