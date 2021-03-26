/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#include <climits>

using namespace std;
vector<int>adj_dfs[2500];
vector<int>adj_dfs2[2500];
void dfs(int s , vector<bool>&visited){
    if(visited[s]){
        return;
    }
    visited[s] = 1;
    //cout<<s<<" "<<visited[s]<<endl;
    for(auto a:adj_dfs[s]){
        dfs(a,visited);
    }
    return;
}
void dfs2(int s , vector<bool>&visited1){
    if(visited1[s]){
        return;
    }
    visited1[s] = 1;
    //cout<<s<<" "<<visited1[s]<<endl;
    for(auto a:adj_dfs2[s]){
        dfs2(a,visited1);
    }
    return;
}
int main()
{
    int n,m;
    cin>>n>>m;

    tuple<int,int,long>adj[m];

    for(int i=0 ; i<m;i++){
        int a,b;
        long w;
        cin>>a>>b>>w;
        adj[i] = make_tuple(a-1,b-1,w);
        adj_dfs[b-1].push_back(a-1);
        adj_dfs2[a-1].push_back(b-1);
    }
    /*for(int i=0 ; i<n ;i++){
        for(auto a:adj_dfs2[i]){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    for(int i=0 ; i<n ;i++){
        for(auto a:adj_dfs[i]){
            cout<<a<<" ";
        }
        cout<<endl;
    }*/
    //Run the bellman ford n-1 times
    vector<long>dist(n,LONG_MIN);
    dist[0]=0;

    for(int i=0;i<n-1 ; i++){
        for(auto e : adj){
            int a,b;
            long w;
            tie(a,b,w) = e;
            if(dist[a] != LONG_MIN){

                dist[b] = max(dist[b],dist[a]+w);
                /*for(int i=0 ; i<n ;i++){
                    cout<<dist[i]<<" ";
                }*/
                //cout<<endl;
            }
        }
    }

    //run the bellman ford for nth time
    bool changed[n] = {0};
    bool change=0;

    for (auto e:adj){
        int a,b;
        long w;
        tie(a,b,w) = e;

        if(dist[b] < dist[a]+w){
            changed[b] = 1;
            change = 1;
        }

    }

    /*for(int i=0 ; i<n ;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;*/

    /*for(int i=0 ; i<n ;i++){
        cout<<changed[i]<<" ";
    }
    cout<<endl;*/



    if(change){
        //run dfs on the last node
        vector<bool>visited(n,0);
        vector<bool>visited1(n,0);

        dfs(n-1 , visited);
        dfs2(0,visited1);

        /*for(int i=0 ; i<n ;i++){
            cout<<visited[i]<<" ";
        }
        cout<<endl;
        for(int i=0 ; i<n ;i++){
            cout<<visited1[i]<<" ";
        }
        cout<<endl;*/
        for(int i=0 ; i<n;i++){
            if(changed[i] == 1 && visited[i] == 1 && visited1[i] == 1){
                cout<<-1<<endl;
                return 0;
            }
        }

        //cout<<endl;
    }
    cout<<dist[n-1]<<endl;


    return 0;
}
