#include <iostream>
#include <fstream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;
    }

private:
    int max_sum;

private:
    //后序遍历
    int dfs(const TreeNode *root){
        if(root == nullptr) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int sum = root->val;
        if(l > 0) sum += l;
        if(r > 0) sum += r;
        max_sum = max(max_sum, sum); //update the max sum, return result, two directions.
        int tmp = max(l, r);
        return tmp > 0 ? (tmp + root->val) : root->val;
    }
};

TreeNode* createTree()
{
    TreeNode *T;
    int data;
    cin>>data;
    if(data == -1){
        T = nullptr;
    }else{
        T = new TreeNode(data);
        T->left = createTree();
        T->right = createTree();
    }
    return T;
}

int main()
{
    fstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());
    TreeNode *t = createTree();
    Solution sln;
    cout<<sln.maxPathSum(t)<<endl;
    in.close();
    return 0;
}
