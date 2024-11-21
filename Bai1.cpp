#include <iostream>
#include <vector>
#include <ctime>
#include <functional>
#include <iomanip>
#include <algorithm>
using namespace std;

void ShellSort(int a[], int n) {
	int cnt = 0;
	int x = 0;
	for (int gap = n / 2; gap > 0; gap /= 2) {
		int cnt_insertion_sort = 0;
		cout << "gap thu " << ++x << " : " << endl;
		for (int i = gap; i < n; i++) {
			int tmp = a[i];
			int j = i ;
			while (j >= gap && a[j - gap] > tmp) {
				a[j] = a[j - gap];
				j -= gap;
				cnt_insertion_sort++;
			}
			a[j] = tmp;
		}
		cout << "so lan hoan vi: " << cnt_insertion_sort << endl;
		for (int i = 0; i < n; i++) {
			cout << a[i] << "\t";
		}
		cout << endl;
		++cnt;
	}
	cout << "So lan thuc hien gap: " << cnt << endl;
}

int findMax(int a[], int n) {
	int res = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > res) {
			res = a[i];
		}
	}
	return res;
}





void CountingSort(int a[], int n) {
	int *count;
	int *output;
	int max = findMax(a, n);
	count = new int[max + 1]();
	output = new int[n];

	int demsolanCount = 0;
	int demsolanGan = 0;
	for (int i = 0; i < n; i++) {
		count[a[i]]++ ; 
		demsolanCount++;
	}
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
		demsolanCount++;
	}
	for (int i = n-1; i >= 0; i--) {
		output[count[a[i]] -1] = a[i];
		count[a[i]]--;
		demsolanGan++;
	}

	cout << "So lan thuc hien count: " << demsolanCount << endl;
	cout << "So lan gan: " << demsolanGan << endl;
	for (int i = 0; i < n; i++) {
		cout << output[i] << " ";
	}
	cout << endl;
	delete[] count;
	delete[] output;
}


void CountingSort(long long a[], int n, int exp) {
	int count[10] = { 0 };
	int *output = new int[n];
	int demsolanCount = 0;
	int demsolanGan = 0;
	for (int i = 0; i < n; i++) {
		count[(a[i] / exp) % 10] ++;
		demsolanCount++;
	}
	for (int i = 1; i <= 9; i++) {
		count[i] += count[i - 1];
		demsolanCount++;
	}
	for (int i = n - 1; i >= 0; i--) {
		output[count[(a[i] / exp )% 10] - 1] = a[i];
		count[(a[i] / exp % 10)]--;
		demsolanGan++;
	}

	cout << "So lan thuc hien count: " << demsolanCount << endl;
	cout << "So lan gan: " << demsolanGan << endl;
	for (int i = 0; i < n; i++) {
		cout << output[i] << "\t";
	}
	cout << endl;
	delete[] output;
}

void RadixSort(long long a[], int n) {
	long long max = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	int i = 0;
	for (int exp = 1; max / exp > 0; exp *= 10) {
		cout << "Lan thuc hien thu " << i + 1 << " : " << endl;
		CountingSort(a, n, exp);
	}
}


void CountingSort(vector<double> &buckets) {

}


void InsertionSort(vector<double> &buckets) {
	int n = buckets.size();
	for (int i = 1; i < n; i++) {
		int j = i-1;
		double tmp = buckets[i];
		while (j >= 0 && buckets[j ] > tmp) {
			buckets[j + 1] = buckets[j];
			j--;
		}
		buckets[j + 1] = tmp;
	}
	for (int i = 0; i < n; i++) {
		cout << buckets[i] << "\t";
	}
	cout << endl;
}

void BucketSort(double a[], int n) {
	vector<double> buckets[10005];
	for (int i = 0; i < n; i++) {
		int bi = n*a[i];
		buckets[bi].push_back(a[i]);
	}
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (!buckets[i].empty()) {
			cout << "Lan thuc hien insertion sort thu " << ++x <<" tai bucket thu "<< i << " : " << endl;
			InsertionSort(buckets[i]);
		}
	}
	int cnt = 0;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < buckets[i].size(); j++) {
			a[idx++] = buckets[i][j];
			++cnt;
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << "\t";
		}
		cout << endl;
	}
	cout << "so lan gop cac phan tu: " << cnt<<endl;
}


