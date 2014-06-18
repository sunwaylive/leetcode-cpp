#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *);

ListNode* swapPairs(ListNode *head)
{

}

ListNode* generateList(int size)
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *cur = head;

    for(int i = 0; i < size-1; i++){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    //srand((unsigned)time(NULL));
    p->val = rand() % 10;
    p->next = NULL;
    cur->next = p;
    cur = cur->next;
    }

    ListNode *manual = (ListNode*) malloc(sizeof(ListNode));
    manual->val = 1;
    manual->next = NULL;
    cur->next = manual;
    return head->next;
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
    ListNode *l2 = generateList(4);
    print_list(l2);

    ListNode *re = swapPairs(l2);
    print_list(re);
    return 0;
}
