#include <iostream>
#include <vector>

using namespace std;

class linked_list{
private:
	struct node{
		int data;
		node* prev;
		node* next;
		explicit node(int data):data(data),prev(nullptr),next(nullptr){}
	};
	node* head;
	node* tail;
	void erase(node* m){
		if(m==tail){
			auto temp=tail;
			tail=tail->prev;
			tail->next=nullptr;
			free(temp);
			return;
		}
		auto l = m->prev;
		auto r = m->next;
		l->next=r;
		r->prev=l;
		free(m);
	}
public:
	linked_list():head(nullptr),tail(nullptr){}
	void insert(int key){
		auto temp = new node(key);
		if(!tail){
			head=tail=temp;
			return;
		}
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
	void unique(){
		auto ptr=head;
		while(ptr&&ptr->next){
			while(ptr&&ptr->next&&ptr->data==ptr->next->data)
				erase(ptr->next);
			ptr=ptr->next;
		}
	}
	void print(){
		if(!head){
			cout<<"list empty!!"<<endl;
			return;
		}
		auto ptr = head;
		while(ptr){
			cout<<ptr->data<<' ';
			ptr=ptr->next;
		}
		cout<<endl;
	}
};

int main(){
	linked_list list;
	int i;
	cin>>i;
	while(i!=-1){
		list.insert(i);
		cin>>i;
	}
	list.print();
	list.unique();
	list.print();
}