void automaticallyValue(int a[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 10000 + 1;
	}
}

void automaticallyValue(double a[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = static_cast<double>(rand()) / RAND_MAX;
	}
}

void printArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}
void printArr(double a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}

int main() {
	srand(time(0));
	int choice;
	
	do {
		system("cls");
		cout << "==================MENU===============\n";
		cout << "1. Shell Sort \n";
		cout << "2. Counting Sort \n";
		cout << "3. Radix Sort \n";
		cout << "4. Bucket Sort \n";
		cout << "0. exits \n";
		cout << "=====================================\n";
		cout << "---> Your choice: "; cin >> choice;
		int selection, n, option;
		if (choice > 0 && choice <= 4) {
			do {
				cout << " You want your array values will be automatic(0) or manual(1)?  ";
				cin >> selection;
				if (selection != 0 && selection != 1) {
					cout << "ERROR VALUE!!! \n";
				}
			} while (selection != 0 && selection != 1);
			cout << "So luong phan tu cua mang: ";
			cin >> n;
			if (selection == 0) {
				do {
					cout << "Option: Best (0) or Worst (1) case? \n";
					cin >> option;
					if (option != 0 && option != 1) {
						cout << "ERROR OPTION!!! \n";
					}
				} while (option != 0 && option != 1);
			}
		}
		switch (choice) {
			case 0: {
				cout << "STOP THE MENU !!! \n";
				break;
			}

			//Shell Sort
			case 1: {
				int *a = new int[n];
				if (selection == 0) {
					automaticallyValue(a, n);
					if (option == 0) {
						sort(a, a + n);
						
					}
					else {
						sort(a, a + n, greater<>());
					}
					
				}
				else {
					for (int i = 0; i < n; i++) {
						printf("nhap phan tu a[%d]: ", i);
						cin >> a[i];
					}
				}
			
				cout << "Mang sau khi duoc khoi tao: \n";
				printArr(a, n);
				cout << "---------------------------\n";
				ShellSort(a, n);
				delete[] a;
				break;
			}

			//Counting Sort
			case 2: {
				int *a = new int[n];
				if (selection == 0) {
					automaticallyValue(a, n);
					if (option == 0) {
						for (int i = 0; i < n; i++) {
							a[i] = 1;
						}
					}
					else {
						int max = findMax(a, n);
						a[n - 1] = pow(max, 2);
					}
				}
				else {
					for (int i = 0; i < n; i++) {
						printf("nhap phan tu a[%d]: ", i);
						cin >> a[i];
					}
				}
				cout << "Mang sau khi duoc khoi tao: \n";
				printArr(a, n);
				cout << "---------------------------\n";
				CountingSort(a, n);
				delete[] a;
				break;
			}

			//radix sort
			case 3: {
				long long *a = new long long[n];
				if (selection == 0) {
					if (option == 0) {
						for (int i = 0; i < n; i++) {
							a[i] = rand()%10;
						}
					}
					else {
						for (int i = 0; i < n; i++) {
							a[i] = rand() % 100000 + 1;
						}
					}

				}
				else {
					for (int i = 0; i < n; i++) {
						printf("nhap phan tu a[%d]: ", i);
						cin >> a[i];
					}
				}
				cout << "Mang sau khi duoc khoi tao: \n";
				for (int i = 0; i < n; i++) {
					cout << a[i] << "\t";
				}
				cout << endl;
				cout << "---------------------------\n";
				RadixSort(a, n);
				
				delete[] a;
				break;
			}

			// buckets sort 
			case 4: {
				double *a = new double[n];
				if (selection == 0) {
					automaticallyValue(a, n);
					if(option == 1) {
						for (int i = n-1; i >= 0; i--) {
							a[i] = 0.1 + (n-i-1)*0.000001;
						}
					}
				}
				else {
					for (int i = 0; i < n; i++) {
						printf("nhap phan tu a[%d]: ", i);
						cin >> a[i];
					}
				}
				cout << "Mang sau khi duoc khoi tao: \n";
				printArr(a, n);
				cout << "---------------------------\n";
				BucketSort(a, n);
				delete[] a;
				break;
			}
			default: {
				cout << "YOUR CHOICE IS NOT ACCEPTED \n";
				break;
			}
		}
		system("pause");
	} while (choice != 0);
	
	return 0;
}