#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *);

ListNode* reverse(ListNode *prev, ListNode *start, ListNode *end)
{
    ListNode *p, *q, *r;
    ListNode *end_next = end->next;
    for(p = start, q = p->next, r = q->next; q != end_next; ){
        q->next = p;
        p = q;
        q = r;
        r = (r == NULL) ? NULL : r->next;
    }
    prev->next = end;
    start->next = end_next;
    return start;
}

ListNode* reverseKGroup(ListNode *head, int k)
{
    if(!head || !head->next || k < 2) return head;

    ListNode dummy(-1);
    dummy.next = head;
    ListNode *d_h = &dummy;

    ListNode *pre = d_h , *start = pre->next, *end = start;
    while(end){
        for(int i = 1; i < k && end; ++i)
            end = end->next;
        if(end == NULL) break;
        pre = reverse(pre, start, end);
        print_list(dummy.next);
        start = pre->next;
        end = start;
    }
    return dummy.next;
}

ListNode* generateList(int size)
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *cur = head;

    for(int i = 0; i < size-1; i++){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    //srand((unsigned)time(NULL));
    p->val = rand() % 10 + 1;
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

    ListNode *re = reverseKGroup(l2, 3);
    print_list(re);
    return 0;
}
