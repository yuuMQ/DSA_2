#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1005];
bool visited[1005];

void inp(){
    int n, m;
    for(int i=1; i<=n; i++){
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout<<v<<" ";
        for(int x: adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }

}

int main(){

}