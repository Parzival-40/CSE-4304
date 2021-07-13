#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack<int> ex;
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		for(auto &i:s){
			if(isdigit(i)){
				ex.push(i-'0');
			}else{
				int x;
				int y;
				y=ex.top();
				ex.pop();
				x=ex.top();
				ex.pop();
				switch(i){
					case '+':
					{
						ex.push(x+y);
						break;
					}
					case '-':
					{
						ex.push(x-y);
						break;
					}
					case '*':
					{
						ex.push(x*y);
						break;
					}
					case '/':
					{
						ex.push(x/y);
						break;
					}
					default:
					break;
				}
			}
		}
		cout<<ex.top()<<endl;
		ex.pop();
	}	
}