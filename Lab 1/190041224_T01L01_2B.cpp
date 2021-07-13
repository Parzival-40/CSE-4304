#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
	return a.second>b.second || (a.second==b.second?a.first<b.first:false);
}

int main(){
	vector<pair<int,int>> a(9);
	int x;
	while(true){
		cin>>x;
		if(x<1){
			break;
		}
		a[x-1].first=x;
		a[x-1].second++;
	}
	sort(a.begin(),a.end(),comp);
	for(auto &i:a){
		cout<<i.first<<" Occurs "<<i.second<<(i.second>1?" times":" time")<<endl;
	}
}