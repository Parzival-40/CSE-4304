#include <iostream>

using namespace std;

class BST{
private:
	struct node{
		int data;
		node* left;
		node* right;
		node(int x):data(x),left(nullptr),right(nullptr){}
	};
	node* root;
	node* insert(node* current,int& x){
		if(!current){
			return new node(x);
		}
		if(x>current->data){
			current->right=insert(current->right,x);
		}else{
			current->left=insert(current->left,x);
		}
		return current;
	}
	int height(node* current){
		if(!current)return 0;
		return max(1+height(current->left),1+height(current->right));
	}
public:
	BST():root(nullptr){}
	void insert(int& x){
		if(!root){
			root=new node(x);
			return;
		}
		insert(root,x);	
	}
	int height(){
		return height(root)-1;
	}
};

int main(){
	BST enemy;
	int x;
	cin>>x;
	while(x!=-1){
		enemy.insert(x);
		cin>>x;
	}
	cout<<enemy.height()<<endl;
}
