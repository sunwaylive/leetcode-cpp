#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
    ListNode dummy(-1);
    ListNode *p = &dummy;
    for(; l1 != NULL && l2 != NULL; p = p->next){
        if(l1->val < l2->val) { p->next = l1; l1 = l1->next; }
        else { p->next = l2; l2 = l2->next;}
    }
    p->next = (l1 == NULL) ? l2 : l1;
    return dummy.next;
}


ListNode* generateList(int size)
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *cur = head;
    for(int i = 0; i < size; i++){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->val = i;//rand() % 100;
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
    ListNode *l2 = generateList(10);
    print_list(l2);
    ListNode *re = mergeTwoLists(l1, l2);
    print_list(re);
    return 0;
}
