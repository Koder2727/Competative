/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int n=0;
    cin>>n;
    long int arr[n][n];
    char s;
    for(int i=0;i<n;i++){
        for(int j=0 ; j<n ; j++){
            cin>>s;
            if (i==0 && j==0 && s=='*'){
              arr[n-1][n-1]=0;
              goto label;
            }
            if (s != '*'){
                if (i == 0){
                    if(j==0){
                        arr[i][j] = 1;
                    }
                    else if (arr[i][j-1] == 0){
                        arr[i][j] = 0;
                    }
                    else{
                        arr[i][j] = 1;
                    }
                }
                else if (j==0){
                    if(i==0){
                        arr[i][j] = 1;
                    }
                    else if (arr[i-1][j] == 0){
                        arr[i][j] = 0;
                    }
                    else{
                        arr[i][j] = 1;
                    }
                }
                else{
                    arr[i][j] = (arr[i-1][j] + arr[i][j-1])%1000000007;
                }
            }
            else{
                arr[i][j] = 0;
            }
        }
    }
    label:
      cout<<arr[n-1][n-1];

    return 0;
}
