#include <iostream>
#include <stack>

using namespace std;

class tw_stk_q{
private:
	stack<int> a,b;
	int size,c;
	bool o=false,u=false;
public:
	tw_stk_q(int n):c(0),size(n){}

	int front(){
		return b.top();
	}

	void enqueue(int x){
		if(is_full()){
			o=true;
			return;
		}
		while(!b.empty()){
			a.push(b.top());
			b.pop();
		}
		a.push(x);
		while(!a.empty()){
			b.push(a.top());
			a.pop();
		}
		c++;
		u=false;
	}
	void dequeue(){
		if(is_empty()){
			u=true;
			return;
		}
		b.pop();
		c--;
		o=false;
	}
	void print(){
		cout<<"Size:"<<c<<" elements: ";
		if(c==0)cout<<"NULL"<<endl;
		else if(u)cout<<"Underflow !"<<endl;
		else if(o)cout<<"Overflow !"<<endl;
		else {
			stack<int> t;
			while(!b.empty()){
				cout<<b.top()<<' ';
				t.push(b.top());
				b.pop();
			}
			cout<<endl;
			while(!t.empty()){
				b.push(t.top());
				t.pop();
			}
		}
	}
	bool is_empty(){
		return b.empty();
	}
	bool is_full(){
		return c==size;
	}
};

int main(){
	int n;
	cin>>n;
	tw_stk_q a(n);
	int q;
	cin>>q;
	while(q){
		int x;
		cin>>x;
		if(x==1){
			cin>>x;
			a.enqueue(x);
			a.print();
			q--;
		}else if(x==2){
			a.dequeue();
			a.print();
			q--;
		}
	}
}