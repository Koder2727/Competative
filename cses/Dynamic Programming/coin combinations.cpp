
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n=0,x=0;
    cin>>x>>n;

    int dice[x];

    for(int i=0 ; i<x ; i++){
        cin>>dice[i];
    }

    long long value[n+1];

    value[0] = 1;
    for(int i=1;i<=n;i++){

        value[i] = 0;

        for (auto c:dice){
            if(i-c >=0){
                value[i]+=(value[i-c]%1000000007);
            }
        }
    }

    cout<<value[n]%(1000000007);

    return 0;
}
