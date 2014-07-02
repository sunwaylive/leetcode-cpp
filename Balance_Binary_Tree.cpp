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
        Tree = (TreeNode*) malloc(sizeof(TreeNode));
        Tree->val = data;
        Tree->left = createTree();
        Tree->right = createTree();
    }
    return Tree;
}

void BST(TreeNode **root, TreeNode *newNode)
{
    if(*root == NULL)
        *root = newNode;
    else if(newNode->val < (*root)->val)
        BST(&(*root)->left, newNode);
    else if(newNode->val > (*root)->val)
        BST(&(*root)->right, newNode);
    //we ignore equal cases.
}

TreeNode* createBST()
{
    int data;
    TreeNode *root = NULL;
    while(cin>>data){//end when get a non-num input
        TreeNode *t = new TreeNode(data);
        BST(&root, t);
    }
    return root;
}

void inorder(TreeNode *root)
{
    if(root){
        inorder(root->left);
        cout<<root->val<<endl;
        inorder(root->right);
    }
}

int treeDepth(TreeNode* root)
{
    if(root == NULL) return 0;

    int ld = treeDepth(root->left);
    int rd = treeDepth(root->right);

    return max(ld, rd) + 1;
}

int treeNodeNum(TreeNode *root)
{
    if(root == NULL) return 0;

    return 1 + treeNodeNum(root->left) + treeNodeNum(root->right);
}

int treeLeafNodeNum(TreeNode *root)
{
    if(!root) return 0;
    else if(!root->left && !root->right)
        return 1 ;//+ treeLeafNodeNum(root->left) + treeLeafNodeNum(root->right);
    else
        return treeLeafNodeNum(root->left) + treeLeafNodeNum(root->right);
}

bool isBalanced(TreeNode *root) {
    if(root == NULL) return true;

    int lh = treeDepth(root->left);
    int rh = treeDepth(root->right);
    if(abs(lh - rh) > 1) return false;
    else return isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    //ifstream in;
    //in.open("input.txt");
    //cin.rdbuf(in.rdbuf());
    TreeNode *t = createBST();
    inorder(t);
    //in.close();
    return 0;
}
