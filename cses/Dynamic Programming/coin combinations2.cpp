/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int n=0,x=0;
    cin>>n>>x;
    //n is number of rows x is number of coloumns
    long int coins[n];

    vector<vector<int>>dp(n+1,vector<int>(x+1,0));

    for(long int i=0;i<n;i++){
        cin>>coins[i];
    }

    //sort(coins,coins+n);

    //long int dp[n+1][x+1];

    for (long int i=0 ; i<n;i++){
        dp[i+1][0] = 1;
    }

    for(long int i=0;i<x+1;i++){
        dp[0][i] = 0;
    }

    for (long int i=1;i<=n;i++){
        for (long int j=1 ; j<x+1 ; j++){
            dp[i][j] = 0;
            if (j - coins[i-1] < 0){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = (dp[i-1][j] + dp[i][j-coins[i-1]])%1000000007;
            }
        }
    }

    /*for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=x ; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/

    cout<<dp[n][x];

    return 0;
}
