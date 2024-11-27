#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, vector<int>>> adj;
int n;

void init(){
	cout<<"Nhap so luong dinh: "; cin>>n;
	adj.resize(n);
	
	for(int i=0; i<n; i++){
		int val;
		cout<<"Nhap gia tri tai dinh thu "<<i+1<< " : ";
		cin>>val;
		adj[i].first = val;
		cout<<"Nhap so dinh ke: ";
		int m; cin>>m;
		for(int j=1; j<=m; j++){
			cout<<"Nhap gia tri thu "<< j <<" : ";
			int k; cin>>k;
			adj[i].second.push_back(k);
		} 
	}
	
	for(auto &p : adj){
		sort(p.second.begin(), p.second.end());
	}
	sort(adj.begin(), adj.end(), [](const pair<int, vector<int>> &a, const pair<int, vector<int>> &b){
		return a.first < b.first;
	});
}

void xuat(){
	for(auto val: adj){
		cout<<val.first<<" : ";
		for(int x : val.second){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}

int main(){
	init();
	xuat();
}