#include<bits/stdc++.h>
using namespace std;
int main(){

    int n , m ;

    vector<vector<int>> graph;
    vector<vector<int>> dist(n , vector<int>(m,1e9));

    set<pair<int,pair<int,int>>> st;
    st.insert({0,{0,0}});
    dist[0][0]=0;// root's distance from root is zero

    while(st.size()>0){
        auto p = *st.begin();
        st.erase(st.begin());

        int x = p.second.first;
        int y = p.second.second;

        for(auto movement : movements){
            int nx = x + movement.first;
            int ny = y + movement.second;

            if(nx<0 || ny<o || nx>=graph.size() || ny>= graph[0].size()) continue;

            // weight of new location is 
            int wt = graph[nx][ny];

            if(wt + dist[x][y] < dist[nx][ny]){
                dist[nx][ny]=wt + dist[x][y];
                st.insert({dist[nx][ny], {nx,ny}});
            }
        }
    }


    return 0;
}