#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x){}
};

TreeNode* createTree(){
    TreeNode *T;
    int data;
    cin>>data;
    if(data == -1){
        T = NULL;
    }else{
        T = new TreeNode(data);
        T->left = createTree();
        T->right = createTree();
    }
    return T;
}

//************************************************************
//get the sum of all path from root to leaf
void allPathSumHelper(TreeNode *root, vector<vector<int> > &result, vector<int> &path){
    if(!root) return;

    path.push_back(root->val);
    if(!root->left && !root->right) result.push_back(path);

    allPathSumHelper(root->left, result, path);
    allPathSumHelper(root->right, result, path);
    path.pop_back();
}

vector<vector<int> > allPathSum(TreeNode *root){
    vector<vector<int> > result;
    if(root == NULL) return result;

    vector<int> path;
    allPathSumHelper(root, result, path);
    return result;
}

//************************************************************
//get all the path from root to leaf that add up to a given sum
void pathSumSpecificHelper(TreeNode *root, vector<vector<int> > &result, vector<int> &path, int sum){
    if(!root) return;
    //if we use root->val, the following codes have dealt with all possibilities
    path.push_back(root->val);
    if(!root->left && !root->right && sum == root->val)
        result.push_back(path);
    pathSumSpecificHelper(root->left, result, path, sum - root->val);
    pathSumSpecificHelper(root->right, result, path, sum - root->val);
    path.pop_back();
}

vector<vector<int> > pathSumSpecific(TreeNode *root, int sum){
    vector<vector<int> > result;
    if(!root) return result;

    vector<int> path;
    pathSumSpecificHelper(root, result, path, sum);
    return result;
}

//************************************************************
//problem located here: https://oj.leetcode.com/problems/path-sum/
//check whether exist a path whose sum equals to a given one
bool hasPathSum(TreeNode *root, int sum){
    if(!root) return false;

    if(!root->left && !root->right && sum == root->val)
        return true;

    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());
    TreeNode *root = createTree();
    vector<vector<int> > ret;
    ret = pathSumSpecific(root, 8);
    for(int i = 0; i < ret.size(); ++i){
        for(int j = 0; j < ret[i].size(); ++j){
            cout<<ret[i][j] <<" ";
        }
        cout<<endl;
    }
    in.close();
    return 0;
}
