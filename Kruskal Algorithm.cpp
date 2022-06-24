#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int parent[N];
int size[N];

void make(int v){
    parent[v]=v;
    size[v]=1;

}

int find(int v){
    if(v==parent[v])
        return v;
    
    return parent[v]=find(parent[v]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);

    if(a != b){
        if(size[a]<size[b])
            swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }

}
/*

6 9 
5 4 9 
1 4 1 
5 1 4
4 3 5
4 2 3
1 2 2 
3 2 3
3 6 8
2 6 7

*/
int main(){

    int v,e;
    cin>>v>>e;
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<e;i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        edges.push_back({wt,{v1,v2}});
    }
    sort(edges.begin(),edges.end());

    for(int i=1;i<=v;i++)
        make(i);
    
    int total_cost=0;
    for(auto edge : edges ){
        int wt=edge.first;
        int v1=edge.second.first;
        int v2=edge.second.second;

        if(find(v1)==find(v2))
            continue;

        Union(v1,v2);
        total_cost+=wt;
        cout<<v1<<" "<<v2<<endl;
    }
    

    cout<<total_cost<<endl;

    return 0;
}