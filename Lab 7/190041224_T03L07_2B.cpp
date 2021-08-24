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
			a[v] = 0;
		}
	}
	void update(int v, int l, int r, int i, int j, int add) {
		if (i > j) {
			return;
		}
		if (l == i && r == j) {
			a[v] += add;
		} else {
			int m = (l + r) / 2;
			update(v * 2, l, m, i, min(m, j), add);
			update(v * 2 + 1, m + 1, r, max(m + 1, i), j, add);
		}
	}
	int get(int v, int l, int r, int pos) {
		if (l == r) {
			return a[v];
		}
		int m = (l + r) / 2;
		if (pos > m)
			return a[v] + get(v * 2 + 1, m + 1, r, pos);
		else
			return a[v] + get(v * 2, l, m, pos);
	}

public:
	SegTree(vector<int>& b)
	  : n(b.size()) {
		a.resize(4 * n, 0);
		build(b, 1, 0, n - 1);
	}
	void update(int l, int r, int add) {
		update(1, 1, n, l, r, add);
	}
	int get(int pos) {
		return get(1, 1, n, pos);
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
		int l, r, add;
		cin >> l >> r >> add;
		b.update(l, r, add);
		for (int i = 1; i <= n; i++) {
			cout << b.get(i) << ' ';
		}
		cout << endl;
	}
}
