#include <iostream>

using namespace std;

class BST {
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
	int updateHeight(node* current) {
		return 1 + max(height(current->left), height(current->right));
	}
	int height(node* current) {
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
		cout << current->data << "(" << balanceFactor(current) << ") ";
		print(current->right);
	}
	node* insert(node* current, int& x) {
		if (!current) {
			return new node(x);
		}
		if (x > current->data) {
			current->right = insert(current->right, x);
			current->right->parent = current;
		} else {
			current->left = insert(current->left, x);
			current->left->parent = current;
		}
		current->height = updateHeight(current);
		return current;
	}

public:
	BST()
	  : root(nullptr) {}
	void print() {
		print(root);
	}
	void insert(int& x) {
		root = insert(root, x);
		root->height = updateHeight(root);
	}
};

int main() {
	BST balance;
	int x;
	cin >> x;
	while (x != -1) {
		balance.insert(x);
		balance.print();
		cout << endl;
		cin >> x;
	}
}
