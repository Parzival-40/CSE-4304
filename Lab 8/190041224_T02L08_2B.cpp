#include <cmath>
#include <iostream>

using namespace std;

int slash(string cash) {
	int x = 0;
	for (int i = 0; i < cash.size(); i++) {
		x += cash[i] * pow(3, i);
	}
	return x;
}

bool rabinKarp(string find, string in) {
	int flash = slash(find);
	string sub = in.substr(0, find.size());
	int clash = slash(sub);
	for (int i = 0, j = find.size(); j <= in.size(); j++) {
		cout << find << "--" << flash << endl;
		cout << sub << "--" << clash << endl;
		if (flash == clash && find == sub) return true;
		clash -= in[i];
		clash /= 3;
		clash += in[j] * pow(3, find.size() - 1);
		sub = in.substr(++i, find.size());
	}
	return false;
}

int main() {
	string in;
	cin >> in;
	string find;
	cin >> find;
	cout << rabinKarp(find, in);
}