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

int dfs(TreeNode *root, int sum)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL)
        return sum * 10 + root->val;

    return dfs(root->left, sum * 10 + root->val) + dfs(root->right, sum * 10 + root->val);
}

int sumNumbers(TreeNode *root) {
    return dfs(root, 0);
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());

    TreeNode *t = createTree();
    cout<<sumNumbers(t)<<endl;
    in.close();
    return 0;
}
