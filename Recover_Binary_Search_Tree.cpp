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

void detect(pair<TreeNode*, TreeNode*> &broken, TreeNode *prev, TreeNode *cur)
{
    if(prev != NULL && cur != NULL
       && prev->val > cur->val){
        cout<<"prev: "<<prev->val<<endl;
        cout<<"cur: "<<cur->val<<endl;
        if(broken.first == NULL) broken.first = prev;
        broken.second = cur;
    }
}

void recoverTree(TreeNode *root)
{
    TreeNode *tmp = NULL, *prev = NULL, *cur = root;
    pair<TreeNode*, TreeNode*> broken;

    while(cur != NULL){
        if(cur->left == NULL){
            //cout<<cur->val<<endl;
            detect(broken, prev, cur);
            prev = cur;
            cur = cur->right;
            //detect(broken, prev, cur);
        }else{
            tmp = cur->left;
            while(tmp->right != NULL && tmp->right != cur)
                tmp = tmp->right;

            if(tmp->right == NULL){
                tmp->right = cur;
                cur = cur->left;
            }else{
                detect(broken, prev, cur);
                tmp->right = NULL;
                prev = cur;
                //cout<<cur->val<<endl;
                cur = cur->right;
                //detect(broken, prev, cur);
            }
        }
    }
    cout<<broken.first<<endl;
    cout<<broken.second<<endl;
    swap(broken.first->val, broken.second->val);
}

// class Solution {
// public:
//     TreeNode *s1,*s2,*pre;
//     void recoverTree(TreeNode *root) {
//         s1=s2=pre=NULL;
//         inorder(root);
//         swap(s1->val,s2->val);
//         return;
//     }

//     void inorder(TreeNode *root)
//     {
//         if(!root)
//             return;
//         inorder(root->left);
//         if(pre&&pre->val>root->val)
//         {
//             if(s1==NULL)
//                 s1=pre,s2=root;
//             else
//                 s2=root;
//         }
//         pre=root;
//         inorder(root->right);
//     }
// };

void inorderTraversal(TreeNode *root)
{
    if(root != NULL){
        inorderTraversal(root->left);
        cout<<root->val<<endl;
        inorderTraversal(root->right);
    }
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());

    TreeNode *t = createTree();
    inorderTraversal(t);
    recoverTree(t);
    inorderTraversal(t);
    return 0;
}
