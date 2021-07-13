#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main(){
	int n;
	cin>>n;
	
	vector<int> in(n);
	for(auto &i:in)cin>>i;

	queue<int> a;
	stack<int> b;
	
	for(auto &i:in){
		a.push(i);
	}
	
	for(int i=1;i<=n;i++){
		if(!a.empty()&&a.front()==i){
			a.pop();
		}else if(!b.empty()&&b.top()==i){
			b.pop();
		}else{
			while(!a.empty()&&a.front()!=i){
				b.push(a.front());
				a.pop();
			}
			if(!a.empty()&&a.front()==i){
				a.pop();
			}
		}
	}
	cout<<(a.empty()&&b.empty()?"Yes":"No")<<endl;
}