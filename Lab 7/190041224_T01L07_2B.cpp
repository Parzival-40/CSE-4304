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
			a[v] = min(a[v * 2], a[v * 2 + 1]);
		}
	}
	int mini(int v, int l, int r, int i, int j) {
		if (i > j) {
			return INT_MAX;
		}
		if (l == i && r == j) {
			return a[v];
		}
		int m = (l + r) / 2;
		return min(mini(v * 2, l, m, i, min(m, j)),
				   mini(v * 2 + 1, m + 1, r, max(i, m + 1), j));
	}

public:
	SegTree(vector<int>& b)
	  : n(b.size()) {
		a.resize(4 * n, INT_MAX);
		build(b, 1, 0, n - 1);
	}
	int mini(int l, int r) {
		return mini(1, 1, n, l, r);
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
		int i, j;
		cin >> i >> j;
		cout << b.mini(i, j) << endl;
	}
}
