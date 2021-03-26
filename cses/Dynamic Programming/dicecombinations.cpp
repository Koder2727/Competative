#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n=0;
    cin>>n;

    //initialize the dice array
    int dice[6] = {1,2,3,4,5,6};

    //array to store value of number of ways of getting sum n
    long int value[n+1];

    //one way to take nothing
    value[0] = 1;

    for(int i=1;i<=n;i++){

        value[i] = 0;

        for (auto c:dice){
            if(i-c >=0){
                value[i] += (value[i-c]%1000000007);
            }
        }
    }

    cout<<value[n]%1000000007;

    return 0;
}
