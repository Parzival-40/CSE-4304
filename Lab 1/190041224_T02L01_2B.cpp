#include <iostream>
#define ull unsigned long long

using namespace std;

ull factorial_iter(ull n){
	if(!n){
		return 1;
	}
	ull mul=1;
	do{
		mul*=n;
	}while(--n);
	return mul;
}

ull factorial_recur(ull n){
	if(!n){
		return 1;
	}
	return n*factorial_recur(n-1);
}

int main(){
	ull n;
	cin>>n;
	cout<<factorial_iter(n)<<" (using iteration)"<<endl;
	cout<<factorial_recur(n)<<" (using recursion)"<<endl;
}