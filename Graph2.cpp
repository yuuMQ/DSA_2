#include <iostream>
#include <vector>
#include <ctime>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

struct Edge{
	int u, v;
	int w;
};
int n, m;
vector<Edge> adj;
vector<int> check_adj[MAXN];
vector<pair<int, int>> Prim_adj[MAXN];

bool visited[MAXN];
int parent[MAXN], size[MAXN];
int d[MAXN];
void make_set(){
	for(int i=1; i<=n; i++){
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

bool Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
	if(size[a] < size[b]) swap(a, b);
	parent[b] = a;
	size[a] += size[b];
	return true;
}


void init(){
	n = rand() % 10 + 10;
	m = rand() %(n*(n-1))/2;
	for(int i=0; i<m; i++){
		int x, y, w;
		do{
			x = rand() % n + 1;
			y = rand() % n + 1;
			w = rand() % 10 + 1;
		}while(x == y || find(check_adj[x].begin(), check_adj[x].end(), y)!= check_adj[x].end());
		check_adj[x].push_back(y);
		check_adj[y].push_back(x);  
		
		Prim_adj[x].push_back({y, w});
		Prim_adj[y].push_back({x, w});
		adj.push_back({x, y, w});
	}
	memset(visited, false, sizeof(visited));
	for(int i=1; i<=n; i++){
		d[i] = INT_MAX;
	}
}


void Kruskal(){
	// Tao cay khung cuc tieu rong
	vector<Edge> MST;
	// trong so
	int d = 0;
	sort(adj.begin(), adj.end(), [](Edge a, Edge b){ return a.w < b.w; });
	
	for(int i=0; i<m; i++){
		if(MST.size() == n-1) break;
		// Canh e la canh nho nhat
		Edge e = adj[i];
		if(Union(e.u, e.v)){
			MST.push_back(e);
			d += e.w;
		}
	}
	// Tra ve ket qua
	if(MST.size() != n-1){
		cout<<"Do thi khong lien thong!!";
	}
	else{
		cout<<d<<endl;
		for(auto x : MST){
			cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;
		}
	}
}


void Prim(int u){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	vector<Edge> MST;
	int res = 0;
	Q.push({0, u});
	while(!Q.empty()){
		pair<int, int> top = Q.top(); Q.pop();
		int dinh = top.second, trongso = top.first;
		
		if(visited[dinh]){
			continue;
		}
		res += trongso;
		visited[dinh] = true;
		if(u != dinh){
			MST.push_back({dinh, parent[dinh], trongso});
		}
		for(auto it : Prim_adj[dinh]){
			int y = it.first, w = it.second;
			if(!visited[y] && w < d[y]){
				Q.push({w, y});
				d[y] = w;
				parent[y] = dinh;
			}
		}
	}
	cout<<res<<endl;
	for(auto it : MST){
		cout<<it.u <<" "<<it.v<<" "<<it.w<<endl;
	}
}

int main(){
	srand(time(NULL));
	init();
	make_set();
	Kruskal();
	memset(visited, false, sizeof(visited));
	cout<<endl;
	Prim(1);
}