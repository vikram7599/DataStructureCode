void add_nodes(TreeNode* root, vector<vector<int>> &left, vector<vector<int>> &right) {
    if(root == NULL) return;
    queue<pair<TreeNode*, int>> q;
    int index;
    int x = 0;
    
    q.push(make_pair(root, x));
    pair<TreeNode*, int> p;
    TreeNode* ptr = new TreeNode(0);
    
    
    while(q.size()) {
        p = q.front();
        x = p.second;
        ptr = p.first;
        
        q.pop();
        if(ptr->left) q.push(make_pair(ptr->left, x-1));
        if(ptr->right) q.push(make_pair(ptr->right, x+1));
        
        if(x < 0) {
            index = abs(x)-1;
            if(index < left.size()) left[index].push_back(ptr->val);
            else {
                left.push_back(vector<int>());
                left[index].push_back(ptr->val);
            }
        }
        else {
            index = x;
            if(index < right.size()) right[index].push_back(ptr->val);
            else {
                right.push_back(vector<int>());
                right[index].push_back(ptr->val);
            }
        }
    }
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    // author : ninja
    vector<vector<int>> left;
    vector<vector<int>> right;
    
    add_nodes(A, left, right);
    
    reverse(left.begin(), left.end());
    left.insert(left.end(), right.begin(), right.end());
    right.clear();
    
    return left;
}