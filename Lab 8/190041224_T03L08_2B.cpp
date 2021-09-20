#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
	vector<int> table;
	int size;
	const int prime = 37;
	int (HashTable::*hashes[3])(int& x, int& i) = {&HashTable::linear,
												   &HashTable::quadratic,
												   &HashTable::_double};
	int inline _hash(const int& x) {
		return x % table.size();
	}
	int inline sec_hash(const int& x) {
		return prime - x % prime;
	}
	int inline linear(int& x, int& i) {
		return _hash(x + i / i);
	}
	int inline quadratic(int& x, int& i) {
		return _hash(x + i * i);
	}
	int inline _double(int& x, int& i) {
		return _hash(x + sec_hash(i * i));
	}
	int probe(int& c, int& x) {
		int attempts = 6;
		for (int i = 1, hash = _hash(x); i <= attempts; i++) {
			if (!table[hash]) {
				table[hash] = x;
				return hash;
			}
			cout << "Collision: Index-" << hash << endl;
			hash = (this->*hashes[c - 1])(hash, i);
		}
		cout << "Input Abandoned! Reached Maximum Number of Attempts!!" << endl;
		return 0;
	}

public:
	HashTable(int& n)
	  : size(0) {
		table.resize(n, 0);
	}
	double loadFactor() {
		return (double)size / table.size();
	}
	void insert(int c, int x) {
		if (size >= table.size()) {
			cout << "Input Abandoned! Table Full!!" << endl;
			return;
		}
		int p = probe(c, x);
		if (!p) {
			return;
		}
		size++;
		cout << "Inserted : Index-" << p << " (L.F.=" << loadFactor() << ")" << endl;
	}
	void display() {
		for (auto& i : table)
			cout << i << ' ';
		cout << endl;
	}
};
int main() {
	int c, n, q;
	cin >> c >> n >> q;
	HashTable table(n);
	while (q--) {
		int x;
		cin >> x;
		table.insert(c, x);
	}
	// table.display();
}