/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n=0;
    cin>>n;

    int dice[6] = {1,2,3,4,5,6};

    long int value[n+1];

    //no way to not take anything
    value[0] = 1;
    for(int i=1;i<=n;i++){

        value[i] = 0;

        for (auto c:dice){
            if(i-c >=0){
                value[i]+=(value[i-c]%1000000007);
            }
        }
    }

    cout<<value[n]%1000000007;

    return 0;
}
