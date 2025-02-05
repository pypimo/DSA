## dfs
1. inorder - left root right
2. pre-order - root left right
3. post-order -  left right root
### preorder
recursive
```cpp
void preorder(TreeNode* root, vector<int> &v) {
        if (root==NULL) return;
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }
```
iterative
```cpp
vector<int> preorderTraversal(TreeNode* root) {    
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
### inorder
```cpp
void inorder(TreeNode* root, vector<int> &v) {
        if (root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        }
```
iterative
```cpp
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    //visit node, store in stack, move to its left
    //if null, node=stack.top, print(node), pop stack, move right
    if (root==NULL) return {};
    TreeNode* node = root;
    while(true) {
        if (node != NULL) {
            st.push(node);
            node =node->left;
        } else {
            if (!st.size()) break;
            node=st.top();
            st.pop();
            ans.push_back(node->val);
            node=node->right;
        }
    }
    return ans;
}
```
### postorder
recursive
```cpp
void postorder(TreeNode* root, vector<int> &v) {
    if (root==NULL) return;
    postorder(root->left,v);
    postorder(root->right,v);
    v.push_back(root->val);
}
```
iterative
```cpp
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (root==NULL) return postorder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            postorder.push_back(curr->val);
            if (curr->left!=NULL) st.push(curr->left);
            if (curr->right!=NULL) st.push(curr->right);
        }
        reverse(postorder.begin(), postorder.end());
        return postorder;
    }
```
### all 3 traversal
```cpp
```
## bfs
Level Order Traversal
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i=0; i<size; i++) {
                TreeNode* Node = q.front();
                q.pop();
                level.push_back(Node->val);
                if (Node->left!=NULL) q.push(Node->left);
                if (Node->right!=NULL) q.push(Node->right); 
            }
            ans.push_back(level);
        }
        return ans;
}
```
