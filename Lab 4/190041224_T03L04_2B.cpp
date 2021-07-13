#include <iostream>

using namespace std;

class dequeue{
private:
	struct node{
		int data;
		node* prev;
		node* next;
		explicit node(int data):data(data),prev(nullptr),next(nullptr){}
	};
	node* head;
	node* tail;
	int _size;
public:
	dequeue():head(nullptr),tail(nullptr),_size(0){}
	bool is_empty(){return _size==0;}
	int size(){return _size;}
	void push_front(int key){
		auto temp = new node(key);
		if(!head){
			head=tail=temp;
			_size++;
			return;
		}
		head->prev=temp;
		temp->next=head;
		head=temp;
		_size++;
	}
	void push_back(int key){
		auto temp = new node(key);
		if(!tail){
			head=tail=temp;
			_size++;
			return;
		}
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
		_size++;
	}
	void pop_back(){
		if(is_empty()){
			cout<<"Dequeue empty!!"<<endl;
			return;
		}
		auto temp=tail;
		tail=tail->prev;
		tail->next=nullptr;
		free(temp);
		_size--;
	}
	void pop_front(){
		if(is_empty()){
			cout<<"Dequeue empty!!"<<endl;
			return;
		}
		auto temp=head;
		head=head->next;
		head->prev=nullptr;
		free(temp);
		_size--;
	}
	void print(){
		if(is_empty()){
			cout<<"Dequeue empty!!"<<endl;
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
	bool running = true;
	dequeue deck;
	while(running){
		cin>>c;
		int key;
		switch(c){
			case 1:
			cin>>key;
			deck.push_front(key);
			break;
			case 2:
			deck.push_back(key);
			break;
			case 3:
			deck.pop_front();
			break;
			case 4:
			deck.pop_back();
			break;
			case 5:
			running = false;
			break;
			default:
			break;
		}
		deck.print();
	}
}