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
    string s1,s2;
    cin>>s1>>s2;
    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>>arr(n1,vector<int>(n2,0));
    int test=0;
    if (s1[0] == s2[0]){
        arr[0][0] = 0;
        test=1;
    }
    else{
        arr[0][0] = 1;
    }
    for(int i=1 ; i<n1 ; i++){
        if (s1[i] == s2[0] && test == 0){
            arr[i][0] = arr[i-1][0];
            test=1;
        }
        else{
            arr[i][0] = 1+arr[i-1][0];
        }
    }
    test=0;

    if (s1[0] == s2[0]){
        arr[0][0] = 0;
        test=1;
    }
    else{
        arr[0][0] = 1;
    }


    for(int i=1 ; i<n2 ; i++){
        if (s2[i] == s1[0] && test == 0){
            arr[0][i] = arr[0][i-1];
            test = 1;
        }
        else{
            arr[0][i] = 1+arr[0][i-1];
        }
    }

    for(int i=1 ; i<n1 ; i++){
        for(int j=1 ; j<n2 ; j++){
            if (s1[i] == s2[j]){
                arr[i][j] = arr[i-1][j-1];
            }
            else{
                 int k = min(arr[i-1][j]+1 , arr[i][j-1]+1);
                 arr[i][j] = min(arr[i-1][j-1]+1 , k);
            }
        }
    }

    cout<<arr[n1-1][n2-1];

    return 0;
}
