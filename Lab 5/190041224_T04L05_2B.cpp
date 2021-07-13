#include <iostream>

using namespace std;

class BST{
private:
	struct node{
		int data;
		int lsubtree_size;
		int rsubtree_size;
		node* left;
		node* right;
		node(int x):data(x),left(nullptr),right(nullptr),lsubtree_size(0),rsubtree_size(0){}
	};
	node* root;
	node* insert(node* current,int& x){
		if(!current){
			return new node(x);
		}
		if(x>current->data){
			current->rsubtree_size++;
			current->right=insert(current->right,x);
		}else{
			current->lsubtree_size++;
			current->left=insert(current->left,x);
		}
		return current;
	}
	int before(node* current, int& x){
		if(!current)return 0;
		if(x<current->data){
			return before(current->left, x);
		}
		else if(x>current->data){
			return 1+current->lsubtree_size+before(current->right,x);
		}else{
			return current->lsubtree_size;
		}
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
	int before(int& x){
		return before(root,x);
	}
};

int main(){
	BST reservation;
	int x;
	cin>>x;
	while(x!=-1){
		reservation.insert(x);
		cin>>x;
	}
	int t;
	cin>>t;
	while(t--){
		cin>>x;
		cout<<reservation.before(x)<<endl;
	}
}
