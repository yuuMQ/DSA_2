#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include <set>
#include <map>
using namespace std;

#define ii pair<int, int>
const int MAXN = 10005;

int choice;
int tongtrongsoMin_Kruskal = INT_MAX;
int tongtrongsoMin_Prim = INT_MAX;

struct Edge {
	int u, v, w;
};
int n, m;
vector<int> adj[MAXN];
int MaTranKe[MAXN][MAXN] = { 0 };
// Kruskal
vector<Edge> Kruskal_adj;
int Parent[MAXN];
int Size[MAXN];
int MinSize[MAXN];

// Prim
vector<ii> Prim_adj[MAXN];
bool visited[MAXN];
int Distance[MAXN];
int Min_distance[MAXN];

int soluongCayBaoTrum = 0;

void make_set() {
	for (int i = 1; i <= n; i++) {
		Parent[i] = i;
		Size[i] = 1;
	}
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		Distance[i] = INT_MAX;
		Min_distance[i] = INT_MIN;
	}
}

int Find(int v) {
	if (v == Parent[v]) return v;
	return Parent[v] = Find(Parent[v]);
}

bool Union(int u, int v) {
	u = Find(u);
	v = Find(v);
	if (u == v) return false;
	if (Size[u] < Size[v]) swap(u, v);
	Parent[v] = u;
	Size[u] += Size[v];
	return true;
}


void khoitaoDinh() {
	do {
		cout << "Ban muon nhap dinh auto(0) hay manual(1): "; cin >> choice;
		if (choice != 0 && choice != 1) cout << "Khong hop le!!\n";
	} while (choice != 0 && choice != 1);
	
	switch (choice) {
	case 0: {
		cout << "Nhap dinh auto tu 10 -> 20: ";
		n = rand() % 10 + 11;
		cout << "Toi da khoi tao cho ban " << n << " dinh \n";
		break;
	}
	case 1: {
		cout << "Hay nhap so dinh cua ban: ";
		cin >> n;
		break;
	}
	}
}

void khoitaoCanh() {
	do {
		cout << "Ban muon nhap canh auto(0) hay manual(1): "; cin >> choice;
		if (choice != 0 && choice != 1) cout << "Khong hop le!!\n";
	} while (choice != 0 && choice != 1);
	cout << "So canh toi da ma ban co the khoi tao la: " << n*(n - 1)/2 << endl;

	switch (choice) {
	case 0: {
		m = rand() % n*(n - 1)/2 + 1;
		cout << "Toi se khoi tao cho ban: " << m << " canh \n";
		break;
	}
	case 1: {
		do {
			cout << "Nhap so canh cua ban: "; cin >> m;
			if (m<0 || m>n*(n - 1)) cout << "Khong hop le!!\n";
		} while (m<0 || m>n*(n - 1));
		break;
	}
	}
}

void init() {
	int selection;
	do {
		cout << "Ban muon nhap cay auto(0) hay manual(1): "; cin >> selection;
	} while (selection != 0 && selection != 1);
	cout << "Ban chi duoc phep khoi tao cay vo huong!!\n";
	khoitaoDinh();
	khoitaoCanh();

	switch (selection) {
	case 0: {
		cout << "Nhap cay auto!!" << endl;
		for (int i = 0; i < m; i++) {
			int x, y, w;
			do {
				x = rand() % n + 1;
				y = rand() % n + 1;
				w = rand() % 10 + 1;
			} while (x == y || find(adj[x].begin(), adj[x].end(), y) != adj[x].end());
			adj[x].push_back(y);
			adj[y].push_back(x);
			Kruskal_adj.push_back({ x, y, w });
			Prim_adj[x].push_back({ y, w });
			Prim_adj[y].push_back({ x, w });
			MaTranKe[x][y] = MaTranKe[y][x] = w;
		}
		break;
	}
	case 1: {
		cout << "Nhap cay manual!!" << endl;
		for (int i = 0; i < m; i++) {
			int x, y, w;
			do {
				cout << "Nhap dinh: "; cin >> x;
				cout << "Nhap dinh ke: "; cin >> y;
				cout << "Nhap trong so giua 2 dinh: "; cin >> w;
				if (x == y || find(adj[x].begin(), adj[x].end(), y) != adj[x].end()) {
					cout << "Dinh da ton tai!!\n";
				}
				else if (x > n || y > n || x < 0 || y < 0) {
				cout << "Dinh khong hop le\n";
			}
			} while (x == y || find(adj[x].begin(), adj[x].end(), y) != adj[x].end() || x > n || y > n || x < 0 || y < 0);
			adj[x].push_back(y);
			adj[y].push_back(x);
			Kruskal_adj.push_back({ x, y, w });
			Prim_adj[x].push_back({ y, w });
			Prim_adj[y].push_back({ x, w });
			MaTranKe[x][y] = MaTranKe[y][x] = w;
		}
		break;
	}
	}
}


