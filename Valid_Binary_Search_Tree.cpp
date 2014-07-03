#include <iostream>
#include <fstream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

void BST(TreeNode **root, TreeNode *newNode)
{
    if(*root == NULL){
        *root = newNode;
    }else if(newNode->val < (*root)->val){
        BST(&(*root)->left, newNode);
    }else if(newNode->val > (*root)->val){
        BST(&(*root)->right, newNode);
    }else{
        BST(&(*root)->left, newNode);
    }
}

TreeNode* createBST()
{
    int data;
    TreeNode *root = NULL;
    while(cin>>data){
        TreeNode* t = new TreeNode(data);
        BST(&root, t);
    }
    return root;
}

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

bool isValid(TreeNode *root, int lower, int upper)
{
    if(root == NULL) return true;

    return (root->val > lower) && (root->val < upper)
        && isValid(root->left, lower, root->val)
        && isValid(root->right, root->val, upper);
}

bool isValidBST(TreeNode *root) {
    return isValid(root, INT_MIN, INT_MAX);
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());

    TreeNode *t = createTree();

    cout<<isValidBST(t)<<endl;
    in.close();
    return 0;
}
