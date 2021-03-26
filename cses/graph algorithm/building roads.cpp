/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
/*void dfs(int n){
    visited[n] = true;

    for(&i : connection[n]){
        if(!visited[i]){
            dfs(i);
        }
    }
}*/

using namespace std;

int main()
{
    int n,roads;
    int counnt=0;
    vector<int>ans;
    cin>>n>>roads;

    queue<int>q;

    vector<int>connection[n];
    vector<bool>visited(n,0);

    for(int i=0 ; i<roads ; i++){
        int a=0,b=0;
        cin>>a>>b;

        connection[a-1].push_back(b-1);
        connection[b-1].push_back(a-1);
    }

    for(int j=0;j<n;j++){
        if(!visited[j]){
            q.push(j);

            while(!q.empty()){
                int k=q.front();
                q.pop();
                visited[k] = true;

                for(int &i : connection[k]){
                    if(!visited[i]){
                        q.push(i);
                    }
                }

            }

            ans.push_back(j);
            counnt++;
        }
    }

    cout<<counnt-1<<endl;

    for(int i=0 ; i<counnt-1;i++){
        cout<<ans[i]+1<<" "<<ans[i+1]+1<<endl;
    }

    return 0;
}
