#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <ctime>
#include <set>
#include <functional>
using namespace std;

struct Edge {
	int u, v, w;
};

vector<int> adj[100005];
vector<int> rev_adj[100005];
bool visited[100005];
int n, m;
int check = 0;
int huong = 0;
int show = 0;

vector<pair<int, int>> Distance_adj[100005];
vector<Edge> Kruskal_adj;
vector<pair<int, int>> Prim_adj[100005];
int Parent[100005];
int Size[100005];
int MaTranKe[10005][10005] = { 0 };




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
	cout << "So canh toi da duoc phep khoi tao la : " << check << endl;
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
	huong = choice;
	KhoiTaoSoCanh();
	int selection;
	do {
		cout << "Ban muon do thi co trong so(0) hay khong co trong so(1) : ";
		cin >> selection;
		if (selection != 0 && selection != 1) {
			cout << "Lua chon khong hop le!!\n";
		}
	} while (selection != 0 && selection != 1);
	show = selection;
	if (selection == 1) {
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
				MaTranKe[x][y] = MaTranKe[y][x] = 1;
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
				MaTranKe[x][y] = 1;
			}
			break;
		}
		}
	}
	else {
		switch (choice) {
			// Do thi vo huong
		case 0: {
			int x, y, w;
			for (int i = 0; i < m; i++) {
				do {
					x = rand() % n + 1;
					y = rand() % n + 1;
					w = rand() % 10 + 1;
				} while (x == y || find(adj[x].begin(), adj[x].end(), y) != adj[x].end());
				adj[x].push_back(y);
				adj[y].push_back(x);
				MaTranKe[x][y] = w;
				MaTranKe[y][x] = w;

				Kruskal_adj.push_back({ x, y, w });
				Prim_adj[x].push_back({ y, w });
				Prim_adj[y].push_back({ x, w });
				Distance_adj[x].push_back({ y, w });
				Distance_adj[y].push_back({ x, w });
			}
			break;
		}

				// Do thi co huong
		case 1: {
			int x, y, w;
			for (int i = 0; i < m; i++) {
				do {
					x = rand() % n + 1;
					y = rand() % n + 1;
					w = rand() % 100 + 1;
				} while (x == y || find(adj[x].begin(), adj[x].end(), y) != adj[x].end());
				adj[x].push_back(y);
				rev_adj[y].push_back(x);
				MaTranKe[x][y] = w;

				Prim_adj[x].push_back({ y, w });
				Distance_adj[x].push_back({ y, w });
			}
			break;
		}
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
	huong = choice;

	KhoiTaoSoCanh();

	int selection;
	do {
		cout << "Ban muon do thi co trong so(0) hay khong co trong so(1) : ";
		cin >> selection;
		if (selection != 0 && selection != 1) {
			cout << "Lua chon khong hop le!!\n";
		}
	} while (selection != 0 && selection != 1);
	show = selection;
	if(selection == 1){
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
	}
	else {
		switch (choice) {

			// Do thi vo huong
		case 0: {
			int x, y, w;
			for (int i = 0; i < m; i++) {
				do {
					cout << "Nhap dinh: "; cin >> x;
					cout << "Nhap dinh ke voi dinh " << x << " : "; cin >> y;
					cout << "Nhap trong so: "; cin >> w;
				} while (x == y || find(adj[x].begin(), adj[x].end(), y) != adj[x].end());
				adj[x].push_back(y);
				adj[y].push_back(x);
				MaTranKe[x][y] = w;
				MaTranKe[y][x] = w;
				Kruskal_adj.push_back({ x, y, w });
				Prim_adj[x].push_back({ y, w });
				Prim_adj[y].push_back({ x, w });
				Distance_adj[x].push_back({ y, w });
				Distance_adj[y].push_back({ x, w });

			}
			break;
		}

				// Do thi co huong
		case 1: {
			int x, y, w;
			for (int i = 0; i < m; i++) {
				do {
					cout << "Nhap dinh: "; cin >> x;
					cout << "Nhap dinh ke voi dinh " << x << " : "; cin >> y;
					cout << "Nhap trong so: "; cin >> w;
					if (x == y || find(adj[x].begin(), adj[x].end(), y) != adj[x].end()) {
						cout << "Gia tri da ton tai!! \n";
					}
				} while (x == y || find(adj[x].begin(), adj[x].end(), y) != adj[x].end());
				adj[x].push_back(y);
				rev_adj[y].push_back(x);

				MaTranKe[x][y] = w;
				Prim_adj[x].push_back({ y, w });
				Distance_adj[x].push_back({ y, w });
			}
			break;
		}
		}
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	memset(visited, false, sizeof(visited));
}






void printGraph() {
	cout << "--------------Danh sach ke cua do thi----------\n";
		for (int i = 1; i <= n; i++) {
			cout << i << "\t:\t";
			for (int x : adj[i]) {
				cout << x << "\t";
			}
			cout << endl;
		}

		cout << "--------------Ma tran ke cua do thi-----------\n";
		cout << "\t";
		for (int i = 1; i <= n; i++) {
			cout << i << "\t";
		}
		cout << endl;
		for (int i = 1; i <= n; i++) {
			cout << i << "|\t";
			for (int j = 1; j <= n; j++) {
				cout << MaTranKe[i][j] << "\t";
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

bool connected_Graph_CoHuong() {
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




void make_set() {
	for (int i = 1; i <= n; i++) {
		Parent[i] = i;
		Size[i] = 1;
	}
}
int Find(int v) {
	if (v == Parent[v]) {
		return v;
	}
	return Parent[v] = Find(Parent[v]);
}


bool Union(int u, int v) {
	u = Find(u);
	v = Find(v);
	if (u == v) return false;
	Size[u] += Size[v];
	Parent[v] = u;
	return true;
}
void Kruskal() {
	vector<Edge> MST;
	int d = 0;
	sort(Kruskal_adj.begin(), Kruskal_adj.end(), [](Edge a, Edge b) {return a.w < b.w; });
	for (Edge e : Kruskal_adj) {
		if (MST.size() == n - 1) break;
		if (Union(e.u, e.v)) {
			MST.push_back(e);
			d += e.w;
		}
	}
	if (MST.size() < n - 1) {
		cout << "Do thi khong lien thong!! \n";
	}
	else {
		set <int> vertices;
		cout << "Cay khung cuc tieu theo Kruskal co trong so la: " << d << endl;
		cout << "Cac danh sach canh cua cay khung: \n";
		for (Edge e : MST) {
			cout << e.u << " " << e.v << " " << e.w << endl;
			vertices.insert(e.u);
			vertices.insert(e.v);
		}
		cout << "Cac dinh trong cay khung: \n";
		for (int i : vertices) {
			cout << i << "\t";
		}
	}
}

bool taken[10005];
void Prim(int u) {
	vector<Edge> MST;
	int d = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, u });
	while (!q.empty()) {
		pair<int, int> top = q.top(); q.pop();
		int dinh = top.second, trongso = top.first;

		if (!taken[dinh]) {
			d += trongso;
			taken[dinh] = true;
			for (pair<int, int> x : Prim_adj[dinh]) {
				if (!taken[x.first]) {
					q.push({ x.second, x.first });
				}
			}
		}

	}
	cout << "Trong so cua cay khung cuc tieu: " << d <<endl;


}


int Dijikstra(int s, vector<int>& total_vertices) {
	vector<int> d(n + 1, INT_MAX);
	vector<int> parent(n + 1, -1);
	d[s] = 0;

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, s });

	while (!q.empty()) {
		pair<int, int> top = q.top(); q.pop();
		int dinh = top.second, distance = top.first;

		if (distance > d[dinh]) {
			continue;
		}

		for (pair<int, int> e : Distance_adj[dinh]) {
			int v = e.first, w = e.second;
			if (d[v] > d[dinh] + w) {
				d[v] = d[dinh] + w;
				parent[v] = dinh;
				q.push({ d[v], v });
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] != INT_MAX) {
			sum += d[i];
			total_vertices.push_back(i);
		}
		
	}
	
	cout << "Gia tri duong di tu dinh thu " << s << " toi cac dinh con lai: " << endl;
	for (int i = 1; i <= n; i++) {
		if (d[i] == INT_MAX) {
			cout << "-1\t";
		}
		else {
			cout << d[i] << "\t";
		}
	}
	cout << endl;
	cout << "tong chi phi: " << sum << endl;
	return sum;

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
	cout << "-----------------DO THI VUA DUOC KHOI TA0--------------- \n";
	printGraph();

	memset(visited, false, sizeof(visited));
	cout << "-----------KIEM TRA TINH LIEN THONG--------\n";
	bool c = connected_Graph_CoHuong();
	if (c) {
		cout << "Do thi lien thong!!\n";
	}
	else {
		cout << "Do thi khong lien thong!!\n";
	}
	
	vector<int> res_vertices;
	int min_sum = INT_MAX;
	int min_vertice = INT_MAX;
	cout << "-------------Xet duong di-----------\n";
	cout << "-1 -> Khong co duong di!! \n";
	for (int i = 1; i <= n; i++) {
		vector<int> total_vertices;
		int s = Dijikstra(i, total_vertices);
		if (s < min_sum && total_vertices.size() >= res_vertices.size()) {
			min_sum = s;
			min_vertice = i;
			res_vertices = total_vertices;
		}
	}
	cout << "Vay tram phat song se toi uu nhat o dinh " << min_vertice << endl;
	cout << "Chi phi min: " << min_sum << endl;
	cout << "Cac dinh di duoc : \n";
	for (int x : res_vertices) {
		cout << x << "\t";
	}
	cout << endl;

	
	system("pause");
	return 0;
}