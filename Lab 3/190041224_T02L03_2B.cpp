#include <iostream>
#include <vector>

using namespace std;
class MaxHeap{
private:
	vector<int> a;
public:
	MaxHeap(vector<int> x){
		a=x;
	}
	void heapify(int n, int i){
		int max = i;
	    int l = 2 * i + 1;
	    int r = 2 * i + 2;
	  
	    if (l < n && a[l] > a[max])
	    	max = l;
	  
	    if (r < n && a[r] > a[max])
	    	max = r;

	    if (max != i) {
	      swap(a[i], a[max]);
	      heapify(n, max);
	    }
	}

	void Build_max_heap(){
		for (int i = a.size() / 2 - 1; i >= 0; i--)
	    	heapify(a.size(), i);
	}

	void heap_sort(){
		
		Build_max_heap();

	  	for (int i = a.size() - 1; i >= 0; i--) {
	    	swap(a[0], a[i]);
	    	heapify(i, 0);
	    }
	}

	void print(){
		for(auto &i:a){
			cout<<i<<' ';
		}
		cout<<endl;
	}
};


int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i:a)cin>>i;
	MaxHeap h(a);
	h.heap_sort();
	h.print();
}