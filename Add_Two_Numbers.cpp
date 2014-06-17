#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0, value = 0;
    ListNode dummy(-1);
    ListNode *p = &dummy;
    for(; l1 != NULL && l2 != NULL; l1 = l1->next, l2 = l2->next){
        value = l1->val + l2->val + carry;
        carry = value / 10;
        ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
        tmp->val = value % 10;
        tmp->next = NULL;
        p->next = tmp;
        p = p->next;
    }

    while(l1 != NULL){
        ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
        value = l1->val + carry;
        tmp->val = value % 10;
        tmp->next = NULL;
        p->next = tmp;
        carry = value / 10;
        l1 = l1->next;
        p = p->next;
    }

    while(l2 != NULL){
        ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
        value = l2->val + carry;
        tmp->val = value % 10;
        tmp->next = NULL;
        p->next = tmp;
        carry = value / 10;
        l2 = l2->next;
        p = p->next;
    }

    if(l1 == NULL && l2 == NULL && carry !=0){
        ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
        tmp->val = carry;
        tmp->next = NULL;
        p->next = tmp;
        p = p->next;
    }

    return dummy.next;
}

ListNode* generateList(int size)
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *cur = head;
    for(int i = 0; i < size; i++){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    srand((unsigned)time(NULL));
    p->val = rand() % 10;
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
    ListNode *l1 = generateList(5);
    print_list(l1);
    ListNode *l2 = generateList(5);
    print_list(l2);
    ListNode *re = addTwoNumbers(l1, l2);
    print_list(re);
    return 0;
}
