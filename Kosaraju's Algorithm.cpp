// Kosaraju's algorithm for strong connected component 
/*

1. do topo sort and fill up stack
1'.transpose the graph
2. then do travarsal starting from stack's top to end 
3. dfs travarsal
4. at a time visited nodes are strongly connected compenent

*/

#include<bits/stdc++.h>
using namespace std;

void dfsTopo(int v,vector<int> &vis,vector<int> graph[],vector<int> &toposort){
    vis[v]=true;

    for(auto child : graph[v]){
        if(!vis[child]){
            dfsTopo(child,vis,graph,toposort);
        }
    }

    toposort.push_back(v);
    

}

void dfsTrans(int v,vector<int> &vis,vector<int> graph[]){
    
    vis[v]=true;
    cout<<v<<" ";

    for(auto child : graph[v]){
        if(!vis[child]){
            dfsTrans(child,vis,graph);
        }
    }
}



int main(){
    int n,m;
    cin>>n>>m;

    vector<int> vis(n,-1);
    vector<int> graph[n+1];
    vector<int> transGraph[n+1];
    vector<int> toposort;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    // dfs for topo and fill up toposort

    for(int i=0;i<n;i++){

        if(vis[i] != -1) continue;

        dfsTopo(i,vis,graph,toposort);

    }

    // transpose the graph and make vis zero

    for(int i=0;i<m;i++){
        vis[i]=0;

        for(auto v : graph[i]){
            transGraph[v].push_back(i);
        }
    }

/*
5 5
0 1
1 2
2 0
1 3
3 4
*/

    // redfs with toposort


    for(auto v : toposort){

        if(vis[v]==0){

            cout<<"strongly connected component : ";
            dfsTrans(v,vis,transGraph);
            cout<<endl;

        }

    }



    return 0;
}