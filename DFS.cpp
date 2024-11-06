#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
int n, m;
bool visited[1005];

void dfs(int u){
    cout<<u<<" ";
    visited[u] = true;
    for(int v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main(){

}