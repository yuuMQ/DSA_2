#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

string vobanh[2] = { "day", "mong" };
string cheese[3] = { "Italian", "Portuguese", "French" };
string topping[6] = { "A", "B", "C", "D", "E", "F" };
string sauces[2] = { "cay", "mat ong" };

vector<string> Menu_Pizza;


string pizza[4];
void menu() {
	int cnt = 0;
	int cnt_vobanh = 0, cnt_cheese = 0, cnt_topping = 0, cnt_sauces = 0;

	// full topping
	for (string &vb : vobanh) {
		for (string &c : cheese) {
			for (string &tp : topping) {
				for (string &s : sauces) {
					Menu_Pizza.push_back("\n----PIZZA-----\nDe banh: " + vb);
					Menu_Pizza.push_back("\n----PIZZA-----\nDe banh: " + vb + "\nCheese: " + c + "\n------------\n");
					Menu_Pizza.push_back("\n----PIZZA-----\nDe banh: " + vb + "\nCheese: " + c + "\nTopping: " + tp + "\n------------\n");
					Menu_Pizza.push_back("\n----PIZZA-----\nDe banh: " + vb + "\nCheese: " + c + "\nSauce: " + s + "\n------------\n");
					Menu_Pizza.push_back("\n----PIZZA-----\nDe banh: " + vb + "\nCheese: " + c + "\nTopping: " + tp + "\nSauce: " + s + "\n------------\n");
					Menu_Pizza.push_back("\n----PIZZA-----\nDe banh: " + vb + "\nTopping: " + tp + "\n------------\n");
					Menu_Pizza.push_back("\n----PIZZA-----\nDe banh: " + vb + "\nSauce: " + s + "\n------------\n");
					Menu_Pizza.push_back("\n----PIZZA-----\nDe banh: " + vb + "\nTopping: " + tp + "\nSauce: " + s + "\n------------\n");
					cnt += 8;
				}
			}
		}
	}

	
	cout << "\n--------------MENU PIZZA---------------\n";
	for (auto x : Menu_Pizza) {
		cout << x;
	}

	cout << "Co tong cong: " << cnt << " cai pizza \n";
	cout << "Do phuc tap: O(" << 2 * 3 * 6 * 2 << ")" << " hay O(2*N) " << endl;
}




int main() {
	menu();
	system("pause");
	return 0;
}