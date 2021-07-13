#include <iostream>
#include <vector>

using namespace std;

int bin_search_iter(int x,vector<int>& a){
	int l=0;
	int r=a.size()-1;
	int m=l+(r-l)/2;
	while(l<=r){
		if(a[m]==x){
			return m;
		}
		if(a[m]<x){
			l=m+1;
		}else {
			r=m-1;
		}
		m=l+(r-l)/2;
	}
	return -1;
}

int bin_search_recur(int x,vector<int>& a,int l,int r){
	if(l>r){
		return -1;
	}
	int m=l+(r-l)/2;
	if(a[m]==x){
		return m;
	}
	if(a[m]<x){
		return bin_search_recur(x, a, m+1, r);
	}else {
		return bin_search_recur(x, a, l, m-1);
	}
}

int main(){
	vector<int> a;
	int x;
	while(true){
		cin>>x;
		if(x<0){
			break;
		}
		a.emplace_back(x);
	}
	cin>>x;
	cout<<bin_search_iter(x,a)<<" (using iteration)"<<endl;
	cout<<bin_search_recur(x,a,0,a.size()-1)<<" (using recursion)"<<endl;
}