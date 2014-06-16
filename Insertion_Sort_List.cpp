#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* findInsertPos(ListNode *head, int x)
{
    ListNode *pre = NULL;
    // if x == INT_MIN, pre will return with NULL if we use only ">"
    for(ListNode *cur = head; cur != NULL && x >= cur->val;
        pre = cur, cur = cur->next)
        ;
    return pre;
}

ListNode* insertionSortList(ListNode *head)
{
    ListNode dummy(INT_MIN);
    for(ListNode *cur = head; cur != NULL;){
        ListNode *pos = findInsertPos(&dummy, cur->val);
        ListNode *tmp = cur->next;
        cur->next = pos->next;
        pos->next = cur;
        cur = tmp;
    }
    return dummy.next;
}


ListNode* generateList(int size)
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *cur = head;
    for(int i = 0; i < size; i++){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->val = rand() % 100;
    p->next = NULL;
    cur->next = p;
    cur = cur->next;
    }
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
    ListNode *l1 = generateList(20);
    print_list(l1);
    l1 = insertionSortList(l1);
    print_list(l1);
    return 0;
}
