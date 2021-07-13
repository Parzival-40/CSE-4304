#include <iostream>

using namespace std;

class AVL {
private:
	struct node {
		int data;
		int height;
		node* parent;
		node* left;
		node* right;
		node(int x)
		  : height(0),
			data(x),
			parent(nullptr),
			left(nullptr),
			right(nullptr) {}
	};
	node* root;

	void leftRotate(node* nodeToRotate) {
		node* temp = nodeToRotate->right;
		nodeToRotate->right = nullptr;
		if (nodeToRotate == root) {
			root = temp;
		}
		node* parent = nodeToRotate->parent;
		nodeToRotate->parent = nullptr;
		temp->parent = parent;
		if (parent) {
			if (nodeToRotate == parent->right) {
				parent->right = temp;
			} else if (nodeToRotate == parent->left) {
				parent->left = temp;
			}
		}
		insert(temp, nodeToRotate);
	}
	void rightRotate(node* nodeToRotate) {
		node* parent = nodeToRotate->parent;
		node* temp = nodeToRotate->left;
		nodeToRotate->parent = nullptr;
		nodeToRotate->left = nullptr;
		if (parent) {
			if (nodeToRotate == parent->right) {
				parent->right = temp;
			} else if (nodeToRotate == parent->left) {
				parent->left = temp;
			}
		}
		temp->parent = parent;
		if (nodeToRotate == root) {
			root = temp;
		}
		insert(temp, nodeToRotate);
	}
	void insert(node* insertInto, node* nodeToInsert) {
		if (nodeToInsert->data > insertInto->data) {
			if (insertInto->right)
				insert(insertInto->right, nodeToInsert);
			else {
				insertInto->right = nodeToInsert;
				nodeToInsert->parent = insertInto;
				nodeToInsert->height = updateHeight(nodeToInsert);
			}
		} else {
			if (insertInto->left)
				insert(insertInto->left, nodeToInsert);
			else {
				insertInto->left = nodeToInsert;
				nodeToInsert->parent = insertInto;
				nodeToInsert->height = updateHeight(nodeToInsert);
			}
		}
		insertInto->height = updateHeight(insertInto);
		balance(insertInto);
	}
	void balance(node* current) {
		if (balanceFactor(current) < -1) {
			leftRotate(current);
		} else if (balanceFactor(current) > 1) {
			rightRotate(current);
		}
	}
	int updateHeight(node* current) {
		return 1 + max(height(current->left), height(current->right));
	}
	int height(node*& current) {
		if (!current) return -1;
		return current->height;
	}
	int balanceFactor(node* current) {
		return height(current->left) - height(current->right);
	}
	void print(node* current) {
		if (!current) {
			return;
		}
		print(current->left);
		cout << current->data
			 << "(" << balanceFactor(current) << ") ";
		print(current->right);
	}
	void insert(node* current, int& x) {
		if (x > current->data) {
			if (current->right)
				insert(current->right, x);
			else {
				current->right = new node(x);
				current->right->parent = current;
			}
		} else {
			if (current->left)
				insert(current->left, x);
			else {
				current->left = new node(x);
				current->left->parent = current;
			}
		}
		current->height = updateHeight(current);
		balance(current);
	}

	node* find(node* in, int& x) {
		if (!in) {
			return nullptr;
		}
		if (x > in->data) {
			return find(in->right, x);
		} else if (x < in->data) {
			return find(in->left, x);
		} else {
			return in;
		}
	}

	node* lca(node* x, int& y) {
		if (!find(x, y)) {
			return lca(x->parent, y);
		} else {
			return x;
		}
	}

public:
	AVL()
	  : root(nullptr) {}
	void print() {
		print(root);
		cout << endl;
	}
	void insert(int& x) {
		if (!root) {
			root = new node(x);
			return;
		}
		insert(root, x);
	}
	int lca(int& x, int& y) {
		return lca(find(root, x), y)->data;
	}
};

int main() {
	AVL tree;
	int x;
	cin >> x;
	while (x != -1) {
		tree.insert(x);
		cin >> x;
	}
	cout << "Status: ";
	tree.print();
	int t;
	cin >> t;
	int y;
	while (t--) {
		cin >> x >> y;
		cout << tree.lca(x, y) << endl;
	}
}
