#include<bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n) {
	vector<int> v(n, INT_MIN);
	int width[n];
	stack<int> st;
	for(int i=0; i<n; i++){
		while(!st.empty() && a[st.top()]>=a[i]){
			int index = st.top();
			st.pop();
			int l = st.empty()?-1:st.top();
			width[index] = i-l-1;
		}
		st.push(i);
	}
	while(!st.empty()){
		int index = st.top();
		st.pop();
		int l =  st.empty()?-1:st.top();
		width[index] = n - l -1;
	}
	for(int i=0; i<n; i++){
		
		int range = width[i];
		v[range-1] = max(v[range-1], a[i]);
	}
	for(int i=n-2; i>=0; i--){
		
			v[i] = max(v[i+1], v[i]);
		
	}
	return v;
}