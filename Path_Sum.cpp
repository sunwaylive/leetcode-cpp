#include <iostream>
#include <fstream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

TreeNode* createTree()
{
    TreeNode *Tree;
    int data;
    cin>>data;
    if(data == -1){
        Tree = NULL;
    }else{
        Tree = new TreeNode(data);
        Tree->left = createTree();
        Tree->right = createTree();
    }
    return Tree;
}

bool hasPathSum(TreeNode *root, int sum) {
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL)
        return sum == root->val;

    return hasPathSum(root->left, sum - root->val)
        || hasPathSum(root->right, sum - root->val);
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());

    TreeNode *t = createTree();
    cout<<hasPathSum(t, 4)<<endl;
    in.close();
    return 0;
}
