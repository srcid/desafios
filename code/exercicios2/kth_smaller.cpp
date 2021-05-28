#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void transverse(TreeNode* node, int& k, vector<int>& tord) {
        if (node != nullptr) {
            transverse(node->left, k, tord);
            tord.push_back(node->val);
            if (tord.size()==k) {
                return;
            }
            transverse(node->right, k, tord);
        }
    }    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> tord;
        transverse(root, k, tord);
        
        return tord[k-1];
    }
};

int main(int argc, char const *argv[])
{
    /* ... */
    return 0;
}
