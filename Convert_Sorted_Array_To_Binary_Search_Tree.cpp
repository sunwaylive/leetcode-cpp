#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

TreeNode* createBST(vector<int> &num, int l, int r)
{
    TreeNode *root;
    if(l > r){
        root = NULL;
    }else{
        int mid = (l + r) / 2;
        root = new TreeNode(num[mid]);
        root->left = createBST(num, l, mid - 1);
        root->right = createBST(num, mid + 1, r);
    }
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
    return createBST(num, 0, num.size() - 1);
}

void preorder(TreeNode *root)
{
    if(root){
        cout<<root->val<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> v(A, A + sizeof(A) / sizeof(A[0]));
    TreeNode *t = sortedArrayToBST(v);
    preorder(t);
    return 0;
}
