#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    queue<pair<int,int>>q,ans;
    int n,m;
    cin>>n>>m;

    stack<char>final;

    long long X[] ={-1,1,0,0};
    long long Y[] = {0 , 0 , -1 , 1};

    //int diff=1;
    char arr[1001][1001];

    pair<int,int>start,end;

    vector<vector<int>>number(n,vector<int>(m,INT_MAX));
    vector<vector<char>>steps(n,vector<char>(m,'_'));

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin>>arr[i][j];

            if(arr[i][j] == 'A'){
                start = make_pair(i,j);
            }
            if(arr[i][j] == 'B'){
                end = make_pair(i,j);
            }
        }
    }
    q.push(start);
    number[start.first][start.second]= 0;
    char S[] = {'U','D','L','R'};

    do{
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int curr = number[x][y] + 1;

        for(int i=0 ; i<4 ; i++){
            int a_ = x+X[i];
            int b = y+Y[i];
            //cout<<curr;

            if(a_>=0 && b>=0 && a_<n && b<m && (arr[a_][b] == '.' || arr[a_][b] == 'B')){
                q.push(make_pair(a_,b));
                //cout<<curr;
                if (number[a_][b] > curr){
                    steps[a_][b] = S[i];
                    number[a_][b] = curr;
                }
                arr[a_][b] = '#';
            }
            if (number[end.first][end.second] != INT_MAX){
                break;
            }
        }

    }while(!q.empty());

    /*for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cout<<number[i][j]<<" ";
        }
        cout<<endl;
    }*/

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cout<<steps[i][j]<<" ";
        }
        cout<<endl;
    }

    if (number[end.first][end.second] != INT_MAX){
        cout<<"YES"<<endl<<number[end.first][end.second]<<endl;
        //final.push(steps[end.first][end.second]);

        ans.push(end);

        do{
        int x = ans.front().first;
        int y = ans.front().second;
        //cout<<"hi"<<" ";
        if (ans.front() == start){
            break;
        }
        final.push(steps[x][y]);

        ans.pop();
        int curr = number[x][y] - 1;

        for (int i=3 ; i>=0 ; i--){
            int a_ = x + X[i];
            int b = y + Y[i];

            //cout<<curr;

            if(a_>=0 && b>=0 && a_<n && b<m && curr == number[a_][b]){
                ans.push(make_pair(a_,b));

                break;
                //cout<<curr;
                //arr[a_][b] = '#';
            }

        }

    }while(!ans.empty());

    while(!final.empty()){
        cout<<final.top();
        final.pop();
    }

    }

    else{
        cout<<"NO";
    }
    return 0;
}
