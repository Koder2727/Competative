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

    int sums[n];

    for(int &v : sums)cin>>v;

    int sum=0;

    for(auto i:sums){
        sum+=i;
    }

    sort(sums , sums+n);

    vector<vector<int>>arr(n+1,vector<int>(sum+1,0));

    for(int i=0 ; i<n+1 ; i++){
        arr[i][0] = 1;
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=sum ; j++){
            if (j - sums[i-1] >= 0){
                arr[i][j] = max(arr[i-1][j] , arr[i-1][j-sums[i-1]]);
            }
            else{
                arr[i][j] = arr[i-1][j];
            }
        }
    }

    /*for(int i=0 ; i<= n ;i++){
        for(int j=0 ; j<=sum ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/

    int count=0;

    for(int i=1 ; i<= sum;i++){
        if (arr[n][i] == 1){
            count++;
        }
    }

    cout<<count<<endl;
    for(int i=1 ; i<= sum;i++){
        if (arr[n][i] == 1){
            cout<<i<<" ";
        }
    }

    return 0;
}
