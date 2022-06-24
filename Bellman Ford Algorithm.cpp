// bellman ford algorithm 
// is NOT working with negative cycle 
// need to be directed graph

#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,m;
    cin>>n>>m;

    vector<int> dist(n+1,1e9);
    dist[0]=0;

    vector<vector<int>> edges;

    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        vector<int> temp(3);

        temp[0]=u;
        temp[1]=v;
        temp[2]=wt;

        edges.push_back(temp);

    }

    int u,v,wt;

    for(int i=1;i<=n-1;i++){

        for(auto vi : edges){
            
            u=vi[0];
            v=vi[1];
            wt=vi[2];

            if(dist[u] + wt < dist[v]){
                dist[v] = wt + dist[u];
            }

        }

    }

/*

6 7
0 1 5 
1 5 -3
1 2 -2
2 4 3
3 2 6 
3 4 -2
5 3 1

*/

    bool flag=false;
    // remain flase if there is no -ve cycle
    // to see we do one time relax 

    for(int i=0;i<1;i++){

        for(int i=0;i<n;i++){

            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];

            if(dist[u]+wt < dist[v] ){

                flag=true;
                cout<<-1;
                break;

            }

        }
    }


    if(flag==false){
        for(int i=0;i<n;i++){
            cout<<dist[i]<<endl;
        }
    }


    return 0;
}