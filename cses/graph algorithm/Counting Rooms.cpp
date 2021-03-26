

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    queue<pair<int,int>>a;
    int n,m;
    cin>>n>>m;

    long long X[] ={-1,1,0,0};
    long long Y[] = {0 , 0 , -1 , 1};

    int diff=1;

    //vector<vector<char>>arr(n,vector<char>(m));
    //vector<vector<int>>visited(n,vector<int>(m,0));
    char arr[1000][1000];
    //bool visited[1000][1000] = {false};

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin>>arr[i][j];
        }
    }

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){

                if ( arr[i][j] == '.'){
                a.push(make_pair(i,j));

                while(!a.empty()){
                    int x = a.front().first;
                    int y = a.front().second;
                    a.pop();

                    //cout<<a.size()<<" "<<x<<" "<<y<<"\n";

                    for(int i=0 ; i<4 ; i++){
                        int a_ = x+X[i];
                        int b = y+Y[i];

                        if(a_>=0 && b>=0 && a_<n && b<m && arr[a_][b] == '.'){
                            a.push(make_pair(a_,b));
                            arr[a_][b] = '#';
                        }
                    }

                }
                //cout<<"change here ";
                diff++;
            }

        }
    }
    cout<<diff-1<<"\n";
    return 0;
}
