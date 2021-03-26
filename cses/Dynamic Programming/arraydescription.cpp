
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long int mod = 1e9 + 7;
    int n,m;
    cin>>n>>m;

    vector<vector<int>> arr(n,vector<int>(m+1,0));

    int x0;
    cin>>x0;

    if (x0==0){
        fill(arr[0].begin() , arr[0].end() , 1);
    }
    else{
        arr[0][x0] = 1;
    }

    for(int i=1 ; i<n ; i++){
        int x;
        cin>>x;

        if(x==0){
            for(int j=1 ; j<=m ; j++){
                for(auto k : {j-1,j,j+1}){
                    if(k>=1 && k<=m){
                        (arr[i][j] += arr[i-1][k]) %= mod;
                    }
                }
            }
        }
        else{
            for(auto k : {x-1,x,x+1}){
                if(k>=1 && k<=m){
                    (arr[i][x] += arr[i-1][k]) %= mod;
                }
            }
        }

    }
    int ans=0;

    for(int i=1 ; i<= m ;i++){
        (ans += arr[n-1][i]) %= mod;
    }
    cout<<ans;

    return 0;
}
