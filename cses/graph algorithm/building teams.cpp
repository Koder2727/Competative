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
    int arr[n] = {0};
    bool visited[n] = {false};

    int total = 0;

    queue<int>q1,q2;

    for(int i=0 ; i<m ; i++){
        int a,b;

        cin>>a>>b;
        connection[a-1].push_back(b-1);
        connection[b-1].push_back(a-1);

    }

    q1.push(0);
    arr[0] = 1;
    visited[0] = true;

    while(!q1.empty() || !q2.empty()){

        while(!q1.empty()){
            int c = q1.front();
            q1.pop();

            for(int &i:connection[c]){
                if (visited[i] == false){
                    visited[i] = true;
                    q2.push(i);
                    arr[i] = 2;
                }
                else if(visited[i] == true){
                    if(arr[i] == 1){
                        cout<<"IMPOSSIBLE"<<endl;
                        return 0;
                    }
                }
            }
        }

        while(!q2.empty()){

            int c = q2.front();
            q2.pop();

            for(int &i:connection[c]){
                if (visited[i] == false){
                    visited[i] = true;
                    q1.push(i);
                    arr[i] = 1;
                }
                else if(visited[i] == true){
                    if(arr[i] == 2){
                        cout<<"IMPOSSIBLE"<<endl;
                        return 0;
                    }
                }
            }

        }
    }


    for(int j=0;j<n;j++){
        if(!visited[j]){
            q1.push(j);
            visited[j] = true;
            arr[j] = 1;

            while(!q1.empty() || !q2.empty()){

                while(!q1.empty()){
                    int c = q1.front();
                    q1.pop();

                    for(int &i:connection[c]){
                        if (visited[i] == false){
                            visited[i] = true;
                            q2.push(i);
                            arr[i] = 2;
                        }
                        else if(visited[i] == true){
                            if(arr[i] == 1){
                                cout<<"IMPOSSIBLE"<<endl;
                                return 0;
                            }
                        }
                    }
                }

                while(!q2.empty()){

                    int c = q2.front();
                    q2.pop();

                    for(int &i:connection[c]){
                        if (visited[i] == false){
                            visited[i] = true;
                            q1.push(i);
                            arr[i] = 1;
                        }
                        else if(visited[i] == true){
                            if(arr[i] == 2){
                                cout<<"IMPOSSIBLE"<<endl;
                                return 0;
                            }
                        }
                    }

                }
            }


        }
    }


    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
