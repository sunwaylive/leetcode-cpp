#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

void print_list(ListNode *l);

TreeNode* createBST(ListNode *&head)
{
    TreeNode *root;
    if(head == NULL){
        root = NULL;
    }else if(head->next == NULL){
        root = new TreeNode(head->val);
    }else{
        //get the middle of the list
        ListNode *fast = head, *slow = head, *prev = NULL;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        //slow is middle, use it and cut the list
        root = new TreeNode(slow->val);
        ListNode *newHead = slow->next;
        if(prev != NULL)
            prev->next = NULL;

        root->left = createBST(head);
        root->right = createBST(newHead);
    }
    return root;
}

TreeNode *sortedListToBST(ListNode *head) {
    return createBST(head);
}

ListNode* generateList(int size)
{
    ListNode dummy(INT_MIN);
    ListNode *cur = &dummy;
    for(int i = 0; i < size; ++i){
        ListNode *p = new ListNode(i);
        cur->next = p;
        cur = cur->next;
    }
    return dummy.next;
}

void preorder(TreeNode *root)
{
    if(root){
        cout<<root->val<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void print_list(ListNode *l)
{
    ListNode *tmp = l;
    while(tmp != NULL){
        cout<< tmp->val <<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

int main()
{
    ListNode *list = generateList(20);
    print_list(list);
    TreeNode *t = sortedListToBST(list);
    preorder(t);
    return 0;
}
