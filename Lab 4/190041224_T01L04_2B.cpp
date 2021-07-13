#include <iostream>

using namespace std;

class linked_list{
private:
	struct node{
		int data;
		node* next;
		explicit node(int data):data(data),next(nullptr){}
	};
	node* head;
	node* tail;
public:
	linked_list():head(nullptr),tail(nullptr){}
	void Insert_front(int key){
		auto temp = new node(key);
		if(!head)tail=temp;
		temp->next=head;
		head=temp;
	}
	void Insert_back(int key){
		auto temp = new node(key);
		if(!tail)head=temp;
		tail->next=temp;
		tail=temp;
	}
	void Insert_after_node(int key,int v){
		auto ptr = head;
		while(ptr&&ptr->data!=v){ptr=ptr->next;}
		if(!ptr){
			cout<<v<<" not listed in the list!!"<<endl;
			return;
		}
		auto temp = new node(key);
		temp->next=ptr->next;
		ptr->next=temp;
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
		auto ptr = head;
		while(ptr&&ptr->next->data!=key){ptr=ptr->next;}
		if(!ptr){
			cout<<key<<" not listed in the list!!"<<endl;
			return;
		}
		auto temp=ptr->next;
		ptr->next=temp->next;
		free(temp);
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
		auto ptr = head;
		while(ptr&&ptr->next!=tail){ptr=ptr->next;}
		if(!ptr)return;
		tail=ptr;
		free(ptr->next);
		tail->next=nullptr;
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
	int c=0;
	bool running =true;
	linked_list list;
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
	}
}