/******************************************************************************

                              We will use floyld-marshall algorithm

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<long>>adj(n,vector<long>(n,LONG_MAX));
    vector<vector<long>>dist(n,vector<long>(n,LONG_MAX));

    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;

        if (adj[a-1][b-1] > w){
        adj[a-1][b-1] = w;
        adj[b-1][a-1] = w;
        }

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (i == j) dist[i][j] = 0;
            else if(adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = LONG_MAX;
        }
    }

    for(int k=0 ; k< n ;k++){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(dist[i][k] != LONG_MAX && dist[k][j] != LONG_MAX)
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
            }
        }
    }

    //tkaing queries
    for(int i=0 ; i<q ; i++){
        int q1,q2;
        cin>>q1>>q2;
        if(dist[q1-1][q2-1] != LONG_MAX)
            cout<<dist[q1-1][q2-1]<<endl;
        else
            cout<<-1<<endl;
    }






    return 0;
}
