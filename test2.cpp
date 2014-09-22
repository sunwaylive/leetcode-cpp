#include<iostream>
#include<stdio.h>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//int A[]= {1,2,3,-1,-1,4,-1,-1,5};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    bool isValidBST(TreeNode *root)
    {
        return true;
    }

public:
    TreeNode* createTree(void)
    {
        int data;
        TreeNode* root;
        scanf("%d\n", &data);
        fflush(stdin);
        if( data == -1)
            root = NULL;
        else
        {
            root = (TreeNode*)malloc(sizeof(TreeNode));
            root -> val = data;
            root -> left  = createTree();
            root -> right = createTree();
        }
        return root;
    }

public:
    void preInorderTree(TreeNode *T)
    {
        if(NULL != T)
        {
            cout <<  T -> val << " ";
            preInorderTree(T -> left);
            preInorderTree(T -> right);
        }
    }
};

int main()
{
    // { 1,2,3,#,#,4,#,#,5}
    cout<<INT_MAX<<endl;
    cout<<INT_MIN<<endl;
    return 0;
}
