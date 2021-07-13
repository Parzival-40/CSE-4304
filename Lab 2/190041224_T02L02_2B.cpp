#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	stack<char> a;
	while(n--){
		cin>>s;
		for(auto &i:s){
			a.push(i);
		}
		while(!a.empty()){
			cout<<a.top();
			a.pop();
		}
		cout<<endl;
	}
}