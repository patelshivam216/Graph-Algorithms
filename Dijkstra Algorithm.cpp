#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
const int INF = 1e4;
int n,m;
vector<pair<int, int>> graph[N];
//          node distance




void dijkstra(int source){

    
    vector<int> dist(N,INT_MAX);// dist=level
  
    
    set<pair<int,int>> st;
    st.insert({0,source});
    //         dis,node 
    // distance means level 
    dist[source]=0;

    while(st.size()>0){

        auto node = *st.begin();
        int v = node.second;
        int dist_v = node.first;
        st.erase(st.begin());

        for(auto child : graph[v]){

            auto child_v = child.first;
            auto wt = child.second;

            if(dist[v] + wt < dist[child_v]){
                
                 dist[child_v]= dist[v]+wt;
                 st.insert({dist[child_v],child_v});


            }
        }

    }

    for(int i=1;i<=n;i++){
        cout<<i<<" - "<<dist[i]<<endl;
    }

}
/*

input 

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
int main(){

    cin>>n>>m;
    
        for(int j=0;j<m;j++){
            int v1,v2,wt;
            cin>>v1>>v2>>wt;
            graph[v1].push_back({v2,wt});
        }
   


    dijkstra(1);
   
    

}