void inDoThi() {
	cout << "----------------------Danh Sach Canh-------------------------\n";
	for (int i = 1; i <= n; i++) {
		cout << i << "\t:\t";
		for (int x : adj[i]) {
			cout << x << "\t";
		}
		cout << endl;
	}

	cout << "-----------------------Ma Tran Ke-----------------------\n";
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



void Kruskal() {
	vector<Edge> MST;
	int d = 0;
	sort(Kruskal_adj.begin(), Kruskal_adj.end(), [](Edge a, Edge b) {
		return a.w < b.w;
	});
	for (int i = 0; i < m; i++) {
		if (MST.size() == n - 1) {
			break;
		}
		Edge e = Kruskal_adj[i];
		if (Union(e.u, e.v)) {
			MST.push_back(e);
			d += e.w;
		}
	}
	if (MST.size() < n - 1) {
		cout << "Do thi khong lien thong!!!\n";
	}
	else {
		cout << "Cay khung cuc tieu co tong trong so la: " << d << endl;
		cout << "Danh sach ke cua cay khung: \n";
		cout << "Dinh\tDinh ke\tTrong so\n";
		for (Edge e : MST) {
			cout << e.u << "\t" << e.v << "\t" << e.w << endl;
		}
	}
	tongtrongsoMin_Kruskal = d;
}

void Prim(int u) {
	priority_queue<ii, vector<ii>, greater<ii>> q;
	vector<Edge> MST;
	q.push({ 0, u });
	int d = 0;
	while (!q.empty()) {
		ii top = q.top(); q.pop();
		int dinh = top.second, trongso = top.first;
		if (visited[dinh]) continue;
		d += trongso;
		visited[dinh] = true;
		if (u != dinh) {
			MST.push_back({ dinh, Parent[dinh], trongso });
		}
		for(auto it : Prim_adj[dinh]){
			int y = it.first, w = it.second;
			if (!visited[y] && w < Distance[y]) {
				q.push({ w, y });
				Distance[y] = w;
				Parent[y] = dinh;
			}
		}
	}
	if (MST.size() < n - 1) {
		cout << "Do thi khong lien thong!! \n";
	}
	else {
		cout << "Tong trong so trong cay khung: " << d << endl;;
		cout << "Danh sach ke cua cay khung: "<<endl;
		cout << "Dinh\tDinh ke\tTrong so\n";
		for (Edge e : MST) {
			cout << e.u << "\t" << e.v << "\t" << e.w << endl;
		}
	}
	tongtrongsoMin_Prim = d;
}



int Prim_sl(int u) {

	priority_queue<ii, vector<ii>, greater<ii>> q;
	vector<Edge> MST;
	q.push({ 0, u });
	int d = 0;
	while (!q.empty()) {
		ii top = q.top(); q.pop();
		int dinh = top.second, trongso = top.first;
		if (visited[dinh]) continue;
		d += trongso;
		visited[dinh] = true;
		if (u != dinh) {
			MST.push_back({ dinh, Parent[dinh], trongso });
		}
		for (auto it : Prim_adj[dinh]) {
			int y = it.first, w = it.second;
			if (!visited[y] && w < Distance[y]) {
				q.push({ w, y });
				Distance[y] = w;
				Parent[y] = dinh;
			}
		}
	}
	if (MST.size() < n - 1) {
		return -1;
	}
	return d;
}



// Cay khung cuc dai

bool UnionMin(int u, int v) {
	u = Find(u);
	v = Find(v);
	if (u == v) return false;
	if (Size[u] > Size[v]) swap(u, v);
	Parent[v] = u;
	Size[u] += Size[v];
	return true;
}

void Kruskal_max() {
	vector<Edge> MST;
	int d = 0;
	sort(Kruskal_adj.begin(), Kruskal_adj.end(), [](Edge a, Edge b) {
		return a.w > b.w;
	});
	for (int i = 0; i < m; i++) {
		if (MST.size() == n - 1) break;
		Edge e = Kruskal_adj[i];
		if (Union(e.u, e.v)) {
			MST.push_back(e);
			d += e.w;
		}
	}
	if (MST.size() < n - 1) cout << "Do thi khong lien thong!!\n";
	else {
		cout << "Tong trong so cua cay khung cuc dai: " << d << endl;
		cout << "Danh sach ke cua cay khung: \n";
		cout << "Dinh\tDinh ke\tTrong so\n";
		for (Edge e : MST) {
			cout << e.u << "\t" << e.v << "\t" << e.w << endl;
		}
	}
}


void Prim_max(int u) {
	priority_queue<ii, vector<ii>, less<ii>> q;
	q.push({ 0, u });
	vector<Edge> MST;
	int d = 0;
	while (!q.empty()) {
		ii top = q.top(); q.pop();
		int dinh = top.second, trongso = top.first;
		if (visited[dinh]) continue;
		d += trongso;
		visited[dinh] = true;
		if (u != dinh) {
			MST.push_back({ dinh, Parent[dinh], trongso });
		}
		for (ii it : Prim_adj[dinh]) {
			int y = it.first, w = it.second;
			if (!visited[y] && w > Min_distance[y]) {
				q.push({ w, y });
				Min_distance[y] = w;
				Parent[y] = dinh;
			}
		}
	}
	if (MST.size() < n - 1) cout << "Do thi khong lien thong!!\n";
	else {
		cout << "Tong trong so cua cay khung cuc dai: " << d << endl;
		cout << "Danh sach ke cua cay khung\n";
		cout << "Dinh\tDinh ke\tTrong so\n";
		for (Edge e : MST) {
			cout << e.u << "\t" << e.v << "\t" << e.w << endl;
		}
	}
}



void Kruskal_for_manual_graph(vector<Edge> v, int dinhbandau) {
	vector<Edge> MST;
	int d = 0;
	sort(v.begin(), v.end(), [](Edge a, Edge b) {return a.w < b.w; });
	for (int i = 0; i < m; i++) {
		if (MST.size() == n - 1) {
			break;
		}
		Edge e = v[i];
		if (Union(e.u, e.v)) {
			MST.push_back(e);
			d += e.w;
		}
	}
	if (MST.size() < n - 1) {
		cout << "Do thi khong lien thong!!\n";
	}
	else {
		if (n == dinhbandau) {
			if (d > tongtrongsoMin_Kruskal) {
				cout << "Day khong la cay bao trum nho nhat\n";
			}
			else if (d == tongtrongsoMin_Kruskal) {
				cout << "Day la cay bao trum nho nhat cung voi cay goc";
			}
			else {
				cout << "Day la cay bao trum nho nhat moi\n";
			}
		}

		else {
			cout << "Day la cay bao trum nho nhat\n";
			cout << "Cay bao trum nho nhat co tong trong so la: " << d << endl;
			cout << "Danh sach ke cua cay khung\n";
			cout << "Dinh\tDinh ke\tTrong so\n";
			for (Edge e : MST) {
				cout << e.u << "\t" << e.v << "\t" << e.w << endl;
			}
		}
	}
}





int main() {
	srand(time(NULL));
	init();
	make_set();
	cout << "-----------------------------------Do thi ban dau-----------------------------------------------\n";
	inDoThi();
	cout << "==================CAY KHUNG CUC TIEU=================\n";
	cout << "--------------KRUSKAL----------------\n";
	Kruskal();
	cout << "----------------PRIM-----------------\n";
	Prim(1);

	make_set();
	cout << "-------------So luong cay bao trum------------\n";
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int d = Prim_sl(i);
		if (d != -1) {
			++cnt;
		}
	}
	cout << "Tong so luong cay bao trum nho nhat la: " << cnt << endl;

	cout << endl << endl;
	make_set();
	cout << "====================CAY KHUNG CUC DAI==================\n";
	cout << "-----------------KRUSKAL-----------------\n";
	Kruskal_max();
	cout << "-----------------PRIM-----------------\n";
	Prim_max(1);
	cout << "-------------------------------Do thi cua ban---------------------------------\n";
	cout << "==============KIEM SOAT CAY BAO TRUM==============\n";
	int dinhHientai = n;
	do {
		cout << "Hay nhap vao so dinh la dinh con cua do thi ban dau: ";
		cin >> n;
		if (n < 0  || n > dinhHientai) cout << "Khong hop le!!\n";
	} while (n < 0 || n > dinhHientai);
	
	make_set();
	vector<int> check_adj[MAXN];
	vector<Edge> Kruskal_for_manual;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			Kruskal_for_manual.push_back({ i, j, MaTranKe[i][j] });
		}
	}
	
	inDoThi();

	cout << "--------------------CAY KHUNG CUC TIEU-------------------\n";
	Kruskal_for_manual_graph(Kruskal_for_manual, dinhHientai);

	system("pause");
	return 0;
}