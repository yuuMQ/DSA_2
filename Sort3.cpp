#include <bits/stdc++.h>
using namespace std;

void xuat(int a[], int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}
void xuat(float a[], int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

//shell sort
void shell_sort(int a[], int n){
    for(int gap = n/2; gap >0; gap/=2){
        for(int i=gap; i<n; i++){
            int j = i;
            int x = a[i];
            while(j>0 && x < a[j-1]){
                a[j] = a[j-1];
                --j;
            }
            a[j] = x;
        }
    }
}

int find_max(int a[], int n){
    int max = 0;
    for(int i=1; i<n; i++){
        if(a[i] > max) max = a[i];
    }
    return max;
}

//Counting sort
void counting_sort(int a[], int n){
    int max = find_max(a, n);
    int count[max+1];
    int output[n];
    for(int i=0; i<=max; i++){
        count[i] = 0;
    }
    for(int i=0; i<n; i++){
        count[a[i]]++;
    }
    for(int i=1; i<=max; i++){
        count[i] += count[i-1];
    }
    for(int i=n-1; i>=0; i--){
        output[count[a[i]]-1] = a[i];
        count[a[i]]--; 
    }
    xuat(output, n);
}

void counting_sort_2(int a[], int n, int exp){
    int max = 0;
    for(int i=0; i<=n; i++){
        if(a[i]%(exp*10) > max){
            max = a[i]%(exp*10);
        }
    }
    int count[max+1]={0};
    int output[n];
    for(int i=0; i<n; i++){
        count[a[i]%(exp*10)]++;
    }
    for(int i=1; i<=max; i++){
        count[i] += count[i-1];
    }
    for(int i=n-1; i>=0; i--){
        output[count[a[i]%(exp*10)]-1] = a[i];
        count[a[i]%(exp*10)]--;
    }
    for(int i=0; i<n; i++){
        a[i] = output[i];
    }
}

//Radix sort
void radix_sort(int a[], int n){
    int max = find_max(a, n);
    for(int exp=1; max/exp>0; exp*=10){
        counting_sort_2(a, n, exp);
    }
}

void insertion_sort(vector<float>& v){
    int n = v.size();
	for(int i=1; i<n; i++){
		int j = i-1;
		float tmp = v[i];
		while(j>=0 && v[j] > tmp){
			v[j+1] = v[j];
			--j;
		}
		v[j+1] = tmp;
	}
}

//bucket sort
void bucket_sort(float a[], int n){
    vector<float> b[n];
    for(int i=0; i<n; i++){
        int bi = n*a[i];
        b[bi].push_back(a[i]);
    }
    for(int i=0; i<n; i++){
        insertion_sort(b[i]);
    }
    int idx = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<b[i].size(); j++){
            a[idx++] = b[i][j];
        }
    }
}
int main(){
    float a[] = {0.42, 0.32, 0.25, 0.92, 0.65, 0.45, 0.75};
    int n = sizeof(a) / sizeof(a[0]);
    bucket_sort(a, n);
    xuat(a, n);
}