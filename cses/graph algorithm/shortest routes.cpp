/******************************************************************************

                              we will use bellman ford alogorithm

*******************************************************************************/

#include <bits/stdc++.h>

long n,m;
using namespace std;

int main()
{

    cin>>n>>m;
    /*tuple<int ,int ,int>edges[m];

    for(int i=0 ; i<m ; i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges[i] = make_tuple(a,b,w);

    }*/

    vector<pair<long,long>>adj[n];

    /*int arr[n];

    for(int k=0 ; k<n;k++){
        arr[k] = INT_MAX;
    }

    arr[0] = 0;
    for(int i=0 ; i<n-1 ; i++){
        for(auto j : arr){
        cout<<j<<" ";
        }
        cout<<endl;
        for(auto e : edges){
            int a,b,w;
            tie(a,b,w) = e;

            if (arr[a-1] != INT_MAX){
                arr[b-1] = min(arr[b-1] , arr[a-1]+w);
            }
        }
    }

    */

    for(int j=0 ; j<m ; j++){
        long a,b,w;
        cin>>a>>b>>w;

        adj[a-1].push_back( make_pair(b-1,w));
    }

    priority_queue<pair<long,long>>q;
    long distance[n];
    bool processed[n] = {false};
    for(int j=0;j<n;j++){
        distance[j] = LONG_MAX;
    }

    distance[0]=0;
    q.push(make_pair(0,0));

    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        if (processed[a]){
            continue;
        }
        processed[a] = true;
        for(auto e : adj[a]){
            long b = e.first , w = e.second;

            if(distance[a]+w < distance[b]){
                distance[b] = distance[a]+w;
                q.push(make_pair(-distance[b], b));
            }
        }
    }

    for(auto j:distance){
        cout<<j<<" ";
    }
    cout<<endl;

    return 0;
}
