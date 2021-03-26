#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=0 , x=0;
    cin>>n>>x;

    /*int books[n+1];
    int pages[n+1];*/
    vector <int> books(n) , pages(n);
    books[0] = 0;
    pages[0] = 0;

    /*for(int i=1 ; i<=n ; i++){
        scanf("%d ",&books[i] );
    }

    for(int j=1 ; j<=n ; j++){
        scanf("%d ",&pages[j] );
    }*/

    for(int&v : books)cin>>v;
    for(int&v:pages)cin>>v;

    vector<vector<int>>arr(n+1,vector<int>(x+1,0));

    /*for (int i=0 ; i<=n ; i++){
        arr[0][i] = 0;

    }
    for(int i=0 ; i<=x ; i++){
        arr[i][0] = 0;
    }*/

    for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      arr[i][j] = arr[i-1][j];
      int left = j-books[i-1];
      if (left >= 0) {
	arr[i][j] = max(arr[i][j], arr[i-1][left]+pages[i-1]);
      }
    }
  }

    /*for(int i=0;i<=x;i++){
        for(int j=0 ; j<=n ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    cout<<arr[n][x];



    return 0;
}
