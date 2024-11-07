#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

void printArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}

void insertionSort(int arr[], int n, int &cnt, int &time){
	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
			++cnt;
		}
		arr[j + 1] = key;
		++time;
		printArr(arr, n);
	}
}



int partition(int arr[], int n, int low, int high, int &cnt) {
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			cnt++;
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	cnt++;
	printArr(arr, n);
	return (i + 1);
}
void quickSort(int arr[], int n, int low, int high, int &cnt, int &time) {
	if (low < high) {
		++time;
		int pi = partition(arr, n, low, high, cnt);
		quickSort(arr, n, low, pi - 1, cnt, time);
		quickSort(arr, n,  pi + 1, high, cnt, time);		
	}
}

void heapify(int arr[], int n, int i, int &heapify_count) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}
	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify_count++;
		heapify(arr, n, largest, heapify_count);
	}
}

void heapSort(int arr[], int n, int &heapify_count, int &time) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i, heapify_count);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		printArr(arr, n);
		time++;
		heapify(arr, i, 0, heapify_count);
	}
}



int Fibonacci(int n, int &cnt){
	if (n <= 1) {
		return n;
	}
	cnt++;
	int left = Fibonacci(n - 2, cnt);
	int right = Fibonacci(n - 1, cnt);
	return left + right;
}


void insertValuesToOtherArr(int a[], int b[], int n) {
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
}

void shell_sort(int a[], int n) {
	for (int gap = n / 2; gap > 0; gap/=2) {
		for (int i = gap; i < n; i++) {
			int tmp = a[i];
			int j = i;
			while (j >= gap && a[j-gap] > tmp) {
				a[j] = a[j - gap];
				j-=gap;
			}
			a[j] = tmp;
		}
	}
}
void counting_sort(int a[], int n) {

}



int main() {
	srand(time(NULL));
	string choice;
	int n;
	int *a;
	do {
		system("cls");
		do {
			cout << "Nhap kich thuoc cua mang (n): ";
			cin >> n;
			if (n <= 0) cout << "Gia tri khong hop le!!" << endl;
		} while (n <= 0);
		a = new int[n];
		int select;
		do {
			cout << "Ban muon nhap manual(1) hay automatic(0): ";
			cin >> select;
			if (select != 1 && select != 0) {
				cout << "Lua chon khong hop le!! \n";
			}
		} while (select != 1 && select != 0);

		switch (select) {
			case 0: {
				for (int i = 0; i < n; i++) {
					a[i] = rand() % 100 + 1;
				}
				break;
			}
			case 1: {
				cout << "Ban hay tu nhap gia tri cho mang: " << endl;
				for (int i = 0; i < n; i++) {
					cin >> a[i];
				}
				break;
			}
		}

		do {
			system("cls");
			int cnt = 0;
			int *check = new int[n];
			int time = 0;
			insertValuesToOtherArr(a, check, n);
			cout << "===========MENU==========\n";
			cout << "1. Insertion sort \n";
			cout << "2. Quick sort \n";
			cout << "3. Heap sort \n";
			cout << "4. ao ra day so Fibonacci \n";
			cout << "5. Shell sort \n";
			cout << "0. Ket thuc Mang \n";
			cout << "=========================\n";
			cout << "Lua chon cua ban -> "; cin >> select;
			switch (select) {
				case 1: {
					printArr(check, n);
					cout << "===========INSERTION SORT========\n";
					insertionSort(check, n, cnt, time);
					cout << "Tong so lan gan la: " << cnt << endl;
					cout << "So lan thuc hien phep toan: " << time << endl;
					break;
				}
				case 2: {
					printArr(check, n);
					cout << "==============QUICK SORT==========\n";
					quickSort(check, n, 0, n-1, cnt, time);
					cout << "So lan gan: " << cnt << endl;
					cout << "So lan de quy: " << time << endl; 
					break;
				}
				case 3: {
					printArr(check, n);
					int heapify_count = 0;
					cout << "============HEAP SORT==============\n";
					heapSort(check, n, heapify_count, time);
					cout << "So lan heapify: " << heapify_count << endl;
					cout << "So lan thuc hien: " << time << endl;
					break;
				}
				case 4: {
					cout << "============FIBONACCI============\n";
					cout << "Nhap so luong phan tu fibonacci: "; cin >> n;
					cout << "Day so fibonacci co " << n << " phan tu: \n";
					for (int i = 0; i < n; i++) {
						cout << Fibonacci(i, cnt) << "\t";
					}
					cout << endl;
					cout << "So lan thuc hien de quy: " << cnt << endl;
					break;
				}
				case 5: {
					printArr(check, n);
					cout << "===============SHELL SORT===============\n";
					shell_sort(check, n);
					printArr(check, n);
					break;
				}
				case 0: {
					cout << "Ket thuc mang duoc tao!! \n";
					break;
				}
				default:{
					cout << "Khong hop le!! \n";
					break;
				}
			}
			system("pause");
			delete[] check;
			check = nullptr;
		} while (select != 0);
		cout << "nhap gia tri bat ki de tiep tuc thuc hien, nhap 0 de dung lai"<<endl;
		cin >> choice;
	} while (choice != "0");
	delete[] a;
	a = nullptr;
	system("pause");
	return 0;

}