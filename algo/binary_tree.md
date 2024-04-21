# Binary Trees
## types
1. full bt - each node has 0/2 children
2. complete bt - each level is completely filled xcpt last level (which must have nodes as left as possible)
3. perfect bt - all leaf nodes are at same level
4. balanced bt - height = log n (n= no of nodes)
5. degenerate - like a linked list, each node has  only 1 child
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
        ios::sync_with_stdio(0);
        cin.tie(0);

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
        ios::sync_with_stdio(0);
        cin.tie(0);
        
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
## max height
- recursive - O(n) worst when skewed
```cpp
int maxDepth(TreeNode* root) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        if (root==NULL) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return 1+max(l,r);
}
```
- level - space worst O(n) when full BT
```cpp
int maxDepth(TreeNode* root) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        if (root==NULL) return 0;

        int l=0, now=1, nxt=0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            now--;
            
            if (curr->left!=NULL) {
                nxt++;
                q.push(curr->left);
            }
            if (curr->right!=NULL) {
                nxt++;
                q.push(curr->right);
            }
            if (!now) {
                l++;
                now=nxt;
                nxt=0;
            }
        }
        return l;
    }
```
## diameter (longest path b/w 2 nodes), max path sum (path is when adjacent paths have a way => take max sum path)

## boundary traversal
- left subtree is left boundary
- right subtree is right boundary
- leaves are all leaf nodes
- ans = left + leaves + reverse(right)
- dont include root since it can be both left or right, just include it in beginning if not leaf
- level order doesnt work, bcz boundary traversal technically is not tracing, it checks for left right subtree
- and then defines left right boundary
```
failed level order bcz it traces the right edges nicely
but this boundary traveresal defines left boundary = left subtree's leftmost and right boundary = right subtree's rightmost
reason: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
```
```cpp
class Solution {
public:
    vector<int> ans;

    void addLeft(Node* curr) {
        while(curr!=NULL) {
            if (!isLeaf(curr)) ans.push_back(curr->data);
            if (curr->left!=NULL) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void addLeaf(Node* curr) {
        if (curr==NULL) return;
        if (isLeaf(curr)) {
            ans.push_back(curr->data);
            return;
        }
        addLeaf(curr->left);
        addLeaf(curr->right);
    }
    
    void addRight(Node* curr) {
        vector<int> tmp;
        while(curr!=NULL) {
            if (!isLeaf(curr)) tmp.push_back(curr->data);
            if (curr->right!=NULL) curr = curr->right;
            else curr = curr->left;
        }
        reverse(tmp.begin(), tmp.end());
        for (auto x : tmp) {
            ans.push_back(x);
        }
    }

    bool isLeaf(Node* root) {
        if (root->left==NULL && root->right==NULL) return true;
        return false;
    }
    vector <int> boundary(Node *root)
    {
        
        if (root==NULL) return ans;
        //Your code here
        if (!isLeaf(root)) ans.push_back(root->data);
        addLeft(root->left);
        addLeaf(root);
        addRight(root->right);
        return ans;
    }
};
```
