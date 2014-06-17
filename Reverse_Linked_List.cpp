#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *head);

ListNode* findPos(ListNode *head, int n)
{
    ListNode *pos = head;
    while(n-- > 1 && pos != NULL){
        pos = pos->next;
    }
    return pos;
}

ListNode *reverseList(ListNode *head)
{
    if(head == NULL || head->next == NULL) return head;

    ListNode *p, *q, *r;
    for(p = head, q = p->next, r = q->next; q != NULL;){
        q->next = p;
        p = q;
        q = r;
        r = (r == NULL) ? NULL : r->next;
    }
    head->next = NULL;
    return p;
}

ListNode* reverseBetween(ListNode *head, int m, int n)
{
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *dummy_head = &dummy;

    ListNode *pre_start = findPos(dummy_head, m);
    ListNode *pre_end = findPos(dummy_head, n);
    ListNode *start = pre_start->next;
    ListNode *end = pre_end->next;

    ListNode *tmp = end->next;
    end->next = NULL;
    ListNode *new_start = reverseList(start);
    pre_start->next = new_start;
    start->next = tmp;
    return dummy.next;
}

ListNode* reverseBetween2(ListNode *head, int m, int n)
{
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *prev = &dummy;

    for(int i = 0; i < m-1; ++i)
        prev = prev->next;

    ListNode * const head2 = prev;
    prev = head2->next;
    ListNode *cur = prev->next;
    for(int i = m; i < n; ++i){
        prev->next = cur->next;//save for the next cur position
        //head-insertion building linked list
        cur->next = head2->next;
        head2->next = cur;
        cur = prev->next;
    }
    cout<<dummy.next->val <<endl;
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
    ListNode *l2 = generateList(5);
    print_list(l2);

    ListNode *re = reverseBetween2(l2, 1, 4);
    print_list(re);
    return 0;
}
