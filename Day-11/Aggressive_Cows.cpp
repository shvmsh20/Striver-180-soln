//T/C: O(nlog(n))

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPoss(vector<int> &v, int chck, int c){
	int coor = v[0], count=1;
	for(int i=1; i<v.size(); i++){
		if(v[i]-coor>=chck){
			count++;
			coor = v[i];
		}
	}
	return count>=c;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		int n, c, res=-1;
		cin >> n >> c;
		vector<int> v;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		int l=1, h=v[n-1]-v[0];
		while(l<=h){
			int mid = (l+h)/2;
			if(isPoss(v, mid, c)){
				res=mid;
				l = mid+1;
			}else{
				h = mid-1;
			}
		}
		cout <<  res << endl;
	}
	return 0;
}