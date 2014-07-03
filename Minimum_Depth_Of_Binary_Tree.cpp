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

int minDepth(TreeNode *root) {
    if(root == NULL) return 0;

    int ld = minDepth(root->left);
    int rd = minDepth(root->right);
    //this node may not be leaf node, so the path that ends just at it is not a real one
    if(ld == 0)
        return rd + 1;
    else if(rd == 0)
        return ld + 1;
    else return min(ld, rd) + 1;
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());

    TreeNode *t = createTree();
    cout<<minDepth(t)<<endl;
    in.close();
    return 0;
}
