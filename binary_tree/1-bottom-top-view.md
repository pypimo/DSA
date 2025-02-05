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
