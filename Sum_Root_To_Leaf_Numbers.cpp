#include <iostream>
#include <fstream>
#include <stack>

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

int sumNumbers2(TreeNode *root)
{
    int result = 0;
    int sum = 0;
    stack<TreeNode*> nodeStack;
    TreeNode* last = NULL;
    while(NULL != root || !nodeStack.empty())
    {
        while(NULL != root)
        {
            nodeStack.push(root);
            result  = 10*result + root -> val;
            root = root -> left;
        }
        root = nodeStack.top();
        if(NULL == root ->right || last == root -> right)   // if the right has been visited, visit the curent node
        {
            if(NULL == root -> left && NULL == root -> right)
                sum += result;
            last = root;
            result /= 10;
            nodeStack.pop();
            free(root);
            root = NULL;
        }
        else                                                   // if the right node has not visited, visit it
            root = root -> right;
    }
    return sum;
}


int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());

    TreeNode *t = createTree();
    cout<<sumNumbers2(t)<<endl;
    in.close();
    return 0;
}
