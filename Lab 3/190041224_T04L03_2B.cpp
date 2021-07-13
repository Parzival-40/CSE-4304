#include <iostream>
#include <vector>

using namespace std;

class Min_priority_queue{
private:
	vector<int> a;

	void heapify(int n, int i){
		int min = i;
	    int l = 2 * i + 1;
	    int r = 2 * i + 2;
	  
	    if (l < n && a[l] < a[min])
	    	min = l;
	  
	    if (r < n && a[r] < a[min])
	    	min = r;

	    if (min != i) {
	      swap(a[i], a[min]);
	      heapify(n, min);
	    }
	}

public:

	Min_priority_queue(){}

	void print(){
		for(auto &i:a){
			cout<<i<<' ';
		}
		cout<<endl;
	}
	
	int minimum(){
		return a.front();
	}
	
	int extract(){
		int x=a.front();
		swap(a.front(),a.back());
		a.pop_back();
		heapify(a.size(), 0);
		return x;
	}
	
	void insert(int key){
		a.push_back(key);
		heapify(a.size(), 0);
	}
	void decrease_key(int pos,int key){
		if(a[pos-1]<=key)return;
		a[pos-1]=key;
		heapify(a.size(), 0);
	}
	void increase_key(int pos,int key){
		if(a[pos-1]>=key)return;
		a[pos-1]=key;
		heapify(a.size(), 0);
	}

	bool is_empty(){
		return a.size()==0;
	}
};


int main(){
	int n,k;
	cin>>n>>k;
	Min_priority_queue a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.insert(x);
	}
	int c=0;
	while(!a.is_empty()&&a.minimum()<k){
		int t=a.minimum();
		a.extract();
		a.increase_key(1, t+a.minimum());
		c++;
	}
	cout<<c<<endl;
}