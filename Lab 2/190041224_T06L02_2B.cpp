#include <iostream>
#include <stack>

using namespace std;

bool is_openning(char i){
	return i=='('||i=='{'||i=='[';
}

bool is_closing(char i){
	return i==')'||i=='}'||i==']';
}

int braces(char i){
	switch(i){
		case '(':
		case ')':
		return 1;
		case '{':
		case '}':
		return 2;
		case '[':
		case ']':
		return 3;
		default:
		return 0;
	}
}

int main(){
	string s;
	stack<char> a;
	getline(cin,s);
	int ans = 0;
	for(auto &i:s){
		if(is_openning(i)){
			a.push(i);
		}else if(is_closing(i)){
			if(!a.empty()&&braces(a.top())==braces(i)){
				a.pop();
			}else {
				ans++;
			}
		}
	}
	cout<<ans+a.size()<<endl;
}