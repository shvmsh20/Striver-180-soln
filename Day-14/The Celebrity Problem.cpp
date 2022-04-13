int findCelebrity(int n) {
	stack<int> st;
	for(int i=0; i<n; i++){
		st.push(i);
	}
	while(st.size()!=1){
		int x = st.top();
		st.pop();
		int y = st.top();
		st.pop();
		if(knows(x, y)){
			st.push(y);
		}else{
			st.push(x);
		}
	}
	int pans = st.top();
	for(int i=0; i<n; i++){
		if(i==pans){
			continue;
		}
		if(knows(pans, i)){
			return -1;
		}
		if(knows(i, pans)==false){
			return -1;
		}
	}
	return pans;
}