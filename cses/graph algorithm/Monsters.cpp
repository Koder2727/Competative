#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>>monsters;
vector<vector<int>>g(1000,vector<int>(1000,INT_MAX));
map<pair<int,int>,pair<int,int>>par_mp;
vector<pair<int,int>>moves = {{-1,0},{1,0},{0,1},{0,-1}};
pair<int,int>si , se;

int n,m;
bool isValid(int x, int y , int timer){
    if(x<0 || y<0 || x>=n || y>= m ){
        return false;
    }
    if(g[x][y] <= timer || (si.first == x && si.second == y)){
        return false;
    }
    return true;
}

bool Escape(int x, int y , int timer){
    if (!isValid(x,y,timer)){
        return false;
    }
    if(x==0 || y==0 || x == n-1 || y == m-1){
        return true;
    }
    return false;
}

void Preprocess_lava_flow(){
    queue<pair<pair<int,int> , int>>q;

    for (auto m : monsters){
        q.push(make_pair(m , 0));
    }

    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int timer = q.front().second;
        q.pop();
        timer++;

        for(auto mv : moves){
            int tx = cx+mv.first;
            int ty = cy + mv.second;

            if(isValid(tx,ty,timer)){
                g[tx][ty] = timer;
                q.push({{tx,ty},timer});
                /*for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        cout<<g[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;*/
            }
        }
    }
}

bool Plan_Escape(){
    //cout<<"hare";
    queue<pair<pair<int,int>,int>>q;
    q.push(make_pair(si,0));
    par_mp[si] = make_pair(-1,-1);
    //cout<<si.first<<" "<<si.second<<" ";
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int timer = q.front().second;
        q.pop();
        timer++;


        for(auto mv:moves){
            int tx = cx+mv.first;
            int ty = cy+mv.second;

            if(Escape(tx,ty,timer)){
                par_mp[make_pair(tx,ty)]={cx,cy};
                se = {tx,ty};return true;
            }
            if(isValid(tx,ty,timer)){
                if(par_mp[{cx,cy}] != make_pair(tx,ty)){
                    par_mp[{tx,ty}]={cx,cy};
                //g[tx][ty] = timer;
                q.push({{tx,ty},timer});
                }
            }
        }
    }
    return false;
}

int main()
{
    //vector<int>v1 = {};

    //int n ,m;
    cin>>n>>m;
    //cout<<n<<m<<" ";
    for(int i=0 ; i<n ; i++){

        for(int j=0 ; j<m ; j++){
            char a;
            //cout<<a;
            cin>>a;
        //    cout<<"ok";
            if(a=='#'){
                g[i][j] = 0;
            }
            if(a == '.'){
                g[i][j] = INT_MAX;
            }
            if(a == 'A'){
                si = make_pair(i,j);
            }
            if(a == 'M'){
                monsters.push_back(make_pair(i,j));
            }
        }
    }

    if (si.first ==0 || si.first == n-1 || si.second == 0 || si.second == m-1){
        cout<<"YES"<<endl;
        cout<<0;
        return 0;
    }

    bool ans=0;
    //cout<<"hore";
    Preprocess_lava_flow();
    ans=Plan_Escape();
    //cout<<g[0][0]<<n<<m;
    //cout<<"Heer";

    if(ans){
        cout<<"YES"<<endl;
        vector<char>final;

        pair<int,int>curr=par_mp[se];
        stack<char>s;
        int diff_1[] = {1,0,-1,0};
        int diff_2[] = {0,-1,0,1};
        char step[] = {'D','L','U','R'};
        pair<int,int>prev = se;
        //cout<<par_mp[make_pair(1,2)].first;
        while(curr != make_pair(-1,-1)){


            int diff_11 = prev.first - curr.first;
            int diff_22 = prev.second - curr.second;
            /*cout<<prev.first<<curr.first<<prev.second<<curr.second;
            cout<<diff_11<<" "<<diff_22<<endl;
            cout<<par_mp[curr].first<<" "<<par_mp[curr].second<<endl;*/
            for (int k=0;k<4;k++){
                if(diff_11 == diff_1[k] && diff_22==diff_2[k]){
                    s.push({step[k]});
                    break;
                }
            }
            prev = curr;
            curr = par_mp[curr];



        }
        cout<<s.size()<<endl;
        while(!s.empty()){
            cout<<s.top();
            s.pop();
        }
        cout<<endl;


        /*for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }*/

        //cout<<"finished";
    }
    else{
        cout<<"NO";
    }

    return 0;
}
