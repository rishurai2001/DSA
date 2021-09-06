#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}

#define pii pair<int,int>
const int n=9;

void addEdge(vector<pii>graph[],int src,int des,int wt){

    graph[src].push_back({des,wt});
    graph[des].push_back({src,wt});


}
void Dijkstras(vector<pair<int,int>>adj[]){

    bool isMST[n];
    int dist[n];
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,0});
    
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
        isMST[i]=false;
    }
    dist[0]=0;

    while(!pq.empty()){
        
       while(!pq.empty()&& isMST[pq.top().second]){
            pq.pop();
        }

        if(pq.empty()) break;

        int v=pq.top().second;
        pq.pop();
        isMST[v]=true;

        for(pii x:adj[v]){
            if(isMST[x.first]==false && dist[v]!=INT_MAX && x.second+dist[v]<dist[x.first]){
                 dist[x.first]=x.second+dist[v];
                 pq.push({x.second+dist[v],x.first});
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<i<<":"<<dist[i]<<"\n";
    }


}




signed main(){
    fast;
     
   
   vector<pii>graph[n];
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);
    Dijkstras(graph);
    return 0;
}
