 void maping(map<int, int>& m, vector<int>& ino, int n) {
        for (int i = 0; i < n; i++) {
            m[ino[i]] = i;
        }
    }
    TreeNode* solve(vector<int>& ino, vector<int>& post, int& ind, int st, int end, map<int, int>& m, int n) {
        if (ind < 0 || st > end) {
            return NULL;
        }

        int ele = post[ind--];  
        int pos = m[ele]; 
        TreeNode* root = new TreeNode(ele);
        root->right = solve(ino, post, ind, pos + 1, end, m, n);
        root->left = solve(ino, post, ind, st, pos - 1, m, n);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& ino, vector<int>& post) {
        int n = ino.size();
        map<int, int> m;
        maping(m, ino, n);
        int ind = n - 1;
        return solve(ino, post, ind, 0, n - 1, m, n);
    }
