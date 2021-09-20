#include <iostream>
#include <vector>
using namespace std;

class Dictionary {
private:
	struct node {
		vector<node*> alpha;
		int isEnd;
		node()
		  : isEnd(0) {
			alpha.resize(26);
			for (auto& i : alpha)
				i = nullptr;
		}
	};
	node* root;
	int countWordsBelow(node* curr) {
		if (!curr) return 0;
		int c = curr->isEnd;
		for (auto& i : curr->alpha) {
			c += countWordsBelow(i);
		}
		return c;
	}

public:
	Dictionary()
	  : root(new node){};
	void insert(string& word) {
		node* temp = root;
		for (auto& i : word) {
			if (!temp->alpha[i - 'a']) temp->alpha[i - 'a'] = new node;
			temp = temp->alpha[i - 'a'];
		}
		temp->isEnd++;
	}
	int countWordsWithPrefix(string& prefix) {
		node* temp = root;
		for (auto& i : prefix) {
			if (!temp->alpha[i - 'a']) return 0;
			temp = temp->alpha[i - 'a'];
		}
		return countWordsBelow(temp);
	}
};

string& toLower(string& s) {
	for (auto& i : s) {
		if (i >= 'A' && i <= 'Z') {
			i += 32;
		}
	}
	return s;
}

int main() {
	int n, q;
	cin >> n >> q;
	Dictionary dictionary;
	string word;
	for (int i = 0; i < n; i++) {
		cin >> word;
		dictionary.insert(toLower(word));
	}
	string prefix;
	for (int i = 0; i < q; i++) {
		cin >> prefix;
		cout << dictionary.countWordsWithPrefix(toLower(prefix)) << endl;
	}
}