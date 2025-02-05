## max height
- recursive - O(n) worst when skewed
```cpp
int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return 1+max(l,r);
}
```
## check for balanced bt
- can use 2 functions, bool check and maxDepth
- after getting maxDepth of left and right check
- if check(node->left) && check(node->right) && (abs(maxDepth(node->left)-maxDepth(node->right))<=1) return true;
- return false;

USING ONE FUNCTION ONLY
![chrome_uhzWLnOLDl](https://github.com/user-attachments/assets/45309f6e-c401-498c-8f30-629bed269bb7)


## diameter (longest path b/w 2 nodes)
![chrome_MaKoBF5fOo](https://github.com/user-attachments/assets/d57f2c37-0829-425c-a54a-aa6a8fc9724b)
