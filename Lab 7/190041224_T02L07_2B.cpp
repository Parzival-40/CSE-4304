#include <iostream>
#include <vector>
using namespace std;

class SegTree {
private:
	vector<int> a;
	int n;
	void build(vector<int>& b, int v, int l, int r) {
		if (l == r) {
			a[v] = b[l];
		} else {
			int m = (l + r) / 2;
			build(b, v * 2, l, m);
			build(b, v * 2 + 1, m + 1, r);
			a[v] = a[v * 2] + a[v * 2 + 1];
		}
	}
	int sum(int v, int l, int r, int i, int j) {
		if (i > j) {
			return 0;
		}
		if (l == i && r == j) {
			return a[v];
		}
		int m = (l + r) / 2;
		return sum(v * 2, l, m, i, min(j, m)) +
			   sum(v * 2 + 1, m + 1, r, max(i, m + 1), j);
	}
	void update(int v, int l, int r, int pos, int new_val) {
		if (l == r) {
			a[v] = new_val;
		} else {
			int m = (l + r) / 2;
			if (pos <= m)
				update(v * 2, l, m, pos, new_val);
			else
				update(v * 2 + 1, m + 1, r, pos, new_val);
			a[v] = a[v * 2] + a[v * 2 + 1];
		}
	}

public:
	SegTree(vector<int>& b)
	  : n(b.size()) {
		a.resize(4 * n, 0);
		build(b, 1, 0, n - 1);
	}
	int sum(int l, int r) {
		return sum(1, 1, n, l, r);
	}
	void update(int pos, int new_val) {
		update(1, 1, n, pos, new_val);
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto& i : a)
		cin >> i;
	SegTree b(a);
	while (q--) {
		int i;
		cin >> i;
		switch (i) {
		case 1: {
			int pos;
			cin >> pos;
			cout << a[pos - 1];
			a[pos - 1] = 0;
			b.update(pos, a[pos - 1]);
			cout << " ( ";
			for (auto& i : a)
				cout << i << ' ';
			cout << ')' << endl;
			break;
		}
		case 2: {
			int pos, add;
			cin >> pos >> add;
			a[pos - 1] += add;
			b.update(pos, a[pos - 1]);
			for (auto& i : a)
				cout << i << ' ';
			cout << endl;
			break;
		}
		case 3: {
			int i, j;
			cin >> i >> j;
			cout << b.sum(i, j) << endl;
			break;
		}
		}
	}
}
