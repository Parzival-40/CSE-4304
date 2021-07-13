#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class BST{
private:
	struct node{
		int data;
		node* left;
		node* right;
		node(int data):data(data),left(nullptr),right(nullptr){}
	};
	node* root;
public:
	BST():root(nullptr){}
	bool insert(int x){
		if(!root){
			root = new node(x);
			return true;
		}
		stack<node*> stck;
		node* predecessor=nullptr;
		node* successor=nullptr;
		auto temp = root;
		auto res = new node(x);
		while(temp||!stck.empty()){
			while(temp){
				stck.push(temp);
				temp=temp->left;
			}
			temp=stck.top();
			stck.pop();
			if(res->data>temp->data){
				predecessor=temp;
			}else if(res->data<temp->data){
				successor=temp;
				break;
			}
			temp=temp->right;
		}
		if((predecessor?(res->data-predecessor->data>3):true)&&(successor?(successor->data-res->data>3):true)){
			temp=root;
			while(true){
				if(res->data<temp->data){
					if(temp->left){
						temp=temp->left;
					}else {
						temp->left=res;
						break;
					}
				}else {
					if(temp->right){
						temp=temp->right;
					}else {
						temp->right=res;
						break;
					}
				}
			}
			return true;
		}else {
			free(res);
			return false;
		}
	}
	void print(){
		queue<node*> cue;
		auto temp = root;
		while(temp||!cue.empty()){
			cout<<temp->data<<' ';
			if(temp->left)cue.push(temp->left);
			if(temp->right)cue.push(temp->right);
			if(!cue.empty()){
				temp=cue.front();
				cue.pop();
			}
			else {
				temp=nullptr;
			}
		}
	}
};

int main(){
	BST reservation;
	int x;
	cin>>x;
	while(x!=-1){
		if(!reservation.insert(x)){
			reservation.print();
			cout<<"(Reservation failed)"<<endl;
		}else {
			reservation.print();
			cout<<endl;
		}
		cin>>x;
	}
}
