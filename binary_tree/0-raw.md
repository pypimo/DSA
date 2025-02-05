# Intro
## types
1. full bt - each node has 0/2 children
2. complete bt - each level is completely filled xcpt last level (which must have nodes as left as possible)
3. perfect bt -  each node has 0/2 children and 0 children ones are at same level (leaf nodes)
4. balanced bt - The absolute difference of heights of left and right subtrees at any node is less than 1
5. degenerate - like a linked list, each node has  only 1 child
## Uses
Perfect binary trees are used to implement heap data structures
They are used to construct threaded binary trees
They are used in algorithms like heapsort and merge sort
They are used to organize and search for information quickly

```cpp
class TreeNode {
public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int data) {
                this->val=data;
                this->left=NULL;
                this->right=NULL;
        }
        TreeNode(int data, TreeNode* l, TreeNode* r) {
                this->val=data;
                this->left=l;
                this->right=r;
        }

}
```
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
## top view
- my intial approach was using a map for node, int to check what dist the source node is at
- but much better to just insert the pair with node, dist
https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
```cpp
vector<int> topView(Node *root) {   
        vector<int> ans;
        if (root==NULL) return ans;
        map<int,int> m; //to store nodes at each distance
        
        // level order
        queue<pair<Node*,int>> q; //node,dist
        q.push({root,0});
        
        while(!q.empty()) {
            int size  = q.size();
            while(size--) {
                Node* curr = q.front().first;
                int dist = q.front().second;
                if (!m.count(dist)) m[dist]=curr->data;
                q.pop();
                 
                if (curr->left!=NULL) q.push({curr->left, dist-1});
                if (curr->right!=NULL) q.push({curr->right, dist+1});
            }
        }
       
        //print
        for (auto x : m) {
            ans.push_back(x.second);
        }   
        
        return ans;
}
```
## bottom view
```cpp
vector <int> bottomView(Node* root) {
        vector<int> ans;
        if (root==NULL) return ans;
        map<int,vector<int>> m;
        
        // level order
        queue<pair<Node*,int>> q; //node,dist
        q.push({root,0});
        
        while(!q.empty()) {
            int size  = q.size();
            map<int,int> m2;
            while(size--) {
                Node* curr = q.front().first;
                int dist = q.front().second;
                if (m2[dist]) m[dist].push_back(curr->data);
                else {
                    m[dist] = {curr->data};
                }
                q.pop();
                 
                if (curr->left!=NULL) q.push({curr->left, dist-1});
                if (curr->right!=NULL) q.push({curr->right, dist+1});
            }
        }
       
        //print
        for (auto x : m) {
            for (auto y : x.second) {
                ans.push_back(y);
            }
        }   
        
        return ans;
}
```
