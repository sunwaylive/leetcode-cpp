#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

vector<TreeNode*> generate(int l , int r)
{
    vector<TreeNode*> ans;
    if(l > r){
        ans.push_back(NULL);
    }else{
        for(int k = l; k <= r; ++k){
            vector<TreeNode*> left = generate(l, k - 1);
            vector<TreeNode*> right = generate(k + 1, r);

            //for each k, there left.size() kinds of left sub-tree, and right.size() kinds of right sub-trees
            for(int kl = 0; kl < left.size(); ++kl){
                for(int kr = 0; kr < right.size(); ++kr){
                    TreeNode *root = new TreeNode(k);
                    root->left = left[kl];
                    root->right = right[kr];
                    ans.push_back(root);
                }
            }
        }
    }
    return ans;
}

vector<TreeNode *> generateTrees(int n) {
    return generate(1, n);
}

int main()
{
    vector<TreeNode*> ret;
    ret = generateTrees(3);
    cout<<ret.size()<<endl;
    return 0;
}
