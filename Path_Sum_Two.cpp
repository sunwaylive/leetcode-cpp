#include <iostream>
#include <fstream>
#include <vector>

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

void path(TreeNode *root, int sum, vector<int> &cur, vector<vector<int> > &result)
{
    if(root == NULL) return;

    cur.push_back(root->val);
    if(root->left == NULL && root->right == NULL){
        if(sum == root->val)
            result.push_back(cur);
    }

    path(root->left, sum - root->val, cur, result);
    path(root->right, sum - root->val, cur, result);

    //undo
    cur.pop_back();
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > result;
    vector<int> cur;

    path(root, sum, cur, result);
    return result;
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());

    TreeNode *t = createTree();
    vector<vector<int> > ret;
    ret = pathSum(t, 3);
    cout<<ret.size()<<endl;
    in.close();
    return 0;
}
