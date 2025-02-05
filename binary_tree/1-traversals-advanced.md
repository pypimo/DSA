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
![bt](https://github.com/user-attachments/assets/1bb387d3-6614-4a6d-8394-690ea2daaaab)

