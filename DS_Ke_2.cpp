#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
int n, m;
int main(){
    cout<<"Nhap so dinh: "; cin>>n;
    for(int i=1; i<=n; i++){
        cout<<"Nhap so canh ke cua dinh "<<i<<": ";
        cin>>m;

        for(int j=1; j<=m; j++){
            cout<<"Nhap gia tri cac dinh ke voi dinh "<<i<<": ";
            int u; cin>>u; 
            adj[i].push_back(u);
        }
        sort(adj[i].begin(), adj[i].end());
    }

    for(int i=1; i<=n; i++){
        cout<<i<<" : "; 
        for(int u:adj[i]){
            cout<<u<<" ";
        }
        cout<<endl;
    }
}