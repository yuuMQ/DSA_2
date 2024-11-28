#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <ctime>

using namespace std;

vector<int> adj[100005];
vector<int> rev_adj[100005];
bool visited[100005];
int n, m; 
int check = 0;

void KhoiTaoSoDinh() {
	int choice;
	do {
		cout << "Ban muon nhap so dinh auto(0) hay manual(1): ";
		cin >> choice;
		if (choice != 0 && choice != 1) {
			cout << "Lua chon khong hop le!!\n";
		}
	} while (choice != 0 && choice != 1);

	if (choice == 0) {
		cout << "Toi se khoi tao cho ban so dinh random tu 10 -> 20!!" << endl;
		n = rand() % 10 + 11;
	}
	else {
		do {
			cout << "Nhap so dinh ma ban muon nhap: ";
			cin >> n;
			if (n <= 0 || n > 100005) cout << "Khong hop le!! \n";
		} while (n <= 0 || n > 100005);
	}
	cout << "So dinh duoc khoi tao la : " << n << endl;
}

void KhoiTaoSoCanh() {
	cout << "So canh toi da duoc phep khoi tao la : " << check<<endl;
	int choice;
	do {
		cout << "Ban muon nhap so canh auto(0) hay manual(1): ";
		cin >> choice;
		if (choice != 0 && choice != 1) {
			cout << "Lua chon khong hop le!!\n";
		}
	} while (choice != 0 && choice != 1);
	if (choice == 0) {
		cout << "Toi se khoi tao cho ban so canh random!!" << endl;
		m = rand() % check + 1;
	}
	else {
		do {
			cout << "Nhap so canh ma ban muon nhap: ";
			cin >> m;
			if (m > check || m < 0) {
				cout << "Khong hop le!! \n";
			}
		} while (m > check || m < 0);
	}
	cout << "So canh duoc khoi tao: " << m << endl;
}



void initRandom() {
	KhoiTaoSoDinh();
	int choice;
	do {
		cout << "Ban muon nhap do thi vo huong(0) hay co huong(1) : ";
		cin >> choice;
		if (choice != 0 && choice != 1) {
			cout << "Lua chon khong hop le!!\n";
		}
	} while (choice != 0 && choice != 1);

	if (choice == 0) {
		check = (n * (n - 1)) / 2;
	}
	else {
		check = n * (n - 1);
	}
	KhoiTaoSoCanh();
	switch (choice) {

	// Do thi vo huong
	case 0: {
		int x, y;
		for (int i = 0; i < m; i++) {
			do {
				x = rand() % n + 1;
				y = rand() % n + 1;
			} while (x == y || find(adj[x].begin(), adj[x].end(), y) != adj[x].end());
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		break;
	}

	// Do thi co huong
	case 1: {
		int x, y;
		for (int i = 0; i < m; i++) {
			do {
				x = rand() % n + 1;
				y = rand() % n + 1;
			} while (x == y || find(adj[x].begin(), adj[x].end(), y) != adj[x].end());
			adj[x].push_back(y);
			rev_adj[y].push_back(x);
		}
		break;
	}
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	memset(visited, false, sizeof(visited));
}

void initManual() {
	KhoiTaoSoDinh();
	int choice;
	do {
		cout << "Ban muon nhap do thi vo huong(0) hay co huong(1) : ";
		cin >> choice;
		if (choice != 0 && choice != 1) {
			cout << "Lua chon khong hop le!!\n";
		}
	} while (choice != 0 && choice != 1);
	if (choice == 0) {
		check = (n*(n - 1)) / 2;
	}
	else {
		check = n*(n - 1);
	}

	
	KhoiTaoSoCanh();

	switch (choice) {

	// Do thi vo huong
	case 0: {
		int x, y;
		for (int i = 0; i < m; i++) {
			do {
				cout << "Nhap dinh: "; cin >> x;
				cout << "Nhap dinh ke voi dinh " << x << " : "; cin >> y;
			} while (x == y || find(adj[x].begin(), adj[x].end(), y) != adj[x].end());
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		break;
	}

	// Do thi co huong
	case 1: {
		int x, y;
		for (int i = 0; i < m; i++) {
			do {
				cout << "Nhap dinh: "; cin >> x;
				cout << "Nhap dinh ke voi dinh " << x << " : "; cin >> y;
				if (x == y || find(adj[x].begin(), adj[x].end(), y) != adj[x].end()) {
					cout << "Gia tri da ton tai!! \n";
				}
			} while (x == y || find(adj[x].begin(), adj[x].end(), y) != adj[x].end());
			adj[x].push_back(y);
			rev_adj[y].push_back(x);
		}
		break;
	}
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	memset(visited, false, sizeof(visited));
}






void printGraph() {
	for (int i = 1; i <= n; i++) {
		cout << i << "\t:\t";
		for (int x : adj[i]) {
			cout << x << "\t";
		}
		cout << endl;
	}
}


//BFS
void BFS(int u, vector<int>& bfs) {
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		bfs.push_back(v);
		for (int x : adj[v]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

bool BFS_FindLocation(int u, int res, vector<int> &path) {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	vector<int> parent(n + 1, -1);

	q.push(u);
	visited[u] = true;

	while (!q.empty()) {
		int v = q.front(); q.pop();
		
		if (v == res) {
			while (v != -1) {
				path.push_back(v);
				v = parent[v];
			}
			reverse(path.begin(), path.end());
			return true;
		}

		for (int x : adj[v]) {
			if (!visited[x]) {
				q.push(x);
				parent[x] = v;
				visited[x] = true;
			}
		}
	}
	return false;
}

//DFS
void DFS(int u, vector<int>& dfs) {
	dfs.push_back(u);
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) {
			DFS(v, dfs);
		}
	}
}
void DFS(int u, int res) {
	visited[u] = true;
	if (u == res) {
		return;
	}
	for (int v : adj[u]) {
		if (!visited[v]) {
			DFS(v, res);
			if (visited[res]) return;
		}
	}
}

void DFS_VoHuong(int u) {
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) {
			DFS_VoHuong(v);
		}
	}
}


void DFS_CoHuong(int u) {
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) {
			DFS_CoHuong(v);
		}
	}
}
void DFS_CoHuong_DaoNguoc(int u) {
	visited[u] = true;
	for (int v : rev_adj[u]) {
		if (!visited[v]) {
			DFS_CoHuong_DaoNguoc(v);
		}
	}
}


