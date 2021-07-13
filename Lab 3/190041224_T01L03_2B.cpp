#include <iostream>
#include <vector>

using namespace std;

class l_queue{
private:
	vector<int> a;
	int i,j;
public:
	l_queue(int n):i(-1),j(-1){
		a.resize(n);
	}
	
	int front(){
		if(is_empty()){
			return INT_MIN;
		}
		return a[i+1];
	}

	void enqueue(int x){
		if(is_full())return;
		j++;
		a[j]=x;
	}

	void dequeue(){
		if(is_empty())return;
		i++;
	}
	
	bool is_empty(){
		return i==j;
	}
	
	bool is_full(){
		return j==a.size()-1;
	}

};

class c_queue{
private:
	vector<int> a;
	int i,j;
public:
	c_queue(int n):i(-1),j(-1){
		a.resize(n);
	}

	int front(){
		if(is_empty()){
			return INT_MIN;
		}
		return a[i];
	}

	void enqueue(int x){
		if(is_full())return;
		if(i==-1)i++;
		j=(j+1)%a.size();
		a[j]=x;
	}

	void dequeue(){
		if(is_empty())return;
		if(i==j){
			i=j=-1;
			return;
		}
		i=(i+1)%a.size();
	}
	
	bool is_empty(){
		return i==-1;
	}
	
	bool is_full(){
		return i==(j+1)%a.size();
	}

};

int main(){
	int n;
	cin>>n;
	l_queue l(n);
	c_queue c(n);
	int x=1;
	while(x){
		cin>>x;
		if(x==1){
			cin>>x;
			l.enqueue(x);
			c.enqueue(x);
			if(l.front()==INT_MIN){
				cout<<"empty"<<endl;
			}else
				cout<<l.front()<<endl;
			if(c.front()==INT_MIN){
				cout<<"empty"<<endl;
			}else
				cout<<c.front()<<endl;
		}else if(x==2){
			l.dequeue();
			c.dequeue();
			if(l.front()==INT_MIN){
				cout<<"empty"<<endl;
			}else
				cout<<l.front()<<endl;
			if(c.front()==INT_MIN){
				cout<<"empty"<<endl;
			}else
				cout<<c.front()<<endl;
		}
		cout<<endl;
	}
}