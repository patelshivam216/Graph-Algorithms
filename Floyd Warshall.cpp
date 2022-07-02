#include<bits/stdc++.h>
using namespace std;
int const N=510;


int main(){
    int n,m;// vertex and edges
    cin>>n>>m;
    int dist[N][N];

    // Intialization for dp/dist array
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=1e3;
        }
    }


    // Ip for graph considering 2D graph
    for(int i=0;i<m;i++){

        int u,v,wt;
        cin>>u>>v>>wt;
        dist[u][v]=wt;

    }

    //floyd warshall algo 1-Base indexing 
    for(int k=1;k<=n;k++){

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min( dist[i][j] , dist[i][k] + dist[k][j] );
            }
        }

    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] != 1e3)
            cout<<"distance from "<<i<<" to "<<j<<" is "<<dist[i][j]<<endl;

        }
    }

/*

6 9
1 2 1 
1 3 5 
2 3 2 
3 5 2 
2 5 1 
2 4 2 
4 5 3 
4 6 1 
5 6 2 

*/



    return 0;
}
