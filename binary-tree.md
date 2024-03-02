# Binary Trees
## types
1. full bt - each node has 0/2 children
2. complete bt - each level is completely filled xcpt last level (which must have nodes as left as possible)
3. perfect bt - all leaf nodes are at same level
4. balanced bt - height = log n (no of nodes)
5. degenerate - like a linked list, each node has  only 1 child
## traversals
### dfs
1. inorder - left root right
2. pre-order - root left right
3. post-order -  left right root
### bfs 
just write level by level
## preorder
recursive
```
void preorder(TreeNode* root, vector<int> &v) {
        if (root==NULL) return;
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }
```
iterative
```
vector<int> preorderTraversal(TreeNode* root) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        vector<int> ans;
        stack<TreeNode*> st;
        if (root==NULL) return {};
        st.push(root);
        while(!st.empty()) {
            TreeNode* curr = st.top();
            ans.push_back(curr->val);
            st.pop();
            if (curr->right!=NULL) st.push(curr->right);
            if (curr->left!=NULL) st.push(curr->left);
        }
        return ans;
    }
```