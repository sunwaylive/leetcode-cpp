#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x)
{
    ListNode dummy(INT_MIN);
    dummy.next = head;

    ListNode *cur = &dummy;
    ListNode *p, *q;
    while(cur->next != NULL){
        for(q = p, p = cur->next; p != NULL && p->val >= x; q = p, p = p->next)
            ;
        if(p != NULL){
            q->next = p->next;
            p->next = cur->next;
            cur->next = p;
            cur = cur->next;
        }else break;
    }
    return dummy.next;
}

ListNode* generateList(int size)
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *cur = head;
    for(int i = 0; i < size; i++){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    // srand((unsigned)time(NULL));
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
    ListNode *l2 = generateList(10);
    print_list(l2);

    ListNode *re = partition(l2, l2->val);
    print_list(re);
    return 0;
}
