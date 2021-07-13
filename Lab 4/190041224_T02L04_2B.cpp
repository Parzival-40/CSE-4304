#include <iostream>

using namespace std;

class double_linked_list{
private:
	struct node{
		int data;
		node* prev;
		node* next;
		explicit node(int data):data(data),prev(nullptr),next(nullptr){}
	};
	node* head;
	node* tail;
public:
	double_linked_list():head(nullptr),tail(nullptr){}
	void Insert_front(int key){
		auto temp = new node(key);
		if(!head){
			head=tail=temp;
			return;
		}
		head->prev=temp;
		temp->next=head;
		head=temp;
	}
	void Insert_back(int key){
		auto temp = new node(key);
		if(!tail){
			head=tail=temp;
			return;
		}
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
	void Insert_after_node(int key,int v){
		auto l = head;
		while(l&&l->data!=v){l=l->next;}
		if(!l){
			cout<<v<<" not listed in the list!!"<<endl;
			return;
		}
		auto r=l->next;
		auto m = new node(key);
		m->next=r;
		m->prev=l;
		l->next=m;
		r->prev=m;
	}
	void Update_node(int key,int v){
		auto ptr = head;
		while(ptr&&ptr->data!=v){ptr=ptr->next;}
		if(!ptr){
			cout<<v<<" not listed in the list!!"<<endl;
			return;
		}
		ptr->data=key;
	}
	void Remove_element(int key){
		auto m = head;
		while(m&&m->data!=key){m=m->next;}
		if(!m){
			cout<<key<<" not listed in the list!!"<<endl;
			return;
		}
		auto l=m->prev;
		auto r=m->next;
		l->next=r;
		r->prev=l;
		free(m);
	}
	void Remove_end(){
		if(head==tail){
			if(!head){
				cout<<"list empty!!"<<endl;
				return;
			}
			free(head);
			head=tail=nullptr;
			return;
		}
		auto temp=tail;
		tail=tail->prev;
		tail->next=nullptr;
		free(temp);
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
	void rprint(){
		if(!head){
			cout<<"list empty!!"<<endl;
			return;
		}
		auto ptr = tail;
		while(ptr){
			cout<<ptr->data<<' ';
			ptr=ptr->prev;
		}
		cout<<endl;
	}
};

int main(){
	int c=0;
	bool running =true;
	double_linked_list list;
	while(running){
		cin>>c;
		int key,v;
		switch(c){
			case 1:
			cin>>key;
			list.Insert_front(key);
			break;
			case 2:
			cin>>key;
			list.Insert_back(key);
			break;
			case 3:
			cin>>key>>v;
			list.Insert_after_node(key,v);
			break;
			case 4:
			cin>>key>>v;
			list.Update_node(key,v);
			break;
			case 5:
			cin>>key;
			list.Remove_element(key);
			break;
			case 6:
			list.Remove_end();
			break;
			case 7:
			running=false;
			break;
			default:
			break;
		}
		list.print();
		list.rprint();
	}
}