bool connected_Graph_VoHuong(int n) {
	memset(visited, false, sizeof(visited));
	DFS_VoHuong(1);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}

bool connected_Graph_CoHuong(int n) {
	memset(visited, false, sizeof(visited));
	DFS_CoHuong(1);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			return false;
		}
	}
	memset(visited, false, sizeof(visited));
	DFS_CoHuong_DaoNguoc(1);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}

bool DFS_FindLocation(int res) {
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			DFS(i, res);
			if (visited[res]) {
				return true;
			}
		}
	}
	return false;
}









int main() {
	int repeat;
	srand(time(NULL));
		system("cls");
		int choice;
		do {
			cout << "Ban muon nhap do thi random(0) hay manual(1): ";
			cin >> choice;
			if (choice != 0 && choice != 1) {
				cout << "Lua chon khong hop le!! \n";
			}
		} while (choice != 0 && choice != 1);


		if (choice == 0) {
			initRandom();
		}
		else if (choice == 1) {
			initManual();
		}
		cout << "-----------------DANH SACH KE CUA DO THI VUA DUOC KHOI TA0--------------- \n";
		printGraph();

		vector<int> bfs;
		vector<int> dfs;

		cout << "----------------BFS---------------\n";
		cout << "Nhap dinh ban muon duyet BFS: ";
		int v; cin >> v;
		BFS(v, bfs);
		for (int val : bfs) {
			cout << val << " ";
		}
		cout << endl;
		cout << "-----------------DFS---------------\n";
		cout << "Nhap dinh ban muon duyet DFS: ";
		cin >> v;
		memset(visited, false, sizeof(visited));
		DFS(v, dfs);
		for (int val : dfs) {
			cout << val << " ";
		}
		cout << endl;


		cout << "-----------Tim Kiem Dinh--------------\n";
		cout << "Nhap dinh ma ban muon tim trong do thi: ";
		int key; cin >> key;
		if (DFS_FindLocation(key)) cout << "Dinh co ton tai trong do thi!! \n";
		else cout << "Dinh khong ton tai trong do thi!! \n";




		cout << "-----------Tim Duong Di--------------\n";
		vector<int> path;
		cout << "Nhap dinh ban muon xuat phat: "; cin >> key;
		memset(visited, false, sizeof(visited));
		int res;
		cout << "Nhap dinh ban muon toi: "; cin >> res;
		if (BFS_FindLocation(key, res, path)) {
			cout << "Duong di tu " << key << " toi " << res << " la: \n";
			for (int x : path) {
				cout << x << " ";
			}
			cout << endl;
		}
		else {
			cout << "Khong ton tai duong di tu " << key << " toi " << res << "!!!! \n";
		}

		cout << "----------------KIEM TRA DO THI LIEN THONG--------------\n";
		if (choice == 0) {
			if (connected_Graph_VoHuong(n)) {
				cout << "Do thi lien thong!! \n";
			}
			else {
				cout << "Do thi khong lien thong!! \n";
			}
		}
		else {
			if (connected_Graph_CoHuong(n)) {
				cout << "Do thi lien thong!! \n";
			}
			else {
				cout << "Do thi khong lien thong!! \n";
			}
		}
		system("pause");

	
	return 0;
}
