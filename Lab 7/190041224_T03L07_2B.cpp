#include <iostream>
#include <vector>
using namespace std;

class SegTree {
private:
	vector<pair<int, int>> a;
	int n;
	static int inline range(const int& l, const int& r) {
		return r - l + 1;
	}
	void build(const vector<int>& b, const int& v, const int& l, const int& r) {
		if (l == r) {
			a[v].first = b[l];
			a[v].second = 0;
		} else {
			int m = (l + r) / 2;
			build(b, v * 2, l, m);
			build(b, v * 2 + 1, m + 1, r);
			a[v].first = a[v * 2].first + a[v * 2 + 1].first;
		}
	}
	void update(const int& v, const int& l, const int& r, const int& i, const int& j, const int& add) {
		if (i > j) {
			return;
		}
		if (l == i && r == j) {
			a[v].first += range(l, r) * add;
			a[v].second += add;
			return;
		} else {
			int m = (l + r) / 2;
			update(v * 2, l, m, i, min(m, j), add);
			update(v * 2 + 1, m + 1, r, max(m + 1, i), j, add);
			a[v].first = a[v * 2].first + a[v * 2 + 1].first + range(l, r) * a[v].second;
		}
	}
	int query(const int& v, const int& l, const int& r, const int& i, const int& j, const int& c = 0) {
		if (i > j) {
			return 0;
		}
		if (l == i && r == j) {
			return a[v].first + c * range(l, r);
		}
		int m = (l + r) / 2;
		return query(v * 2, l, m, i, min(m, j), c + a[v].second) +
			   query(v * 2 + 1, m + 1, r, max(m + 1, i), j, c + a[v].second);
	}

public:
	SegTree(vector<int>& b)
	  : n(b.size()) {
		a.resize(4 * n, make_pair(0, 0));
		build(b, 1, 0, n - 1);
	}
	void update(const int& l, const int& r, const int& add) {
		update(1, 1, n, l, r, add);
	}
	int query(const int& l, const int& r) {
		return query(1, 1, n, l, r);
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
		int c, l, r;
		cin >> c >> l >> r;
		if (c == 1) {
			int add;
			cin >> add;
			b.update(l, r, add);
		} else if (c == 2) {
			cout << b.query(l, r) << endl;
		}
	}
}
