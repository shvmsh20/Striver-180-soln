void sortStack(stack<int> &stack)
{
	
    if(stack.size()==1) return;
    int temp = stack.top();
    stack.pop();
    
    sortStack(stack);
    vector<int> v;
    while(!stack.empty() && stack.top()>temp){
        v.push_back(stack.top());
        stack.pop();
    }
    stack.push(temp);
    for(int i=v.size()-1; i>=0; i--){
        stack.push(v[i]);
    }
    v.clear();
}