#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class int_Stack{
private:
	vector<int> a;
	int i=0;

public:

	int_Stack(int n){
		a.resize(n);
	}

	void print(){

		if(is_Empty()){
			cout<<"0 NULL"<<endl;
			return;
		}

		cout<<size()<<' ';

		for(int j=0;j<size();j++){
			cout<<a[j]<<' ';
		}
		cout<<endl;
	}

	void push(int x){
		if(is_Full())return;
		a[i]=x;
		i++;
	}

	void pop(){
		if(is_Empty())return;
		i--;
	}

	bool is_Empty(){
		return i==0;
	}

	bool is_Full(){
		return size()==a.size();
	}

	int size(){
		return i;
	}

};

void print(stack<int> a){
	if(a.empty()){
		cout<<"0 NULL"<<endl;
		return;
	}

	cout<<a.size()<<' ';

	stack<int> b;

	while(!a.empty()){
		b.push(a.top());
		a.pop();
	}

	while(!b.empty()){
		cout<<b.top()<<' ';
		b.pop();
	}
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	int_Stack a(n);
	stack<int> b;
	int t;
	cin>>t;
	while(t--){
		int c;
		cin>>c;
		if(c==1){
			int x;
			cin>>x;
			a.push(x);
			b.push(x);
			a.print();
			print(b);
		}else if(c==2) {
			a.pop();
			b.pop();
			a.print();
			print(b);
		}
	}
}