#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
	vector<int> a;
	int x;
	while(true){
		cin>>x;
		if(!x){
			break;
		}
		a.emplace_back(x);
	}
	cin>>x;
	vector<pair<int,int>> w;
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++){
			if(a[i]+a[j]==x){
				w.emplace_back(make_pair(i+1, j+1));
			}
		}
	}
	if(!w.size()){
		cout<<"No pair found!"<<endl;
	}else {
		cout<<w.size()<<(w.size()>1?" Pairs:":" Pair:")<<endl;
		for(auto &i:w){
			cout<<"(worker-"<<i.first<<", worker-"<<i.second<<")"<<endl;
		}	
	}
}