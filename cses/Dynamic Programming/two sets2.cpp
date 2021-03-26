/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=0;
    cin>>n;

    int y = (n*(n+1)/2);

    if(y%2 != 0){
        cout<<0;
        return 0;
    }
    y = y/2;

    vector<vector<int>>arr(n,vector<int>(y+1,0));

    arr[0][0] = 1;

    for(int i=1 ; i<n;i++){
        for(int j=0 ; j<=y ; j++){
            if(j-i>=0){
                arr[i][j] = (arr[i-1][j] + arr[i-1][j-i])%1000000007;
            }
            else{
                arr[i][j] = arr[i-1][j];
            }
        }
    }

    cout<<arr[n-1][y];

    return 0;
}
