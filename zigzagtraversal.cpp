vector<int> zigZagTraversal(Node* root)
{
	// Code here
	stack<Node*> s1,s2;
	vector<int> ans;
	int flag = 1;
	s1.push(root);
	while(!s1.empty() || !s2.empty()) {
	    if(flag) {
	        while(!s1.empty()) {
	            auto t = s1.top();
	            s1.pop();
	            ans.push_back(t->data);
	            if(t->left) s2.push(t->left);
	            if(t->right) s2.push(t->right);
	        } 
	        flag = 0;
	    }
	    else {
	        while(!s2.empty()) {
	            auto t = s2.top();
	            s2.pop();
	            ans.push_back(t->data);
	            if(t->right) s1.push(t->right);
	            if(t->left) s1.push(t->left);
	        }
	        flag = 1;
	    }
	}
	return ans;
}