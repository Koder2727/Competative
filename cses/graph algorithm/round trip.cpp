
#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int>g[100001];
vector<int>parents(100001,-1);
vector<bool>visited(100001,0);
int sv=-1,ev=-1;

bool dfs(int i , int parent){
    //cout<<"IN dfs "<<parent<<" "<<i<<endl;
    visited[i] = 1;
    parents[i] = parent;

    for(auto j : g[i]){
        if(j == parent){
            continue;
        }

        if (visited[j]){
          sv = j;
          ev = i;
          return 1;
        }

        if (!visited[j]){
            if(dfs(j,i)){
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    cin>>n>>m;
    bool cycle =0;
    for(int i=0 ; i<m ; i++){
        int a , b;
        cin>>a>>b;
        //cout<<a<<" "<<b<<endl;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    /*for(int i=0 ; i<n ; i++){
        cout<<visited[i]<<" ";
    }*/
    //cout<<endl;
    for(int i=1 ; i<=n ; i++){
        if (!visited[i]){
           // cout<<"HEre "<<endl;
            cycle = dfs(i,-1);
            if (cycle)
                break;
        }
    }

    /*for(int i=0 ; i<n ; i++){
        cout<<parents[i]<<" ";
    }*/
    //cout<<endl;
    //cout<<sv<<" "<<ev;
    if(sv != -1 && ev != -1){
        int tv = ev;
        vector<int>ans;
        ans.push_back(tv);
        while(tv!=sv){
            ans.push_back(parents[tv]);
            tv = parents[tv];
        }
        ans.push_back(ev);
        cout<<ans.size()<<endl;
        for(auto k : ans){
            cout<<k<<" ";
        }
        cout<<endl;
    }
    else{
      cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
