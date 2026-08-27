# LCA O(n)
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
- find the two nodes and identify last common node in that path
```cpp
  class Solution {
public: 

    bool dfs(TreeNode* curr, TreeNode* goal, vector<TreeNode*>& path) {
        if (curr==goal) return true;
        if (curr->left!=NULL) {   
            path.push_back(curr->left);
            if (dfs(curr->left,goal, path)) return true;
        }
        if (curr->right!=NULL) {
            path.push_back(curr->right);
           if (dfs(curr->right,goal, path)) return true;
        }
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // get two paths then findcommon
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        TreeNode* ans=NULL;

        if (root==NULL) return ans;
        vector<TreeNode*> path1,path2;
        path1.push_back(root);
        path2.push_back(root);

        dfs(root, p, path1);
        dfs(root, q, path2);
        
        // PRINTING PATHS
        // for (auto x : path1) {
        //     cout << x->val << " ";
        // }
        for (int i=0; i<min(path1.size(), path2.size()); i++) {
            if (path1[i]==path2[i]) ans = path1[i];
        }
        return ans;
    }
};
```
- another method
```
TreeNode *find1, *find2, *ans=NULL;
// dfs to look left, then right - at whichever you see p and q first 
// that's ans
pair<int,int> dfs(TreeNode* curr){
    if (curr==NULL) return {0,0};
    pair<int,int> p1, p2, p3;
    if (ans==NULL) p1=dfs(curr->left);
    if (ans==NULL) p2=dfs(curr->right);
    if (curr==find1 || p1.first || p2.first) p3.first=1; 
    if (curr==find2 || p1.second || p2.second) p3.second=1; 
    if (ans==NULL && p3.first && p3.second) ans=curr;
    cout << curr->val << " " << p3.first << " " << p3.second << '\n';
    return p3;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    find1=p; find2=q;
    dfs(root);
    return ans;
}
```
- for q queries -> q*n (doestn work if q ~ 1e5)
## Binary Lifting
```cpp
```
