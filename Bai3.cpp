#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct soxe {
	string a[3];
};
int n;
vector<soxe> biensoxe;

void nhap() {
	cout << "Nhap so luong bien bao: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap bien bao thu " << i << " : \n";
		string matinh; cout << "Nhap ma tinh: "; cin >> matinh;
		string kitu; cout << "Nhap ki tu: "; cin >> kitu;
		string chuso; cout << "Nhap 5 chu so duoi: "; cin >> chuso;
		soxe x;
		x.a[0] = matinh; x.a[1] = kitu; x.a[2] = chuso;
		biensoxe.push_back(x);
	}
}

void CountingSort(vector<soxe> &bienso, int exp){
	vector<soxe> output(bienso.size());
	vector<int> count(256, 0);
	for (int i = 0; i < bienso.size(); i++) {
		count[bienso[i].a[exp][0]]++;
	}
	for (int i = 1; i < count.size(); i++) {
		count[i] += count[i - 1];
	}
	for (int i = bienso.size()-1; i >= 0; i--) {
		output[count[bienso[i].a[exp][0]] - 1] = bienso[i];
		count[bienso[i].a[exp][0]]--;
	}
	for (int i = 0; i < bienso.size(); i++) {
		bienso[i] = output[i];
	}
}
void RadixSort(vector<soxe> &a) {
	for (int exp = 2; exp >= 0; exp--) {
		CountingSort(a, exp);
	}
}

void hienthi() {
	for (int i = 0; i < n; i++) {
		cout << biensoxe[i].a[0] << " " << biensoxe[i].a[1] << " " << biensoxe[i].a[2] << endl;
	}
}

int main() {
	// nhap bien so xe -> 3 phan -> 2 chu so Ma tinh, ki tu ABCD->Z, 5 chu so
	nhap();
	cout << "Bien so xe truoc khi sap xep\n";
	hienthi();
	RadixSort(biensoxe);
	cout << "Bien so xe sau khi sap xep\n";
	hienthi();
	system("pause");
}