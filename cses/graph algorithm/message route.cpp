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
    int n,m;
    cin>>n>>m;

    vector<int>connection[n];
    vector<int>arr(n,INT_MAX);
    vector<int>arr2(n,INT_MAX);

    queue<int>q;
    stack<int>s;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        connection[a-1].push_back(b-1);
        connection[b-1].push_back(a-1);

    }

    arr[0] = 0;

    q.push(0);

    while(!q.empty()){
        int c = q.front();
        q.pop();

        if(c == n-1){
            break;
        }

        int curr = arr[c]+1;

        for(int &i:connection[c]){
            if(arr[i]>curr){
                q.push(i);
                arr[i] = curr;
                arr2[i] = c;
            }
        }
    }
    s.push(n);
    int temp=n-1;

    /*for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0 ; i<n ; i++){
        cout<<arr2[i]<<" ";
    }*/

    if(arr[n-1] == INT_MAX){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<arr[n-1]+1<<endl;

        while(true){
        temp = arr2[temp];

        if(temp == 0){
            break;
        }

        s.push(temp+1);
    }

    s.push(1);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    }

    return 0;
}
