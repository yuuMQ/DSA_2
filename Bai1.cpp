#include <iostream>
#include <algorithm>
#include <ctime>
#include <queue>
#include <stack>

using namespace std;

void toBinary(int n) {
	int cnt = 0;
	stack<int> st;
	while (n) {
		st.push(n % 2);
		n /= 2;
		++cnt;
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	cout << endl;
	cout << "Do phuc tap cua thuat toan la O(" << cnt << ")" << endl;
}



int main() {
	int n;
	cout << "Nhap n: "; cin >> n;
	toBinary(n);

	system("pause");
	return 0;
}