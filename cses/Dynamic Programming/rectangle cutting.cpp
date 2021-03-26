/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int k = INT_MAX;

    vector<vector<int>>arr(a,vector<int>(b,k));

    for(int i=0 ; i<a;i++){
        arr[i][0] = i;
    }

    for(int i=0;i<b;i++){
        arr[0][i] = i;
    }

    for(int i=0 ; i<a;i++){
        for(int j=0 ; j<b ; j++){

            if (i==j){
                arr[i][j] = 0;
            }
            else{

                for(int k=0 ; k< i ; k++){
                    arr[i][j] = min(arr[i][j] , (arr[i-k-1][j]+1+arr[k][j]));
                }

                for(int l=0 ; l<j ; l++){
                    arr[i][j] = min(arr[i][j] , (arr[i][j-l-1]+1+arr[i][l]));
                }
            }

        }
    }

    /*for(int i=0 ; i<a ; i++){
        for(int j=0 ; j<b ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/

    cout<<arr[a-1][b-1];



    return 0;
}
